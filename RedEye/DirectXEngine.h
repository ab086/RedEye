#pragma once
#include <d3d11.h>


class DirectXEngine {

	public:
		DirectXEngine();

		// Initialize DirectX 11 device
		bool init();
		// Release DirectX 11 device
		bool release();

		~DirectXEngine();

};
