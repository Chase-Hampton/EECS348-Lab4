#include <stdio.h>

float convert_celsius(float temp, int scale);
float convert_from_celsius(float celcius, int target);
void advisory(float celcius);

int main() {
    float input_temp, converted_temp, value_celsius;
    int current_scale, target;

    printf("Enter the temperature value: ");
    scanf("%f", &input_temp);

    printf("Choose the temperature scale of the input value (Fahrenheit, Celsius, or Kelvin): ");
    scanf("%d", &current_scale);

    printf("Choose the conversion target (Fahrenheit, Celsius, or Kelvin): ");
    scanf("%d", &target);

    value_celsius = convert_celsius(input_temp, current_scale);

    converted_temp = revert_celsius(value_celsius, target);

    printf("\nConverted temerature: %.2f\n", converted_temp);
    advisory(value_celsius);

    return 0;

}

float convert_celsius(float temp, int scale) {
    if (scale == 1) return (temp - 32) * 5 / 9;
    if (scale == 3) return temp - 273.15;
    return temp;
}

float revert_celcius(float celsius, int target) {
    if (target == 1) return (celsius * 9 / 5) + 32;
    if (target == 3) return celsius + 273.25;
    return celsius;
}

void advisory(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\nAdvisory: Wear a heavy coat and stay warm. \n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Category: Cold\nAdvisory: Wear a jacket.\n"); 
    } else if (celsius >= 10 && celsius < 25) {
        printf("Comfortable\nAdvisory: The weather is comfortable. Enjoy your day!\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Hot\nAdvisory: It's getting hot. Stay hydrated.\n");
    } else {
        printf("Extreme Heat\nAdvisory: Extreme heat warning! Stay indoors and keep cool.\n");
    }
}