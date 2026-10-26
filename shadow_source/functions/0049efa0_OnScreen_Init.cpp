// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049EFA0
// Canonical corpus name: OnScreen_Init
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OnScreen_Init_0049efa0.c

void UnknownObject::OnScreen_Init()
{
    // On-screen UI subsystem initializer invoked from Game_Init (0042D6B0). It runs an assertion-style string check that gates a debug log write, initializes the race-session descriptor with constants against the passed object, conditionally sets up the cockpit dashboard LED gauge when the vehicle count (dword_5C329C) is positive, dispatches a double-delegate on the resource manager, and tail-calls a sub-initializer sub_49B0A0 whose value it returns.
    // GUARD: Assertion gate: only proceed to the debug log when StringSplitLoop(2, aDDevF119992002_16, 2616) returns non-zero; the string is a __FILE__-style source-path literal used as an assertion tag [global:0x005CCF10, callee:0x004D7A50, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aEnteredOnscree_1) emits the entered-on-screen message when the assertion check passes [global:0x008AD25C, global:0x005CCF54, callee:0x004D7AA0]
    // CALL: RaceInitWithConstants(&dword_8AD298, this) seeds the race-session descriptor at 0x008AD298 with this object's data and constant defaults [global:0x008AD298, callee:0x004D8220]
    // GUARD: Conditional: when dword_5C329C (vehicle count) is greater than 0, the cockpit LED gauge setup runs [global:0x005C329C, source:raw]
    // CALL: CockpitDashboardLEDGaugeSetup(&dword_7CE058) initializes the cockpit LED gauge UI singleton, only when vehicles exist [global:0x007CE058, callee:0x0049CA00]
    // CALL: DoubleDelegateCall_bbe0(&dword_7CD204) dispatches the pending resource delegate [global:0x007CD204, callee:0x0045BBE0]
    // RETURN: Return sub_49B0A0(); the on-screen sub-initializer result becomes this function's value, called by Game_Init (0042D6B0) [callee:0x0049B0A0, caller:0x0042D6B0, function:0x0049EFA0]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(2, aDDevF119992002_16, 2616) != 0)
    //       DebugLogWrite(&dword_8AD25C, aEnteredOnscree_1);
    //   RaceInitWithConstants(&dword_8AD298, this);
    //   if (dword_5C329C > 0)
    //       CockpitDashboardLEDGaugeSetup(&dword_7CE058);
    //   DoubleDelegateCall_bbe0(&dword_7CD204);
    //   return sub_49B0A0();
    // UNRESOLVED: Meaning of the 2616 argument and the source-path literal aDDevF119992002_16 used by the assertion check is not documented
    // UNRESOLVED: Relationship between this function's object and the race descriptor at 0x008AD298 is unverified
    // UNRESOLVED: What double-delegate 0x007CD204 holds and what sub_49B0A0 further initializes is outside this packet's evidence
}
