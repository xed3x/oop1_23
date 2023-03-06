/* Allgemeine Fragen:
Reicht die gcc 10.2.1 Version aus ? 
Bekommt man einen Login, um seinen eigenen Code auf eure Systeme vor der Abgabe kompilieren uns somit testen zu können? Wenn ja ab wann und wird das in der KU / VO noch angesagt?

Helft mir bitte dabei und korrigiert mich, wenn nötig, ob ich das richtig lese! egal ob Logik oder Fehler in der Begriffsnutzung
*/

#include <iostream>
#include <cstdio>
#include <string>

struct SuperHero{ char name_[30]; int power_; };
void printHeroPointer(SuperHero* hero){ std::cout << hero->name_ << std::endl; }
void printHeroReference(SuperHero& hero){ std::cout << hero.name_ << std::endl; }
typedef struct _Calculation_{ int operand_a_; int operand_b_; char operator_; } Calculation;
typedef struct _Book_ { char name_[50]; int pages_; struct _Book_* nextBook_; } Book;
int add(int x, int y){ return x + y; }
float  add(float x, float y){ return x + y; }
void f(int* p, int m){
  m = m+5; 
  printf("1.f.1: %d\n",p);
  printf("1.f.2: %d\n",*p);
  *p = *p + m; 
  printf("1.f.3: %d\n",*p);
  return;
}
int main(int xx , char* argv[]){
  // Frage / Beispiel 1:
  int p=5, m=10; 
  printf("1.1: %d\n",&p);
  f(&p,m); printf("1.2: %d\n",p + m);
  /*Meine Fragen zur Frage / Beispiel 1:
      Man hat void main wo per & im f(&p,m) die Adresse (0x7...) übergeben wird (Was bei mir laut Ubuntu mit dem Output 1.1 den Wert 2126214692 hat, somit kein 0x..., wieso?) Dann wiederum per void f(...) mit dem int* veranlasst wird, dass nur ein Pointer als Eingabe erlaubt wird, (was aus meiner Sicht etwas unlogisch erscheint, da & != * sein sollte. Hätte man hier nicht einfach int& p nehmen können, damit man sich das *-Sternchen ersparen hätte können?) damit dann per *p die Zahl über die gleiche Adresse wieder angesprochen wird (wie laut Output 1.f.2), um die Rechnung per *p + m zu ermöglichen. Dann muss man wieder *p = ... setzen, damit C++ versteht, dass es nur den Wert auf exakt der eingegebenen Adresse unter p verändern soll, damit kein neuen Speicher reservieren wird (Was aus meiner Sicht etwas strange ist, da ja p per int* p so oder so nur das sein kann / soll) Übersehe ich da etwas oder ist genau sowas der Grund, wieso viele Firmen wie google und co. nicht ohne Grund (zum Eigenschutz, etc.) eigene Programmiersprachen entwickeln, um von dieser Logik weg zu kommen. Zwischeninfo: Und nein, objektorientierte Programmierung habe ich noch nie gebraucht, obwohl ich bereits einige riesige Projekte in php, python und js realisiert habe. Auch auf systemtechnischer Ebene habe ich lieber python statt c++ genutzt, um billige bis mittlere Securitystandards für meinen Server zu entwickeln
      Output: g++ oop1.cpp -o foo && ./oop1
        1.1: 2125202980
        1.f.1: 2125202980
        1.f.2: 5
        1.f.3: 20
        1.2: 30

        x.1: 0x7eac0620
        x.2: 0x7eac0620
        x.3: 0x1
  */

  printf("\n");
  //Frage / Beispiel 2:
  Book b3 = { "The Return of the King", 444, NULL };
  Book b2 = { "The Two Towers", 510, &b3 };
  Book b1 = { "The Fellowship of the Ring", 608, &b2 };
  printf("%s", b1.nextBook_->name_);
  
  printf("\n");
  //Frage / Beispiel 3:
  //Aufruf: ./oop1 will be fun
  printf("%s", *(argv + 1));
  /*Meine Fragen zur Frage / Beispiel 3:
      Unter int main() werden 2 Argumente benötigt, int argc und char* argv[]. Man kann ja auch nur main(int ,argv[]) nehmen, nur bin ich mir hierbei nicht sicher ob es nur zum Unterdrücken von Warnings genutzt wird, welche Konsequenzen es hat bzw. haben kann. Könnt ihr mir bitte genau erklären wieso diese int argc oder nur int unbedingt verwendet werden muss und was der Unterschied bei der Nutzung von main(int, char* argv[]) zu main(int argc, char* argv[]) ist, damit ich nichts übersehen kann? Was mich aber eher verwirrt ist *(argv + 1)! argv ist für mich ein array, da die Eingabe will be bla bla zu einem Array gebündelt wird, sobald ein space erkannt wird. Wie kann es dann sein, dass argv + 1 funktionieren kann? In anderen Programmiersprachen macht man das per argv[1], womit man direkt auf die Variabe zugreifft. Mag sein, das C++ dabei auch den Namen der auszuführenden File (oop1) als 0-tes Arraymitglied implementiert, womit eine Stelle weiter (will) die Lösung sein muss. Da ja per char* argv[] das Array vom Compiler selbst an die Speicheradresse platziert wird und wir per *(argv + 1) auf die Werte abrufen ist mir der Pointer an dieser Stelle verständlich. Liegt es nur an der veralteten Schreibweise, weil C++ diese Schreibweise übernommen hat ohne auf das neue argv[n] Modell umzusteigen oder übersehe ich da etwas?  
  */

  printf("\n\n");
  //Pointerdarstellung
  int number = 1;
  int* ptr;
  ptr = &number;
  printf("x.1: %p\n", &number);  //0x7fffffffdcdc
  printf("x.2: %p\n", ptr);      //0x7fffffffdcdc
  printf("x.3: %p\n", *ptr);     // 1
  //std::cout << "Hello World" << std::endl;

  printf("\n");
  // Ist ein struct mit dem Objekt gleichzusetzen oder gibt es Unterschiede?
  Calculation c1 = {5,4,'+'};
  // Anscheinend autodetect was was ist
  printf("%d %c %d\n",c1.operand_a_, c1.operator_,c1.operand_b_);

  printf("\n");
  int a = 24601;
  int& a_ref = a;
  int* a_ptr = &a;

  std::cout << a << std::endl;        //24601
  std::cout << &a << std::endl;       //0x7ea44544
  std::cout << *&a << std::endl;      //24601
  std::cout << a_ref << std::endl;    //24601
  std::cout << a_ptr << std::endl;    //0x7fffffffdcdc
  std::cout << *a_ptr << std::endl;   //24601

  printf("\n");  
  SuperHero ironman = {"Tony Stark",9000};
  printHeroPointer(&ironman);
  printHeroReference(ironman);

  printf("\n");  
  int var1 = 21.3, var2 = 21; std::cout << add(var1, var2) << std::endl;
  printf("\n");
  std::string author = "Mein String ist neu";
  std::cout << author << std::endl; return 0;   

}
/*


@05.03.23 - 10:17 
C:\Windows\system32>netstat -fnoi
Aktive Verbindungen
  Protokoll  Lokale Adresse         Remoteadresse          Status          PID      Zeit im Status (ms)
TCP    192.168.8.83:57493     52.143.86.214:443      HERGESTELLT        0     31455
TCP    192.168.8.83:57498     52.143.84.45:443       WARTEND            6     29761
TCP    192.168.8.83:57521     51.124.78.146:443      WARTEND            6     29434
TCP    192.168.8.83:57522     40.127.169.103:443     WARTEND            6     29127
TCP    192.168.8.83:57523     51.124.78.146:443      WARTEND            6     29157
TCP    192.168.8.83:57524     51.124.78.146:443      WARTEND            6     29022
TCP    192.168.8.83:57525     40.127.169.103:443     WARTEND            6     28935
TCP    192.168.8.83:57526     51.124.78.146:443      WARTEND            6     28886
TCP    192.168.8.83:57527     51.124.78.146:443      WARTEND            6     28732
TCP    192.168.8.83:57530     13.91.16.64:443        WARTEND            6     25936
TCP    192.168.8.83:57542     173.194.76.188:5228    HERGESTELLT        0     27565
TCP    192.168.8.83:57543     93.184.221.240:80      WARTEND            6     26691
TCP    192.168.8.83:57544     40.127.169.103:443     WARTEND            6     26714
TCP    192.168.8.83:57546     40.125.122.151:443     WARTEND            6     25859
TCP    192.168.8.83:57547     93.184.221.240:80      WARTEND            6     17125
TCP    192.168.8.83:57550     20.199.120.85:443      HERGESTELLT        0     26559
TCP    192.168.8.83:57551     162.247.243.29:443     HERGESTELLT        0     26496
TCP    192.168.8.83:57552     162.247.243.29:443     HERGESTELLT        0     26496
TCP    192.168.8.83:57553     139.45.197.239:443     HERGESTELLT        0     26479
TCP    192.168.8.83:57557     139.45.197.239:443     HERGESTELLT        0     26387
TCP    192.168.8.83:57560     13.91.16.64:443        WARTEND            6     16286
TCP    192.168.8.83:57561     40.127.169.103:443     WARTEND            6     25815
TCP    192.168.8.83:57562     40.127.169.103:443     WARTEND            6     25630
TCP    192.168.8.83:57566     51.124.78.146:443      WARTEND            6     25318
TCP    192.168.8.83:57568     51.124.78.146:443      WARTEND            6     24932
TCP    192.168.8.83:57570     51.124.78.146:443      WARTEND            6     24783
TCP    192.168.8.83:57571     51.124.78.146:443      WARTEND            6     24648
TCP    192.168.8.83:57572     51.124.78.146:443      WARTEND            6     24490
TCP    192.168.8.83:57573     52.143.84.45:443       WARTEND            6     23186
TCP    192.168.8.83:57574     51.124.78.146:443      WARTEND            6     24271
TCP    192.168.8.83:57576     104.80.244.38:443      HERGESTELLT        0     23454
TCP    192.168.8.83:57593     35.167.139.248:443     HERGESTELLT        0     13975
TCP    192.168.8.83:57594     40.125.122.151:443     WARTEND            6     9771
TCP    192.168.8.83:57596     199.232.18.114:443     HERGESTELLT        0     13645
TCP    192.168.8.83:57600     40.125.120.53:443      HERGESTELLT        0     11060
TCP    192.168.8.83:57601     20.189.173.13:443      WARTEND            6     8996
TCP    192.168.8.83:57606     142.251.36.163:443     WARTEND            6     10100
TCP    192.168.8.83:57607     104.80.244.38:443      HERGESTELLT        0     9886
TCP    192.168.8.83:57614     104.80.244.38:443      HERGESTELLT        0     9477
TCP    192.168.8.83:57615     209.197.3.8:80         HERGESTELLT        0     9407
TCP    192.168.8.83:57616     8.241.45.126:80        HERGESTELLT        0     9233
TCP    192.168.8.83:57617     8.249.63.254:80        HERGESTELLT        0     9233
TCP    192.168.8.83:57618     2.18.79.145:80         HERGESTELLT        0     8820
TCP    192.168.8.83:57619     8.238.190.126:80       HERGESTELLT        0     8576
TCP    192.168.8.83:57620     8.248.145.254:80       HERGESTELLT        0     8576
TCP    192.168.8.83:57621     20.189.173.13:443      WARTEND            6     7363
TCP    192.168.8.83:57623     13.32.110.29:443       HERGESTELLT        0     6625
TCP    192.168.8.83:57624     199.232.18.114:443     HERGESTELLT        0     6402
TCP    192.168.8.83:57625     20.189.173.13:443      WARTEND            6     5361
TCP    192.168.8.83:57627     20.189.173.13:443      WARTEND            6     260
TCP    192.168.8.83:57628     20.199.120.85:443      HERGESTELLT        0     658

*/