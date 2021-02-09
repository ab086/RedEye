#pragma once
#include <Windows.h>

class Window {

	public:
		Window();

		// Initialize Window
		bool init();
		bool broadcast();

		// Release Window
		bool release();
		bool isRunning();

		// Events
		virtual void onCreate();
		virtual void onUpdate();
		virtual void onDestroy();

		~Window();

	protected:
		HWND m_hwnd;
		bool m_isRunning;
};

