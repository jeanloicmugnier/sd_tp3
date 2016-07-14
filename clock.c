

double set_beg_time(clk *clk) {
    clk->beg = clock();
    return 0;
}

double set_end_time(clk *clk) {
    clk->end = clock();
    return 0;
}

/**
 * Format the time
 * @return pointer to 
 */
char * format_time(double diff) {
    char str[20];
    sprintf(str, "%f", diff);
    char * ex = "exec time: ";
    strcat(ex, str);
    return ex;
}

char print_time(double time) {
    //    double tx = clk_calc_time(clk);
    char* res = format_time(time);
    printf(" res: %s \n", res);
    return *res;
}
