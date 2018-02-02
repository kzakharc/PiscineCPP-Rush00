// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlayerClass.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 13:14:04 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/05 13:14:05 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PlayerClass.hpp"

PlayerClass::PlayerClass() {
	lives_point = 5;
	// bull = NULL;
}

PlayerClass::PlayerClass(int y, int x) {
	_y = y;
	_x = x;
	lives_point = 5;
}

PlayerClass::PlayerClass(PlayerClass const &copy) {
	*this = copy;
}

PlayerClass &PlayerClass::operator=(PlayerClass const &rfs) {
	this->_x = rfs.get_x();
	this->_y = rfs.get_y();
	this->lives_point = rfs.get_lives_point();
	return *this;
}

int 		PlayerClass::get_lives_point() const {
	return this->lives_point;
}

void 	PlayerClass::set_lives_point(int point) {
	this->lives_point = point;
	_x = WIDTH / 2;
	_y = HEIGHT - 2;
}

void		PlayerClass::shoot(int map[HEIGHT][WIDTH]) {
	map[_y][_x] = 1;
}

int		PlayerClass::update(WINDOW *w, char c, int map[HEIGHT][WIDTH]) {
	if (lives_point && map[_y][_x]) {
		map[_y][_x] = 0;
		lives_point--;
	}
	if (lives_point < 1) {
		wattron(w, COLOR_PAIR(2));
		mvwprintw(w, _y, _x, "%c", 'x');
		wattroff(w, COLOR_PAIR(2));
	}
	else {
		wattron(w, COLOR_PAIR(2));
		mvwprintw(w, _y, _x, "%c", c);
		wattroff(w, COLOR_PAIR(2));
	}
	return (0);
}

void		PlayerClass::takeDamage() {
	lives_point--;
	_y = HEIGHT - 2;
	_x = WIDTH / 2;
}


// void	PlayerClass::shoot() {
// 	if (!bull) {
// 		bull = new Bullet(_y, _x);
// 	}
// 	else
// 		bull->addBull(_y, _x);
// }
// void	PlayerClass::updateBull(WINDOW *w) {
// 	if (bull)
// 		bull->changePos(w);
// }