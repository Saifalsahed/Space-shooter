#include "iGraphics.h"

#define MAX_NUMBER_OF_BULLETS 20
#define MAX_NUMBER_OF_BOSS_BULLETS 20
#define LENGHTH_OF_AIRCRAFT 66
#define HEIGTH_OF_AIRCRAFT 141
#define NUMBEROFENEMY 400
#define SCREENWIDTH 1200
#define SCREENHEIGHT 720
#define TOTALENEMY 5
struct bullet
{
	int x, y;
	bool isalive;
};
struct bullet bullets[MAX_NUMBER_OF_BULLETS];
struct bossbullet
{
	int bossbulletX, bossbulletY;
	bool show;
};
struct bossbullet bb[MAX_NUMBER_OF_BOSS_BULLETS];
struct enemy1
{
	int x, y, initial_X;
	bool On = false;
};
enemy1 e1[5];
int enemyIndex1 = 0;
typedef struct enemy2 enemy2;
struct enemy2
{
	int x = 0, y = 0, initial_X;
	bool On = false;
};
enemy2 e2[5];
int enemyIndex2 = 0;
typedef struct enemy3 enemy3;
struct enemy3
{
	int x = 0, y = 0, initial_X;
	bool On = false;
};
enemy3 e3[5];
int enemyIndex3 = 0;
typedef struct enemy4 enemy4;
struct enemy4
{
	int x = 0, y = 0, initial_X;
	bool On = false;
};
enemy4 e4[5];
int enemyIndex4 = 0;
typedef struct enemy5 enemy5;
struct enemy5
{
	int x = 0, y = 0, initial_X;
	bool On = false;
};
enemy5 e5[5];
int enemyIndex5 = 0;
struct enemy6
{
	int x = 0, y = 0, initial_X;
	bool On = false;
};
enemy6 e6[5];
struct boss
{
	int boss_x, boss_y;
	bool boss_on;
};
struct boss Boss;
int leaserX, leaserY;
int laser_show = 0;
int laserflag = 0;
int bx = 0, by = 0, dx = 10, dy = 5;
char background[] = "bp\\Backgroundimage.bmp";
int mode = 0;
/*function iDraw() is called again and again by the system.
 */
int i, lx, ly, gmstate = 0;
int j = 1, k = 0;
int bulletMoveTimer, enemyMoveTimer, enemyinitializer;
int boss = 0;
int score = 0;
int bosslife = 5,life=5;
int bss=1;
char sscore[10];
char bossscore[20];
char olife[20];
char rscore[20];
int d;
int gmover=0;
FILE *f;
// int bulletX[MAX_NUMBER_OF_BULLETS],bulletY[MAX_NUMBER_OF_BULLETS];
// int bulletsisalive[MAX_NUMBER_OF_BULLETS];
int numberOfBullets = 0, numberofbossbullets = 0; // number bullets on the screen
void highscore()
{
	iShowBMP(0,0,"bp\\highscore.bmp");
	FILE *fp=fopen("score.txt","r");
	iSetColor(255,255,255);
	fgets(rscore,20,fp);
	iText(300,300,rscore,GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0,0,255);
	fclose(fp);
}
void showMainMenu()
{
	iShowBMP(0, 0, "bp\\MainMenu.bmp");
	iSetColor(123, 266, 345);
	iFilledRectangle(60, 300, 125, 40);
	iFilledRectangle(60, 250, 125, 40);
	iFilledRectangle(60, 200, 125, 40);
	//iFilledRectangle(60, 150, 125, 40);
	iSetColor(25, 124, 250);
	iText(65, 310, "Start Game", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(65, 265, "Instruction", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(63, 215, "Last Score", GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(65, 165, "About Us", GLUT_BITMAP_TIMES_ROMAN_24);
}
void showinstruction()
{
	iShowBMP(0, 0, "bp\\instructions.bmp");
	//iSetColor(123, 266, 345);
	//iFilledRectangle(600, 100, 65, 30);
	//iSetColor(25, 124, 250);
	//iText(605, 110, "Return", GLUT_BITMAP_9_BY_15);
}
void End()
{
	if((bosslife==0 && Boss.boss_on==false) || life<=0)
	{
        for (int i = 0; i < MAX_NUMBER_OF_BOSS_BULLETS; i++)
		{
			bb[i].show = false;
		}
	}
}
void showGameInterface()
{
	f=fopen("score.txt","w");

	iShowBMP(0, 0, background);
	iShowBMP2(bx, by, "bp\\Spaceshuttle.bmp", 0);
	iText(7, 700, sscore, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(200, 700, olife, GLUT_BITMAP_TIMES_ROMAN_24);
	if(Boss.boss_on==true)
	{
		iText(1000, 700, bossscore, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (score  >= 6 && mode == 1 )
	{  
		if(bss>0)
		{
			Boss.boss_on = true;
			bss--;
		}
		if(Boss.boss_on == true)
		{

		
		iShowBMP2(Boss.boss_x + 600, Boss.boss_y + 350, "bp\\boss.bmp", 0);
		for (i = 0; i <= TOTALENEMY; i++)
		{
			e1[i].On = false;
			e2[i].On = false;
			e3[i].On = false;
			e4[i].On = false;
			e5[i].On = false;
		}
		}
	}
		if (bosslife <= 0){
						Boss.boss_on = false;
						gmover=1;
				}
	if (numberOfBullets > 0)
	{
		iSetColor(0, 0, 255);
		// int bulletsisalive = 0;
		for (int i = 0; i < MAX_NUMBER_OF_BULLETS; i++)
		{
			if (bullets[i].isalive)
			{
				// iFilledRectangle(bulletX[i],bulletY[i],5,10);
				iShowBMP2(bullets[i].x, bullets[i].y, "bp\\leaser.bmp", 0);
			}
			// for(int j=0;j<numberOfEnemiesOnScreen;j++){
			// check if this bullet/rectangle intersencts with the enemy
			// if true
			// flag the enemy
			// score counter++
			// bulletsisalive[i] = 1
			// }
		}
	}
	if (Boss.boss_on)
	{
		iSetColor(255, 0, 0);
		for (int i = 0; i < MAX_NUMBER_OF_BOSS_BULLETS; i++)
		{
			// bb[i].show=true;
			if (bb[i].show)
			{
				// bb[i].bossbulletX=Boss.boss_x;
				// bb[i].bossbulletY=Boss.boss_y;
				iShowBMP2(bb[i].bossbulletX, bb[i].bossbulletY, "bp\\boss_beam.bmp", 0);
			}
		}
	}
	/*if(Boss.boss_on){
	boss = 1;
	iShowBMP2(Boss.boss_x,Boss.boss_y+350, "bp\\boss.bmp", 0);
	for (i = 0; i <= TOTALENEMY; i++){
		e1[i].On = false;
		e2[i].On = false;
		e3[i].On = false;
		e4[i].On = false;
		e5[i].On = false;

	}}*/
	/*for (j = 0; j <= totalBullet; j++){
	s[j].gulliOn = false;
	}*/

	for (int i = 0; i < 5; i++)
	{
		if (e1[i].On)
		{
			iShowBMP2(e1[i].x, e1[i].y, "bp//enemy_ship.bmp", 0);
		}
		if (e2[i].On)
		{
			iShowBMP2(e2[i].x, e2[i].y, "bp//enemy_ship2.bmp", 0);
		}
		if (e3[i].On)
		{
			iShowBMP2(e3[i].x, e3[i].y, "bp//enemy_ship3.bmp", 0);
		}
		if (e4[i].On)
		{
			iShowBMP2(e4[i].x, e4[i].y, "bp//enemy_ship4.bmp", 0);
		}
		if (e5[i].On)
		{
			iShowBMP2(e5[i].x, e5[i].y, "bp//enemy_ship5.bmp", 0);
		}
	}
}

void Showlaser()
{
	iShowBMP2(leaserX, leaserY, "bp\\laser3.bmp", 0);
	leaserX = bx + LENGHTH_OF_AIRCRAFT / 2 - 15;
	leaserY = by + HEIGTH_OF_AIRCRAFT - 10;
}
void Bulletshoot()
{
	if (numberOfBullets < MAX_NUMBER_OF_BULLETS)
	{
		for (int i = 0; i < MAX_NUMBER_OF_BULLETS; i++)
		{
			if (!bullets[i].isalive)
			{
				bullets[i].x = bx + LENGHTH_OF_AIRCRAFT / 2 - 15;
				bullets[i].y = by + HEIGTH_OF_AIRCRAFT - 6;
				bullets[i].isalive = true;
				break;
			}
		}
		numberOfBullets++;
	}
}

void bossBulletshoot()
{   
	if(Boss.boss_on){
	if (numberOfBullets < MAX_NUMBER_OF_BOSS_BULLETS)
	{
		for (int i = 0; i < MAX_NUMBER_OF_BOSS_BULLETS; i++)
		{
			if (!bb[i].show)
			{
				bb[i].bossbulletX = Boss.boss_x + 650;
				bb[i].bossbulletY = Boss.boss_y + 350;
				bb[i].show = true;
				break;
			}
		}
		numberofbossbullets++;
	}
	}
}
void movebossBullet()
{   
	if(Boss.boss_on){
	if (numberofbossbullets > 0)
	{
		for (int i = 0; i < MAX_NUMBER_OF_BOSS_BULLETS; i++)
		{
			if (bb[i].show)
			{
				if (bb[i].bossbulletY < 0)
				{
					bb[i].show = false;
					numberofbossbullets--;
				}
				else
				{
					bb[i].bossbulletY -= 10;
					printf("%d", 5);
					// bulletX[i] +=10;
				}
			}
			//if(i==MAX_NUMBER_OF_BOSS_BULLETS-1)  i=0;
		}
		printf("number of bb: %d\n", numberofbossbullets);
	}
}
}
void callEnemy1()
{
	e1[enemyIndex1].On = true;
	e1[enemyIndex1].x = rand() % 1100;
	printf("%d:  ", e1[enemyIndex1].x);
	e1[enemyIndex1].y = 730;
	enemyIndex1++;
	if (enemyIndex1 > TOTALENEMY)
	{
		enemyIndex1 = 0;
	}
}
void callEnemy2()
{
	e2[enemyIndex2].On = true;
	e2[enemyIndex2].x = rand() % 1100;
	e2[enemyIndex2].y = 730;
	enemyIndex2++;
	if (enemyIndex2 > TOTALENEMY)
	{
		enemyIndex2 = 0;
	}
}
void callEnemy3()
{
	e3[enemyIndex3].On = true;
	e3[enemyIndex3].x = rand() % 1100;
	e3[enemyIndex3].y = 730;
	enemyIndex3++;
	if (enemyIndex3 > TOTALENEMY)
	{
		enemyIndex3 = 0;
	}
}
void callEnemy4()
{
	e4[enemyIndex4].On = true;
	e4[enemyIndex4].x = rand() % 1100;
	e4[enemyIndex4].y = 730;
	enemyIndex4++;
	if (enemyIndex4 > TOTALENEMY)
	{
		enemyIndex4 = 0;
	}
}
void callEnemy5()
{
	e5[enemyIndex5].On = true;
	e5[enemyIndex5].x = rand() % 1100;
	e5[enemyIndex5].y = 730;
	enemyIndex5++;
	if (enemyIndex5 > TOTALENEMY)
	{
		enemyIndex5 = 0;
	}
}
void enemyMove()
{
	if (mode == 1)
	{
		if (Boss.boss_on == false)
		{
			for (int i = 0; i < TOTALENEMY; i++)
			{
				if (e1[i].On == true)
				{
					if (e1[i].y > 0)
						e1[i].y -= 20;
					if (e1[i].y <= 0)
					{
						// e1[i].x=rand() % 5000 ;
						e1[i].y = 730;
						e1[i].On = false;
					}
				}
				if (e2[i].On == true)
				{
					if (e2[i].y > 0)
						e2[i].y -= 30;
					if (e2[i].y <= 0)
					{
						e2[i].x = rand() % 3000;
						e2[i].y = 730;
						e2[i].On = false;
					}
				}
				if (e3[i].On == true)
				{
					if (e3[i].y > 0)
						e3[i].y -= 25;
					if (e3[i].y <= 0)
					{
						// e3[i].x=rand()%3500;
						e3[i].y = 730;
						e3[i].On = false;
					}
				}
				if (e4[i].On == true)
				{
					if (e4[i].y > 0)
						e4[i].y -= 35;
					if (e4[i].x <= 0)
					{
						// e4[i].x=rand()%45;
						e4[i].y = 730;
						e4[i].On = false;
					}
				}
				if (e5[i].On == true)
				{
					if (e5[i].y > 0)
						e5[i].y -= 28;
					if (e5[i].y <= 0)
					{
						// e5[i].x=rand()%5500;
						e5[i].y = 730;
						e5[i].On = false;
					}
				}
			}
		}
		else if (Boss.boss_on == true)
		{
			Boss.boss_x = Boss.boss_x + dx;
			Boss.boss_y = Boss.boss_y + dy;
			if ((dx > 0 && Boss.boss_x > 200))
			{
				dx = dx * -1;
			}
			if (dy > 0 && Boss.boss_y > 150)
			{
				dy = -dy;
			}
			if (dx < 0 && Boss.boss_x < -150)
			{
				dx = dx * -1;
			}
			if (dy < 0 && Boss.boss_y < 100)
			{
				dy = -dy;
			}
		}
	}
}
void collitionCheck()
{
	if (mode == 1)
	{
		for (int i = 0; i <= MAX_NUMBER_OF_BULLETS; i++)
		{
			for (int j = 0; j <= TOTALENEMY; j++)
			{
				if (((bullets[i].x + 20 >= e1[j].x && bullets[i].x <= e1[j].x + 42) && (bullets[i].y + 42 >= e1[j].y && bullets[i].y <= e1[j].y + 44)))
				{
					if (e1[j].On == true && bullets[i].isalive == true)
					{
						e1[j].On = false;
						// colck = true;
						// printf("dead");

						score++;
						bullets[i].isalive = false;
						numberOfBullets--;
						sprintf(sscore, "Score : %d", score);
						/*strcpy(scoreArray, "SCORE:  ");
						sprintf(ch, "%d", (score));
						printf("%d", score);
						strcat(scoreArray, ch);*/
					}
				}
				if (((bullets[i].x + 20 >= e2[j].x && bullets[i].x <= e2[j].x + 34) && (bullets[i].y + 43 >= e2[j].y && bullets[i].y <= e2[j].y + 48)))
				{

					if (e2[j].On == true && bullets[i].isalive == true)
					{
						e2[j].On = false;
						// colck = true;
						// printf("dead");
						score++;
						sprintf(sscore, "Score : %d", score);
						bullets[i].isalive = false;
						numberOfBullets--;
					}
				}

				if ((bullets[i].x + 20 >= e3[j].x && bullets[i].x <= e3[j].x + 56) && (bullets[i].y + 43 >= e3[j].y && bullets[i].y <= e3[j].y + 60))
				{

					if (e3[j].On == true && bullets[i].isalive == true)
					{
						e3[j].On = false;
						// colck = true;
						// printf("dead");
						score++;
						sprintf(sscore, "Score : %d", score);
						bullets[i].isalive = false;
						numberOfBullets--;
						/*strcpy(scoreArray, "SCORE:  ");
						sprintf(ch, "%d", (score));
						printf("%d", score);

						strcat(scoreArray, ch);*/
					}
				}

				if ((bullets[i].x + 20 >= e4[j].x && bullets[i].x <= e4[j].x + 31) && (bullets[i].y + 43 >= e4[j].y && bullets[i].y <= e4[j].y + 56))
				{

					if (e4[j].On == true && bullets[i].isalive == true)
					{
						e4[j].On = false;
						// colck = true;
						// printf("dead");
						score++;
						sprintf(sscore, "Score : %d", score);
						bullets[i].isalive = false;
						numberOfBullets--;

						/*strcpy(scoreArray, "SCORE:  ");
						sprintf(ch, "%d", (score));
						printf("%d", score);

						strcat(scoreArray, ch);*/
					}
				}

				if ((bullets[i].x + 20 >= e5[j].x && bullets[i].x <= e5[j].x + 30) && (bullets[i].y + 43 >= e5[j].y && bullets[i].y <= e5[j].y + 56))
				{

					if (e5[j].On == true && bullets[i].isalive == true)
					{
						e5[j].On = false;
						// colck = true;
						// printf("dead");
						score++;
						sprintf(sscore, "Score : %d", score);
						bullets[i].isalive = false;
						numberOfBullets--;
						/*strcpy(scoreArray, "SCORE:  ");
						sprintf(ch, "%d", (score));
						printf("%d", score);*/
						//}

						// strcat(scoreArray, ch);
					}
				}
			}
			for (int j = 0; j <= TOTALENEMY; j++)
			{
				// if (s[j].y1 >= 1170)s[j].isalive = false;
				if ((bx + LENGHTH_OF_AIRCRAFT > e1[j].x && bx < e1[j].x + 42) && (by + HEIGTH_OF_AIRCRAFT > e1[j].y && by < e1[j].y + 44))
				{

					if (e1[j].On == true)
					{
						e1[j].On = false;
						//Boss.boss_on = true;
						if(life>=0)
						 life--;
					}
				}
				else if ((bx + LENGHTH_OF_AIRCRAFT > e2[j].x && bx < e2[j].x + 34) && (by + HEIGTH_OF_AIRCRAFT > e2[j].y && by < e2[j].y + 48))
				{

					if (e2[j].On == true)
					{
						e2[j].On = false;
						if(life>=0)
						life--;
					}
				}
				else if ((bx + LENGHTH_OF_AIRCRAFT > e3[j].x && bx < e3[j].x + 56) && (by + HEIGTH_OF_AIRCRAFT > e3[j].y && by < e3[j].y + 60))
				{
					if (e3[j].On == true)
					{
						e3[j].On = false;
						if(life>=0)
						life--;
					}
				}
				else if ((bx + LENGHTH_OF_AIRCRAFT > e4[j].x && bx < e4[j].x + 31) && (by + HEIGTH_OF_AIRCRAFT > e4[j].y && by < e4[j].y + 56))
				{

					if (e4[j].On == true)
					{
						e4[j].On = false;
						if(life>=0)
						life--;
					}
				}
				else if ((bx + LENGHTH_OF_AIRCRAFT > e5[j].x && bx < e5[j].x + 30) && (by + HEIGTH_OF_AIRCRAFT > e5[j].y && by < e5[j].y + 56))
				{

					if (e5[j].On == true)
					{
						e5[j].On = false;
						if(life>=0)
						life--;
					}
				}
				// strcat(lifeArray, ch);
			}
			for (int j = 0; j <= TOTALENEMY; j++)
			{
				if (((leaserX + 28 >= e1[j].x && leaserX <= e1[j].x + 42) && (leaserY + 580 >= e1[j].y && leaserY <= e1[j].y + 44)))
				{
					if (e1[j].On == true)
					{
						e1[j].On = false;
					}
				}
				if (((leaserX + 28 >= e2[j].x && leaserX <= e2[j].x + 34) && (leaserY + 580 >= e2[j].y && leaserY <= e2[j].y + 48)))
				{

					if (e2[j].On == true)
					{
						e2[j].On = false;
					}
				}
				if ((leaserX + 28 >= e3[j].x && leaserX <= e3[j].x + 56) && (leaserY + 580 >= e3[j].y && leaserY <= e3[j].y + 60))
				{

					if (e3[j].On == true)
					{
						e3[j].On = false;
					}
				}
				if ((leaserX + 28 >= e4[j].x && leaserX <= e4[j].x + 31) && (leaserY + 580 >= e4[j].y && leaserY <= e3[j].y + 56))
				{

					if (e4[j].On == true)
					{
						e4[j].On = false;
					}
				}
				if ((leaserX + 28 >= e5[j].x && leaserX <= e5[j].x + 30) && (leaserY + 580 >= e5[j].y && leaserY <= e5[j].y + 56))
				{

					if (e5[j].On == true)
					{
						e5[j].On = false;
					}
				}
			}
		}
		for (int i = 0; i <= MAX_NUMBER_OF_BULLETS; i++)
		{
			if (Boss.boss_on == 1)
			{   
				//sprintf(sscore, "Score : %d", score);
				sprintf(bossscore,"Boss Life :%d",bosslife);
						//sprintf(olife,"Life :%d",life);
				if (((bullets[i].x + 20 >= Boss.boss_x + 600 && bullets[i].x <= Boss.boss_x + 100 + 600) && (bullets[i].y + 43 >= Boss.boss_y + 350 && bullets[i].y <= Boss.boss_y + 90 + 350)))
				{
					if (bullets[i].isalive == true)
					{
						bullets[i].isalive = false;
						numberOfBullets--;
						score++;
						bosslife--;
						/*sprintf(sscore, "Score : %d", score);
						sprintf(bossscore,"Boss Life :%d",bosslife);
						sprintf(olife,"Life :%d",life);&*/
					}
					
					if (bosslife <= 0)
					{
						Boss.boss_on = false;
					}
				}
				// strcat(scoreArray, ch);
			} // strcat(bossLifeArray, ch);
		}

		for (int i = 0; i <= MAX_NUMBER_OF_BOSS_BULLETS; i++)
		{
			if (Boss.boss_on)
			{
				if ((bb[i].bossbulletX + 8 >= bx && bb[i].bossbulletX <= bx + LENGHTH_OF_AIRCRAFT) && (bb[i].bossbulletY + 12 >= by && bb[i].bossbulletY <= by + HEIGTH_OF_AIRCRAFT))
				{
					if (bb[i].show)
					{
						bb[i].show = false;
						if(life>=0)
						life--;
						numberofbossbullets--;
					}
				}
			}
		}
	}
}
	void iDraw()
	{
		// place your drawing codes here
		iClear();
		/*if(bosslife==0 && Boss.boss_on==false || life==0){
			iSetColor(0,0,0);
			iFilledRectangle(0,0,1280,720);
			iSetColor(255,0,255);
			iText(360,360,"Game Over",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(360,260,"Press g to continue",GLUT_BITMAP_TIMES_ROMAN_24);
		}*/
		// iShowBMP(20,0,hero);
		//  if(mode==0) iShowBMP(0,0,front);
		 if (mode == 1)
		{
			showGameInterface();
			sprintf(sscore, "Score : %d", score);
			sprintf(olife,"Life :%d",life);
			// Showleaser();
		}
		// iShowBMP(0,0,background);
		// iShowBMP(20,0,hero);
		// iLine(0,360,1200,360);
		else if (mode == 0)
		{   
			showMainMenu();
		}
		else if (mode == 2)
		{
			showinstruction();
		}
		else if (mode == 3)
		{
			highscore();
		}
		// iFilledRectangle(200,150,40,30);
		// iSetColor(123,266,345);
		if (laserflag == 1)
		{
			// Showlaser();
			leaserX = bx + LENGHTH_OF_AIRCRAFT / 2 - 15;
			leaserY = by + HEIGTH_OF_AIRCRAFT - 5;
			iShowBMP2(leaserX, leaserY, "bp\\laser3.bmp", 0);
		}
		if (Boss.boss_on == true)
		{
			//movebossBullet();
		}
		if((bosslife==0 && Boss.boss_on==false)  || life<=0){
			iSetColor(0,0,0);
			iFilledRectangle(0,0,1280,720);
			iSetColor(255,255,255);
			iText(360,360,"Game Over",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(360,260,"Press g to continue",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(360, 300, sscore, GLUT_BITMAP_TIMES_ROMAN_24);
            fprintf(f,"%s",sscore);
			fclose(f);
		}
	}
	    /*
		function iMouseMove() is called when the user presses and drags the mouse.
		(mx, my) is the position where the mouse pointer is.
		*/
	void iMouseMove(int mx, int my)
	{
		printf("x = %d, y= %d\n", mx, my);
		// place your codes here
	}
	    /*
		function iMouse() is called when the user presses/releases the mouse.
		(mx, my) is the position where the mouse pointer is.
		*/
	void iMouse(int button, int state, int mx, int my)
	{
		if (mode == 1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			// gmstate = 1;
			// lx=bx;
			// ly=by;
			// i=0;
		}
		if (mx >= 60 && mx <= 180 && my >= 300 && my <= 340 && mode == 0)
		{
			mode = 1;
		}
		if (mx >= 60 && mx <= 180 && my >= 250 && my <= 290 && mode == 0)
		{
			mode = 2;
		}
		if((mx>=60 && mx<=180 && my>=200 && my<=240) && mode==0)
		{
			
			mode=3;
		}
		if((mx>=0 && mx <=1200 && my>=0 && my<=720) && mode==3)
		{
			mode=3;
		}
	}

	/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
	void iKeyboard(unsigned char key)
	{
		if (key == 'q')
		{
			if (laserflag == 0)
			{
				laserflag = 1;
				
			}
			else
			{
				laserflag = 0;
			}
		}
		if (key ==' ' && mode == 1 && laserflag == 0)
		{
			laserflag = 0;
			Bulletshoot();
		}

		if (key == 'p' && Boss.boss_on == true)
		{
			// bossBulletshoot();
			// movebossBullet();
			// enemymovement();
		}
		
		if (key == 'g' && (life<=0||(bosslife<=0)))
		{
			enemyIndex1 = 0;
			enemyIndex2=0;
			enemyIndex3=0;
			enemyIndex4=0;
			enemyIndex5=0;
			mode = 0;
			leaserX, leaserY;
 			laser_show = 0;
 			laserflag = 0;
 			bx = 0, by = 0, dx = 10, dy = 5;
 			i, lx, ly, gmstate = 0;
            j = 1, k = 0;
            bulletMoveTimer, enemyMoveTimer, enemyinitializer;
            boss = 0;
			bss=1;
            score = 0;
			life=5;
            bosslife = 5;
            numberOfBullets = 0, numberofbossbullets = 0;
			gmover=0;
			Boss.boss_on=false;
		}
		// place your codes for other keys here
	}

	  /*
	   int *ptr=(int*)calloc(5,sizeof(int));
	    p=(int*)realloc(ptr,10*sizeof(int));

		function iSpecialKeyboard() is called whenver user hits special keys like-
		function keys, home, end, pg up, pg down, arraows etc. you have to use
		appropriate constants to detect them. A list is:
		GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
		GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
		GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
		GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
		*/
	void iSpecialKeyboard(unsigned char key)
	{

		if (key == GLUT_KEY_END)
		{
			exit(0);
		}
		if (key == GLUT_KEY_RIGHT)
		{
			if (bx >= 0 && bx < 1200 - LENGHTH_OF_AIRCRAFT)
				bx += 10;
		}
		if (key == GLUT_KEY_LEFT)
		{
			if (bx > 0 && bx <= 1200)
				bx -= 10;
		}
		if (key == GLUT_KEY_DOWN)
		{
			if (by > 0 && by <= 720)
				by -= 10;
		}
		if (key == GLUT_KEY_UP)
		{
			if (by >= 0 && by < 720 - HEIGTH_OF_AIRCRAFT)
				by += 10;
		}
		if (key == GLUT_KEY_INSERT )
		{
			mode=0;
		}
		/* code */

		// place your codes for other keys here
	}

	void moveBullet()
	{
		if (numberOfBullets > 0)
		{
			for (int i = 0; i < MAX_NUMBER_OF_BULLETS; i++)
			{
				if (bullets[i].isalive)
				{
					if (bullets[i].y > 700)
					{
						bullets[i].isalive = false;
						numberOfBullets--;
					}
					else
					{
						bullets[i].y += 10;
						// bulletX[i] +=10;
					}
				}
				//if(i=MAX_NUMBER_OF_BULLETS-1)  i=0;
			}
			printf("number of bullets: %d\n", numberOfBullets);
		}
	}

	int main()
	{
		// place your own initialization codes here.
		Boss.boss_on = false;
		for (int i = 0; i < MAX_NUMBER_OF_BULLETS; i++)
		{
			bullets[i].isalive = false;
		}
		for (int i = 0; i < MAX_NUMBER_OF_BOSS_BULLETS; i++)
		{
			bb[i].show = false;
		}
		iSetTimer(1, collitionCheck);
		iSetTimer(7520, callEnemy1);
		iSetTimer(5000, callEnemy2);
		iSetTimer(4500, callEnemy3);
		iSetTimer(6050, callEnemy4);
		iSetTimer(2500, callEnemy5);
		// if(Boss.boss_on){
		// iSetTimer(25,bossBulletshoot);

		iSetTimer(25, movebossBullet);
		// iSetTimer(1300,callEnemy6);
		iSetTimer(500, bossBulletshoot);
		iSetTimer(250, enemyMove);
		iSetTimer(25, moveBullet);

		// enemyMoveTimer =iSetTimer(25,enemymovement);
		iInitialize(1200, 720, "Space Shooter");

		return 0;
	}
