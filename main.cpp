/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:03:25 by dkosolap          #+#    #+#             */
/*   Updated: 2017/11/04 20:25:14 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "GameClass.hpp"

int 	main(void) {

 	srand(time(0));
	GameClass general;

	general.start();
	return (0);
};

// int 	p = WIDTH / 2;

// void	ft_generate(char paralax[HEIGHT][WIDTH]) {
// 	for (int i = HEIGHT - 1; i != -1 ; i--) {
// 		for (int j = 0; j < WIDTH; j++) {
// 			if (i != 0) {
// 				paralax[i][j] = paralax[i - 1][j];
// 			}
// 		}
// 	}
// 	for (int i = 0; i < WIDTH; ++i) {
// 		if (rand() % 50 == 0)
// 			paralax[0][i] = '.';
// 		else// _x = (rand() % (HEIGHT - 4)) + 2;
// 			paralax[0][i] = ' ';
// 	}
// }

// void	ft_refresh(WINDOW *w, char paralax[HEIGHT][WIDTH]) {
// 	// (void)paralax;
// 	// for (int i = 0; i < HEIGHT; i++)
// 		mvwprintw(w, 0, 0, "%s", paralax);
// 		mvwprintw(w, HEIGHT - 2, p, "%c", '^');

// 	// noecho(); // убираем вывод в консоль нажатых клавишь
// 	box(w, 0, 0);
// 	wrefresh(w);
// }


// int 	main(void) {
// 	WINDOW	*w;
// 	char	paralax[HEIGHT][WIDTH];

// 	for (int i = 0; i < HEIGHT; i++) {
// 		for (int j = 0; j < WIDTH; j++) {
// 			paralax[i][j] = ' ';
// 		}
// 	}

// 	start_visual();
// 	w = inits();
// 	// ft_refresh(w, paralax);
// 	while (true) {
// 		switch ( wgetch(w) ) {
// 			case KEY_LEFT:
// 				p--;
// 				break;
// 			case KEY_RIGHT:
// 				p++;
// 				// mvwprintw(w, 1, 1, "%s", "right");
// 				break;
// 		}
// 		ft_generate(paralax);
// 		if (paralax[HEIGHT - 2][p] == '.')
// 			break ;
// 		ft_refresh(w, paralax);
// 		wgetch(w);
// 		usleep(50000);
// 	}
// 	close_visual();
// 	return (0);
// };
