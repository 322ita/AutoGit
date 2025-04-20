#include<iostream>
#include<string>
using namespace std;

bool gitCheck();

int main(int argc, char *argv[]) {
    
    if(!gitCheck()){
        cout<<"git non è installato!"<<endl;
        return -1;
    }

    if(argv[1] == nullptr) {
        cout<<"Nessun messaggio di commit fornito."<<endl;
        return -2;
    }else if(argv[2] == nullptr) {
        cout<<"Nessun branch fornito."<<endl;
        return -3;
    }
    string messaggio = argv[1];
    string branch = argv[2];

    cout<<"messaggio: "<<messaggio<<endl;
    cout<<"branch: "<<branch<<endl;
    string comando = "git commit -m \""+messaggio+"\"";
    string comando2 = "git push origin \""+branch+"\"";
    
    cout<<"aggiungendo i file..."<<endl;
    system("git add .");

    cout<<"eseguendo il commit..."<<endl;
    system(comando.c_str());

    cout<<"mandando al branch "<<branch<<endl;
    system(comando2.c_str());
    


    return 0;
}


bool gitCheck(){
    cout<<"Controllo se git è installato..."<<endl;
    string ris = _WIN32 ? "NUL 2>&1" : "/dev/null 2>&1";
    string command = "git --version > " + ris;
    int result = system(command.c_str());
    return result == 0;
}