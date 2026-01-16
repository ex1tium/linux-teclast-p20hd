/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2021.
 */
/* HS03 code for SR-SL6215-01-181 by gaochao at 20210713 start */

#ifndef __BATTERY_ID_VIA_ADC__
#define __BATTERY_ID_VIA_ADC__

/* Battery ID definitions - generic default */
#if defined(CONFIG_TARGET_UMS9230_4H10)
enum multiBatteryID {
    BATTERY_SCUD_BYD = 0,
    BATTERY_ATL_NVT,
    BATTERY_SCUD_SDI,
    BATTERY_UNKNOWN,
};
#define BATTERY_SCUD_BYD_ID_VOLTAGE_UP     1250
#define BATTERY_SCUD_BYD_ID_VOLTAGE_LOW    1052
#define BATTERY_ATL_NVT_ID_VOLTAGE_UP      817
#define BATTERY_ATL_NVT_ID_VOLTAGE_LOW     600
#define BATTERY_SCUD_SDI_ID_VOLTAGE_UP     1009
#define BATTERY_SCUD_SDI_ID_VOLTAGE_LOW    903

#elif defined(CONFIG_UMS512_25C10_CHARGER)
enum multiBatteryID {
    BATTERY_SCUD_BYD = 0,
    BATTERY_ATL_NVT,
    BATTERY_SCUD_ATL,
    BATTERY_UNKNOWN,
};
#define BATTERY_SCUD_BYD_ID_VOLTAGE_UP    691
#define BATTERY_SCUD_BYD_ID_VOLTAGE_LOW   498
#define BATTERY_ATL_NVT_ID_VOLTAGE_UP     364
#define BATTERY_ATL_NVT_ID_VOLTAGE_LOW    226
#define BATTERY_SCUD_ATL_ID_VOLTAGE_UP    1009
#define BATTERY_SCUD_ATL_ID_VOLTAGE_LOW   903

#elif defined(CONFIG_TARGET_UMS512_1H10)
enum multiBatteryID {
    BATTERY_ATL_NVT = 0,
    BATTERY_SCUD_BYD,
    BATTERY_SCUD_ATL,
    BATTERY_UNKNOWN,
};
#define BATTERY_ATL_NVT_ID_VOLTAGE_UP     842
#define BATTERY_ATL_NVT_ID_VOLTAGE_LOW    680
#define BATTERY_SCUD_BYD_ID_VOLTAGE_UP    1182
#define BATTERY_SCUD_BYD_ID_VOLTAGE_LOW   1023
#define BATTERY_SCUD_ATL_ID_VOLTAGE_UP    435
#define BATTERY_SCUD_ATL_ID_VOLTAGE_LOW   263

#else
/* Default/Generic definition for non-Samsung devices (e.g., Teclast P20HD) */
enum multiBatteryID {
    BATTERY_UNKNOWN = 0,
    BATTERY_ATL_NVT,
    BATTERY_SCUD_BYD,
    BATTERY_SCUD_ATL,
    BATTERY_SCUD_SDI,
};
#define BATTERY_SCUD_BYD_ID_VOLTAGE_UP     0
#define BATTERY_SCUD_BYD_ID_VOLTAGE_LOW    0
#define BATTERY_ATL_NVT_ID_VOLTAGE_UP      0
#define BATTERY_ATL_NVT_ID_VOLTAGE_LOW     0
#define BATTERY_SCUD_ATL_ID_VOLTAGE_UP     0
#define BATTERY_SCUD_ATL_ID_VOLTAGE_LOW    0
#define BATTERY_SCUD_SDI_ID_VOLTAGE_UP     0
#define BATTERY_SCUD_SDI_ID_VOLTAGE_LOW    0
#endif

/* Function declarations / stubs */
#if IS_ENABLED(CONFIG_BATTERY_ID_VIA_ADC)
/* Functions provided by battery_id_via_adc.c */
int bat_id_get_adc_num(void);
int battery_get_bat_id_voltage(void);
int battery_get_bat_id(void);
#else
/* Stub functions for devices without multi-battery support (e.g., Teclast P20HD) */
static inline int bat_id_get_adc_num(void) { return 0; }
static inline int battery_get_bat_id_voltage(void) { return 0; }
static inline int battery_get_bat_id(void) { return BATTERY_UNKNOWN; }
#endif

#endif
/* HS03 code for SR-SL6215-01-181 by gaochao at 20210713 end */
