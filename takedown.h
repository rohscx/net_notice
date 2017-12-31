#define KNRM  "\x1B[0m" // text color normal
#define KRED  "\x1B[31m" // text color red
#define KGRN  "\x1B[32m" // text color green
#define KYEL  "\x1B[33m" // text color yellow
#define KBLU  "\x1B[34m" // text color blue
#define KMAG  "\x1B[35m" // text color magenta
#define KCYN  "\x1B[36m" // text color cyan
#define KWHT  "\x1B[37m" // text color white
// attempts to stop a running application
char* takedown (char *a, char *b, char *c, char *d, char *e) {
	//removed a bunch of stuff and now it's simpler
	int y1;
	char* v1[] = {a,b,c,d,e};
	for (y1 = 0; y1 < 5; y1++) {
		system(v1[y1]);
		printf ("%s.\n", KRED);
		printf("BRINGING DOWN ____|:|<*-*> (%s)\n",v1[y1]);
		printf ("%s.\n", KNRM);
		sleep(1);
	}
	sleep(15);
}
