#include "..\headers\Application.h"



int main()
{
	Application application(960,540,"keyviewer test");
	int returnCode = application.Initialize();
	if (!returnCode)
	{
		application.Run();
	}

	return 0;
}
/*
todo
ini파일 로드 헤더 써서 키 변경 가능하게 하기
콘솔 창 지우기
리펙터링
*/