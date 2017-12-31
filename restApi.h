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
