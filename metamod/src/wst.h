#pragma once

#include <ISmmPlugin.h>
#include <iserver.h>
#include "igameevents.h"
#include "steam/isteamhttp.h"
#include "vscript/ivscript.h"


struct WSTConfig {
    bool detourHostSay;
};

class WSTPlugin : public ISmmPlugin, public IMetamodListener
{
public:
	bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
	bool Unload(char *error, size_t maxlen);
	bool Pause(char *error, size_t maxlen);
	bool Unpause(char *error, size_t maxlen);
	void AllPluginsLoaded();
//	void Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *);

public:
	const char *GetAuthor();
	const char *GetName();
	const char *GetDescription();
	const char *GetURL();
	const char *GetLicense();
	const char *GetVersion();
	const char *GetDate();
	const char *GetLogTag();

    void Hook_GameServerSteamAPIActivated();
    void Hook_GameServerSteamAPIDeactivated();

    WSTConfig LoadOrCreateConfig();

    IScriptVM *Hook_CreateVM(ScriptLanguage_t language);
};

extern WSTPlugin g_WSTPlugin;