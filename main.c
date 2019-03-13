/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:00:10 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/13 18:33:13 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/SDL.h"
#include "unistd.h"

const int WIDTH = 500, HEIGHT = 300;

enum KeyPressSurfaces
{
	K_DEFAULT,
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_TOTAL
};

int main(int argc, char **argv)
{
	int			running;
	SDL_Window	*window;
	SDL_Event	event;
	SDL_Surface	*surface;
	SDL_Surface	*key[4];
	SDL_Surface	*current;
	int			a;

	a = 0;
	running = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (write(1, "fail to init\n", 13));
	if (!(window = SDL_CreateWindow("Tuto", SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI)))
		exit (1);
	surface = SDL_GetWindowSurface(window);
	key[0] = SDL_LoadBMP("/Users/apelissi/Downloads/39409044_10217121920390157_395934725572657152_o.bmp");
	key[1] = SDL_LoadBMP("/Users/apelissi/Downloads/apelissi.bmp");
	key[2] = SDL_LoadBMP("/Users/apelissi/Downloads/39409044_10217121920390157_395934725572657152_o.bmp");
	key[3] = SDL_LoadBMP("/Users/apelissi/Downloads/apelissi.bmp");
	current = key[a];
	SDL_BlitSurface(current, NULL, surface, NULL);
	SDL_UpdateWindowSurface(window);	
	while (running)	
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT || event.key.keysym.sym == 27) 
				running = 0;
			else
			{
				printf("key = %d\n", event.key.keysym.sym);
				a = (a + 1) % 4;
				current = key[a];
			SDL_BlitSurface(current, NULL, surface, NULL);
			}
			SDL_UpdateWindowSurface(window);	
		}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}

