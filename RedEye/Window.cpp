#include "Window.h"

Window::Window() {

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

	switch(msg) {
	case WM_CREATE: {
		// Create the window
		// Collect and store for later use
		Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
		window->onCreate();
		break;
	}
		

	case WM_DESTROY: {
		// Destroy the window
		Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->onDestroy();
		::PostQuitMessage(0);
		break;
	}

	default: {
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}
	}

	return NULL;
}

bool Window::init() {

	// Set up WNDCLASSEX object
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"WindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	// If class registration fails, kill function
	if(!::RegisterClassEx(&wc)) {
		return false;
	}

	// Create the window
	// Begin CreateWindowEx
	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
								wc.lpszClassName, 
								L"Vulkan Application", 
								WS_OVERLAPPEDWINDOW, 
								CW_USEDEFAULT, 
								CW_USEDEFAULT, 
								1024, 
								768, 
								NULL, 
								NULL, 
								NULL, 
								this);
	// End CreateWindowEx

	// If create window fails, kill function
	if(!m_hwnd) {
		return false;
	}

	// Display the window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	// Set window running to true
	m_isRunning = true;

	return true;
}

bool Window::broadcast() {
	MSG msg;

	while(::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0) {

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	this->onUpdate();

	Sleep(1);

	return true;
}

bool Window::release() {

	// Destroy the window
	if(m_hwnd) {
		::DestroyWindow(m_hwnd);
		return false;
	} else {
		// If this gets returned, something went wrong
		return true;
	}
}

bool Window::isRunning() {
	return m_isRunning;
}

void Window::onCreate() {

}

void Window::onUpdate() {

}

void Window::onDestroy() {
	m_isRunning = false;
}

Window::~Window() {

}
