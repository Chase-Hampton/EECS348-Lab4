#include <stdio.h>
#include <ctype.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temp(float celsius);

int main() {
    float temperature, convertedTemp, tempInCelsius;
    char inputScale, targetScale;

    printf("=== Temperature Conversion Utility ===\n");

    printf("Enter temperature value: ");
    if (scanf("%f", &temperature) !=1) {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }

    printf("Enter input scale (C, F, K): ");
    scanf(" %c", &inputScale);
    inputScale = toupper(inputScale);
    
    printf("Enter target scale (C, F, K): ");
    scanf(" %c", &targetScale);
    targetScale = toupper(targetScale);

    if ((inputScale != 'C' && inputScale != 'F' && inputScale != 'K') ||
        (targetScale != 'C' && targetScale != 'F' && targetScale != 'K')) {
        printf("Error: Invalid scale selection.\n");
        return 1;
    }

    if (inputScale == targetScale) {
        printf("Error: Cannot convert to the same scale.\n");
        return 1;
    }

    if (inputScale == 'K' && temperature < 0) {
        printf("Error: Kelvin cannot be negative.\n");
        return 1;
    }

     if (inputScale == 'C') {
        tempInCelsius = temperature;
    } 
    else if (inputScale == 'F') {
        tempInCelsius = fahrenheit_to_celsius(temperature);
    } 
    else {  // K
        tempInCelsius = kelvin_to_celsius(temperature);
    }

    // Convert Celsius to target scale
    if (targetScale == 'C') {
        convertedTemp = tempInCelsius;
    } 
    else if (targetScale == 'F') {
        convertedTemp = celsius_to_fahrenheit(tempInCelsius);
    } 
    else {  // K
        convertedTemp = celsius_to_kelvin(tempInCelsius);
    }

    printf("\nConverted Temperature: %.2f %c\n", convertedTemp, targetScale);

    categorize_temp(tempInCelsius);

    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (9.0/5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0/9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temp(float celsius) {

    if (celsius < 0) {
        printf("Category: Freezing\n");
        printf("Advisory: Wear multiple layers of winter clothing.\n");
    }

    else if (celsius >= 0 && celsius <= 10) {
        printf("Category: Cold\n");
        printf("Advisory: Wear a jacket or sweatshirt.\n");
    }

    else if (celsius >= 10 && celsius <= 25) {
        printf("Category: Comfortable\n");
        printf("Advisory: The weather is nice, go enjoy it.\n");
    }

    else if (celsius >= 25 && celsius <= 35) {
        printf("Category: Hot\n");
        printf("Advisory: Make sure to drink plenty of water.\n");
    }

    else {
        printf("Category: Extreme Heat\n");
        printf("Advisory: Stay indoors and avoid being outside.\n");
    }
}