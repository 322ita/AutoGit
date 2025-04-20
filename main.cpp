#include<iostream>
#include<string>
using namespace std;

bool gitCheck();

int main(int argc, char *argv[]) {
    
    if(!gitCheck()){
        cout<<"git is not installed!"<<endl;
        return -1;
    }

    if(argv[1] == nullptr) {
        cout<<"No comment for commit inputed."<<endl;
        return -2;
    }else if(argv[2] == nullptr) {
        cout<<"No branch inputed."<<endl;
        return -3;
    }
    string messaggio = argv[1];
    string branch = argv[2];

    cout<<"Message: "<<messaggio<<endl;
    cout<<"Branch: "<<branch<<endl;
    string comando = "git commit -m \""+messaggio+"\"";
    string comando2 = "git push origin \""+branch+"\"";
    
    cout<<"Adding the files..."<<endl;
    system("git add .");

    cout<<"commiting..."<<endl;
    system(comando.c_str());

    cout<<"pushing to "<<branch<<endl;
    system(comando2.c_str());
    


    return 0;
}


bool gitCheck(){
    cout<<"Checking if git is installed..."<<endl;
    string ris;
    #ifdef _WIN32
        ris = "NUL 2>&1";
    #else
        ris = "/dev/null 2>&1";
    #endif
    string command = "git --version > " + ris;
    int result = system(command.c_str());
    return result == 0;
}