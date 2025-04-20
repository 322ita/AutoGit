#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
    
    if(argv[1] == nullptr) {
        cout<<"Nessun messaggio di commit fornito."<<endl;
        return -1;
    }else if(argv[2] == nullptr) {
        cout<<"Nessun branch fornito."<<endl;
        return -1;
    }
    string messaggio = argv[1];
    string branch = argv[2];

    cout<<"messaggio: "<<messaggio<<endl;
    cout<<"branch: "<<branch<<endl;
    string comando = "git commit -m \""+messaggio+"\"";
    string comando2 = "git push origin \""+branch+"\"";
    
    cout<<"aggiungendo i file git..."<<endl;
    system("git add .");

    cout<<"eseguendo il commit..."<<endl;
    cout<<"comando: "<<comando<<endl;
    system(comando.c_str());

    cout<<"mandando al branch "<<branch<<endl;
    system(comando2.c_str());
    


    return 0;
}