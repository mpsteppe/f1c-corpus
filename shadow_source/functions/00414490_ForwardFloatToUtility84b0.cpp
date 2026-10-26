// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414490
// Canonical corpus name: SingleFunctionCallWrapper_4490
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_4490_00414490.c

void UnknownObject::ForwardFloatToUtility84b0()
{
    // Forwarding wrapper: reads float global flt_5EA618 and passes it to UtilityFunction_84b0, returning UtilityFunction_84b0's int result unchanged.
    // CALL: Call UtilityFunction_84b0 with the value of float global flt_5EA618 as its only argument. [source:raw, global:0x005EA618, abi:lead]
    // RETURN: Return the int result produced by UtilityFunction_84b0. [source:raw]

    // Conservative worker pseudocode:
    //   int SingleFunctionCallWrapper_4490(void) {
    //     return UtilityFunction_84b0(flt_5EA618);
    //   }
    // UNRESOLVED: UtilityFunction_84b0 is not listed in the packet callees, so its exact behavior is unknown here.
    // UNRESOLVED: Meaning of float global flt_5EA618 and who writes it are unknown.
}
