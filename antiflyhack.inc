/*
    Light Anti Cheat
    (C) 2024 | Lasho4

    * Callback

    - OnPlayerDetectFlyHack(playerid)
*/
#if defined _antiflyhack_included
    #endinput
#endif
#define _antiflyhack_included

#if !defined _samp_included
    #error "`a_samp` must be defined"
#endif

forward OnPlayerDetectFlyHack(playerid);

static
        s_AntiFlyHackWarningSpam[MAX_PLAYERS];

public OnPlayerSpawn(playerid)
{
    s_AntiFlyHackWarningSpam[playerid] = gettime()+3;
    #if defined afh_OnPlayerSpawn
		return afh_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn afh_OnPlayerSpawn
#if defined afh_OnPlayerSpawn
	forward afh_OnPlayerSpawn(playerid);
#endif

public OnPlayerUpdate(playerid)
{
    if(s_AntiFlyHackWarningSpam[playerid] < gettime())
    {
        new _animid;
        if((_animid=GetPlayerAnimationIndex(playerid)) && (1538 <= _animid <= 1544))
        {
            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);
            if((z) > (1.5))
            {
                CallRemoteFunction("OnPlayerDetectFlyHack", "i", playerid);
                s_AntiFlyHackWarningSpam[playerid] = gettime()+3;
            }
        }
    }
	#if defined afh_OnPlayerUpdate
		return afh_OnPlayerUpdate(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate afh_OnPlayerUpdate
#if defined afh_OnPlayerUpdate
	forward afh_OnPlayerUpdate(playerid);
#endif