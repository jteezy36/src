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

/*! \file */

#include <string.h>

#include <isc/safe.h>

isc_boolean_t
isc_safe_memequal(const void *s1, const void *s2, size_t n) {
	uint8_t acc = 0;

	if (n != 0U) {
		const uint8_t *p1 = s1, *p2 = s2;

		do {
			acc |= *p1++ ^ *p2++;
		} while (--n != 0U);
	}
	return (ISC_TF(acc == 0));
}

void
isc_safe_memwipe(void *ptr, size_t len) {
	if (ptr == NULL || len == 0)
		return;

	explicit_bzero(ptr, len);
}
