// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameClass.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 00:38:22 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/05 00:38:27 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameClass.hpp"

GameClass::GameClass() {

	this->_score = 0;
	this->_bestScore = 0;
	paralaxInit();
	initscr();
	noecho(); // убираем вывод в консоль нажатых клавишь
	curs_set(0); // убираем курсор
	// intit window game
	this->_w = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(this->_w, true); // обрабатываем все нажатия
	nodelay(this->_w, true);
	// intit window score
	this->_s = newwin(8, 20, 0, WIDTH + 1);
	keypad(this->_s, true); // обрабатываем все нажатия
	nodelay(this->_s, true);
	
	ply = new PlayerClass(HEIGHT - 2, WIDTH / 2);
	mvwprintw(this->_w, HEIGHT - 2, WIDTH / 2, "^");

	enemy = new EnemiesClass[HEIGHT];
	intitMap();
	ft_refresh();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, 24, COLOR_BLACK);
}

void	GameClass::intitMap() {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j)
			map[i][j] = 0;
	}
}


GameClass::GameClass(GameClass const &copy) {
	*this = copy;
}

GameClass		&GameClass::operator=(GameClass const &rfs) {
	this->_w = rfs.getWindow();
	return *this;
}

GameClass::~GameClass() {
	delete ply;
	delete [] enemy;
	endwin();
}

WINDOW			*GameClass::getWindow() const {
	return this->_w;
}

void	GameClass::updateBull() {

	for (int i = 0; i < HEIGHT - 1; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (map[i + 1][j] == 1) {
				mvwprintw(_w, i + 1, j, " ");
				map[i][j] = map[i + 1][j];
				map[i + 1][j] = 0;
				mvwprintw(_w, i, j, "|");
			}
		}
	}
	for (int i = 0; i < HEIGHT; ++i) {
		if (enemy[i].get_x() == ply->get_x()
		&& enemy[i].get_y() == ply->get_y()) {
			enemy[i].killEnemi(_w);
			ply->takeDamage();
		}
	}
}


void			GameClass::ft_refresh() {
	ft_generate();
    wattron(_w, COLOR_PAIR(3));
	mvwprintw(_w, 0, 0, "%s", paralax);
    wattroff(_w, COLOR_PAIR(3));
	updateBull();
	ply->update(_w, '^', map);
	for (int i = 0; i < HEIGHT; ++i)
		_score += enemy[i].update(_w, '*', map);
	box(this->_w, 0, 0);
	wrefresh(this->_w);
	mvwprintw(this->_s, 1, 1, "lives: %i", ply->get_lives_point());
	mvwprintw(this->_s, 2, 1, "score: %i", _score);
	if (_score > _bestScore)
		_bestScore = _score;
	mvwprintw(this->_s, 3, 1, "Best score: %i", _bestScore);
	box(this->_s, 0, 0);
	wrefresh(this->_s);
}

int			GameClass::ft_wgetch() {
	int c = 0;
	switch ((c = wgetch(this->_w))) {
		case KEY_LEFT:
			ply->mvleft(_w, '^');
			break;
		case KEY_RIGHT:
			ply->mvright(_w, '^');
			break;
		case KEY_UP:
			ply->mvup(_w, '^');
			break;
		case KEY_DOWN:
			ply->mvdown(_w, '^');
			break;
		case 32:
			ply->shoot(map);
			break;
	}
	return (c);
}

void		GameClass::restart() {
	ply->set_lives_point(0);
	mvwprintw(this->_s, 4, 1, "Game over!");
	mvwprintw(this->_s, 5, 1, "Space: restart");
	mvwprintw(this->_s, 6, 1, "Ecs: exit");
	for (int i = 0; i < HEIGHT; ++i)
		enemy[i].restart();
	_score = 0;
	ft_refresh();
}


void			GameClass::start() {
	int c = 0;

	while (c != 27) {
		int count = 0;
		while (c != 27 && ply->get_lives_point()) {
			c = ft_wgetch();
			if ((count % 5) == 0)
				for (int i = 0; i < HEIGHT; ++i)
					enemy[i].behavior(_w);
			ft_refresh();
			usleep(50000);
			count++;
		}
		restart();
		switch ((c = wgetch(this->_w)) ) {
			case 32:
				ply->set_lives_point(5);
				_score = 0;
				wclear(_w);
				ft_refresh();
				wclear(_s);
				box(this->_s, 0, 0);
				intitMap();
				break;
			case 27:
				return ;
				break;
		}
	}
}

// PARALLAX

void		GameClass::paralaxInit() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			paralax[i][j] = ' ';
		}
	}
}

void	GameClass::ft_generate() {
	for (int i = HEIGHT - 1; i != -1 ; i--) {
		for (int j = 0; j < WIDTH; j++) {
			if (i != 0) {
				paralax[i][j] = paralax[i - 1][j];
			}
		}
	}
	for (int i = 0; i < WIDTH; ++i) {
		if (rand() % 50 == 0)
			paralax[0][i] = '.';
		else
			paralax[0][i] = ' ';
	}
}
