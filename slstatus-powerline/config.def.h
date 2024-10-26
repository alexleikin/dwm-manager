
/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

static const struct arg args[] = {
    /* function 	format          	argument */
    //{disk_free,   "[ %s / ",           "/"},         
    //{disk_total,  "%s] | ",           "/"},
    {run_command,    "^c#f0416f^\ue0b2^b#f0416f^^c#000100^ ﮮ %s ^c#f2e7a0^\ue0b2",    "cat ~/.local/countpackages"},
    {run_command,    "^b#f2e7a0^^c#000100^ %s ^c#67a7db^\ue0b2",    "~/bin/vol.sh"},
    {run_command,    "^b#67a7db^^c#000100^  %s ^c#71d94c^\ue0b2",    "sensors | awk '/^Tctl/ {print $2}'"},
    {cpu_perc,    "^b#71d94c^^c#100548^  %s%% ^c#e0af68^\ue0b2",      NULL},
    {ram_used,    "^b#e0af68^^c#15161e^  %s/",           NULL},
    {ram_total,   "%s ^c#bb9af6^\ue0b2",           NULL},
    {datetime,    "^b#bb9af6^^c#000100^  %s ^c#f7768e^\ue0b2",           "%F"},
    {datetime,	  "^b#f7768e^^c#000100^  %s ",	"%T"}
};




//	{run_command, "C %s |", "sensors | awk '/^Tctl/ {print $2}'"},
//	{run_command, "A %s |", "sensors | grep '^mem' | awk '{print $2}'"},
