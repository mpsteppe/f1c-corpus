// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00496380
// Canonical corpus name: sub_496380
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_496380_00496380.c

void UnknownObject::TitleSplashResourceLoad()
{
    // Loads the title-screen bitmap resource. When global flag dword_7D0398 (fill label: PhotoFreeCameraFlag) is zero, loads the default title bitmap aGametitleBmp and returns that result directly. Otherwise attempts the magazine/promotional splash aPmbeltiteMag and falls back to aGametitleBmp when the magazine load does not return byte value 1. Returns the last ResourceFileLoader result.
    // GUARD: If dword_7D0398 is zero (fill label: PhotoFreeCameraFlag clear), skip the magazine-splash path and load the default title bitmap. [global:0x007D0398, source:raw]
    // CALL: ResourceFileLoader(aGametitleBmp, 0.0, 0): load the default title-screen bitmap and return its result directly. [callee:0x004F9D60, global:0x005CC9F0, source:raw]
    // RETURN: Return the ResourceFileLoader result from the flag-clear path. [source:raw]
    // CALL: result = ResourceFileLoader(aPmbeltiteMag, 0.0, 0): attempt to load the magazine/promotional splash bitmap. [callee:0x004F9D60, global:0x005CCA00, source:raw]
    // GUARD: If the low byte of the magazine load result is not 1, treat the load as failed and fall back to the default title bitmap. [callee:0x004F9D60, global:0x005CC9F0, source:raw]
    // CALL: ResourceFileLoader(aGametitleBmp, 0.0, 0): load the default title bitmap on the fallback path. [callee:0x004F9D60, global:0x005CC9F0, source:raw]
    // RETURN: Return the magazine loader result when it succeeded (byte value 1). [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D0398 == 0) return ResourceFileLoader(aGametitleBmp, 0.0, 0);
    //   result = ResourceFileLoader(aPmbeltiteMag, 0.0, 0);
    //   if (result != 1) return ResourceFileLoader(aGametitleBmp, 0.0, 0);
    //   return result;
    // UNRESOLVED: unk_8AFE18 (0x008AFE18) is listed as a packet global (fill label: GameRacePhaseTimer, DERIVED) but the raw source of this function never reads it; the fill attributes its access to ResourceFileLoader, which is not evidenced in this packet.
    // UNRESOLVED: The role of the 0.0 and 0 arguments to ResourceFileLoader is not named in the packet; the fill describes them as position/alpha parameters (DERIVED).
}
