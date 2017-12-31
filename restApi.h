// locates the applications pid based on the name
char* restApi (char *url[], char *postData[]) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
  printf ("url : %s\n" , a);
  printf ("blob : %s\n" , b);
  return 0;
}
