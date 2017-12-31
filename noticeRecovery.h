// networkRecovery status notification
void noticeRecovery (int a, char *b, char *c) {
	if (a == -1){
		// do nothing
	} else if (a == 0) {
		printf ("Network Doctor: NO actions needed\n");
		printf ("External IP Address: %s\n", b);
		printf ("Internal IP Address: %s\n", c);
	} else {
		printf ("Network Doctor: Corrective action teken: %i\n", a);
		printf ("External IP Address: %s\n", b);
		printf ("Internal IP Address: %s\n", c);
	}
}
