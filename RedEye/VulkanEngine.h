#pragma once

class VulkanEngine {

	public:
		VulkanEngine();

		// Initialize Vulkan device
		bool init();
		// Release Vulkan device
		bool release();

		~VulkanEngine();

};
