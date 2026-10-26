// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589D7D
// Canonical corpus name: UtilityFunction_9d7d
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_9d7d_00589d7d.c

void UnknownObject::callAllNonNullCallbacks()
{
    // Iterator that walks a contiguous array of void function pointers starting at a1 and invokes every non-null entry, stopping when the pointer address reaches the limit a2. Calls all non-null callbacks; called by sub_589C77 and sub_589CC6.
    // LOOP: Iterate function-pointer slots from a1 while (unsigned int)a1 < a2. [source:raw]
    // GUARD: Invoke the current entry only when *a1 is non-null. [source:raw]
    // CALL: Indirect call through the current function pointer: (*a1)(). [source:raw]
    // CALCULATION: Advance a1 by one function-pointer slot each iteration. [source:raw]

    // Conservative worker pseudocode:
    //   while ((unsigned int)a1 < a2) {
    //       if (*a1) (*a1)();
    //       ++a1;
    //   }
    // UNRESOLVED: a2 is typed unsigned int but is compared against the pointer address cast to unsigned int, so it acts as the end address of the callback array, not a count.
    // UNRESOLVED: field:this:0x00000000 is a spurious template-generated field; the raw source is a __cdecl helper with two pointer/int parameters and no `this`.
}
