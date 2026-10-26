// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00435240
// Canonical corpus name: StateFlagCheck_5240
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateFlagCheck_5240_00435240.c

void UnknownObject::StateFlagCheckNegated()
{
    // Parameterless boolean helper: calls StateFlagCheck(flt_5EA618) and returns the logical negation of its result. Reads the float-typed global flt_5EA618 (read-only) and feeds it as the flag-check argument. No locals, fields, guards or extra callees.
    // CALL: Read global flt_5EA618 and pass it as the argument to StateFlagCheck. [global:0x005EA618, callee:0x00418940, source:raw]
    // CALCULATION: Negate the StateFlagCheck result: BOOL result = !StateFlagCheck(...). [source:raw]
    // RETURN: Return the negated boolean. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_435240()
    //   {
    //     return !StateFlagCheck(flt_5EA618);
    //   }
    // UNRESOLVED: flt_5EA618 is float-typed in the IDB but is consumed as a StateFlagCheck argument; its role is unknown.
    // UNRESOLVED: Semantics of StateFlagCheck (0x00418940) and why the caller CarSelectionStateMachine (00434460) wants the inverted result are not established.
    // UNRESOLVED: abi name StateFlagCheck (LEGACY) and function identity 0x00435240 contribute no additional semantics.
}
