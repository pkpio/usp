/*
 * usctp.c - Usb Stream Control Transmission Protocol
 *
 * Copyright (C) 2015 Praveen Kumar Pendyala <m@praveen.xyz>
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License v2. See the file COPYING in the main directory of this archive for
 * more details
 *
 */
 
#define INSTREAM_COUNT 		2 	// # of streams to read data from
#define OUTSTREAM_COUNT 	2	// # of streams to write data to
#define INSTREAM_BUFFER_SIZE	512	// size of buffers used for instreams
#define OUTSTREAM_BUFFER_SIZE	8192	// size of buffers used for outstreams
