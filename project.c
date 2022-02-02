#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>
#include<allegro5/keyboard.h>
#include<allegro5/allegro.h>

int n;
int start()
{
    
    al_init();
    
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_flip_display();
    al_install_keyboard();
    al_install_mouse();
   

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(1280, 960);
    ALLEGRO_FONT* font = al_load_ttf_font("impact.ttf", 100, 0);
    ALLEGRO_FONT* font1 = al_load_ttf_font("impact.ttf", 50, 0);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
   
 
    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 30, 100));
            al_draw_filled_triangle(600, 400, 700, 450, 600, 500, al_map_rgb(255, 255, 255));
            al_draw_text(font, al_map_rgb(255, 255, 255), 500, 0,1000, "START");
            al_draw_text(font1, al_map_rgb(255, 255, 255), 420, 800, 1000, "press any key to start");
            al_flip_display();

            redraw = false;
        }
    }
    
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}
int game() {
    int x = -20, y = -20, a1 = -20, b1 = -20, a2 = -20, b2 = -20, a3 = -20, b3 = -20, a4 = -20, b4 = -20, a5 = -20, a6 = -20, a7 = -20, a8 = -20, b5 = -20, b6 = -20, b7 = -20, b8 = -20, a9 = -20, b9 = -20;
    
    int l[60];
    for (int i = 0; i < 60; i++) {
        l[i] = 0;
    }
    al_init();

    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_flip_display();
    al_install_keyboard();
    al_install_mouse();


    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(1280, 960);
    ALLEGRO_FONT* font = al_load_ttf_font("impact.ttf", 100, 0);
    ALLEGRO_FONT* font1 = al_load_ttf_font("impact.ttf", 50, 0);
    ALLEGRO_BITMAP* bitmap1 = al_load_bitmap("1.png");
    ALLEGRO_BITMAP* bitmap2 = al_load_bitmap("2.png");
    ALLEGRO_BITMAP* bitmap3 = al_load_bitmap("3.png");
    ALLEGRO_BITMAP* bitmapnull = al_load_bitmap("null.png");
    ALLEGRO_BITMAP* n1 = al_load_bitmap("n1.png");
    ALLEGRO_BITMAP* n2 = al_load_bitmap("n2.png");
    ALLEGRO_BITMAP* n3 = al_load_bitmap("n3.png");
    ALLEGRO_BITMAP* n4 = al_load_bitmap("n4.png");
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;
   
    int i = 0, j = -1, z = 0;
    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }
        
           if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                x = event.mouse.x;
                y = event.mouse.y;
                if (n == 4) {
                    if (i % (2 * n) == 0) { a1 = x; b1 = y; }
                    if (i % (2 * n) == 1) { a2 = x; b2 = y; }
                    if (i % (2 * n) == 2) { a3 = x; b3 = y; }
                    if (i % (2 * n) == 3) { a4 = x; b4 = y; }
                    if (i % (2 * n) == 4) { a5 = x; b5 = y; }
                    if (i % (2 * n) == 5) { a6 = x; b6 = y; }
                    if (i % (2 * n) == 6) { a7 = x; b7 = y; }
                    if (i % (2 * n) == 7) { a8 = x; b8 = y; }
                }
                if (n == 3) {
                    if (i % (3 * n) == 0) { a1 = x; b1 = y; }
                    if (i % (3 * n) == 1) { a2 = x; b2 = y; }
                    if (i % (3 * n) == 2) { a3 = x; b3 = y; }
                    if (i % (3 * n) == 3) { a4 = x; b4 = y; }
                    if (i % (3 * n) == 4) { a5 = x; b5 = y; }
                    if (i % (3 * n) == 5) { a6 = x; b6 = y; }
                    if (i % (3 * n) == 6) { a7 = x; b7 = y; }
                    if (i % (3 * n) == 7) { a8 = x; b8 = y; }
                    if (i % (3 * n) == 8) { a9 = x; b9 = y; }
                }
                if (n == 2) {
                    if (i % (4 * n) == 0) { a1 = x; b1 = y; }
                    if (i % (4 * n) == 1) { a2 = x; b2 = y; }
                    if (i % (4 * n) == 2) { a3 = x; b3 = y; }
                    if (i % (4 * n) == 3) { a4 = x; b4 = y; }
                    if (i % (4 * n) == 4) { a5 = x; b5 = y; }
                    if (i % (4 * n) == 5) { a6 = x; b6 = y; }
                    if (i % (4 * n) == 6) { a7 = x; b7 = y; }
                    if (i % (4 * n) == 7) { a8 = x; b8 = y; }
                }

                i++; j++;
           }
           if (x > 200 && x < 296 && y>100 && y < 185)l[0] = 1;
           else if (x > 296 && x < 392 && y>100 && y < 185)l[1] = 1;
           else if (x > 392 && x < 488 && y>100 && y < 185)l[2] = 1;
           else if (x > 488 && x < 584 && y>100 && y < 185)l[3] = 1;
           else if (x > 584 && x < 680 && y>100 && y < 185)l[4] = 1;
           else if (x > 680 && x < 776 && y>100 && y < 185)l[5] = 1;
           else if (x > 776 && x < 872 && y>100 && y < 185)l[6] = 1;
           else if (x > 152 && x < 248 && y>185 && y < 270)l[7] = 1;
           else if (x > 248 && x < 344 && y>185 && y < 270)l[8] = 1;
           else if (x > 344 && x < 440 && y>185 && y < 270)l[9] = 1;
           else if (x > 440 && x < 536 && y>185 && y < 270)l[10] = 1;
           else if (x > 536 && x < 632 && y>185 && y < 270)l[11] = 1;
           else if (x > 632 && x < 728 && y>185 && y < 270)l[12] = 1;
           else if (x > 728 && x < 824 && y>185 && y < 270)l[13] = 1;
           else if (x > 824 && x < 920 && y>185 && y < 270)l[14] = 1;
           else if (x > 200 && x < 296 && y>270 && y < 355)l[15] = 1;
           else if (x > 296 && x < 392 && y>270 && y < 355)l[16] = 1;
           else if (x > 392 && x < 488 && y>270 && y < 355)l[17] = 1;
           else if (x > 488 && x < 584 && y>270 && y < 355)l[18] = 1;
           else if (x > 584 && x < 680 && y>270 && y < 355)l[19] = 1;
           else if (x > 680 && x < 776 && y>270 && y < 355)l[20] = 1;
           else if (x > 776 && x < 872 && y>270 && y < 355)l[21] = 1;
           else if (x > 152 && x < 248 && y>355 && y < 440)l[22] = 1;
           else if (x > 248 && x < 344 && y>355 && y < 440)l[23] = 1;
           else if (x > 344 && x < 440 && y>355 && y < 440)l[24] = 1;
           else if (x > 440 && x < 536 && y>355 && y < 440)l[25] = 1;
           else if (x > 536 && x < 632 && y>355 && y < 440)l[26] = 1;
           else if (x > 632 && x < 728 && y>355 && y < 440)l[27] = 1;
           else if (x > 728 && x < 824 && y>355 && y < 440)l[28] = 1;
           else if (x > 824 && x < 920 && y>355 && y < 440)l[29] = 1;
           else if (x > 200 && x < 296 && y>440 && y < 525)l[30] = 1;
           else if (x > 296 && x < 392 && y>440 && y < 525)l[31] = 1;
           else if (x > 392 && x < 488 && y>440 && y < 525)l[32] = 1;
           else if (x > 488 && x < 584 && y>440 && y < 525)l[33] = 1;
           else if (x > 584 && x < 680 && y>440 && y < 525)l[34] = 1;
           else if (x > 680 && x < 786 && y>440 && y < 525)l[35] = 1;
           else if (x > 786 && x < 872 && y>440 && y < 525)l[36] = 1;
           else if (x > 152 && x < 248 && y>525 && y < 610)l[37] = 1;
           else if (x > 248 && x < 344 && y>525 && y < 610)l[38] = 1;
           else if (x > 344 && x < 440 && y>525 && y < 610)l[39] = 1;
           else if (x > 440 && x < 536 && y>525 && y < 610)l[40] = 1;
           else if (x > 536 && x < 632 && y>525 && y < 610)l[41] = 1;
           else if (x > 632 && x < 728 && y>525 && y < 610)l[42] = 1;
           else if (x > 728 && x < 824 && y>525 && y < 610)l[43] = 1;
           else if (x > 824 && x < 920 && y>525 && y < 610)l[44] = 1;
           else if (x > 200 && x < 296 && y>610 && y < 695)l[45] = 1;
           else if (x > 296 && x < 392 && y>610 && y < 695)l[46] = 1;
           else if (x > 392 && x < 488 && y>610 && y < 695)l[47] = 1;
           else if (x > 488 && x < 584 && y>610 && y < 695)l[48] = 1;
           else if (x > 584 && x < 680 && y>610 && y < 695)l[49] = 1;
           else if (x > 680 && x < 776 && y>610 && y < 695)l[50] = 1;
           else if (x > 776 && x < 872 && y>610 && y < 695)l[51] = 1;
           else if (x > 152 && x < 248 && y>695 && y < 780)l[52] = 1;
           else if (x > 248 && x < 344 && y>695 && y < 780)l[53] = 1;
           else if (x > 344 && x < 440 && y>695 && y < 780)l[54] = 1;
           else if (x > 440 && x < 536 && y>695 && y < 780)l[55] = 1;
           else if (x > 536 && x < 632 && y>695 && y < 780)l[56] = 1;
           else if (x > 632 && x < 728 && y>695 && y < 780)l[57] = 1;
           else if (x > 728 && x < 824 && y>695 && y < 780)l[58] = 1;
           else if (x > 824 && x < 920 && y>695 && y < 780)l[59] = 1;








        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 30, 100));

            al_draw_bitmap(bitmap3, 200, 100, 1);
            al_draw_bitmap(bitmap1, 296, 100, 1);
            al_draw_bitmap(bitmap1, 392, 100, 0);
            al_draw_bitmap(bitmap1, 488, 100, 0);
            al_draw_bitmap(bitmap1, 584, 100, 0);
            al_draw_bitmap(bitmap1, 680, 100, 0);
            al_draw_bitmap(bitmap2, 776, 100, 0);
            al_draw_bitmap(bitmap3, 152, 185, 0);
            al_draw_bitmap(bitmap2, 248, 185, 0);
            al_draw_bitmap(bitmap1, 344, 185, 0);
            al_draw_bitmap(bitmap3, 440, 185, 0);
            al_draw_bitmap(bitmap1, 536, 185, 0);
            al_draw_bitmap(bitmap1, 632, 185, 0);
            al_draw_bitmap(bitmap2, 728, 185, 0);
            al_draw_bitmap(bitmap2, 824, 185, 0);
            al_draw_bitmap(bitmap1, 200, 270, 0);
            al_draw_bitmap(bitmap2, 296, 270, 0);
            al_draw_bitmap(bitmap2, 392, 270, 0);
            al_draw_bitmap(bitmap1, 488, 270, 0);
            al_draw_bitmap(bitmap3, 584, 270, 0);
            al_draw_bitmap(bitmap1, 680, 270, 0);
            al_draw_bitmap(bitmap2, 776, 270, 0);
            al_draw_bitmap(bitmap2, 152, 355, 0);
            al_draw_bitmap(bitmap3, 248, 355, 0);
            al_draw_bitmap(bitmap1, 344, 355, 0);
            al_draw_bitmap(bitmap3, 440, 355, 0);
            al_draw_bitmap(bitmap2, 536, 355, 0);
            al_draw_bitmap(bitmap3, 632, 355, 0);
            al_draw_bitmap(bitmap2, 728, 355, 0);
            al_draw_bitmap(bitmap3, 824, 355, 0);
            al_draw_bitmap(bitmap1, 200, 440, 0);
            al_draw_bitmap(bitmap1, 296, 440, 0);
            al_draw_bitmap(bitmap3, 392, 440, 0);
            al_draw_bitmap(bitmap3, 488, 440, 0);
            al_draw_bitmap(bitmap2, 584, 440, 0);
            al_draw_bitmap(bitmap2, 680, 440, 0);
            al_draw_bitmap(bitmap1, 776, 440, 0);
            al_draw_bitmap(bitmap2, 152, 525, 0);
            al_draw_bitmap(bitmap2, 248, 525, 0);
            al_draw_bitmap(bitmap3, 344, 525, 0);
            al_draw_bitmap(bitmap3, 440, 525, 0);
            al_draw_bitmap(bitmap2, 536, 525, 0);
            al_draw_bitmap(bitmap2, 632, 525, 0);
            al_draw_bitmap(bitmap1, 728, 525, 0);
            al_draw_bitmap(bitmap2, 824, 525, 0);
            al_draw_bitmap(bitmap1, 200, 610, 0);
            al_draw_bitmap(bitmap2, 296, 610, 0);
            al_draw_bitmap(bitmap2, 392, 610, 0);
            al_draw_bitmap(bitmap3, 488, 610, 0);
            al_draw_bitmap(bitmap1, 584, 610, 0);
            al_draw_bitmap(bitmap1, 680, 610, 0);
            al_draw_bitmap(bitmap2, 776, 610, 0);
            al_draw_bitmap(bitmap3, 152, 695, 0);
            al_draw_bitmap(bitmap3, 248, 695, 0);
            al_draw_bitmap(bitmap1, 344, 695, 0);
            al_draw_bitmap(bitmap1, 440, 695, 0);
            al_draw_bitmap(bitmap1, 536, 695, 0);
            al_draw_bitmap(bitmap1, 632, 695, 0);
            al_draw_bitmap(bitmap2, 728, 695, 0);
            al_draw_bitmap(bitmap1, 824, 695, 0);

            if (l[0] == 1) { 
                al_draw_bitmap(bitmapnull, 200, 100, 1);
            }
            if (l[1] == 1) {
                al_draw_bitmap(bitmapnull, 296, 100, 1);
            }
            if (l[2] == 1) {
                al_draw_bitmap(bitmapnull, 392, 100, 0);
            }
            if (l[3] == 1) {
                al_draw_bitmap(bitmapnull, 488, 100, 0);
            }
            if (l[4] == 1) {
                al_draw_bitmap(bitmapnull, 584, 100, 0);
            }
            if (l[5] == 1) {
                al_draw_bitmap(bitmapnull, 680, 100, 0);
            }
            if (l[6] == 1) {
                al_draw_bitmap(bitmapnull, 776, 100, 0);
            }
            if (l[7] == 1) {
                al_draw_bitmap(bitmapnull, 152, 185, 0);
            }
            if (l[8] == 1) {
                al_draw_bitmap(bitmapnull, 248, 185, 0);
            }
            if (l[9] == 1) {
                al_draw_bitmap(bitmapnull, 344, 185, 0);
            }
            if (l[10] == 1) {
                al_draw_bitmap(bitmapnull, 440, 185, 0);
            }
            if (l[11] == 1) {
                al_draw_bitmap(bitmapnull, 536, 185, 0);
            }
            if (l[12] == 1) {
                al_draw_bitmap(bitmapnull, 632, 185, 0);
            }
            if (l[13] == 1) {
                al_draw_bitmap(bitmapnull, 728, 185, 0);
            }
            if (l[14] == 1) {
                al_draw_bitmap(bitmapnull, 824, 185, 0);
            }
            if (l[15] == 1) {
                al_draw_bitmap(bitmapnull, 200, 270, 0);
            }
            if (l[16] == 1) {
                al_draw_bitmap(bitmapnull, 296, 270, 0);
            }
            if (l[17] == 1) {
                al_draw_bitmap(bitmapnull, 392, 270, 0);
            }
            if (l[18] == 1) {
                al_draw_bitmap(bitmapnull, 488, 270, 0);
            }
            if (l[19] == 1) {
                al_draw_bitmap(bitmapnull, 584, 270, 0);
            }
            if (l[20] == 1) {
                al_draw_bitmap(bitmapnull, 680, 270, 0);
            }
            if (l[21] == 1) {
                al_draw_bitmap(bitmapnull, 776, 270, 0);
            }
            if (l[22] == 1) {
                al_draw_bitmap(bitmapnull, 152, 355, 0);
            }
            if (l[23] == 1) {
                al_draw_bitmap(bitmapnull, 248, 355, 0);
            }
            if (l[24] == 1) {
                al_draw_bitmap(bitmapnull, 344, 355, 0);
            }
            if (l[25] == 1) {
                al_draw_bitmap(bitmapnull, 440, 355, 0);
            }
            if (l[26] == 1) {
                al_draw_bitmap(bitmapnull, 536, 355, 0);
            }
            if (l[27] == 1) {
                al_draw_bitmap(bitmapnull, 632, 355, 0);
            }
            if (l[28] == 1) {
                al_draw_bitmap(bitmapnull, 728, 355, 0);
            }
            if (l[29] == 1) {
                al_draw_bitmap(bitmapnull, 824, 355, 0);
            }
            if (l[30] == 1) {
                al_draw_bitmap(bitmapnull, 200, 440, 0);
            }
            if (l[31] == 1) {
                al_draw_bitmap(bitmapnull, 296, 440, 0);
            }
            if (l[32] == 1) {
                al_draw_bitmap(bitmapnull, 392, 440, 0);
            }
            if (l[33] == 1) {
                al_draw_bitmap(bitmapnull, 488, 440, 0);
            }
            if (l[34] == 1) {
                al_draw_bitmap(bitmapnull, 584, 440, 0);
            }
            if (l[35] == 1) {
                al_draw_bitmap(bitmapnull, 680, 440, 0);
            }
            if (l[36] == 1) {
                al_draw_bitmap(bitmapnull, 776, 440, 0);
            }
            if (l[37] == 1) {
                al_draw_bitmap(bitmapnull, 152, 525, 0);
            }
            if (l[38] == 1) {
                al_draw_bitmap(bitmapnull, 248, 525, 0);
            }
            if (l[39] == 1) {
                al_draw_bitmap(bitmapnull, 344, 525, 0);
            }
            if (l[40] == 1) {
                al_draw_bitmap(bitmapnull, 440, 525, 0);
            }
            if (l[41] == 1) {
                al_draw_bitmap(bitmapnull, 536, 525, 0);
            }
            if (l[42] == 1) {
                al_draw_bitmap(bitmapnull, 632, 525, 0);
            }
            if (l[43] == 1) {
                al_draw_bitmap(bitmapnull, 728, 525, 0);
            }
            if (l[44] == 1) {
                al_draw_bitmap(bitmapnull, 824, 525, 0);
            }
            if (l[45] == 1) {
                al_draw_bitmap(bitmapnull, 200, 610, 0);
            }
            if (l[46] == 1) {
                al_draw_bitmap(bitmapnull, 296, 610, 0);
            }
            if (l[47] == 1) {
                al_draw_bitmap(bitmapnull, 392, 610, 0);
            }
            if (l[48] == 1) {
                al_draw_bitmap(bitmapnull, 488, 610, 0);
            }
            if (l[49] == 1) {
                al_draw_bitmap(bitmapnull, 584, 610, 0);
            }
            if (l[50] == 1) {
                al_draw_bitmap(bitmapnull, 680, 610, 0);
            }
            if (l[51] == 1) {
                al_draw_bitmap(bitmapnull, 776, 610, 0);
            }
            if (l[52] == 1) {
                al_draw_bitmap(bitmapnull, 152, 695, 0);
            }
            if (l[53] == 1) {
                al_draw_bitmap(bitmapnull, 248, 695, 0);
            }
            if (l[54] == 1) {
                al_draw_bitmap(bitmapnull, 344, 695, 0);
            }
            if (l[55] == 1) {
                al_draw_bitmap(bitmapnull, 440, 695, 0);
            }
            if (l[56] == 1) {
                al_draw_bitmap(bitmapnull, 536, 695, 0);
            }
            if (l[57] == 1) {
                al_draw_bitmap(bitmapnull, 632, 695, 0);
            }
            if (l[58] == 1) {
                al_draw_bitmap(bitmapnull, 728, 695, 0);
            }
            if (l[59] == 1) {
                al_draw_bitmap(bitmapnull, 824, 695, 0);
            }
            
           
            if (n == 4) {
                al_draw_bitmap(n1, a1 - 20, b1 - 20, 0);
                al_draw_bitmap(n2, a2 - 20, b2 - 20, 0);
                al_draw_bitmap(n3, a3 - 20, b3 - 20, 0);
                al_draw_bitmap(n4, a4 - 20, b4 - 20, 0);
                al_draw_bitmap(n1, a5 - 20, b5 - 20, 0);
                al_draw_bitmap(n2, a6 - 20, b6 - 20, 0);
                al_draw_bitmap(n3, a7 - 20, b7 - 20, 0);
                al_draw_bitmap(n4, a8 - 20, b8 - 20, 0);
            }
            if (n == 3) {
                al_draw_bitmap(n1, a1 - 20, b1 - 20, 0);
                al_draw_bitmap(n2, a2 - 20, b2 - 20, 0);
                al_draw_bitmap(n3, a3 - 20, b3 - 20, 0);
                al_draw_bitmap(n1, a4 - 20, b4 - 20, 0);
                al_draw_bitmap(n2, a5 - 20, b5 - 20, 0);
                al_draw_bitmap(n3, a6 - 20, b6 - 20, 0);
                al_draw_bitmap(n1, a7 - 20, b7 - 20, 0);
                al_draw_bitmap(n2, a8 - 20, b8 - 20, 0);
                al_draw_bitmap(n3, a9 - 20, b9 - 20, 0);
            }
            if (n == 2) {
                al_draw_bitmap(n1, a1 - 20, b1 - 20, 0);
                al_draw_bitmap(n2, a2 - 20, b2 - 20, 0);
                al_draw_bitmap(n1, a3 - 20, b3 - 20, 0);
                al_draw_bitmap(n2, a4 - 20, b4 - 20, 0);
                al_draw_bitmap(n1, a5 - 20, b5 - 20, 0);
                al_draw_bitmap(n2, a6 - 20, b6 - 20, 0);
                al_draw_bitmap(n1, a7 - 20, b7 - 20, 0);
                al_draw_bitmap(n2, a8 - 20, b8 - 20, 0);
            }



            al_flip_display();

            redraw = false;
        }
    }
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_uninstall_mouse();
    al_destroy_event_queue(queue);
    al_destroy_bitmap(bitmap1);
    al_destroy_bitmap(bitmap2);
    al_destroy_bitmap(bitmap3);
    al_destroy_bitmap(bitmapnull);
    al_destroy_bitmap(n1);
    al_destroy_bitmap(n2);
    al_destroy_bitmap(n3);
    al_destroy_bitmap(n4);

    return 0;
}
int main(){
    
   printf("The number of players: ");
   scanf("%d", &n);
   start();
   game();
}