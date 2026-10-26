// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8EA0
// Canonical corpus name: FrameRateCounterInitReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FrameRateCounterInitReset_004f8ea0.c

void UnknownObject::FrameRateCounterInitReset()
{
    // Resets a frame-rate counter/timer object: conditionally frees the heap object held at this+0x18, searches the wide-string linked list for the "FTFrameRate" entry and compares its match, then zeroes every counter/timer field (this+0x0 through this+0x2C, plus the byte flags at this+0x2C and this+0x6C). Returns 0.
    // GUARD: Guard on the allocation pointer: when this[6] (this+0x18) is non-null, the object is released before the counter fields are reset. [field:this:0x00000018, source:raw]
    // CALL: Calls EmptyStub_7470(this[6]) with the pointer stored at this+0x18. [callee:0x00557470, field:this:0x00000018, source:raw]
    // CALL: Calls FreeWrapper_7bcf(v2) to release the heap object that was at this+0x18. [callee:0x00587BCF, field:this:0x00000018, source:raw]
    // CALL: Calls WideStringLinkedListSearch(aFtframerate) using the "FTFrameRate" string global to search the wide-string linked list; result stored in v3. [callee:0x0053D1F0, global:0x005D6D78, source:raw]
    // GUARD: Guard on the search result: when v3 is non-null a comparison pass runs against the found entry. [source:raw]
    // CALL: Calls StringCompareLinkedListSearch(v3) with the entry found by the wide-string search. [callee:0x0053D130, source:raw]
    // ASSIGNMENT: Zeroes the dword fields this+0x0, this+0x4, this+0x8, this+0xC, this+0x10, this+0x14, this+0x18, this+0x1C, this+0x20, this+0x24, this+0x28 and this+0x2C, clearing every frame-rate counter/timer slot and the freed pointer. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Zeroes the byte flag at this+0x6C. [field:this:0x0000006C, source:raw]
    // RETURN: Returns 0. [function:0x004F8EA0, source:raw]

    // Conservative worker pseudocode:
    //   int FrameRateCounterInitReset(_DWORD *this) {
    //     void *v2 = (void *)this[6];
    //     if ( v2 ) {
    //       EmptyStub_7470(this[6]);
    //       FreeWrapper_7bcf(v2);
    //     }
    //     int v3 = WideStringLinkedListSearch(aFtframerate);
    //     if ( v3 )
    //       StringCompareLinkedListSearch(v3);
    //     this[0..10] = 0;
    //     *((_BYTE *)this + 44) = 0;
    //     *((_BYTE *)this + 108) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Global 0x008AFE64 (dword_8AFE64) is read by this routine per deterministic facts but does not appear in the packet's raw source text; the read's purpose is unresolved.
    // UNRESOLVED: Semantics of the wide-string linked-list search and its match comparison (registration vs configuration lookup) are not evidenced.
    // UNRESOLVED: The single static caller VidMan_Post (0x004FAC00) context in which this reset runs is not established.
}
