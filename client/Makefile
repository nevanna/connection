
NAME = client
FILES = client.c ft_connect.c ft_sdl.c ft_net_part.c ft_render_part.c ft_braz.c ft_move.c
SRC = $(addprefix srcs/, $(FILES))
FILESO = $(addprefix objectives/, $(FILES:.c=.o))
FLAGS = -Wall -Wextra -Werror
LIBA = -L ./libs/libft -lft
ADD = -framework OpenGL -framework AppKit
INCL = -I. -I Frameworks/SDL2_mixer.framework/Versions/A/Headers \
	   -I Frameworks/SDL2.framework/Versions/A/Headers \
	    -I Frameworks/SDL2_net.framework/Versions/A/Headers \
	   -F Frameworks/

FRAMEWORK =	-F Frameworks/ -framework SDL2  -framework SDL2_mixer -framework SDL2_net

all: $(NAME)

$(NAME): $(FILESO)
	make -C ./libs/libft/
	#$(FLAGS) -fsanitize=address -g
	gcc   -o $(NAME) $(SRC) $(INCL) $(LIBA) $(MIN) $(ADD) $(FRAMEWORK)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 Frameworks/SDL2.framework/Versions/A/SDL2 $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer Frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer $(NAME)
	@install_name_tool -change @rpath/SDL2_net.framework/Versions/A/SDL2_net Frameworks/SDL2_net.framework/Versions/A/SDL2_net $(NAME)
objectives/%.o: srcs/%.c | objectives
	#$(FLAGS) -fsanitize=address -g
	gcc   $(INCL) -o $@ -c $<

clean:
	rm -rf objectives/
	make clean -C ./libs/libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libs/libft/

objectives:
	mkdir objectives/
re: fclean all
