#include "callbacks.h"
#include "utils.h"
#include "plugininfo.h"

qboolean pfnClientConnect(edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128])
{
    QUERY_CLIENT_CVAR_VALUE2(pEntity, "host_build", GETPLAYERUSERID(pEntity));

    RETURN_META_VALUE(MRES_IGNORED, 0);
}

void pfnCvarValue2(const edict_t *pEnt, int requestID, const char *pszCvarName, const char *pszValue)
{

    if (requestID != GETPLAYERUSERID((edict_t *)pEnt))
    {
        ALERT(at_console, "[%s] Error while checking player with AUTHID %s: Request id did not match\n", VLOGTAG);
        RETURN_META(MRES_IGNORED);
    }

    if (atoi(pszValue) < 1200)
    {
        CLIENT_PRINTF((edict_t *)pEnt, print_console, "Your client %s is old. Please update your xash3d\n");
        ALERT(at_console, "[%s] Client with AUTHID %s have an old version of xash3d (%s)\n", VLOGTAG, GETPLAYERAUTHID((edict_t *)pEnt), pszValue);
        SERVER_COMMAND(va("kick #%i", GETPLAYERUSERID((edict_t *)pEnt)));
        SERVER_EXECUTE();
        RETURN_META(MRES_IGNORED);
    }
    else
    {
        ALERT(at_console, "[%s] %s value : %s\n", VLOGTAG, pszCvarName, pszValue);
    }

    RETURN_META(MRES_IGNORED);
}
