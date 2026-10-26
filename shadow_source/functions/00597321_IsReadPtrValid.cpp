// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597321
// Canonical corpus name: IsBadReadPtrWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IsBadReadPtrWrapper_00597321.c

void UnknownObject::IsReadPtrValid()
{
    // Wraps the imported IsBadReadPtr check: returns the logical negation of IsBadReadPtr(lp, ucb), i.e. true when the given range is readable. The ABI lead labels this function IsBadReadPtr_Wrapper.
    // CALL: Invoke the imported IsBadReadPtr global (0x59E080) with the two parameters (lp, ucb) passed to this function. [global:0x0059E080, function:0x00597321, source:raw]
    // CALCULATION: Negate the IsBadReadPtr result so a readable range yields a non-zero BOOL. [source:raw, abi:lead]
    // RETURN: Return the negated readability result. [function:0x00597321, source:raw]

    // Conservative worker pseudocode:
    //   BOOL IsReadPtrValid(void *lp, UINT_PTR ucb) {
    //       return !IsBadReadPtr(lp, ucb);
    //   }
    // UNRESOLVED: The subsystem that consumes this readability gate is unknown; callers sub_5934E1 and sub_5939F9 are the only linking evidence.
    // UNRESOLVED: IsBadReadPtr is referenced as an imported global rather than a resolved callee, so the exact import mechanism is unresolved.
}
