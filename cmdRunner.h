char* cmdRunner (char *a) {
	FILE *fp;
	int status;
	char path[255];

	fp = popen(a, "r");
	if (fp == NULL)
	    /* Handle error */;
			printf("error FP Null!");

	while (fgets(path, 255, fp) != NULL)
	    printf("%s", path);
	status = pclose(fp);
	if (status == -1) {
	    /* Error reported by pclose() */
	    printf("error reported in pclose");
	} else {
	    /* Use macros described under wait() to inspect `status' in order
	       to determine success/failure of command executed by popen() */
	    strcpy(buffer_out,path);
		  printf("buffer_out  %s", buffer_out);
			return buffer_out;
	}
}
