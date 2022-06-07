#include <SFML/Graphics.hpp>
#include <Scene.hpp>

int main()
{
	int N, N1;
	std::cin >> N >> N1;
	mt::Scene scene(1920, 1080,N,N1);
	scene.LifeCycle();
	return 0;
}
