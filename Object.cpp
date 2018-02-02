// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Object.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 14:48:27 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/05 14:48:28 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

# include "Object.hpp"

AObject::AObject(int y, int x) {
	_y = y;
	_x = x;
}

void        AObject::mvleft(WINDOW *w, char c) {
	// mvwprintw(w, 10, 0, "HERE%c", c);
	mvwprintw(w, _y, _x, " ");
	_x = ((_x - 1) % (WIDTH - 2));
	if (_x < 1)
		_x = (WIDTH - 2) + _x;
	mvwprintw(w, _y, _x, "%c", c);
}

void        AObject::mvright(WINDOW *w, char c) {
	mvwprintw(w, _y, _x, " ");
	_x = (_x) % (WIDTH - 2) + 1;
	mvwprintw(w, _y, _x, "%c", c);
}

void        AObject::mvup(WINDOW *w, char c) {
	mvwprintw(w, _y, _x, " ");
	_y = ((_y - 1) % (HEIGHT - 2));
	if (_y < 1)
		_y = (HEIGHT - 2) + _y;
	mvwprintw(w, _y, _x, "%c", c);
}

void		AObject::mvdown(WINDOW *w, char c) {
	mvwprintw(w, _y, _x, " ");
	_y = (_y) % (HEIGHT - 2) + 1;
	mvwprintw(w, _y, _x, "%c", c);
}

AObject::AObject(AObject const &copy) {
	*this = copy;
}

AObject &AObject::operator=(AObject const &rfs) {
	this->_x = rfs.get_x();
	this->_y = rfs.get_y();
	return *this;
}

int			AObject::get_x() const {
 	return (_x);
}

int			AObject::get_y() const {
	 return (_y);
}

// void	Object::repaint(WINDOW *w) {
// 	mvwprintw(this->_w, 3, p, "%s", "^");
// }
