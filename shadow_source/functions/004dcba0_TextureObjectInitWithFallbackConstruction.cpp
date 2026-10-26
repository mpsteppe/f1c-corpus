// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCBA0
// Canonical corpus name: sub_4DCBA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DCBA0_004dcba0.c

void UnknownObject::TextureObjectInitWithFallbackConstruction()
{
    // Thiscall init routine for a texture/rendering object. First runs ResourceCleanup_cd10 to clear prior state. When a3 (creation flag) is set, optionally registers a10 through sub_53CBC0 into a local list, allocates a 96-byte zero-filled child object stored at this[1], forces bit 0 of its field at +68, and attempts D3DTextureCreation(a3, 0, 2052). If any setup branch succeeds it returns 1; otherwise it stores config arguments a2/a7/a8 into this[7]/this[5]/this[6] and computes position alignment via PositionComputationWithAlignment(a4, a5, a6, a9). Unregisters the local list node v15 if it was registered, and runs ResourceCleanup_cd10 again when the success flag v10 is set.
    // ASSIGNMENT: Initialize local flag v10 = 0 and local list anchor v15 = 0 before cleanup. [source:raw]
    // CALL: Call ResourceCleanup_cd10(this) to clear any prior object state. [callee:0x004DCD10, source:raw]
    // GUARD: Guard on a3: the texture/allocation branch only runs when a3 is nonzero. [source:raw]
    // GUARD: Guard on a10: sub_53CBC0(&v15, a10) is only invoked when a10 is nonzero. [callee:0x0053CBC0, source:raw]
    // CALL: Register a10 into the local list anchored at v15 via sub_53CBC0(&v15, a10). [callee:0x0053CBC0, source:raw]
    // CALL: Allocate 96 bytes via OperatorNewNhMallocWrapper(96) and zero-fill the block through StructInitWithZeroFill (returning 0 on allocation failure). [callee:0x00587C03, callee:0x0054FE10, source:raw]
    // ASSIGNMENT: Store the allocated child object pointer into this[1] (offset 0x4) and set bit 0 of its dword at +68. [field:this:0x00000004, source:raw]
    // CALL: Attempt D3DTextureCreation(a3, 0, 2052); on a nonzero result jump to the success label. [callee:0x00550080, source:raw]
    // CALL: Fallback construction ObjectConstructorWithAllocationAndSubInit(this, 2, this[1], 32, 192); if it succeeds set v10 = 1. [callee:0x00553980, source:raw]
    // ASSIGNMENT: When both creation paths fail, store the config parameters: this[5] = a7, this[6] = a8, this[7] = a2 (offsets 0x14, 0x18, 0x1C). [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // CALL: Compute position with alignment parameters via PositionComputationWithAlignment(a4, a5, a6, a9). [callee:0x004DCDD0, source:raw]
    // GUARD: Guard on v15: if the local node was registered, remove it from the physics object linked list via PhysicsObjectLinkedListRemoval(v15). [callee:0x0053CE40, source:raw]
    // GUARD: Guard on v10: when any creation path succeeded, run ResourceCleanup_cd10(this) before returning. [callee:0x004DCD10, source:raw]
    // RETURN: Return v10 (1 on success, 0 on failure). [source:raw]
    // CALL: Called by sub_49B0A0 (0x0049B0A0) and FloatToIntConversionDelegation (0x004DCC90) to initialize the texture/object. [caller:0x0049B0A0, caller:0x004DCC90, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DCBA0(int *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
    //     int v10 = 0;
    //     int v15 = 0;
    //     ResourceCleanup_cd10(this);
    //     if (a3) {
    //       if (a10) sub_53CBC0(&v15, a10);
    //       int p = OperatorNewNhMallocWrapper(96);
    //       p = p ? StructInitWithZeroFill(p) : 0;
    //       this[1] = p;
    //       *(int*)(p + 68) |= 1;
    //       if (D3DTextureCreation(a3, 0, 2052)) goto success;
    //     }
    //     if (ObjectConstructorWithAllocationAndSubInit(this, 2, this[1], 32, 192)) {
    //   success:
    //       v10 = 1;
    //     } else {
    //       this[5] = a7; this[6] = a8; this[7] = a2;
    //       PositionComputationWithAlignment(a4, a5, a6, a9);
    //     }
    //     if (v15) PhysicsObjectLinkedListRemoval(v15);
    //     if (v10) ResourceCleanup_cd10(this);
    //     return v10;
    //   }
    // UNRESOLVED: Owner class of 'this' is unknown; offsets 0x4/0x14/0x18/0x1C are read/written but their concrete field semantics (beyond texture/config storage) are not established.
    // UNRESOLVED: Read of global dword_8AFE64 (0x008AFE64) is listed by the facts but not visible in the raw source text; its role in this call is unclear.
    // UNRESOLVED: Relationship between the allocated 96-byte child (this[1]) and the fallback ObjectConstructorWithAllocationAndSubInit parameters (2, 32, 192) is not fully resolved.
    // UNRESOLVED: Meaning of the return value semantics between the two callers (0x0049B0A0, 0x004DCC90) is not established.
}
