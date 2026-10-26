// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498D70
// Canonical corpus name: FAILWRONGTRIAGE_8d70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILWRONGTRIAGE_8d70_00498d70.c

void UnknownObject::DestroyDualListAndFreeIfFlagged()
{
    // Destroys a dual linked list on 'this' via DualListDestruction, then conditionally frees the object's memory through FreeWrapper_7bcf when bit 0 of the flag argument a2 is set. Returns the original 'this' pointer.
    // CALL: DualListDestruction(this) unconditionally tears down the dual list owned by this [callee:0x00498D90, source:raw]
    // GUARD: Only take the free path when bit 0 of a2 is set: (a2 & 1) != 0 [source:raw]
    // CALL: FreeWrapper_7bcf(this) releases the object memory when the flag bit 0 is set, after list destruction [callee:0x00587BCF, source:raw]
    // RETURN: Return the original this pointer unchanged [function:0x00498D70, source:raw]

    // Conservative worker pseudocode:
    //   DualListDestruction(this);
    //   if ((a2 & 1) != 0)
    //     FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: Only bit 0 of a2 is consumed; the meaning of the other flag bits is unknown
    // UNRESOLVED: DualListDestruction frees the internal list nodes; whether the outer 'this' allocation is separately owned and always caller-managed is not evidenced here
}
