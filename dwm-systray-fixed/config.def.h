/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int attachmode         = 0;        /* 0 master (default), 1 = above, 2 = aside, 3 = below, 4 = bottom */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const char *fonts[]          = { "Lato:regular:pixelsize=22:antialias=true:autohint=true","Iosevka Nerd Font:pixelsize=22:antialias=true:autohint=true"  };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const unsigned int baralpha = 100;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
        [SchemeStatus]  = { "#B0BEC5", col_gray1,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
        [SchemeTagsSel]  = { "#FB8C00", col_gray1,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
        [SchemeTagsNorm]  = { "#B0BEC5", col_gray1,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
        [SchemeInfoSel]  = { col_gray4, "#000000",  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
        [SchemeInfoNorm]  = { col_gray1, col_gray1,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};
static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
    [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
    [SchemeStatus] = { OPAQUE, baralpha, borderalpha },
    [SchemeTagsSel] = { OPAQUE, baralpha, borderalpha },
    [SchemeTagsNorm]  = { OPAQUE, baralpha, borderalpha },
    [SchemeInfoSel]  = { OPAQUE, baralpha, borderalpha },
    [SchemeInfoNorm]  = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"alacritty", "--class", "spterm1", "--config-file", "/home/alex/.config/alacritty/alacritty-scratch.toml", NULL };
const char *spcmd2[] = {"alacritty", "--class", "spterm2", "--config-file", "/home/alex/.config/alacritty/alacritty-scratch.toml", "-e", "ncmpcpp", NULL };
const char *spcmd3[] = {"qalculate-gtk", NULL };
static Sp scratchpads[] = {
       /* name          cmd  */
       {"spterm1",     spcmd1},
       {"spterm2",     spcmd2},
       {"qalculate-gtk",   spcmd3},
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "", "", "","", "", "", "󰨞", "", "", "" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
        /* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
        { "vlc",                NULL,       NULL,       1 << 0,            1,           -1 },
        { "firefox",            NULL,       NULL,       1 << 2,            0,           -1 },
        { "TelegramDesktop",    NULL,       NULL,       1 << 3,            0,           -1 },
        { "Pcmanfm",            NULL,       NULL,       1 << 4,            1,           -1 },
        { "Code",               NULL,       NULL,       1 << 6,            0,           -1 },
        { "discord",            NULL,       NULL,       1 << 5,            0,           -1 },
        { "Brave-browser",      NULL,       NULL,       1 << 7,            0,           -1 },
        { "Virt-manager",       NULL,       NULL,       1 << 8,            0,           -1 },
        { "zoom",               NULL,       NULL,       1 << 9,            0,           -1 },
        { NULL,                 "spterm1",  NULL,       SPTAG(0),          1,           -1 },
        { NULL,                 "spterm2",  NULL,       SPTAG(1),          1,           -1 },
        { NULL,                 "qalculate-gtk",     NULL,       SPTAG(2),          1,           -1 },
       /* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
        { "st",           NULL,     NULL,           0,         0,          1,           0,        -1  },
        { "kitty",        NULL,     NULL,           0,         0,          1,           0,        -1  },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include <X11/XF86keysym.h>
#include "vanitygaps.c"
#include "shiftview.c"

static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "D[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid }, { "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define MODKEY1 Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "/home/alex/bin/rdmenu.sh", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *lockcmd[]  = { "/home/alex/bin/lock", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
        { 0,                            XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
        { 0,                            XF86XK_AudioMute, spawn, {.v = mutevol } },
        { 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },
        { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
        { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
        { Mod1Mask,                     XK_l,      spawn,          {.v = lockcmd } },
        { MODKEY,                       XK_b,      togglebar,      {0} },
        { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
        { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
        { MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = +1 } },
        { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
        { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
        { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
        { MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
        { MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
        { MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
        { MODKEY,                       XK_Return, zoom,           {0} },
        { MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
        { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
        { MODKEY,                       XK_Tab,    view,           {0} },
        { MODKEY,                       XK_w,      killclient,     {0} },
        { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
        { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
        { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
        { MODKEY,                       XK_space,  setlayout,      {0} },
        { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
        { MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
        { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
        { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
        { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
        { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
        { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
        { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        { MODKEY,                       XK_n,      shiftview,      {.i = +1 } },
        { MODKEY|ShiftMask,             XK_n,      shiftview,      {.i = -1 } },
        { MODKEY1,                      XK_t,      togglescratch,  {.ui = 0 } },
        { MODKEY1,                      XK_m,      togglescratch,  {.ui = 1 } },
        { MODKEY1,                      XK_c,      togglescratch,  {.ui = 2 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
        { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
        { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
        { ClkWinTitle,          0,              Button2,        zoom,           {0} },
        { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
        { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
        { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
        { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
        { ClkTagBar,            0,              Button1,        view,           {0} },
        { ClkTagBar,            0,              Button3,        toggleview,     {0} },
        { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
        { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
