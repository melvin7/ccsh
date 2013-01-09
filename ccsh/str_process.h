//
//  str_process.h
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#ifndef CCSH_STR_PROCESS_H
#define CCSH_STR_PROCESS_H
#include <stdbool.h>

bool    cc_is_blank(char ch);
char    *cc_get_next_blank(const char *str);
void    cc_skip_blank(char  **str);
bool    cc_str_is(const char *str1, const char *str2);
bool    cc_str_begin_with(const char *str, char ch);

#endif
