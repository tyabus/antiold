#pragma once

#include "extdll.h"
#include "meta_api.h"

qboolean pfnClientConnect(edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128]);

// new api

void pfnCvarValue2(const edict_t *pEnt, int requestID, const char *pszCvarName, const char *pszValue);
