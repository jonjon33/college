#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#include"robot.h"

const int HEIGHT = 19;
const int WIDTH = 80;
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
			terrain[x][y] = rand()%13;
		}
	}
	bots[2][2] = new robot(1);
	bots[7][7] = new robot(2);
	bots[12][12] = new robot(3);
	bots[17][17] = new robot(4);
}
void world::draw(){
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			if(bots[x][y] == NULL)
				switch(terrain[x][y]){

				case 1:
					cout << 'T';
					break;
				case 2:
					cout << '#';
					break;
				default:
					cout << '.';
					break;
				}
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
