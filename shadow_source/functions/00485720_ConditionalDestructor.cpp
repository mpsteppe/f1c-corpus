// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485720
// Canonical corpus name: ConditionalConstructorDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalConstructorDestructor_00485720.c

void UnknownObject::ConditionalDestructor()
{
    // Destructor: writes the object's vtable pointer (off_5A9448) into this+0, conditionally cleans a sub-object at this+224 via ConditionalDualCleanup, chains to the base-class destructor sub_485EB0, then frees self via FreeWrapper_7bcf when flag a2 bit 0 is set. Returns this. Class identity and field layout beyond the vtable are unknown.
    // ASSIGNMENT: Write vtable pointer off_5A9448 into this+0 before any cleanup. [source:raw, field:this:0x00000000, global:0x005A9448, function:0x00485720, abi:lead]
    // CALL: ConditionalDualCleanup on the two-field sub-object embedded at this+224. [source:raw, callee:0x00499B50]
    // CALL: Call base-class destructor sub_485EB0 on this to continue the destruction chain. [source:raw, callee:0x00485EB0]
    // GUARD: Guard: if (a2 & 1) != 0, this object was heap-allocated and must be freed. [source:raw]
    // CALL: FreeWrapper_7bcf(this) deallocates the object when the flag bit is set. [source:raw, callee:0x00587BCF]
    // RETURN: Return this (thiscall convention returns the object address). [source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall ConditionalDestructor(this, char a2) {
    //     *(_DWORD*)this = &off_5A9448;
    //     ConditionalDualCleanup(this + 224);
    //     sub_485EB0(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Owner class identity and the meaning of the off_5A9448 vtable are unknown.
    // UNRESOLVED: Layout of the embedded sub-object at this+224 is only partially known via ConditionalDualCleanup.
    // UNRESOLVED: The a2 flag semantics (in-heap allocator bit vs caller-supplied destroy flag) are not established.
}
