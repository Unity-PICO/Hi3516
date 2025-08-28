#ifndef __RP_LCD_MIPI_5_5INCH_1080x1920_H__
#define __RP_LCD_MIPI_5_5INCH_1080x1920_H__
#include "sample_comm.h"
#include "hi_mipi_tx.h"
/*============================= mipi 5 inch 1080x1920 lcd config ====================================*/
combo_dev_cfg_t MIPI_TX_5_5INCH_1080X1920_60_CONFIG = {
	.devno = 0,
	.lane_id = {0, 1, 2, 3},
	.output_mode = OUTPUT_MODE_DSI_VIDEO	,

	.output_format = OUT_FORMAT_RGB_24_BIT,
	.video_mode =  BURST_MODE,

	.sync_info = {
		.vid_pkt_size=1080,
        .vid_hsa_pixels=4,
        .vid_hbp_pixels=30,
        .vid_hline_pixels=1150,
        .vid_vsa_lines=2,
        .vid_vbp_lines=6,
        .vid_vfp_lines=6,
        .vid_active_lines=1934,
        .edpi_cmd_size=0,
	},
	.phy_data_rate=900,
    .pixel_clk=133446,
  };

VO_SYNC_INFO_S MIPI_TX_5_5INCH_1080X1920_60_SYNC_INFO = {
	.u16Hact=1080,
    .u16Hbb=34,
    .u16Hfb=36,
    .u16Hpw=4,
    .u16Vact=1920,
    .u16Vbb=8,
    .u16Vfb=6,
    .u16Vpw=2,
};

VO_USER_INTFSYNC_INFO_S MIPI_TX_5_5INCH_1080X1920_60_USER_INTFSYNC_INFO = {
	.stUserIntfSyncAttr =
	{
		.stUserSyncPll	=
		{
			.u32Fbdiv=133,
            .u32Frac=0x722D0E,
            .u32Refdiv=2,
            .u32Postdiv1=4,
            .u32Postdiv2=3,
		},
	},

	.u32DevDiv			= 1,
	.u32PreDiv			= 1,
    };

lcd_resoluton_t MIPI_TX_5_5INCH_1080X1920_60_LCD_RESOLUTION = {
	.pu32W	= 1080,
	.pu32H	= 1920,
	.pu32Frm= 60,

};


HI_VOID InitScreen_mipi_5_5inch_1080x1920(HI_S32 s32fd)
{
	SAMPLE_PRT("%s,%d.\n",__FUNCTION__,__LINE__);
	HI_S32     fd     = s32fd;
    HI_S32     s32Ret;
    HI_U8      cmd[30];
    cmd_info_t cmd_info = {0};
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x00FE; 
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
	cmd_info.cmd_size  = 0x08C2; 
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
	cmd_info.cmd_size  = 0x2053; 
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
	cmd_info.cmd_size  = 0xFF51; 
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

}

#endif /* End of #ifndef __RP_LCD_MIPI_5_5INCH_1080x1920_H__ */
