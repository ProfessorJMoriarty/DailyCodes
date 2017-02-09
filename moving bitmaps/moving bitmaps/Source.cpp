
#include <allegro5/allegro.h>
#include <math.h>

int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;
	ALLEGRO_BITMAP *bouncer3 = NULL;
	ALLEGRO_BITMAP *bouncer4 = NULL;
	//here's the bouncer's x and y coordinates on the screen, initally set to 30,30
	float bouncer_x = 120;
	float bouncer_y = 240;
	float bouncer2_x = 320;
	float bouncer2_y = 240;
	float bouncer3_x = 220;
	float bouncer3_y = 240;
	float bouncer4_x = 420;
	float bouncer4_y = 240;
	//here's the bouncer's x and y directions, initially set to -4, 4
	float bouncer_dx = -8.0, bouncer_dy = -8.0;
	float bouncer2_dx = -8.0, bouncer2_dy = -6.0;
	float bouncer3_dx = -8.0, bouncer3_dy = -9.0;
	float bouncer4_dx = -8.0, bouncer4_dy = -7.0;
	bool redraw = true;

	al_init();

	//set the timer so it "ticks" at 2 milliseconds
	timer = al_create_timer(.002);

	display = al_create_display(640, 480);

	//create a little 32x32 square
	bouncer = al_create_bitmap(50, 50);
	bouncer2 = al_create_bitmap(30, 30);
	bouncer3 = al_create_bitmap(20, 20);
	bouncer4 = al_create_bitmap(50, 50);
	//use this to *draw* your own bitmaps (instead of loading them from a file)
	//before we used al_load_bitmap()
	al_set_target_bitmap(bouncer);

	//set the color of your bitmap
	al_clear_to_color(al_map_rgb(0, 250, 50));


	al_set_target_bitmap(bouncer2);

	//set the color of your bitmap
	al_clear_to_color(al_map_rgb(200, 000, 200));
	al_set_target_bitmap(bouncer3);

	//set the color of your bitmap
	al_clear_to_color(al_map_rgb(155, 200, 100));
	al_set_target_bitmap(bouncer4);

	//set the color of your bitmap
	al_clear_to_color(al_map_rgb(170, 100, 200));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	//register the timer as an event source so it can generate events
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	//GUESS WHAT THIS DOES
	al_start_timer(timer);

	while (1) //GAME LOOP
	{
		ALLEGRO_EVENT ev;
		//this function will wait forever if no events come in
		al_wait_for_event(event_queue, &ev);

		//////////////////////////////////////////////////////////////////////////////////
		//this section handles the bouncing-off-the-edges action

		//sets this part of the game to run on the clicks of the timer 
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//if the box hits the left wall OR the right wall
			if (bouncer_x < 0 || bouncer_x > 640 - 32) {
				//flip the x direction
				bouncer_dx = -bouncer_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (bouncer_y < 0 || bouncer_y > 640 - 32) {
				//flip the y direction
				bouncer_dy = -bouncer_dy;
			}
			if (bouncer2_x < 0 || bouncer2_x > 640 - 32) {
				//flip the x direction
				bouncer2_dx = -bouncer2_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (bouncer2_y < 0 || bouncer2_y > 480 - 32) {
				//flip the y direction
				bouncer2_dy = -bouncer2_dy;
			}
			if (bouncer3_x < 0 || bouncer3_x > 640 - 32) {
				//flip the x direction
				bouncer3_dx = -bouncer3_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (bouncer3_y < 0 || bouncer3_y > 480 - 32) {
				//flip the y direction
				bouncer3_dy = -bouncer3_dy;
			}
			if (bouncer4_x < 0 || bouncer4_x > 640 - 32) {
				//flip the x direction
				bouncer4_dx = -bouncer4_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (bouncer4_y < 0 || bouncer4_y > 480 - 32) {
				//flip the y direction
				bouncer4_dy = -bouncer4_dy;
			}

			//really important code!
			//move the box in a diagonal
			bouncer_x += sin(bouncer_dx);
			bouncer_y += bouncer_dy;

			bouncer2_x += sin(bouncer2_dx);
			bouncer2_y += bouncer2_dy;

			bouncer3_x += bouncer3_dx;
			bouncer3_y += bouncer3_dy;

			bouncer4_x += bouncer4_dx;
			bouncer4_y += bouncer4_dy;

			//if an event happened, you better redraw
			redraw = true;
		}

		//////////////////////////////////////////////////////////////////
		//kill program if the user clicks the exit button
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//if you were supposed to redraw but there wasn't an event, don't redraw
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
		
		
			//al_clear_to_color(al_map_rgb(0, 0, 0));

			//here's where the magic happens: draw the square to the screen
			//at the coordinate position bouncer_x, bouncer_y
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_draw_bitmap(bouncer2, bouncer2_x, bouncer2_y, 0);
			al_draw_bitmap(bouncer3, bouncer3_x, bouncer3_y, 0);
			al_draw_bitmap(bouncer4, bouncer4_x, bouncer4_y, 0);
			al_flip_display();
		}
	}//end game loop

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}