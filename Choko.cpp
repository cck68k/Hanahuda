#include"Choko.h"
#include<iostream>

unsigned int keystate_left;
unsigned int keystate_up;
unsigned int keystate_right;
unsigned int keystate_down;
unsigned int keystate_1;
unsigned int keystate_2;
unsigned int keystate_3;
unsigned int keystate_4;
unsigned int keystate_5;
unsigned int keystate_6;
unsigned int keystate_7;
unsigned int keystate_8;
unsigned int keystate_9;
unsigned int keystate_10;

int mousex;
int mousey;
unsigned int click_left;
unsigned int click_right;

int graph_cursor;

double GetFps(){
	static double fps = 0.f;
	static unsigned int counter = 0;
	static unsigned int time = 0;
	static unsigned int time_save = 0;
	if (counter == 0)
		time_save = GetNowCount();
	if (counter == 60){
		time = GetNowCount();//�~���b���x����int�^
		fps = 1000.0f / ((time - time_save) / 60.0f);
		counter = 0;
	}
	else{
		counter++;
	}//ifelse���͕���Dcounter��0��������else�ȉ��͔�΂����

	return fps;
}

void FpsControll(){
	static unsigned int counter = 0;
	static unsigned int time = 0;
	if (counter == 30){//every 30 frames
		while ((GetNowCount() - time) < 500){}
		counter = 0;
	}
	if (counter == 0)time = GetNowCount();
	counter++;
}

void InputReceive(){
	int joypad1input = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if ((joypad1input & PAD_INPUT_LEFT) == OFF){
		keystate_left = 0;
	}
	else{
		keystate_left++;
	}
	if ((joypad1input & PAD_INPUT_UP) == OFF){
		keystate_up = 0;
	}
	else{
		keystate_up++;
	}

	if ((joypad1input & PAD_INPUT_RIGHT) == OFF){
		keystate_right = 0;
	}
	else{
		keystate_right++;
	}

	if ((joypad1input & PAD_INPUT_DOWN) == OFF){
		keystate_down = 0;
	}
	else{
		keystate_down++;
	}

	if ((joypad1input & PAD_INPUT_1) == OFF){
		keystate_1 = 0;
	}
	else{
		keystate_1++;
	}
	if ((joypad1input & PAD_INPUT_2) == OFF){
		keystate_2 = 0;
	}
	else{
		keystate_2++;
	}
	if ((joypad1input & PAD_INPUT_3) == OFF){
		keystate_3 = 0;
	}
	else{
		keystate_3++;
	}
	if ((joypad1input & PAD_INPUT_4) == OFF){
		keystate_4 = 0;
	}
	else{
		keystate_4++;
	}
	if ((joypad1input & PAD_INPUT_5) == OFF){
		keystate_5 = 0;
	}
	else{
		keystate_5++;
	}
	if ((joypad1input & PAD_INPUT_6) == OFF){
		keystate_6 = 0;
	}
	else{
		keystate_6++;
	}
	if ((joypad1input & PAD_INPUT_7) == OFF){
		keystate_7 = 0;
	}
	else{
		keystate_7++;
	}
	if ((joypad1input & PAD_INPUT_8) == OFF){
		keystate_8 = 0;
	}
	else{
		keystate_8++;
	}
	if ((joypad1input & PAD_INPUT_9) == OFF){
		keystate_9 = 0;
	}
	else{
		keystate_9++;
	}
	if ((joypad1input & PAD_INPUT_10) == OFF){
		keystate_10 = 0;
	}else{
		keystate_10++;
	}

	GetMousePoint(&mousex, &mousey);

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
		click_left++;
	}else{
		click_left = 0;
	}

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		click_right++;
	}else {
		click_right = 0;
	}
}

void InputDistribute(unsigned int& keystate, unsigned int keyconfig){
	switch (keyconfig){
	case 1:keystate = keystate_1; break;
	case 2:keystate = keystate_2; break;
	case 3:keystate = keystate_3; break;
	case 4:keystate = keystate_4; break;
	case 5:keystate = keystate_5; break;
	case 6:keystate = keystate_6; break;
	case 7:keystate = keystate_7; break;
	case 8:keystate = keystate_8; break;
	case 9:keystate = keystate_9; break;
	case 10:keystate = keystate_10; break;
	default:break;
	}
}

int CursorLoad(const char *filename) {
	int result = LoadGraph(filename);
	if (result == -1) {
		return -1;
	}else{
		graph_cursor = result;
		return 0;
	}
}

void CursorDraw() {
	DrawGraph(mousex, mousey, graph_cursor, TRUE);
}

void Wait(){
	int waiter = -1;

	while (waiter != 0){
		std::cout << "Continue to input 0" << std::endl;
		std::cin >> waiter;
	}
}

/*
�z��������ɂƂ�
�E�z��ϐ��̖��O�����n��
�E[]�󊇌ʂł����Ƃ�;���̂��炩���������̓|�C���^

SignRand�֐���SelectUnused�֐��̕Ԃ�l��const�ɂ�����error LNK 2019 (��`��������Ȃ�)���o���D

int FileReadLine(int filehandle,const int charmax){
char chara[charmax];//�G���[�F�����͖��x�ς�邩��const�Ƃ͂�������
*/
/*
char* const FileReadLine(int filehandle){
char chara[100];
if (filehandle == NULL)return chara;//chara��Ԃ����Ƃ���ŃA�h���X���������Astatic�́H
for (int i = 0; i < 100 && FileRead_getc(filehandle) != '\n'; i++)
chara[i] = FileRead_getc(filehandle);
return chara;//�A�h���X��Ԃ��Ă�̂ɕԂ�l�Ƀ|�C���^�H
}

int FileReadSkip(const int filehandle,const int number_of_row){
if (filehandle == NULL)return -1;
for (int i = 0; i<number_of_row; i++)
while (FileRead_getc(filehandle) != '\n');
return 0;
}

int SelectUnused(unsigned int max, unsigned int arr[]){//���̂̓|�C���^������ const int const �ɂ�����~?
for (unsigned int number = 0; number < max; number++){
if (arr[number] == OFF){
return number;
}
}
return -1;
}
*/
