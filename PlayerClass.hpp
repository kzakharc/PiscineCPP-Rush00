// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlayerClass.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 13:13:57 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/05 13:13:59 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PISCINE_CPP_PLAYERCLASS_HPP
#define PISCINE_CPP_PLAYERCLASS_HPP

# include "Object.hpp"

class   PlayerClass : public AObject {

private:
	int 	lives_point;
public:

	// void	updateBull(WINDOW *w, int map[HEIGHT][WIDTH]);
	PlayerClass();
	PlayerClass(int y, int x);
	PlayerClass(PlayerClass const &copy);
	~PlayerClass() {};
	PlayerClass &operator=(PlayerClass const & rfs);

	void 	set_lives_point(int point);
	int		get_lives_point() const;
	void	shoot(int map[HEIGHT][WIDTH]);
	int		update(WINDOW *w, char c, int map[HEIGHT][WIDTH]);
	void	takeDamage();

};

#endif
