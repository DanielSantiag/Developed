/* Jogo da Velha
 Daniel Ferreira Santiago - danielto07@yahoo.com.br - daniel.x.santiago@gmail.com
 Ricardo Alves Teixeira   
 Renan Moreira dos Santos 
 3º Semestre - Ciência da Computação    
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.c>
#include <conio.h>
#include <string.h>
#include <windows.h>

// Variáveis globais.
char mt[3][3];
int p=0,lug=0,lug1=0,mod=3,lg=0,beginJg=0,jg=0,poss=6,pt=0,op1=0,op=0,px1,py1,px2,py2,scx=0,ct=0;
int vl1=0,vl2=0,jgd=0,jg2=0,win,winx,pos,gx=0,gy=0,vlgx=0,vlgy=0,intro=0,ladg,emp=0,mv=0,at;
char lad=' ',lad1=' ',us='X',pc='O',nom[20]={'-','-','-'};

int wwin(){ // Função "wwin" tem como objetivo verificar quem ganhou X ou O.
   int x,y;
   // Verificá x
   for(x=0;x<3;x++){  
   if(mt[0][x]==us && mt[1][x]==us && mt[2][x]==us){gx=1;vlgx++;ladg='v';lg=x;}}
   for(y=0;y<3;y++){
   if(mt[y][0]==us && mt[y][1]==us && mt[y][2]==us){gx=1;vlgx++;}}
   if(mt[0][0]==us && mt[1][1]==us && mt[2][2]==us){gx=1;vlgx++;}
   if(mt[0][2]==us && mt[1][1]==us && mt[2][0]==us){gx=1;vlgx++;}

   // Verificá O.
   for(x=0;x<3;x++){  
   if(mt[0][x]==pc && mt[1][x]==pc && mt[2][x]==pc){gy=1;vlgy++;}}
   for(y=0;y<3;y++){
   if(mt[y][0]==pc && mt[y][1]==pc && mt[y][2]==pc){gy=1;vlgy++;}}
   if(mt[0][0]==pc && mt[1][1]==pc && mt[2][2]==pc){gy=1;vlgy++;}
   if(mt[0][2]==pc && mt[1][1]==pc && mt[2][0]==pc){gy=1;vlgy++;}
     
   if(gx>0||gy>0){return 1;}else{return 0;}   
}
     
int temcomodefend(){ // Função "temcomodefend" verificá se há possibilidades de defender.     
    int y1,c,i;
    winx=0;
// Verificá na horizontal.
   int x,y,vt=0;
   for(x=0;x<3;x++){
     for(y=0;y<3;y++){                
       if(mt[x][y]==us){ vt++; }
       if(vt==2){for(y1=0;y1<3;y1++){if(mt[x][y1]==' '){ vt++; } }}
       if(vt==3){ winx++; lad1='h'; lug1=x; vt++; }
   }vt=0;
   }
// "mod>=1" mod é o nível do game, então se nível for médio verificá na vertical. 
   if(mod>=1){ 
// Verificá na vertical.
   for(x=0;x<3;x++){
     for(y=0;y<3;y++){                
       if(mt[y][x]==us){ vt++; }
       if(vt==2){for(y1=0;y1<3;y1++){if(mt[y1][x]==' '){ vt++; } }}
       if(vt==3){ winx++; lad1='l'; lug1=x; vt++; }
   }vt=0;
   }}
   
   vt=0;
// "mod>=2" se nível for hard, verificá as diagonais.    
   if(mod>=2){ 
// Se nível hard, verificá nas diagonais.
   for(x=0;x<3;x++){
   if(mt[x][x]==us){vt++;}
   if(mt[x][x]==pc){ vt=0;}}
   if(vt==2){for(y1=0;y1<3;y1++){if(mt[y1][y1]==' '){ vt++; } }}
   if(vt==3){winx++;}
   vt=0;
   for(x=0,c=2;x<3;x++,c--){
   if(mt[x][c]==us){vt++;}
   if(mt[x][c]==pc){ vt=0;}}
   if(vt==2){for(y1=0,c=2;y1<3;y1++,c--){if(mt[y1][c]==' '){ vt++; } }}
   if(vt==3){winx++; lad1='d';}}
// Se nível for impossible, então verificá uma posição especial.   
   if(mod>=3){if(mt[2][1]==us && mt[1][2]==us){ if(mt[2][2]==' '){winx++; lad1='c';}}}
   
   return winx;  
}


int temcomoganha(){ // Essa função verificá se há possibilidades de ganhar.
    int y1,x1;
    win=0;

   // Verificá na horizontal.
   int x,y,vt=0;
   for(x=0;x<3;x++){
     for(y=0;y<3;y++){                
       if(mt[x][y]==pc){ vt++; }
       if(vt==2){for(y1=0;y1<3;y1++){if(mt[x][y1]==' '){ vt++; } }}
       if(vt==3){ win++; lug=x; lad='h'; vt=0; }
   }vt=0;}
   if(mod>=1){ //Se nível for médio, entra nessa condição.
   //Lateral
   for(x=0;x<3;x++){
     for(y=0;y<3;y++){                
       if(mt[y][x]==pc){ vt++; }
       if(vt==2){for(y1=0;y1<3;y1++){if(mt[y1][x]==' '){ vt++; } }}
       if(vt==3){ win++; lug=x; lad='l'; vt=0; }
   }vt=0;}}
   //Diagonal
   if(mod>=2){
     for(y=0;y<3;y++){                
       if(mt[y][y]==pc){ vt++; }
       if(vt==2){for(y1=0;y1<3;y1++){if(mt[y1][y1]==' '){ vt++; } }}
       if(vt==3){ win++; lad='a'; vt=0; }       
   }vt=0;
    for(y=0,x=2;y<3;y++,x--){                              
       if(mt[y][x]==pc){ vt++; }
       if(vt==2){for(y1=0,x1=2;y1<3;y1++,x1--){if(mt[y1][x1]==' '){ vt++; } }}
       if(vt==3){ win++; lug=x; lad='b'; vt=0; }
       }vt=0;
       }
   vt=0;
   
   return win ;  
   }

void estrut(int x,int y){ // Essa função mostra o cenário do game na tela. 
     char s1=205,s2=186,s3=206,s='+',ss=184;
     int temp=70,px=2,py=6;
     
     if(intro==0){  // Se for a primeira vez que joga, irá iniciar uma animação.
     textcolor(2);
     gotoxy(x,y); printf("   %c   %c   ",s2,s2);Sleep(temp);
     gotoxy(x,y+1); printf("   %c   %c   ",s2,s2);Sleep(temp);
     gotoxy(x,y+2); printf("%c%c%c%c%c%c%c%c%c%c%c",s1,s1,s1,s3,s1,s1,s1,s3,s1,s1,s1);Sleep(temp);
     gotoxy(x,y+3); printf("   %c   %c   ",s2,s2);Sleep(temp);
     gotoxy(x,y+4); printf("   %c   %c   ",s2,s2);Sleep(temp);
     gotoxy(x,y+5); printf("%c%c%c%c%c%c%c%c%c%c%c",s1,s1,s1,s3,s1,s1,s1,s3,s1,s1,s1);Sleep(temp);
     gotoxy(x,y+6); printf("   %c   %c   ",s2,s2);Sleep(temp);
     gotoxy(x,y+7); printf("   %c   %c   ",s2,s2);Sleep(temp);
     intro++;}
     //Estrutura do jogo da velha.
     textcolor(2);
     gotoxy(x,y); printf("   %c   %c   ",s2,s2);
     gotoxy(x,y+1); printf("   %c   %c   ",s2,s2);
     gotoxy(x,y+2); printf("%c%c%c%c%c%c%c%c%c%c%c",s1,s1,s1,s3,s1,s1,s1,s3,s1,s1,s1);
     gotoxy(x,y+3); printf("   %c   %c   ",s2,s2);
     gotoxy(x,y+4); printf("   %c   %c   ",s2,s2);
     gotoxy(x,y+5); printf("%c%c%c%c%c%c%c%c%c%c%c",s1,s1,s1,s3,s1,s1,s1,s3,s1,s1,s1);
     gotoxy(x,y+6); printf("   %c   %c   ",s2,s2);
     gotoxy(x,y+7); printf("   %c   %c   ",s2,s2);
     //Placar.
     textcolor(3);
     gotoxy(60,2); printf("User  :  %d",vlgx);
     gotoxy(60,3); printf("Pc    :  %d",vlgy);
     gotoxy(60,4); printf("Velha :  %d",emp);
     //Essa parte mostra a matriz principal "mt[3][3]" onde pode ser X ou O depende da variável us e pc.
     int c1=3,c2=6; //c1 e c2 define a cor para X e O.
     if(mt[0][0]==us){textcolor(c1);}if(mt[0][0]==pc){textcolor(c2);}gotoxy(x+1,y+1); printf("%c",mt[0][0]);
     if(mt[0][1]==us){textcolor(c1);}if(mt[0][1]==pc){textcolor(c2);}gotoxy(x+5,y+1); printf("%c",mt[0][1]);
     if(mt[0][2]==us){textcolor(c1);}if(mt[0][2]==pc){textcolor(c2);}gotoxy(x+9,y+1); printf("%c",mt[0][2]);
     if(mt[1][0]==us){textcolor(c1);}if(mt[1][0]==pc){textcolor(c2);}gotoxy(x+1,y+4); printf("%c",mt[1][0]);
     if(mt[1][1]==us){textcolor(c1);}if(mt[1][1]==pc){textcolor(c2);}gotoxy(x+5,y+4); printf("%c",mt[1][1]);
     if(mt[1][2]==us){textcolor(c1);}if(mt[1][2]==pc){textcolor(c2);}gotoxy(x+9,y+4); printf("%c",mt[1][2]);
     if(mt[2][0]==us){textcolor(c1);}if(mt[2][0]==pc){textcolor(c2);}gotoxy(x+1,y+7); printf("%c",mt[2][0]);
     if(mt[2][1]==us){textcolor(c1);}if(mt[2][1]==pc){textcolor(c2);}gotoxy(x+5,y+7); printf("%c",mt[2][1]);
     if(mt[2][2]==us){textcolor(c1);}if(mt[2][2]==pc){textcolor(c2);}gotoxy(x+9,y+7); printf("%c",mt[2][2]);
     

     if(gx==1||gy==1){ // Se X ou O bolinha ganhar, então entra nessa condição e mostra quem ganhou.
     if(gx==1){  gotoxy(32,15); printf("%c Win ",us); beginJg=0;  }
     if(gy==1){  gotoxy(32,15); printf("%c Win ",pc); beginJg=1; }}
     //Mostra na tela o nível do game.
     textcolor(3); gotoxy(2,2); printf("Modo:");
     textcolor(8);if(mod==0){ gotoxy(8,2); printf(" Easy");}
     textcolor(9);if(mod==1){ gotoxy(8,2); printf(" Medium");}
     textcolor(10);if(mod==2){ gotoxy(8,2); printf(" Hard");}
     textcolor(11);if(mod==3){ gotoxy(8,2); printf(" Impossible");}
     textcolor(4);if(mod==4){ gotoxy(8,2); printf(" Fight");}
     textcolor(7);      
     // Indicando a posição do cursor na estrutura do jogo.   
    gotoxy(px+1,py+1); printf("%c",s);
    gotoxy(px+5,py+1); printf("%c",s);
    gotoxy(px+9,py+1); printf("%c",s);
    gotoxy(px+1,py+4); printf("%c",s);
    gotoxy(px+5,py+4); printf("%c",s);
    gotoxy(px+9,py+4); printf("%c",s);
    gotoxy(px+1,py+7); printf("%c",s);
    gotoxy(px+5,py+7); printf("%c",s);
    gotoxy(px+9,py+7); printf("%c",s);
     // Mostra uma tabelinha no canto inferior esquerdo, Que indica a posição do cursor.     
     gotoxy(px+1,py-1);printf("Cursor");
    if(p==0){ gotoxy(px+1,py+1); printf("%c",ss);}
    if(p==1){ gotoxy(px+5,py+1); printf("%c",ss);}
    if(p==2){ gotoxy(px+9,py+1); printf("%c",ss);}
    if(p==3){ gotoxy(px+1,py+4); printf("%c",ss);}
    if(p==4){ gotoxy(px+5,py+4); printf("%c",ss);}
    if(p==5){ gotoxy(px+9,py+4); printf("%c",ss);}
    if(p==6){ gotoxy(px+1,py+7); printf("%c",ss);}
    if(p==7){ gotoxy(px+5,py+7); printf("%c",ss);}
    if(p==8){ gotoxy(px+9,py+7); printf("%c",ss);}
    // Mostra no canto inferior direito os comandos do game.
    textcolor(6);
    gotoxy(60,6);printf("*** Botoes ***");
    gotoxy(60,8);printf("    W ");
    gotoxy(60,9);printf(" A  S  D  <--> [K]");
    gotoxy(60,11);printf(" N --> Sair / Menu");
}

void ataqu(){ // Essa função é chamada quando não há possibilidades de ganhar ou defender.
     jg2++;

     if(jg2==1){ if(mt[1][1]==' '){mt[1][1]=pc;}else{ if(mt[0][0]==' '){mt[0][0]=pc;}}}
if(mt[0][2]==us || mt[0][0]==us){if(jg2==2){ if(mt[1][0]==' '){mt[1][0]=pc;}else{ if(mt[0][0]==' '){mt[0][0]=pc;}else{ if(mt[0][2]==' '){mt[0][2]=pc;}else{ if(mt[2][2]==' '){mt[2][2]=pc;}}}}}}else{
if(mt[1][2]==us){if(jg2==2){if(mt[2][2]==' '){mt[2][2]=pc;}else{ if(mt[0][2]==' '){mt[0][2]=pc;}else{ if(mt[0][0]==' '){mt[0][0]=pc;}}}}}else{
if(jg2==2){if(mt[0][0]==' '){mt[0][0]=pc;}else{ if(mt[0][2]==' '){mt[0][2]=pc;}else{ if(mt[2][2]==' '){mt[2][2]=pc;}}}}}
}
     if(jg2==3||jg2==4||jg2==5){if(mt[1][0]==' '){mt[1][0]=pc;}else{if(mt[0][0]==' '){mt[0][0]=pc;}else{ if(mt[0][1]==' '){mt[0][1]=pc;}else{
     if(mt[0][2]==' '){mt[0][2]=pc;}else{if(mt[1][1]==' '){mt[1][1]=pc;}else{if(mt[1][2]==' '){mt[1][2]=pc;}else{
     if(mt[2][0]==' '){mt[2][0]=pc;}else{if(mt[2][1]==' '){mt[2][1]=pc;}else{ if(mt[2][2]==' '){mt[2][2]=pc;}else{
     }}}}}}}}}
}}     
void maquina(){ // Nessa função está toda a inteligência da Máquina. 
     int c,i;
     if(temcomoganha()>0){ 
       if(lad=='h'){            
        if(lug==0){ for(c=0;c<3;c++){ if(mt[0][c]==' '){mt[0][c]=pc;}}}
        if(lug==1){ for(c=0;c<3;c++){ if(mt[1][c]==' '){mt[1][c]=pc;}}}
        if(lug==2){ for(c=0;c<3;c++){ if(mt[2][c]==' '){mt[2][c]=pc;}}}}
       if(lad=='l'){
        if(lug==0){ for(c=0;c<3;c++){ if(mt[c][0]==' '){mt[c][0]=pc;}}}
        if(lug==1){ for(c=0;c<3;c++){ if(mt[c][1]==' '){mt[c][1]=pc;}}}
        if(lug==2){ for(c=0;c<3;c++){ if(mt[c][2]==' '){mt[c][2]=pc;}}}}
        if(lad=='a'){
         for(c=0;c<3;c++){ if(mt[c][c]==' '){mt[c][c]=pc;}}}
        if(lad=='b'){
        if(mt[0][2]==' '){mt[0][2]=pc;}
        if(mt[1][1]==' '){mt[1][1]=pc;}
        if(mt[2][0]==' '){mt[2][0]=pc;}}
        // Se não jogar.
        if(lad=='h'){            
        if(lug==0){ for(c=0;c<3;c++){ if(mt[0][c]==us){ataqu();}}}
        if(lug==1){ for(c=0;c<3;c++){ if(mt[1][c]==us){ataqu();}}}
        if(lug==2){ for(c=0;c<3;c++){ if(mt[2][c]==us){ataqu();}}}}
       if(lad=='l'){
        if(lug==0){ for(c=0;c<3;c++){ if(mt[c][0]==us){ataqu();}}}
        if(lug==1){ for(c=0;c<3;c++){ if(mt[c][1]==us){ataqu();}}}
        if(lug==2){ for(c=0;c<3;c++){ if(mt[c][2]==us){ataqu();}}}}
        if(lad=='a'){
         for(c=0;c<3;c++){ if(mt[c][c]==' '){ataqu();}}}
        if(lad=='b'){
        if(mt[0][2]==us){ataqu();}
        if(mt[1][1]==us){ataqu();}
        if(mt[2][0]==us){ataqu();}}                                                    
        }else{
      if(temcomodefend()>0){ 
       if(lad1=='h'){            
        if(lug1==0){ for(c=0;c<3;c++){ if(mt[0][c]==' '){mt[0][c]=pc; winx=0;}}}
        if(lug1==1){ for(c=0;c<3;c++){ if(mt[1][c]==' '){mt[1][c]=pc; winx=0;}}}
        if(lug1==2){ for(c=0;c<3;c++){ if(mt[2][c]==' '){mt[2][c]=pc; winx=0;}}}}
       if(lad1=='l'){
        if(lug1==0){ for(c=0;c<3;c++){ if(mt[c][0]==' '){mt[c][0]=pc; winx=0;}}}
        if(lug1==1){ for(c=0;c<3;c++){ if(mt[c][1]==' '){mt[c][1]=pc; winx=0;}}}
        if(lug1==2){ for(c=0;c<3;c++){ if(mt[c][2]==' '){mt[c][2]=pc; winx=0;}}}}
       if(lad1=='d'){
        if(mt[0][2]==' '){mt[0][2]=pc;}
        if(mt[1][1]==' '){mt[1][1]=pc;}
        if(mt[2][0]==' '){mt[2][0]=pc;}}
       if(lad1=='c'){
        if(mt[2][2]==' '){mt[2][2]=pc;}             
                     } 
        
        }else{ataqu();}}} // Se não entrar em nenhuma condição acima, então chama a função ataqu.
void mudsimb(){ // Função para atribuir X ou O a matriz conforme a posição selecionada.
  int c,i,vn=0;
  for(c=0;c<3;c++){for(i=0;i<3;i++){
     // Mapeia a matriz, Atribuí X ou O, Atribuí mais 1 as variáveis jg e jgd.                              
     if(vn==p){ if(mt[c][i]==' '){mt[c][i]=us; jg=1; jgd++; if(wwin()==0){ if(beginJg==0){maquina();}} }}
     vn++; // Numera as posições de jogada.             
}}}               
int esclug(int x,int y){ // Função para o usuário escolher um lugar.
     int sai=0;
     char cmd,s='+';
     textcolor(1);
    if(p==0){ if(mt[0][0]==' '){gotoxy(x+1,y+1); printf("%c",s);}}
    if(p==1){ if(mt[0][1]==' '){gotoxy(x+5,y+1); printf("%c",s);}}
    if(p==2){ if(mt[0][2]==' '){gotoxy(x+9,y+1); printf("%c",s);}}
    if(p==3){ if(mt[1][0]==' '){gotoxy(x+1,y+4); printf("%c",s);}}
    if(p==4){ if(mt[1][1]==' '){gotoxy(x+5,y+4); printf("%c",s);}}
    if(p==5){ if(mt[1][2]==' '){gotoxy(x+9,y+4); printf("%c",s);}}
    if(p==6){ if(mt[2][0]==' '){gotoxy(x+1,y+7); printf("%c",s);}}
    if(p==7){ if(mt[2][1]==' '){gotoxy(x+5,y+7); printf("%c",s);}}
    if(p==8){ if(mt[2][2]==' '){gotoxy(x+9,y+7); printf("%c",s);}}
    
    cmd=getch(); // Captura tecla pressionada. 

    if(cmd=='d'||cmd=='D'){ if(p<8){p++;}} //Se tecla pressionada for igual a d ou D e posição menor que 8, então posição++.
    if(cmd=='a'||cmd=='A'){ if(p>0){p--;}} //Se tecla pressionada for igual a a ou A e posição maior que 0, então posição--.
    if(cmd=='w'||cmd=='W'){ if(p>2){p=p-3;}} //Se tecla pressionada for igual a w ou W e posição menor que 2, então posição=posição-3.
    if(cmd=='s'||cmd=='S'){ if(p<6){p=p+3;}} //Se tecla pressionada for igual a s ou S e posição menor que 6, então posição=posição+3.
    
    if(cmd=='k'||cmd=='K'){  mudsimb(p); } //Se tecla pressionada for igual a k ou K então Significa que o usuário confirmou sua jogada, então chama a função mudsimb.
    if(cmd=='n'||cmd=='N'){sai=1;}  //Se tecla pressionada for igual a n ou N então a função retorna 1 ENTÃO(volta para o menu).          
    
    return sai;
      }
int verifempat(){ // Verifica se houve um empate.
     int x,y,v=0; 
     for(x=0;x<3;x++){for(y=0;y<3;y++){ if(mt[x][y]!=' '){v++;}}} 
     if(v==9){return 1; }else{ return 0;}}
     
// Especial Modo fight game.
void esCampFigh(int x, int y){
     char s1=205,s2=186,s3=187,s4=201,ss=184;
     textcolor(2);
     gotoxy(x-8,y+10); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s4,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s3);
     gotoxy(x-8,y+11); printf("%c                           %c   ",s2,s2);
     gotoxy(x-8,y+12); printf("%c                           %c   ",s2,s2);
     gotoxy(x-8,y+13); printf("%c                           %c   ",s2,s2);
     gotoxy(x-8,y+14); printf("%c                           %c   ",s2,s2);
     
     textcolor(3); gotoxy(2,2); printf("Modo:");
     textcolor(8);if(mod==0){ gotoxy(8,2); printf(" Easy");}
     textcolor(9);if(mod==1){ gotoxy(8,2); printf(" Medium");}
     textcolor(10);if(mod==2){ gotoxy(8,2); printf(" Hard");}
     textcolor(11);if(mod==3){ gotoxy(8,2); printf(" Impossible");}
     textcolor(4);if(mod==4){ gotoxy(8,2); printf(" Fight");}
     
     textcolor(3);
     gotoxy(60,2); printf("User  :  %d",vlgx);
     gotoxy(60,3); printf("Pc    :  %d",vlgy);
     }
void intrFight(int x,int y){ // Introdução do jogo no Modo Fight.
     char s1=205,s2=186,s3=187,s4=201,s='+',ss=184;
     int temp=70,px=2,py=6,c,c1=3,c2=6,x1=35,y1=14,x2=39,y2=14;
     for(c=0;c<3;c++){
     textcolor(2);
     gotoxy(x-8,y+10); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s4,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s3);
     gotoxy(x-8,y+11); printf("%c                           %c   ",s2,s2);gotoxy(x-8,y+12); printf("%c                           %c   ",s2,s2);
     gotoxy(x-8,y+13); printf("%c                           %c   ",s2,s2);gotoxy(x-8,y+14); printf("%c                           %c   ",s2,s2);
     // variáveis tics.
     textcolor(c1);gotoxy(x+5,y+7+c); printf("%c",us);
     textcolor(c2);gotoxy(x+9,y+7+c); printf("%c",pc);
     Sleep(80);clrscr();}
     // Apartir daqui vou trabalhar com x1x2 e y1y2.
for(c=0;c<7;c++){
         if(c<3){x1--;y1--;x2++;y2--;}
         if(c==3){x1--;x2++;}
         if(c>3){y1++;x1--;x2++;y2++;}             
textcolor(c1);gotoxy(x1,y1); printf("%c",us);textcolor(c2);gotoxy(x2,y2); printf("%c",pc);
sleep(60);clrscr();textcolor(2);
gotoxy(x-8,y+10); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",s4,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s3);
gotoxy(x-8,y+11); printf("%c                           %c   ",s2,s2);gotoxy(x-8,y+12); printf("%c                           %c   ",s2,s2);gotoxy(x-8,y+13); printf("%c                           %c   ",s2,s2);
gotoxy(x-8,y+14); printf("%c                           %c   ",s2,s2);
}
 textcolor(c1);gotoxy(x1,y1); printf("%c",us);textcolor(c2);gotoxy(x2,y2); printf("%c",pc);
 textcolor(4);gotoxy(33,7);printf("F");Sleep(30);
 gotoxy(34,7);printf("i");Sleep(30);gotoxy(35,7);printf("g");Sleep(30);gotoxy(36,7);printf("h");Sleep(30);gotoxy(37,7);printf("t");Sleep(30);
 gotoxy(38,7);printf(" ");Sleep(30);gotoxy(39,7);printf("!!");Sleep(80);gotoxy(32,7);printf("                                   ");
     //end
     }
void AIpc(){ //Inteligência artificial da máquina.
     int c1=3,c2=6,v=0;
    
    if(scx>4){if(px1+1==px2 ||px1==px2){gotoxy(px1,px2);printf("-}");if(py1==py2){ px1=px1-3;} Sleep(30);} }
    if(scx>5){v=1;} if(v==1){if(px2>23){px2--;}Sleep(30);mv=1;v++;}
    if(scx>6){ if(px1<px2){ if(px2>23){px2--;}}
    if(px1>px2){px2++;}
     Sleep(50);mv=1;}
    if(ct>1 && ct<10){px2--; Sleep(10); mv=1;}            
     if(ct>9000){ct=0;}
     }     
void figth(int x, int y){ // Nessa função ocorre o game de luta.
     scx=0;ct=0;
     char s1=205,s2=186,s3=187,s4=201,s='+',ss=184,cmd,cmd1;
     int temp=70,px=2,py=6,c,c1=3,c2=6,x1=28,y1=14,x2=46,y2=14,lx=0;
     clrscr();intrFight(30,5);
     px1=x1;py1=y1;px2=x2;py2=y2;
     
     while(1){ 
     textcolor(c1);gotoxy(px1,py1); printf("%c",us);
     textcolor(c2);gotoxy(px2,py2); printf("%c",pc);

      esCampFigh(30,5);
      
      if(kbhit()){
     cmd=getch(); mv=1;
      if(kbhit()){cmd1=getch();
      if(cmd1=='k'){at=6;}}
     }
     if(cmd=='d'){px1++;lx=0;}
     if(cmd=='a'){px1--;lx=1;}
     if(cmd=='w'){
        for(c=0;c<7;c++){
          if(c<3){py1--;}               
          if(c==3){}
          if(c>3){py1++;}
          AIpc();
          textcolor(c1);gotoxy(px1,py1); printf("%c",us);
          textcolor(c2);gotoxy(px2,py2); printf("%c",pc);
          Sleep(30);clrscr(); esCampFigh(30,5);              
                         }}
     if(cmd=='s'){gotoxy(px1,py1);printf("_");Sleep(15);}
     if(cmd=='k'){
                 if(lx==0){gotoxy(px1+1,py1);printf("-)");sleep(20);if(px2==px1+2){px2++;scx++;}if(px2==px1+1){px2=px2+at;at=4;scx++;}}
                 if(lx==1){gotoxy(px1-2,py1);printf("(-");sleep(20);if(px2+2==px1){px2--;scx++;}if(px2+1==px1){px2=px2-4;scx++;}}
                  }
     // Verifica se lutadores caíram.
     if(px1<=21 && py1==14 || px1>=51 && py1==14 ){
                for(c=0;c<5;c++){py1++;  
     textcolor(c1);gotoxy(px1,py1); printf("%c",us);
     textcolor(c2);gotoxy(px2,py2); printf("%c",pc);
                esCampFigh(30,5);Sleep(100);clrscr();}
                textcolor(4);gotoxy(30,15);printf("You Lose !!!");Sleep(300);getch();break;
                }
      if(px2<=21 && py2==14 || px2>=51 && py2==14 ){
                for(c=0;c<5;c++){py2++;  
     textcolor(c1);gotoxy(px1,py1); printf("%c",us);
     textcolor(c2);gotoxy(px2,py2); printf("%c",pc);
                esCampFigh(30,5);Sleep(100);clrscr();}
                textcolor(5);gotoxy(30,15);printf("You Win !!!");Sleep(300);getch();break;
                } 
     ct++;// Contador.
     if(ct==500){textcolor(1);gotoxy(px2,py2-1);printf("?");} //se tempo for maior que 500 então mostra uma interrogação na cabeça do bolinha.          
     AIpc();                   
     if(mv==1){clrscr();mv=0;cmd='0';}
     }
}// Fim modo fight game.     
               
void game(){ //O game inteiro roda nessa função.
     
     int c,i;
     char cmd;
while(1){ 
// Zera as variáveis para um novo jogo.
p=0;lug=0;lug1=0;vl1=0;vl2=0;jgd=0;jg2=0;gx=0;gy=0,jg=1;
// Atribuí espaço a todas posições da matriz principal.          
     for(c=0;c<3;c++){
       for(i=0;i<3;i++){               
       mt[c][i]=' ';               
     }}
     
    if(beginJg==0){ //Define quem começa o jogo, Se beginJg for igual a zero então usuário começa a jogar.
    while(jgd<9){   //Loop até 9, pois o jogo só pode ter 9 jogadas.                 
     estrut(30,5);  //Mostra a interface do jogo.
     if(gx>0 || gy>0){break;} //Se X ou O ganhar o loop é finalizado.
     if(wwin()==1){break;}    //Se X ou O ganhar o loop é finalizado.
     if(verifempat()>0){emp++; gotoxy(32,15); printf("Empate"); break; } //Se empatar o loop e finalizado.
     if(esclug(30,5)==1){break;}}
     if(mod==4){figth(30,5); break;}}//Se modo fight estiver setado, então entra nessa condição.
     
     if(beginJg==1){ //Se beginJg for igual a um então maquina começa a jogar.
    while(jgd<9){ 
     if(jg==1){maquina();jg=0;}                 
     estrut(30,5);
     if(gx>0 || gy>0){break;}
     if(wwin()==1){break;}
      
     if(verifempat()>0){emp++; gotoxy(32,15); printf("Empate"); break; }
     if(esclug(30,5)==1){break;}
     }}
     
     //Atualiza a interface.
     estrut(30,5);
     textcolor(8); gotoxy(27,20);printf("Deseja sair [Y][N]");
     cmd=getch();
     clrscr();textcolor(8);
     if(cmd=='y'||cmd=='Y'){
      if(mod==2){ if(vlgy==0){ 
     if(vlgx>2&&vlgx<5){      gotoxy(10,14);printf("New Record! Nome:");gotoxy(29,14);gets(nom); poss=4; pt=vlgx;}
     if(vlgx>4&&vlgx<6){      gotoxy(10,14);printf("New Record! Nome:");gotoxy(29,14);gets(nom); poss=3; pt=vlgx;}
     if(vlgx>5&&vlgx<9){      gotoxy(10,14);printf("New Record! Nome:");gotoxy(29,14);gets(nom); poss=2; pt=vlgx;}
     if(vlgx>8){              gotoxy(10,14);printf("New Record! Nome:");gotoxy(29,14);gets(nom); poss=1; pt=vlgx;}     
     }}                
     break;}
     }
}     
     
int menu(){ //Mostra o menu na tela.
  clrscr();
  char cmd; 
  int op1=0,m[6]={0,0,0,0,0,0};
     while(1){
    clrscr();
     textcolor(6);gotoxy(30,2);printf("Jogo da Velha #");
     gotoxy(30,4);printf("[ ]");gotoxy(34,4);printf("User Vs Pc");
     gotoxy(30,5);printf("[ ]");gotoxy(34,5);printf("Ranking ");
     gotoxy(30,6);printf("[ ]");gotoxy(34,6);printf("Configuracao");
     gotoxy(30,7);printf("[ ]");gotoxy(34,7);printf("Sair");
     textcolor(7);
     gotoxy(28,15);printf(" W   S --> Movimentar");
     gotoxy(28,16);printf("   K  ---> Enter");
     textcolor(9); 
     if(op1==0){gotoxy(31,4);printf("X");}
     if(op1==1){gotoxy(31,5);printf("X");}
     if(op1==2){gotoxy(31,6);printf("X");}
     if(op1==3){gotoxy(31,7);printf("X");}
    

     cmd=getch();
     
     if(cmd=='s'||cmd=='S'){if(op1<3){ op1++; }}
     if(cmd=='w'||cmd=='W'){if(op1>0){ op1--; }}
     if(cmd=='k'||cmd=='K'){break;}
     
     }
     return op1;
     }
void config(){//Mostra menu de configurações.
  char cmd,a=219; 

     while(1){
     textcolor(10);
     gotoxy(30,2);printf("Jogo da Velha");
     gotoxy(30,4);printf("[ ] Easy");
     gotoxy(30,5);printf("[ ] Medium");
     gotoxy(30,6);printf("[ ] Hard");
     gotoxy(30,7);printf("[ ] Impossible");
    textcolor(4); gotoxy(30,8);printf("[ ] (--Fight--)");textcolor(10);
     gotoxy(30,9);printf("[ ] [ ]X - [ ]O");
     textcolor(7);
     gotoxy(28,15);printf(" W   S --> Movimentar");
     gotoxy(28,16);printf(" K ------> Enter");
     textcolor(10);     
     if(op==0){gotoxy(31,4);printf("X");mod=0; }
     if(op==1){gotoxy(31,5);printf("X");mod=1; }
     if(op==2){gotoxy(31,6);printf("X");mod=2; }
     if(op==3){gotoxy(31,7);printf("X");mod=3; }
     if(op==4){gotoxy(31,8);printf("X");mod=4; }
     if(op==5){gotoxy(31,9);printf("X");}textcolor(2);
     if(op1==0){gotoxy(35,9);printf("%c",a);us='X';pc='O';}
     if(op1==1){gotoxy(42,9);printf("%c",a);us='O';pc='X';}
     cmd=getch();
     textcolor(10);

     if(cmd=='s'||cmd=='S'){if(op<5){ op++; }}
     if(cmd=='w'||cmd=='W'){if(op>0){ op--; }}
     if(cmd=='d'||cmd=='D'){if(op==5){ if(op1<1){ op1++; }}}
     if(cmd=='a'||cmd=='A'){if(op==5){ if(op1>0){ op1--; }}}
     if(cmd=='k'||cmd=='K'){break;}
   }}
     
void rank(){ //Calcula e Mostra o Ranking.
  int c,i,a[5]={0,0,0,0,0};  
  //Calcula a posição do usuário.
  if(poss==6){a[5]=6;a[4]=5;a[3]=4;a[2]=3;a[1]=2;a[0]=1;}
  if(poss==5){a[5]=5;a[4]=6;a[3]=4;a[2]=3;a[1]=2;a[0]=1;}
  if(poss==4){a[5]=4;a[4]=6;a[3]=5;a[2]=3;a[1]=2;a[0]=1;}
  if(poss==3){a[5]=3;a[4]=6;a[3]=5;a[2]=4;a[1]=2;a[0]=1;}
  if(poss==2){a[5]=2;a[4]=6;a[3]=5;a[2]=4;a[1]=3;a[0]=1;}
  if(poss==1){a[5]=1;a[4]=6;a[3]=5;a[2]=4;a[1]=3;a[0]=2;}
  //Mostra a tabela do Ranking.  
     clrscr();textcolor(8);
     gotoxy(30,2); printf("-- Ranking Modo Hard --");
     
textcolor(7);gotoxy(25,4); printf("Lugar   Nome            Partidas");
             gotoxy(25,5); printf("================================");
             textcolor(2); 
gotoxy(25,6); printf("1ª");gotoxy(33,5+a[0]);printf("Daniel");gotoxy(50,5+a[0]);printf("8/0");
gotoxy(25,7); printf("2ª");gotoxy(33,5+a[1]);printf("Lucas");gotoxy(50,5+a[1]);printf("5/0");
gotoxy(25,8); printf("3ª");gotoxy(33,5+a[2]);printf("Jerry");gotoxy(50,5+a[2]);printf("4/0");
gotoxy(25,9); printf("4ª");gotoxy(33,5+a[3]);printf("Michael");gotoxy(50,5+a[3]);printf("2/0");
gotoxy(25,10); printf("5ª");gotoxy(33,5+a[4]);printf("Leonardo");gotoxy(50,5+a[4]);printf("2/1");
gotoxy(25,11); printf("6ª");textcolor(8);gotoxy(33,5+a[5]);printf("%s",nom);gotoxy(50,5+a[5]);printf("%d/0",pt);
           
     getch();
}             
void intr(){//Mostra a introdução do jogo.
     int c=-8,ii=2,temp=100,n=219;
     char j=n,q=n,w=n,k=n,l=n,i=n;
    textcolor(3);  
    textcolor(6);Sleep(temp);
gotoxy(10+c,10);printf("   %c%c%c",j,j,j);gotoxy(10+c,11);printf("   %c%c%c",j,j,j);gotoxy(10+c,12);printf("   %c%c%c",j,j,j);gotoxy(10+c,13);printf("   %c%c%c",j,j,j);
gotoxy(10+c,14);printf("   %c%c%c",j,j,j);gotoxy(10+c,15);printf("   %c%c%c",j,j,j);gotoxy(10+c,16);printf("%c%c%c%c%c%c",j,j,j,j,j,j);gotoxy(10+c,17);printf("%c%c%c%c%c%c",j,j,j,j,j,j);Sleep(temp);
gotoxy(17+c,10); printf("%c%c%c%c%c%c",q,q,q,q,q,q);gotoxy(17+c,11); printf("%c%c%c%c%c%c",q,q,q,q,q,q);gotoxy(17+c,12); printf("%c%c  %c%c",q,q,q,q);gotoxy(17+c,13); printf("%c%c  %c%c",q,q,q,q);
gotoxy(17+c,14); printf("%c%c  %c%c",q,q,q,q);gotoxy(17+c,15); printf("%c%c  %c%c",q,q,q,q);gotoxy(17+c,16); printf("%c%c%c%c%c%c",q,q,q,q,q,q);gotoxy(17+c,17); printf("%c%c%c%c%c%c",q,q,q,q,q,q);Sleep(temp);
gotoxy(24+c,10); printf("%c%c%c%c%c%c",w,w,w,w,w,w);gotoxy(24+c,11); printf("%c%c%c%c%c%c",w,w,w,w,w,w);gotoxy(24+c,12); printf("%c%c  %c%c",w,w,w,w);gotoxy(24+c,13); printf("%c%c  %c%c",w,w,w,w);
gotoxy(24+c,14); printf("%c%c    ",w,w);gotoxy(24+c,15); printf("%c%c %c%c%c",w,w,w,w);gotoxy(24+c,16); printf("%c%c  %c%c",w,w,w,w);gotoxy(24+c,17); printf("%c%c%c%c%c%c",w,w,w,w,w,w);Sleep(temp);
gotoxy(31+c,10); printf("%c%c%c%c%c%c",k,k,k,k,k,k);gotoxy(31+c,11); printf("%c%c%c%c%c%c",k,k,k,k,k,k);gotoxy(31+c,12); printf("%c%c  %c%c",k,k,k,k);gotoxy(31+c,13); printf("%c%c  %c%c",k,k,k,k);
gotoxy(31+c,14); printf("%c%c  %c%c",k,k,k,k);gotoxy(31+c,15); printf("%c%c  %c%c",k,k,k,k);gotoxy(31+c,16); printf("%c%c%c%c%c%c",k,k,k,k,k,k);gotoxy(31+c,17); printf("%c%c%c%c%c%c",k,k,k,k,k,k);Sleep(temp);textcolor(2);
gotoxy(39+c,10); printf("%c%c%c%c%c%c",l,l,l,l,l,l);gotoxy(39+c,11); printf("%c%c%c%c%c%c",l,l,l,l,l,l);gotoxy(39+c,12); printf(" %c  %c%c",l,l,l);gotoxy(39+c,13); printf(" %c  %c%c",l,l,l);
gotoxy(39+c,14); printf(" %c  %c%c",l,l,l);gotoxy(39+c,15); printf(" %c  %c%c",l,l,l);gotoxy(39+c,16); printf("%c%c%c%c%c%c",l,l,l,l,l,l);gotoxy(39+c,17); printf("%c%c%c%c%c%c",l,l,l,l,l,l);Sleep(temp);
gotoxy(46+c,10); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(46+c,11); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(46+c,12); printf("%c%c  %c%c",i,i,i,i);gotoxy(46+c,13); printf("%c%c  %c%c",i,i,i,i);
gotoxy(46+c,14); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(46+c,15); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(46+c,16); printf("%c%c  %c%c",i,i,i,i);gotoxy(46+c,17); printf("%c%c  %c%c",i,i,i,i);Sleep(temp);textcolor(6);
gotoxy(52+c+ii,10); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii,11); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii,12); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii,13); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii,14); printf("%c%c  %c%c",l,l,l,l);
gotoxy(52+c+ii,15); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii,16); printf(" %c%c%c%c ",l,l,l,l);gotoxy(52+c+ii,17); printf("  %c%c%  ",l,l,l,l);Sleep(temp);
gotoxy(59+c+ii,10); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii,11); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii,12); printf("%c%c%c   ",i,i,i);gotoxy(59+c+ii,13); printf("%c%c%c%c%c%c",i,i,i,i,i,i);
gotoxy(59+c+ii,14); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii,15); printf("%c%c%c   ",i,i,i);gotoxy(59+c+ii,16); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii,17); printf("%c%c%c%c%c%c",i,i,i,i,i,i);Sleep(temp);
gotoxy(66+c+ii,10); printf("%c%c    ",i,i);gotoxy(66+c+ii,11); printf("%c%c    ",i,i);gotoxy(66+c+ii,12); printf("%c%c    ",i,i);gotoxy(66+c+ii,13); printf("%c%c    ",i,i);
gotoxy(66+c+ii,14); printf("%c%c    ",i,i);gotoxy(66+c+ii,15); printf("%c%c    ",i,i);gotoxy(66+c+ii,16); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(66+c+ii,17); printf("%c%c%c%c%c%c",i,i,i,i,i,i);Sleep(temp);
gotoxy(73+c+ii,10); printf("%c%c  %c%c",i,i,i,i);gotoxy(73+c+ii,11); printf("%c%c  %c%c",i,i,i,i);gotoxy(73+c+ii,12); printf("%c%c  %c%c",i,i,i,i);gotoxy(73+c+ii,13); printf("%c%c%c%c%c%c",i,i,i,i,i,i);
gotoxy(73+c+ii,14); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(73+c+ii,15); printf("%c%c  %c%c",i,i,i,i);gotoxy(73+c+ii,16); printf("%c%c  %c%c",i,i,i,i);gotoxy(73+c+ii,17); printf("%c%c  %c%c",i,i,i,i); Sleep(temp);
gotoxy(80+c+ii,10); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(80+c+ii,11); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(80+c+ii,12); printf("%c%c  %c%c",i,i,i,i);gotoxy(80+c+ii,13); printf("%c%c  %c%c",i,i,i,i);gotoxy(80+c+ii,14); printf("%c%c%c%c%c%c",i,i,i,i,i,i);
gotoxy(80+c+ii,15); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(80+c+ii,16); printf("%c%c  %c%c",i,i,i,i);gotoxy(80+c+ii,17); printf("%c%c  %c%c",i,i,i,i);

     gotoxy(35,20);printf("Pressione K");
     getch();
     //Animação
     clrscr();
     int a,b,c3=1,lets=1,tim=0;
     for(a=0;a<40;a++){
       if(a<9){lets=1;}
       if((a>8)&&(a<18)){lets=2;}
       if((a>17)&&(a<25)){lets=3;}     
       if((a>24)&&(a<30)){lets=4;}

    textcolor(6);
if(lets<5){
gotoxy(10+c+a,10); printf("   %c%c%c",j,j,j);gotoxy(10+c+a,11); printf("   %c%c%c",j,j,j);gotoxy(10+c+a,12); printf("   %c%c%c",j,j,j);gotoxy(10+c+a,13); printf("   %c%c%c",j,j,j);
gotoxy(10+c+a,14); printf("   %c%c%c",j,j,j);gotoxy(10+c+a,15); printf("   %c%c%c",j,j,j);gotoxy(10+c+a,16); printf("%c%c%c%c%c%c",j,j,j,j,j,j);gotoxy(10+c+a,17); printf("%c%c%c%c%c%c",j,j,j,j,j,j);
}
 if(lets<4){   
gotoxy(17+c+a,10); printf("%c%c%c%c%c%c",q,q,q,q,q,q);gotoxy(17+c+a,11);printf("%c%c%c%c%c%c",q,q,q,q,q,q);gotoxy(17+c+a,12); printf("%c%c  %c%c",q,q,q,q);
gotoxy(17+c+a,13); printf("%c%c  %c%c",q,q,q,q);gotoxy(17+c+a,14); printf("%c%c  %c%c",q,q,q,q);gotoxy(17+c+a,15); printf("%c%c  %c%c",q,q,q,q);
gotoxy(17+c+a,16); printf("%c%c%c%c%c%c",q,q,q,q,q,q);gotoxy(17+c+a,17);printf("%c%c%c%c%c%c",q,q,q,q,q,q);}
 if(lets<3){   
gotoxy(24+c+a,10); printf("%c%c%c%c%c%c",w,w,w,w,w,w);gotoxy(24+c+a,11); printf("%c%c%c%c%c%c",w,w,w,w,w,w);gotoxy(24+c+a,12); printf("%c%c  %c%c",w,w,w,w);
gotoxy(24+c+a,13); printf("%c%c  %c%c",w,w,w,w);gotoxy(24+c+a,14); printf("%c%c    ",w,w);gotoxy(24+c+a,15); printf("%c%c %c%c%c",w,w,w,w);
gotoxy(24+c+a,16); printf("%c%c  %c%c",w,w,w,w);gotoxy(24+c+a,17); printf("%c%c%c%c%c%c",w,w,w,w,w,w);
}
if(lets==1){
gotoxy(31+c+a,10); printf("%c%c%c%c%c%c",k,k,k,k,k,k);gotoxy(31+c+a,11); printf("%c%c%c%c%c%c",k,k,k,k,k,k);gotoxy(31+c+a,12); printf("%c%c  %c%c",k,k,k,k);
gotoxy(31+c+a,13); printf("%c%c  %c%c",k,k,k,k);gotoxy(31+c+a,14); printf("%c%c  %c%c",k,k,k,k);gotoxy(31+c+a,15); printf("%c%c  %c%c",k,k,k,k);gotoxy(31+c+a,16); printf("%c%c%c%c%c%c",k,k,k,k,k,k);
gotoxy(31+c+a,17); printf("%c%c%c%c%c%c",k,k,k,k,k,k);
}   
if(lets==5){ 
sleep(100);
    textcolor(2);
gotoxy(39+c-a,10); printf("%c%c%c%c%c%c",l,l,l,l,l,l);gotoxy(39+c-a,11); printf("%c%c%c%c%c%c",l,l,l,l,l,l);gotoxy(39+c-a,12); printf(" %c  %c%c",l,l,l);
gotoxy(39+c-a,13); printf(" %c  %c%c",l,l,l);gotoxy(39+c-a,14); printf(" %c  %c%c",l,l,l);gotoxy(39+c-a,15); printf(" %c  %c%c",l,l,l);
gotoxy(39+c-a,16); printf("%c%c%c%c%c%c",l,l,l,l,l,l);gotoxy(39+c-a,17); printf("%c%c%c%c%c%c",l,l,l,l,l,l);
gotoxy(46+c+a,10); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(46+c+a,11); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(46+c+a,12); printf("%c%c  %c%c",i,i,i,i);
gotoxy(46+c+a,13); printf("%c%c  %c%c",i,i,i,i);gotoxy(46+c+a,14); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(46+c+a,15); printf("%c%c%c%c%c%c",i,i,i,i,i,i);
gotoxy(46+c+a,16); printf("%c%c  %c%c",i,i,i,i);gotoxy(46+c+a,17); printf("%c%c  %c%c",i,i,i,i);textcolor(6);
}
if(lets==1){
gotoxy(52+c+ii-a,10); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii-a,11); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii-a,12); printf("%c%c  %c%c",l,l,l,l);
gotoxy(52+c+ii-a,13); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii-a,14); printf("%c%c  %c%c",l,l,l,l);gotoxy(52+c+ii-a,15); printf("%c%c  %c%c",l,l,l,l);
gotoxy(52+c+ii-a,16); printf(" %c%c%c%c ",l,l,l,l);gotoxy(52+c+ii-a,17); printf("  %c%c%  ",l,l,l,l);
}
if(lets<3){    
gotoxy(59+c+ii-a,10); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii-a,11); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii-a,12); printf("%c%c%c   ",i,i,i);
gotoxy(59+c+ii-a,13); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii-a,14); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii-a,15); printf("%c%c%c   ",i,i,i);
gotoxy(59+c+ii-a,16); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(59+c+ii-a,17); printf("%c%c%c%c%c%c",i,i,i,i,i,i);
}
if(lets<4){    
gotoxy(66+c+ii-a,10); printf("%c%c    ",i,i);gotoxy(66+c+ii-a,11); printf("%c%c    ",i,i);gotoxy(66+c+ii-a,12); printf("%c%c    ",i,i);
gotoxy(66+c+ii-a,13); printf("%c%c    ",i,i);gotoxy(66+c+ii-a,14); printf("%c%c    ",i,i);gotoxy(66+c+ii-a,15); printf("%c%c    ",i,i);
gotoxy(66+c+ii-a,16); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(66+c+ii-a,17); printf("%c%c%c%c%c%c",i,i,i,i,i,i);
}
if(lets<5){    
gotoxy(73+c+ii-a,10); printf("%c%c  %c%c",i,i,i,i);gotoxy(73+c+ii-a,11); printf("%c%c  %c%c",i,i,i,i);gotoxy(73+c+ii-a,12); printf("%c%c  %c%c",i,i,i,i);
gotoxy(73+c+ii-a,13); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(73+c+ii-a,14); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(73+c+ii-a,15); printf("%c%c  %c%c",i,i,i,i);
gotoxy(73+c+ii-a,16); printf("%c%c  %c%c",i,i,i,i);gotoxy(73+c+ii-a,17); printf("%c%c  %c%c",i,i,i,i); 
}
if(lets<6){    
gotoxy(80+c+ii-a,10); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(80+c+ii-a,11); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(80+c+ii-a,12); printf("%c%c  %c%c",i,i,i,i);
gotoxy(80+c+ii-a,13); printf("%c%c  %c%c",i,i,i,i);gotoxy(80+c+ii-a,14); printf("%c%c%c%c%c%c",i,i,i,i,i,i);gotoxy(80+c+ii-a,15); printf("%c%c%c%c%c%c",i,i,i,i,i,i);
gotoxy(80+c+ii-a,16); printf("%c%c  %c%c",i,i,i,i);gotoxy(80+c+ii-a,17); printf("%c%c  %c%c",i,i,i,i);
}
clrscr();}clrscr();}
void developers(){
     gotoxy(20,2);printf("Trabalho Programacao Estruturada II");Sleep(100);
     gotoxy(20,6);printf("Daniel Ferreira Santiago RA: 6451327159");Sleep(100);
     gotoxy(20,7);printf("Ricardo Alves Teixeira   RA: 6814004062");Sleep(100);
     gotoxy(20,8);printf("Renan Moreira dos Santos RA: 6654394808 ");Sleep(100);
     gotoxy(20,11);printf("Professor");Sleep(100);
     gotoxy(20,12);printf("     Michel Fontana");Sleep(100);
     getch();
     }        
main(){ //Principal
       system("color A");
       system("title Jogo da Velha");
       
       developers();clrscr();  //Apresentação do trabalho
       intr(); //Mostra a animação 
int op,ani;
while(1){ //Loop infinito até o jogado escolher sair
vlgx=0;vlgy=0,emp=0,beginJg=0;
       op=menu(); // Chama a função menu que retornará a opção escolhida pelo usuário.  
       clrscr();  
       if(op==0){game();} //Se opção for igual a 0 entra no jogo
             if(op==1){rank();} //Se opção for igual a 1 entra no ranking
                if(op==2){config();}//Se opção for igual a 2 entra em configuração
                     if(op==3){ //Se opção for igual a 3 então mostra uma pequena animação e fecha o jogo.
                               
                       for(ani=0;ani<25;ani++){        
                        gotoxy(35,1+ani);       
                        printf("Finish the game!");Sleep(100);clrscr();}
                               return 0;}
                     }
       system("pause>>null");  
}
//the end.
