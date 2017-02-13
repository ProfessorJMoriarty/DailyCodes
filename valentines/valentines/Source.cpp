#include <stdio.h>
#include <allegro5/allegro.h>
#include <cmath>
#include<iostream>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;

//function declarations
void draw_polar(float radius, float angle);
void draw_polar2(float radius, float angle);


const float FPS = 120;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 5; //change this to change your pen size
float x = 0;
ALLEGRO_BITMAP *bouncer = NULL;
ALLEGRO_BITMAP *bouncer2 = NULL;
float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
int t = 0;


float bouncer2_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
float bouncer2_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;

float bouncer_dx = -4.0, bouncer_dy = 4.0;
int main(int argc, char **argv) {

	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand();
	int offset = (randomNumber % 10);
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;


	bool redraw = true;
	double t = 1;

	al_init();

	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon
	ALLEGRO_FONT *font = al_load_ttf_font("children.ttf", 72, 0);
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(1040, 840);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	bouncer2 = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(bouncer2);

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (1)
	{
		t++;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
				bouncer_dx = -bouncer_dx;
			}

			if (bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
				bouncer_dy = -bouncer_dy;
			}

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;


			al_set_target_bitmap(bouncer2);

			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_set_target_bitmap(bouncer);

			al_set_target_bitmap(al_get_backbuffer(display));

			int b = 0;
			for (float j = 0; j<100; j += .001) {//change this counter to speed the curl/uncurl of the spiral
				for (float i = 0; i<1; i += .005) {//change this counter to make spiral drawn with more or less dots

					al_set_target_bitmap(bouncer);
					al_clear_to_color(al_map_rgb(20 + b / 1000, (50 + b++) / 1200, (150 + b) / 500)); //mess with this to change color change
					al_set_target_bitmap(bouncer2);
					al_clear_to_color(al_map_rgb(0, 0, 0));//bouncer 2 (for polar2) is painted black
					al_set_target_bitmap(al_get_backbuffer(display));
					draw_polar(1000 * log(j)*log(i)*log(i), 100 * sin(i)*sin(j)*sin(i)); //here's the equation that does the drawing
					draw_polar2(1200 * log(j)*log(i)*log(i), 100 * sin(i)*sin(j)*sin(i)); //here's the equation that does the drawing
					draw_polar2(100 * log(j)*log(i)*log(i), 100 * sin(i)*sin(j)*sin(i)); //here's the equation that does the drawing
				}
				al_set_target_bitmap(al_get_backbuffer(display));
				al_flip_display();
				Sleep(5);//speeds up or slows the animation
						 //al_clear_to_color(al_map_rgb(0,0,0)); //comment this out to make the screen not refresh
			}



			al_draw_text(font, al_map_rgb(255, 255, 255), 500, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Happy Valentine's Day!");
			al_flip_display();
			Sleep(5);
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}




	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

void draw_polar(float radius, float angle) {

	bouncer_x = radius * cos(angle);
	bouncer_y = radius * sin(angle);
	al_draw_bitmap(bouncer, bouncer_x + 520, bouncer_y + 520, 0);


}

void draw_polar2(float radius, float angle) {

	bouncer2_x = radius * cos(angle);
	bouncer2_y = radius * sin(angle);
	al_draw_bitmap(bouncer2, bouncer2_x + 520, bouncer2_y + 520, 0);


}