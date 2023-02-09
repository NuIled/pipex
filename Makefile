# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 12:15:05 by aoutifra          #+#    #+#              #
#    Updated: 2023/02/09 03:36:10 by aoutifra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -I bonus

SRC = ft_split.c      pipex.c     utils.c     process.c 
SRC_BONUS = ft_split_bonus.c get_next_line.c heredoc.c get_next_line_utils.c pipex_bonus.c process_bonus.c 
# Specify the NAME binary

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Specify the object files that need to be built
HEADER_BN = $(addprefix bonus/, HEADER_BONUS)


# Specify the compiler and flags
HEADER = pipex.h
HEADER_BONUS = get_next_line.h pipex_bonus.h

all : $(NAME)

$(NAME) : $(OBJECTS)
	

%.o : %.c $(HEADER)
	@ $(CC) $(CFLAGS) $< -o $(NAME)
# # Default rule
# all: $(NAME)

# # Rule to build the NAME binary

# $(NAME): $(OBJECTS)
# 	$(CC)  $(OBJECTS) -o $(NAME)

# # Rule to build the object files
# %.o: %.c $(HEADER) ${HEADER_BN}
# 	$(CC) $(CFLAGS) -c $<

# bonus:
# 	$(CC) -c $(addprefix bonus/, ${b}) -o $(addprefix bonus/, $(NAME))

# # Clean rule
# clean:
# 	rm -f $(NAME) $(OBJECTS)
	

fclean:
	rm -rf $(NAME) $(OBJ)
# re: fclean all

# fcleanbonus:
# 	rm -f $(addprefix bonus/, ${BOBJ}) $(addprefix bonus/, ${NAME}) 