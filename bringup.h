#define KNRM  "\x1B[0m" // text color normal
#define KRED  "\x1B[31m" // text color red
#define KGRN  "\x1B[32m" // text color green
#define KYEL  "\x1B[33m" // text color yellow
#define KBLU  "\x1B[34m" // text color blue
#define KMAG  "\x1B[35m" // text color magenta
#define KCYN  "\x1B[36m" // text color cyan
#define KWHT  "\x1B[37m" // text color white
// re-initializes network componets
char* bringup (char *a, char *b, char *c, char *d, char *e) {
	//printf("this is B: %s\n this is A: %s\n this is C: %s\n", b, a, c ); //debug
	int y1;
	char* v1[] = {a,b,c,d,e};
	for (y1 = 0; y1 < 5; y1++) {
		system(v1[y1]);
		// text color yellow
		printf ("%s.\n", KYEL);
		printf("BRINGING UP ____|:|<*-*> (%s)\n", v1[y1]);
		// text color normal
		printf ("%s.\n", KNRM);
		sleep(1);

	}


	return 0;
}
