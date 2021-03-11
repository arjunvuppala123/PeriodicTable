#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

/*
this structure has all the attributes of an element
*/
struct element
{

    int atomic_number;
    char name[30];
    float atomic_weight;
    char symbol[5];
    float melting_point;
    float boiling_point;
    float density;
    char state[15];
    char met_st[9];       //it denotes metallic state of the element
};

//changing the name of the structure
typedef struct element el;

//declaring a global variable of type
el e;

//function to validate string-type inputs
void checkstring(char str[])
{
    int i;
    for (i=0; str[i]!= '\0'; i++)
    {
        if (isalpha(str[i]) == 0)
            {
                printf("\nEnter character or string only:\n");
                fflush(stdin);
                scanf(" %s",&str);
            }
    }
}

//checks for duplicate element in the file
int nodup(int anum)
{
    FILE *ipt;

    ipt = fopen ("periodictable.dat", "rb");

    rewind(ipt);
    while(fread(&e, sizeof(e), 1, ipt)==1)
        {
            if(anum==e.atomic_number)
                {
                    printf("This element is already present!!Try again!!\n");
                    return 1;
                }
        }
        return 0;
}
//Displays the menu and periodic table
int menu()
{
    int ch;
    system("color 1E"); //sets background and textcolor
    system("cls");
    printf("\n\t\t\t        THE MODERN PERIODIC TABLE\n");

    printf("\t\t\t        -------------------------\n");

    printf("\t    -----                                                             ------\n");
    printf("\t    | H |                                                             | He |\n");
    printf("\t    | 1 |                                                             | 2  |\n");
    printf("\t    | Li Be                                          B   C  N  O   F  Ne |\n");
    printf("\t    | 3  4                                           5   6  7  8   9  10 |\n");
    printf("\t    | Na Mg                                          Al Si  P  S   Cl Ar |\n");
    printf("\t    | 11 12                                          13 14  15 16  17 18 |\n");
    printf("\t    | K  Ca Sc   Ti  V  Cr   Mn  Fe  Co  Ni  Cu  Zn  Ga Ge  As Se  Br Kr |\n");
    printf("\t    | 19 20 21   22  23 24   25  26  27  28  29  30  31 32  33 34  35 36 |\n");
    printf("\t    | Rb Sr Y    Zr  Nb Mo   Tc  Ru  Rh  Pd  Ag  Cd  In Sn  Sb Te  I  Xe |\n");
    printf("\t    | 37 38 39   40  41 42   43  44  45  46  47  48  49 50  51 52  53 54 |\n");
    printf("\t    | Cs Ba La*  Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg  Tl Pb  Bi Po  At Rn |\n");
    printf("\t    | 55 56 57   72  73  74  75  76  77  78  79  80  81 82  83 84  85 86 |\n");
    printf("\t    ---------------------------------------------------------------\n");
    printf("\t    | Fr Ra Ac** Rf  Db  Sg  Bh  Hs  Mt  Ds  Uuu Uub -Uuq - Uuh   |\n");
    printf("\t    | 87 88 89   104 105 106 107 108 109 110 111 112 - 113 -  114 |\n");
    printf("\t    ---------------------------------------------------------------\n\n");
    printf("\t\t  | Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu\n");
    printf("\t\t  | 58 59 60 61 62 63 64 65 66 67 68 69 70 71\n");
    printf("\t\t  | Th Pa U  Np Pu Am Cm Bk Cf Es Fm  Md  No  Lr\t\t\t\n");
    printf("\t\t  | 90 91 92 93 94 95 96 97 98 99 100 101 102 103\n\t\t\t-------------------------\n");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\n    NB: the * indicates the start of lathanoid series");
    printf("       the **  indicates the start of actinoid series ");
    printf("\n-----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t  Main Menu:");
    printf("\n\t  1-Entering data for new element");
    printf("\n\t  2-Displaying data of element of your choice");
    printf("\n\t  3-Whether entered element is a metal or non metal");
    printf("\n\t  4-Exit\n");

    printf("\t  enter your choice:");

    scanf("%d",&ch);

    return ch;
}

//function for verifying metallic state of particular element
void metal_state()
{
   system("color 4A");
    FILE *ipt;

    int flag1=0,a,item;

    printf("Enter the atomic number:");
    a=scanf("%d",&item);

    while (a!=1)
        {
            printf("\nonly integer type allowed\n");
            fflush(stdin);
                a=scanf("%d",&item);
        }

        ipt = fopen ("periodictable.dat", "rb");

        rewind(ipt);

        while(fread(&e, sizeof(e), 1, ipt)==1)
            {
               if(item==e.atomic_number){
                    flag1=1;
                if(strcmp(e.met_st,"metal")==0)
                {
                    system("color 5A");
                    printf("***************");
                    printf("\n*It is a Metal*\n");
                    printf("***************");
               }
               else if(strcmp(e.met_st,"non-metal")==0){
                    system("color 6F");
                printf("*******************");
                printf("\n*It is a Non-Metal*\n");
                printf("*******************");

                break;
               }
               else
                {
                    system("color 7C");
                    printf("*******************");
                    printf("\n*It is a metalloid*\n");
                    printf("*******************");

                }
           }
           }

           if (flag1==0){
                system("color 4");
                printf("Element not found!");
           }
            fclose(ipt);
            printf ("\n\t\t\t\t  Press any key to continue!!");
            getch();
}

//Displays the details of the element upon entry of the atomic number
void display()
{

    FILE *ipt;
    int item,flag2=0,a;
    printf("Enter the atomic number:");
    a=scanf("%d",&item);
    while(a!=1)
        {
            printf("\nonly integer type allowed\n");
            fflush(stdin);
            a=scanf("%d",&item);
        }
    ipt = fopen ("periodictable.dat", "rb");
    rewind(ipt);
    while(fread(&e, sizeof(e), 1, ipt)==1)
        {
            if(item==e.atomic_number)
                {
                    system("color 2E");
                    printf("\nNB:In Data , 0 indicates that the data is unknown!!(Mostly implies for elements of atomic number > 100)");

                    flag2=1;
                    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------");
                    printf ("\nAtomic number: %d\nElement name: %s\nAtomic weight: %f amu\nSymbol: %s\nMelting point: %f C\nBoiling Point: %f C\nDensity: %f g/cm\nState: %s\n",
                            e.atomic_number,e.name,e.atomic_weight,e.symbol,e.melting_point,e.boiling_point,e.density,e.state);
                    printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
                    break;

                }
            }
            if (flag2==0){
                system("color 4");
                printf("Element not found!"); }
            fclose(ipt);
            printf ("\n\t\t\t\t  Press any key to continue!!");
            getch();
}


//adding new elements in the file
void element_entry()
{
    system("color 2B");
    int a,b,c,d,anum;
    FILE *fpt;
    char ch;


    do{
            fpt=fopen("periodictable.dat","ab");

            printf("Enter the atomic number:");

            fflush(stdin);

            a=scanf("%d",&e.atomic_number);
            anum=e.atomic_number;
            while (a!=1)
            {
                printf("\nonly integer type allowed\n");
                printf("Enter Again:");
                fflush(stdin);
                a=scanf("%d",&e.atomic_number);
            }
            while (nodup(e.atomic_number) ==1)
            {
                 printf("Enter the atomic number:");
                 fflush(stdin);
                 a=scanf("%d",&e.atomic_number);
                 while (a!=1)
                {
                    printf("\nonly integer type allowed\n");
                    printf("Enter Again:");
                    fflush(stdin);
                    a=scanf("%d",&e.atomic_number);
                }
            }
            e.atomic_number=anum;

            printf("Enter the element name:");
            scanf(" %s",e.name);
            checkstring(e.name);

            printf("Enter the atomic weight (in gram):");
            c=scanf("%f",&e.atomic_weight);
            while(e.atomic_weight<0)
            {
                printf("Atomic weight is Negative");
                printf("Enter Again:");
                fflush(stdin);
                c=scanf("%f",&e.atomic_weight);
            }
           while (c!=1)
            {
                printf("\nonly float type allowed\n");
                printf("Enter Again:");
                fflush(stdin);
                c=scanf("%f",&e.atomic_weight);
            }

            printf("Enter the element symbol:");
            scanf(" %s",e.symbol);
            checkstring(e.symbol);

            printf("Enter the element's melting point (in centigrade):");
            b=scanf("%f",&e.melting_point);
            while (b!=1)
            {
                printf("\nonly float type allowed\n");
                printf("Enter Again:");
                fflush(stdin);
                b=scanf("%f",&e.melting_point);
            }

            printf("Enter the element's boiling point (in centigrade):");
            d=scanf("%f",&e.boiling_point);
            while (d!=1)
            {
                printf("\nonly float type allowed\n");
                printf("Enter Again:");
                fflush(stdin);
                d=scanf("%f",&e.boiling_point);
            }


            printf("Enter the element's density (g/ml):");
            scanf("%f",&e.density);

            printf("Enter the element's state (Gas,Liquid or Solid):");
            scanf("%s",&e.state);
            checkstring(e.state);

            printf("Enter the element metallic state (metal or non-metal or metalloid):");
            scanf(" %s",e.met_st);
            checkstring(e.met_st);

             fwrite(&e,sizeof(e),1,fpt);

             if(fwrite != 0)
                printf("contents to file written successfully !\n");

            else
                printf("error writing file !\n");

            printf("Want to enter more elements?? (y for yes and n for no):");
            scanf(" %c",&ch);

           }
           while(ch=='y'||ch=='Y');

           fclose(fpt);
           printf ("\n\t\t\t\t  Press any key to continue!!");

           getch();
}

int main()
{
    char ch;

    system(" color 7C");

    int i,x;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tA C programming project on Periodic table");
    Sleep(800);
    system("cls");

    for(i=1;i<=30;++i)
    {
                       Sleep(5);
                       system("cls");

                       if(i%2==0)
                           printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING..",i);

                       else if(i%3==0)
                           printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING...",i);

                       else
                           printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING.",i);

                       if(i==100)
                           Sleep(100);
    }

     system("cls");
     int choice;

    //action selected bases on user entry

     do{
        choice=menu();

        switch(choice)
        {
        case 1:

            element_entry();

            continue;

        case 2:

            display();

            continue;

        case 3:

           metal_state();

            continue;

        case 4:
            break;

        default:

            printf("\nWrong Choice!!!!");

            break;

            }
    }

    while(choice<=3);

    printf("\nThank you for using this program\n");

}

