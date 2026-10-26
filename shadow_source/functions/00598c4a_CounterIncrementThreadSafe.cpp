// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598C4A
// Canonical corpus name: CounterIncrementThreadSafe
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CounterIncrementThreadSafe_00598c4a.c

void UnknownObject::CounterIncrementThreadSafe()
{
    // Thread-safe increment of a counter field at this+0x4 guarded against a -1 sentinel. Enters a critical section on a local synchronization object, increments the counter unless it holds the -1 sentinel, then leaves the critical section and returns its status. The -1 guard makes the increment conditional on the counter not being in a disabled/closed state.
    // CALL: Enter the critical section: call sub_59A54D on the local 4-byte synchronization object v4 to acquire the lock. [callee:0x0059A54D]
    // GUARD: Read the counter field this[1] (byte offset 0x4, RW); the increment path is taken only when the value is not the -1 sentinel. [field:this:0x00000004]
    // ASSIGNMENT: Increment the counter in place: this[1] = this[1] + 1. [field:this:0x00000004]
    // CALL: Leave the critical section: call sub_59A5E9 on the same local object v4 to release the lock, and use its return value as the function result. [callee:0x0059A5E9]
    // RETURN: Return the status produced by the lock-release call sub_59A5E9. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_598C4A(DWORD *this) {
    //     char v4[4];
    //     sub_59A54D(v4);
    //     int v2 = this[1];
    //     if (v2 != -1)
    //       this[1] = v2 + 1;
    //     return sub_59A5E9(v4);
    //   }
    // UNRESOLVED: What object the -1 sentinel represents (disabled/closed state) is not established here.
    // UNRESOLVED: Whether the counter at this+0x4 is a reference count, sequence number, or other counter is unresolved.
    // UNRESOLVED: The lock helpers sub_59A54D / sub_59A5E9 are not identified beyond being acquire/release of a 4-byte critical-section object.
}
