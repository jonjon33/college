#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#include"robot.h"

const int HEIGHT = 10;
const int WIDTH = 10;
class world{
private:
	int terrain[WIDTH][HEIGHT];
	robot *bots[WIDTH][HEIGHT];
public:
	void set_up();
	void draw();
	void update();
};

void world::set_up(){
	for(int y = 0; y < HEIGHT;y++){
		for(int x = 0; x < WIDTH; x++){
			bots[x][y] = NULL;
			terrain[x][y] = rand()%3;
		}
	}
	bots[2][2] = new robot(1);
	bots[7][7] = new robot(2);
}
void world::draw(){
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			if(bots[x][y] == NULL)
				cout << (char)(terrain[x][y] + 45; // This bugs me
			else
				bots[x][y] -> draw();
		}
		cout << endl;
	}
	for(int y = 0; y < HEIGHT; y++)
		for(int x = 0; x < WIDTH; x++)
			if(bots[x][y] != NULL){
				bots[x][y]->print();
				bots[x][y]->refresh();
				cout << "\n";
			}
}
void world::update(){
	int tempx,tempy;
	robot *temp;
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			if(bots[x][y] != NULL){
				tempx = x;
				tempy = y;
				bots[x][y] -> move(tempx,tempy);
				if(tempx < 0 || tempx >= WIDTH)
					tempx = x;
				if(tempy < 0 || tempy >= HEIGHT)
					tempy = y;
				if(bots[tempx][tempy] == NULL){
					temp = bots[x][y];
					bots[x][y] = NULL;
					bots[tempx][tempy] = temp;
				}
			}
		}
	}
}
