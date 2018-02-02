// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EnemiesClass.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 13:10:57 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/05 13:10:58 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "EnemiesClass.hpp"

EnemiesClass::EnemiesClass() {
	_y = -(rand() % HEIGHT);
	_x = (rand() % (WIDTH - 4)) + 2;
	_live = 1;
}

EnemiesClass::EnemiesClass(EnemiesClass const &copy) {
 	*this = copy;
}

EnemiesClass &EnemiesClass::operator=(EnemiesClass const &rfs) {
 	this->_x = rfs.get_x();
 	this->_y = rfs.get_y();
 	return *this;
}

void EnemiesClass::behavior(WINDOW *_w) {
	static int tmp;

	if (_live) {
		if (tmp % 9 == 0 || tmp % 9 == 1 || tmp % 9 == 2 || tmp % 9 == 3 || tmp % 9 == 4) {
			mvwprintw(_w, _y, _x, " ");
			_x = (_x) % (WIDTH - 2) + 1;
            _y = (_y) % (HEIGHT - 2) + 1;
            mvwprintw(_w, _y, _x, "%c", '*');
        }
        else {
            mvwprintw(_w, _y, _x, " ");
            _x = ((_x - 1) % (WIDTH - 2));
            if (_x < 1)
                _x = (WIDTH - 2) + _x;
            _y = (_y) % (HEIGHT - 2) + 1;
            mvwprintw(_w, _y, _x, "%c", '*');
        }
		tmp++;
		if (_y == HEIGHT)
			killEnemi(_w);
	}
	else {
		restart();
	}
}

void EnemiesClass::killEnemi(WINDOW *_w) {
	_live = 0;
	mvwprintw(_w, _y, _x, " ");
}

EnemiesClass::~EnemiesClass() {

}

void		EnemiesClass::restart() {
	_y = -(rand() % HEIGHT);
	_x = (rand() % (WIDTH - 4)) + 2;
	_live = 1;

}


int		EnemiesClass::update(WINDOW *w, char c, int map[HEIGHT][WIDTH]) {
	if (_y > -1 && _live && map[_y][_x] == 1) {
		map[_y][_x] = 0;
		mvwprintw(w, _y, _x, " ");
		_live--;
		return (1);
	}
	if (_live) {
        wattron(w, COLOR_PAIR(1));
        mvwprintw(w, _y, _x, "%c", c);
        wattroff(w, COLOR_PAIR(1));
    }
	return (0);
}
