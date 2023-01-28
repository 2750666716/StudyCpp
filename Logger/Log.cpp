#include <iostream>

//日志类
//有 error、warning、info三个等级
class Log
{
public:
	enum LogLevel
	{
		LevelError = 0, LevelWarning, LevelInfo
	};


private:
	//log等级
	LogLevel m_LogLevel = LevelInfo;

public:
	void SetLevel(LogLevel level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]:" << message << std::endl;
	}

	void Warning(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]:" << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]:" << message << std::endl;
	}
};

int main()
{
	Log log;
	log.SetLevel(log.LevelError);
	log.Warning("Hello");
	log.Error("Hello");
	log.Info("Hello");


}