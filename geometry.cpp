#include <iostream>
//#include <Windows.h>
#define Pi 3.14
/* Реализовать абстрактный базовый класс «Фигура», содержащий методы вычисления площади и метод show()
для отображения информации об объекте. Построить производные классы Square (квадрат), Circle (окружность), 
Rectangle (прямоугольник), содержащие методы для вычисления площади фигур. Создать массив указателей на объекты
базового класса и заполнить этот массив объектами производных классов. Продемонстрировать работу виртуальных методов
базового класса при проходе по этому массиву.  */ 
typedef struct Point {
	int x;
	int y;
} Point;

class figure {
public:
	figure(){
		p1.x = 0;
		p1.y = 0;
		squarearea = 0;
	}
	figure(int x, int y) {
		p1.x = x;
		p1.y = y;
		squarearea = 0;
	}
	~figure();
	figure(const figure &f){
		p1.x = f.p1.x;
		p1.y = f.p1.y;
		squarearea = f.squarearea;
	}
	void set(int x, int y){
		p1.x = x;
		p1.y = y;
	}
	void setsq(double S){
		squarearea = S;
	}
	double getsq(){
		return squarearea;
	}
	int getx(){
		return p1.x;
	}
	int gety(){
		return p1.y;
	}
	virtual void showfigureparam(){
		std::cout << "Starting point of figure: (" << p1.x << ";" << p1.y << ")" << std::endl << "Square of figure: " << squarearea << std::endl;
	}
	virtual void calculsquare(){

	}
private:
	Point p1;
	double squarearea;
};

// если конструкторы в производном классе неопределены, при создании объекта сработает конструктор без аргументов базового класса

class Rectangle : public figure {
public:
	Rectangle() : figure(){
		width = 0;
		height = 0;
	}
	Rectangle(int w, int h) : figure(){
		width = w;
		height = h;
	}
	Rectangle(int x, int y, int w, int h) : figure(x, y){
		width = w;
		height = h;
	}

	Rectangle(Rectangle &R){
		width = R.width;
		height = R.height;
		set(R.getx(), R.gety());
		setsq(R.getsq());
	}

	~Rectangle() {

	}
	void showfigureparam(){
		figure::showfigureparam();
		std::cout << "Width of Rectangle: " << width << std::endl << "Height of Rectangle: " << height << std::endl;
	}
	void calculsquare(){
		setsq(width*height);
	}
private:
	int width;
	int height;
};

class Square : public  figure {
public:
	Square() : figure(){
		edge = 0;
	}
	Square(int e) : figure(){
		edge = e;
	}
	Square(int x, int y, int e) : figure(x, y){
		edge = e;
	}
	Square(Square &S){
		edge = S.edge;
		set(S.getx(), S.gety());
		setsq(S.getsq());
	}
	~Square() {

	}
	void showfigureparam(){
		figure::showfigureparam();
		std::cout << "Edge of Square: " << edge << std::endl;
	}
	void calculsquare(){
		setsq(edge*edge);
	}
private:
	int edge;
};

class Circle : public figure {
public:
	Circle(){
		Radius = 0;
	}
	Circle(int R){
		Radius = R;
	}
	Circle(int x, int y, int R) : figure(x, y){
		Radius = R;
	}
	Circle(Circle &C){
		Radius = C.Radius;
		set(C.getx(), C.gety());
		setsq(C.getsq());
	}
	void showfigureparam(){
		figure::showfigureparam();
		std::cout << "Radius of Circle: " << Radius << std::endl;
	}
	void calculsquare(){
		setsq(Pi*Radius*Radius);
	}
private:
	int Radius;
};

int main(){
	figure * geometry[9];
	for (int i = 0; i < 3; i++){
		geometry[i] = new Rectangle(0, 0, 3, 4);
	}
	for (int i = 3; i < 6; i++){
		geometry[i] = new Circle(0, 0, 74);
	}
	for (int i = 6; i < 9; i++){
		geometry[i] = new Square(0, 0, 11);
	}
	for (int i = 0; i < 9; i++){
		geometry[i]->calculsquare();
		geometry[i]->showfigureparam();
	}
	system("PAUSE");
	return 0;
}
