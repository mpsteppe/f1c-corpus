// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A352
// Canonical corpus name: DestructorConditionalFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorConditionalFree_0059a352.c

void UnknownObject::DestructorConditionalFree()
{
    // Compiler-generated destructor helper (this-adjusting, conditional free): computes v3 = a1 - 8, runs VTableFixupDuringConstruction on v3 with a2 and three uninitialized stack slots, then, when flag a3 bit 0 is set, frees v3 via FreeWrapper_7bcf. Returns v3. The a1-8 adjustment and the VTable fixup are characteristic of an MSVC scalar-deleting destructor thunk for a multiply-inherited base, though the owning class is not evidenced here.
    // ASSIGNMENT: Compute the adjusted object pointer: v3 = a1 - 8. [source:raw]
    // CALL: Call VTableFixupDuringConstruction (callee 0x005998A1) with v3, a2, and the uninitialized stack slots v6/v7/v8. [callee:0x005998A1, source:raw]
    // GUARD: Guard on the low bit of the flag: when (a3 & 1) != 0 the object is conditionally freed. [source:raw]
    // CALL: Free the adjusted object v3 via FreeWrapper_7bcf (callee 0x00587BCF) when the flag bit is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return the adjusted object pointer v3. [source:raw]

    // Conservative worker pseudocode:
    //   void *DestructorConditionalFree(int a1, int a2, char a3) {
    //     void *v3 = (void *)(a1 - 8);
    //     VTableFixupDuringConstruction((char *)v3, a2, v6, v7, v8);
    //     if (a3 & 1)
    //       FreeWrapper_7bcf(v3);
    //     return v3;
    //   }
    // UNRESOLVED: The a1-8 adjustment implies a multiply-inherited base-class destructor thunk, but the owning class identity is unknown.
    // UNRESOLVED: Stack slots v6/v7/v8 are read uninitialized (positive-sp warning); their semantics and that of a2 are unknown.
    // UNRESOLVED: VTableFixupDuringConstruction's argument meaning and postcondition are not established by this packet.
    // UNRESOLVED: No callers are listed; the object type and destruction context are unknown.
}
