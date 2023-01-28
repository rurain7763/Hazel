#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::createApplication();

int main(int argc, char** argv)
{
	Hazel::Log::init();
	HZ_CORE_WARN("init success");
	int a = 10;
	HZ_INFO("hello var={0}", a);

	auto app = Hazel::createApplication();
	app->run();
	delete app;
}

#endif