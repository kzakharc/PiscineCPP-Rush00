// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EnemiesClass.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 13:11:04 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/05 13:11:05 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef PISCINE_CPP_ENEMIESCLASS_HPP
#define PISCINE_CPP_ENEMIESCLASS_HPP

#include "ft_retro.hpp"
#include "Object.hpp"

class 	EnemiesClass :  public AObject {

	int		_live;// = 1;

public:

	EnemiesClass();
	// EnemiesClass(WINDOW *w);
	EnemiesClass(EnemiesClass const &copy);
	~EnemiesClass(); // write
	EnemiesClass &operator=(EnemiesClass const & rfs);
	void		behavior(WINDOW *_w);
	void		killEnemi(WINDOW *_w);
	int			update(WINDOW *w, char c, int map[HEIGHT][WIDTH]);
	void		restart();

};

#endif //PISCINE_CPP_ENEMIESCLASS_HPP
