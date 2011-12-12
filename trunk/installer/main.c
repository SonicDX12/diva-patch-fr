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

#include "divapatch.h"
#include "divaext_translation.h"
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


PSP_MODULE_INFO("Extend Patch FR", 0, 1, 5);
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
char *path[98];
int enter_button = 0;
extern int currdev;
extern char *cpath;
int plus;

#define FW(f) ((((f >> 8) & 0xF) << 24) | (((f >> 4) & 0xF) << 16) | ((f & 0xF) << 8) | 0x10)

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
	
	WriteFile(path[4], (void *)divapatch, size_divapatch, 0);
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
	WriteFile(path[97], (void *)divapatch, size_divapatch, 0);
	sceKernelDelayThread(1200000);	
	SetProgress(100, 1);
	
	vlfGuiAddEventHandler(0, 600000, OnInstallComplete, NULL);
	return sceKernelExitDeleteThread(0);
}

void installing()
{
	SceUID install_thid = sceKernelCreateThread("install_thread", install_thread, 0x18, 0x10000, 0, NULL);// Dark_Alex's antifreeze method.
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
			installing();
			break;

		case 1:
			point = 1;
			Credits_Changelog(1);
			return VLF_EV_RET_REMOVE_HANDLERS | VLF_EV_RET_REMOVE_OBJECTS;

		case 2:
			point = 2;
			Credits_Changelog(0);
			return VLF_EV_RET_REMOVE_HANDLERS | VLF_EV_RET_REMOVE_OBJECTS;
		
		case 3:
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

	title_text = vlfGuiAddText(1, 1, "Project Diva Patch FR Installer v2.0      (12/12/11)");
	title_pic = vlfGuiAddPictureResource("ps3scan_plugin.rco", "tex_infobar_icon", 4, -2);
	vlfGuiSetTitleBar(title_text, title_pic, 1, 1);

	char *items[] = { "Installer le patch Extend FR", "Changelog", "Credits", "Quitter" };

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
			"    (Sauvegarder, Charger, Quitter le jeu?, etc)\n";
		x = 35;
	}
	else
	{
		crchtext =
			"Project Diva Patch FR\n"
			"Installer v2.0\n"
			"Copyright(C) 2011, Sonic DX\n\n"
			"   Credits:\n"
			"     - Codestation\n"// Plugin, Eboot reversing
			"     - Frostegater\n\n"// Installer
			"   Merci:\n"
			"     - Moi, Sonic DX\n"// fr translate, Eboot reversing
			"     - Reload\n"// fr translate
			"     - DarkCenobyte\n"// Pictures
			"     - Staz\n"// fr translate
			"     - Kienono\n\n"// fr translate
			"Patch FR fait pour des fans\n"
			"par des fan";

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
		path[9] = "ef0:/seplugins/divapatch/font12dot_01.png";
		path[10] = "ef0:/seplugins/divapatch/menu_help_01.png";
		path[11] = "ef0:/seplugins/divapatch/menu_help_02.png";
		path[12] = "ef0:/seplugins/divapatch/menu_title_adhk.png";
		path[13] = "ef0:/seplugins/divapatch/menu_title_crsl.png";
		path[14] = "ef0:/seplugins/divapatch/menu_title_edit.png";
		path[15] = "ef0:/seplugins/divapatch/menu_title_home.png";
		path[16] = "ef0:/seplugins/divapatch/menu_title_modl.png";
		path[17] = "ef0:/seplugins/divapatch/menu_title_msbx.png";
		path[18] = "ef0:/seplugins/divapatch/menu_title_optn.png";
		path[19] = "ef0:/seplugins/divapatch/menu_title_plys.png";
		path[20] = "ef0:/seplugins/divapatch/menu_title_prvd.png";
		path[21] = "ef0:/seplugins/divapatch/menu_title_room.png";
		path[22] = "ef0:/seplugins/divapatch/menu_title_rtmg.png";
		path[23] = "ef0:/seplugins/divapatch/menu_title_shop.png";
		path[24] = "ef0:/seplugins/divapatch/menu_title_visl.png";
		path[25] = "ef0:/seplugins/divapatch/pv_rank_01.png";
		path[26] = "ef0:/seplugins/divapatch/pv_start_37.png";
		path[27] = "ef0:/seplugins/divapatch/pv_start_39.png";
		path[28] = "ef0:/seplugins/divapatch/pv_start_40.png";
		path[29] = "ef0:/seplugins/divapatch/pv_start_41.png";
		path[30] = "ef0:/seplugins/divapatch/pv_start_53.png";
		path[31] = "ef0:/seplugins/divapatch/pv_start_65.png";
		path[32] = "ef0:/seplugins/divapatch/pv_start_67.png";
		path[33] = "ef0:/seplugins/divapatch/pv_start_68.png";
		path[34] = "ef0:/seplugins/divapatch/pv_start_69.png";
		path[35] = "ef0:/seplugins/divapatch/pv_start_70.png";
		path[36] = "ef0:/seplugins/divapatch/pv_start_71.png";
		path[37] = "ef0:/seplugins/divapatch/pv_start_72.png";
		path[38] = "ef0:/seplugins/divapatch/pv_start_73.png";
		path[39] = "ef0:/seplugins/divapatch/pv_start_74.png";
		path[40] = "ef0:/seplugins/divapatch/pv_start_75.png";
		path[41] = "ef0:/seplugins/divapatch/pv_start_76.png";
		path[42] = "ef0:/seplugins/divapatch/pv_start_77.png";
		path[43] = "ef0:/seplugins/divapatch/pv_start_78.png";
		path[44] = "ef0:/seplugins/divapatch/pv_start_79.png";
		path[45] = "ef0:/seplugins/divapatch/pv_start_80.png";
		path[46] = "ef0:/seplugins/divapatch/pv_start_81.png";
		path[47] = "ef0:/seplugins/divapatch/pv_start_82.png";
		path[48] = "ef0:/seplugins/divapatch/pv_start_83.png";
		path[49] = "ef0:/seplugins/divapatch/pv_start_84.png";
		path[50] = "ef0:/seplugins/divapatch/pv_start_85.png";
		path[51] = "ef0:/seplugins/divapatch/pv_start_86.png";
		path[52] = "ef0:/seplugins/divapatch/pv_start_87.png";
		path[53] = "ef0:/seplugins/divapatch/pv_start_88.png";
		path[54] = "ef0:/seplugins/divapatch/pv_start_89.png";
		path[55] = "ef0:/seplugins/divapatch/pv_start_90.png";
		path[56] = "ef0:/seplugins/divapatch/pv_start_91.png";
		path[57] = "ef0:/seplugins/divapatch/pv_start_92.png";
		path[58] = "ef0:/seplugins/divapatch/pv_start_93.png";
		path[59] = "ef0:/seplugins/divapatch/pv_start_94.png";
		path[60] = "ef0:/seplugins/divapatch/pv_start_95.png";
		path[61] = "ef0:/seplugins/divapatch/pv_start_96.png";
		path[62] = "ef0:/seplugins/divapatch/pv_start_97.png";
		path[63] = "ef0:/seplugins/divapatch/pv_start_edit.png";
		path[64] = "ef0:/seplugins/divapatch/load_00.png";
		path[65] = "ef0:/seplugins/divapatch/load_01.png";
		path[66] = "ef0:/seplugins/divapatch/load_02.png";
		path[67] = "ef0:/seplugins/divapatch/load_03.png";
		path[68] = "ef0:/seplugins/divapatch/load_04.png";
		path[69] = "ef0:/seplugins/divapatch/load_05.png";
		path[70] = "ef0:/seplugins/divapatch/load_06.png";
		path[71] = "ef0:/seplugins/divapatch/load_07.png";
		path[72] = "ef0:/seplugins/divapatch/load_08.png";
		path[73] = "ef0:/seplugins/divapatch/load_09.png";
		path[74] = "ef0:/seplugins/divapatch/load_10.png";
		path[75] = "ef0:/seplugins/divapatch/load_11.png";
		path[76] = "ef0:/seplugins/divapatch/load_12.png";
		path[77] = "ef0:/seplugins/divapatch/load_13.png";
		path[78] = "ef0:/seplugins/divapatch/load_14.png";
		path[79] = "ef0:/seplugins/divapatch/load_15.png";
		path[80] = "ef0:/seplugins/divapatch/load_16.png";
		path[81] = "ef0:/seplugins/divapatch/load_17.png";
		path[82] = "ef0:/seplugins/divapatch/load_18.png";
		path[83] = "ef0:/seplugins/divapatch/load_19.png";
		path[84] = "ef0:/seplugins/divapatch/load_20.png";
		path[85] = "ef0:/seplugins/divapatch/load_21.png";
		path[86] = "ef0:/seplugins/divapatch/load_22.png";
		path[87] = "ef0:/seplugins/divapatch/load_23.png";
		path[88] = "ef0:/seplugins/divapatch/load_24.png";
		path[89] = "ef0:/seplugins/divapatch/load_25.png";
		path[90] = "ef0:/seplugins/divapatch/load_26.png";
		path[91] = "ef0:/seplugins/divapatch/load_27.png";
		path[92] = "ef0:/seplugins/divapatch/load_28.png";
		path[93] = "ef0:/seplugins/divapatch/load_29.png";
		path[94] = "ef0:/seplugins/divapatch/load_30.png";
		path[95] = "ef0:/seplugins/divapatch/load_31.png";
		path[96] = "ef0:/seplugins/divapatch/edit_base_04.png";
		path[97] = "ef0:/seplugins/divapatch/divapatch.prx";
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
		path[9] = "ms0:/seplugins/divapatch/font12dot_01.png";
		path[10] = "ms0:/seplugins/divapatch/menu_help_01.png";
		path[11] = "ms0:/seplugins/divapatch/menu_help_02.png";
		path[12] = "ms0:/seplugins/divapatch/menu_title_adhk.png";
		path[13] = "ms0:/seplugins/divapatch/menu_title_crsl.png";
		path[14] = "ms0:/seplugins/divapatch/menu_title_edit.png";
		path[15] = "ms0:/seplugins/divapatch/menu_title_home.png";
		path[16] = "ms0:/seplugins/divapatch/menu_title_modl.png";
		path[17] = "ms0:/seplugins/divapatch/menu_title_msbx.png";
		path[18] = "ms0:/seplugins/divapatch/menu_title_optn.png";
		path[19] = "ms0:/seplugins/divapatch/menu_title_plys.png";
		path[20] = "ms0:/seplugins/divapatch/menu_title_prvd.png";
		path[21] = "ms0:/seplugins/divapatch/menu_title_room.png";
		path[22] = "ms0:/seplugins/divapatch/menu_title_rtmg.png";
		path[23] = "ms0:/seplugins/divapatch/menu_title_shop.png";
		path[24] = "ms0:/seplugins/divapatch/menu_title_visl.png";
		path[25] = "ms0:/seplugins/divapatch/pv_rank_01.png";
		path[26] = "ms0:/seplugins/divapatch/pv_start_37.png";
		path[27] = "ms0:/seplugins/divapatch/pv_start_39.png";
		path[28] = "ms0:/seplugins/divapatch/pv_start_40.png";
		path[29] = "ms0:/seplugins/divapatch/pv_start_41.png";
		path[30] = "ms0:/seplugins/divapatch/pv_start_53.png";
		path[31] = "ms0:/seplugins/divapatch/pv_start_65.png";
		path[32] = "ms0:/seplugins/divapatch/pv_start_67.png";
		path[33] = "ms0:/seplugins/divapatch/pv_start_68.png";
		path[34] = "ms0:/seplugins/divapatch/pv_start_69.png";
		path[35] = "ms0:/seplugins/divapatch/pv_start_70.png";
		path[36] = "ms0:/seplugins/divapatch/pv_start_71.png";
		path[37] = "ms0:/seplugins/divapatch/pv_start_72.png";
		path[38] = "ms0:/seplugins/divapatch/pv_start_73.png";
		path[39] = "ms0:/seplugins/divapatch/pv_start_74.png";
		path[40] = "ms0:/seplugins/divapatch/pv_start_75.png";
		path[41] = "ms0:/seplugins/divapatch/pv_start_76.png";
		path[42] = "ms0:/seplugins/divapatch/pv_start_77.png";
		path[43] = "ms0:/seplugins/divapatch/pv_start_78.png";
		path[44] = "ms0:/seplugins/divapatch/pv_start_79.png";
		path[45] = "ms0:/seplugins/divapatch/pv_start_80.png";
		path[46] = "ms0:/seplugins/divapatch/pv_start_81.png";
		path[47] = "ms0:/seplugins/divapatch/pv_start_82.png";
		path[48] = "ms0:/seplugins/divapatch/pv_start_83.png";
		path[49] = "ms0:/seplugins/divapatch/pv_start_84.png";
		path[50] = "ms0:/seplugins/divapatch/pv_start_85.png";
		path[51] = "ms0:/seplugins/divapatch/pv_start_86.png";
		path[52] = "ms0:/seplugins/divapatch/pv_start_87.png";
		path[53] = "ms0:/seplugins/divapatch/pv_start_88.png";
		path[54] = "ms0:/seplugins/divapatch/pv_start_89.png";
		path[55] = "ms0:/seplugins/divapatch/pv_start_90.png";
		path[56] = "ms0:/seplugins/divapatch/pv_start_91.png";
		path[57] = "ms0:/seplugins/divapatch/pv_start_92.png";
		path[58] = "ms0:/seplugins/divapatch/pv_start_93.png";
		path[59] = "ms0:/seplugins/divapatch/pv_start_94.png";
		path[60] = "ms0:/seplugins/divapatch/pv_start_95.png";
		path[61] = "ms0:/seplugins/divapatch/pv_start_96.png";
		path[62] = "ms0:/seplugins/divapatch/pv_start_97.png";
		path[63] = "ms0:/seplugins/divapatch/pv_start_edit.png";
		path[64] = "ms0:/seplugins/divapatch/load_00.png";
		path[65] = "ms0:/seplugins/divapatch/load_01.png";
		path[66] = "ms0:/seplugins/divapatch/load_02.png";
		path[67] = "ms0:/seplugins/divapatch/load_03.png";
		path[68] = "ms0:/seplugins/divapatch/load_04.png";
		path[69] = "ms0:/seplugins/divapatch/load_05.png";
		path[70] = "ms0:/seplugins/divapatch/load_06.png";
		path[71] = "ms0:/seplugins/divapatch/load_07.png";
		path[72] = "ms0:/seplugins/divapatch/load_08.png";
		path[73] = "ms0:/seplugins/divapatch/load_09.png";
		path[74] = "ms0:/seplugins/divapatch/load_10.png";
		path[75] = "ms0:/seplugins/divapatch/load_11.png";
		path[76] = "ms0:/seplugins/divapatch/load_12.png";
		path[77] = "ms0:/seplugins/divapatch/load_13.png";
		path[78] = "ms0:/seplugins/divapatch/load_14.png";
		path[79] = "ms0:/seplugins/divapatch/load_15.png";
		path[80] = "ms0:/seplugins/divapatch/load_16.png";
		path[81] = "ms0:/seplugins/divapatch/load_17.png";
		path[82] = "ms0:/seplugins/divapatch/load_18.png";
		path[83] = "ms0:/seplugins/divapatch/load_19.png";
		path[84] = "ms0:/seplugins/divapatch/load_20.png";
		path[85] = "ms0:/seplugins/divapatch/load_21.png";
		path[86] = "ms0:/seplugins/divapatch/load_22.png";
		path[87] = "ms0:/seplugins/divapatch/load_23.png";
		path[88] = "ms0:/seplugins/divapatch/load_24.png";
		path[89] = "ms0:/seplugins/divapatch/load_25.png";
		path[90] = "ms0:/seplugins/divapatch/load_26.png";
		path[91] = "ms0:/seplugins/divapatch/load_27.png";
		path[92] = "ms0:/seplugins/divapatch/load_28.png";
		path[93] = "ms0:/seplugins/divapatch/load_29.png";
		path[94] = "ms0:/seplugins/divapatch/load_30.png";
		path[95] = "ms0:/seplugins/divapatch/load_31.png";
		path[96] = "ms0:/seplugins/divapatch/edit_base_04.png";
		path[97] = "ms0:/seplugins/divapatch/divapatch.prx";
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