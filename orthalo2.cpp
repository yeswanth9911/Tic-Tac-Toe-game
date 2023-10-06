#include<simplecpp>
void horizontal(int **a,int i,int j,int k,int &steps,int player);
void vertical(int **a,int i,int j,int k,int &steps,int player);
void cross_increasing(int **a,int i,int j,int k,int &steps,int player);
void cross_decreasing(int **a,int i,int j,int k,int &steps,int player);
void colourbox(int **a,int i,int j,int k);
void changecolour(int **a,int i,int j,int k,int &steps,int player);

void colourbox(int **a,int i,int j,int k){//colouring the box and for white a[i][j]=2 and for black is 1;
 Circle c(50*i+25,50*j+25,20);
 if(k%2==0) c.setColor(COLOR("black"));
 if(k%2==1) c.setColor(COLOR("white"));
 c.setFill();
 c.imprint();
 a[i][j]=(k%2)+1;
 }

 void bestfitbox(int **a,int &i,int &j,int steps){
   int best=-1,curr=0;
   for(int q=1;q<9;q++){
    steps=0;
     for(int w=1;w<9;w++){
      if(a[q][w]==0){
         changecolour(a,q,w,2,steps,1);
         curr=steps;
     if(curr>best){
     best=curr;i=q;j=w;}
    } }}
 }
 void changecolour(int **a,int i,int j,int k,int &steps,int player){//changing the middle boxes
   horizontal(a,i,j,k,steps,player);
   vertical(a,i,j,k,steps,player);
   cross_increasing(a,i,j,k,steps,player);
   cross_decreasing(a,i,j,k,steps,player);
 }
 void horizontal(int **a,int i,int j,int k,int &steps,int player){//changing the horizontal row
   bool q=0;
   int w=i;
   int p=i+1;
   for(;p!=9;p++){
      if( a[i+1][j]==(k%2)+1  || a[p][j]==0 ) break;
      if(a[p][j]==(k%2)+1) {q=1;break;}
   }
   if(q==1) {
   repeat(p-i-1){steps++;if(player==2 )colourbox(a,++i,j,k);}}
   i=w;
   bool r=0;
   int s=i-1;
   for(;s!=0;s--){
      if( a[i-1][j]==(k%2)+1  || a[s][j]==0 ) break;
      if( a[s][j]==(k%2)+1) {r=1;break;}
   }
   if(r==1) {
   repeat(i-s-1){ steps++;if(player==2 )colourbox(a,--i,j,k);}}
   }

 void vertical(int **a,int i,int j,int k,int &steps,int player){//changing the vertical row
   bool q=0;
   int w=j;
   int p=j+1;
   for(;p!=9;p++){
      if( a[i][j+1]==(k%2)+1  || a[i][p]==0 ) break;
      if(a[i][p]==(k%2)+1) {q=1;break;}
   }
   if(q==1) {
   repeat(p-j-1){steps++;if(player==2 )colourbox(a,i,++j,k);}}
   j=w;
   bool r=0;
   int s=j-1;
   for(;s!=0;s--){
      if( a[i][j-1]==(k%2)+1  || a[i][s]==0 ) break;
      if( a[i][s]==(k%2)+1) {r=1;break;}
   }
   if(r==1) {
   repeat(j-s-1){ steps++;if(player==2 )colourbox(a,i,--j,k);}}
   }

 void cross_increasing(int **a,int i,int j,int k,int &steps,int player){//changing the y=x like curve;
   bool q=0;
   int w=i,e=j;
   int p=i+1,u=j+1;
   for(;p!=9 && u!=9;p++,u++){
      if( a[i+1][j+1]==(k%2)+1  || a[p][u]==0 ) break;
      if(a[p][u]==(k%2)+1) {q=1;break;}
   }
   if(q==1) {
   repeat(p-i-1){ steps++;if(player==2 )colourbox(a,++i,++j,k);}}
   i=w;j=e;
   bool r=0;
   int s=i-1,v=j-1;
   for(;s!=0 && v!=0;s--,v--){
      if( a[i-1][j-1]==(k%2)+1  || a[s][v]==0 ) break;
      if( a[s][v]==(k%2)+1) {r=1;break;}
   }
   if(r==1) {
   repeat(i-s-1){steps++;if(player==2 )colourbox(a,--i,--j,k);}}
   }

   void cross_decreasing(int **a,int i,int j,int k,int &steps,int player){//changing the x+y=0 like curve;
   bool q=0;
   int w=i,e=j;
   int p=i+1,u=j-1;
   for(;p!=9 && u!=0;p++,u--){
      if( a[i+1][j-1]==(k%2)+1  || a[p][u]==0 ) break;
      if(a[p][u]==(k%2)+1) {q=1;break;}
   }
   if(q==1) {
   repeat(p-i-1){steps++;if(player==2 )colourbox(a,++i,--j,k);}}
   i=w;j=e;
   bool r=0;
   int s=i-1,v=j+1;
   for(;s!=0 && v!=9;s--,v++){
      if( a[i-1][j+1]==(k%2)+1  || a[s][v]==0 ) break;
      if( a[s][v]==(k%2)+1) {r=1;break;}
   }
   if(r==1) {
   repeat(i-s-1){steps++;if(player==2 )colourbox(a,--i,++j,k);}}
   }

   void declare(int k,int a,int b,int steps){//declaring win at the final stage
     if(k==60){
     if (a>b) cout <<"White Won";
      else if(b>a) cout<<"Black Won";
      else cout<<"Draw";
   }
   if(a==0) cout<<"Blacks Won";
   if(b==0) cout<<"Whites Won";
   if(steps==0){
     if(k%2==0) cout<<"White Won";
     if(k%2==1) cout<<"Black Won";
   }
   }
  int countwhite(int **a){//counting number of whites
   int k=0;
   for(int i=1;i<9;i++){
    for(int j=1;j<9;j++){
    if(a[i][j]==2) k++;}}
   return k;
}

  int countblack(int **a){//counting number of whites
   int k=0;
   for(int i=1;i<9;i++){
    for(int j=1;j<9;j++){
    if(a[i][j]==1) k++;}}
   return k;
}
void clickbox(int **a,bool &flag,int player){//seecting the box with mouse and drawing a circle it
 static int k=0;
 int steps=0;
 int j,i;
 if((player==1 && k%2==0) || player==2){
 int cPos = getClick();
 double x = floor(cPos/65536);
 double y = floor(cPos%65536);
 x=floor(x/50)*50;
 y=floor(y/50)*50;
 i=x/50;j=y/50;
 if(a[i][j]!=0) return;}
 if(player==1 && k%2==1){wait(1);bestfitbox(a,i,j,steps);}
 k++;
 if(k%2==1) cout<<"white"<<"    "<<i<<"    "<<j<<endl;
 else cout<<"Black"<<"    "<<i<<"    "<<j<<endl;
 colourbox(a,i,j,k);
 changecolour(a,i,j,k,steps,2);
 int u=countwhite(a);
 int v=countblack(a);
 if(k==60 || u==0|| v==0 || steps==0) {declare(k,u,v,steps);flag=1;}
 }

void drawbox(){//drawing the box and four circles
 Rectangle r(250,250,500,500);
 r.setColor(COLOR("green"));
 r.setFill();
 r.imprint();
 for(int i=0;i<9;i++){
    Line L(50*(i+1),50,50*(i+1),450); L.imprint();
 }
 for(int i=0;i<9;i++){
    Line L(50,50*(i+1),450,50*(i+1)); L.imprint();
 }
 Circle c1(225,225,20);Circle c2(275,275,20);
 c1.setColor(COLOR("white"));c2.setColor(COLOR("white"));
 c2.setFill(); c1.setFill();
 c1.imprint();c2.imprint();

 Circle c3(275,225,20);Circle c4(225,275,20);
 c4.setColor(COLOR("black"));c3.setColor(COLOR("black"));
 c4.setFill(); c3.setFill();
 c4.imprint(); c3.imprint();
}
int **create_array(){//creating an array with code a[i][j]=10*i+j and x=i*50 and y=j*50
  int **a=new int*[10];
  for(int k=0;k<10;k++) a[k]=new int[10];
  for(int i=0;i<10;i++){
     for(int j=0;j<10;j++) a[i][j]=0;}
  a[4][4]=2; a[5][5]=2;
  a[4][5]=1; a[5][4]=1;
   return a;}

void Rules(){//rules of the game;
cout<<"click on the box which you want to place your colour"<<endl<<endl;
cout<<"Rules:"<<endl;
cout<<"* Each player is given with 30 blacks and 30 whites"<<endl;
cout<<"* At the end the player with more number of boxes with his colour will win"<<endl;
cout<<"* If the player was not able to change even one box coour then he wil lose "<<endl;
cout<<"* If the player can change all the colours of the opponents then he is won"<<endl;
cout<<"colour: row: coloumn:"<<endl;
}
main_program{
  int **a=create_array();
  bool flag=0;
  int p;
  cout<<"Enter 1 for one player and 2 for two players: ";cin>>p;
  Rules();
  turtleSim();
  drawbox();
  repeat(100){
  if(flag==1) break;
  clickbox(a,flag,p);}
  wait(2);
}
