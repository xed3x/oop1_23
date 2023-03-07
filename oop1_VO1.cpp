#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

int add(int x, int y){ return x + y; }
float add(float x, float y){ return x + y; }
struct SuperHero{ char name_[30]; int power_; };
void printHeroPointer(SuperHero* hero){ std::cout << hero->name_; }
void printHeroReference(SuperHero& hero){ std::cout << hero.name_; }
namespace Marvel{ struct SuperHero{ char* name_; int power_; int strenght_; }; }
namespace DC{ struct SuperHero{ char* name_; int power_; int weakness_; }; }
typedef struct _Book_ { char name_[50]; int pages_; struct _Book_* nextBook_; } Book; // Frage / Beispiel 2
typedef struct _Calculation_{ int operand_a_; int operand_b_; char operator_; } Calculation; // Example: Struct
void printNumbers(char* arr, size_t length){
  for(size_t i=0;i<length;i++)
    if( *(arr + i) >= '0' && *(arr + i) <= '9' )
      printf("%c", arr[i]);
  printf("\n");
}
void f(int* p, int m){ // Frage / Beispiel 1:
  m = m+5; 
  printf("1.f.1: %d | 1.f.2: %d | ", p, *p);
  *p = *p + m; 
  printf("1.f.3: %d ",*p);
  //return;
}
int main(int xx , char* argv[]){
  if(1){  // Frage / Beispiel 1:
    int p=5, m=10; 
    printf("BSP 1: 1.1: %d | ",&p);
    f(&p,m); printf("| 1.2: %d\n",p + m);
  }
  if(1){  // Frage /Beispiel 2:
    Book b3 = { "The Return of the King", 444, NULL };
    Book b2 = { "The Two Towers", 510, &b3 };
    Book b1 = { "The Fellowship of the Ring", 608, &b2 };
    printf("BSP 2: %s\n", b1.nextBook_->name_);
  }
  if(1){  // Frage / Beispiel 3:
    //Aufruf: ./oop1 will be fun
    printf("BSP 3: %s\n", *(argv + 1));
  }
  if(1){  // Pointerdarstellung
    int number = 1; int* ptr; ptr = &number;
    printf("Pointerdarstellung: &number: %p | ptr: %p | *ptr: %d \n", &number, ptr, *ptr);  //0x7fffffffdcdc, 0x7fffffffdcdc, 1
  }
  if(1){  // call-by-{value,reference}
    char arr[] = {'H','a','1','4','0'};
    printf("call-by-{value,reference}: ");
    printNumbers(arr, sizeof(arr));
  }
  if(1){  // Memory Allocation
    char* mem = (char*) malloc(sizeof(char) * 3 + 1); // mit melloc holen wir uns Speicher vom Heap ab in der Größe von (char = 1Byte) * 3 + 1 NULL Byte
    if (mem == NULL) return 1;
    printf("Memory Allocation: *mem(NULL): %c", *mem);
    strcpy(mem, "ESP");
    printf("| *mem(ESP): %p", *mem);
    mem = (char*) realloc(mem, 4 + 1);
    printf(" | *mem(relloc): %p", *mem); // auch realloc(mem, sizeof(char) * 4 + 1) | sizeof(char) ist immer 1 Byte, daher Mal 4
    if(mem == NULL) return -1;
    strcpy(mem, "OOP1");
    printf(" | *mem(OOP1): %p", *mem);
    free(mem); mem = NULL;
  }
  if(1){  // struct
    Calculation c1 = {5,4,'+'};
    printf("struct: %d %c %d\n",c1.operand_a_, c1.operator_,c1.operand_b_);
  }
  if(1){  // Ein- und Ausgabe
    char speise[50];
    printf("Ein- und Ausgabe: Was ist deine Lieblingsspeise? ");
    //scanf("%s",speise);
    printf("Meine Lieblingsspeise ist %s! \n", speise);
  }
  if(1){  // Unterschiede 
    std::cout << "Unterschiede: Diese Ausgabe funktioniert NUR in C++ über #include <iostream>" << std::endl;
    printf("Unterschiede: Diese Ausgabe funktioniert AUCH in C++ über #include <cstdio>\n");
  }
  if(1){  // Namespace
    Marvel::SuperHero ironman; ironman.power_ = 9000;
    DC::SuperHero superman; superman.power_ = 8999;
    std::cout << "Namespaces: Ironman = " << ironman.power_ << " | Superman = " << superman.power_ << std::endl;
  }
  if(1){  // Referenzen
    int a = 24601;  int& a_ref = a;  int* a_ptr = &a;
    std::cout << "Reference: a = " << a << " | &a = " << &a << " | int& a_ref = a == " << a_ref << " | int* a_ptr = &a == " << a_ptr << " | *a_ptr = " << *a_ptr << std::endl; // 24601, 0x7fffffffdcdc, 24601, 0x7fffffffdcdc, 24601
  }
  if(1){  // Example - Superheros
    SuperHero ironman = {"Tony Stark",9000};
    std::cout << "Example: Superheros: &ironman@Pointer = ";
    printHeroPointer(&ironman); 
    std::cout << " | ironman@Reference = ";
    printHeroReference(ironman); 
  }
  if(1){  // Auto
    auto var1 = 123;          //Integer
    auto var2 = 1.2;          //Double
    auto var3 = var1 + var2;  //Double
    auto var4 = 123456789789; //Long
    auto *var5 = &var1;       //Pointer
    std::cout << "Auto: var1 = " << var1 << " | var2 = " << var2 << " | var3 = " << var3 << " | var4 = " << var4 << " | *var5 = " << var5 << std::endl;
  }
  if(1){  // for++ - range-based for loops
    char arr[] = {'H','a','1','1','0'};
    std::cout << "for++: range-based for loops: size_t i=0;i<sizeof(arr);i++ -> ";
    for(size_t i=0;i<sizeof(arr);i++){ std::cout << arr[i]; } // Bisheriger Ansatz
    std::cout << " | auto el : arr -> ";
    for(auto el : arr){ std::cout << el; } // Range-based for loop
    std::cout << "\n";
  }
  if(1){  // Funktionsaufrufe
    int var1 = 21.3, var2 = 21; std::cout << "Funktionsaufrufe: C++ [OK]:" << add(var1, var2) << " | C [Nicht OK]" << std::endl;
  }
  if(1){  // Strings
    std::string author = "Mein String";
    std::cout << "Strings: Originaleintrag = " << author;
    author = "Neuer String";
    std::cout << " | Neuer Eintrag = " << author << std::endl;
  }
}