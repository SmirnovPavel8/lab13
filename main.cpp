#include <SFML/Graphics.hpp>
#include <Scene.hpp>

int main()
{
	std::setlocale(LC_ALL, "Russian");
	int N, N1;
	std::cout << "введите число шаров ";
	std::cin >> N;
	std::cout<<std::endl<<"введите число колеблющихся шаров ";
	std::cin >> N1;
	mt::Scene scene(1920, 1080,N,N1);
	scene.LifeCycle();
	return 0;
}
