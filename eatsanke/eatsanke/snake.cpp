#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int N=30,M=20;

int size=32;
int w=size*N,h=size*M;

int dir,num=4;

struct snake{
	int x,y;
}s[1000];

struct fruit{
	int x,y;
}f;


void Tick(){
	if(dir==4) {num+=50; return;}

	for(int i = num;i>0;--i){
		s[i].x = s[i-1].x;
		s[i].y = s[i-1].y;
	}
	
	if(dir==0) s[0].y+=1;
	if(dir==1) s[0].x-=1;
	if(dir==2) s[0].x+=1;
	if(dir==3) s[0].y-=1;

	if((s[0].x==f.x)&&(s[0].y==f.y)){
		num++;
		f.x=rand() % N;
		f.y=rand() % M;
	}

	if(s[0].x>N) s[0].x=0;
	if(s[0].x<0) s[0].x=N;
	if(s[0].y>M) s[0].y=0;
	if(s[0].y<0) s[0].y=M;


	for(int i =1;i<num;++i)
		if(s[0].x==s[i].x&&s[0].y==s[i].y) num=i;


}




int main(int argc,char** argv){
	srand(time(0));
	RenderWindow window(VideoMode(w,h),"new game");
	
	Texture t1,t2;
	t1.loadFromFile("gray.png");
	t2.loadFromFile("green.png");
	
	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Clock clock;
	float timer = 0,delay=0.05;
	f.x=10;
	f.y=10;

	while(window.isOpen()){
		float time = clock.getElapsedTime().asSeconds();
		timer+=time;
		clock.restart();
		
		Event e;
		while(window.pollEvent(e)){
			if(e.type==Event::Closed)
				window.close();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Left)&&dir!=2) dir=1;
		if(Keyboard::isKeyPressed(Keyboard::Right)&&dir!=1) dir=2;
		if(Keyboard::isKeyPressed(Keyboard::Up)&&dir!=0) dir=3;
		if(Keyboard::isKeyPressed(Keyboard::Down)&&dir!=3) dir=0;
		if(Keyboard::isKeyPressed(Keyboard::A)) dir=4;

		if(delay<timer) {timer=0;Tick();}

		window.clear();
		for(int i = 0;i<N;++i)
			for(int j =0;j<M;j++){
				sprite1.setPosition(i*size,j*size);
				window.draw(sprite1);
			}

		for(int i= 0 ;i<num;++i){
			sprite2.setPosition(s[i].x*size,s[i].y*size);
			window.draw(sprite2);
		}

		sprite2.setPosition(f.x*size,f.y*size);
		window.draw(sprite2);

		window.display();
	}


	return 0;
}
