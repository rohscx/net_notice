char* cmdRunner (char *a) {
	FILE *fp;
	int status;
	char path[255];
	char *str_to_ret = malloc (sizeof (char) * required_size);

	fp = popen(a, "r");
	if (fp == NULL)
	    /* Handle error */;
			printf("error FP Null!");

	while (fgets(path, 255, fp) != NULL)
	    printf("%s", path);
			strcpy(str_to_ret,path);
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
