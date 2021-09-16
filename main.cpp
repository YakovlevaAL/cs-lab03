#include <iostream>
#include <vector>
#include <ctime>
#include "histogram.h"
#include "svg.h"
#include"InfoText.h"
//#include <wx/gauge.h>

#include <time.h>
#include <curl/curl.h>

#include <sstream>
#include <string>

#include <stdio.h>
#include <ctime>
using namespace std;

vector<double>
input_numbers(istream& in,size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}
void call_back(){
   int i=0;
    srand( time( 0 ) );
    while(i<10)
    {
            i++;
            cerr<<"Progress: "<< i*10 -(rand()%9+1) <<"%\n";
            //cout<<"Progress: "<< progress <<"%\n";
        Sleep(100/i);
    }
 cerr<<"Progress: "<<10*i<<"%\n";
    Sleep(120/i);
return;
    }
Input
read_input(istream& in,bool prompt){
Input data;
if(prompt)
cerr<<"Enter number count: ";
size_t number_count;
in >> number_count;
if(prompt)
cerr<<" Enter numbers: ";
data.numbers =input_numbers(in,number_count);
if(prompt)
cerr <<"Enter bin count: ";
size_t bin_count;
in >> data.bin_count;

return data;
}

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
  auto data_size = item_size * item_count;
 stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
 buffer->write(reinterpret_cast<char*>(items), data_size);
    return data_size;
}

size_t progress_callback(
  void* clientp,  // this is an unchanged pointer as set with CURLOPT_PROGRESSDATA
  double dltotal, // the total bytes to be downloaded (or 0 if not downloading)
  double dlnow,   // the current download bytecount (or 0 if not downloading)
  double ultotal, // the total bytes to be uploaded (or 0 if not uploading)
  double ulnow)  // the current upload bytecount (or 0 if not uploading){
  {
    stringstream* ptr= reinterpret_cast<stringstream*>(clientp);
    auto D=dlnow * 100.0f / dlnow ;
    return D;
  }


 Input
download(const string& address) {
    curl_global_init(CURL_GLOBAL_ALL);
    stringstream buffer;
    stringstream* ptr;
    CURL* curl=curl_easy_init();
    CURLcode res = CURLE_OK;
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION,progress_callback);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
        cout << address<<endl;
        cout << curl_easy_strerror(res);
            exit(1);
            }
        curl_easy_cleanup(curl);
        call_back();
        }
return read_input(buffer, false);
}

int main(int argc, char* argv[]) {
    Input input;
    if (argc > 1) {
        input = download(argv[1]);
    } else {
        input = read_input(cin, true);// Ввод данных
    }
    //Обработка данных
    const auto bins = make_histogram(input);
    // Вывод данных
    show_histogram_svg(bins);

    return 0;
}
