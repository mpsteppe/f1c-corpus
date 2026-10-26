// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587230
// Canonical corpus name: CounterIncrementDecrementByFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CounterIncrementDecrementByFlag_00587230.c

void UnknownObject::adjustByteCounterByFlag()
{
    // Adjusts a byte counter at this[25] (byte offset 0x19): reads the current value, then increments when the flag a2 is non-zero, or decrements when a2 is zero and the current value is non-zero (a zero counter is never decremented below zero). Returns the pre-modification value.
    // ASSIGNMENT: Read the current byte counter value from this[25] (byte offset 0x19) into result [field:this:0x00000019, source:raw]
    // GUARD: When a2 is non-zero, take the increment path [source:raw]
    // ASSIGNMENT: Store the incremented value (result+1) back to this[25] (byte offset 0x19) [field:this:0x00000019, source:raw]
    // GUARD: Else, when the current counter is non-zero, take the decrement path [source:raw]
    // ASSIGNMENT: Store the decremented value (result-1) back to this[25] (byte offset 0x19) [field:this:0x00000019, source:raw]
    // RETURN: Return the counter value as it was before any modification [source:raw]
    // CALL: Invoked by MutexCallbackDispatch (0057E3A0), sub_580DE0, NetworkFileTransferAcceptHandler (0058119A), sub_5813E0, NetworkBufferSearch (00581600), and sub_585870 [caller:0x0057E3A0, caller:0x00580DE0, caller:0x0058119A, caller:0x005813E0, caller:0x00581600, caller:0x00585870]

    // Conservative worker pseudocode:
    //   result = this[25];
    //   if (a2) {
    //     this[25] = result + 1;
    //   } else if (result) {
    //     this[25] = result - 1;
    //   }
    //   return result;
    // UNRESOLVED: No upper-bound guard exists on the increment path; a counter at 255 would wrap on increment
    // UNRESOLVED: The owner object is unknown; the counter's role (only reachable from mutex/network callers here) is not established
    // UNRESOLVED: Decrement is skipped at zero, so the counter cannot go negative, but whether it represents a reference count or retry count is unverified
}
