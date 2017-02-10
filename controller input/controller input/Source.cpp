#include <stdio.h>
#include <allegro5/allegro.h>

#include "xbox.h"		


// Input constants for player
const int UP = 0;				// Constants to make the code that accepts
const int DOWN = 1;				// and applies input easier to read.
const int LEFT = 2;				// Also used for other purposes where we track direction
const int RIGHT = 3;
const int FIRE = 4;
const int JUMP = 5;
const int SWAP = 6;
int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *square = NULL;

	float square_x = 50;
	float square_y = 50;
	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_install_keyboard();
	al_install_joystick();
	timer = al_create_timer(.02);
	display = al_create_display(640, 480);


	////// Initialize the Xbox controller 
	xc_install();
	XC_STATE *controller = xc_get_state(0);
	if (!controller) {
		fprintf(stderr, "Failed to grab xbox controller state.\n");
		return 1;
	}
	xc_clear_state(controller);

	square = al_create_bitmap(32, 32);
	al_set_target_bitmap(square);
	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, xc_get_event_source()); // this one looks to the controller

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);


	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		xc_update(ev);

		//timer section///////////////////////////////////////////////////////////////////////////////////////////////////////
		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (key[0] && square_y >= 0) {
				square_y -= 4.0;
			}

			if (key[1] && square_y <= 480 - 32) {
				square_y += 4.0;
			}

			if (key[2] && square_x >= 0) {
				square_x -= 4.0;
			}


			if (key[3] && square_x <= 640 - 32) {
				square_x += 4.0;
			}


			redraw = true;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == XC_EVENT_BUTTON_DOWN) {

			if (controller->button_a) {
				key[JUMP] = true;
			}
			if (controller->button_x) {
				key[FIRE] = true;
			}

			if (controller->button_back) {
				key[SWAP] = true;
			}
		}
		//Check - did a button get released?
		else if (ev.type == XC_EVENT_BUTTON_UP) {

			if (!controller->button_a) {
				key[JUMP] = false;
			}
			if (!controller->button_x) {
				key[FIRE] = false;
			}
			if (!controller->button_back) {
				key[SWAP] = false;
			}
		}

		//Check - did the axis get pushed?
		else if (ev.type == XC_EVENT_AXIS) {

			if (controller->left_stick_x<0) {
				key[LEFT] = true;
			}
			else {
				key[LEFT] = false;
			}

			if (controller->left_stick_x>0) {
				key[RIGHT] = true;
			}
			else {
				key[RIGHT] = false;
			}

			if (controller->left_stick_y>0) {
				key[DOWN] = true;
			}
			else {
				key[DOWN] = false;
			}

			if (controller->left_stick_y<0) {
				key[UP] = true;
			}
			else {
				key[UP] = false;
			}
		}


		//////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {


			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[0] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[1] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[2] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[3] = true;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[0] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[1] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[2] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[3] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		//render section///////////////////////////////////////////////////////////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;


			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(square, square_x, square_y, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(square);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}