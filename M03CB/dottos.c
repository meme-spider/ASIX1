#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void stdinFlush(){ // prevents spammage of 'invalid input' messages
	char ch=0x20;
	while(ch!=0x0A){
		scanf("%c",&ch);
	}
}

int main()
{
	Display* dpy = XOpenDisplay(NULL);
	char keys_return[32];
	FILE *fp;
	fp=fopen("henlowaarudo.txt","w+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);
	
	while (true){
		system("clear");
		XQueryKeymap( dpy, keys_return );
		KeyCode ka = XKeysymToKeycode( dpy, XK_A );
		KeyCode kd = XKeysymToKeycode( dpy, XK_D );
		KeyCode kq = XKeysymToKeycode( dpy, XK_Q );
		bool aIsPressed = !!( keys_return[ ka>>3 ] & ( 1<<(ka&7) ) );
		bool dIsPressed = !!( keys_return[ kd>>3 ] & ( 1<<(kd&7) ) );
		bool qIsPressed = !!( keys_return[ kq>>3 ] & ( 1<<(kq&7) ) );
		printf("\n");
		if(qIsPressed) break;
		else if(aIsPressed||dIsPressed){
			for (int i=1;i<=256;i++){
				printf("%s",aIsPressed&&dIsPressed? " #": " ·");
				if(!(i%32)) printf("\n");
			}
		}
		printf("Press Q to quit");
		usleep(1000000/30);
	}
	printf("Press Enter to exit");
	stdinFlush();
    XCloseDisplay(dpy);

	return 0;
}
