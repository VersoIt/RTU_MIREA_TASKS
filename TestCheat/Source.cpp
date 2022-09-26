#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	int score_pointer = 0x0230616C; // score pointer
	int pointer_offset = 0x738; // score offset
	int score_to_write = 100;

	cout << "Hack" << endl;

	DWORD score = static_cast<DWORD>(pointer_offset + score_pointer);
	HWND hwnd = FindWindowA(NULL, "Логика");

	if (hwnd == NULL)
	{
		cout << "Cannot find a game!" << endl;
		return EXIT_FAILURE;
	}
	
	DWORD process_id;
	GetWindowThreadProcessId(hwnd, &process_id);

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id);

	if (process_id == NULL)
	{
		cout << "Cannot obtain process!" << endl;
		return EXIT_FAILURE;
	}

	for (;;)
	{
		WriteProcessMemory(handle, (PBYTE*)score, &score_to_write, sizeof(score_to_write), 0);
		Sleep(1000);
	}

	return EXIT_SUCCESS;
}