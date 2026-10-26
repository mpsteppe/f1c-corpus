// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5C80
// Canonical corpus name: sub_4C5C80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C5C80_004c5c80.c

void UnknownObject::SceneFilterPropertyInit()
{
    // Initializes a filter-property structure: stores the scene index a2 at offset 0x0, resets the order-position field at offset 0x4 to 0, initializes the slot/sort-key field at offset 0x8 to -1 (all-ones), copies the filter name string a3 through StringCopyWithBufferRealloc, then calls SceneOrderSlotFinder(this) to resolve the scene's slot. Returns this.
    // ASSIGNMENT: this[1] (byte offset 0x4) = 0: resets the order-position / filter-state field to its default. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: this[2] (byte offset 0x8) = -1: initializes the slot/sort-key field to all-ones (packet init_literal 18446744073709551615). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: this[0] = a2: stores the caller-provided scene index/identifier at offset 0x0. [field:this:0x00000000, source:raw]
    // CALL: Calls StringCopyWithBufferRealloc(a3) to copy the filter name string (a3) into a persistent buffer. [callee:0x00566650, source:raw]
    // CALL: Calls SceneOrderSlotFinder(this) to look up the scene's position in the SceneOrder list; on a match the slot field is updated. [callee:0x004C5CB0, source:raw]
    // RETURN: Returns this (the initialized structure pointer). [source:raw]

    // Conservative worker pseudocode:
    //   this[1] = 0;
    //   this[2] = -1;
    //   this[0] = a2;
    //   StringCopyWithBufferRealloc(a3);
    //   SceneOrderSlotFinder(this);
    //   return this;
    // UNRESOLVED: The legacy ABI name 'String_Path_Registration' (abi:lead) is inconsistent with the raw source, which initializes a filter-property structure (scene index, order position, slot) and performs a scene-order lookup; the proposed name follows the existing analysis fill.
    // UNRESOLVED: Whether offset 0x8 is a signed slot index (-1 sentinel) or an unsigned all-ones value (18446744073709551615) is not resolved by the packet; both spellings come from the raw source / field literal.
}
