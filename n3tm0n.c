#include <stdio.h> // standard out put commands
#include <string.h> // string commands
#include <sys/types.h> // system() function
#include <sys/wait.h> // system() function
#include <stdlib.h> // socket open checking commands
#include <unistd.h> // socket open checking commands
#include <sys/socket.h> // socket open checking commands
#include <netinet/in.h> // socket open checking commands
#include <arpa/inet.h> // socket open checkking commands

// variables for application
char status_1[8];
static char add_1[11] = "8.8.4.4";
static char add_2[11] = "8.8.8.8";
static int port_1 = 53;
static char eth_int_1[5] = "eth0";
static char wlan_int_1[6] = "wlan0";
static char wpa_sup_1 [20] = "PLACE HOLDER"; //PlACE HOLDER REPLACE WITH COMMAND
static char dhcp_cmd_1[10] = "dhclient ";
static char dhcp_cmd_2[13] = "dhclient -r ";
static char wpa_cmd_1[56] = "wpa_supplicant -iwlan0 -c/etc/wpa_supplicant.conf -dd &";
static char wpa_cmd_2[15] = "wpa_supplicant";
static char ip_cmd_1[31] = "ip addr add 10.10.10.1/30 dev ";
static char ip_cmd_2[31] = "ip addr del 10.10.10.1/30 dev ";
static char ip_cmd_3[31] = "link set eth0 up ";
static char rf_cmd_1[19] = "rfkill unblock wifi";
static char rf_cmd_2[18] = "rfkill block wifi";
static char kill_cmd_1[9] = "killall --ignore-case ";
static char kill_cmd_2[9] = "kill -9 ";
static char ps_cmd_1[23] = "ps aux | grep --color ";
static char ps_cmd_2[36] = " | grep -v grep | awk '{print $1}'";
static char app1 [] = {"ps -A | grep -q wpa_supplicant"};
static char app2 [] = {"ps -A | grep -q dhclient"};
static char app3 [] = {"ps -A | grep -q rfkill"};
char buffer_out [150];


// functions
// network status notification
int notice (int a) {
	//printf("int a = %i\n", a); //debug
	if (a <= 0){
		char status_1[] = {"(ノ ˘_˘)ノ　ζ|||ζ　ζ|||ζ　ζ|||ζ"};
		printf ("NETWORK STATUS : %s\n" , status_1);
		return 10;
	}else {
		char status_1[] = {"⊃｡•́‿•̀｡)⊃━✿✿✿✿✿✿✿✿✿✿✿✿✿✿✿✿✿✿"};
		printf ("NETWORK STATUS : %s\n" , status_1);
		return 10;
	}

}
// pings and collects response. Special not about struct: int (a) and (c) are passed for IP and Port number
int socktest_1(int a, char *b) {
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
			return (z);
		}


		else {

			printf("Test Success: port: %i address: %s\n", a, b);
			z = 1;
		}
		close(sockfd);
		return z;
}


int socktest_2(int a, char *b) {
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
			return (z);
		}


		else {

			printf("Test Success: port: %i address: %s\n", a, b);
			z = 1;
		}
		close(sockfd);
		return z;
}

// contatinates to create usable commands
char* cmd_maker(const char *s1, const char *s2) {
	const size_t len1 = strlen(s1);
	const size_t len2 = strlen(s2);
	char *result = malloc(len1+len2+1);//+1 for the zero-terminator
	//in real code you would check for errors in malloc here
	memcpy(result, s1, len1);
	memcpy(result+len1, s2, len2+1);//+1 to copy the null-terminator
	printf ("RDY TO APPLY ____|:|<*-*> (%s)\n", result);//debug
	sleep(5);//debug
	return result;
}

char* pidfind (char *a) {
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
	return buffer_out;

/*	int z;
	z = system(a);

	printf("getpid var %s\n pid got %i\n", a);


	return buffer;
*/
}

char* takedown (char *a, char *b, char *c, char *d, char *e) {
	//kind of complicated and I have forgotton how it works...
	int z1,y1,w1;
	char* x1[] = {app1};
	char* v1[] = {a,b,c,d,e};
	for (y1 = 0; y1 < 5; y1++) {
		w1 = system(x1[y1]);
		wait;
		//printf("w1=%i system(%s) x1[%i]\n",w1,x1[y1],y1);
	       if (w1 = 0) {
		       system(v1[y1]);
		       printf("Killing %s\n",v1[y1]);
		       sleep(2);
	       }
		if (y1 = 1) {
			for (y1 = 1; y1 < 4; y1++) {
				system(v1[y1]);
				printf("BRINGING DOWN ____|:|<*-*> (%s)\n",v1[y1]);
				sleep(2);
			}
			y1 = 5;
		}

	}
	sleep(15);
}

// re-initializes network componets
// re-initializes network componets
char* bringup (char *a, char *b, char *c, char *d, char *e) {
	//printf("this is B: %s\n this is A: %s\n this is C: %s\n", b, a, c ); //debug
	int z1,y1,w1;

	char* v1[] = {a,b,c,d,e};
	for (y1 = 0; y1 < 5; y1++) {
		system(v1[y1]);
		printf("BRINGING UP ____|:|<*-*> (%s)\n", v1[y1]);
		sleep(8);

	}


	return 0;
}
// starts functions and outputs for debugs
int main (void) {
	int fail_status_1 = 0;
	int fail_count_1 = 0;
	int updown_1 = 1;
	int mustbeup = 0;
	int netcheck_1;


	//printf ("UpDown Status : %d\n", updown_1);
	if (updown_1 !=0) {
		notice(netcheck_1);
		netcheck_1 = socktest_1(port_1, add_1) + socktest_2(port_1, add_2);
		//printf ("%i\n dogsgs\n", netcheck_1);//debug
		//sleep(10);
		if (netcheck_1 >=1) {
			fail_count_1 = 0;
			fail_status_1 = 0;
			//printf ("netcheck %i\n updown %i\n", netcheck_1, updown_1);//debug
			notice(netcheck_1);
			sleep(600);
			system("clear");
			main();

		} else {
			notice(netcheck_1);
			//printf ("netcheck %i\n updown %i\n", netcheck_1, updown_1);//debug
			char *dhcp_wlan = cmd_maker(dhcp_cmd_2, wlan_int_1);
			char *ps_wlan = cmd_maker(ps_cmd_1, wlan_int_1); ps_wlan = cmd_maker(ps_wlan, ps_cmd_2);
			char *wlan_dhcp_pid = pidfind(ps_wlan);
			char *dhcp_kill = cmd_maker(kill_cmd_2, wlan_dhcp_pid);
			char *sup_kill = cmd_maker(kill_cmd_1, wpa_cmd_2);
			char *eth_kill = cmd_maker(ip_cmd_2, eth_int_1);
			//char *doctor_1 = takedown (dhcp_wlan, dhcp_kill, sup_kill, rf_cmd_2, eth_kill);
			char *doctor_1 = takedown (sup_kill,dhcp_wlan,dhcp_kill,rf_cmd_2,eth_kill);
			//printf("%s\n %s\n",sup_kill, wlan_dhcp_pid);//debug
			char *eth_up = cmd_maker(ip_cmd_1, eth_int_1);
			char *dhcp_wlan_up = cmd_maker(dhcp_cmd_1, wlan_int_1);
			char *doctor_3 = bringup(rf_cmd_1, wpa_cmd_1, eth_up, dhcp_wlan_up, ip_cmd_3);
			fail_count_1++;
			fail_status_1 = 1;

		}
	}
	sleep(60);
	main();
}
