#include <QCoreApplication>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
using std::cout;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int numero;
    pid_t pid;

    for(numero=0; numero<3; numero++){
        pid = fork();
        cout<<"Hola Soy el Proceso: "<<getpid()<<" y mi padre es: "<<getppid()<<"\n";
        if( pid!=0 ){
            break;
        }
        srandom( getpid() );
        sleep( random()%3 );
    }
    if( pid!=0 ){
        cout<<"Fin del Proceso: "<<wait(NULL)<<"\n";
    }
    return 0;
}
