#include <iostream>
#include <fstream>
#include <sstream>
#include <pigpio.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

#define BUTTON_PIN 6
#define IR_LED_PIN 26
#define IR_SENS_PIN 13

using namespace std;
struct IrCodeC{
    vector<int> body;
};
vector<int> getIR(){
    int cnt=0,old=0;
    vector<int> data;
    while(gpioRead(IR_SENS_PIN)==1);
    while(data.size()==0 || cnt<data[0]*2){
        int now=gpioRead(IR_SENS_PIN);
        if(now!=old){
            data.push_back(cnt);
            old=now;
            cnt=0;
        }
        cnt++;
    }
    return data;
}
bool convertIR(vector<int> &data,IrCodeC &rep){
    double t=-1;
    {
        vector<int> tmp=data;
        int sum=0;
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();i++){
            if(tmp[0]*1.6<tmp[i]){
                t=(double)sum/i;
                break;
            }
            sum+=tmp[i];
        }
        if(t==-1)return false;
    }
    cout<<t<<endl;
    for(int i=0;i<data.size();i++){
        if(data[i]<t*0.5){
            return false;
        }else if(data[i]<t*1.5){//1T
            rep.body.push_back(1);
        }else if(data[i]<t*2.5){//2T
            rep.body.push_back(2);
        }else if(data[i]<t*3.5){//3T
            rep.body.push_back(3);
        }else if(data[i]<t*6){//4T SONY
            rep.body.push_back(4);
        }else if(data[i]<t*12){//8T AEHA
            rep.body.push_back(8);
        }else if(data[i]<t*22){//16T NEC
            rep.body.push_back(16);
        }else{
            return false;
        }
    }
    return true;
}

bool sendIR(IrCodeC ir){
    chrono::microseconds t(562);
    gpioSetPWMrange(IR_LED_PIN,30);
    gpioSetPWMfrequency(IR_LED_PIN,40000);
    auto start = chrono::system_clock::now();
    int sum=0;
    for(int i=0;i<ir.body.size();i++){
        gpioPWM(IR_LED_PIN,((i+1)%2)*10);
        sum+=ir.body[i];
        this_thread::sleep_until(start+sum*t);
    }
    gpioPWM(IR_LED_PIN,0);
    return true;
}

int main(int argc, char *argv[]){
    if(argc!=2)return 0;
    gpioCfgClock(1,1,0);
    if(gpioInitialise() <0){
        return -1;
    }
    gpioSetMode(BUTTON_PIN,PI_INPUT);
    gpioSetMode(IR_SENS_PIN,PI_INPUT);
    gpioSetMode(IR_LED_PIN,PI_OUTPUT);
    gpioWrite(IR_LED_PIN,0);
    vector<IrCodeC> codes;
    string ifilename ="codeData.txt";
    ifstream ifile(ifilename);
    if(!ifile){
        cout<<"ファイルが見当たりません"<<endl;
        exit(1);
    }
    while(!ifile.eof()){
        string line;
        getline(ifile,line);
        //cout<<line<<endl;
        IrCodeC tmp;
        istringstream iss(line);
        string s;
        while(iss>>s)tmp.body.push_back(stoi(s));
        codes.push_back(tmp);
    }
    /*
    for(int i=0;i<codes[0].body.size();i++){
        cout<<codes[0].body[i]<<" ";
    }
    cout<<endl;
    */
    for(int i=0;i<6;i++){
      if(i!=0)usleep(100000);
      sendIR(codes[atoi(argv[1])]);
    }
    gpioTerminate();
    return 0;
}
