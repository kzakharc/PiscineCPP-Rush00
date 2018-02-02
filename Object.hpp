// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Object.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 14:48:17 by kzakharc          #+#    #+#             //
//   Updated: 2017/11/05 14:48:18 by kzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OBJECT_HPP
# define OBJECT_HPP
# include "ft_retro.hpp"

class 	AObject {

protected:

	int		_x;
	int 	_y;

public:

	AObject() {};
	AObject(int y, int x);
	AObject(AObject const & copy);
	AObject &operator=(AObject const & rfs);
	virtual ~AObject() {};
	virtual void	mvleft(WINDOW *w, char c);
	virtual void	mvright(WINDOW *w, char c);
	virtual void	mvup(WINDOW *w, char c);
	virtual void	mvdown(WINDOW *w, char c);
	virtual int		update(WINDOW *w, char c, int map[HEIGHT][WIDTH]) = 0;
	virtual int 	get_x() const;
	virtual int 	get_y() const;
};

#endif
