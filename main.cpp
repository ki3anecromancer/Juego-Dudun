#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Estructura que guarda los datos del personaje
struct Personaje {
    int vida;
    int mana;
    int ataque;
    int defensa;
    int pociones;
    int monedas;
    char nombre[20];
} pj;

// Estructura que guarda la vida de los esqueletos
struct Esqueleto {
    int vida;
} esqueleto;

// Estructura primer jefe:


int main() {
    int n_enemigo;	// Que enemigo toca
    int accion;	// Opcion elegida
    int zona(20); // Contador de zonas

    // Valores iniciales del personaje
    pj.vida = 100;
    pj.mana = 100;
    pj.ataque = 1;
    pj.defensa = 1;
    pj.pociones = 1;
    pj.monedas = 0;

    srand(time(NULL)); // Inicializar numero random
///////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Elija un nombre de 20 caracteres o menos: ";
    cin.getline(pj.nombre, 20, '\n');
    // Dejar espacio largo
    for (int i=0; i<40; i++) {
        cout << '\n';
    }
///////////////////////////////////////////////////////////////////////////////////////////////////
    // Repetir accion mientras la haya vida
    do {
        do {
            // Mostrar estadisticas del personaje
            cout << "Vida [" << pj.vida << "]\tMana [" << pj.mana << "]" << endl;
            cout << "Ataque [" << pj.ataque << "]\tDefensa [" << pj.defensa << "]" << endl;
            cout << "Pociones [" << pj.pociones << "]\tMonedas [" << pj.monedas << "]" << endl;


            cout << "\n[1] Avanzar\n[2] Usar pocion\n\t\tAccion elegida: ";
            cin >> accion;

            switch(accion) {
            case 1:
                // Dejar espacio largo
                for (int i=0; i<40; i++) {
                    cout << '\n';
                }

                // PRIMER JEFE: Golem de Arcilla
            	if (zona == 20) {
					cout << "\n**************************************************\n";
					cout << "\tZONA 20: Catacumba del Nigromante";
					cout << "\n**************************************************\n";

					cout << "\nHas llegado a la Zona 20, te encuentras con un guerrero moribundo." << endl;
					cout << "\nGUERRERO: Si vas hacia alli ten cuidado, apenas he logrado escapar." << endl;
					cout << "Ten mis ultimas pociones, mi espada y mis bendiciones en tu batalla." << endl;
					cout << "\n\n\t-- Presione una tecla para continuar --";
                    getch();
					cout << "\n\n" << pj.nombre << " ha recuperado la salud al 100%" << endl;
					cout << pj.nombre << " ha conseguido +1 de ataque" << endl;
					pj.vida = 100;
					pj.ataque += 1;

					cout << "\n\n\t-- Presione una tecla para continuar --";
                    getch();
					zona++;
					break;
            	}



                // Mensaje de zona actual
                cout << "\n=====================================================\n";
                cout << "\t:::: Has avanzado a la zona " << zona << " ::::" << endl;
                cout << "=====================================================\n";
                n_enemigo = 1+rand()%100;	// Generar numero aleatorio [1,100]

                // 1% chances de que aparezca una Sombra Extraña
                if (n_enemigo == 1) {
                    cout << "\n== TE HAS TOPADO CON UNA SOMBRA EXTRANA ==\n";
                    cout << "\nPierdes la mitad de tus monedas y de tus pociones\n" << endl;
                    pj.monedas -= (pj.monedas * 0.5);
                    pj.pociones -= (pj.pociones * 0.5);
                    cout << "Te quedan [" << pj.monedas << "] monedas" << endl;
                    cout << "Te quedan [" << pj.pociones << "] pociones" << endl;
                    cout << "\n\n\t-- Presione una tecla para continuar --";
                    getch();
                }

                // 2% chances de que aparezca un Herrero
                else if ((n_enemigo == 2) || (n_enemigo == 3)) {
                    cout << "\n== HAS ENCONTRADO UN HERRERO ==\n";

                    int mejora; // Nivel de mejora de las estadisticas
                    mejora = 1+rand()%5;

                    if (n_enemigo == 2) {
                        cout << "\nEl herrero ha mejorado en [" << mejora << "] tu ataque" << endl;
                        pj.ataque += mejora;
                        cout << "\nTu ataque actual es [" << pj.ataque << "]" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    } else if (n_enemigo == 3) {
                        cout << "\nEl herrero ha mejora en [" << mejora << "] tu defensa" << endl;
                        pj.defensa += mejora;
                        cout << "\nTu defensa actual es [" << pj.defensa << "]" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    }
                }

                // 5% chances de que aparezca un Cofre Misterioso
                else if ((n_enemigo >=4) && (n_enemigo <= 8)) {
                    cout << "\n== HAS ENCONTRADO UN COFRE MISTERIOSO ==\n";

                    int contenido; // Que objeto aparece
                    contenido = 1+rand()%100;

                    if (contenido <=30) {
                        cout << "\nTu defensa ha aumentado [2] puntos" << endl;
                        pj.defensa += 2;
                        cout << "\n[" << pj.defensa << "] defensa actual" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    } else if ((contenido > 30) && (contenido <= 60)) {
                        cout << "\nTu ataque ha aumentado [2] puntos" << endl;
                        pj.ataque += 2;
                        cout << "\n[" << pj.ataque << "] ataque actual" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    } else if ((contenido > 60) && (contenido <= 80)) {
                        cout << "\nHas encontrado una pocion curativa" << endl;
                        pj.pociones += 1;
                        cout << "\n[" << pj.pociones << "] pociones actuales" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    } else if ((contenido > 80) && (contenido <= 100)) {

                        int oro_cofre;
                        oro_cofre = 20+rand()%16;

                        cout << "\nHas encontrado [" << oro_cofre << "] monedas" << endl;
                        pj.monedas += oro_cofre;
                        cout << "\n[" << pj.monedas << "] monedas actuales" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    }
                }

                // 6% chances de encontrar un Botin tirado
                else if ((n_enemigo >= 9) && (n_enemigo <= 14)) {
                    cout << "\n== HAS ENCONTRADO UN BOTIN PERDIDO ==\n";

                    int botin_perdido; // Oro del botin
                    botin_perdido = 20+rand()%31;

                    cout << "\nHas recogido [" << botin_perdido << "] monedas" << endl;
                    pj.monedas += botin_perdido;
                    cout << "\n[" << pj.monedas << "] monedas actuales" << endl;
                    cout << "\n\n\t-- Presione una tecla para continuar --";
                    getch();
                }

                // 6& chances de encontrarse un Curandero
                else if ((n_enemigo >= 15) && (n_enemigo <= 20)) {
                    cout << "\n== TE HAS TOPADO CON UN CURANDERO==\n";

                    // Si la vida esta completa
                    if (pj.vida == 100) {
                        cout << "\nTu vida ya esta al maximo" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    }
                    // Si la vida esta a la mitad o mas
                    else if (pj.vida >= 50) {
                        cout << "\nHas recuperado [" << 100-pj.vida << "] de vida" << endl;
                        pj.vida = 100;
                        cout << "\n[" << pj.vida << "] vida actual" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    }
                    // Si la vida esta a menos de la mitad
                    else if (pj.vida <50) {
                        cout << "\nHas recuperado [50] de vida" << endl;
                        pj.vida += 50;
                        cout << "\n[" << pj.vida << "] vida actual" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                    }

                }

                // 20% chances de encontrar un Mercader
                else if ((n_enemigo >=21) && (n_enemigo <= 40)) {
                    cout << "\n== Te has topado con un Mercader ==\n";

                    int mercader_opcion, seguir_comprando;

                    do {
                        cout << "\n------------------";
                        cout << "\n[" << pj.monedas << "] monedas disponibles";
                        cout << "\n[" << pj.pociones << "] pociones actuales";
                        cout << "\n[" << pj.ataque << "] ataque actual";
                        cout << "\n[" << pj.defensa << "] defensa actual\n";
                        cout << "------------------\n";
                        cout << "\nOpcion\tPrecio\tProducto\tEfecto\n";
                        cout << "1.\t[30]\tPocion\t\tRecupera 20 de vida" << endl;
                        cout << "2.\t[40]\tEspada\t\t+1 de Ataque" << endl;
                        cout << "3.\t[40]\tEscudo\t\t+1 de Defensa" << endl;
                        cout << "4. Salir" << endl;

                        // Salir de la tienda si el jugador NO tiene dinero
                        if (pj.monedas < 30) {
                            cout << "\nNo tienes dinero suficiente para comprar en la tienda" << endl;
                            mercader_opcion = 4;
                        }

                        // Ingresar en la tienda si el jugador tiene dinero suficiente
                        else if (pj.monedas >= 30) {
                            cout << "\n\tElija una opcion: ";
                            cin >> mercader_opcion;

                            // Comprar pocion curativa
                            if (mercader_opcion == 1) {
                                if (pj.monedas >= 30) {
                                    cout << "\nHas comprado una pocion curativa" << endl;
                                    pj.pociones += 1;
                                    pj.monedas -= 30;
                                    cout << "\n[" << pj.pociones << "] pociones actuales" << endl;
                                    cout << "[" << pj.monedas << "] monedas restantes" << endl;
                                    // Opcion de seguir comprando
                                    do {
                                        cout << "------------------\n";
                                        cout << "\nSeguir en la tienda? [1] SI [2] NO";
                                        cout << "\n\t\t\t\tElija una opcion: ";
                                        cin >> seguir_comprando;
                                        switch (seguir_comprando) {
                                        case 1:
                                            // Dejar espacio largo
                                            for (int i=0; i<40; i++) {
                                                cout << '\n';
                                            }
                                            break;
                                        case 2:
                                            mercader_opcion = 4;
                                            break;
                                        }
                                    } while ((seguir_comprando < 1) || (seguir_comprando > 2));

                                }
                            }
                            // Comprar espada +1 ataque
                            else if (mercader_opcion == 2) {
                                if (pj.monedas >= 40) {
                                    cout << "\nHas comprado una espada" << endl;
                                    pj.ataque += 1;
                                    pj.monedas -= 40;
                                    cout << "\n[" << pj.ataque << "] ataque actual" << endl;
                                    cout << "[" << pj.monedas << "] monedas restantes" << endl;
                                    // Opcion de seguir comprando
                                    do {
                                        cout << "------------------\n";
                                        cout << "\nSeguir en la tienda? [1] SI [2] NO";
                                        cout << "\n\t\t\t\tElija una opcion: ";
                                        cin >> seguir_comprando;
                                        switch (seguir_comprando) {
                                        case 1:
                                            // Dejar espacio largo
                                            for (int i=0; i<40; i++) {
                                                cout << '\n';
                                            }
                                            break;
                                        case 2:
                                            mercader_opcion = 4;
                                            break;
                                        }
                                    } while ((seguir_comprando < 1) || (seguir_comprando > 2));
                                } else if (pj.monedas < 40) {
                                    cout << "\nNo dispones del dinero suficiente" << endl;
                                    cout << "\n\t::::::::::::::::::::::::::::::::::::::\n\n";
                                    cout << "\n\n\t-- Presione una tecla para continuar --";
                                    getch();
                                    // Dejar espacio largo
                                    for (int i=0; i<40; i++) {
                                        cout << '\n';
                                    }
                                }
                            }
                            // Comprar escudo +1 defensa
                            else if (mercader_opcion == 3) {
                                if (pj.monedas >= 40) {
                                    cout << "\nHas comprado un escudo" << endl;
                                    pj.defensa += 1;
                                    pj.monedas -= 40;
                                    cout << "\n[" << pj.defensa << "] defensa actual" << endl;
                                    cout << "[" << pj.monedas << "] monedas restantes" << endl;
                                    // Opcion de seguir comprando
                                    do {
                                        cout << "------------------\n";
                                        cout << "\nSeguir en la tienda? [1] SI [2] NO";
                                        cout << "\n\t\t\t\tElija una opcion: ";
                                        cin >> seguir_comprando;
                                        switch (seguir_comprando) {
                                        case 1:
                                            // Dejar espacio largo
                                            for (int i=0; i<40; i++) {
                                                cout << '\n';
                                            }
                                            break;
                                        case 2:
                                            mercader_opcion = 4;
                                            break;
                                        }
                                    } while ((seguir_comprando < 1) || (seguir_comprando > 2));
                                } else if (pj.monedas < 40) {
                                    cout << "\nNo dispones del dinero suficiente" << endl;
                                    cout << "\n\t::::::::::::::::::::::::::::::::::::::\n\n";
                                    cout << "\n\n\t-- Presione una tecla para continuar --";
                                    getch();
                                    // Dejar espacio largo
                                    for (int i=0; i<40; i++) {
                                        cout << '\n';
                                    }
                                }
                            }
                            // Si la opcion marcada no es ninguna valida
                            else if ((mercader_opcion < 1) || (mercader_opcion > 4)) {
                                cout << "\nIngrese una opcion valida" << endl;
                                cout << "\n\t::::::::::::::::::::::::::::::::::::::\n\n";
                                cout << "\n\n\t-- Presione una tecla para continuar --";
                                getch();
                                // Dejar espacio largo
                                for (int i=0; i<40; i++) {
                                    cout << '\n';
                                }
                            }
                        }
                    } while (mercader_opcion != 4);
                    cout << "\n\n\t-- Presione una tecla para continuar --";
                    getch();
                }

                // 60% chances de que aparezca de 1 a 3 esqueletos
                // Primera zona 1-19
                else if ((n_enemigo > 40) && (zona < 20)) {
                    int cantidad_enemigos; // Cuantos enemigos aparecen [1,3]
                    int critico_enemigo; // Probabilidad golpe critico del enemigo
                    int critico_pj; // Probabilidad golpe critico personaje
                    int ataque_enemigo; // Danio hecho por el enemigo
                    int seleccion_combate; // Opcion elegida para combatir
                    int danioT_enemigo; // Danio total enemigo
                    int vida_perdidad; // Vida que pierde el personaje
                    int ataque_pj; // Danio hecho por el personaje
                    int recompensa_esqueleto; // Monedas recibida por derrotar un esqueleto
                    char fcrit_ene; // Marcar que el enemigo hizo danio critico;
                    char fcrit_pj; // Marcar que el personaje hizo danio critico;
                    int drop_pocion; // Chances de tirar una pocion

                    cantidad_enemigos = 1+rand()%2;

                    cout << "\n=== HAS SIDO EMBOSCADO POR " << cantidad_enemigos << " ESQUELETOS GUERREROS===" << endl;

                    esqueleto.vida = 10; // Reiniciar vida del esqueleto

                    // Batalla con el/los enemigo
                    do {
                        cout <<  "\nEnemigos restantes: " << cantidad_enemigos << endl;
                        cout << "\nVida del enemigo: " << esqueleto.vida << endl; // Mostrar vida del enemigo
                        cout << "\nVida de " << pj.nombre << " [" << pj.vida << "]" << endl; // Mostrar vida del personaje
                        cout << "Mana de " << pj.nombre << " [" << pj.mana << "]" << endl; // Mostrar mana del personaje

                        // Opciones enemigos enemigo
                        cout << "\n1. Atacar" << endl;
                        cout << "2. Defender [50% menos de dano recibido]" << endl;

                        // Preguntar por su opcion hasta que elija una opcion valida [1,2]
                        do {
                            cout << "\n\t\tAccion elegida: ";
                            cin >> seleccion_combate;
                        } while ((seleccion_combate < 1) || (seleccion_combate > 2));

                        ///////////////////////////// Calcular el danio del enemigo
                        ataque_enemigo = 1+rand()%3; // Ataque del enemigo [1,3]
                        critico_enemigo = 1+rand()%100; // Probabilidad de golpe critico enemigo [1,100]
                        fcrit_ene = 'F'; // Resetear danio critico del enemigo

                        if (critico_enemigo > 5) { // 95% chances de ataque normal
                            danioT_enemigo = ataque_enemigo;
                        } else if (critico_enemigo <= 5) { // 5% chances de golpe critico +50% danio
                            danioT_enemigo = ataque_enemigo * 2;
                            fcrit_ene = 'V';
                        }

                        if (danioT_enemigo > pj.defensa) {
                            vida_perdidad = danioT_enemigo - pj.defensa;
                        } else if (danioT_enemigo <= pj.defensa) {
                            vida_perdidad = 1;
                        }

                        ///////////////////////////// Calcular el danio del personaje
                        critico_pj = 1+rand()%100; // Probabilidad de golpe critico del personaje [1,100]
                        fcrit_pj = 'F'; // Resetear danio critico personaje

                        if (critico_pj > 5) { // 95% chances de ataque normal
                            ataque_pj = pj.ataque;
                        } else if (critico_pj <= 5) { // 5% chances de golpe critico
                            ataque_pj = pj.ataque * 2;
                            fcrit_pj = 'V';
                        }
                        /////////////////////////////

                        switch(seleccion_combate) {
                        case 1:

                            // Dejar espacio largo
                            for (int i=0; i<40; i++) {
                                cout << '\n';
                            }
                            cout << "\n=== Turno del 'Esquleto Guerrero' ===" << endl;

                            // Mensaje ataque del enemigo
                            if (fcrit_ene == 'V') { // Mensaje golpe critico enemigo
                                cout << "[GOLPE CRITICO] ";
                            }
                            cout << "Pierdes " << vida_perdidad << " puntos de vida" << endl;
                            pj.vida -= vida_perdidad;

                            if (pj.vida > 0) { // Mensaje si aun queda vida
                                cout << "\n[" << pj.vida << "] vida restante" << endl;
                            } else if (pj.vida <= 0) { // Mensaje si no queda mas vida
                                pj.vida = 0;
                                cout << "\n[0] vida restante" << endl;
                                cout << "\n\n\t-- Presione una tecla para continuar --";
                                getch();
                                break;
                            }

                            // Mensaje ataque del personaje
                            cout << "\n=== Turno de " << pj.nombre << " ===" << endl;
                            if (fcrit_pj == 'V') { // Mensaje golpe critico personaje
                                cout << "[GOLPE CRITICO] ";
                            }
                            cout << "El enemigo pierde " << ataque_pj << " puntos de vida" << endl;
                            esqueleto.vida -= ataque_pj;

                            if (esqueleto.vida > 0) { // Mensaje si le queda vida al enemigo
                                cout << "\n[" << esqueleto.vida << "] vida restante" << endl;
                            } else if (esqueleto.vida <= 0) { // Mensaje si muere el enemigo
                                cout << "\n[0] vida restante" << endl;
                                recompensa_esqueleto = 5+rand()%3;
                                cout << "\nHas obtenido " << recompensa_esqueleto << " monedas" << endl;
                                pj.monedas += recompensa_esqueleto;
                                cantidad_enemigos--;
                                esqueleto.vida = 10;

                                drop_pocion = 1+rand()%+100; // Numero al azar [1,100]
                                if (drop_pocion <= 5) {
                                    cout << "Has obtenido una pocion" << endl;
                                    pj.pociones += 1;
                                }

                                cout << "\n\n\t-- Presione una tecla para continuar --";
                                getch();
                                // Dejar espacio largo
                                for (int i=0; i<40; i++) {
                                    cout << '\n';
                                }
                                break;
                            }

                            cout << "\n\n\t-- Presione una tecla para continuar --";
                            getch();
                            // Dejar espacio largo
                            for (int i=0; i<40; i++) {
                                cout << '\n';
                            }
                            break;
                        case 2:
                            cout << "\n=== Turno del 'Esquleto Guerrero' ===" << endl;

                            // Mensaje ataque del enemigo
                            if (fcrit_ene == 'V') { // Mensaje golpe critico enemigo
                                cout << "[GOLPE CRITICO] ";
                            }
                            cout << "Pierdes " << vida_perdidad << " puntos de vida" << endl;
                            pj.vida -= vida_perdidad - (vida_perdidad / 2);
                            break;
                        }

                    } while ((cantidad_enemigos > 0) && (pj.vida > 0));

                    // Dejar espacio largo
                    for (int i=0; i<40; i++) {
                        cout << '\n';
                    }
                }

                // Dejar espacio corto
                for (int i=0; i<3; i++) {
                    cout << '\n';
                }
                // Avanzar de zona
                zona++;
                break;

            case 2:	// Usar pociones
                if (pj.pociones <= 0) {	// NO TIENE POCIONES
                    cout << "\nNo hay pociones disponibles" << endl;
                    cout << "\n\n\t-- Presione una tecla para continuar --";
                    getch();
                    break;
                } else if (pj.pociones > 0) {	// TIENE POCIONES
                    if (pj.vida == 100) {
                        cout << "\nNo se puede aumentar mas la vida" << endl;
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                        break;
                    } else if (pj.vida >= 80) {
                        cout << "\nVida restaurada al maximo" << endl;
                        pj.vida = 100;
                        pj.pociones -= 1;
                        cout << "\n[" << pj.vida << "] Vida actual";
                        cout << "\n[" << pj.pociones << "] Pociones restantes";
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                        break;
                    } else if (pj.vida < 80) {
                        cout << "\nHas recuperado 20 puntos de vida" << endl;
                        pj.vida += 20;
                        pj.pociones -= 1;
                        cout << "\n[" << pj.vida << "] Vida actual";
                        cout << "\n[" << pj.pociones << "] Pociones restantes";
                        cout << "\n\n\t-- Presione una tecla para continuar --";
                        getch();
                        break;
                    }
                }
            }

            // Dejar espacio largo
            for (int i=0; i<40; i++) {
                cout << '\n';
            }

        } while (accion < 1 || accion > 2);
    } while (pj.vida >0);
///////////////////////////////////////////////////////////////////////////////////////////////////
    // Si gana el juego
    if (pj.vida > 0) {
        cout << "\nGANASTE" << endl;
    } else if (pj.vida <= 0) {
        cout << "\nPERDISTE GAME OVER" << endl;
    }


    getch();
    return 0;
}
