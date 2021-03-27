#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<process.h>
float avg;
long gross=0, p;
int rnd=0, j=0, q=1;
struct total
   {
      int turn;
      long pts;
      long hs;
   }total_scr[1000];
void final(int p)
{
   system("cls");
   cout<<"FINAL STATISTICS: \n";
   cout<<"Turn No.\t\tScore\n";
   for(int i=0; i<p; i++)
      {
	 cout<<total_scr[i].turn<<"\t\t\t"<<total_scr[i].pts<<"\n";
	 gross=gross+total_scr[i].pts;
      }
   cout<<"Highest Score:  "<<total_scr[0].hs<<"\n";
   avg=gross/p;
   cout<<"Average Score:  "<<avg;
   if(avg<100)
      cout<<"\nHope You Learn From Your ACCIDENTS....";
   else if(100<=avg && avg<500)
      cout<<"\nWhy Don't You Enter Driving Classes....AS A STUDENT!!";
   else if(500<=avg && avg<1000)
      cout<<"\nNext Time, You Might Just Be Able To HANDLE THE GEARS PROPERLY.... ";
   else if(1000<=avg && avg<2500)
      cout<<"\nYou Are Really PUNCHING ABOVE YOUR OWN WEIGHT....";
   else if(2500<=avg && avg<5000)
      cout<<"\nWOAH!! A Few More Metres And Even The Opposing Cars Will Think Twice Before CROSSING YOUR PATH!!";
   else if(5000<=avg && avg<10000)
      cout<<"\nWhy Don't You Enter Driving Classes....AS A PROFESSIONAL TEACHER!!";
   else
      cout<<"\nA NEW LEGEND IS BORN...";
}
void lines()
{
   textbackground(1);
   clrscr();
   textcolor(15);
   window(19,1,51,25);
   for (int x=1; x<25; x++)
   cprintf("≥                               ≥");
   textcolor(10);
   window(55,6,77,21);
   cprintf("      INSTRUCTIONS    \n");
   cprintf("  Press Left and Right\n");
   cprintf("  arrow keys to navigate \n");
   cprintf("    Press P to Pause\n");
   cprintf("       Press X to Exit \n");
   textcolor(9);
   window(55,18,79,20);
   cprintf("SCORE" );
}
int strt[3], dwn[3], end[3];
int cars[3], go=0, speed;
void score (int p, int s=1)
{
   static unsigned long scr=0, sc=0;
   textcolor(5);
   window(61,18,70,23);
   cprintf("        ");
   window(61,18,70,23);
   cprintf("%d", ++scr);
   textcolor(11);
   for (int x=1; x<=10; x++)
   if (scr>=x*100 && speed>20)
      speed--;
   if (s==0)
   {
      for(int i=0; i<p; i++)
	 {
	    total_scr[i].turn=i+1;
	 }
      total_scr[j].pts=scr;
      j++;
      if(scr>sc)
	 sc=scr;
      window(55,24,75,24);
      cprintf("Best Score: ");
      cout<<sc;
      scr=0;
      return;
   }
   total_scr[0].hs=sc;
}
void status(int s)
{
   textcolor(0);
   window(55,20,75,23);
   switch(s)
   {
      case 1: cprintf("Playing...");
	      cprintf("                        ");
	      cprintf("                        ");
	      break;
      case 2: cprintf("Paused   ");
	      cprintf("                        ");
	      cprintf("                        ");
	      break;
      case 3: cprintf("Game Over");
	      cprintf("            Press Arrow");
	      cprintf("          To Continue");

   }
   textcolor(11);
}
void myc(int x)
{
   int i;
   textcolor(7);
   window(20+(x*10),21,29+(x*10),25);
   cprintf("   ﬂﬂ€ﬂﬂ  ");
   cprintf("  €€€€€€€ ");
   cprintf("   €€ €€  ");
   textcolor(10);
   cprintf(" ﬂﬂﬂﬂﬂﬂﬂﬂﬂ");
   textcolor(WHITE);
   delay(10);
   if (x==0 || x==2)
   {
      x=1;
      window(20+(x*10),21,29+(x*10),25);
      for(i=0; i<4; i++)
      cprintf("          ");
   }
   else
   {
      x=0;
      window(20+(x*10),21,29+(x*10),25);
      for(i=0; i<4; i++)
      cprintf("          ");
      x=2;
      window(20+(x*10),21,29+(x*10),25);
      for(i=0; i<4; i++)
      cprintf("          ");
   }

}
void dc(int x, int car)
{
   if(strt[x]==25)
   {
      strt[x]=1;
      dwn[x]=1;
      end[x]=1;
   }
   if(strt[x]<10)
   window(20+(x*10),1,29+(x*10),5);
   textcolor(4);
   if(end[x]>0)
   {
      window(20+(x*10),end[x]+20,29+(x*10),25);
      if(end[x]==1)
      {
	 cprintf("          ");
	 textcolor(0);
	 cprintf(" ‹‹‹‹‹‹‹‹‹");
	 textcolor(4);
	 cprintf("   €€ €€  ");
	 cprintf("  €€€€€€€ ");
      }
      else if(end[x]==2)
      {
	 cprintf("          ");
	 textcolor(0);
	 cprintf(" ‹‹‹‹‹‹‹‹‹");
	 textcolor(4);
	 cprintf("   €€ €€  ");
      }
      else if(end[x]==3)
      {
	 cprintf("          ");
	 textcolor(0);
	 cprintf(" ‹‹‹‹‹‹‹‹‹");
      }
      else
      {
	 cprintf("          ");
	 end[x]=-1;
	 strt[x]=0;
	 cars[x]=0;
      }
      end[x]++;
   }
   else if (strt[x]>=5)
   {
      window(20+(x*10),dwn[x],29+(x*10),dwn[x]+5);
      cprintf("          ");
      textcolor(0);
      cprintf(" ‹‹‹‹‹‹‹‹‹");
      textcolor(4);
      cprintf("   €€ €€  ");
      cprintf("  €€€€€€€ ");
      cprintf("   ‹‹€‹‹  ");
      dwn[x]++;
   }
   else if(strt[x]==1)
      {
	 cprintf("   ‹‹€‹‹  ");
      }
   else if(strt[x]==2)
      {
	 cprintf("  €€€€€€€ ");
	 cprintf("   ‹‹€‹‹  ");
      }
   else if(strt[x]==3)
      {
	 cprintf("   €€ €€  ");
	 cprintf("  €€€€€€€ ");
	 cprintf("   ‹‹€‹‹  ");
      }
   else if(strt[x]==4)
      {
	 textcolor(0);
	 cprintf(" ‹‹‹‹‹‹‹‹‹");
	 textcolor(4);
	 cprintf("   €€ €€  ");
	 cprintf("  €€€€€€€ ");
	 cprintf("   ‹‹€‹‹  ");
      }
   strt[x]++;
   if(strt[x]==21 && x==car)
      {
	 status(3);
	 rnd=rnd+1;
	 speed=30;
	 score(p,0);
	 sound(60);
	 delay(110);
	 nosound();
	 sound(80);
	 delay(150);
	 nosound();
	 sound(120);
	 delay(210);
	 nosound();
	 go=1;
	 getch();
      }
   textcolor(YELLOW);
}
void main()
{
   clrscr();
   textbackground(1);
   randomize();
   textcolor(0);
   cout<<"\n How many turns?   ";
   cin>>p;
   _setcursortype(_NOCURSOR);
   char c, ch;
   int i, x;
   while(1)
      {
	 for(x=0;x<3;x++)
	    {
	       strt[x]=1;
	       dwn[x]=1;
	       end[x]=0;
	       cars[x]=0;
	    }
	 lines();
	 status(1);
	 speed=30;
	 x=1;
	 myc(x);
	 if(rnd!=p)
	 go=0;
	 else
	    {
	       goto last;
	    }
	 while(!go)
	    {
	       while(!kbhit())
		  {
		     if(random(speed)==5 && cars[0]==0 && (cars[1]==0 || cars[2]==0))
			cars[0]=1;
		     else if(random(speed)==5 && cars[1]==0 && (cars[0]==0 || cars[2]==0))
			cars[1]=1;
		     else if(random(speed)==5 && cars[2]==0 && (cars[1]==0 || cars[0]==0))
			cars[2]=1;
		     for(i=0;i<3;i++)
			if(cars[i]!=0)
			   dc(i,x);
		     sound(100);
		     delay(speed*2);
		     nosound();
		     score(p,1);
		  }
	       c=getch();
	       switch(tolower(c))
		  {
		     case 'p': status(2);
			       sound(1500);
			       delay(210);
			       nosound();
			       sound(350);
			       delay(150);
			       nosound();
			       sound(1000);
			       delay(300);
			       nosound();
			       getch();
			       status(1);
			       break;
		     case 0:   ch=getch();
			       if(ch==75 && x>0)
				  {
				     x--;
				     myc(x);
				     sound(1200);
				     delay(20);
				  }
			       else if(ch==77 && x<2)
				  {
				     x++;
				     myc(x);
				     sound(1200);
				     delay(20);
				  }
			       break;
		     case 'x': return;
		  }
	    }
      }
   last:
   final(p);
   getch();
}



