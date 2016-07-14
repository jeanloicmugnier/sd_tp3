/* 
 * File:   file_handler.h
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on July 4, 2016, 9:30 PM
 */

#ifndef FILE_HANDLER_H
#define	FILE_HANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

    void write_in_file(char * name, char * mode, char* cont);
    void open_file(char * path, char* mode);

#ifdef	__cplusplus
}
#endif

#endif	/* FILE_HANDLER_H */

