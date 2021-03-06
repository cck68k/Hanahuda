#pragma once
#include"Scene.h"


class ResultScene : public Scene{
private:
	int graph_fusuma_left;
	int graph_fusuma_right;

	int count;
	int leftx_limit;
	int rightx_limit;

	bool isclosing;

	int gamenum;
	int teban;
	int score_player0;
	int score_player1;

	int winner;

public:
	ResultScene(int _gamenum, int _teban, int _score_player0, int _score_player1);
	~ResultScene();

	int Update();
	void Draw();
};
