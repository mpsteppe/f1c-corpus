// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D0E20
// Canonical corpus name: StewardLightGlowNodeFinder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StewardLightGlowNodeFinder_004d0e20.c

void UnknownObject::FindLightAndGlowNodes()
{
    // Resolves two scene node handles for the steward light/glow setup: evaluates scene node property index 0 for node identifier a2 and stores the handle at this+4 (line node), then for node identifier a3 storing at this+8 (glow node). If a resolved handle is zero, a scene-path split loop with an error code is attempted and, when it succeeds, a "could not find line/glow" message is written to the debug log buffer dword_8AD25C. Returns the glow node handle (zero when not found).
    // ASSIGNMENT: Evaluate scene node property index 0 of the line node identifier a2 via EvaluateSceneNodeProperty and store the resulting handle in this+4. [callee:0x005453A0, field:this:0x00000004, caller:0x004D38F0]
    // GUARD: When the line node handle is zero and StringSplitLoop(1, aDDevF119992002_3, 642) succeeds, write the 'could not find line' message (aCouldNotFindLi) to the debug log via DebugLogWrite using buffer dword_8AD25C. [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3B6C, global:0x005D3BB0, global:0x008AD25C]
    // ASSIGNMENT: Evaluate scene node property index 0 of the glow node identifier a3 via EvaluateSceneNodeProperty and store the resulting handle in this+8. [callee:0x005453A0, field:this:0x00000008]
    // GUARD: When the glow node handle is zero, run StringSplitLoop(1, aDDevF119992002_3, 645); on success write the 'could not find glow' message (aCouldNotFindGl) to the debug log via DebugLogWrite using buffer dword_8AD25C and return that result. [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3B6C, global:0x005D3B94, global:0x008AD25C]
    // RETURN: Return the glow node handle (zero when the glow node could not be resolved). [function:0x004D0E20]

    // Conservative worker pseudocode:
    //   line = EvaluateSceneNodeProperty(a2, 0);
    //   this[1] = line;
    //   if (!line && StringSplitLoop(1, aDDevF119992002_3, 642))
    //       DebugLogWrite(&dword_8AD25C, aCouldNotFindLi);
    //   glow = EvaluateSceneNodeProperty(a3, 0);
    //   this[2] = glow;
    //   if (!glow) {
    //       r = StringSplitLoop(1, aDDevF119992002_3, 645);
    //       if (r) return DebugLogWrite(&dword_8AD25C, aCouldNotFindGl);
    //   }
    //   return glow;
    // UNRESOLVED: Exact meaning of the node identifiers a2/a3 and the property index 0 passed to EvaluateSceneNodeProperty is not established.
    // UNRESOLVED: The scene-path format string aDDevF119992002_3 content and the split codes 642/645 are unknown.
    // UNRESOLVED: The steward owner object layout (this+4, this+8) is not confirmed.
}
