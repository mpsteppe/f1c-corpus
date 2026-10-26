// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E0DB0
// Canonical corpus name: MultiSystemStructInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiSystemStructInitializer_004e0db0.c

void UnknownObject::MultiSystemStructInitializer()
{
    // Bulk one-time lazy initialization of multiple substructure blocks of a single owning object, invoked from vehicle reset paths (VehicleRespawnReset and VehicleResetClear). Initializes two singleton blocks at dword offsets 377 and 394, then runs a 4-iteration loop initializing block pairs (offset cursor minus 68 dwords, then the cursor) advancing 296 dwords per iteration, and finishes with an 8-iteration loop initializing 68-dword-strided blocks starting at dword offset 411. Returns the result of the last LazyInitCallback.
    // CALL: LazyInitCallback(this, this + 377) one-time initializes the singleton substructure block at dword offset 377. [callee:0x004E0D00, source:raw]
    // CALL: LazyInitCallback(this, this + 394) one-time initializes the singleton substructure block at dword offset 394. [callee:0x004E0D00, source:raw]
    // ASSIGNMENT: Set up the first loop: cursor v2 = this + 98 dwords and loop counter v3 = 4. [source:raw]
    // LOOP: Four iterations: LazyInitCallback(this, v2 - 68) then LazyInitCallback(this, v2), advancing the cursor 296 dwords each pass until the counter reaches zero. [callee:0x004E0D00, source:raw]
    // ASSIGNMENT: Set up the second loop: cursor v4 = this + 411 dwords and loop counter v5 = 8. [source:raw]
    // LOOP: Eight iterations: result = LazyInitCallback(this, v4), advancing the cursor 68 dwords each pass until the counter reaches zero. [callee:0x004E0D00, source:raw]
    // RETURN: Return the result of the last LazyInitCallback from the final loop. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4E0DB0(_DWORD* this) {
    //     LazyInitCallback(this, (int)(this + 377));
    //     LazyInitCallback(this, (int)(this + 394));
    //     int v2 = (int)(this + 98);
    //     int v3 = 4;
    //     do { LazyInitCallback(this, v2 - 68); LazyInitCallback(this, v2); v2 += 296; } while (--v3);
    //     int v4 = (int)(this + 411);
    //     int v5 = 8;
    //     int result;
    //     do { result = LazyInitCallback(this, v4); v4 += 68; } while (--v5);
    //     return result;
    //   }
    // UNRESOLVED: The owning object (this) and which substructures live at dword offsets 377, 394, 98+-68, 98+296k and 411+68k are unknown; all offsets are grounded only in the raw source and have no named field evidence.
    // UNRESOLVED: The pattern suggests a struct array of four 296-dword blocks with a 68-dword sub-block each, and an 8-element 68-dword array, but the semantic identity of each block is unresolved.
    // UNRESOLVED: Why the four 296-dword blocks are each initialized in two pieces (v2-68 and v2) is unresolved.
}
