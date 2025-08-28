#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "hi_common.h"
#include "sample_vio.h"
#include "mpi_sys.h"

//added lcd config head files
#include "mpi_sys.h"
#include "sample_comm.h"

/******************************************************************************
* function : show usage
******************************************************************************/
void SAMPLE_VIO_Usage(char *sPrgNm)
{
    /* printf("Usage : %s <index>\n", sPrgNm);
    printf("index:\n");
    printf("\t 0)VI (Online) - VPSS(Online) - VO.\n");
    printf("\t 1)WDR(Offline)- VPSS(Offline) - VO. LDC+DIS+SPREAD.\n");
    printf("\t 2)Resolute Ratio Switch.\n");
    printf("\t 3)GDC - VPSS LowDelay.\n");
    printf("\t 4)Double WDR Pipe.\n");
    printf("\t 5)FPN Calibrate & Correction.\n");
    printf("\t 6)WDR Switch.\n");
    printf("\t 7)90/180/270/0/free Rotate.\n");
    printf("\t 8)UserPic.\n");
    printf("\t 9)VI-VPSS-VO(MIPI_TX).\n\n");

    printf("\t Hi3516DV300/Hi3559V200/Hi3556V200) vo HDMI output.\n");
    printf("\t Hi3516CV500) vo BT1120 output.\n");
    printf("\t If you have any questions, please look at readme.txt!\n"); */

    printf("Usage : %s -f <display> -l <lcd_cel> -s <sns0_rotat> -S <sns1_rotat> -t <sns0_type> -T <sns1_type>\n", sPrgNm);
    printf("<display>:\n");
    printf("\t 9)  SAMPLE_VIO_VPSS_VO_MIPI_TX.\n");
    printf("\t 10) SAMPLE_VIO_VPSS_VO_MIPI_TX_DOUBLE_VI.\n");
    printf("\t 11) SAMPLE_VIO_VPSS_VO_HDMI_TX.\n");
    printf("\t 12) SAMPLE_VIO_VPSS_VO_MIPI_TX_DOUBLE_VI.\n");

    printf("<lcd_cel>:\n");
    printf("\t 0)7inch   1024x600 MIPI.\n");
    printf("\t 1)8inch   800x1280 MIPI.\n");
    printf("\t 2)10inch  800x1280 MIPI.\n");
    printf("\t 3)5inch   720x1280 MIPI.\n");
    printf("\t 4)4inch   480x800  MIPI.\n");
    printf("\t 5)5.5inch 720x1280 MIPI.\n");
    printf("\t 6)7inch   800x1280 MIPI.\n");
    printf("\t 7)8inch   800x1280_9881C MIPI.\n");
    printf("\t 8)5.5inch-new 720x1280 MIPI.\n");
    printf("\t 9)10inch-new  800x1280 MIPI.\n");
    printf("\t 10)5.5inch 1080x1920 MIPI.\n");
    printf("\t 11)5inch   720x1280-v2 MIPI.\n");

    printf("<sns0_rotat> and <sns1_rotat>: \n");
    printf("\t 0)   rotat 0   degrees.\n");
    printf("\t 90)  rotat 90  degrees.\n");
    printf("\t 180) rotat 180 degrees.\n");
    printf("\t 270) rotat 270 degrees.\n");
    printf("\t Any degrees is not supported.\n");

    printf("<sns0_type> and <sns1_type>:\n");
    printf("\t 2) imx327_2l .\n");
    printf("\t 6) imx307_2l .\n");
    printf("\t 32) gc2093_2l .\n");

    printf("example:\n");
    printf("./sample_vio -f 10 -l 0 -r 90 -R 0 -t 2 -T 2\n");
    return;
}

/******************************************************************************
* function    : main()
* Description : main
******************************************************************************/
#ifdef __HuaweiLite__
int app_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    HI_S32 s32Ret = HI_FAILURE;
    HI_S32 s32Index  = 10;
    HI_U32 u32VoIntfType = 0;
    HI_U32  u32ChipId;

    HI_S32 ch;
    HI_U32 saturation = 0;
    HI_U32 sns0_rotat = 0, sns1_rotat = 0;
    HI_U32 lcd_sel = 0;
    HI_U32 sns_type = 0;
    HI_U32 enWDRMode = 0;

    while((ch=getopt(argc,argv,"f:s:r:R:l:t:T:h")) != -1) {
        switch(ch) {
        case 'f':
            s32Index = atoi(optarg);
            printf("option f:'%s', s32Index = %d\n",optarg, s32Index);
            break;

        case 's':
            saturation = atoi(optarg);
            printf("option s:'%s' saturation = %d\n",optarg, saturation);
            break;

        case 'r':
            sns0_rotat = atoi(optarg);
            printf("option r:'%s', sensor0_ratation = %d\n",optarg, sns0_rotat);
            switch(sns0_rotat) {
            case 0:
                sns0_rotat = 0;
                break;
            case 90:
                sns0_rotat = 1;
                break;
            case 180:
                sns0_rotat = 2;
                break;
            case 270:
                sns0_rotat = 3;
                break;
            default:
                sns0_rotat = 0;
            }
            break;

        case 'R':
            sns1_rotat = atoi(optarg);
            printf("option T:'%s', sensor1_ratation =%d\n",optarg, sns1_rotat);
            printf("option r:'%s', sensor0_ratation = %d\n",optarg, sns0_rotat);
            switch(sns1_rotat) {
            case 0:
                sns1_rotat = 0;
                break;
            case 90:
                sns1_rotat = 1;
                break;
            case 180:
                sns1_rotat = 2;
                break;
            case 270:
                sns1_rotat = 3;
                break;
            default:
                sns0_rotat = 0;
            }
            break;

        case 'l':
            lcd_sel = atoi(optarg);
            printf("option l:'%s', lcd_sel = %d\n",optarg, lcd_sel);
            switch(lcd_sel) {
            case 0:
                g_mipi_tx_config = &MIPI_TX_7INCH_1024X600_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_7INCH_1024X600_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_7INCH_1024X600_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_7INCH_1024X600_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_7inch_1024x600;
                break;

            case 1:
                g_mipi_tx_config = &MIPI_TX_8INCH_800X1280_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_8INCH_800X1280_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_8INCH_800X1280_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_8INCH_800X1280_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_8inch_800x1280;
                break;

            case 2:
                g_mipi_tx_config = &MIPI_TX_10INCH_800X1280_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_10INCH_800X1280_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_10INCH_800X1280_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_10INCH_800X1280_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_10inch_800x1280;
                break;
            case 3:
                g_mipi_tx_config = &MIPI_TX_5INCH_720X1280_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_5INCH_720X1280_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_5INCH_720X1280_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_5INCH_720X1280_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_5inch_720x1280;
                break;
            case 4:
                g_mipi_tx_config = &MIPI_TX_4INCH_480X800_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_4INCH_480X800_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_4INCH_480X800_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_4INCH_480X800_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_4inch_480x800;
                break;
            case 5:
                g_mipi_tx_config = &MIPI_TX_5_5INCH_720X1280_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_5_5INCH_720X1280_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_5_5INCH_720X1280_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_5_5INCH_720X1280_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_5_5inch_720x1280;
                break;
            case 6:
                g_mipi_tx_config = &MIPI_TX_7INCH_800X1280_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_7INCH_800X1280_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_7INCH_800X1280_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_7INCH_800X1280_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_7inch_800x1280;
                break;

            case 7:
                g_mipi_tx_config = &MIPI_TX_8INCH_800X1280_60_CONFIG_9881C;
                g_mipi_tx_sync_info = &MIPI_TX_8INCH_800X1280_60_SYNC_INFO_9881C;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_8INCH_800X1280_60_USER_INTFSYNC_INFO_9881C;
                g_mipi_tx_lcd_resolution = &MIPI_TX_8INCH_800X1280_60_LCD_RESOLUTION_9881C;
                g_mipi_lcd_init = &InitScreen_mipi_8inch_800x1280_9881C;
                break;

            case 8:
                g_mipi_tx_config = &MIPI_TX_5_5INCH_NEW_720X1280_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_5_5INCH_NEW_720X1280_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_5_5INCH_NEW_720X1280_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_5_5INCH_NEW_720X1280_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_5_5inch_new_720x1280;
                break;

            case 9:
                g_mipi_tx_config = &MIPI_TX_10INCH_NEW_800X1280_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_10INCH_NEW_800X1280_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_10INCH_NEW_800X1280_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_10INCH_NEW_800X1280_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_10inch_new_800x1280;
                break;
	    case 10:
                g_mipi_tx_config = &MIPI_TX_5_5INCH_1080X1920_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_5_5INCH_1080X1920_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_5_5INCH_1080X1920_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_5_5INCH_1080X1920_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_5_5inch_1080x1920;
                break;
	
            case 11:
                g_mipi_tx_config = &MIPI_TX_5INCH_720X1280_V2_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_5INCH_720X1280_V2_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_5INCH_720X1280_V2_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_5INCH_720X1280_V2_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_5inch_720x1280_V2;
                break;

            default:
                g_mipi_tx_config = &MIPI_TX_7INCH_1024X600_60_CONFIG;
                g_mipi_tx_sync_info = &MIPI_TX_7INCH_1024X600_60_SYNC_INFO;
                g_mipi_tx_user_intfsync_info = &MIPI_TX_7INCH_1024X600_60_USER_INTFSYNC_INFO;
                g_mipi_tx_lcd_resolution = &MIPI_TX_7INCH_1024X600_60_LCD_RESOLUTION;
                g_mipi_lcd_init = &InitScreen_mipi_7inch_1024x600;
            }
            break;

        case 't':
            sns_type = atoi(optarg);
            g_sns_type[0] = sns_type;

            switch(sns_type) {
            case 3:				//SONY_IMX327_2L_MIPI_2M_30FPS_12BIT_WDR2TO1
            case 7:				//SONY_IMX307_2L_MIPI_2M_30FPS_12BIT_WDR2TO1
            case 33:			//gc2093 WDR2TO1 mode
                enWDRMode = 3;	//WDR_MODE_2To1_LINE
                break;
            default:
                enWDRMode = 0;	//WDR_MODE_NONE
            }

            printf("option t:'%s', sns0_type = %d\n",optarg, g_sns_type[0]);
            break;

        case 'T':
            sns_type = atoi(optarg);
            g_sns_type[1] = sns_type;

            switch(sns_type) {
            case 3:				//SONY_IMX327_2L_MIPI_2M_30FPS_12BIT_WDR2TO1
            case 7:				//SONY_IMX307_2L_MIPI_2M_30FPS_12BIT_WDR2TO1
            case 33:			//gc2093 WDR2TO1 mode
                enWDRMode = 3;	//WDR_MODE_2To1_LINE
                break;
            default:
                enWDRMode = 0;	//WDR_MODE_NONE
            }

            printf("option T:'%s', sns1_type = %d\n",optarg, g_sns_type[1]);
            break;


        case 'h':
            SAMPLE_VIO_Usage(argv[0]);
            return 0;
            break;

        default:
            SAMPLE_VIO_Usage(argv[0]);
            return 0;
        }
    }



    /* if (argc < 2 || argc > 2)
    {
        SAMPLE_VIO_Usage(argv[0]);
        return HI_FAILURE;
    }

    if (!strncmp(argv[1], "-h", 2))
    {
        SAMPLE_VIO_Usage(argv[0]);
        return HI_SUCCESS;
    } */

#ifdef __HuaweiLite__
#else
    signal(SIGINT, SAMPLE_VIO_HandleSig);
    signal(SIGTERM, SAMPLE_VIO_HandleSig);
#endif

    HI_MPI_SYS_GetChipId(&u32ChipId);

    if (HI3516C_V500 == u32ChipId) {
        u32VoIntfType = 1;
    } else {
        u32VoIntfType = 0;
    }

    SAMPLE_VIO_MsgInit();

    //s32Index = atoi(argv[1]);
    switch (s32Index) {
    /*
    case 0:
        s32Ret = SAMPLE_VIO_ViOnlineVpssOnlineRoute(u32VoIntfType);
        break;

    case 1:
        s32Ret = SAMPLE_VIO_WDR_LDC_DIS_SPREAD(u32VoIntfType);
        break;

    case 2:
        s32Ret = SAMPLE_VIO_ResoSwitch(u32VoIntfType);
        break;

    case 3:
        s32Ret = SAMPLE_VIO_ViVpssLowDelay(u32VoIntfType);
        break;

    case 4:
        s32Ret = SAMPLE_VIO_ViDoubleWdrPipe(u32VoIntfType);
        break;

    case 5:
        s32Ret = SAMPLE_VIO_FPN(u32VoIntfType);
        break;

    case 6:
        s32Ret = SAMPLE_VIO_ViWdrSwitch(u32VoIntfType);
        break;

    case 7:
        s32Ret = SAMPLE_VIO_Rotate(u32VoIntfType);
        break;

    case 8:
        s32Ret = SAMPLE_VIO_SetUsrPic(u32VoIntfType);
        break;
    */
    case 9:
        s32Ret = SAMPLE_VIO_VPSS_VO_MIPI_TX(u32VoIntfType, saturation, sns0_rotat,enWDRMode);
        break;

    case 10:
        s32Ret = SAMPLE_VIO_VPSS_VO_MIPI_TX_DOUBLE_VI(u32VoIntfType, saturation, sns0_rotat, sns1_rotat,enWDRMode);
        break;

    case 11:
        s32Ret = SAMPLE_VIO_VPSS_VO_HDMI(u32VoIntfType, saturation, sns0_rotat,enWDRMode);
        break;

    case 12:
        s32Ret = SAMPLE_VIO_VPSS_VO_HDMI_DOUBLE_VI(u32VoIntfType, saturation, sns0_rotat, sns1_rotat,enWDRMode);
        break;

    default:
        SAMPLE_PRT("the index %d is invaild!\n",s32Index);
        SAMPLE_VIO_Usage(argv[0]);
        SAMPLE_VIO_MsgExit();
        return HI_FAILURE;
    }

    if (HI_SUCCESS == s32Ret) {
        SAMPLE_PRT("sample_vio exit success!\n");
    } else {
        SAMPLE_PRT("sample_vio exit abnormally!\n");
    }

    SAMPLE_VIO_MsgExit();

    return s32Ret;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
