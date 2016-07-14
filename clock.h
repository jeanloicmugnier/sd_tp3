/* 
 * File:   clock.h
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on June 22, 2016, 10:41 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "clock.h"
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

    typedef struct Clk {
        clock_t beg;
        clock_t end;
    } clk;
    double set_beg_time(clk *clk);
    double set_end_time(clk *clk);
    char * format_time(double diff);
    char print_time(double time);
#ifdef	__cplusplus
}
#endif

#endif	/* CLOCK_H */

