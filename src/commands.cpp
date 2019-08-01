#include "extdll.h"
#include "meta_api.h"
#include "utils.h"
#include "plugininfo.h"

void cmd_plugin_version()
{
    PRINT_CONSOLE("Anti_Old xash3d client version %s\n", VVERSION);
    PRINT_CONSOLE("Build date: %s %s\n", __DATE__, __TIME__);
    PRINT_CONSOLE("Compiler version: %s\n", __VERSION__);
    #ifdef DEBUG
    PRINT_CONSOLE("Debug Build\n");
    #endif
}

void cmd_plugin_usage( void )
{
    PRINT_CONSOLE("AntiOld\n");
    PRINT_CONSOLE("usage: antiold <command> [<arguments>]\n");
    PRINT_CONSOLE("   version          - display plugin version info\n");
}

void plugin_COMMAND( void )
{
    const char *cmd;

    cmd = CMD_ARGV(1);

    if (!strcasecmp(cmd, "version"))
        cmd_plugin_version();
    else
	{
        PRINT_CONSOLE("Unrecognized plugin command: %s\n", cmd);
        cmd_plugin_usage();
        return;
	}
}
