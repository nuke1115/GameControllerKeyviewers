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
ini���� �ε� ��� �Ἥ Ű ���� �����ϰ� �ϱ�
�ܼ� â �����
�����͸�
*/