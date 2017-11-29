//#include "lista.h"
#include "basedatos.h"
#include "baseDatosVista.h"
#include "baseDatosControl.h"
#include "tablaControl.h"
#include "tablaVista.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    BaseDatosVista bdv;
    BaseDatos bd("universidad.bd");
    BaseDatosControl bdc;
    TablaVista tv;
    TablaControl tc;
    bool execute=true;
    bool vBD=true;
    while(execute){
        if(vBD){
            bdv.mostrarComandos();
            bdc.setOpcion(bd,bdv,execute,vBD);
        }
        else{
            tv.mostrarComandos();
            tc.setOpcion(bd,tv,vBD);
        }
    }
    return 0;
}
