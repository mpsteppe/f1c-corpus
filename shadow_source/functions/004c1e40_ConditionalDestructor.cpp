// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C1E40
// Canonical corpus name: UtilityFunction_1e40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_1e40_004c1e40.c

void UnknownObject::ConditionalDestructor()
{
    // Conditional destruction of a two-pointer object and optionally the object itself. Frees the child pointer this[2] (this+0x8) when non-zero, frees the child pointer this[0] (this+0x0) when non-zero, and when bit 0 of the flag a2 is set frees the receiver this as well. Returns this. Structural twin of ConditionalDestructor_46f0 per the prelabel cluster copy; called by DoubleListCleanup (004C1700).
    // GUARD: If the child pointer this[2] (this+0x8) is non-zero. [field:this:0x00000008, source:raw]
    // CALL: Free the child pointer this[2] (this+0x8) via FreeWrapper_7bcf (00587BCF). [field:this:0x00000008, callee:0x00587BCF, source:raw]
    // GUARD: If the child pointer *this (this+0x0) is non-zero. [field:this:0x00000000, source:raw]
    // CALL: Free the child pointer *this (this+0x0) via FreeWrapper_7bcf (00587BCF). [field:this:0x00000000, callee:0x00587BCF, source:raw]
    // GUARD: If bit 0 of the flag a2 is set, i.e. (a2 & 1) != 0. [source:raw]
    // CALL: Free the receiver this itself via FreeWrapper_7bcf (00587BCF). [callee:0x00587BCF, source:raw]
    // RETURN: Return the receiver pointer this. [source:raw]
    // CALL: Invoked by DoubleListCleanup (004C1700) to release the two child pointers and, when flagged, the owning object. [caller:0x004C1700, source:raw]

    // Conservative worker pseudocode:
    //   void* ConditionalDestructor(void** this, char a2) {
    //     if (this[2]) FreeWrapper_7bcf(this[2]);
    //     if (this[0]) FreeWrapper_7bcf(this[0]);
    //     if ((a2 & 1) != 0) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: FreeWrapper_7bcf (00587BCF) semantics (free vs delete) are not defined in this packet.
    // UNRESOLVED: The returned this pointer after an optional self-free is unused here; the caller DoubleListCleanup (004C1700) behavior is outside this packet.
    // UNRESOLVED: Why the object keeps two child pointers at this+0x0 and this+0x8 (double-list nodes per the caller name) is inferred, not grounded.
}
