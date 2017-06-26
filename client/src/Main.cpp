#include "Engine.h"

class TestGameObject : public GameObject
{
  public:
	TestGameObject() : GameObject(){};

	void Update(float deltaTime) override
	{
		DEBUG_LOG("HOLDE DON JOSE");
	};

	void LateUpdate(float deltaTime) override
	{
		DEBUG_LOG("Hola Pepe");
	};
};

class InitializeObject : public GameObject
{
  public:
	InitializeObject() : GameObject()
	{
		m_index = 0;
		test = nullptr;
		//test = GameObject::Instantiate<TestGameObject>();
	};

	void Update(float deltaTime) override
	{
		DEBUG_LOG("HOLA AMIGOS");
		if (test == nullptr)
			test = GameObject::Instantiate<TestGameObject>();
	};

	void LateUpdate(float deltaTime) override
	{

		if ((m_index % 2) == 0)
			if (test != nullptr)
				GameObject::Destroy(test);

		m_index++;
		//auto tmp = this;
		//GameObject::Destroy(tmp);
		//if(test != nullptr)
		//GameObject::Destroy(test);
	};

  private:
	TestGameObject *test;
	int m_index;
};

int main(int carg, char **arg)
{
	Engine::Initialize(1024, 768, "Argentum Online");
	//GameObject::Instantiate<InitializeObject>();
	Engine::Run();

	return 0;
}
