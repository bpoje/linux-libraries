# Notes:
# Symbol @ means don't print command
# The .ONESHELL: directive allows to write multiple line recipes to be executed in the same shell invocation.

#Text colours
GREEN=\033[0;32m
VIOLET=\033[0;35m
BLUE=\033[0;34m
BLUE_GREEN=\033[0;36m
RED=\033[0;31m
RED_BOLD=\033[1;31m
NC=\033[0m # No Color
#echo -e "${RED}text${NC}"

path_app_that_uses_library = ./app-that-uses-library
path_library = ./library

all: create_library create_app

create_library:
# Build library
	cd "$(path_library)" && $(MAKE)

create_app:
# Build app using library
	cd "$(path_app_that_uses_library)" && $(MAKE)

run_app:
# Run app using library
	cd "$(path_app_that_uses_library)" && $(MAKE) run_app

clean:
# Clean library
	cd "$(path_library)" && $(MAKE) clean
# Clean app using library
	cd "$(path_app_that_uses_library)" && $(MAKE) clean
