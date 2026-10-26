// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499160
// Canonical corpus name: sub_499160
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_499160_00499160.c

void UnknownObject::UiDestructorWithConditionalFree()
{
    // __thiscall teardown helper: first runs the object's vtable reset and list destruction (ShortComputation_9180 at 0x00499180), then, when the low bit of flag a2 is set, frees the object memory via FreeWrapper_7bcf; returns this. Matches the legacy ABI lead of a UI destructor with conditional free.
    // CALL: Invoke ShortComputation_9180(this) (0x00499180) to reset the vtable pointer and run the object's list destruction. [callee:0x00499180, source:raw]
    // GUARD: Guard on (a2 & 1) != 0; only when the low bit is set does the following free execute. [source:raw]
    // CALL: Conditionally call FreeWrapper_7bcf(this) (0x00587BCF) to release the object memory. [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD *UiDestructorWithConditionalFree(DWORD *this, char a2) {
    //     ShortComputation_9180(this); // vtable reset + list destruction
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Object type owning this destructor is unknown (owner UNKNOWN).
    // UNRESOLVED: Meaning of the a2 flag bit 0 (delete/free ownership) is caller-defined; no callers are recorded in the packet.
}
