#ifndef __RP_LCD_MIPI_10INCH_NEW_800X1280_H__
#define __RP_LCD_MIPI_10INCH_NEW_800X1280_H__
#include "sample_comm.h"
#include "hi_mipi_tx.h"

/*============================= mipi 10 inch 800x1280 lcd config ====================================*/
combo_dev_cfg_t MIPI_TX_10INCH_NEW_800X1280_60_CONFIG = {
    .devno = 0,
    .lane_id = {0, 1, 2, 3},
    .output_mode = OUTPUT_MODE_DSI_VIDEO,
    .output_format = OUT_FORMAT_RGB_24_BIT,
    .video_mode =  BURST_MODE,

    .sync_info = {
        .vid_pkt_size=800,
        .vid_hsa_pixels=30,
        .vid_hbp_pixels=60,
        .vid_hline_pixels=950,
        .vid_vsa_lines=2,
        .vid_vbp_lines=30,
        .vid_vfp_lines=20,
        .vid_active_lines=1332,
        .edpi_cmd_size=0,

    },

    .phy_data_rate=456,
    .pixel_clk=75924,


};

VO_SYNC_INFO_S MIPI_TX_10INCH_NEW_800X1280_60_SYNC_INFO = {
    .u16Hact=800,
    .u16Hbb=90,
    .u16Hfb=60,
    .u16Hpw=30,
    .u16Vact=1280,
    .u16Vbb=32,
    .u16Vfb=20,
    .u16Vpw=2,

};

VO_USER_INTFSYNC_INFO_S MIPI_TX_10INCH_NEW_800X1280_60_USER_INTFSYNC_INFO = {
    .stUserIntfSyncAttr =
    {
        .stUserSyncPll	=
        {
            .u32Fbdiv=75,
            .u32Frac=0xEC8B43,
            .u32Refdiv=2,
            .u32Postdiv1=4,
            .u32Postdiv2=3,

        },
    },

    .u32DevDiv			= 1,
    .u32PreDiv			= 1,
};

lcd_resoluton_t MIPI_TX_10INCH_NEW_800X1280_60_LCD_RESOLUTION = {
    .pu32W	= 800,
    .pu32H	= 1280,
    .pu32Frm= 60,

};

HI_VOID InitScreen_mipi_10inch_new_800x1280(HI_S32 s32fd)
{
    HI_S32     fd     = s32fd;
    HI_S32     s32Ret;
    HI_U8      cmd[30];
    cmd_info_t cmd_info = {0};

    SAMPLE_PRT("%s,%d.\n",__FUNCTION__,__LINE__);
    cmd[0] = 0xFF;
    cmd[1] = 0x98;
    cmd[2] = 0x81;
    cmd[3] = 0x03;
    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x4; 
    cmd_info.data_type = 0x29;
    cmd_info.cmd       = cmd;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0001; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0002; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x5303; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1304; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0005; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0406; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0007; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0008; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2209; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x220a; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x000b; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x010c; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x000d; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x000e; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x230f; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2310; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0011; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0012; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0013; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0014; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0015; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0016; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0017; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0018; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0019; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x001a; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x001b; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x001c; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x001d; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x441e; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x801f; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0220; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0321; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0022; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0023; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0024; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0025; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0026; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0027; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x3328; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0329; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x002a; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x002b; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x002c; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x002d; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x002e; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x002f; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0030; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0031; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0032; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0033; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0434; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0035; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0036; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0037; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x3C38; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0039; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x403a; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x403b; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x003c; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x003d; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x003e; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x003f; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0040; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0041; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0042; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0043; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0044; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0150; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2351; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x4552; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x6753; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x8954; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0xab55; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0156; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2357; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x4558; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x6759; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x895a; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0xab5b; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0xcd5c; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0xef5d; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x115e; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x015f; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0060; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1561; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1462; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0C63; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0D64; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0E65; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0F66; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0667; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0268; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0269; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x026a; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x026b; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x026c; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x026d; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x086e; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x026f; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0270; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0271; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0272; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0273; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0274; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0175; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0076; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1577; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1478; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0C79; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0D7a; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0E7b; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0F7c; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x087D; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x027E; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x027F; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0280; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0281; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0282; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0283; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0684; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0285; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0286; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0287; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0288; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0289; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x028A; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd[0] = 0xFF;
    cmd[1] = 0x98;
    cmd[2] = 0x81;
    cmd[3] = 0x04;
    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x4; 
    cmd_info.data_type = 0x29;
    cmd_info.cmd       = cmd;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x156C; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x3B6E; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x736F; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x243A; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x148D; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0xBA87; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x7626; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0xD1B2; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x27B5; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x7531; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0330; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x983B; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1f35; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1433; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0F7A; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0238; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0039; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd[0] = 0xFF;
    cmd[1] = 0x98;
    cmd[2] = 0x81;
    cmd[3] = 0x01;
    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x4; 
    cmd_info.data_type = 0x29;
    cmd_info.cmd       = cmd;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0A22; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0A31; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0735; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0052; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x5A53; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0054; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x5955; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x8350; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x8051; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2060; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0161; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0762; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0063; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x08A0; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0FA1; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x15A2; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0EA3; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0DA4; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1BA5; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0FA6; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x14A7; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x33A8; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x17A9; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x23AA; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x3FAB; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x22AC; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x24AD; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x59AE; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2BAF; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2EB0; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x4CB1; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x5CB2; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x33B3; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x08C0; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0FC1; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x15C2; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0EC3; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0DC4; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x1BC5; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0FC6; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x14C7; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x33C8; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x17C9; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x23CA; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x3FCB; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x22CC; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x24CD; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x59CE; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2BCF; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x2ED0; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x4CD1; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x5CD2; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x33D3; 
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd[0] = 0xFF;
    cmd[1] = 0x98;
    cmd[2] = 0x81;
    cmd[3] = 0x00;
    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x4; 
    cmd_info.data_type = 0x29;
    cmd_info.cmd       = cmd;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0011; 
    cmd_info.data_type = 0x05;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(200000);

    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0029; 
    cmd_info.data_type = 0x05;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);
    
    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0035; 
    cmd_info.data_type = 0x05;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
    close(fd);
    return;
    }
    usleep(1000);
}

#endif /* End of #ifndef __RP_LCD_MIPI_10INCH_NEW_800X1280_H__*/
