#pragma once

class Level
{
protected:
	Level();
	virtual ~Level() = default;

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
	
public:
	void Clear_Resources();
	unsigned int GetLevelIndex() const { return m_iLevelIndex; };

protected:
	class CGameInstance* m_pGameInstance = { nullptr };
	unsigned int   		 m_iLevelIndex = { 0 };

public:
	virtual void Free();
};

