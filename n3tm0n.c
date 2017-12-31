#include <stdio.h> // standard out put commands
#include <string.h> // string commands
#include <sys/types.h> // system() function
#include <sys/wait.h> // system() function
#include <stdlib.h> // socket open checking commands
#include <unistd.h> // socket open checking commands
#include <sys/socket.h> // socket open checking commands
#include <netinet/in.h> // socket open checking commands
#include <arpa/inet.h> // socket open checkking commands
#include <errno.h> // strerror output
#include <curl/curl.h> // command-line tool for transferring data
#include "cmdRunner.h" // command Runner file
#include "notice.h" // displays status informaiton
#include "noticeRecovery.h" // displays number of times the applicaiton has attempted recovery
#include "socktest_1.h" // test a socket for connectivity
#include "socktest_2.h" // test a socket for connectivity
#include "cmd_maker.h" // returns the concatenation of two strings
#include "pidfind.h" // attempts to return an applicaitons pid based on the applications name
#include "takedown.h" // attempts to take down an interface
#include "bringup.h" // attempts to bring up an interface


#define KNRM  "\x1B[0m" // text color normal
#define KRED  "\x1B[31m" // text color red
#define KGRN  "\x1B[32m" // text color green
#define KYEL  "\x1B[33m" // text color yellow
#define KBLU  "\x1B[34m" // text color blue
#define KMAG  "\x1B[35m" // text color magenta
#define KCYN  "\x1B[36m" // text color cyan
#define KWHT  "\x1B[37m" // text color white



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
static char wpa_cmd_1[92] = "wpa_supplicant -iwlan0 -c/etc/wpa_supplicant.conf -dd > ./logs/stdOut 2>./logs/stdError &";
static char wpa_cmd_2[15] = "wpa_supplicant";
static char ip_cmd_1[31] = "ip addr add 10.10.10.1/30 dev ";
static char ip_cmd_2[31] = "ip addr del 10.10.10.1/30 dev ";
static char ip_cmd_3[34] = "ip link set eth0 up ";
static char rf_cmd_1[19] = "rfkill unblock wifi";
static char rf_cmd_2[18] = "rfkill block wifi";
static char kill_cmd_1[24] = "killall --ignore-case ";
static char kill_cmd_2[11] = "kill -9 ";
static char kill_cmd_3[14] = "pkill -9 ";
static char ps_cmd_1[23] = "ps aux | grep --color ";
static char ps_cmd_2[36] = " | grep -v grep | awk '{print $2}'";
static char ps_cmd_3[55] = "ip a | grep wlan0 | cut -d: -f2 | awk '{print $2}'";
static char ps_cmd_4[55] = "ip a | grep eth0 | cut -d: -f2 | awk '{print $2}'";
static char ps_cmd_5[64] = "ip a | grep wpa_supplicant | cut -d: -f2 | awk '{print $2}'";
static int recoveryCounter = -1;

class restApi
{
    // Access specifier
    public:
    // Data Members
    string dataUrl;
    string dataBlob;
    // Member Functions()
    void printUrl()
    {
       cout << "dataUrl is: " << dataUrl;
    }
    void dataBlob()
    {
       cout << "dataBlob is: " << dataBlob;
    }
    void postRequest()
    {
       cout << "dataBlob is: " << dataBlob;
       CURL *curl;
       CURLcode res;
       char url[]= dataUrl;
       char postData[] = dataBlob;
       curl = curl_easy_init();
       if(curl) {
         curl_easy_setopt(curl, CURLOPT_URL, url);
         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);
         res = curl_easy_perform(curl);
         curl_easy_cleanup(curl);
       }
       return 0;
     }
};


// starts functions and outputs for debugs
int main (void) {
	int fail_status_1 = 0;
	int fail_count_1 = 0;
	int updown_1 = 1;
	int mustbeup = 0;
	int netcheck_1;
	char *ipAddressWLAN0 = cmdRunner(ps_cmd_4);
	char *ipAddressETH0 = cmdRunner(ps_cmd_3);
	// debugs
	//printf ("UpDown Status : %d\n", updown_1);
	//printf ("ipAddressWLAN0 : %s\n", ipAddressWLAN0);
	//printf ("ipAddressETH0 : %s\n", ipAddressETH0);
	// Declare an object of class geeks
	 restApi obj1;
	 // accessing data member
	 obj1.dataUrl = "wwww.google.com.com.com.com";
	 obj1.dataBlob = "blob0:blob,blob1:{blob:deepBlob}";
	 // accessing member function
	 obj1.printUrl();
	 obj1.dataBlob();
	if (updown_1 !=0) {
		// text color green
		printf ("%s.\n", KGRN);
		notice(netcheck_1);
		// text color normal
		printf ("%s.\n", KNRM);
		netcheck_1 = socktest_1(noticeRecovery, port_1, add_1, recoveryCounter, ipAddressWLAN0, ipAddressETH0) + socktest_2(noticeRecovery, port_1, add_2, recoveryCounter, ipAddressWLAN0, ipAddressETH0);
		//printf ("%i\n dogsgs\n", netcheck_1);//debug
		//sleep(10);
		if (netcheck_1 >=1) {
			fail_count_1 = 0;
			fail_status_1 = 0;
			//printf ("netcheck %i\n updown %i\n", netcheck_1, updown_1);//debug
			// text color green
			printf ("%s.\n", KGRN);
			notice(netcheck_1);
			// text color normal
			printf ("%s.\n", KNRM);
			sleep(600);
			system("clear");
			main();

		} else {
			KBLU; // text color blue
			notice(netcheck_1);
			//printf ("netcheck %i\n updown %i\n", netcheck_1, updown_1);//debug
			char *dhcp_wlan = cmd_maker(dhcp_cmd_2, wlan_int_1);
			char *ps_wlan = cmd_maker(ps_cmd_1, wlan_int_1); ps_wlan = cmd_maker(ps_wlan, ps_cmd_2);
			char *wlan_dhcp_pid = pidfind(ps_wlan);
			char *dhcp_kill = cmd_maker(kill_cmd_2, wlan_dhcp_pid);
			// clean up free memory from wlan_dhcp_pid
			free(wlan_dhcp_pid);
			char *sub_pid = cmdRunner(ps_cmd_5);
			char *sup_kill = cmd_maker(kill_cmd_3, wpa_cmd_2);
			char *eth_kill = cmd_maker(ip_cmd_2, eth_int_1);
			//char *doctor_1 = takedown (dhcp_wlan, dhcp_kill, sup_kill, rf_cmd_2, eth_kill);
			char *doctor_1 = takedown (sup_kill,dhcp_wlan,dhcp_kill,rf_cmd_2,eth_kill);
			//printf("%s\n %s\n",sup_kill, wlan_dhcp_pid);//debug
			char *eth_up = cmd_maker(ip_cmd_1, eth_int_1);
			char *dhcp_wlan_up = cmd_maker(dhcp_cmd_1, wlan_int_1);
			char *doctor_3 = bringup(rf_cmd_1, wpa_cmd_1, eth_up, dhcp_wlan_up, ip_cmd_3);
			// text color normal
			printf ("%s.\n", KNRM);
			fail_count_1++;
			fail_status_1 = 1;
			recoveryCounter++;
		}
	}
	sleep(60);
	main();
}
