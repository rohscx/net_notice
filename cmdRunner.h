char* cmdRunner (char *a) {
	FILE *fp;
	int status;
	char buffer[255];
	char *str_to_ret = malloc (sizeof (char) * 50);

	fp = popen(a, "r");
	if (fp == NULL)
	    /* Handle error */;
			printf("error FP Null!");

	while (fgets(buffer, 255, fp) != NULL)
			buffer[strlen(buffer)-1] = '\0';
			str_to_ret[strlen(buffer)-1] = '\0';
	    printf("%s", buffer);
			strcpy(str_to_ret,buffer);
			printf("buffer_out  %s", str_to_ret);
	status = pclose(fp);
	if (status == -1) {
	    /* Error reported by pclose() */
	    printf("error reported in pclose");
	} else {
	    /* Use macros described under wait() to inspect `status' in order
	       to determine success/failure of command executed by popen() */
			return str_to_ret;
	}
}
