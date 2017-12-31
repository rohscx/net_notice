// pings and collects response. Special not about struct: int (a) and (c) are passed for IP and Port number
int socktest_1(void (*f)(int,char *,char *), int a, char *b, int c, char *d, char *e) {
	int z;

		int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		struct sockaddr_in addr = {AF_INET, htons(a), inet_addr(b)};
		struct timeval timeout;
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;
		setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
		setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
		if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) != 0) {

			z = 0;
			printf("Test **__FAILED__**: port: %i address: %s\n", a, b);
			// calls noticeRecovery function
			// extrainious on screen text commenting out. Only one needed
			//(*f)(c);
			return (z);
		}


		else {

			printf("Test Success: port: %i address: %s\n", a, b);
			// calls noticeRecovery function
			// extrainious on screen text commenting out. Only one needed
			//(*f)(c);
			z = 1;
		}
		close(sockfd);
		return z;
}
