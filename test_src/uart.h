/* uart.h */
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

#ifndef UART_H_
#define UART_H_

#include "config.h"

#if UART_NI == 0
# include "uart_i.h"
#elif UART_NI == 1
# include "uart_ni.h"
#else
# error "You have to set 'UART_NI' to '0' for interrupt driven uart o to '1' for a polling driven uart!"
#endif

#endif /* UART_H_ */
