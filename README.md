# cdl2020
##### Necula Bianca

Repo pentru rezolvarea problemei pentru CDL2020. Programul nu este inca functional.
### Works:
* citirea si memorarea fisierelor
* citirea si memorarea cuvintelor din fisiere
* crearea unei matrici binare nr_fisiere*nr_cuvinte care memoreaza aparitia cuvantului in fisier
* citirea secventei de la stdin
* implementarea unei stive de stringuri

### Not working, but almost done:
* rezolvarea secventei prin memorarea unui vector de rezultate binare pt fiecare fisier (main)
* evaluate(@param): 
  * crearea a 2 stive pentru memorarea operanzilor si valorilor 
  * transformarea valorilor din stringuri (cuvinte) in valori binare prin cautarea in matrice a valorii corespunzatoare (change(@param))
  * efectuarea operatiei binare intre cele 2 valori (infix) in apply_op(@param)
  * returnarea rezultatului ca fiind ultima valoare ramasa in stiva de valori
### Not working yet:
* stiva de int
* functionalitate noua: GUI in Linux pentru search engine in directorul curent cu GTK+3 like
```
1:  #include <gtk/gtk.h>  
2:  int main( int  argc,  
3:       char *argv[] )  
4:  {  
5:    GtkWidget *window;  
6:    gtk_init (&argc, &argv);  
7:    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);  
8:    gtk_widget_show (window);  
9:    gtk_main ();  
10:    return 0;  
11:  }  
```

> Thanks for reading!

