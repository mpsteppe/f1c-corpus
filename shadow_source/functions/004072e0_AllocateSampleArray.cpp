// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004072E0
// Canonical corpus name: MilesSoundSystemSampleAllocator
// Owner: MilesSoundSystem [DERIVED]
// Raw source: functions/MilesSoundSystemSampleAllocator_004072e0.c

void MilesSoundSystem::AllocateSampleArray()
{
    // Reallocates the Miles sound-system sample array: tears down the existing 20-byte-entry array at this+0x48 (releasing per-entry virtual sub-objects and AIL sample handles, then freeing the array header), stores the new count into this+0x4C, allocates a fresh zero-filled array via OperatorNewNhMallocWrapper, and, for each new entry, allocates and initializes an AIL sample handle when the driver handle at this+0x90 is set.
    // GUARD: Guard: only tear down the existing sample array when this[0x48] (array pointer) is non-null. [field:this:0x00000048, function:0x004072E0, source:raw]
    // LOOP: Loop while the entry count this[0x4C] > 0 (guard), stepping 20 bytes per entry, to tear down each entry of the existing array. [field:this:0x0000004C, guard:0, source:raw]
    // CALL: For each entry holding a live sub-object (vtable pointer non-null), invoke its virtual release routine via vtable slot +8 (indirect call, no named packet callee). [source:raw, field:this:0x00000048]
    // CALL: Call AIL_release_sample_handle (global 0x0059E3F0) on each entry's sample handle at entry+16 and clear that handle slot. [global:0x0059E3F0, field:this:0x00000048, source:raw]
    // CALL: Free the array header memory by calling FreeWrapper_7bcf (callee 0x00587BCF) on this[0x48]-4. [callee:0x00587BCF, field:this:0x00000048, source:raw]
    // ASSIGNMENT: Null this[0x48] after teardown, then store the new count a2 into this[0x4C]. [field:this:0x00000048, field:this:0x0000004C, source:raw]
    // CALL: If a2 > 0, allocate 20*a2+4 bytes via OperatorNewNhMallocWrapper (callee 0x00587C03), storing a2 in the allocation header and zero-filling every 20-byte entry. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the new array pointer into this[0x48], or 0 when allocation fails. [field:this:0x00000048, source:raw]
    // CALL: When the allocation succeeded and the driver handle this[0x90] is set, allocate an AIL sample handle via AIL_allocate_sample_handle (global 0x0059E3EC) into each entry+16. [field:this:0x00000090, global:0x0059E3EC, source:raw]
    // CALL: Initialize each newly allocated sample handle via AIL_init_sample (global 0x0059E3DC). [global:0x0059E3DC, source:raw]

    // Conservative worker pseudocode:
    //   if (this[0x48] != 0) {
    //     for (i = 0; i < this[0x4C]; ++i) {
    //       entry = this[0x48] + i*20;
    //       if (*(entry)) (*vtable+8)(*(entry));
    //       if (*(entry+16)) { AIL_release_sample_handle(*(entry+16)); *(entry+16) = 0; }
    //     }
    //     FreeWrapper_7bcf(this[0x48]-4);
    //     this[0x48] = 0;
    //   }
    //   this[0x4C] = a2;
    //   if (a2 > 0) {
    //     p = OperatorNewNhMallocWrapper(20*a2+4);
    //     this[0x48] = p ? p+1 : 0;
    //     zero-fill a2 20-byte entries;
    //     if (this[0x48]) for each entry: if (this[0x90]) { entry+16 = AIL_allocate_sample_handle(this[0x90]); AIL_init_sample(entry+16); }
    //   }
    // UNRESOLVED: Raw source is elided after AIL_allocate_sample_handle; AIL_init_sample on each handle is confirmed by existing analysis but the exact call ordering after the elision is not fully visible.
    // UNRESOLVED: The per-entry virtual release via vtable slot +8 has no named packet callee; the released sub-object type is unknown.
    // UNRESOLVED: Field offsets 0x48, 0x4C, 0x90 are read/written only within this function in the packet; their owning class is inferred from the ABI lead, not independently proven.
    // UNRESOLVED: Caller GenericObjectConstructorWithVTable (0x00406AB0) instantiates the owner, but no constructor/field evidence beyond the call site is present.
}
