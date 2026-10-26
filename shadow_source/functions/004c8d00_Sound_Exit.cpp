// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8D00
// Canonical corpus name: Sound_Exit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Sound_Exit_004c8d00.c

void UnknownObject::Sound_Exit()
{
    // Sound-system exit routine called from GameExit: when a string-split probe succeeds it writes an 'entered sound exit' debug message, then unconditionally dispatches two global vtable calls with query values 1 and 0, computes a short value from pointer-table entry flt_5EA618, resets virtual dispatch state on the sound context pointer, and returns the result of the final arithmetic-comparison helper.
    // GUARD: If StringSplitLoop(2, aDDevF119992002_24, 768) returns non-zero when cast to unsigned byte, run the debug log. [callee:0x004D7A50, global:0x005D3398]
    // CALL: DebugLogWrite(&dword_8AD25C, aEnteredSoundEx): write the 'entered sound exit' message into the debug buffer. [callee:0x004D7AA0, global:0x008AD25C, global:0x005D3424]
    // CALL: GlobalVTableDispatchWithQuery(1): dispatch a global vtable call with query value 1. [callee:0x00411740]
    // CALL: GlobalVTableDispatchWithQuery(0): dispatch a global vtable call with query value 0. [callee:0x00411740]
    // CALL: ShortComputation_8900(flt_5EA618): compute a short value from the pointer-table entry. [callee:0x00418900, global:0x005EA618]
    // CALL: VirtualDispatchStateReset(this): reset virtual dispatch state on the sound context pointer. [callee:0x004C8630]
    // RETURN: Return the result of the arithmetic-comparison helper named ArithmeticComparison_8350 in the raw source, called with no arguments; this callee has no dedicated callee entry in the packet. [source:raw]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(2, aDDevF119992002_24, 768)) DebugLogWrite(&dword_8AD25C, aEnteredSoundEx);
    //   GlobalVTableDispatchWithQuery(1);
    //   GlobalVTableDispatchWithQuery(0);
    //   ShortComputation_8900(flt_5EA618);
    //   VirtualDispatchStateReset(this);
    //   return ArithmeticComparison_8350();
    // UNRESOLVED: Purpose and meaning of the StringSplitLoop(2, ..., 768) probe and the aDDevF119992002_24 string.
    // UNRESOLVED: Semantics of the GlobalVTableDispatchWithQuery query values 1 and 0.
    // UNRESOLVED: What ShortComputation_8900 derives from flt_5EA618.
    // UNRESOLVED: Identity of the ArithmeticComparison_8350 callee, which is called and returned but absent from the packet callee table.
}
