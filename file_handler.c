void write_in_file(char * name, char* cont) {
    FILE *f = fopen(name, "a");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    /* print some text */
    fprintf(f, "%s\n", cont);
    fclose(f);
}

