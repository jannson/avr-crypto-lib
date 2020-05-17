/* cast5.h */
/*
 This file is part of the AVR-Crypto-Lib.
 Copyright (C) 2006-2015 Daniel Otte (bg@nerilex.org)

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/** 
 * \file	cast5.h
 * \author	Daniel Otte
 * \date 	2006-07-26
 * \license GPLv3 or later
 * \brief Implementation of the CAST5 (aka CAST-128) cipher algorithm as described in RFC 2144
 * 
 */

#ifndef CAST5_H_
#define CAST5_H_ 

#include <stdint.h> 

#ifndef BOOL
#define BOOL
#ifndef __BOOL
#define __BOOL
#ifndef __BOOL__
#define __BOOL__
typedef enum {
    false = 0, true = 1
} bool;
#endif
#endif
#endif

/** \typedef cast5_ctx_t
 * \brief CAST-5 context
 * 
 * A variable of this type may hold a keyschedule for the CAST-5 cipher. 
 * This context is regulary generated by the 
 * cast5_init(uint8_t *key, uint8_t keylength_b, cast5_ctx_t *s) function.
 */
typedef struct cast5_ctx_st {
    uint32_t mask[16];
    uint8_t rotl[8]; /* 4 bit from every rotation key is stored here */
    uint8_t roth[2]; /* 1 bit from every rotation key is stored here */
    bool shortkey;
} cast5_ctx_t;

/** \fn void cast5_init(const void *key, uint16_t keylength_b, cast5_ctx_t *s);
 * \brief generate keyschedule/contex for CAST-5
 * 
 * This function generates the keyschedule from the supplied key for the 
 * CAST-5 cipher and stores it in a supplied ::cast5_ctx_t context.
 * \param key pointer to the key
 * \param keylength_b length of the key in bits (maximum 128 bits)
 * \param s pointer to the context
 */
void cast5_init(const void *key, uint16_t keylength_b, cast5_ctx_t *s);

/** \fn void cast5_enc(void *block, const cast5_ctx_t *s);
 * \brief encrypt a block with the CAST-5 algorithm
 * 
 * This function encrypts a block of 64 bits (8 bytes) with the CAST-5 algorithm.
 * It uses a keyschedule as generated by the 
 * cast5_init(void *key, uint8_t keylength_b, cast5_ctx_t *s) function.
 * \param block pointer to the block which gets encrypted
 * \param s pointer to the keyschedule/context
 */
void cast5_enc(void *block, const cast5_ctx_t *s);

/** \fn void cast5_dec(void *block, const cast5_ctx_t *s);
 * \brief decrypt a block with the CAST-5 algorithm
 * 
 * This function decrypts a block of 64 bits (8 bytes) with the CAST-5 algorithm.
 * It uses a keyschedule as generated by the 
 * cast5_init(void *key, uint8_t keylength_b, cast5_ctx_t *s) function.
 * \param block pointer to the block which gets decrypted
 * \param s pointer to the keyschedule/context
 */
void cast5_dec(void *block, const cast5_ctx_t *s);

#endif
