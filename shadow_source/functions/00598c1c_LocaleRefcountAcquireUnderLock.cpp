// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598C1C
// Canonical corpus name: LocaleRefcountAcquireUnderLock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LocaleRefcountAcquireUnderLock_00598c1c.c

void UnknownObject::LocaleRefcountAcquireUnderLock()
{
    // Stores a locale-facet reference value (obtained from sub_59AAB9) into the caller object's offset 0x0, then under a lock held via sub_59A54D/sub_59A5E9 performs a thread-safe increment of the global reference counter at 0x008D4650. Returns the caller object pointer.
    // ASSIGNMENT: Stores into *this (byte offset 0x0) the locale facet reference returned by sub_59AAB9(). [field:this:0x00000000, callee:0x0059AAB9, source:raw]
    // CALL: Calls sub_59A54D(v3) to acquire the lock/synchronization primitive that guards the reference counter (v3 is a stack BYREF buffer). [callee:0x0059A54D, source:raw]
    // CALL: Calls CounterIncrementThreadSafe(dword_8D4650): thread-safe increment of the global reference counter at 0x008D4650. [callee:0x00598C4A, global:0x008D4650, source:raw]
    // CALL: Calls sub_59A5E9(v3) to release the lock previously acquired with sub_59A54D. [callee:0x0059A5E9, source:raw]
    // RETURN: Returns this (the caller-provided object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   this[0] = sub_59AAB9();
    //   lock = sub_59A54D(buffer);
    //   CounterIncrementThreadSafe(dword_8D4650);
    //   sub_59A5E9(buffer);
    //   return this;
    // UNRESOLVED: sub_59A54D / sub_59A5E9 are interpreted as lock acquire/release based on the existing analysis fill; the raw source itself provides no symbol names.
    // UNRESOLVED: The exact class owning this constructor-style initializer is not evidenced; the legacy ABI name Locale_Refcount_Acquire_Under_Lock is consistent with the canonical name and was not adopted as a class.
}
