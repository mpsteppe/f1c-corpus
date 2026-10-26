// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CEEF0
// Canonical corpus name: sub_4CEEF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CEEF0_004ceef0.c

void UnknownObject::BuildTerrainIniPath()
{
    // Constructs the file path to terrain.ini by formatting the season and track directory globals into a caller-supplied buffer via StringFormatWithBufferOverflowCheck. Each directory global falls back to the default application directory (byte_5EA438) when null. Called from scene/particle/telemetry initialization paths.
    // ASSIGNMENT: v2 = dword_5EC420 (track directory); when null, v2 = byte_5EA438 (default application directory). [global:0x005EC420, global:0x005EA438, source:raw]
    // GUARD: Null guard on the track directory global dword_5EC420; if zero, substitute the default directory byte_5EA438. [global:0x005EC420, global:0x005EA438, source:raw]
    // ASSIGNMENT: v3 = dword_5EC3D8 (season directory); when null, v3 = byte_5EA438 (default application directory). [global:0x005EC3D8, global:0x005EA438, source:raw]
    // GUARD: Null guard on the season directory global dword_5EC3D8; if zero, substitute the default directory byte_5EA438. [global:0x005EC3D8, global:0x005EA438, source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck(a1, "%s%sterrain.ini", v3, v2) formatting the two directory paths plus the terrain.ini literal (aSSterrainIni at 0x005D3930) into the caller-supplied target buffer a1. [callee:0x0058815F, global:0x005D3930, source:raw]
    // RETURN: Return the result of the formatting call to the caller. [source:raw]
    // CALL: Invoked by SceneTrackFileLoader (0044C0E0), ParticleSoundEffectSpawner (004607A0), SpecialFX_Init (004CF070) and TelemetryDataDump (004D4A80) to obtain the terrain.ini path during track/effect/telemetry setup. [caller:0x0044C0E0, caller:0x004607A0, caller:0x004CF070, caller:0x004D4A80, source:raw]

    // Conservative worker pseudocode:
    //   v2 = dword_5EC420 ? dword_5EC420 : byte_5EA438;
    //   v3 = dword_5EC3D8 ? dword_5EC3D8 : byte_5EA438;
    //   return StringFormatWithBufferOverflowCheck(a1, "%s%sterrain.ini", v3, v2);
    // UNRESOLVED: a1 and a2 roles: a1 is the target buffer of the format call; a2 is unused in the raw source and its purpose is unknown.
    // UNRESOLVED: The exact meaning of the season/track directory globals (dword_5EC3D8, dword_5EC420) and of byte_5EA438 (assumed default application directory) is DERIVED from call context, not proven here.
}
