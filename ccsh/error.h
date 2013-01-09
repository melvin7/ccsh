//
//  error.h
//  ccsh
//
//  Created by xichen on 12-4-10.
//  Copyright (c) 2012 xichen. All rights reserved.
//

#ifndef CCSH_ERROR_H
#define CCSH_ERROR_H

typedef enum 
{
    CC_OK,
    CC_ERR_NOMEM
}CC_ERR;

typedef struct 
{
    CC_ERR  err_no;
    char    *err_str;
}cc_err_info;

extern  cc_err_info errs[];

// global error number
extern  int         errno;

void    cc_err(CC_ERR err_no);

#endif
