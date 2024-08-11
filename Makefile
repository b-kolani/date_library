CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
AR = ar
ARFLAGS = rcs
LDFLAGS =

# Fichiers sources
SRC = src/date.c
OBJS = $(SRC:.c=.o)
LIB = lib/libdate.a
EXEC = test_program

# Cible par défaut
all: $(LIB) $(EXEC)
	@echo "Building all..."

# Création de la bibliothèque statique
$(LIB): $(OBJS)
	@mkdir -p lib
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "Library created: $(LIB)"

# Création de l'exécutable
$(EXEC): $(LIB) tests/main.o
	@$(CC) -o $@ tests/main.o -Llib -ldate $(LDFLAGS)
	@echo "Executable created: $(EXEC)"

# Compilation des fichiers objets pour la bibliothèque
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

# Compilation des fichiers objets pour les tests
tests/main.o: tests/main.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

# Nettoyage des fichiers générés
clean:
	@rm -f $(OBJS) tests/main.o $(EXEC)
	@rm -f $(LIB)
	@echo "Cleaning up..."
