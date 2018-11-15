#include "ground.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern BGround_ BGround;



void draw_main(input input_info)
	{

	srand(time(NULL));
	static int music = 1;
	if (music == 1)
	{
		start_music("music.mp3");
		music = 0;
	}
	static int px = 40, py = 250;
	static int p2x = 438, p2y = 250;
	static int init = 1;
	static int timer = 0;
	// Gamefield
	static int x = 30, x2 = 448, y = 30, y2 = 448;
	draw_line(x, y, x2, y, 255, 255, 255, 0);
	draw_line(x, y2, x2, y2, 255, 255, 255, 0);
	draw_line(x, y, x, y2, 255, 255, 255, 0);
	draw_line(x2, y, x2, y2, 255, 255, 255, 0);

	// Player scores
	static int p1highscore = 0, p2highscore = 0;
	char text[100];
	char text2[100];
	sprintf(text, "Player 1 Score: %d", p1highscore);
	sprintf(text2, "Player 2 Score: %d", p2highscore);
	draw_text(text, 30, 10, 225, 0, 0);
	draw_text(text2, 340, 10, 0, 0, 225);
	//Ball
	static int ballx = (x + x2) / 2;
	static int bally = (y + y2) / 2;
	static int directionx = rand() % 2;
	static int directiony = rand() % 2;
	static int k = 1;
	draw_text("O", ballx, bally, 0, 225, 0);

	if (init == 1)
	{
		init = 0;
		timer = 0;
		px = 40, py = 250;
		p2x = 438; p2y = 250;
		ballx = (x + x2) / 2;
		bally = (y + y2) / 2;
		draw_text("O", ballx, bally, 0, 225, 0);
		directionx = directionx;
		directiony = directiony;
		draw_line(px, py - 20, px, py + 20, 225, 0, 0, 5);
		draw_line(p2x, p2y - 20, p2x, p2y + 20, 0, 0, 225, 5);
	}

	// Paddle movement
	if (p1highscore < 5 && p2highscore < 5)
	{
		if (input_info.s_key_down == 1 && input_info.w_key_down == 0)
		{
			if (py < 425)
			{
				py += 5;
				draw_line(px, py - 20, px, py + 20, 225, 0, 0, 5);
			}
		}
		if (input_info.w_key_down == 1 && input_info.s_key_down == 0)
		{
			if (py > 55)
			{
				py -= 5;
				draw_line(px, py - 20, px, py + 20, 225, 0, 0, 5);
			}
		}
		if (input_info.down_cursor_down == 1 && input_info.up_cursor_down == 0)
		{
			if (p2y < 425)
			{
				p2y += 5;
				draw_line(p2x, p2y - 20, p2x, p2y + 20, 0, 0, 225, 5);
			}
		}
		if (input_info.up_cursor_down == 1 && input_info.down_cursor_down == 0)
		{
			if (p2y > 55)
			{
				p2y -= 5;
				draw_line(p2x, p2y - 20, p2x, p2y + 20, 0, 0, 225, 5);
			}
		}
	}
	else
	{
		if (input_info.s_key_down == 1 && input_info.w_key_down == 0)
		{
			if (py < 425)
			{
				py += 7;
				draw_line(px, py - 20, px, py + 20, 225, 0, 0, 5);
			}
		}
		if (input_info.w_key_down == 1 && input_info.s_key_down == 0)
		{
			if (py > 55)
			{
				py -= 7;
				draw_line(px, py - 20, px, py + 20, 225, 0, 0, 5);
			}
		}
		if (input_info.down_cursor_down == 1 && input_info.up_cursor_down == 0)
		{
			if (p2y < 425)
			{
				p2y += 7;
				draw_line(p2x, p2y - 20, p2x, p2y + 20, 0, 0, 225, 5);
			}
		}
		if (input_info.up_cursor_down == 1 && input_info.down_cursor_down == 0)
		{
			if (p2y > 55)
			{
				p2y -= 7;
				draw_line(p2x, p2y - 20, p2x, p2y + 20, 0, 0, 225, 5);
			}
		}
	}
	//Pong rackets
	draw_line(px, py - 20, px, py + 20, 225, 0, 0, 5);
	draw_line(p2x, p2y - 20, p2x, p2y + 20, 0, 0, 225, 5);

	// Ball movement
	if (p1highscore < 5 && p2highscore < 5)
	{
		if (directionx == 1)
		{
			ballx += 2 + k;
		}
		else
		{
			ballx -= 2 + k;
		}
		if (directiony == 1)
		{
			bally += 3 + k;
		}
		else
		{
			bally -= 3 + k;
		}
	}
	else
	{
		if (directionx == 1)
		{
			ballx += 4 + k;
		}
		else
		{
			ballx -= 4 + k;
		}
		if (directiony == 1)
		{
			bally += 5 + k;
		}
		else
		{
			bally -= 5 + k;
		}
	}
	// Ball hits the wall
	if (bally < y + 1)
	{
		directiony = 1;
	}
	if (bally > y2 - 16)
	{
		directiony = 0;
	}
	// Ball hits the paddle
	if (ballx < px + 1 && (bally > py - 20 && bally < py + 20))
	{
		directionx = 1;
		if (input_info.w_key_down == 0)
		{
			directiony = 0;
		}
		else
		{
			directiony = 1;
		}
	}
	if (ballx > p2x - 15 && (bally > p2y - 20 && bally < p2y + 20))
	{
		directionx = 0;
		if (input_info.up_cursor_down == 0)
		{
			directiony = 0;
		}
		else
		{
			directiony = 1;
		}
	}
	// Player 1 Scores
	if (ballx > 448)
	{
		timer++;
		if (timer == 5)
		{
			init = 1;
			p1highscore += 1;
		}
		if (p1highscore == 10)
		{
			PostQuitMessage(0);
		}
	}
	// Player 2 Scores
	if (ballx < 30)
	{
		timer++;
		if (timer == 5)
		{
			init = 1;
			p2highscore += 1;
		}
		if (p2highscore == 10)
		{
			PostQuitMessage(0);
		}
	}
	}