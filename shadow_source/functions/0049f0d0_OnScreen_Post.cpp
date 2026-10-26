// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F0D0
// Canonical corpus name: OnScreen_Post
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OnScreen_Post_0049f0d0.c

void UnknownObject::OnScreen_Post()
{
    // OnScreen post-frame routine called from Game_Post. Runs a guarded assertion log (StringSplitLoop over the source-path string aDDevF119992002_16 with count 2688, writing the EnteredOnScreen message aEnteredOnscree_3 through DebugLogWrite into the dword_8AD25C buffer when it passes), calls the session-mode utility UtilityFunction_8720 on the dword_8AD298 identifier with the object pointer, runs the multi-stage cleanup cycle over the dword_7CE058 UI singleton, then returns the result of StaticArrayCleanup.
    // GUARD: Assertion log gate: if StringSplitLoop(2, aDDevF119992002_16, 2688) is non-zero, write the aEnteredOnscree_3 message through DebugLogWrite into the dword_8AD25C buffer [callee:0x004D7A50, global:0x005CCF10, callee:0x004D7AA0, global:0x008AD25C, global:0x005CCF8C, source:raw]
    // CALL: Call the session-mode utility UtilityFunction_8720(&dword_8AD298, this), passing the identifier and the object pointer [callee:0x004D8720, global:0x008AD298, source:raw]
    // CALL: Run the multi-stage cleanup cycle over the dword_7CE058 UI singleton: MultiStageCleanupWithRepeatedCallCycle(&dword_7CE058) [callee:0x0049D150, global:0x007CE058, source:raw]
    // RETURN: Return the result of StaticArrayCleanup() as the function result [callee:0x0049B1C0, function:0x0049F0D0, source:raw]
    // CALL: Identified as the OnScreen_Post ABI entry invoked by Game_Post as a post-frame callback [caller:0x0042DA30, abi:lead, function:0x0049F0D0]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(2, aDDevF119992002_16, 2688))
    //       DebugLogWrite(&dword_8AD25C, aEnteredOnscree_3);
    //   UtilityFunction_8720(&dword_8AD298, this);
    //   MultiStageCleanupWithRepeatedCallCycle(&dword_7CE058);
    //   return StaticArrayCleanup();
    // UNRESOLVED: The 2688 constant passed to StringSplitLoop is preserved as-is; its meaning (likely a string-length guard) is unknown.
    // UNRESOLVED: The roles of dword_8AD298 (session-mode identifier) and dword_7CE058 (UI singleton) are taken from prior analysis and are not independently established from this packet.
    // UNRESOLVED: The exact relationship of StaticArrayCleanup to this cleanup pass is unknown.
}
