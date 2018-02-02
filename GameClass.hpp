// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameClass.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 00:38:33 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/05 00:38:35 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PISCINE_CPP_GAMECLASS_HPP
# define PISCINE_CPP_GAMECLASS_HPP

#include "ft_retro.hpp"
#include "Object.hpp"
#include "PlayerClass.hpp"
#include "EnemiesClass.hpp"

class AObject;
class   PlayerClass;
// class   EnemiesClass;

class	GameClass {

private:

	WINDOW		*_w;
	WINDOW		*_s;
	int 		_score;
	int 		_bestScore;
	PlayerClass *ply;
	EnemiesClass *enemy;
	char		paralax[HEIGHT][WIDTH];
	void		ft_refresh();
	int			ft_wgetch();
	int			map[HEIGHT][WIDTH];
	void		intitMap();
	void		updateBull();
	void		restart();
	void		paralaxInit();
	void		ft_generate();
public:
	GameClass();
	GameClass(GameClass const &copy);
	~GameClass();

	GameClass 		&operator=(GameClass const & rfs);
	WINDOW 			*getWindow() const; 	//return from  WINDOW *inits();
	void			start();
};

static int 		max_score;				//for store last max score

#endif //PISCINE_CPP_GAMECLASS_HPP
