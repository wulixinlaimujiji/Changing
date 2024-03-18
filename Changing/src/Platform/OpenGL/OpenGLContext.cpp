#include "chngpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Changing {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CHNG_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CHNG_CORE_ASSERT(status, "Failed to initialize Glad!");

		CHNG_CORE_INFO("OpenGL Info:");
		std::string vendor = reinterpret_cast<const char*>(glGetString(GL_VENDOR));
		CHNG_CORE_INFO("  Vendor: {}", vendor);
		std::string renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
		CHNG_CORE_INFO("  Renderer: {}", renderer);
		std::string version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
		CHNG_CORE_INFO("  Version: {}", version);
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}