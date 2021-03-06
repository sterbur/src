/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/* $Id: strerror.c,v 1.1 2020/02/07 09:58:54 florian Exp $ */

/*! \file */



#include <stdio.h>
#include <string.h>

#include <isc/strerror.h>
#include <isc/util.h>

void
isc__strerror(int num, char *buf, size_t size) {
	char *msg;
	unsigned int unum = (unsigned int)num;

	REQUIRE(buf != NULL);

	msg = strerror(num);
	if (msg != NULL)
		snprintf(buf, size, "%s", msg);
	else
		snprintf(buf, size, "Unknown error: %u", unum);
}
