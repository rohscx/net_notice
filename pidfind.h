// locates the applications pid based on the name
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
		int sz;
		sz=strlen(buffer_out);
		char *pidfindOutput = malloc(sz);  // allocate memory from the heap
		strcpy(pidfindOutput,buffer);
		return pidfindOutput;
	}
}
