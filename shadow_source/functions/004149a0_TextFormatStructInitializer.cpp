// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004149A0
// Canonical corpus name: TextFormatStructInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextFormatStructInitializer_004149a0.c

void UnknownObject::TextFormatStructInitializer()
{
    // this-call initializer for a text-format record. Across eight slot groups at offsets 0x8..0x98 it resets each slot to the inactive state (DWORD -1, DWORD -1, BYTE 0), interleaving every group with a call to StringCopyWithBufferRealloc(&byte_5EA438) that reinitializes the global path-string buffer. The raw source also shows a ninth trailing slot group beyond the last field-table entry (via this += 156), with the final StringCopyWithBufferRealloc return value passed through. Called during format-list entry setup/teardown and driver resource cleanup.
    // CALL: Reinitialize the global path-string buffer via StringCopyWithBufferRealloc(&byte_5EA438) before the first slot group. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 0: set this+0x8 to -1. [field:this:0x00000008]
    // ASSIGNMENT: Slot 0: set this+0xC to -1. [field:this:0x0000000C]
    // ASSIGNMENT: Slot 0: clear this+0x10 (active/flag byte) to 0. [field:this:0x00000010]
    // CALL: Reinitialize the global path-string buffer via StringCopyWithBufferRealloc(&byte_5EA438) before slot 1. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 1: set this+0x18 to -1. [field:this:0x00000018]
    // ASSIGNMENT: Slot 1: set this+0x1C to -1. [field:this:0x0000001C]
    // ASSIGNMENT: Slot 1: clear this+0x20 (active/flag byte) to 0. [field:this:0x00000020]
    // CALL: Reinitialize the global path-string buffer via StringCopyWithBufferRealloc(&byte_5EA438) before slot 2. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 2: set this+0x2C to -1. [field:this:0x0000002C]
    // ASSIGNMENT: Slot 2: set this+0x30 to -1. [field:this:0x00000030]
    // ASSIGNMENT: Slot 2: clear this+0x34 (active/flag byte) to 0. [field:this:0x00000034]
    // CALL: Reinitialize the global path-string buffer via StringCopyWithBufferRealloc(&byte_5EA438) before slot 3. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 3: set this+0x40 to -1. [field:this:0x00000040]
    // ASSIGNMENT: Slot 3: set this+0x44 to -1. [field:this:0x00000044]
    // ASSIGNMENT: Slot 3: clear this+0x48 (active/flag byte) to 0. [field:this:0x00000048]
    // CALL: Reinitialize the global path-string buffer via StringCopyWithBufferRealloc(&byte_5EA438) before slot 4. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 4: set this+0x54 to -1. [field:this:0x00000054]
    // ASSIGNMENT: Slot 4: set this+0x58 to -1. [field:this:0x00000058]
    // ASSIGNMENT: Slot 4: clear this+0x5C (active/flag byte) to 0. [field:this:0x0000005C]
    // CALL: Reinitialize the global path-string buffer via StringCopyWithBufferRealloc(&byte_5EA438) before slot 5. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 5: set this+0x68 to -1. [field:this:0x00000068]
    // ASSIGNMENT: Slot 5: set this+0x6C to -1. [field:this:0x0000006C]
    // ASSIGNMENT: Slot 5: clear this+0x70 (active/flag byte) to 0. [field:this:0x00000070]
    // CALL: Reinitialize the global path-string buffer via StringCopyWithBufferRealloc(&byte_5EA438) before slot 6. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 6: set this+0x7C to -1. [field:this:0x0000007C]
    // ASSIGNMENT: Slot 6: set this+0x80 to -1. [field:this:0x00000080]
    // ASSIGNMENT: Slot 6: clear this+0x84 (active/flag byte) to 0. [field:this:0x00000084]
    // CALL: Reinitialize the global path-string buffer via StringCopyWithBufferRealloc(&byte_5EA438) before slot 7. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 7: set this+0x90 to -1. [field:this:0x00000090]
    // ASSIGNMENT: Slot 7: set this+0x94 to -1. [field:this:0x00000094]
    // ASSIGNMENT: Slot 7: clear this+0x98 (active/flag byte) to 0. [field:this:0x00000098]
    // CALL: Advance this by 156 bytes and reinitialize the global path-string buffer once more for the trailing slot group. [callee:0x00566650, global:0x005EA438, source:raw]
    // RETURN: Return the result of the final StringCopyWithBufferRealloc call. [function:0x004149A0, abi:lead]
    // CALL: Invoked as a text-format block initializer from GlobalListTripleCleanupWithTimerRemoval, sub_414600, DrawableResourceCleanup, NamedEntryLookupInFormatList, VehicleListBuilderFromGlobalArray and StructDestructor. [caller:0x00414210, caller:0x00414600, caller:0x004150C0, caller:0x00415230, caller:0x00415780, caller:0x00415900]

    // Conservative worker pseudocode:
    //   int TextFormatStructInitializer(char *this) {
    //     reset_slot(this, 8);   StringCopyWithBufferRealloc(&byte_5EA438);
    //     reset_slot(this, 0x18); StringCopyWithBufferRealloc(&byte_5EA438);
    //     reset_slot(this, 0x2C); StringCopyWithBufferRealloc(&byte_5EA438);
    //     reset_slot(this, 0x40); StringCopyWithBufferRealloc(&byte_5EA438);
    //     reset_slot(this, 0x54); StringCopyWithBufferRealloc(&byte_5EA438);
    //     reset_slot(this, 0x68); StringCopyWithBufferRealloc(&byte_5EA438);
    //     reset_slot(this, 0x7C); StringCopyWithBufferRealloc(&byte_5EA438);
    //     reset_slot(this, 0x90); StringCopyWithBufferRealloc(&byte_5EA438);
    //     reset_slot(this + 156, 8);
    //     return StringCopyWithBufferRealloc(&byte_5EA438);
    //     // reset_slot(o, n): *(DWORD*)(o+n) = -1; *(DWORD*)(o+n+4) = -1; *(BYTE*)(o+n+8) = 0;
    //   }
    // UNRESOLVED: Raw source for slot 0 writes a single BYTE 0 at this+12, while the deterministic field table records this+0xC with init literal -1; the two packet sources disagree for slot 0.
    // UNRESOLVED: Raw source shows a trailing ninth slot group after the last field-table entry (this advanced by 156, then offsets relative to the new base); no field evidence refs cover it, so its offsets are not named here.
    // UNRESOLVED: The exact meaning of each slot (x/y coordinates, active flag) is inferred from the -1/-1/0 reset pattern, not stated in the packet.
    // UNRESOLVED: The previous contents of global byte_5EA438 are not shown; it is reinitialized at every slot boundary.
}
