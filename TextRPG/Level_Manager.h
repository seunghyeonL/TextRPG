#pragma once

class Level_Manager final
{
private:
	Level_Manager();
	virtual ~Level_Manager() = default;

public:
	void Initialize();
	void Update();
	void Render();

public:
	void Change_Level(class Level* pNewLevel);
	
	class Level* Get_Level() { return m_pCurrentLevel; };

private:
	class Level* m_pCurrentLevel{ nullptr };
	unsigned int m_iLevelIndex{ 0 };

public:
	static Level_Manager* Create();
	virtual void Free();
};
