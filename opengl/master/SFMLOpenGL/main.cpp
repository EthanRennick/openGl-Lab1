#include <Game.h>
// <summary> /// Change 1 Add GL.H and Glu.h /// This hooks up OpenGL with our Game /// </summary> 
 #include <gl/GL.h> 
 #include <gl/GLU.h> 
using namespace std;

int main(void)
{
	Game& game = Game();
	game.run();
}