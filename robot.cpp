#include <Windows.h>
#include <gl/GL.h>
#include <Math.h>
#include <gl/GLU.h>

#define WINDOW_TITLE "Practical Assignment Robot"

float LAangle = 0;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		else if (wParam == 'Q')//press key 1
			LAangle += 10;
		else if (wParam == 'W')//press key 1
			LAangle -= 10;
			break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void balljoint(float r) {
	GLUquadricObj* sphere = NULL;	
	sphere = gluNewQuadric();	
	gluQuadricDrawStyle(sphere, GLU_FILL);	
	gluSphere(sphere, r, 30, 30);
	gluDeleteQuadric(sphere);
}

void palm() {
	glBegin(GL_QUADS);
	//front
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0.4, 0, 0);
	glVertex3f(0.4, 0, 0.5);
	glVertex3f(0, 0, 0.5);
	//left
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, 0.1, 0.5);
	glVertex3f(0, 0.1, 0);
	glVertex3f(0, 0, 0);
	//base
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0.4, 0, 0);
	glVertex3f(0.4, 0.1, 0);
	glVertex3f(0, 0.1, 0);
	//back
	glColor3f(1, 1, 0);
	glVertex3f(0, 0.1, 0);
	glVertex3f(0, 0.1, 0.5);
	glVertex3f(0.4, 0.1, 0.5);
	glVertex3f(0.4, 0.1, 0);
	//right
	glColor3f(1, 0, 1);
	glVertex3f(0.4, 0.1, 0);
	glVertex3f(0.4, 0, 0);
	glVertex3f(0.4, 0, 0.5);
	glVertex3f(0.4, 0.1, 0.5);
	//up
	glColor3f(0, 1, 1);
	glVertex3f(0.4, 0.1, 0.5);
	glVertex3f(0.4, 0, 0.5);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, 0.1, 0.5);
	glEnd();
}

void upperArm() {
	glBegin(GL_QUADS);
	//front
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 0.12);
	glVertex3f(0.2, 0, 0.12);
	glVertex3f(0.2, 0, 0);
	//left
	glColor3f(0, 1, 0);
	glVertex3f(0.2, 0, 0);
	glVertex3f(0.2, 0, 0.12);
	glVertex3f(0.2, 0.12, 0.12);
	glVertex3f(0.2, 0.12, 0);
	//base
	glColor3f(0, 0, 1);
	glVertex3f(0.2, 0.12, 0);
	glVertex3f(0.2, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.12, 0);
	//back
	glColor3f(1, 1, 0);
	glVertex3f(0, 0.12, 0);
	glVertex3f(0.2, 0.12, 0);
	glVertex3f(0.2, 0.12, 0.12);
	glVertex3f(0, 0.12, 0.12);
	//right
	glColor3f(1, 0, 1);
	glVertex3f(0, 0.12, 0.12);
	glVertex3f(0, 0.12, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 0.12);
	//up
	glColor3f(0, 15, 15);
	glVertex3f(0, 0, 0.12);
	glVertex3f(0, 0.12, 0.12);
	glVertex3f(0.2, 0.12, 0.12);
	glVertex3f(0.2, 0, 0.12);
	glEnd();
}

void lowerArm() {
	glBegin(GL_QUADS);
	//front
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 0.1);
	glVertex3f(0.22, 0, 0.1);
	glVertex3f(0.22, 0, 0);
	//left
	glColor3f(0, 1, 0);
	glVertex3f(0.22, 0, 0);
	glVertex3f(0.22, 0, 0.1);
	glVertex3f(0.22, 0.1, 0.1);
	glVertex3f(0.22, 0.1, 0);
	//base
	glColor3f(0, 0, 1);
	glVertex3f(0.22, 0.1, 0);
	glVertex3f(0.22, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.1, 0);
	//back
	glColor3f(1, 1, 0);
	glVertex3f(0, 0.1, 0);
	glVertex3f(0.22, 0.1, 0);
	glVertex3f(0.22, 0.1, 0.1);
	glVertex3f(0, 0.1, 0.1);
	//right
	glColor3f(1, 0, 1);
	glVertex3f(0, 0.1, 0.1);
	glVertex3f(0, 0.1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 0.1);
	//up
	glColor3f(0, 1, 1);
	glVertex3f(0, 0, 0.1);
	glVertex3f(0, 0.1, 0.1);
	glVertex3f(0.22, 0.1, 0.1);
	glVertex3f(0.22, 0, 0.1);
	glEnd();
}

void leftarm() {//left arm
	
	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	//glRotatef(180, 1, 0, 0);(add for right arm)

	//upperarm
	glPushMatrix();
		glTranslatef(-0.2, -0.01, -0.01);
		upperArm();
	glPopMatrix();

	//balljoint
	glPushMatrix();
		glTranslatef(0, 0.05, 0.05);
		balljoint(0.05);
	glPopMatrix();

	//lowerarm move
	glPushMatrix();
	glRotatef(LAangle, 0, 0, 1);
		lowerArm();

	//balljoint
	glPushMatrix();
	glTranslatef(0.22, 0.05, 0.05);
	balljoint(0.05);
	glPopMatrix();

	//palm
	glPushMatrix();
		glTranslatef(0.22, 0.1, 0.05);
		glRotatef(90, 1, 0, 0);
		glScalef(0.2, 0.2, 0.2);
		palm();
	glPopMatrix();

	glPopMatrix();//loweraem move

	glPopMatrix();
}

void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	//glRotatef(0.1, 1, 1, 1);
	glPushMatrix();
	glRotatef(120, 1, 1, 1);
	leftarm();
	glPopMatrix();



}

//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 900, 900,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------