#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(8)
{
	index = glGenLists(primatives);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}



}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(4.0, 0.0, -10.0);
		glVertex3f(4.0, -2.0, -10.0);
		glVertex3f(4.0, -2.0, -10.0);
		glVertex3f(-1.0, 2.0, -9.0);
		glVertex3f(-2.0, -2.0, -9.0);
		glVertex3f(-2.0, -2.0, -9.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0, 2.0, -8.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-2.0, 1.0, -8.0);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0, -1.0, -8.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0, -2.0, -8.0);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0, 1.0, -4.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-2.0, -2.0, -5.0);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(2.0, -2.0, -5.0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0, -1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0); 
		glVertex3f(2.0, -2.0, -5.0);	
	}
	glEnd();
	glEndList();

	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -8.0);
	}
	glEnd();
	glEndList();

}

void Game::update()
{
	cout << "Update up" << endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		glLoadIdentity();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		glTranslatef(0.0001f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		glTranslatef(-0.0001f, 0.0f, 0.0f);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glScalef(1.0f, 1.0f, .999f);
	}

	elapsed = clock.getElapsedTime();

if (elapsed.asSeconds() >= 1.0f)
{
	clock.restart();

	if (!flip)
	{
		flip = true;
		current++;
		if (current > primatives)
		{
			current = 1;
		}
	}
	else
		flip = false;
}

if (flip)
{
	rotationAngle += 0.005f;

	if (rotationAngle > 360.0f)
	{
		rotationAngle -= 360.0f;
	}
}
}

void Game::draw()	
{ 
	cout << "Draw up" << endl; 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 


	//glBegin(GL_TRIANGLES); 
	//{	
	//	glPointSize(20.0f);
	//	glVertex3f(0.0, 2.0, -5.0); 
	//	glVertex3f(-2.0, -2.0, -5.0); 
	//	glVertex3f(2.0, -2.0, -5.0);	
	//} 

	glPointSize(30.0f);

	
	//glBegin(GL_LINES);
	//{
	//	glColor3f(1.0f, 0.0f, 0.0f);
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//}



	

	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(1.0f, 0.0f, 0.0f);
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glVertex3f(2.0, -2.0, -5.0);


	//	glColor3f(0.0f, 1.0f, 0.0f);
	//	glVertex3f(1.0, 1.0, -7.0);
	//	glVertex3f(-1.0, -1.0, -7.0);
	//	glVertex3f(1.0, -1.0, -7.0);
	//}

	//glBegin(GL_TRIANGLE_STRIP);
	//{
	//	glColor3f(1.0f, 0.0f, 0.0f);
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glColor3f(0.0f, 0.0f, 1.0f);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glColor3f(0.0f, 1.0f, 0.0f);
	//	glVertex3f(2.0, -2.0, -5.0);


	//	//glColor3f(0.0f, 1.0f, 0.0f);
	//	//glVertex3f(1.0, 1.0, -7.0);
	//	//glVertex3f(-1.0, -1.0, -7.0);
	//	//glVertex3f(1.0, -1.0, -7.0);
	//}

	//glBegin(GL_TRIANGLE_FAN);
	//{
	//	glColor3f(1.0f, 0.0f, 0.0f);
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glColor3f(0.0f, 0.0f, 1.0f);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glColor3f(0.0f, 1.0f, 0.0f);
	//	glVertex3f(2.0, -2.0, -5.0);
	//}

	

	//glBegin(GL_QUAD_STRIP);
	//{
	//	glColor3f(1.0f, 0.0f, 0.0f);
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glColor3f(0.0f, 0.0f, 1.0f);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glColor3f(0.0f, 1.0f, 0.0f);
	//	glVertex3f(2.0, -2.0, -5.0);
	//	glColor3f(0.0f, 0.0f, 0.0f);
	//	glVertex3f(1.0, -1.0, -5.0);
	//}
 
	glCallList(current);

	window.display(); 
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}


