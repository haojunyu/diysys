/* Copyright (C) 2011-2015 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Chris Metcalf <cmetcalf@tilera.com>, 2011.
   Based on work contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <http://www.gnu.org/licenses/>.  */

#include <assert.h>
#include <errno.h>
#include <endian.h>
#include <unistd.h>
#include <sys/uio.h>

#include <sysdep-cancel.h>
#include <sys/syscall.h>

ssize_t
__libc_pwritev (int fd, const struct iovec *vector, int count, off_t offset)
{
  assert (sizeof (offset) == 4);
  return SYSCALL_CANCEL (pwritev, fd, vector, count, __ALIGNMENT_ARG
                         __LONG_LONG_PAIR (offset >> 31, offset));
}
strong_alias (__libc_pwritev, __pwritev)
weak_alias (__libc_pwritev, pwritev)
