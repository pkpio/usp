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

/**
 * Packet size (in bytes) is the unit of data sent over USB per transfer.
 * Min:		64 	(for USB full-speed accessories)
 * Optimal:	512	(for USB high-speed accessories)
 * Max: 	16384	(least packet header overhead)
 */
#define usctp_packet_size	512

/**
 * # of URBs reserved for transfers
 * Out - Sending data. In - Receiving data.
 */
#define urb_out_count	1024
#define urb_in_count	512

