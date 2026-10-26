// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0690
// Canonical corpus name: SceneClearReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneClearReset_004a0690.c

void UnknownObject::SceneClearReset()
{
    // Scene clear/reset sequence. Initializes the array-check structure at dword_7D2DB0, selects a track scene path (dword_7CE5EC when non-null, else the fallback byte_5EA438) and loads it via TrackSceneLoader, resets the sound system through a virtual call when the dword_5EB10C interface pointer is alive, reinitializes the buffer at flt_5EA618 with default float values, and finishes by calling the scene sub-initializer sub_4A09F0 on this.
    // CALL: ArrayCheckInit(&dword_7D2DB0) initializes the global array bounds/check structure. [callee:0x004C2810, global:0x007D2DB0, source:raw]
    // ASSIGNMENT: Select the track scene path: use dword_7CE5EC, falling back to the default byte_5EA438 when it is null. [global:0x007CE5EC, global:0x005EA438, source:raw]
    // CALL: TrackSceneLoader(selected path) loads the track scene from the chosen directory. [callee:0x004C55B0, source:raw]
    // GUARD: Sound system reset only runs when the dword_5EB10C interface pointer is non-null. [global:0x005EB10C, source:raw]
    // CALL: Virtual call through the dword_5EB10C interface vtable slot 12, passing the interface itself (thiscall reset/clear of the sound engine). [global:0x005EB10C, source:raw]
    // CALL: BufferInitWith10fDefaults(flt_5EA618) reinitializes the global float buffer with default 10f values. [callee:0x004186A0, global:0x005EA618, source:raw]
    // CALL: sub_4A09F0(this) runs the session scene sub-initializer on the context object. [callee:0x004A09F0, source:raw]
    // RETURN: Return 0 to signal successful scene clear/reset. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A0690(void *this) {
    //     ArrayCheckInit(&dword_7D2DB0);
    //     char *path = dword_7CE5EC;
    //     if (!dword_7CE5EC) path = byte_5EA438;
    //     TrackSceneLoader(path);
    //     if (dword_5EB10C)
    //       (*(void (__thiscall **)(int))(*dword_5EB10C + 12))(dword_5EB10C);
    //     BufferInitWith10fDefaults(flt_5EA618);
    //     sub_4A09F0(this);
    //     return 0;
    //   }
    // UNRESOLVED: The virtual call target at vtable slot 12 of dword_5EB10C is a known sound-system reset in the skeleton fill but the callee address is absent from packet facts, so the exact routine is unverified.
    // UNRESOLVED: unk_8AC368 is listed as a packet global but never appears in the raw decompiled source of this function; its role (VehicleSetupBase in the fill) cannot be grounded here.
    // UNRESOLVED: byte_5EA438 as default directory and flt_5EA618 as float buffer are DERIVED roles; the object owning this context is unknown.
}
