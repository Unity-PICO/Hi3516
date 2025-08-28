#!/bin/bash
# init format
# "addr value1 value2 ..."
init=(
"01 00"
"B9 F1 12 83"
"BA 33 81 05 F9 0E 0E 20 00 00 00 00 00 00 00 44 25 00 91 0A 00 00 02 4F D1 00 00 37"
"B8 26"
"BF 02 10 00"
"B3 07 0B 1E 1E 03 FF 00 00 00 00"
"C0 73 73 50 50 00 00 08 70 00"
"BC 46"
"CC 0B"
"B4 80"
"B2 C8 12 A0"
"E3 07 07 0B 0B 03 0B 00 00 00 00 FF 80 C0 10"
"C1 53 00 32 32 77 F1 FF FF CC CC 77 77"
"B5 09 09"
"B6 B7 B7"
"E9 C2 10 0A 00 00 81 80 12 30 00 37 86 81 80 37 18 00 05 00 00 00 00 00 05 00 00 00 00 F8 BA 46 02 08 28 88 88 88 88 88 F8 BA 57 13 18 38 88 88 88 88 88 00 00 00 03 00 00 00 00 00 00 00 00 00"
"EA 07 12 01 01 02 3C 00 00 00 00 00 00 8F BA 31 75 38 18 88 88 88 88 88 8F BA 20 64 28 08 88 88 88 88 88 23 10 00 00 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"
"E0 00 02 04 1A 23 3F 2C 28 05 09 0B 10 11 10 12 12 19 00 02 04 1A 23 3F 2C 28 05 09 0B 10 11 10 12 12 19"
"11 00"
"29 00"
)

echo   "HI_S32     fd     = s32fd;
    	HI_S32     s32Ret;
    	HI_U8      cmd[30];
    	cmd_info_t cmd_info = {0};" > rp-lcd.h

n_init=${#init[*]}							#获取一维init的数组长度
for ((i=0;i<$n_init;i++));
do
	inner_init=(${init[$i]})				#将一维init字符串赋值到数组
	n_inner_init=${#inner_init[*]}			#获取二维init的数组长度

	if [ $n_inner_init -gt 2 ]; then
		#echo "inner size : $n_inner_init"

		for ((j=0;j<$n_inner_init;j++));
  		do
			#echo ${inner_init[$j]}					# 显示测试
			echo "	cmd[$j] = 0x${inner_init[$j]};" >> rp-lcd.h
  		done
		#n_inner_init_10to16=$(echo "obase=16;${n_inner_init}"|bc)
		#n_inner_init_10to16=$(printf "%x" $n_inner_init)
		#n_inner_init_10to16=$(echo "obase=16;15"|bc)
		#echo "inner size : $n_inner_init"
		#echo "$n_inner_init_10to16"
		n_inner_init_10to16=$(printf "%x" $n_inner_init)
		echo "	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x${n_inner_init_10to16}; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = cmd;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT(\"MIPI_TX SET CMD failed\\n\");
	    close(fd);
	    return;
	}
	usleep(1000);
		" >> rp-lcd.h
	elif [ $n_inner_init -eq 2 ]; then
		#echo "inner size : $n_inner_init"
		echo "	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x${inner_init[1]}${inner_init[0]}; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT(\"MIPI_TX SET CMD failed\\n\");
	    close(fd);
	    return;
	}
	usleep(1000);
		" >> rp-lcd.h
	else
		echo "error size : $n_inner_init"
	fi
done

echo "	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0011; 
	cmd_info.data_type = 0x05;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT(\"MIPI_TX SET CMD failed\\n\");
	    close(fd);
	    return;
	}
	usleep(200000);
" >> rp-lcd.h
		
echo "	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0029; 
	cmd_info.data_type = 0x05;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT(\"MIPI_TX SET CMD failed\\n\");
	    close(fd);
	    return;
	}
	usleep(1000);
" >> rp-lcd.h
