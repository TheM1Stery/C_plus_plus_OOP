#include <iostream>
#include "Smartphone.h"
#include "Laptop.h"
#include <ctime>
int main()
{
	/*Laptop laptop("ROG Zephyrus G", 1337, "ASUS");
	laptop.on();
	laptop.open_browser();
	laptop.toggle_touchpad();*/
	
	Smartphone phone("7 Pro", 1337, "OnePlus");
	phone.on();
	phone.set_alarm(3);

}