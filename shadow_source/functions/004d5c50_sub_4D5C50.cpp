// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D5C50
// Canonical corpus name: sub_4D5C50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D5C50_004d5c50.c

void UnknownObject::sub_4D5C50()
{
    // Single-thunk helper: reads the GlobalQueryWrapper value and passes it cast to int into BooleanToIntConversion at 0x00587B3E, returning the conversion result directly.
    // CALL: Call BooleanToIntConversion at 0x00587B3E with GlobalQueryWrapper (read from 0x004D5C60) cast to int. [callee:0x00587B3E, global:0x004D5C60, source:raw]
    // RETURN: Return the conversion result produced by the call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D5C50() {
    //     return BooleanToIntConversion((int)GlobalQueryWrapper);
    //   }
    // UNRESOLVED: What GlobalQueryWrapper at 0x004D5C60 represents (a boolean flag or a query wrapper address) is unestablished.
    // UNRESOLVED: Semantics of BooleanToIntConversion and why a global is queried through it are unknown here.
}
