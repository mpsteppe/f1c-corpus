// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004881B0
// Canonical corpus name: DualCleanupWithConditionalFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualCleanupWithConditionalFree_004881b0.c

void UnknownObject::DualCleanupWithConditionalFree()
{
    // thiscall teardown. Runs two cleanup passes on the object: ConditionalDualCleanup on a sub-object at this+224, then sub_485EB0 on the object itself. When the low bit of flag a2 is set, the object is freed through FreeWrapper_7bcf. Returns this.
    // CALL: Call ConditionalDualCleanup((_DWORD *)(this + 224)) to clean a sub-object located at offset 224 of this. [callee:0x00499B50, source:raw]
    // CALL: Call sub_485EB0((LPVOID *)this) as the second cleanup pass on the object itself. [callee:0x00485EB0, source:raw]
    // GUARD: Guard on (a2 & 1) != 0; the object is freed only when the low bit of a2 is set. [source:raw]
    // CALL: Call FreeWrapper_7bcf((LPVOID)this) to release the object memory. [callee:0x00587BCF, source:raw]
    // RETURN: Return this (the object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   int DualCleanupWithConditionalFree(int this, char flags) {
    //     ConditionalDualCleanup((_DWORD*)(this + 224));
    //     sub_485EB0((LPVOID*)this);
    //     if ((flags & 1) != 0) FreeWrapper_7bcf((LPVOID)this);
    //     return this;
    //   }
    // UNRESOLVED: Identity of sub_485EB0 and of the sub-object at this+224 are unknown; no fields are packet-evidenced.
    // UNRESOLVED: Caller of the teardown and meaning of the a2 bits other than the low bit are unresolved.
}
