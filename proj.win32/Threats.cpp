#include "Functions.h"

void pause_thread(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	//std::cout << "pause of " << n << " seconds ended\n";
}
void stopMusic() {
	PlaySound(NULL, NULL, 0);
}
void Music(string n)
{
	n += ".wav";
	n = "Musica/" + n;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wide = converter.from_bytes(n);
	LPCWSTR result = wide.c_str();
	PlaySound(result, NULL, SND_ASYNC);
}
void musica()
{
	PlaySound(TEXT("Musica/Ohayou Sayori!.wav"), NULL, SND_ASYNC);
}