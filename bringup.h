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
