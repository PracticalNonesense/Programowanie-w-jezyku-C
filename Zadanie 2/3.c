#include <stdio.h>

struct Point {
  int x;
  int y;
};

int ChngPoint(struct Point *point, int x1, int y1){
    point->x = x1;
    point->y = y1;
}



struct Rectangle {
     struct Point tl;
    struct Point br;
};

int Area(struct Rectangle rect) {
    int width = rect.br.x - rect.tl.x;
    int height = rect.br.y - rect.tl.y;
    return width * height;
};

int Perimeter(struct Rectangle rect) {
    int width = rect.br.x - rect.tl.x;
    int height = rect.br.y - rect.tl.y;
    return 2 * width + 2 * height;
};

int main(){
    struct Point point;
    point.x = 8;
    point.y = 3;
    printf("Wspolrzedne punktu: (%d;%d)\n", point.x, point.y);
    
    ChngPoint(&point, 8, 7);

    printf("Nowe wspolrzedne punktu: (%d;%d)\n", point.x, point.y);
    
    
    struct Rectangle rectangle;
    rectangle.tl.x = 6;
    rectangle.tl.y = 4;
    rectangle.br.x = 1;
    rectangle.br.y = 2;

    int area = Area(rectangle);
    int perimeter = Perimeter(rectangle);
    
    if (perimeter < 0)
    {
        perimeter = perimeter * -1;
    }
    else if(area < 0)
    {
        area = area * -1;
    }

    printf("Pole prostokata: %d\n", area);
    printf("Obwod prostokata: %d\n", perimeter);

    
    return 0;
};
