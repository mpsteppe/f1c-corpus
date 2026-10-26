// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406A70
// Canonical corpus name: sub_406A70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_406A70_00406a70.c

void UnknownObject::SlotResourceFree()
{
    // Conditional slot-resource release. Reads the dword at offset 0x5C of this; when it is not -1, passes it to sub_58C331 for release and resets offset 0x5C to -1. Returns the slot value read (or the release function's result). No-op when the slot is already -1.
    // ASSIGNMENT: Reads the slot-resource handle from offset 0x5C of this into result [field:this:0x0000005C, source:raw]
    // GUARD: Proceeds only when the handle at offset 0x5C is not -1; otherwise skips release [field:this:0x0000005C, source:raw]
    // CALL: Releases the resource handle by calling sub_58C331 with the value at offset 0x5C [callee:0x0058C331, source:raw]
    // ASSIGNMENT: Resets offset 0x5C of this to -1 (inactive) after the release [field:this:0x0000005C, source:raw]
    // RETURN: Returns the release function's result, or the previously read slot value when already inactive [function:0x00406A70, source:raw]
    // STATE_TRANSITION: Invoked as a cleanup path by AudioStreamCloseAndCleanup, sub_4069F0 and LinkedListTraversalByID [caller:0x00406750, caller:0x004069F0, caller:0x00408000, source:raw]

    // Conservative worker pseudocode:
    //   result = this[23];
    //   if (result != -1) {
    //     result = sub_58C331(this[23]);
    //     this[23] = -1;
    //   }
    //   return result;
    // UNRESOLVED: sub_58C331's exact release semantics and whether its return value is meaningful to callers are defined outside this packet
    // UNRESOLVED: The -1 sentinel at offset 0x5C marks an inactive slot; the slot index this handle refers to is not recoverable from this packet
}
