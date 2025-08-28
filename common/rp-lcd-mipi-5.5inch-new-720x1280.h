#ifndef __RP_LCD_MIPI_5_5INCH_NEW_720X1280_H__
#define __RP_LCD_MIPI_5_5INCH_NEW_720X1280_H__
#include "sample_comm.h"
#include "hi_mipi_tx.h"
/*============================= mipi 5_5 inch new 720x1280 lcd config ====================================*/
combo_dev_cfg_t MIPI_TX_5_5INCH_NEW_720X1280_60_CONFIG =
{
    .devno = 0,
    .lane_id = {0, 1, 2, 3},
    .output_mode = OUTPUT_MODE_DSI_VIDEO,
    .output_format = OUT_FORMAT_RGB_24_BIT,
    .video_mode =  BURST_MODE,

    .sync_info = {
		.vid_pkt_size=720,
		.vid_hsa_pixels=2,
		.vid_hbp_pixels=42,
		.vid_hline_pixels=808,
		.vid_vsa_lines=2,
		.vid_vbp_lines=10,
		.vid_vfp_lines=14,
		.vid_active_lines=1280,
		.edpi_cmd_size=0,

	},
	.phy_data_rate=380,
	.pixel_clk=63315,


};

VO_SYNC_INFO_S MIPI_TX_5_5INCH_NEW_720X1280_60_SYNC_INFO = 
{
	.u16Hact=720,
	.u16Hbb=42,
	.u16Hfb=44,
	.u16Hpw=2,
	.u16Vact=1280,
	.u16Vbb=10,
	.u16Vfb=14,
	.u16Vpw=2,

};

VO_USER_INTFSYNC_INFO_S MIPI_TX_5_5INCH_NEW_720X1280_60_USER_INTFSYNC_INFO = 
{
	.stUserIntfSyncAttr = 
	{
		.stUserSyncPll	= 
		{
			.u32Fbdiv=517,
			.u32Frac=0x124F22,
			.u32Refdiv=4,
			.u32Postdiv1=7,
			.u32Postdiv2=7,

		},
	},

	.u32DevDiv			= 1,
	.u32PreDiv			= 1,
};

lcd_resoluton_t MIPI_TX_5_5INCH_NEW_720X1280_60_LCD_RESOLUTION = 
{
	.pu32W	= 720,
	.pu32H	= 1280,
	.pu32Frm= 60,

};


HI_VOID InitScreen_mipi_5_5inch_new_720x1280(HI_S32 s32fd)
{
	SAMPLE_PRT("%s,%d.\n",__FUNCTION__,__LINE__);
	HI_S32     fd     = s32fd;
	HI_S32     s32Ret;
	HI_U8      cmd[100];
	cmd_info_t cmd_info = {0};
	
	cmd[0] = 0xB9;
	cmd[1] = 0xF1;
	cmd[2] = 0x12;
	cmd[3] = 0x83;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x04; 
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
		
	cmd[0] = 0xBA;
	cmd[1] = 0x33;
	cmd[2] = 0x81;
	cmd[3] = 0x05;
	cmd[4] = 0xF9;
	cmd[5] = 0x0E;
	cmd[6] = 0x0E;
	cmd[7] = 0x20;
	cmd[8] = 0x00;
	cmd[9] = 0x00;
	cmd[10] = 0x00;
	cmd[11] = 0x00;
	cmd[12] = 0x00;
	cmd[13] = 0x00;
	cmd[14] = 0x00;
	cmd[15] = 0x44;
	cmd[16] = 0x25;
	cmd[17] = 0x00;
	cmd[18] = 0x91;
	cmd[19] = 0x0A;
	cmd[20] = 0x00;
	cmd[21] = 0x00;
	cmd[22] = 0x02;
	cmd[23] = 0x4F;
	cmd[24] = 0xD1;
	cmd[25] = 0x00;
	cmd[26] = 0x00;
	cmd[27] = 0x37;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1c; 
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
		
	cmd[0] = 0xB8;
	cmd[1] = 0x26;
	cmd[2] = 0x22;
	cmd[3] = 0x20;
	cmd[4] = 0x03;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x05; 
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
		
	cmd[0] = 0xBF;
	cmd[1] = 0x02;
	cmd[2] = 0x11;
	cmd[3] = 0x00;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x04; 
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
		
	cmd[0] = 0xB3;
	cmd[1] = 0x0C;
	cmd[2] = 0x10;
	cmd[3] = 0x0A;
	cmd[4] = 0x50;
	cmd[5] = 0x03;
	cmd[6] = 0xFF;
	cmd[7] = 0x00;
	cmd[8] = 0x00;
	cmd[9] = 0x00;
	cmd[10] = 0x00;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0b; 
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
		
	cmd[0] = 0xC0;
	cmd[1] = 0x73;
	cmd[2] = 0x73;
	cmd[3] = 0x50;
	cmd[4] = 0x50;
	cmd[5] = 0x00;
	cmd[6] = 0x00;
	cmd[7] = 0x08;
	cmd[8] = 0x70;
	cmd[9] = 0x00;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0a; 
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
	cmd_info.cmd_size  = 0x46BC; 
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
	cmd_info.cmd_size  = 0x0BCC; 
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
	cmd_info.cmd_size  = 0x80B4; 
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
		
	cmd[0] = 0xB2;
	cmd[1] = 0xC8;
	cmd[2] = 0x12;
	cmd[3] = 0x30;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x04; 
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
		
	cmd[0] = 0xE3;
	cmd[1] = 0x07;
	cmd[2] = 0x07;
	cmd[3] = 0x0B;
	cmd[4] = 0x0B;
	cmd[5] = 0x03;
	cmd[6] = 0x0B;
	cmd[7] = 0x00;
	cmd[8] = 0x00;
	cmd[9] = 0x00;
	cmd[10] = 0x00;
	cmd[11] = 0xFF;
	cmd[12] = 0x00;
	cmd[13] = 0xC0;
	cmd[14] = 0x10;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0f; 
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
		
	cmd[0] = 0xC1;
	cmd[1] = 0x53;
	cmd[2] = 0x00;
	cmd[3] = 0x1E;
	cmd[4] = 0x1E;
	cmd[5] = 0x77;
	cmd[6] = 0xC1;
	cmd[7] = 0xFF;
	cmd[8] = 0xFF;
	cmd[9] = 0xAF;
	cmd[10] = 0xAF;
	cmd[11] = 0x7F;
	cmd[12] = 0x7F;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0d; 
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
		
	cmd[0] = 0xB5;
	cmd[1] = 0x07;
	cmd[2] = 0x07;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x03; 
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
		
	cmd[0] = 0xB6;
	cmd[1] = 0x70;
	cmd[2] = 0x70;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x03; 
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
		
	cmd[0] = 0xC6;
	cmd[1] = 0x00;
	cmd[2] = 0x00;
	cmd[3] = 0xFF;
	cmd[4] = 0xFF;
	cmd[5] = 0x01;
	cmd[6] = 0xFF;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x07; 
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
		
	cmd[0] = 0xE9;
	cmd[1] = 0xC2;
	cmd[2] = 0x10;
	cmd[3] = 0x05;
	cmd[4] = 0x04;
	cmd[5] = 0xFE;
	cmd[6] = 0x02;
	cmd[7] = 0x81;
	cmd[8] = 0x12;
	cmd[9] = 0x31;
	cmd[10] = 0x45;
	cmd[11] = 0x3F;
	cmd[12] = 0x83;
	cmd[13] = 0x12;
	cmd[14] = 0x91;
	cmd[15] = 0x3B;
	cmd[16] = 0x2A;
	cmd[17] = 0x08;
	cmd[18] = 0x05;
	cmd[19] = 0x00;
	cmd[20] = 0x00;
	cmd[21] = 0x00;
	cmd[22] = 0x00;
	cmd[23] = 0x08;
	cmd[24] = 0x05;
	cmd[25] = 0x00;
	cmd[26] = 0x00;
	cmd[27] = 0x00;
	cmd[28] = 0x00;
	cmd[29] = 0xFF;
	cmd[30] = 0x02;
	cmd[31] = 0x46;
	cmd[32] = 0x02;
	cmd[33] = 0x48;
	cmd[34] = 0x68;
	cmd[35] = 0x88;
	cmd[36] = 0x88;
	cmd[37] = 0x88;
	cmd[38] = 0x80;
	cmd[39] = 0x88;
	cmd[40] = 0xFF;
	cmd[41] = 0x13;
	cmd[42] = 0x57;
	cmd[43] = 0x13;
	cmd[44] = 0x58;
	cmd[45] = 0x78;
	cmd[46] = 0x88;
	cmd[47] = 0x88;
	cmd[48] = 0x88;
	cmd[49] = 0x81;
	cmd[50] = 0x88;
	cmd[51] = 0x00;
	cmd[52] = 0x00;
	cmd[53] = 0x00;
	cmd[54] = 0x00;
	cmd[55] = 0x00;
	cmd[56] = 0x12;
	cmd[57] = 0xB1;
	cmd[58] = 0x3B;
	cmd[59] = 0x00;
	cmd[60] = 0x00;
	cmd[61] = 0x00;
	cmd[62] = 0x00;
	cmd[63] = 0x00;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x40; 
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
		
	cmd[0] = 0xEA;
	cmd[1] = 0x00;
	cmd[2] = 0x1A;
	cmd[3] = 0x00;
	cmd[4] = 0x00;
	cmd[5] = 0x00;
	cmd[6] = 0x00;
	cmd[7] = 0x00;
	cmd[8] = 0x00;
	cmd[9] = 0x00;
	cmd[10] = 0x00;
	cmd[11] = 0x00;
	cmd[12] = 0x00;
	cmd[13] = 0xFF;
	cmd[14] = 0x31;
	cmd[15] = 0x75;
	cmd[16] = 0x31;
	cmd[17] = 0x18;
	cmd[18] = 0x78;
	cmd[19] = 0x88;
	cmd[20] = 0x88;
	cmd[21] = 0x88;
	cmd[22] = 0x85;
	cmd[23] = 0x88;
	cmd[24] = 0xFF;
	cmd[25] = 0x20;
	cmd[26] = 0x64;
	cmd[27] = 0x20;
	cmd[28] = 0x08;
	cmd[29] = 0x68;
	cmd[30] = 0x88;
	cmd[31] = 0x88;
	cmd[32] = 0x88;
	cmd[33] = 0x84;
	cmd[34] = 0x88;
	cmd[35] = 0x20;
	cmd[36] = 0x10;
	cmd[37] = 0x00;
	cmd[38] = 0x00;
	cmd[39] = 0x54;
	cmd[40] = 0x00;
	cmd[41] = 0x00;
	cmd[42] = 0x00;
	cmd[43] = 0x00;
	cmd[44] = 0x00;
	cmd[45] = 0x00;
	cmd[46] = 0x00;
	cmd[47] = 0xC0;
	cmd[48] = 0x00;
	cmd[49] = 0x00;
	cmd[50] = 0x0C;
	cmd[51] = 0x00;
	cmd[52] = 0x00;
	cmd[53] = 0x00;
	cmd[54] = 0x00;
	cmd[55] = 0x30;
	cmd[56] = 0x02;
	cmd[57] = 0xA1;
	cmd[58] = 0x00;
	cmd[59] = 0x00;
	cmd[60] = 0x00;
	cmd[61] = 0x00;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3e; 
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
		
	cmd[0] = 0xE0;
	cmd[1] = 0x00;
	cmd[2] = 0x05;
	cmd[3] = 0x07;
	cmd[4] = 0x1A;
	cmd[5] = 0x39;
	cmd[6] = 0x3F;
	cmd[7] = 0x33;
	cmd[8] = 0x2C;
	cmd[9] = 0x06;
	cmd[10] = 0x0B;
	cmd[11] = 0x0D;
	cmd[12] = 0x11;
	cmd[13] = 0x13;
	cmd[14] = 0x12;
	cmd[15] = 0x14;
	cmd[16] = 0x10;
	cmd[17] = 0x1A;
	cmd[18] = 0x00;
	cmd[19] = 0x05;
	cmd[20] = 0x07;
	cmd[21] = 0x1A;
	cmd[22] = 0x39;
	cmd[23] = 0x3F;
	cmd[24] = 0x33;
	cmd[25] = 0x2C;
	cmd[26] = 0x06;
	cmd[27] = 0x0B;
	cmd[28] = 0x0D;
	cmd[29] = 0x11;
	cmd[30] = 0x13;
	cmd[31] = 0x12;
	cmd[32] = 0x14;
	cmd[33] = 0x10;
	cmd[34] = 0x1A;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x23; 
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
}

#endif /* End of #ifndef __RP_LCD_MIPI_5_5INCH_NEW_720X1280_H__ */
