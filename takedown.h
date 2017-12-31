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
