char* pidfind (char *a) {
	char buffer_out [150];
	FILE* pipe = popen(a, "r");
	if (pipe) {

		char buffer[128];
		while(!feof(pipe)) {

			if(fgets(buffer, 128, pipe) != NULL) {}
		}

		pclose(pipe);
		buffer[strlen(buffer)-1] = '\0';
		buffer_out[strlen(buffer)-1] = '\0';
		strcpy(buffer_out,buffer);
	}
	char *pidfindOutput = malloc(buffer_out);  // allocate memory from the heap
	return pidfindOutput;

/*	int z;
	z = system(a);

	printf("getpid var %s\n pid got %i\n", a);


	return buffer;
*/
}
