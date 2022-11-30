#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "string.h"

typedef struct
{
    int id;
    char nombre[30];
    int edad;
    char sexo;
} eMascota;


int mostrarMascotas(LinkedList *pMascotas);
void mostrarMascota(eMascota *mascota);
int esMacho(void *m);
int esHembra(void *m);
int esMayor5(void *m);
int esMizzie(void *m);
int ordenarPorNombre(void * nombreUno, void*nombre2);
int stringLower(char str[]);
int main()
{

    LinkedList*lista=ll_newLinkedList();

    eMascota m1= {1,"Botitas",6,'m'};
    eMascota m2= {2,"Mizzie",5,'f'};
    eMascota m3= {3,"Blanca",8,'f'};
    eMascota m4= {4,"Patitas",3,'m'};
    eMascota m5= {5,"Blacky",2,'m'};
    eMascota m6= {6,"MascotaSet",5,'f'};
    ll_add(lista,&m1);
    ll_add(lista,&m2);
    ll_add(lista,&m3);
    ll_add(lista,&m4);
    ll_add(lista,&m5);
    LinkedList *listaFiltrada=ll_filter(lista,esHembra);
    // printf("%d",ll_len(lista));
    //  mostrarMascota(&m1);
    // mostrarMascota((eMascota*)ll_get(lista,3));
    mostrarMascotas(lista);
    //se debe eliminar patitas
    ll_remove(lista,3);
    mostrarMascotas(lista);
    printf("Lista filtrada\n");
    mostrarMascotas(listaFiltrada);
    printf("Ordenar por nombre asc\n");
    ll_sort(lista,ordenarPorNombre,1);
    mostrarMascotas(lista);
    printf("La lista esta vacia: %d\n",ll_isEmpty(lista));
    printf("Lista actual\n");
    mostrarMascotas(lista);
    // se debe reemplazar a blacky
    ll_set(lista,0,&m6);
    mostrarMascotas(lista);
    //debe mostrar 1
    printf("%d\n",ll_indexOf(lista,&m3));
    // vuelvo a agregar a patitas en indce 1
    ll_push(lista,1,&m4);
    mostrarMascotas(lista);
    //elimino a patitas y muestro que lo elimine
    printf("Elimine a: ");
    mostrarMascota((eMascota*)(ll_pop(lista,1)));
    //chequeo si la lista contiene a patitas
    printf("existe patitas en la lista: %d\n",ll_contains(lista,&m4)) ;
    //chequeo si la lista contiene a Mizzie
    printf("existe mizzie en la lista: %d\n",ll_contains(lista,&m2)) ;
    //chequeo si la lista filtrada pertence a la lista general
    //tendria que aparecer 1 porque mizzie y blanca pertencen a ambas listas
    printf("CONTAINS ALL %d\n",ll_containsAll(lista,listaFiltrada));
    //creo una sublista con los primeros 3 elementos
    LinkedList *sublista= ll_subList(lista,0,3);
    printf("Mascotas de la sublista\n");
    mostrarMascotas(sublista);
    //clono sublista
    LinkedList*sublistaDos= ll_clone(sublista);
    //debe mostrarse la misma lista
    printf("Mascotas de la sublista clon\n");
    mostrarMascotas(sublistaDos);
    //elimino los elementos de la sublista 2
    ll_clear(sublistaDos);
    //elimino la linkedlist de subslita 2
    ll_deleteLinkedList(sublistaDos);
    return 0;

}







void mostrarMascota(eMascota *mascota)
{
    if(mascota != NULL)
    {

    }
    printf("%d %s %d %c \n",mascota->id,mascota->nombre,mascota->edad,mascota->sexo);
}
int esMacho(void *m)
{
    int ok=0;
    eMascota*unaMascota=NULL;
    if(m!= NULL)
    {
        unaMascota=(eMascota*)m;
        // devuelvo 1 si cumple la condic
        if(unaMascota->sexo== 'm')
        {
            ok=1;
        }
    }
    return ok;
}
int esHembra(void *m)
{
    int ok=0;
    eMascota*unaMascota=NULL;
    if(m!= NULL)
    {
        unaMascota=(eMascota*)m;
        // devuelvo 1 si cumple la condic
        if(unaMascota->sexo== 'f')
        {
            ok=1;
        }
    }
    return ok;
}
int esMayor5(void *m)
{
    int ok=0;
    eMascota*unaMascota=NULL;
    if(m!= NULL)
    {
        unaMascota=(eMascota*)m;
        // devuelvo 1 si cumple la condic
        if(unaMascota->edad>5)
        {
            ok=1;
        }
    }
    return ok;
}
int esMizzie(void *m)
{
    int ok=0;
    eMascota*unaMascota=NULL;
    if(m!= NULL)
    {
        unaMascota=(eMascota*)m;
        // devuelvo 1 si cumple la condic
        if(strcmp(unaMascota->nombre,"Mizzie")==0)
        {
            ok=1;
        }
    }
    return ok;
}
int mostrarMascotas(LinkedList *plistaMascotas)
{
    int validado=0;
    if(plistaMascotas!= NULL)
    {
        printf("ID NOMBRE EDAD SEXO\n");
        for(int i=0; i<ll_len(plistaMascotas); i++)
        {
            mostrarMascota((eMascota*)ll_get(plistaMascotas,i));
        }

        validado=1;
    }
    return validado;
}

int ordenarPorNombre(void * nombreUno, void*nombre2)
{
    int rta=-2;
    eMascota *auxPrimerMascota;
    eMascota *auxSegundaMascota;
    auxPrimerMascota=(eMascota*)nombreUno;
    auxSegundaMascota=(eMascota*)nombre2;
    char primerNombre[30];
    char segundoNombre[30];
    if(nombre2!= NULL && nombreUno!= NULL)
    {
        strcpy(primerNombre,auxPrimerMascota->nombre);
        strcpy(segundoNombre,auxSegundaMascota->nombre);
        stringLower(primerNombre);
        stringLower(segundoNombre);
        rta=strcmp(primerNombre,segundoNombre);
    }

    return rta;
}
int stringLower(char str[])
{
    int validado = 0;
    if (str != NULL)
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] = tolower(str[i]);
        }
        validado = 1;

    }
    return validado;
}

