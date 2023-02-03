SRC		=		sources/allocation.c 	\
				sources/vector.c 	\

SERVER		=		server/main.c	\
					server/server_ctor.c 	\
					server/map/map.c		\
					server/map/place_rsc.c	\
					server/client_ctor.c 	\
					server/select.c 	\
					server/server_handler.c \
					server/player_ctor.c	\
					server/game/game.c	\
					server/game/graphic.c	\
					server/game/game_action.c \
					server/game/game_info.c \
					server/game/vision_look.c \
					server/graphic_cmd/map_info.c \
					server/graphic_cmd/player_info.c \
					server/graphic_cmd/player_action.c \
					server/graphic_cmd/team_info.c \
					server/arguments_handling/args_checker.c	\
					server/arguments_handling/arguments.c 		\
					server/arguments_handling/arguments1.c 		\
					server/arguments_handling/n_option.c 	\
					server/manage_buffer/manage_buffer.c	\
					server/manage_buffer/utils.c	\
					server/manage_buffer/str_to_word_array.c	\

IA			=		ia/Trantorians/Trantorian.cpp	\
					ia/Client.cpp	\
					ia/Tool/Tool.cpp	\
					ia/Exeptions/Exeptions.cpp\

GRAPHIC	=	graphical/encaps/Shape.cpp	\
        	graphical/encaps/Model.cpp	\
        	graphical/encaps/Case.cpp	\
        	graphical/encaps/Map.cpp	\
        	graphical/encaps/Text.cpp	\
        	graphical/SCREENS/HandlingScreen.cpp	\
        	graphical/SCREENS/Screen.cpp	\
        	graphical/SCREENS/MENU/Menu.cpp	\
        	graphical/SCREENS/TITLE/Title.cpp	\
        	graphical/connection/connection.cpp	\
        	graphical/Buttons/Buttons.cpp	\
        	graphical/Buttons/ButtonsScreen.cpp	\
        	graphical/DisplayModule.cpp	\
        	graphical/SCREENS/window.cpp	\
        	graphical/PARSER/Parser.cpp	\
        	graphical/connection/GetInfoConnection.cpp	\
        	graphical/main.cpp	\

NAME	=		zappy_server

NAME_IA 	= 	zappy_ai

NAME_GRAPHIC	=	zappy_gui

CPPFLAGS	=	-I./includes/ -I./ia/Trantorians/ -I./ia/ -I./ia/Tool/ -I./ia/Exeptions -I./graphical -I./graphical/Buttons -I./graphical/encaps -I./graphical/connection -I./graphical/PARSER -I./graphical/SCREENS -I./graphical/SCREENS/MENU -I./graphical/SCREENS/TITLE -g3

SRV		=		$(SERVER:.c=.o)

OBJ		=		$(SRC:.c=.o)

OBJIA		=	$(IA:.cpp=.o)

OBJGRAPHIC	=	$(GRAPHIC:.cpp=.o)

CC		=		gcc

CPP		=		g++

all: server ia graphic

server:	$(SRV) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(SRV) -g3

ia:	$(OBJIA) $(OBJ)
	$(CPP) -o $(NAME_IA) $(OBJ) $(OBJIA) $(CPPFLAGS)

graphic: $(OBJGRAPHIC) $(OBJ)
	$(CPP) -o $(NAME_GRAPHIC) $(OBJ) $(OBJGRAPHIC) $(CPPFLAGS) -Iinc -g3 -lGL -lm -lpthread -ldl -lrt -lX11 -lraylib

clean:
	rm -f $(OBJ)
	rm -f $(SRV)
	rm -f $(OBJIA)
	rm -f $(OBJGRAPHIC)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_IA)
	rm -f $(NAME_GRAPHIC)

re: fclean all

.PHONY:	all clean fclean re