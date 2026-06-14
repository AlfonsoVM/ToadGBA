/* unofficial gameplaySP kai
 *
 * Copyright (C) 2006 Exophase <exophase@gmail.com>
 * Copyright (C) 2007 takka <takka@tfact.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "common.h"


const char *message[2][MSG_END] =
{
  {
    //MSG_TURBO
	"--FF--",

    //MSG_CHARGE
	"[DC IN]",

    //MSG_BUFFER
	"ROM Buffer %2dMB",

    // MSG_BROWSER_HELP
    "��:�I��  �~:���j���[  ��:" FONT_UP_DIRECTORY,

    // MSG_MENU_DATE_FMT_0
    "%4d/%2d/%2d %-4s %2d:%02d",

    // MSG_MENU_DATE_FMT_1
    "%2d/%2d/%4d %-4s %2d:%02d",

    // MSG_MAIN_MENU_TITLE
	#include "text/main_menu_t.h"

    // MSG_MAIN_MENU_0
    "���[�h�X�e�[�g : �X���b�g %d",

    // MSG_MAIN_MENU_1
    "�Z�[�u�X�e�[�g : �X���b�g %d",

    // MSG_MAIN_MENU_2
    "�X�e�[�g�Z�[�u�g�� " FONT_R_TRIGGER,

    // MSG_MAIN_MENU_3
    "�X�N���[�� �V���b�g: %s",

    // MSG_MAIN_MENU_4
    "�G�~�����[�^�̐ݒ�",

    // MSG_MAIN_MENU_5
    "�Q�[���p�b�h�̐ݒ�",

    // MSG_MAIN_MENU_6
    "�A�i���O�X�e�B�b�N�̐ݒ�",

	//MSG_MAIN_MENU_CHEAT
    "�`�[�g���j���[",

    // MSG_MAIN_MENU_7
    "�Q�[���̃��[�h " FONT_L_TRIGGER,

    // MSG_MAIN_MENU_8
    "���Z�b�g",

    // MSG_MAIN_MENU_9
    "�Q�[���ɖ߂�",

    // MSG_MAIN_MENU_10
    "�X���[�v",

    // MSG_MAIN_MENU_11
    "ToadGBA�̏I��",

    //MSG_MAIN_MENU_OVERLAY
    // オーバーレイ
    "\x83\x49\x81\x5B\x83\x6F\x81\x5B\x83\x8C\x83\x43",

    //MSG_MAIN_MENU_RECENT
    // サイキンノゲーム
    "\x83\x54\x83\x43\x83\x4C\x83\x93\x83\x6D\x83\x51\x81\x5B\x83\x80",

    // MSG_MAIN_MENU_HELP_0
    "��:���[�h  " FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�X���b�g�I��",

    // MSG_MAIN_MENU_HELP_1
    "��:�Z�[�u  " FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�X���b�g�I��",

    // MSG_MAIN_MENU_HELP_2
    "��:�T�u���j���[  " FONT_R_TRIGGER ":�V���[�g�J�b�g",

    // MSG_MAIN_MENU_HELP_3
    "��:�C���[�W�ۑ�  " FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�t�H�[�}�b�g�I��",

    // MSG_MAIN_MENU_HELP_4
    "��:�T�u���j���[",

    // MSG_MAIN_MENU_HELP_5
    "��:�T�u���j���[",

    // MSG_MAIN_MENU_HELP_6
    "��:�T�u���j���[",

    // MSG_MAIN_MENU_HELP_CHEAT
    "��:�`�[�g��ύX���܂�",

    // MSG_MAIN_MENU_HELP_7
    "��:�t�@�C���u���E�U  " FONT_L_TRIGGER ":�V���[�g�J�b�g",

    // MSG_MAIN_MENU_HELP_8
    "��:�Q�[�������Z�b�g",

    // MSG_MAIN_MENU_HELP_9
    "��:�Q�[���ɖ߂�",

    // MSG_MAIN_MENU_HELP_10
    "��:�X���[�v ���[�h",

    // MSG_MAIN_MENU_HELP_11
    "��:�I��",

    //MSG_MAIN_MENU_HELP_OVERLAY
    // O:オーバーレイのセッテイ
    "O:\x83\x49\x81\x5B\x83\x6F\x81\x5B\x83\x8C\x83\x43\x83\x6D\x83\x5A\x83\x62\x83\x65\x83\x43",

    //MSG_MAIN_MENU_HELP_RECENT
    // X:サイキンプレイシタゲームヲロード
    "X:\x83\x54\x83\x43\x83\x4C\x83\x93\x83\x76\x83\x8C\x83\x43\x83\x56\x83\x5E\x83\x51\x81\x5B\x83\x80\x83\x8D\x81\x5B\x83\x68",

    // MSG_OPTION_MENU_TITLE
	#include "text/option_menu_t.h"

    // MSG_OPTION_MENU_0
    "��ʕ\\���@�@�@�@�@: %s",

    // MSG_OPTION_MENU_1
    "��ʂ̊g�嗦�@�@�@: %d%%",

    // MSG_OPTION_MENU_2
    "��ʂ̃t�B���^�@�@: %s",

    // MSG_OPTION_MENU_SHOW_FPS
    "FPS�\\�� �@�@�@�@�@: %s",


    // MSG_OPTION_MENU_COLOR_CORRECTION
    "���␳�@�@�@�@�@�@: %s",

    // MSG_OPTION_MENU_BUTTON_MAPPING
    "�{�^���}�b�s���O�@: %s",

    // MSG_OPTION_MENU_3
    "�t���[���X�L�b�v�@: %s",

    // MSG_OPTION_MENU_4
    "�X�L�b�v�̒l�@�@�@: %d",

    // MSG_OPTION_MENU_5
    "����N���b�N�@�@�@: %s",

    // MSG_OPTION_MENU_6
    "�T�E���h���ʁ@�@�@: %s",

    // MSG_OPTION_MENU_7
    "�X�^�b�N�̍œK���@: %s",

    // MSG_OPTION_MENU_8
    "BIOS����N�����s��: %s",

    // MSG_OPTION_MENU_9
    "�o�b�N�A�b�v�̍X�V: %s",

    // MSG_OPTION_MENU_10
    "����@�@�@�@�@�@�@: %s",

    // MSG_OPTION_MENU_HELP_DEFAULT
    "�ݒ�̏�����",

    // MSG_OPTION_MENU_11
    "�߂�",

    // MSG_OPTION_MENU_12
    // コードサイテキカ
    "\x83\x52\x81\x5B\x83\x68\x83\x54\x83\x43\x83\x65\x83\x4C\x83\x4A      : %s",

    // MSG_SUBMENU_VIDEO
    // イメージセッテイ
    "\x83\x43\x83\x81\x81\x5B\x83\x57\x83\x5A\x83\x62\x83\x65\x83\x43       >",

    // MSG_SUBMENU_PERFORMANCE
    // パフォーマンス
    "\x83\x70\x83\x74\x83\x48\x81\x5B\x83\x7D\x83\x93\x83\x58        >",

    // MSG_SUBMENU_AUDIO
    // サウンド
    "\x83\x54\x83\x45\x83\x93\x83\x68            >",

    // MSG_SUBMENU_CONTROLS
    // コントロール
    "\x83\x52\x83\x93\x83\x67\x83\x8D\x81\x5B\x83\x8B          >",

    // MSG_SUBMENU_SYSTEM
    // システム
    "\x83\x56\x83\x58\x83\x65\x83\x80             >",

    // MSG_SUBMENU_DIRECTORIES
    // ディレクトリ
    "\x83\x66\x83\x42\x83\x8C\x83\x4E\x83\x67\x83\x8A         >",

    // MSG_DIR_ROMS
    // ROMフォルダ
    "ROM\x83\x74\x83\x48\x83\x8B\x83\x5F         :",

    // MSG_DIR_SAVE
    // セーブフォルダ
    "\x83\x5A\x81\x5B\x83\x75\x83\x74\x83\x48\x83\x8B\x83\x5F       :",

    // MSG_DIR_STATE
    // セーブステート
    "\x83\x5A\x81\x5B\x83\x75\x83\x58\x83\x65\x81\x5B\x83\x67        :",

    // MSG_DIR_CHEAT
    // チートフォルダ
    "\x83\x60\x81\x5B\x83\x67\x83\x74\x83\x48\x83\x8B\x83\x5F        :",

    // MSG_DIR_SNAP
    // スクリーンショット
    "\x83\x58\x83\x4E\x83\x8A\x81\x5B\x83\x93\x83\x56\x83\x87\x83\x62\x83\x67       :",

    // MSG_HELP_SUBMENU_DIRECTORIES
    // ファイルパス:ROM,セーブ,オーバーレイ  O:モドル
    "\x83\x74\x83\x40\x83\x43\x83\x8B\x83\x70\x83\x58:ROM,\x83\x5A\x81\x5B\x83\x75,\x83\x49\x81\x5B\x83\x6F\x81\x5B\x83\x8C\x83\x43  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_DIR_ROMS
    // X:ROMフォルダヲセンタク  O:モドル
    "X:ROM\x83\x74\x83\x48\x83\x8B\x83\x5F\x83\x90\x83\x5A\x83\x93\x83\x5E\x83\x4E  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_DIR_SAVE
    // X:セーブフォルダヲセンタク  O:モドル
    "X:\x83\x5A\x81\x5B\x83\x75\x83\x74\x83\x48\x83\x8B\x83\x5F\x83\x90\x83\x5A\x83\x93\x83\x5E\x83\x4E  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_DIR_STATE
    // X:セーブステートヲセンタク  O:モドル
    "X:\x83\x5A\x81\x5B\x83\x75\x83\x58\x83\x65\x81\x5B\x83\x67\x83\x90\x83\x5A\x83\x93\x83\x5E\x83\x4E  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_DIR_CHEAT
    // X:チートフォルダヲセンタク  O:モドル
    "X:\x83\x60\x81\x5B\x83\x67\x83\x74\x83\x48\x83\x8B\x83\x5F\x83\x90\x83\x5A\x83\x93\x83\x5E\x83\x4E  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_DIR_SNAP
    // X:スクリーンショットヲセンタク  O:モドル
    "X:\x83\x58\x83\x4E\x83\x8A\x81\x5B\x83\x93\x83\x56\x83\x87\x83\x62\x83\x67\x83\x90\x83\x5A\x83\x93\x83\x5E\x83\x4E  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_VIDEO_BRIGHTNESS
    // アカルサ
    "\x83\x41\x83\x4A\x83\x8B\x83\x54             : %d",

    // MSG_VIDEO_CONTRAST
    // コントラスト
    "\x83\x52\x83\x93\x83\x67\x83\x89\x83\x58\x83\x67           : %d",

    // MSG_VIDEO_SATURATION
    // サイド (彩度)
    "\x83\x54\x83\x43\x83\x68              : %d",

    // MSG_VIDEO_COLORTEMP
    // イロオンド (色温度)
    "\x83\x43\x83\x8D\x83\x49\x83\x93\x83\x68           : %d",

    // MSG_VIDEO_SHARPNESS
    // シャープネス
    "\x83\x56\x83\x83\x81\x5B\x83\x76\x83\x6C\x83\x58          : %s",

    // MSG_VIDEO_GRID
    // LCDグリッド
    "LCD\x83\x4F\x83\x8A\x83\x62\x83\x68        : %s",

    // MSG_VIDEO_COLOR_R
    // アカブースト
    "\x83\x41\x83\x4A\x83\x75\x81\x5B\x83\x58\x83\x67          : %d",

    // MSG_VIDEO_COLOR_G
    // ミドリブースト
    "\x83\x7E\x83\x68\x83\x8A\x83\x75\x81\x5B\x83\x58\x83\x67        : %d",

    // MSG_VIDEO_COLOR_B
    // アオブースト
    "\x83\x41\x83\x49\x83\x75\x81\x5B\x83\x58\x83\x67          : %d",

    // MSG_HELP_SUBMENU_VIDEO
    // ビデオ:ヒョウジ,フィルタ,カラー  O:モドル
    "\x83\x72\x83\x66\x83\x49:\x83\x71\x83\x87\x83\x45\x83\x57,\x83\x74\x83\x42\x83\x8B\x83\x5E,\x83\x4A\x83\x89\x81\x5B  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_SUBMENU_PERFORMANCE
    // パフォーマンス:フレームスキップ,CPU  O:モドル
    "\x83\x70\x83\x74\x83\x48\x81\x5B\x83\x7D\x83\x93\x83\x58:\x83\x74\x83\x8C\x81\x5B\x83\x80\x83\x58\x83\x4C\x83\x62\x83\x76,CPU  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_SUBMENU_AUDIO
    // サウンド:オンリョウセッテイ  O:モドル
    "\x83\x54\x83\x45\x83\x93\x83\x68:\x83\x49\x83\x93\x83\x8A\x83\x87\x83\x45\x83\x5A\x83\x62\x83\x65\x83\x43  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_SUBMENU_CONTROLS
    // コントロール:ボタンマッピング  O:モドル
    "\x83\x52\x83\x93\x83\x67\x83\x8D\x81\x5B\x83\x8B:\x83\x7B\x83\x5E\x83\x93\x83\x7D\x83\x62\x83\x73\x83\x93\x83\x4F  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_SUBMENU_SYSTEM
    // システム:ゲンゴ,BIOS  O:モドル
    "\x83\x56\x83\x58\x83\x65\x83\x80:\x83\x51\x83\x93\x83\x53,BIOS  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_VIDEO_BRIGHTNESS
    // アカルサ (4=ヒョウジュン)  O:モドル
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":\x83\x41\x83\x4A\x83\x8B\x83\x54 (4=\x83\x71\x83\x87\x83\x45\x83\x57\x83\x85\x83\x93)  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_VIDEO_CONTRAST
    // コントラスト (4=ヒョウジュン)  O:モドル
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":\x83\x52\x83\x93\x83\x67\x83\x89\x83\x58\x83\x67 (4=\x83\x71\x83\x87\x83\x45\x83\x57\x83\x85\x83\x93)  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_VIDEO_SATURATION
    // サイド (8=ヒョウジュン)  O:モドル
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":\x83\x54\x83\x43\x83\x68 (8=\x83\x71\x83\x87\x83\x45\x83\x57\x83\x85\x83\x93)  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_VIDEO_COLORTEMP
    // イロオンド (0=アタタカ,16=スズ)  O:モドル
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":\x83\x43\x83\x8D\x83\x49\x83\x93\x83\x68 (0=\x83\x41\x83\x5E\x83\x5E\x83\x4A,16=\x83\x58\x83\x59)  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_VIDEO_SHARPNESS
    // シャープネス (0=オフ)  O:モドル
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":\x83\x56\x83\x83\x81\x5B\x83\x76\x83\x6C\x83\x58 (0=\x83\x49\x83\x74)  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_VIDEO_GRID
    // LCDグリッド  O:モドル
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":LCD\x83\x4F\x83\x8A\x83\x62\x83\x68  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_HELP_VIDEO_COLOR_RGB
    // カラーブースト (4=ニュートラル)  O:モドル
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":\x83\x4A\x83\x89\x81\x5B\x83\x75\x81\x5B\x83\x58\x83\x67 (4=\x83\x6A\x83\x85\x81\x5B\x83\x67\x83\x89\x83\x8B)  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_OPTION_MENU_HELP_0
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   ����",

    // MSG_OPTION_MENU_HELP_1
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   ����",

    // MSG_OPTION_MENU_HELP_2
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   ����",

    // MSG_OPTION_MENU_HELP_SHOW_FPS
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   �G�~�����[�^",

    // MSG_OPTION_MENU_HELP_OPTIMIZATIONS
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   �G�~�����[�^",

    // MSG_OPTION_MENU_HELP_COLOR_CORRECTION
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   GBA�̐F�␳",

    // MSG_OPTION_MENU_HELP_BUTTON_MAPPING
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   X/O����O/X�{�^���}�b�s���O",

    // MSG_OPTION_MENU_HELP_3
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   ����",

    // MSG_OPTION_MENU_HELP_4
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   ����",

    // MSG_OPTION_MENU_HELP_5
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   ����",

    // MSG_OPTION_MENU_HELP_6
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   ����",

    // MSG_OPTION_MENU_HELP_7
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   �G�~�����[�^",

    // MSG_OPTION_MENU_HELP_8
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   �G�~�����[�^",

    // MSG_OPTION_MENU_HELP_9
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   �G�~�����[�^",

    // MSG_OPTION_MENU_HELP_10
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��   �G�~�����[�^",

    // MSG_OPTION_MENU_DEFAULT
    "��:������",

    // MSG_OPTION_MENU_HELP_11
    "��:���C�����j���[",

    // MSG_OPTION_MENU_HELP_12
    // セイカクサ/セイノウ  O:モドル
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":\x83\x5A\x83\x43\x83\x4C\x83\x4A\x83\x58/\x83\x5A\x83\x43\x83\x6E\x83\x45  O:\x83\x82\x83\x68\x83\x8B",

    // MSG_STATE_MENU_DATE_FMT_0
    "%4d/%2d/%2d %-4s %2d:%02d:%02d",

    // MSG_STATE_MENU_DATE_FMT_1
    "%2d/%2d/%4d %-4s %2d:%02d:%02d",

    // MSG_STATE_MENU_DATE_NONE_0
    "----/--/-- ---- --:--:--",

    // MSG_STATE_MENU_DATE_NONE_1
    "--/--/---- ---- --:--:--",

    // MSG_STATE_MENU_STATE_NONE
    "���̃X���b�g�Ƀf�[�^�͂���܂���",

    // MSG_STATE_MENU_TITLE
	#include "text/state_menu_t.h"

    // MSG_STATE_MENU_0
    "",

    // MSG_STATE_MENU_1
    "�t�@�C������X�e�[�g�����[�h",

    // MSG_STATE_MENU_2
    "�߂�",

    // MSG_STATE_MENU_HELP_0
    "��:���s  " FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I��",

    // MSG_STATE_MENU_HELP_1
    "��:�t�@�C���u���E�U",

    // MSG_STATE_MENU_HELP_2
    "��:���C�����j���[",

    // MSG_PAD_MENU_TITLE
	#include "text/pad_menu_t.h"

    // MSG_PAD_MENU_0
    "Up     : %s",

    // MSG_PAD_MENU_1
    "Down   : %s",

    // MSG_PAD_MENU_2
    "Left   : %s",

    // MSG_PAD_MENU_3
    "Right  : %s",

    // MSG_PAD_MENU_4
    "△     : %s",

    // MSG_PAD_MENU_5
    "○     : %s",

    // MSG_PAD_MENU_6
    "×     : %s",

    // MSG_PAD_MENU_7
    "□     : %s",

    // MSG_PAD_MENU_8
    FONT_L_TRIGGER "�@�@ : %s",

    // MSG_PAD_MENU_9
    FONT_R_TRIGGER "�@�@ : %s",

    // MSG_PAD_MENU_10
    "START  : %s",

    // MSG_PAD_MENU_11
    "SELECT : %s",

    // MSG_PAD_MENU_12
    "Back",

    // MSG_PAD_MENU_HELP_0
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":Select",

    // MSG_PAD_MENU_HELP_1
    "X:Return to main menu",

    //PAD�̐ݒ� �R���t�B�O

    // MSG_PAD_MENU_CFG_0
    "��",

    // MSG_PAD_MENU_CFG_1
    "��",

    // MSG_PAD_MENU_CFG_2
    "��",

    // MSG_PAD_MENU_CFG_3
    "��",

    // MSG_PAD_MENU_CFG_4
    "A",

    // MSG_PAD_MENU_CFG_5
    "B",

    // MSG_PAD_MENU_CFG_6
    "L",

    // MSG_PAD_MENU_CFG_7
    "R",

    // MSG_PAD_MENU_CFG_8
    "�X�^�[�g",

    // MSG_PAD_MENU_CFG_9
    "�Z���N�g",

    // MSG_PAD_MENU_CFG_10
    "���j���[",

    // MSG_PAD_MENU_CFG_11
    "�^�[�{",

    // MSG_PAD_MENU_CFG_12
    "�X�e�[�g���[�h",

    // MSG_PAD_MENU_CFG_13
    "�X�e�[�g�Z�[�u",

    // MSG_PAD_MENU_CFG_14
    "A�A��",

    // MSG_PAD_MENU_CFG_15
    "B�A��",

    // MSG_PAD_MENU_CFG_16
    "L�A��",

    // MSG_PAD_MENU_CFG_17
    "R�A��",

    // MSG_PAD_MENU_CFG_18
    "�t���[�����[�g�\��",

    // MSG_PAD_MENU_CFG_19
    "�Ȃ�",

    // MSG_A_PAD_MENU_TITLE
	#include "text/a_pad_menu_t.h"

    // MSG_A_PAD_MENU_0
    "Analog Up : %s",

    // MSG_A_PAD_MENU_1
    "Analog Down : %s",

    // MSG_A_PAD_MENU_2
    "Analog Left : %s",

    // MSG_A_PAD_MENU_3
    "Analog Right : %s",

    // MSG_A_PAD_MENU_4
    "Analog input enabled: %s",

    // MSG_A_PAD_MENU_5
    "Analog input sensitivity: %d",

    // MSG_A_PAD_MENU_6
    "Back",

    // MSG_A_PAD_MENU_HELP_0
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":Select",

    // MSG_A_PAD_MENU_HELP_1
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":Select",

    // MSG_A_PAD_MENU_HELP_2
    "X:Return to main menu",

	//MSG_CHEAT_MENU_TITLE,
	#include "text/cheat_menu_t.h"

	//MSG_CHEAT_MENU_NON_LOAD,
	"(��) %2d: ------------------------",

	//MSG_CHEAT_MENU_0,
	"%%s %2d: %s",

	//MSG_CHEAT_MENU_1,
	"�`�[�g�t�@�C���̃��[�h  " FONT_L_TRIGGER,

	//MSG_CHEAT_MENU_2,
	"�߂�",

	//MSG_CHEAT_MENU_3,
	"�`�[�g�y�[�W: %d",

	//MSG_CHEAT_MENU_HELP_0,
	FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�I�������R�[�h�̗L���^�����̐ؑ�",

	//MSG_CHEAT_MENU_HELP_1,
	"��:�`�[�g�t�@�C�������[�h���܂�  " FONT_L_TRIGGER ":�V���[�g�J�b�g",

	//MSG_CHEAT_MENU_HELP_2,
	"��:���C�����j���[�ɖ߂�܂�",

	//MSG_CHEAT_MENU_HELP_3,
	FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":�y�[�W��ύX",

    //MSG_OVERLAY_MENU_TITLE
    "ｵｰﾊﾞｰﾚｲｾﾝﾀｸ",

    //MSG_OVERLAY_MENU_0
    "ｵｰﾊﾞｰﾚｲ         : %s",

    //MSG_OVERLAY_MENU_1
    "ﾋｮｳｼﾞ            : %s",

    //MSG_OVERLAY_MENU_2
    "Xｵﾌｾｯﾄ          : %d",

    //MSG_OVERLAY_MENU_3
    "Yｵﾌｾｯﾄ          : %d",

    //MSG_OVERLAY_MENU_4
    "ﾒｲﾝﾒﾆｭｰﾆﾓﾄﾞﾙ",

    //MSG_OVERLAY_MENU_HELP_0
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":ｵｰﾊﾞｰﾚｲﾌｧｲﾙｦｾﾝﾀｸ",

    //MSG_OVERLAY_MENU_HELP_1
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":ｵｰﾊﾞｰﾚｲｦｵﾝ/ｵﾌ",

    //MSG_OVERLAY_MENU_HELP_2
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":Xｲﾁﾖｳｾｲ (0-240)",

    //MSG_OVERLAY_MENU_HELP_3
    FONT_CURSOR_LEFT FONT_CURSOR_RIGHT ":Yｲﾁﾖｳｾｲ (0-112)",

    //MSG_OVERLAY_MENU_HELP_4
    "X:ﾒｲﾝﾒﾆｭｰﾆﾓﾄﾞﾙ",

    // MSG_NON_LOAD_GAME
    "�Q�[���̓��[�h����Ă��܂���",

    // MSG_DAYW_0
    "(��)",

    // MSG_DAYW_1
    "(��)",

    // MSG_DAYW_2
    "(��)",

    // MSG_DAYW_3
    "(��)",

    // MSG_DAYW_4
    "(��)",

    // MSG_DAYW_5
    "(��)",

    // MSG_DAYW_6
    "(�y)",

    // MSG_YES
    "�͂�",

    // MSG_NO
    "������",

    // MSG_ON
    "�I��",

    // MSG_OFF
    "�I�t",

    // MSG_ENABLED
    "�L��",

    // MSG_DISABLED
    "����",

    // MSG_AUTO
    "����",

    // MSG_MANUAL
    "�蓮",

    // MSG_EXITONLY
    "�I�����̂�",

    // MSG_LOAD
    "���[�h",

    // MSG_SAVE
    "�Z�[�u",

    // MSG_SCN_SCALED_NONE
    "100% GU",

    // MSG_SCN_SCALED_X15_GU
    "150% GU",

    // MSG_SCN_SCALED_X15_SW
    "150% SW",

    // MSG_SCN_SCALED_USER
    "�w�� GU",

    // MSG_LANG_JAPANESE
    "���{��",

    // MSG_LANG_ENGLISH
    "�p��",

    // MSG_LANG_CHS
    "��������",

    // MSG_LANG_CHT
    "��������",

    // MSG_SS_DATE_FMT_0
    "%04d_%02d_%02d_%s%02d_%02d_%02d_%03d",

    // MSG_SS_DATE_FMT_1
    "%02d_%02d_%04d_%s%02d_%02d_%02d_%03d",

    // MSG_ERR_SET_DIR_0
    "�G���[ [%s] �w�肳�ꂽ�f�B���N�g���͖����ł��B",

    // MSG_ERR_SET_DIR_1
    "�G���[ [%s] �w�肪����܂���B",

    // MSG_ERR_SET_DIR_2
    "�G���[�̔����������ڂ́A�ȉ��̃f�B���N�g���ɐݒ肵�܂��B\n%s",

    // png.c
    // MSG_ERR_SS_PNG_0
    "�������̊m�ۂ��o���܂���ł����B",

    // MSG_ERR_SS_PNG_1
    "PNG�C���[�W�̍쐬���o���܂���ł����B",

    // memory.c
    // MSG_LOADING_ROM
    "���[�h��...",

    // MSG_SEARCHING_BACKUP_ID
    "BACKUP ID ��������",

    // main.c
    // MSG_GBA_SLEEP_MODE
    "�X���[�v ���[�h",

    // MSG_ERR_LOAD_DIR_INI
    "dir.ini�����[�h�o���܂���B���ׂĂ��ȉ��̃f�B���N�g���ɐݒ肵�܂��B\n%s",

    // MSG_ERR_BIOS_NONE
    "BIOS�t�@�C�������[�h�o���܂���B",

    // MSG_ERR_LOAD_GAMEPACK
    "�Q�[���t�@�C�������[�h�o���܂���B",

    // MSG_ERR_OPEN_GAMEPACK
    "�Q�[���t�@�C�����ǂ߂܂���B",

    // MSG_ERR_START_CALLBACK_THREAD
    "�R�[���o�b�N�X���b�h���J�n�o���܂���B",

    // sound.c
    // MSG_ERR_RESERVE_AUDIO_CHANNEL
    "�I�[�f�B�I�`�����l�����m�ۏo���܂���B",

    // MSG_ERR_START_SOUND_THEREAD
    "�T�E���h�X���b�h���J�n�o���܂���B",

    // MSG_ERR_MALLOC
    "�������̊m�ۂ��o���܂���B",

    // MSG_ERR_CONT
    "�����{�^���������Ă��������B",

    // MSG_ERR_QUIT
    "�����{�^���������ƏI�����܂��B",

    // MSG_BLANK
    ""
  },
#include "text/message_ansi.h"
};

