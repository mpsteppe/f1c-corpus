// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C920
// Canonical corpus name: CamMan_Init
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CamMan_Init_0040c920.c

void UnknownObject::CamManInit()
{
    // Camera-manager initializer. Optionally writes a debug log entry when the source-path string split returns non-zero, resolves the manager handle from the "mainview" wide string, clears six game-state globals (0x5EA500/0x5EA504/0x5EA508/0x5EA550/0x5EA554/0x5EA558), then loads the scene file, resolves module asset paths, runs the camera config loader, clears a byte flag at this+0x2D, copies this+0x18 into this+0x8 when the sub_40C140 config-load check fails, and returns the result of GlobalFlagSetClear(32, 1). Called by Game_Init (0042D6B0).
    // GUARD: Debug log is gated on StringSplitLoop(2, aDDevF119992002_15, 3633) returning non-zero [callee:0x004D7A50, global:0x005BE958, source:raw]
    // CALL: When the split guard passes, DebugLogWrite(&dword_8AD25C, aEnteredCammanI) records the "entered camman init" message [callee:0x004D7AA0, global:0x008AD25C, global:0x005BE940, source:raw]
    // CALL: TwoLevelWideStringSearch(aMainview) resolves the camera manager handle and stores it in this+0x0 [callee:0x00544F50, global:0x005BE8E0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clears six game-state globals to 0: dword_5EA550, dword_5EA554, dword_5EA558, dword_5EA500, dword_5EA504, dword_5EA508 [global:0x005EA500, global:0x005EA504, global:0x005EA508, global:0x005EA550, global:0x005EA554, global:0x005EA558, source:raw]
    // CALL: SceneFileLoadByCurrentIndex(this) loads the current scene file into the manager [callee:0x0040C240, source:raw]
    // CALL: ModuleAssetPathResolver(this) resolves the module's asset paths [callee:0x0040C3B0, source:raw]
    // CALL: sub_40C520(this) runs the camera configuration loader [callee:0x0040C520, source:raw]
    // ASSIGNMENT: Writes 0 to the byte flag at this+0x2D [field:this:0x0000002D, source:raw]
    // GUARD: When sub_40C140(this) returns 0, the config-loader result stored in this+0x18 is copied into this+0x8 [callee:0x0040C140, field:this:0x00000018, field:this:0x00000008, source:raw]
    // RETURN: Returns the result of GlobalFlagSetClear(32, 1), setting global init flag 32 [callee:0x0054A200, source:raw]
    // CALL: Invoked by Game_Init (0042D6B0) during game startup [caller:0x0042D6B0, source:raw]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(2, aDDevF119992002_15, 3633))
    //       DebugLogWrite(&dword_8AD25C, aEnteredCammanI);
    //   this[0] = TwoLevelWideStringSearch(aMainview);
    //   dword_5EA550 = 0; dword_5EA554 = 0; dword_5EA558 = 0;
    //   dword_5EA500 = 0; dword_5EA504 = 0; dword_5EA508 = 0;
    //   SceneFileLoadByCurrentIndex(this);
    //   ModuleAssetPathResolver(this);
    //   sub_40C520(this);
    //   byte_at(this+0x2D) = 0;
    //   if (!sub_40C140(this))
    //       this[8] = this[24];
    //   return GlobalFlagSetClear(32, 1);
    // UNRESOLVED: Globals dword_8AFE64 and dword_8AFE88 are flagged read-only by packet facts but never appear in the raw decompiled source; possibly read indirectly through the named callees, unverifiable from this packet
}
