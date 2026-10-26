// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7FA0
// Canonical corpus name: SwitchBasedGlobalLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwitchBasedGlobalLookup_004d7fa0.c

void UnknownObject::SwitchBasedGlobalLookup()
{
    // Selector-to-global lookup compiled as a switch over the integer argument a1 and dispatched through a jump table at 0x004D7FD0: case 1 returns dword_8AD38C, case 2 returns dword_8AD390, case 3 returns dword_8AD394, and the default returns dword_8AD388. Called by UI text/rendering helpers UITextRenderWithScale (004d7e40), CenteredPosition (004d7f20), SizeComputationWithSubtraction (004d7f60) and DrawYellowTextAtFixedScreenPosition (004dc250) to select a render/resource context.
    // CALCULATION: Selector switch on integer argument a1, compiled to a jump table at 0x004D7FD0 [global:0x004D7FD0, source:raw]
    // RETURN: Case 1 returns the global dword_8AD38C [global:0x008AD38C, source:raw]
    // RETURN: Case 2 returns the global dword_8AD390 [global:0x008AD390, source:raw]
    // RETURN: Case 3 returns the global dword_8AD394 [global:0x008AD394, source:raw]
    // RETURN: Default case returns the global dword_8AD388 as the fallback selection [global:0x008AD388, source:raw]
    // CALL: Called by UITextRenderWithScale (004d7e40), CenteredPosition (004d7f20), SizeComputationWithSubtraction (004d7f60) and DrawYellowTextAtFixedScreenPosition (004dc250) to select a render context [caller:0x004D7E40, caller:0x004D7F20, caller:0x004D7F60, caller:0x004DC250, source:raw]

    // Conservative worker pseudocode:
    //   switch (a1) {
    //     case 1: return dword_8AD38C;
    //     case 2: return dword_8AD390;
    //     case 3: return dword_8AD394;
    //     default: return dword_8AD388;
    //   }
    // UNRESOLVED: The four returned dwords are contiguous at 0x008AD388..0x008AD394; the skeleton fill labels them resource/context handles used by UI text rendering, unverifiable from this packet
    // UNRESOLVED: The global jpt_4D7FA9 at 0x004D7FD0 is the compiler-emitted jump table for the switch; it is read only implicitly by the dispatch, never named in the raw source text
}
