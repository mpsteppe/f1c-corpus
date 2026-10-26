// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005831B0
// Canonical corpus name: PlacementDeleteDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlacementDeleteDispatcher_005831b0.c

void UnknownObject::PlacementDeleteDispatcher()
{
    // Destruction dispatcher keyed on flag bits of a2. When bit 2 is set, the object is treated as a placement-allocated block with a count header at this-1: it runs NTimeCallbackLoopWithSEH over all entries with element size 308 using the SingleVTablePointerSet callback, then optionally frees from the header pointer when bit 1 is set, returning this-1. When bit 2 is clear, it calls SingleVTablePointerSet directly on this, optionally frees this when bit 1 is set, and returns this.
    // GUARD: If flag bit 2 of a2 is set, handle the placement-allocated path [source:raw, function:0x005831B0]
    // CALL: Run NTimeCallbackLoopWithSEH(this, 308, *(this - 1), SingleVTablePointerSet): invoke the SingleVTablePointerSet callback over all entries of the block whose entry size is 308 and whose entry count is read from the header at this - 1 [source:raw, callee:0x0058A5F7, callee:0x0057BC70, global:0x0057BC70]
    // GUARD: If flag bit 1 of a2 is set, deallocate memory for the placement-allocated block [source:raw]
    // CALL: FreeWrapper_7bcf(this - 1): release the block starting at the count header [source:raw, callee:0x00587BCF]
    // RETURN: Return this - 1 (the count header base of the placement-allocated block) [source:raw]
    // CALL: Else path: call SingleVTablePointerSet(this) directly to process the single object [source:raw, callee:0x0057BC70, global:0x0057BC70]
    // GUARD: Else path: if flag bit 1 of a2 is set, deallocate the object memory [source:raw]
    // CALL: Else path: FreeWrapper_7bcf(this) to release the object [source:raw, callee:0x00587BCF]
    // RETURN: Return this (the direct object pointer) [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 & 2) {
    //       NTimeCallbackLoopWithSEH(this, 308, *(this - 1), SingleVTablePointerSet);
    //       if (a2 & 1) FreeWrapper_7bcf(this - 1);
    //       return this - 1;
    //   } else {
    //       SingleVTablePointerSet(this);
    //       if (a2 & 1) FreeWrapper_7bcf(this);
    //       return this;
    //   }
    // UNRESOLVED: The exact meaning of the 308 argument to NTimeCallbackLoopWithSEH (element size, stride, or byte width) is not established from this function alone.
    // UNRESOLVED: The header layout at this - 1 (count field size and position) is assumed from the call pattern but not verified here.
    // UNRESOLVED: Flag bits other than bit 1 and bit 2 of a2 are ignored; whether callers rely on that is unknown.
    // UNRESOLVED: The relationship between this, the placement header, and the SingleVTablePointerSet callback's vtable write is not resolved.
}
