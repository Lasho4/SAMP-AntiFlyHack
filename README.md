# SAMP-AntiFlyHack
Anti Fly Hack for San Andreas Multiplayer

## Usage
``` pawn
#include <antiflyhack.inc>
```

## Example
```pawn
public OnPlayerDetectFlyHack(playerid)
{
    SendClientMessage(playerid, 0xE74C3CFF, "You kicked for cheating! {F5B041}Fly hack");
    SetTimerEx("DelayKick", 500, false, "i", playerid);
    return 1;
}

forward DelayKick(playerid);
public DelayKick(playerid) return Kick(playerid);
```
