#include "Engine.h"

int main(int carg, char **arg)
{
	Engine::Initialize(1024,768,"Argentum Online");
	Engine::Run();

    return 0;
}
