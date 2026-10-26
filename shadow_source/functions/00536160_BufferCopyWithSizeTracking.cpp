// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00536160
// Canonical corpus name: BufferCopyWithSizeTracking
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferCopyWithSizeTracking_00536160.c

void UnknownObject::BufferCopyWithSizeTracking()
{
    // Copies min(source remaining, destination remaining) bytes from a source sub-object (read pointer at this+0x1C) into the destination write pointer, advancing both pointers, decrementing both remainders and accumulating a copied total; when the source sub-object's copied count reaches zero, its remaining size is reloaded from its total. Part of the compression/decompression buffer pipeline.
    // CALCULATION: Read source object pointer from this+0x1C and destination remaining size from this+0x10; compute copy length as min(source remaining at sourceObj+0x14, destination remaining at this+0x10) [field:this:0x0000001C, field:this:0x00000010, source:raw]
    // GUARD: If the computed copy length is nonzero, perform the copy [source:raw]
    // CALL: qmemcpy: copy the computed length from the source read pointer (sourceObj+0x10) to the destination write pointer (this+0xC) [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Advance the destination write pointer (this+0xC) by the copied length [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Advance the source read pointer (sourceObj+0x10) by the copied length [source:raw]
    // ASSIGNMENT: Accumulate this+0x14 (total bytes copied) by the copied length [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Decrement this+0x10 (destination remaining size) by the copied length [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Decrement the source remaining size (sourceObj+0x14) by the copied length [source:raw]
    // STATE_TRANSITION: If the source copied count (sourceObj+0x14) reached zero, reload the source remaining size (sourceObj+0x10) from the source total size (sourceObj+0x8) [source:raw]
    // RETURN: Return the source object pointer (this+0x1C); when no copy was performed the return value is `this` itself [field:this:0x0000001C, source:raw]

    // Conservative worker pseudocode:
    //   // this = buffer-pair object; srcObj = *(this+0x1C)
    //   count = min(this->destRemaining /*this+0x10* /, srcObj->remaining /*srcObj+0x14* /);
    //   if (count) {
    //     memcpy(this->writePtr /*this+0xC* /, srcObj->readPtr /*srcObj+0x10* /, count);
    //     this->writePtr += count;      /* this+0xC * /
    //     srcObj->readPtr += count;     /* srcObj+0x10 * /
    //     this->totalCopied += count;   /* this+0x14 * /
    //     this->destRemaining -= count; /* this+0x10 * /
    //     srcObj->remaining -= count;   /* srcObj+0x14 * /
    //     if (srcObj->copied == 0)      /* srcObj+0x14 * /
    //       srcObj->remaining = srcObj->total; /* srcObj+0x10 = srcObj+0x8 * /
    //   }
    //   return srcObj; /* this+0x1C * /
    // UNRESOLVED: Fields this+0x24 and this+0x38 are listed in the deterministic field facts but are not referenced by the raw decompiled body; their role is not resolvable from this packet alone.
    // UNRESOLVED: Fields this+0x2C and this+0x30 are recorded as RW (existing analysis names them the source read pointer and remaining source size) but the raw body reads and advances the source state through the sub-object pointer at this+0x1C; the relationship between this+0x2C/this+0x30 and the sub-object offsets is not resolvable from this packet alone.
    // UNRESOLVED: The source sub-object behind this+0x1C is dereferenced at offsets +0x8, +0x10 and +0x14 (reload/read/remaining) but its concrete type is not established by this packet.
}
