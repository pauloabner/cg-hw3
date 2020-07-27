#ifdef MAINPROGRAM 
#define EXTERN 
#else 
#define EXTERN extern 
#endif 

#ifdef MAINPROGRAM 
const int w = 600, h = 400; // width and height 
#else 
int w, h;
#endif 
