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

    typedef struct Clk {
        clock_t beg;
        clock_t end;
    } clk;

#ifdef	__cplusplus
}
#endif

#endif	/* CLOCK_H */

