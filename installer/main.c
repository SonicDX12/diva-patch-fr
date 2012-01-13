/*
	Project DIVA Extend Patch FR based on XmbControl Inslaller on VLFlib
	Copyright (C) 2011, Dark_Alex
	Copyright (C) 2011, Frostegater
	Copyright (C) 2011, SonicDX

	main.c: XmbControl installer main code
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <pspsdk.h>
#include <pspkernel.h>
#include <vlf.h>
#include <string.h>
#include <stdio.h>
#include <kubridge.h>
#include <psputility_sysparam.h>
#include "main.h"

#include "divapatch5XX.h"
#include "divapatch6XX.h"
#include "divaext_translation.h"
#include "diva2nd0_translation.h"
#include "divaext_images.h"
#include "divaext_embedded.h"
#include "font12dot_01.h"
#include "menu_help_01.h"
#include "menu_help_02.h"
#include "menu_title_adhk.h"
#include "menu_title_crsl.h"
#include "menu_title_edit.h"
#include "menu_title_home.h"
#include "menu_title_modl.h"
#include "menu_title_msbx.h"
#include "menu_title_optn.h"
#include "menu_title_plys.h"
#include "menu_title_prvd.h"
#include "menu_title_room.h"
#include "menu_title_rtmg.h"
#include "menu_title_shop.h"
#include "menu_title_visl.h"
#include "pv_rank_01.h"
#include "pv_start_37.h"
#include "pv_start_39.h"
#include "pv_start_40.h"
#include "pv_start_41.h"
#include "pv_start_53.h"
#include "pv_start_65.h"
#include "pv_start_67.h"
#include "pv_start_68.h"
#include "pv_start_69.h"
#include "pv_start_70.h"
#include "pv_start_71.h"
#include "pv_start_72.h"
#include "pv_start_73.h"
#include "pv_start_74.h"
#include "pv_start_75.h"
#include "pv_start_76.h"
#include "pv_start_77.h"
#include "pv_start_78.h"
#include "pv_start_79.h"
#include "pv_start_80.h"
#include "pv_start_81.h"
#include "pv_start_82.h"
#include "pv_start_83.h"
#include "pv_start_84.h"
#include "pv_start_85.h"
#include "pv_start_86.h"
#include "pv_start_87.h"
#include "pv_start_88.h"
#include "pv_start_89.h"
#include "pv_start_90.h"
#include "pv_start_91.h"
#include "pv_start_92.h"
#include "pv_start_93.h"
#include "pv_start_94.h"
#include "pv_start_95.h"
#include "pv_start_96.h"
#include "pv_start_97.h"
#include "pv_start_edit.h"
#include "load_00.h"
#include "load_01.h"
#include "load_02.h"
#include "load_03.h"
#include "load_04.h"
#include "load_05.h"
#include "load_06.h"
#include "load_07.h"
#include "load_08.h"
#include "load_09.h"
#include "load_10.h"
#include "load_11.h"
#include "load_12.h"
#include "load_13.h"
#include "load_14.h"
#include "load_15.h"
#include "load_16.h"
#include "load_17.h"
#include "load_18.h"
#include "load_19.h"
#include "load_20.h"
#include "load_21.h"
#include "load_22.h"
#include "load_23.h"
#include "load_24.h"
#include "load_25.h"
#include "load_26.h"
#include "load_27.h"
#include "load_28.h"
#include "load_29.h"
#include "load_30.h"
#include "load_31.h"
#include "edit_base_04.h"
#include "home_base_02.h"
#include "menu_base_01.h"
#include "menu_result.h"
#include "mtit_base_01.h"
#include "mtit_base_02.h"
#include "mtit_base_03.h"
#include "mtit_base_04.h"
#include "mtit_base_05.h"
#include "plst_base_01.h"
#include "diva2nd0_images.h"
#include "menu_result2nd0.h"
#include "pv_start_01.h"
#include "pv_start_04.h"
#include "pv_start_06.h"
#include "pv_start_09.h"
#include "pv_start_11.h"
#include "pv_start_13.h"
#include "pv_start_16.h"
#include "pv_start_17.h"
#include "pv_start_18.h"
#include "pv_start_19.h"
#include "pv_start_20.h"
#include "pv_start_21.h"
#include "pv_start_22.h"
#include "pv_start_23.h"
#include "pv_start_24.h"
#include "pv_start_27.h"
#include "pv_start_36.h"
#include "pv_start_38.h"
#include "pv_start_42.h"
#include "pv_start_43.h"
#include "pv_start_44.h"
#include "pv_start_45.h"
#include "pv_start_46.h"
#include "pv_start_47.h"
#include "pv_start_48.h"
#include "pv_start_49.h"
#include "pv_start_50.h"
#include "pv_start_51.h"
#include "pv_start_52.h"
#include "pv_start_54.h"
#include "pv_start_55.h"
#include "pv_start_56.h"
#include "pv_start_57.h"
#include "pv_start_58.h"
#include "pv_start_59.h"
#include "pv_start_60.h"
#include "pv_start_61.h"
#include "pv_start_62.h"
#include "pv_start_63.h"
#include "pv_start_64.h"
#include "pv_start_66.h"

PSP_MODULE_INFO("Diva Patch FR", 0, 1, 5);
PSP_MAIN_THREAD_ATTR(0);

void Install();
void Credits_Changelog(int changelog);
void SysInfo();
void MainMenu(int sel, int start);

int progress_text = -1, progress_bar = -1;
int status = -1;
int last_percentage = -1;
int last_time;
char pg_text[20];
char st_text[128];

int devkit, point;
u16 macaddrfd[64], fwverfd[64];
int focus, psp_model;
char *path[200];
int enter_button = 0;
extern int currdev;
extern char *cpath;
int plus;


#define NUM_DEL_ITEMS_CREDITS_CHANGELOG 1
VlfText text_credits_changelog[NUM_DEL_ITEMS_CREDITS_CHANGELOG];

#define NUM_DEL_ITEMS_TEXTEDITOR 3
VlfText text_texteditor[NUM_DEL_ITEMS_TEXTEDITOR];

VlfText title_text;
VlfPicture title_pic;
VlfInputBox fwversion, macaddr;

#define ENTER_CIRCLE 0

int DoProgressUpdate(void *param)
{
	vlfGuiProgressBarSetProgress(progress_bar, last_percentage);
	vlfGuiSetText(progress_text, pg_text);
	
	return VLF_EV_RET_REMOVE_HANDLERS;
}

void ClearProgress()
{
	last_time = 0;
	last_percentage = -1;
}

void SetProgress(int percentage, int force)
{
	int st =  sceKernelGetSystemTimeLow();
	
	if (force || (percentage > last_percentage && st >= (last_time+520000)))
	{		
		sprintf(pg_text, "%d%%", percentage);
		last_percentage = percentage;
		last_time = st;
		vlfGuiAddEventHandler(0, -1, DoProgressUpdate, NULL);
		
	}
}

int OnInstallComplete(void *param)
{
	vlfGuiRemoveText(status);
	vlfGuiRemoveProgressBar(progress_bar);
	vlfGuiRemoveText(progress_text);

	vlfGuiMessageDialog("Installation fini!", VLF_MD_TYPE_NORMAL | VLF_MD_BUTTONS_NONE);

	progress_bar = -1;
	progress_text = -1;	
	status = -1;
	
	MainMenu(0,NULL);
	
	return VLF_EV_RET_REMOVE_HANDLERS;
}

int ReadFile(char *file, void *buf, int size, int seek)
{
    SceUID fd = sceIoOpen(file, PSP_O_RDONLY, 0);
	
	int read = -1;

	if(fd >= 0)
    {
		sceIoLseek(fd, seek, PSP_SEEK_SET);
		read = sceIoRead(fd, buf, size);
		sceIoClose(fd);
	}

    return read;
}

int WriteFile(char *file, void *buf, int size, int seek)
{
    SceUID fd = sceIoOpen(file, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);

	int write = -1;

    if(fd >= 0)
    {
		sceIoLseek(fd, seek, PSP_SEEK_SET);
        write = sceIoWrite(fd, buf, size);
        sceIoClose(fd);
    }

	return write;
}

static u8 g_buf[64*1024] __attribute__((aligned(64)));
int copy_file(const char *src, const char *dst)
{
	SceUID fd = -1, fdw = -1;
	int ret;

	ret = sceIoOpen(src, PSP_O_RDONLY, 0777);

	if(ret < 0)
		goto error;

	fd = ret;
	ret = sceIoOpen(dst, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);

	if(ret < 0)
		goto error;

	fdw = ret;
	ret = sizeof(g_buf);
	ret = sceIoRead(fd, g_buf, ret);

	while(ret > 0)
	{
		ret = sceIoWrite(fdw, g_buf, ret);
		if (ret < 0)
			goto error;

		ret = sceIoRead(fd, g_buf, ret);
	}

	if(ret < 0)
		goto error;

	sceIoClose(fd);
	sceIoClose(fdw);

	return 0;

error:
	sceIoClose(fd);
	sceIoClose(fdw);

	return ret;
}

int OnCredits_Changelog(int enter)
{
	if(!enter)
	{
		int i;
		for(i = 0; i < NUM_DEL_ITEMS_CREDITS_CHANGELOG; i++)
			vlfGuiRemoveText(text_credits_changelog[i]);

		if(enter_button != ENTER_CIRCLE) /* CROSS */
			vlfGuiCancelBottomDialog();

		MainMenu(point, 0);		
	}

	return VLF_EV_RET_NOTHING;
}

int install_thread(SceSize args, void *argp)
{
	char buffer[1024];	
	memset(buffer, 0, sizeof(buffer));

	int size = ReadFile(path[2], buffer, sizeof(buffer), 0);

	ClearProgress();
    status = vlfGuiAddText(80, 100, "Installation en cours...");
    progress_bar = vlfGuiAddProgressBar(136);    
    progress_text = vlfGuiAddText(240, 148, "0%");
    vlfGuiSetTextAlignment(progress_text, VLF_ALIGNMENT_CENTER);
	
	if(sceIoDopen(path[0]) < 0)
		sceIoMkdir(path[0], 0777);
	
	if(sceIoDopen(path[1]) < 0)
		sceIoMkdir(path[1], 0777);	
		
	if(sceIoDopen(path[107]) < 0)
		sceIoMkdir(path[107], 0777);
		
	if(size < 0)
		WriteFile(path[2], path[3], 41, 0);
	else
	{
		if(!strstr(buffer, path[4]))
		{
			strcat(buffer, path[plus ? 3 : 5]);
			WriteFile(path[2], buffer, size + (plus ? 41 : 43), 0);
		}
	}
	
	if(sceKernelDevkitVersion() == 0x05000010 || sceKernelDevkitVersion() == 0x05050010)
	WriteFile(path[109], (void *)divapatch5XX, size_divapatch5XX, 0);
	else if(sceKernelDevkitVersion() == 0x06020010 || sceKernelDevkitVersion() == 0x06030510 || sceKernelDevkitVersion() == 0x06030910 || sceKernelDevkitVersion() == 0x06060010)
	WriteFile(path[4], (void *)divapatch6XX, size_divapatch6XX, 0);
	
	WriteFile(path[6], (void *)divaext_translation, size_divaext_translation, 0);
	WriteFile(path[7], (void *)divaext_images, size_divaext_images, 0);
	WriteFile(path[8], (void *)divaext_embedded, size_divaext_embedded, 0);
	WriteFile(path[9], (void *)font12dot_01, size_font12dot_01, 0);
	WriteFile(path[10], (void *)menu_help_01, size_menu_help_01, 0);
	sceKernelDelayThread(1200000);
	SetProgress(10, 1);
	WriteFile(path[11], (void *)menu_help_02, size_menu_help_02, 0);
	WriteFile(path[12], (void *)menu_title_adhk, size_menu_title_adhk, 0);
	WriteFile(path[13], (void *)menu_title_crsl, size_menu_title_crsl, 0);
	WriteFile(path[14], (void *)menu_title_edit, size_menu_title_edit, 0);
	WriteFile(path[15], (void *)menu_title_home, size_menu_title_home, 0);
	WriteFile(path[16], (void *)menu_title_modl, size_menu_title_modl, 0);
	WriteFile(path[17], (void *)menu_title_msbx, size_menu_title_msbx, 0);
	WriteFile(path[18], (void *)menu_title_optn, size_menu_title_optn, 0);
	WriteFile(path[19], (void *)menu_title_plys, size_menu_title_plys, 0);
	WriteFile(path[20], (void *)menu_title_prvd, size_menu_title_prvd, 0);
	sceKernelDelayThread(1200000);
	SetProgress(20, 1);
	WriteFile(path[21], (void *)menu_title_room, size_menu_title_room, 0);
	WriteFile(path[22], (void *)menu_title_rtmg, size_menu_title_rtmg, 0);
	WriteFile(path[23], (void *)menu_title_shop, size_menu_title_shop, 0);
	WriteFile(path[24], (void *)menu_title_visl, size_menu_title_visl, 0);
	WriteFile(path[25], (void *)pv_rank_01, size_pv_rank_01, 0);
	WriteFile(path[26], (void *)pv_start_37, size_pv_start_37, 0);
	WriteFile(path[27], (void *)pv_start_39, size_pv_start_39, 0);
	WriteFile(path[28], (void *)pv_start_40, size_pv_start_40, 0);
	WriteFile(path[29], (void *)pv_start_41, size_pv_start_41, 0);
	WriteFile(path[30], (void *)pv_start_53, size_pv_start_53, 0);
	sceKernelDelayThread(1200000);
	SetProgress(30, 1);
	WriteFile(path[31], (void *)pv_start_65, size_pv_start_65, 0);
	WriteFile(path[32], (void *)pv_start_67, size_pv_start_67, 0);
	WriteFile(path[33], (void *)pv_start_68, size_pv_start_68, 0);
	WriteFile(path[34], (void *)pv_start_69, size_pv_start_69, 0);
	WriteFile(path[35], (void *)pv_start_70, size_pv_start_70, 0);
	WriteFile(path[36], (void *)pv_start_71, size_pv_start_71, 0);
	WriteFile(path[37], (void *)pv_start_72, size_pv_start_72, 0);
	WriteFile(path[38], (void *)pv_start_73, size_pv_start_73, 0);
	WriteFile(path[39], (void *)pv_start_74, size_pv_start_74, 0);
	WriteFile(path[40], (void *)pv_start_75, size_pv_start_75, 0);
	sceKernelDelayThread(1200000);
	SetProgress(40, 1);
	WriteFile(path[41], (void *)pv_start_76, size_pv_start_76, 0);
	WriteFile(path[42], (void *)pv_start_77, size_pv_start_77, 0);
	WriteFile(path[43], (void *)pv_start_78, size_pv_start_78, 0);
	WriteFile(path[44], (void *)pv_start_79, size_pv_start_79, 0);
	WriteFile(path[45], (void *)pv_start_80, size_pv_start_80, 0);
	WriteFile(path[46], (void *)pv_start_81, size_pv_start_81, 0);
	WriteFile(path[47], (void *)pv_start_82, size_pv_start_82, 0);
	WriteFile(path[48], (void *)pv_start_83, size_pv_start_83, 0);
	WriteFile(path[49], (void *)pv_start_84, size_pv_start_84, 0);
	WriteFile(path[50], (void *)pv_start_85, size_pv_start_85, 0);
	sceKernelDelayThread(1200000);
	SetProgress(50, 1);
	WriteFile(path[51], (void *)pv_start_86, size_pv_start_86, 0);
	WriteFile(path[52], (void *)pv_start_87, size_pv_start_87, 0);
	WriteFile(path[53], (void *)pv_start_88, size_pv_start_88, 0);
	WriteFile(path[54], (void *)pv_start_89, size_pv_start_89, 0);
	WriteFile(path[55], (void *)pv_start_90, size_pv_start_90, 0);
	WriteFile(path[56], (void *)pv_start_91, size_pv_start_91, 0);
	WriteFile(path[57], (void *)pv_start_92, size_pv_start_92, 0);
	WriteFile(path[58], (void *)pv_start_93, size_pv_start_93, 0);
	WriteFile(path[59], (void *)pv_start_94, size_pv_start_94, 0);
	WriteFile(path[60], (void *)pv_start_95, size_pv_start_95, 0);
	sceKernelDelayThread(1200000);
	SetProgress(60, 1);
	WriteFile(path[61], (void *)pv_start_96, size_pv_start_96, 0);
	WriteFile(path[62], (void *)pv_start_97, size_pv_start_97, 0);
	WriteFile(path[63], (void *)pv_start_edit, size_pv_start_edit, 0);
	WriteFile(path[64], (void *)load_00, size_load_00, 0);
	WriteFile(path[65], (void *)load_01, size_load_01, 0);
	WriteFile(path[66], (void *)load_02, size_load_02, 0);
	WriteFile(path[67], (void *)load_03, size_load_03, 0);
	WriteFile(path[68], (void *)load_04, size_load_04, 0);
	WriteFile(path[69], (void *)load_05, size_load_05, 0);
	WriteFile(path[70], (void *)load_06, size_load_06, 0);
	sceKernelDelayThread(1200000);
	SetProgress(70, 1);
	WriteFile(path[71], (void *)load_07, size_load_07, 0);
	WriteFile(path[72], (void *)load_08, size_load_08, 0);
	WriteFile(path[73], (void *)load_09, size_load_09, 0);
	WriteFile(path[74], (void *)load_10, size_load_10, 0);
	WriteFile(path[75], (void *)load_11, size_load_11, 0);
	WriteFile(path[76], (void *)load_12, size_load_12, 0);
	WriteFile(path[77], (void *)load_13, size_load_13, 0);
	WriteFile(path[78], (void *)load_14, size_load_14, 0);
	WriteFile(path[79], (void *)load_15, size_load_15, 0);
	WriteFile(path[80], (void *)load_16, size_load_16, 0);
	sceKernelDelayThread(1200000);
	SetProgress(80, 1);
	WriteFile(path[81], (void *)load_17, size_load_17, 0);
	WriteFile(path[82], (void *)load_18, size_load_18, 0);
	WriteFile(path[83], (void *)load_19, size_load_19, 0);
	WriteFile(path[84], (void *)load_20, size_load_20, 0);
	WriteFile(path[85], (void *)load_21, size_load_21, 0);
	WriteFile(path[86], (void *)load_22, size_load_22, 0);
	WriteFile(path[87], (void *)load_23, size_load_23, 0);
	WriteFile(path[88], (void *)load_24, size_load_24, 0);
	WriteFile(path[89], (void *)load_25, size_load_25, 0);
	WriteFile(path[90], (void *)load_26, size_load_26, 0);
	sceKernelDelayThread(1200000);
	SetProgress(90, 1);
	WriteFile(path[91], (void *)load_27, size_load_27, 0);
	WriteFile(path[92], (void *)load_28, size_load_28, 0);
	WriteFile(path[93], (void *)load_29, size_load_29, 0);
	WriteFile(path[94], (void *)load_30, size_load_30, 0);
	WriteFile(path[95], (void *)load_31, size_load_31, 0);
	WriteFile(path[96], (void *)edit_base_04, size_edit_base_04, 0);
	WriteFile(path[97], (void *)home_base_02, size_home_base_02, 0);
	WriteFile(path[98], (void *)menu_base_01, size_menu_base_01, 0);
	WriteFile(path[99], (void *)menu_result, size_menu_result, 0);
	WriteFile(path[100], (void *)mtit_base_01, size_mtit_base_01, 0);
	WriteFile(path[101], (void *)mtit_base_02, size_mtit_base_02, 0);
	WriteFile(path[102], (void *)mtit_base_03, size_mtit_base_03, 0);
	WriteFile(path[103], (void *)mtit_base_04, size_mtit_base_04, 0);
	WriteFile(path[104], (void *)mtit_base_05, size_mtit_base_05, 0);
	WriteFile(path[105], (void *)plst_base_01, size_plst_base_01, 0);
	
	if(sceKernelDevkitVersion() == 0x05000010 || sceKernelDevkitVersion() == 0x05050010)
	WriteFile(path[109], (void *)divapatch5XX, size_divapatch5XX, 0);
	else if(sceKernelDevkitVersion() == 0x06020010 || sceKernelDevkitVersion() == 0x06030510 || sceKernelDevkitVersion() == 0x06030910 || sceKernelDevkitVersion() == 0x06060010)
	WriteFile(path[4], (void *)divapatch6XX, size_divapatch6XX, 0);
	sceKernelDelayThread(1200000);	
	SetProgress(100, 1);
	
	vlfGuiAddEventHandler(0, 600000, OnInstallComplete, NULL);
	return sceKernelExitDeleteThread(0);
}

int install_thread2(SceSize args, void *argp)
{
	devkit = sceKernelDevkitVersion();
	char buffer[1024];	
	memset(buffer, 0, sizeof(buffer));

	int size = ReadFile(path[2], buffer, sizeof(buffer), 0);

	ClearProgress();
    status = vlfGuiAddText(80, 100, "Installation en cours...");
    progress_bar = vlfGuiAddProgressBar(136);    
    progress_text = vlfGuiAddText(240, 148, "0%");
    vlfGuiSetTextAlignment(progress_text, VLF_ALIGNMENT_CENTER);
	
	if(sceIoDopen(path[0]) < 0)
		sceIoMkdir(path[0], 0777);
	
	if(sceIoDopen(path[1]) < 0)
		sceIoMkdir(path[1], 0777);	
		
	if(sceIoDopen(path[108]) < 0)
		sceIoMkdir(path[108], 0777);
		
	if(size < 0)
		WriteFile(path[2], path[3], 41, 0);
	else
	{
		if(!strstr(buffer, path[4]))
		{
			strcat(buffer, path[plus ? 3 : 5]);
			WriteFile(path[2], buffer, size + (plus ? 41 : 43), 0);
		}
	}
	
	if(sceKernelDevkitVersion() == 0x05000010 || sceKernelDevkitVersion() == 0x05050010)
	WriteFile(path[109], (void *)divapatch5XX, size_divapatch5XX, 0);
	else if(sceKernelDevkitVersion() == 0x06020010 || sceKernelDevkitVersion() == 0x06030510 || sceKernelDevkitVersion() == 0x06030910 || sceKernelDevkitVersion() == 0x06060010)
	WriteFile(path[4], (void *)divapatch6XX, size_divapatch6XX, 0);
	
	WriteFile(path[106], (void *)diva2nd0_translation, size_diva2nd0_translation, 0);
	WriteFile(path[110], (void *)diva2nd0_images, size_diva2nd0_images, 0);
	WriteFile(path[111], (void *)font12dot_01, size_font12dot_01, 0);
	WriteFile(path[112], (void *)menu_help_01, size_menu_help_01, 0);
	WriteFile(path[113], (void *)menu_help_02, size_menu_help_02, 0);
	WriteFile(path[114], (void *)menu_title_adhk, size_menu_title_adhk, 0);
	WriteFile(path[115], (void *)menu_title_crsl, size_menu_title_crsl, 0);
	WriteFile(path[116], (void *)menu_title_edit, size_menu_title_edit, 0);
	WriteFile(path[117], (void *)menu_title_home, size_menu_title_home, 0);
	WriteFile(path[118], (void *)menu_title_modl, size_menu_title_modl, 0);
	WriteFile(path[119], (void *)menu_title_msbx, size_menu_title_msbx, 0);
	WriteFile(path[120], (void *)menu_title_optn, size_menu_title_optn, 0);
	WriteFile(path[121], (void *)menu_title_plys, size_menu_title_plys, 0);
	WriteFile(path[122], (void *)menu_title_prvd, size_menu_title_prvd, 0);
	WriteFile(path[123], (void *)menu_title_room, size_menu_title_room, 0);
	WriteFile(path[124], (void *)menu_title_rtmg, size_menu_title_rtmg, 0);
	WriteFile(path[125], (void *)menu_title_shop, size_menu_title_shop, 0);
	sceKernelDelayThread(1200000);
	SetProgress(25, 1);
	WriteFile(path[126], (void *)menu_title_visl, size_menu_title_visl, 0);
	WriteFile(path[127], (void *)pv_rank_01, size_pv_rank_01, 0);
	WriteFile(path[128], (void *)edit_base_04, size_edit_base_04, 0);
	//WriteFile(path[129], (void *)home_base_02, size_home_base_02, 0);
	WriteFile(path[130], (void *)menu_base_01, size_menu_base_01, 0);
	WriteFile(path[131], (void *)menu_result2nd0, size_menu_result2nd0, 0);
	WriteFile(path[132], (void *)mtit_base_01, size_mtit_base_01, 0);
	WriteFile(path[133], (void *)mtit_base_02, size_mtit_base_02, 0);
	WriteFile(path[134], (void *)mtit_base_03, size_mtit_base_03, 0);
	WriteFile(path[135], (void *)plst_base_01, size_plst_base_01, 0);
	WriteFile(path[136], (void *)pv_start_01, size_pv_start_01, 0);
	WriteFile(path[137], (void *)pv_start_04, size_pv_start_04, 0);
	WriteFile(path[138], (void *)pv_start_06, size_pv_start_06, 0);
	WriteFile(path[139], (void *)pv_start_09, size_pv_start_09, 0);
	WriteFile(path[140], (void *)pv_start_11, size_pv_start_11, 0);
	WriteFile(path[141], (void *)pv_start_13, size_pv_start_13, 0);
	WriteFile(path[142], (void *)pv_start_16, size_pv_start_16, 0);
	WriteFile(path[143], (void *)pv_start_17, size_pv_start_17, 0);
	WriteFile(path[144], (void *)pv_start_18, size_pv_start_18, 0);
	WriteFile(path[145], (void *)pv_start_19, size_pv_start_19, 0);
	sceKernelDelayThread(1200000);
	SetProgress(50, 1);
	WriteFile(path[146], (void *)pv_start_20, size_pv_start_20, 0);
	WriteFile(path[147], (void *)pv_start_21, size_pv_start_21, 0);
	WriteFile(path[148], (void *)pv_start_22, size_pv_start_22, 0);
	WriteFile(path[149], (void *)pv_start_23, size_pv_start_23, 0);
	WriteFile(path[150], (void *)pv_start_24, size_pv_start_24, 0);
	WriteFile(path[151], (void *)pv_start_27, size_pv_start_27, 0);
	WriteFile(path[152], (void *)pv_start_36, size_pv_start_36, 0);
	WriteFile(path[153], (void *)pv_start_37, size_pv_start_37, 0);
	WriteFile(path[154], (void *)pv_start_38, size_pv_start_38, 0);
	WriteFile(path[155], (void *)pv_start_39, size_pv_start_39, 0);
	WriteFile(path[156], (void *)pv_start_40, size_pv_start_40, 0);
	WriteFile(path[157], (void *)pv_start_41, size_pv_start_41, 0);
	WriteFile(path[158], (void *)pv_start_42, size_pv_start_42, 0);
	WriteFile(path[159], (void *)pv_start_43, size_pv_start_43, 0);
	WriteFile(path[160], (void *)pv_start_44, size_pv_start_44, 0);
	WriteFile(path[161], (void *)pv_start_45, size_pv_start_45, 0);
	WriteFile(path[162], (void *)pv_start_46, size_pv_start_46, 0);
	WriteFile(path[163], (void *)pv_start_47, size_pv_start_47, 0);
	WriteFile(path[164], (void *)pv_start_48, size_pv_start_48, 0);
	WriteFile(path[165], (void *)pv_start_49, size_pv_start_49, 0);
	WriteFile(path[166], (void *)pv_start_50, size_pv_start_50, 0);
	sceKernelDelayThread(1200000);
	SetProgress(75, 1);
	WriteFile(path[167], (void *)pv_start_51, size_pv_start_51, 0);
	WriteFile(path[168], (void *)pv_start_52, size_pv_start_52, 0);
	WriteFile(path[169], (void *)pv_start_53, size_pv_start_53, 0);
	WriteFile(path[170], (void *)pv_start_54, size_pv_start_54, 0);
	WriteFile(path[171], (void *)pv_start_55, size_pv_start_55, 0);
	WriteFile(path[172], (void *)pv_start_56, size_pv_start_56, 0);
	WriteFile(path[173], (void *)pv_start_57, size_pv_start_57, 0);
	WriteFile(path[174], (void *)pv_start_58, size_pv_start_58, 0);
	WriteFile(path[175], (void *)pv_start_59, size_pv_start_59, 0);
	WriteFile(path[176], (void *)pv_start_60, size_pv_start_60, 0);
	WriteFile(path[177], (void *)pv_start_61, size_pv_start_61, 0);
	WriteFile(path[178], (void *)pv_start_62, size_pv_start_62, 0);
	WriteFile(path[179], (void *)pv_start_63, size_pv_start_63, 0);
	WriteFile(path[180], (void *)pv_start_64, size_pv_start_64, 0);
	WriteFile(path[181], (void *)pv_start_65, size_pv_start_65, 0);
	WriteFile(path[182], (void *)pv_start_66, size_pv_start_66, 0);
	WriteFile(path[183], (void *)pv_start_edit, size_pv_start_edit, 0);
	
	if(sceKernelDevkitVersion() == 0x05000010 || sceKernelDevkitVersion() == 0x05050010)
	WriteFile(path[109], (void *)divapatch5XX, size_divapatch5XX, 0);
	else if(sceKernelDevkitVersion() == 0x06020010 || sceKernelDevkitVersion() == 0x06030510 || sceKernelDevkitVersion() == 0x06030910 || sceKernelDevkitVersion() == 0x06060010)
	WriteFile(path[4], (void *)divapatch6XX, size_divapatch6XX, 0);
	
	sceKernelDelayThread(1200000);	
	SetProgress(100, 1);
	
	vlfGuiAddEventHandler(0, 600000, OnInstallComplete, NULL);
	return sceKernelExitDeleteThread(0);
}

void installing_extend()
{
	SceUID install_thid = sceKernelCreateThread("install_thread", install_thread, 0x18, 0x10000, 0, NULL);// Dark_Alex's antifreeze method.
	if(install_thid >= 0)
		sceKernelStartThread(install_thid, 4, NULL);
	
	}
	
void installing_2nd0()
{
	SceUID install_thid = sceKernelCreateThread("install_thread2", install_thread2, 0x18, 0x10000, 0, NULL);// Dark_Alex's antifreeze method.
	if(install_thid >= 0)
		sceKernelStartThread(install_thid, 4, NULL);
	
	}

int menu_sel(int sel)
{
	int read;

	switch (sel)
	{
		case 0:
			vlfGuiCancelCentralMenu();
			installing_extend();
			break;
			
		case 1:
			vlfGuiCancelCentralMenu();
			installing_2nd0();
			break;

		case 2:
			point = 1;
			Credits_Changelog(1);
			return VLF_EV_RET_REMOVE_HANDLERS | VLF_EV_RET_REMOVE_OBJECTS;

		case 3:
			point = 2;
			Credits_Changelog(2);
			return VLF_EV_RET_REMOVE_HANDLERS | VLF_EV_RET_REMOVE_OBJECTS;
		
		case 4:
			sceKernelExitGame();
			break;
	}
	
	return VLF_EV_RET_NOTHING;
}

void MainMenu(int sel, int start)
{	
	if(!start)
	{
		vlfGuiRemoveText(title_text);
		vlfGuiRemovePicture(title_pic);
	}

	title_text = vlfGuiAddText(1, 1, "Diva Patch FR Installer v3.1      (13/01/2012)");
	title_pic = vlfGuiAddPictureResource("ps3scan_plugin.rco", "tex_infobar_icon", 4, -2);
	vlfGuiSetTitleBar(title_text, title_pic, 1, 1);

	char *items[] = { "Installer le patch Extend FR", "Installer le patch 2nd# FR", "Changelog", "Credits", "Quitter" };

	vlfGuiCentralMenu(sizeof(items) / sizeof(char *), items, sel, menu_sel, 0, 0);

	if(enter_button == ENTER_CIRCLE)
	{
		vlfGuiCustomBottomDialog(NULL, "Entrer", 1, 0, VLF_DEFAULT, NULL);
		vlfGuiCancelBottomDialog();
	}

	vlfGuiCustomBottomDialog(NULL, "Entrer", 1, 0, VLF_DEFAULT, NULL);
}


void Credits_Changelog(int changelog)
{
	vlfGuiCustomBottomDialog("Retour", NULL, 1, 0, VLF_DEFAULT, NULL);
	vlfGuiCancelBottomDialog();
	vlfGuiCustomBottomDialog("Retour", NULL, 1, 0, VLF_DEFAULT, OnCredits_Changelog);
	
	vlfGuiRemoveText(title_text);
	vlfGuiRemovePicture(title_pic);
	
	title_text = vlfGuiAddText(35, 1, point != 2 ? "Changelog" : "Credits");
	title_pic = vlfGuiAddPictureResource("ps3scan_plugin.rco", "tex_infobar_icon", 4, -2);
	vlfGuiSetTitleBar(title_text, title_pic, 1, 1);

	char *crchtext;
	int x;
	if(changelog)
	{
		crchtext =
			"(TEST)\n"
			" - Version de base.\n\n"
			"(12/11/11)\n"
			" - Traduction des éléments de la Chambre DIVA.\n\n"
			"(14/11/11)\n"
			" - Traduction des Objets et Chambres.\n"
			" - Traduction des Options.\n"
			" - Traduction de la Boutique.\n"
			" - Traduction d'une partie du mode Ad Hoc.\n\n"
			"(17/11/11)\n"
			" - Ajout de la traduction du textes des images\n"
			" - Petites corrections de traduction.\n\n"
			"(18/11/11)\n"
			" - Ajout des accents dans la traduction.\n"
			"    (Merci DarkCenobyte pour le font!)\n\n"
			"(20/11/11)\n"
			" - Traduction des écrans juste avant de commencer\n"
			"    une chanson ainsi que les conditions de résultats\n"
			" - Petites corrections de traduction sur les infos de\n"
			"    touches.\n\n"
			"(24/11/11)\n"
			" - Traduction d'une partie du mode EDIT.\n"
			" - Correction de traduction par Reload.\n"
			" - Nouvelles images pour les titres et les rangs par\n"
			"    DarkCenobyte.\n\n"
			"(26/11/11)\n"
			" - Le mode EDIT traduit à 80%. (Merci Staz et Kienono\n"
			"    de leur aide)\n"
			" - Nouveau font par DarkCenobyte donc plus de bug dans\n"
			"    les PV, EDIT, Stats.\n"
			" - Ajout de la possibilité de changer les écrans de\n"
			"    chargement. (Fonction NON TESTE! Plus de détails sur\n"
			"    le topic)\n\n"
			"(27/11/11)\n"
			" - Traduction des éléments non traduits encore du mode\n"
			"    EDIT par Kienono\n"
			" - Correction des fautes d'orthographe et synthaxe\n\n"
			"(03/12/11)\n"
			" - Ajout des écrans de chargement restant. Vous pouvez\n"
			"    tous les modifier maintenant\n"
			" - Ajout de la traduction des mouvements pour le\n"
			"    mode EDIT. (Une partie)\n"
			" - Traduction d'une partie du menu Statistique et\n"
			"    des titres\n"
			" - Possibilité de traduire les paroles des chansons\n"
			"    (Sekiranun Graffiti en anglais et d'autres en\n"
			"     en romaji pour le moment)\n"
			" - Mise à jour de l'installer avec une barre de\n"
			"    progression (Demande de Shadow-san)\n\n"
			"(12/12/11)\n"
			" - Suite de la traduction du mode EDIT avec la liste\n"
			"    des fonds, objets, effets ainsi que de nouveaux\n"
			"    menus.\n"
			" - Traduction des descriptions des titres.\n"
			" - Traduction des menus manquants de la Chambre DIVA.\n"
			" - Traduction du SFO et des menus propres de la PSP\n"
			"    (Sauvegarder, Charger, Quitter le jeu?, etc)\n\n"
			"(17/12/11)\n"
			" - Traduction de menus non traduit du mode EDIT.\n"
			" - Correction de fautes et syntaxe.\n"
			" - Traduction de nouvelles images comme l'écran des\n"
			"    résultats et du profil.\n"
			" - Correction des anciennes images.\n\n"
			"(03/01/12)\n"
			" - Mise à jour de l'installer avec l'ajout de la\n"
			"    traduction de 2nd#. Deux versions de l'installer\n"
			"    sera disponible: une pour les CFW 6.XX et\n"
			"    une autre pour les CFW 5.XX\n"
			" - Traduction de nouvelles lyrics pour Extend.\n"
			" - Divers corrections pour Extend.\n"
			" - Debut de traduction FR pour 2nd#.\n\n"
			"(05/01/12)\n"
			" - Mise à jour de l'installer qui supporte\n"
			"    désormais les 2 versions en un seul homebrew.\n"
			" - Ajouts des traductions des images pour 2nd#.\n"
			"    (Reste les écrans avant de débuter une chanson\n"
			"    à traduire)\n"
			" - Correction d'accents pour Extend.\n\n"
			"(13/01/12)\n"
			" - Les pv_start, ou écran avant de commancer la\n"
			"     chanson, pour 2nd# sont traduits.\n"
			" - Les Objets-Aides pour 2nd# sont traduits\n"
			" - Les écrans lorsqu'on fait <<New Game>> qui\n"
			"    concerne l'import de sauvegarde, l'auto-save,\n"
			"    etc... sont traduits pour 2nd# et Extend (sauf\n"
			"    un bout pour Extend où j'ai pas compris)";
		x = 35;
	}
	else
	{
		crchtext =
			"Diva Patch Installer v3.1\n"
			"Copyright(C) 2011, Sonic DX\n\n"
			"   Credits:\n"
			"     - Codestation\n"// Plugin, Eboot reversing
			"     - Frostegater\n\n"// Installer
			"   Merci:\n"
			"     - Moi, Sonic DX\n"// fr translate, Eboot reversing
			"     - Reload\n"// fr translate
			"     - DarkCenobyte\n"// Pictures
			"     - Staz\n"// fr translate
			"     - Kienono\n"// fr translate
			"     - Sonic-San\n";
		x = 140;
	}
	text_credits_changelog[0] = vlfGuiAddText(x, 60, crchtext);		
	vlfGuiSetTextScrollBar(text_credits_changelog[0],  150);
	int i;
	for(i = 0; i < NUM_DEL_ITEMS_CREDITS_CHANGELOG; i++)
		vlfGuiSetTextFontSize(text_credits_changelog[i], 0.75f);
}

int app_main(int argc, char *argv[])
{
	psp_model = kuKernelGetModel();

	if(psp_model == 4 && currdev != MEMORY_STICK)
	{
		path[0] = "ef0:/seplugins";
		path[1] = "ef0:/seplugins/divapatch";
		path[2] = "ef0:/seplugins/game.txt";
		path[3] = "ef0:/seplugins/divapatch/divapatch.prx 1";
		path[4] = "ef0:/seplugins/divapatch/divapatch.prx";
		path[5] = "\r\nef0:/seplugins/divapatch/divapatch.prx 1";
		path[6] = "ef0:/seplugins/divapatch/divaext_translation.bin";
		path[7] = "ef0:/seplugins/divapatch/divaext_images.bin";
		path[8] = "ef0:/seplugins/divapatch/divaext_embedded.bin";
		path[9] = "ef0:/seplugins/divapatch/divaext/font12dot_01.png";
		path[10] = "ef0:/seplugins/divapatch/divaext/menu_help_01.png";
		path[11] = "ef0:/seplugins/divapatch/divaext/menu_help_02.png";
		path[12] = "ef0:/seplugins/divapatch/divaext/menu_title_adhk.png";
		path[13] = "ef0:/seplugins/divapatch/divaext/menu_title_crsl.png";
		path[14] = "ef0:/seplugins/divapatch/divaext/menu_title_edit.png";
		path[15] = "ef0:/seplugins/divapatch/divaext/menu_title_home.png";
		path[16] = "ef0:/seplugins/divapatch/divaext/menu_title_modl.png";
		path[17] = "ef0:/seplugins/divapatch/divaext/menu_title_msbx.png";
		path[18] = "ef0:/seplugins/divapatch/divaext/menu_title_optn.png";
		path[19] = "ef0:/seplugins/divapatch/divaext/menu_title_plys.png";
		path[20] = "ef0:/seplugins/divapatch/divaext/menu_title_prvd.png";
		path[21] = "ef0:/seplugins/divapatch/divaext/menu_title_room.png";
		path[22] = "ef0:/seplugins/divapatch/divaext/menu_title_rtmg.png";
		path[23] = "ef0:/seplugins/divapatch/divaext/menu_title_shop.png";
		path[24] = "ef0:/seplugins/divapatch/divaext/menu_title_visl.png";
		path[25] = "ef0:/seplugins/divapatch/divaext/pv_rank_01.png";
		path[26] = "ef0:/seplugins/divapatch/divaext/pv_start_37.png";
		path[27] = "ef0:/seplugins/divapatch/divaext/pv_start_39.png";
		path[28] = "ef0:/seplugins/divapatch/divaext/pv_start_40.png";
		path[29] = "ef0:/seplugins/divapatch/divaext/pv_start_41.png";
		path[30] = "ef0:/seplugins/divapatch/divaext/pv_start_53.png";
		path[31] = "ef0:/seplugins/divapatch/divaext/pv_start_65.png";
		path[32] = "ef0:/seplugins/divapatch/divaext/pv_start_67.png";
		path[33] = "ef0:/seplugins/divapatch/divaext/pv_start_68.png";
		path[34] = "ef0:/seplugins/divapatch/divaext/pv_start_69.png";
		path[35] = "ef0:/seplugins/divapatch/divaext/pv_start_70.png";
		path[36] = "ef0:/seplugins/divapatch/divaext/pv_start_71.png";
		path[37] = "ef0:/seplugins/divapatch/divaext/pv_start_72.png";
		path[38] = "ef0:/seplugins/divapatch/divaext/pv_start_73.png";
		path[39] = "ef0:/seplugins/divapatch/divaext/pv_start_74.png";
		path[40] = "ef0:/seplugins/divapatch/divaext/pv_start_75.png";
		path[41] = "ef0:/seplugins/divapatch/divaext/pv_start_76.png";
		path[42] = "ef0:/seplugins/divapatch/divaext/pv_start_77.png";
		path[43] = "ef0:/seplugins/divapatch/divaext/pv_start_78.png";
		path[44] = "ef0:/seplugins/divapatch/divaext/pv_start_79.png";
		path[45] = "ef0:/seplugins/divapatch/divaext/pv_start_80.png";
		path[46] = "ef0:/seplugins/divapatch/divaext/pv_start_81.png";
		path[47] = "ef0:/seplugins/divapatch/divaext/pv_start_82.png";
		path[48] = "ef0:/seplugins/divapatch/divaext/pv_start_83.png";
		path[49] = "ef0:/seplugins/divapatch/divaext/pv_start_84.png";
		path[50] = "ef0:/seplugins/divapatch/divaext/pv_start_85.png";
		path[51] = "ef0:/seplugins/divapatch/divaext/pv_start_86.png";
		path[52] = "ef0:/seplugins/divapatch/divaext/pv_start_87.png";
		path[53] = "ef0:/seplugins/divapatch/divaext/pv_start_88.png";
		path[54] = "ef0:/seplugins/divapatch/divaext/pv_start_89.png";
		path[55] = "ef0:/seplugins/divapatch/divaext/pv_start_90.png";
		path[56] = "ef0:/seplugins/divapatch/divaext/pv_start_91.png";
		path[57] = "ef0:/seplugins/divapatch/divaext/pv_start_92.png";
		path[58] = "ef0:/seplugins/divapatch/divaext/pv_start_93.png";
		path[59] = "ef0:/seplugins/divapatch/divaext/pv_start_94.png";
		path[60] = "ef0:/seplugins/divapatch/divaext/pv_start_95.png";
		path[61] = "ef0:/seplugins/divapatch/divaext/pv_start_96.png";
		path[62] = "ef0:/seplugins/divapatch/divaext/pv_start_97.png";
		path[63] = "ef0:/seplugins/divapatch/divaext/pv_start_edit.png";
		path[64] = "ef0:/seplugins/divapatch/divaext/load_00.png";
		path[65] = "ef0:/seplugins/divapatch/divaext/load_01.png";
		path[66] = "ef0:/seplugins/divapatch/divaext/load_02.png";
		path[67] = "ef0:/seplugins/divapatch/divaext/load_03.png";
		path[68] = "ef0:/seplugins/divapatch/divaext/load_04.png";
		path[69] = "ef0:/seplugins/divapatch/divaext/load_05.png";
		path[70] = "ef0:/seplugins/divapatch/divaext/load_06.png";
		path[71] = "ef0:/seplugins/divapatch/divaext/load_07.png";
		path[72] = "ef0:/seplugins/divapatch/divaext/load_08.png";
		path[73] = "ef0:/seplugins/divapatch/divaext/load_09.png";
		path[74] = "ef0:/seplugins/divapatch/divaext/load_10.png";
		path[75] = "ef0:/seplugins/divapatch/divaext/load_11.png";
		path[76] = "ef0:/seplugins/divapatch/divaext/load_12.png";
		path[77] = "ef0:/seplugins/divapatch/divaext/load_13.png";
		path[78] = "ef0:/seplugins/divapatch/divaext/load_14.png";
		path[79] = "ef0:/seplugins/divapatch/divaext/load_15.png";
		path[80] = "ef0:/seplugins/divapatch/divaext/load_16.png";
		path[81] = "ef0:/seplugins/divapatch/divaext/load_17.png";
		path[82] = "ef0:/seplugins/divapatch/divaext/load_18.png";
		path[83] = "ef0:/seplugins/divapatch/divaext/load_19.png";
		path[84] = "ef0:/seplugins/divapatch/divaext/load_20.png";
		path[85] = "ef0:/seplugins/divapatch/divaext/load_21.png";
		path[86] = "ef0:/seplugins/divapatch/divaext/load_22.png";
		path[87] = "ef0:/seplugins/divapatch/divaext/load_23.png";
		path[88] = "ef0:/seplugins/divapatch/divaext/load_24.png";
		path[89] = "ef0:/seplugins/divapatch/divaext/load_25.png";
		path[90] = "ef0:/seplugins/divapatch/divaext/load_26.png";
		path[91] = "ef0:/seplugins/divapatch/divaext/load_27.png";
		path[92] = "ef0:/seplugins/divapatch/divaext/load_28.png";
		path[93] = "ef0:/seplugins/divapatch/divaext/load_29.png";
		path[94] = "ef0:/seplugins/divapatch/divaext/load_30.png";
		path[95] = "ef0:/seplugins/divapatch/divaext/load_31.png";
		path[96] = "ef0:/seplugins/divapatch/divaext/edit_base_04.png";
		path[97] = "ef0:/seplugins/divapatch/divaext/home_base_02.png";
		path[98] = "ef0:/seplugins/divapatch/divaext/menu_base_01.png";
		path[99] = "ef0:/seplugins/divapatch/divaext/menu_result.png";
		path[100] = "ef0:/seplugins/divapatch/divaext/mtit_base_01.png";
		path[101] = "ef0:/seplugins/divapatch/divaext/mtit_base_02.png";
		path[102] = "ef0:/seplugins/divapatch/divaext/mtit_base_03.png";
		path[103] = "ef0:/seplugins/divapatch/divaext/mtit_base_04.png";
		path[104] = "ef0:/seplugins/divapatch/divaext/mtit_base_05.png";
		path[105] = "ef0:/seplugins/divapatch/divaext/plst_base_01.png";
		path[106] = "ef0:/seplugins/divapatch/diva2nd#_translation.bin";
		path[107] = "ef0:/seplugins/divapatch/divaext";
		path[108] = "ef0:/seplugins/divapatch/diva2nd#";
		path[109] = "ef0:/seplugins/divapatch/divapatch.prx";
		path[110] = "ef0:/seplugins/divapatch/diva2nd#_images.bin";
		path[111] = "ef0:/seplugins/divapatch/diva2nd#/font12dot_01.png";
		path[112] = "ef0:/seplugins/divapatch/diva2nd#/menu_help_01.png";
		path[113] = "ef0:/seplugins/divapatch/diva2nd#/menu_help_02.png";
		path[114] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_adhk.png";
		path[115] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_crsl.png";
		path[116] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_edit.png";
		path[117] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_home.png";
		path[118] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_modl.png";
		path[119] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_msbx.png";
		path[120] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_optn.png";
		path[121] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_plys.png";
		path[122] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_prvd.png";
		path[123] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_room.png";
		path[124] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_rtmg.png";
		path[125] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_shop.png";
		path[126] = "ef0:/seplugins/divapatch/diva2nd#/menu_title_visl.png";
		path[127] = "ef0:/seplugins/divapatch/diva2nd#/pv_rank_01.png";
		path[128] = "ef0:/seplugins/divapatch/diva2nd#/edit_base_04.png";
		//path[129] = "ef0:/seplugins/divapatch/diva2nd#/home_base_02.png";
		path[130] = "ef0:/seplugins/divapatch/diva2nd#/menu_base_01.png";
		path[131] = "ef0:/seplugins/divapatch/diva2nd#/menu_result.png";
		path[132] = "ef0:/seplugins/divapatch/diva2nd#/mtit_base_01.png";
		path[133] = "ef0:/seplugins/divapatch/diva2nd#/mtit_base_02.png";
		path[134] = "ef0:/seplugins/divapatch/diva2nd#/mtit_base_03.png";
		path[135] = "ef0:/seplugins/divapatch/diva2nd#/plst_base_01.png";
		path[136] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_01.png";
		path[137] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_04.png";
		path[138] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_06.png";
		path[139] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_09.png";
		path[140] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_11.png";
		path[141] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_13.png";
		path[142] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_16.png";
		path[143] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_17.png";
		path[144] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_18.png";
		path[145] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_19.png";
		path[146] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_20.png";
		path[147] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_21.png";
		path[148] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_22.png";
		path[149] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_23.png";
		path[150] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_24.png";
		path[151] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_27.png";
		path[152] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_36.png";
		path[153] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_37.png";
		path[154] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_38.png";
		path[155] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_39.png";
		path[156] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_40.png";
		path[157] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_41.png";
		path[158] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_42.png";
		path[159] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_43.png";
		path[160] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_44.png";
		path[161] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_45.png";
		path[162] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_46.png";
		path[163] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_47.png";
		path[164] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_48.png";
		path[165] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_49.png";
		path[166] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_50.png";
		path[167] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_51.png";
		path[168] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_52.png";
		path[169] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_53.png";
		path[170] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_54.png";
		path[171] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_55.png";
		path[172] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_56.png";
		path[173] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_57.png";
		path[174] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_58.png";
		path[175] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_59.png";
		path[176] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_60.png";
		path[177] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_61.png";
		path[178] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_62.png";
		path[179] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_63.png";
		path[180] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_64.png";
		path[181] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_65.png";
		path[182] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_66.png";
		path[183] = "ef0:/seplugins/divapatch/diva2nd#/pv_start_edit.png";
	}
	else
	{
		path[0] = "ms0:/seplugins";
		path[1] = "ms0:/seplugins/divapatch";
		path[2] = "ms0:/seplugins/game.txt";
		path[3] = "ms0:/seplugins/divapatch/divapatch.prx 1";
		path[4] = "ms0:/seplugins/divapatch/divapatch.prx";
		path[5] = "\r\nms0:/seplugins/divapatch/divapatch.prx 1";
		path[6] = "ms0:/seplugins/divapatch/divaext_translation.bin";
		path[7] = "ms0:/seplugins/divapatch/divaext_images.bin";
		path[8] = "ms0:/seplugins/divapatch/divaext_embedded.bin";
		path[9] = "ms0:/seplugins/divapatch/divaext/font12dot_01.png";
		path[10] = "ms0:/seplugins/divapatch/divaext/menu_help_01.png";
		path[11] = "ms0:/seplugins/divapatch/divaext/menu_help_02.png";
		path[12] = "ms0:/seplugins/divapatch/divaext/menu_title_adhk.png";
		path[13] = "ms0:/seplugins/divapatch/divaext/menu_title_crsl.png";
		path[14] = "ms0:/seplugins/divapatch/divaext/menu_title_edit.png";
		path[15] = "ms0:/seplugins/divapatch/divaext/menu_title_home.png";
		path[16] = "ms0:/seplugins/divapatch/divaext/menu_title_modl.png";
		path[17] = "ms0:/seplugins/divapatch/divaext/menu_title_msbx.png";
		path[18] = "ms0:/seplugins/divapatch/divaext/menu_title_optn.png";
		path[19] = "ms0:/seplugins/divapatch/divaext/menu_title_plys.png";
		path[20] = "ms0:/seplugins/divapatch/divaext/menu_title_prvd.png";
		path[21] = "ms0:/seplugins/divapatch/divaext/menu_title_room.png";
		path[22] = "ms0:/seplugins/divapatch/divaext/menu_title_rtmg.png";
		path[23] = "ms0:/seplugins/divapatch/divaext/menu_title_shop.png";
		path[24] = "ms0:/seplugins/divapatch/divaext/menu_title_visl.png";
		path[25] = "ms0:/seplugins/divapatch/divaext/pv_rank_01.png";
		path[26] = "ms0:/seplugins/divapatch/divaext/pv_start_37.png";
		path[27] = "ms0:/seplugins/divapatch/divaext/pv_start_39.png";
		path[28] = "ms0:/seplugins/divapatch/divaext/pv_start_40.png";
		path[29] = "ms0:/seplugins/divapatch/divaext/pv_start_41.png";
		path[30] = "ms0:/seplugins/divapatch/divaext/pv_start_53.png";
		path[31] = "ms0:/seplugins/divapatch/divaext/pv_start_65.png";
		path[32] = "ms0:/seplugins/divapatch/divaext/pv_start_67.png";
		path[33] = "ms0:/seplugins/divapatch/divaext/pv_start_68.png";
		path[34] = "ms0:/seplugins/divapatch/divaext/pv_start_69.png";
		path[35] = "ms0:/seplugins/divapatch/divaext/pv_start_70.png";
		path[36] = "ms0:/seplugins/divapatch/divaext/pv_start_71.png";
		path[37] = "ms0:/seplugins/divapatch/divaext/pv_start_72.png";
		path[38] = "ms0:/seplugins/divapatch/divaext/pv_start_73.png";
		path[39] = "ms0:/seplugins/divapatch/divaext/pv_start_74.png";
		path[40] = "ms0:/seplugins/divapatch/divaext/pv_start_75.png";
		path[41] = "ms0:/seplugins/divapatch/divaext/pv_start_76.png";
		path[42] = "ms0:/seplugins/divapatch/divaext/pv_start_77.png";
		path[43] = "ms0:/seplugins/divapatch/divaext/pv_start_78.png";
		path[44] = "ms0:/seplugins/divapatch/divaext/pv_start_79.png";
		path[45] = "ms0:/seplugins/divapatch/divaext/pv_start_80.png";
		path[46] = "ms0:/seplugins/divapatch/divaext/pv_start_81.png";
		path[47] = "ms0:/seplugins/divapatch/divaext/pv_start_82.png";
		path[48] = "ms0:/seplugins/divapatch/divaext/pv_start_83.png";
		path[49] = "ms0:/seplugins/divapatch/divaext/pv_start_84.png";
		path[50] = "ms0:/seplugins/divapatch/divaext/pv_start_85.png";
		path[51] = "ms0:/seplugins/divapatch/divaext/pv_start_86.png";
		path[52] = "ms0:/seplugins/divapatch/divaext/pv_start_87.png";
		path[53] = "ms0:/seplugins/divapatch/divaext/pv_start_88.png";
		path[54] = "ms0:/seplugins/divapatch/divaext/pv_start_89.png";
		path[55] = "ms0:/seplugins/divapatch/divaext/pv_start_90.png";
		path[56] = "ms0:/seplugins/divapatch/divaext/pv_start_91.png";
		path[57] = "ms0:/seplugins/divapatch/divaext/pv_start_92.png";
		path[58] = "ms0:/seplugins/divapatch/divaext/pv_start_93.png";
		path[59] = "ms0:/seplugins/divapatch/divaext/pv_start_94.png";
		path[60] = "ms0:/seplugins/divapatch/divaext/pv_start_95.png";
		path[61] = "ms0:/seplugins/divapatch/divaext/pv_start_96.png";
		path[62] = "ms0:/seplugins/divapatch/divaext/pv_start_97.png";
		path[63] = "ms0:/seplugins/divapatch/divaext/pv_start_edit.png";
		path[64] = "ms0:/seplugins/divapatch/divaext/load_00.png";
		path[65] = "ms0:/seplugins/divapatch/divaext/load_01.png";
		path[66] = "ms0:/seplugins/divapatch/divaext/load_02.png";
		path[67] = "ms0:/seplugins/divapatch/divaext/load_03.png";
		path[68] = "ms0:/seplugins/divapatch/divaext/load_04.png";
		path[69] = "ms0:/seplugins/divapatch/divaext/load_05.png";
		path[70] = "ms0:/seplugins/divapatch/divaext/load_06.png";
		path[71] = "ms0:/seplugins/divapatch/divaext/load_07.png";
		path[72] = "ms0:/seplugins/divapatch/divaext/load_08.png";
		path[73] = "ms0:/seplugins/divapatch/divaext/load_09.png";
		path[74] = "ms0:/seplugins/divapatch/divaext/load_10.png";
		path[75] = "ms0:/seplugins/divapatch/divaext/load_11.png";
		path[76] = "ms0:/seplugins/divapatch/divaext/load_12.png";
		path[77] = "ms0:/seplugins/divapatch/divaext/load_13.png";
		path[78] = "ms0:/seplugins/divapatch/divaext/load_14.png";
		path[79] = "ms0:/seplugins/divapatch/divaext/load_15.png";
		path[80] = "ms0:/seplugins/divapatch/divaext/load_16.png";
		path[81] = "ms0:/seplugins/divapatch/divaext/load_17.png";
		path[82] = "ms0:/seplugins/divapatch/divaext/load_18.png";
		path[83] = "ms0:/seplugins/divapatch/divaext/load_19.png";
		path[84] = "ms0:/seplugins/divapatch/divaext/load_20.png";
		path[85] = "ms0:/seplugins/divapatch/divaext/load_21.png";
		path[86] = "ms0:/seplugins/divapatch/divaext/load_22.png";
		path[87] = "ms0:/seplugins/divapatch/divaext/load_23.png";
		path[88] = "ms0:/seplugins/divapatch/divaext/load_24.png";
		path[89] = "ms0:/seplugins/divapatch/divaext/load_25.png";
		path[90] = "ms0:/seplugins/divapatch/divaext/load_26.png";
		path[91] = "ms0:/seplugins/divapatch/divaext/load_27.png";
		path[92] = "ms0:/seplugins/divapatch/divaext/load_28.png";
		path[93] = "ms0:/seplugins/divapatch/divaext/load_29.png";
		path[94] = "ms0:/seplugins/divapatch/divaext/load_30.png";
		path[95] = "ms0:/seplugins/divapatch/divaext/load_31.png";
		path[96] = "ms0:/seplugins/divapatch/divaext/edit_base_04.png";
		path[97] = "ms0:/seplugins/divapatch/divaext/home_base_02.png";
		path[98] = "ms0:/seplugins/divapatch/divaext/menu_base_01.png";
		path[99] = "ms0:/seplugins/divapatch/divaext/menu_result.png";
		path[100] = "ms0:/seplugins/divapatch/divaext/mtit_base_01.png";
		path[101] = "ms0:/seplugins/divapatch/divaext/mtit_base_02.png";
		path[102] = "ms0:/seplugins/divapatch/divaext/mtit_base_03.png";
		path[103] = "ms0:/seplugins/divapatch/divaext/mtit_base_04.png";
		path[104] = "ms0:/seplugins/divapatch/divaext/mtit_base_05.png";
		path[105] = "ms0:/seplugins/divapatch/divaext/plst_base_01.png";
		path[106] = "ms0:/seplugins/divapatch/diva2nd#_translation.bin";
		path[107] = "ms0:/seplugins/divapatch/divaext";
		path[108] = "ms0:/seplugins/divapatch/diva2nd#";
		path[109] = "ms0:/seplugins/divapatch/divapatch.prx";
		path[110] = "ms0:/seplugins/divapatch/diva2nd#_images.bin";
		path[111] = "ms0:/seplugins/divapatch/diva2nd#/font12dot_01.png";
		path[112] = "ms0:/seplugins/divapatch/diva2nd#/menu_help_01.png";
		path[113] = "ms0:/seplugins/divapatch/diva2nd#/menu_help_02.png";
		path[114] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_adhk.png";
		path[115] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_crsl.png";
		path[116] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_edit.png";
		path[117] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_home.png";
		path[118] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_modl.png";
		path[119] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_msbx.png";
		path[120] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_optn.png";
		path[121] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_plys.png";
		path[122] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_prvd.png";
		path[123] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_room.png";
		path[124] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_rtmg.png";
		path[125] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_shop.png";
		path[126] = "ms0:/seplugins/divapatch/diva2nd#/menu_title_visl.png";
		path[127] = "ms0:/seplugins/divapatch/diva2nd#/pv_rank_01.png";
		path[128] = "ms0:/seplugins/divapatch/diva2nd#/edit_base_04.png";
		//path[129] = "ms0:/seplugins/divapatch/diva2nd#/home_base_02.png";
		path[130] = "ms0:/seplugins/divapatch/diva2nd#/menu_base_01.png";
		path[131] = "ms0:/seplugins/divapatch/diva2nd#/menu_result.png";
		path[132] = "ms0:/seplugins/divapatch/diva2nd#/mtit_base_01.png";
		path[133] = "ms0:/seplugins/divapatch/diva2nd#/mtit_base_02.png";
		path[134] = "ms0:/seplugins/divapatch/diva2nd#/mtit_base_03.png";
		path[135] = "ms0:/seplugins/divapatch/diva2nd#/plst_base_01.png";
		path[136] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_01.png";
		path[137] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_04.png";
		path[138] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_06.png";
		path[139] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_09.png";
		path[140] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_11.png";
		path[141] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_13.png";
		path[142] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_16.png";
		path[143] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_17.png";
		path[144] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_18.png";
		path[145] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_19.png";
		path[146] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_20.png";
		path[147] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_21.png";
		path[148] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_22.png";
		path[149] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_23.png";
		path[150] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_24.png";
		path[151] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_27.png";
		path[152] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_36.png";
		path[153] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_37.png";
		path[154] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_38.png";
		path[155] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_39.png";
		path[156] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_40.png";
		path[157] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_41.png";
		path[158] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_42.png";
		path[159] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_43.png";
		path[160] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_44.png";
		path[161] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_45.png";
		path[162] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_46.png";
		path[163] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_47.png";
		path[164] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_48.png";
		path[165] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_49.png";
		path[166] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_50.png";
		path[167] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_51.png";
		path[168] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_52.png";
		path[169] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_53.png";
		path[170] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_54.png";
		path[171] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_55.png";
		path[172] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_56.png";
		path[173] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_57.png";
		path[174] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_58.png";
		path[175] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_59.png";
		path[176] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_60.png";
		path[177] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_61.png";
		path[178] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_62.png";
		path[179] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_63.png";
		path[180] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_64.png";
		path[181] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_65.png";
		path[182] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_66.png";
		path[183] = "ms0:/seplugins/divapatch/diva2nd#/pv_start_edit.png";
	}

	char buf[2048];
	SceUID fd = sceIoOpen(path[2], PSP_O_RDONLY, 777);
	if(fd >= 0)
	{
		int sizefd = sceIoLseek(fd, 0, PSP_SEEK_END);
		sceIoLseek(fd, 0, PSP_SEEK_SET);
		sceIoRead(fd, &buf, sizefd);
		if(buf[sizefd - 1] == '\n')
			plus = 1;
		else
			plus = 0;
	}
	sceIoClose(fd);

	vlfGuiSetTitleBar(NULL, NULL, 1, 1);
	vlfGuiSystemSetup(1, 1, 1);
	sceUtilityGetSystemParamInt(9, &enter_button);
	MainMenu(0, 1);
	
	while(1)
		vlfGuiDrawFrame();
	
	return 0;
}