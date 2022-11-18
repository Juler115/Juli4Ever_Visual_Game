#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Juli.h"
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <stdio.h>
#define HAVE_STRUCT_TIMESPEC
#include <thread>
#include <chrono> 
#include <codecvt>
#include <tchar.h>

extern map<string,string> Datos;	
extern vector<string>DatMusic;
extern vector<string>DatMusic;
//extern string basura;
extern bool Usados[5];
extern Julieta Juli;
//extern thread hilo;

extern vector<string> EresT;
extern vector<string> SirvesT;
extern vector<string> PensamientosT;
extern vector<string> NosotrosT;
extern vector<string> MiT;


void Act();
bool check();
void dat();
string Bienvenida();
void CACumple();
void CAFavComi();
void CAFavPasat();
void CAAspiraciones();
void Cambio();
void Cambi(int);
void Modi(string, string);
void pause_thread(int);
void stopMusic();
void musica();
void Music(string);
void Gustar();
void Musica();
void CAAfecto();
void JuMusica(int);
void Jugar();
void JugarOp(int);
void TyV();
string Eres(int);
string Sirves(int);
string Pensamientos(int);
string Nosotros(int);
string Mi(int);
void Siento();
void SientoOp(int);
string Enojado();
string Triste();
string Feliz();
string Aburrido();
string Nervioso();
void Decir();
void DecirOp(int);
void DecirOp2(int);
void ACF();