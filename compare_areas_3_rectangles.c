#include <stdio.h>

/* Structure Definition */
typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

/* Function Prototypes */
Rectangle input();
float calculate_area(Rectangle rect);
int compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);
void output(int result, Rectangle r1, Rectangle r2, Rectangle r3);

int main() {
    Rectangle r1, r2, r3;
    int result;

    printf("Enter details of Rectangle 1\n");
    r1 = input();
    r1.area = calculate_area(r1);

    printf("\nEnter details of Rectangle 2\n");
    r2 = input();
    r2.area = calculate_area(r2);

    printf("\nEnter details of Rectangle 3\n");
    r3 = input();
    r3.area = calculate_area(r3);

    result = compare_areas(r1, r2, r3);

    output(result, r1, r2, r3);

    return 0;
}

/* Function to read rectangle details */
Rectangle input() {
    Rectangle rect;

    printf("Enter length: ");
    scanf("%f", &rect.length);

    printf("Enter width: ");
    scanf("%f", &rect.width);

    printf("\n");

    return rect;
}

/* Function to calculate area */
float calculate_area(Rectangle rect) {
    return rect.length * rect.width;
}

/* Function to compare areas */
int compare_areas(Rectangle r1, Rectangle r2, Rectangle r3) {

    if (r1.area > r2.area && r1.area > r3.area)
        return 1;

    else if (r2.area > r1.area && r2.area > r3.area)
        return 2;

    else if (r3.area > r1.area && r3.area > r2.area)
        return 3;

    else if (r1.area == r2.area && r1.area > r3.area)
        return 12;

    else if (r1.area == r3.area && r1.area > r2.area)
        return 13;

    else if (r2.area == r3.area && r2.area > r1.area)
        return 23;

    else
        return 123;
}

/* Function to display result */
void output(int result, Rectangle r1, Rectangle r2, Rectangle r3) {

    printf("\nResult:\n");

    if (result == 1)
        printf("Rectangle 1 has the largest area = %.2f\n", r1.area);

    else if (result == 2)
        printf("Rectangle 2 has the largest area = %.2f\n", r2.area);

    else if (result == 3)
        printf("Rectangle 3 has the largest area = %.2f\n", r3.area);

    else if (result == 12)
        printf("Rectangle 1 and Rectangle 2 have the largest equal area = %.2f\n", r1.area);

    else if (result == 13)
        printf("Rectangle 1 and Rectangle 3 have the largest equal area = %.2f\n", r1.area);

    else if (result == 23)
        printf("Rectangle 2 and Rectangle 3 have the largest equal area = %.2f\n", r2.area);

    else
        printf("All three rectangles have the same area = %.2f\n", r1.area);
}