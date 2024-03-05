#include <stdio.h>
#include <math.h>

struct Point {
  float x;
  float y;
}

float Func(float x, float y){
    float* pnt = &x;
    
    *pnt = *pnt * 2;
    
    float* pnt1 = &y;
    
    *pnt1 = *pnt1 * 2;
    
    return *pnt, *pnt1;
}
struct Rectangle {

}

int main()
{

}
