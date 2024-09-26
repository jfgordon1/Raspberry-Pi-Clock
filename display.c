#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sense.h"
#include "display.h"

#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x1F
#define GREEN 0x7E0
#define RED 0xF800



int open_display(void) {
	pi_framebuffer_t *fb=getFrameBuffer();
	sense_fb_bitmap_t *bm=fb->bitmap;
	if(fb) {
		return 1;
	}else {
		return 0;
	}
}

void display_colons(void){
	pi_framebuffer_t *fb=getFrameBuffer();
    	sense_fb_bitmap_t *bm=fb->bitmap;

	//Top left colon dot
	bm->pixel[5][2]=WHITE;
	bm->pixel[5][3]=WHITE;
	bm->pixel[4][2]=WHITE;
	bm->pixel[4][3]=WHITE;
	//Top right colon dot
	bm->pixel[2][2]=WHITE;
        bm->pixel[2][3]=WHITE;
        bm->pixel[1][2]=WHITE;
        bm->pixel[1][3]=WHITE;
	//Bottom left colon dot
	bm->pixel[5][5]=WHITE;
        bm->pixel[5][6]=WHITE;
        bm->pixel[4][5]=WHITE;
        bm->pixel[4][6]=WHITE;
	//Bottom right colon dot
	bm->pixel[1][5]=WHITE;
        bm->pixel[1][6]=WHITE;
        bm->pixel[2][5]=WHITE;
        bm->pixel[2][6]=WHITE;
}

void display_hours(int hours) {
	pi_framebuffer_t *fb=getFrameBuffer();
	sense_fb_bitmap_t *bm=fb->bitmap;

	int sixteens_place = 0;
	int eights_place = 0;
	int fours_place = 0;
	int twos_place = 0;
	int ones_place = 0;

        //binary calculations
	if (hours - 16 >= 0){
		hours = hours - 16;
		sixteens_place = 1;
	}

	if (hours - 8 >= 0){
                hours = hours - 8;
                eights_place = 1;
        }

	if (hours - 4 >= 0){
                hours = hours - 4;
                fours_place = 1;
        }

	if (hours - 2 >= 0){
                hours = hours - 2;
                twos_place = 1;
        }

	if (hours - 1 >= 0){
                hours = hours - 1;
                ones_place = 1;
        }

        //led display
        if (sixteens_place == 1) {
		bm->pixel[6][3]=BLUE;
	}else {
		bm->pixel[6][3]=BLACK;
	}

        if (eights_place == 1) {
                bm->pixel[6][4]=BLUE;
        }else {
                bm->pixel[6][4]=BLACK;
        }

        if (fours_place == 1) {
                bm->pixel[6][5]=BLUE;
        }else {
                bm->pixel[6][5]=BLACK;
        }

        if (twos_place == 1) {
                bm->pixel[6][6]=BLUE;
        }else {
                bm->pixel[6][6]=BLACK;
        }

        if (ones_place == 1) {
                bm->pixel[6][7]=BLUE;
        }else {
                bm->pixel[6][7]=BLACK;
        }
}

void display_minutes(int minutes){
	pi_framebuffer_t *fb=getFrameBuffer();
        sense_fb_bitmap_t *bm=fb->bitmap;

	int thirtytwos_place = 0;
        int sixteens_place = 0;
        int eights_place = 0;
        int fours_place = 0;
        int twos_place = 0;
        int ones_place = 0;

	// binary calculations
        if (minutes - 32 >= 0){
                minutes = minutes - 32;
                thirtytwos_place = 1;
        }

        if (minutes - 16 >= 0){
                minutes = minutes - 16;
                sixteens_place = 1;
        }

        if (minutes - 8 >= 0){
                minutes = minutes - 8;
                eights_place = 1;
        }

        if (minutes - 4 >= 0){
                minutes = minutes - 4;
                fours_place = 1;
        }

        if (minutes - 2 >= 0){
                minutes = minutes - 2;
                twos_place = 1;
        }

        if (minutes - 1 >= 0){
                minutes = minutes - 1;
                ones_place = 1;
        }

        //led display
        if (thirtytwos_place == 1) {
                bm->pixel[3][2]=GREEN;
        }else {
                bm->pixel[3][2]=BLACK;
        }

        if (sixteens_place == 1) {
                bm->pixel[3][3]=GREEN;
        }else {
                bm->pixel[3][3]=BLACK;
        }

        if (eights_place == 1) {
                bm->pixel[3][4]=GREEN;
        }else {
                bm->pixel[3][4]=BLACK;
        }

        if (fours_place == 1) {
                bm->pixel[3][5]=GREEN;
        }else {
                bm->pixel[3][5]=BLACK;
        }

        if (twos_place == 1) {
                bm->pixel[3][6]=GREEN;
        }else {
                bm->pixel[3][6]=BLACK;
        }

        if (ones_place == 1) {
                bm->pixel[3][7]=GREEN;
        }else {
                bm->pixel[3][7]=BLACK;
        }
}

void display_seconds(int seconds){
 	pi_framebuffer_t *fb=getFrameBuffer();
        sense_fb_bitmap_t *bm=fb->bitmap;

        int thirtytwos_place = 0;
        int sixteens_place = 0;
        int eights_place = 0;
        int fours_place = 0;
        int twos_place = 0;
        int ones_place = 0;

        //binary calculations
        if (seconds - 32 >= 0){
                seconds = seconds - 32;
                thirtytwos_place = 1;
        }

        if (seconds - 16 >= 0) {
                seconds = seconds - 16;
                sixteens_place = 1;
        }

        if (seconds - 8 >= 0) {
                seconds = seconds - 8;
                eights_place = 1;
        }

        if (seconds - 4 >= 0) {
                seconds = seconds - 4;
                fours_place = 1;
        }

	//2s binary digit display
        if (seconds - 2 >= 0) {
                seconds = seconds - 2;
                twos_place = 1;
        }
        
        if (seconds - 1 >= 0){
                seconds = seconds - 1;
                ones_place = 1;
        }

        // led display
        if (thirtytwos_place == 1) {
                bm->pixel[0][2]=RED;
        }else {
                bm->pixel[0][2]=BLACK;
        }

        if (sixteens_place == 1) {
                bm->pixel[0][3]=RED;
        }else {
                bm->pixel[0][3]=BLACK;
        }

        if (eights_place == 1) {
                bm->pixel[0][4]=RED;
        }else {
                bm->pixel[0][4]=BLACK;
        }

        if (fours_place == 1) {
                bm->pixel[0][5]=RED;
        }else {
                bm->pixel[0][5]=BLACK;
        }

        if (twos_place == 1) {
                bm->pixel[0][6]=RED;
        }else {
                bm->pixel[0][6]=BLACK;
        }


        if (ones_place == 1) {
                bm->pixel[0][7]=RED;
        }else {
                bm->pixel[0][7]=BLACK;
        }

}

void display_time(int hours, int minutes, int seconds) {
        display_colons();
        display_hours(hours);
        display_minutes(minutes);
        display_seconds(seconds);
}


void close_display(void) {
	pi_framebuffer_t *fb=getFrameBuffer();
        clearFrameBuffer(fb,BLACK);
	sleep(1);
	freeFrameBuffer(fb);
}
