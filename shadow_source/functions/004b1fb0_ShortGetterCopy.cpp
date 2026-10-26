// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1FB0
// Canonical corpus name: ShortGetterCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortGetterCopy_004b1fb0.c

void UnknownObject::ShortGetterCopy()
{
    // Trivial 16-bit copy wrapper: reads the short at this+0x16, writes it to this+0x14, and returns the copied short value. No branches, guards, globals, or callees. The canonical/abi name (Short_getter_copy, LEGACY) describes a getter that snapshots a short field into a second short field while returning the value.
    // ASSIGNMENT: Read the source short from this+0x16 (this[11]) into the local result. [field:this:0x00000016, source:raw]
    // ASSIGNMENT: Store the result short into this+0x14 (this[10]), overwriting the previous value. [field:this:0x00000014, source:raw]
    // RETURN: Return the copied short value read from this+0x16. [source:raw]

    // Conservative worker pseudocode:
    //   short result = *(short*)((char*)this + 0x16);
    //   *(short*)((char*)this + 0x14) = result;
    //   return result;
    // UNRESOLVED: The owning class is unknown; this+0x14 and this+0x16 are unnamed short fields whose semantic meaning is not grounded by any packet evidence.
    // UNRESOLVED: The getter/copy intent is carried only by the canonical/abi name (LEGACY trust); no callers are recorded in the packet.
}
