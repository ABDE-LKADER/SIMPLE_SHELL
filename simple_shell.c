#include "shell.h"

int main(int argc, char** argv)
{
    if (argc > 2)
	{
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (argc == 2)
	{
        FILE* fp = fopen(argv[1], "r");
        if (fp == NULL)
		{
            perror(argv[1]);
            return EXIT_FAILURE;
        }
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
		{
            char* command = strtok(buffer, "#");
            if (command != NULL) {
                char** args = parse_command(command);
                if (args[0] != NULL)
                    execute_command(args);
                free(args);
            }
        }
        fclose(fp);
        return EXIT_SUCCESS;
    }
    while (1)
	{
        print_prompt();
        char* command = read_command();
        if (command == NULL)
		{
            printf("\n");
            break;
        }
        char** args = parse_command(command);
        if (args[0] != NULL)
            execute_command(args);
        free(args);
        free(command);
    }
    return EXIT_SUCCESS;
}
