/**
 *
 * The common header file that contains general configuration details used in
 * the usp driver. Any module that uses usctp module should be importing this
 * file to get custom structs, params and config used by the usctp driver
 */

/**
 * Total number of streams used in the driver.
 * Ideally, this could be any number but currently limited to the param.
 */
#define STR_COUNT	5

/**
 * Predefined ids for handpicked stream types
 */
#define	STR_VIDEO	0
#define	STR_AUDIO	1
#define STR_KEYBOARD	2
#define STR_MOUSE	3
#define STR_UNKNOWN	4

/**
 * Custom types used by the usctp driver. Particularily for Data exchange
 */
struct usp_receive_cb_t{
        void (*receive) (int length, void *data);
};

