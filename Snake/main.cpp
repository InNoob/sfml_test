//
//  main.cpp
//  Snake
//
//  Created by jason bourne on 2017/8/25.
//
//

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int N=30,M=20;
int size=16;
int w = size*N;
int h = size*M;

int main()
{
    RenderWindow window(VideoMode(w,h),"SnakeGame!");
    
    Texture t1,t2;
    t1.loadFromFile("img/gray.png");
    t2.loadFromFile("img/red.png");
    
    Sprite sprite1(t1);
    Sprite sprite2(t2);
    
    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if(e.type==Event::Closed)
                window.close();
        }
        window.clear();
        
        for (int i = 0; i<N; i++) 
            for (int j = 0; j<M; j++) 
            {
                sprite1.setPosition(i*size,j*size);
                window.draw(sprite1);
            }
        window.display();
    }
    
    
    return 0;
}
