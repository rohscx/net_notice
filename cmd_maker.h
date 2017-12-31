#define KNRM  "\x1B[0m" // text color normal
#define KRED  "\x1B[31m" // text color red
#define KGRN  "\x1B[32m" // text color green
#define KYEL  "\x1B[33m" // text color yellow
#define KBLU  "\x1B[34m" // text color blue
#define KMAG  "\x1B[35m" // text color magenta
#define KCYN  "\x1B[36m" // text color cyan
#define KWHT  "\x1B[37m" // text color white
// contatinates to create usable commands
char* cmd_maker(const char *s1, const char *s2) {
	const size_t len1 = strlen(s1);
	const size_t len2 = strlen(s2);
	char *result = malloc(len1+len2+1);//+1 for the zero-terminator
	//in real code you would check for errors in malloc here
	memcpy(result, s1, len1);
	memcpy(result+len1, s2, len2+1);//+1 to copy the null-terminator
	// text color yellow
	printf ("%s.\n", KYEL);
	printf ("RDY TO APPLY ____|:|<*-*> (%s)\n", result);//debug
	// text color normal
	printf ("%s.\n", KNRM);
	//sleep(5);//debug
	return result;
}
