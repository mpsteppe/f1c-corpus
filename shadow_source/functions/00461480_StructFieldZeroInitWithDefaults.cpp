// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461480
// Canonical corpus name: StructFieldZeroInitWithDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldZeroInitWithDefaults_00461480.c

void UnknownObject::StructFieldZeroInitWithDefaults()
{
    // Field-wise initializer that zeros a block at this+0x0 through this+0x88 and seeds two sentinel bytes (0x7C, 0x7E) with -1, then returns 0. No reads, no globals, no callees; it only stamps literals into a caller-provided object. Called by ArrayInitWithSentinelInLoop (00460C60), ClearPlayerSlots (00460CB0) and a thunk (00461470), so it is shared initialization state for a per-slot object.
    // ASSIGNMENT: Zero the leading dword at this+0x0 [field:this:0x00000000]
    // ASSIGNMENT: Zero the bytes at this+0x4, this+0x24, this+0x3C and this+0x5C [field:this:0x00000004, field:this:0x00000024, field:this:0x0000003C, field:this:0x0000005C]
    // ASSIGNMENT: Seed sentinel bytes: this+0x7C set to -1, this+0x7D cleared to 0, this+0x7E set to -1 [field:this:0x0000007C, field:this:0x0000007D, field:this:0x0000007E]
    // ASSIGNMENT: Zero the four word fields at this+0x80, this+0x82, this+0x84 and this+0x86 [field:this:0x00000080, field:this:0x00000082, field:this:0x00000084, field:this:0x00000086]
    // ASSIGNMENT: Zero the byte at this+0x88 [field:this:0x00000088]
    // RETURN: Return literal 0; the function is a pure initializer with no computed result, called by ArrayInitWithSentinelInLoop (00460C60), ClearPlayerSlots (00460CB0) and thunk 00461470 [function:0x00461480, caller:0x00460C60, caller:0x00460CB0, caller:0x00461470]

    // Conservative worker pseudocode:
    //   *(dword*)(this + 0x0) = 0;
    //   *(byte*)(this + 0x4)  = 0;
    //   *(byte*)(this + 0x24) = 0;
    //   *(byte*)(this + 0x3C) = 0;
    //   *(byte*)(this + 0x5C) = 0;
    //   *(byte*)(this + 0x7C) = -1;
    //   *(byte*)(this + 0x7D) = 0;
    //   *(byte*)(this + 0x7E) = -1;
    //   *(word*)(this + 0x80) = 0;
    //   *(word*)(this + 0x82) = 0;
    //   *(word*)(this + 0x84) = 0;
    //   *(word*)(this + 0x86) = 0;
    //   *(byte*)(this + 0x88) = 0;
    //   return 0;
    // UNRESOLVED: The object type owning offsets 0x0-0x88 is unidentified; callers span an array initializer and a player-slot clearer, so it may be a shared per-slot state struct
    // UNRESOLVED: Purpose of the -1 sentinels at this+0x7C and this+0x7E is not documented; they may be default handles or invalid-id markers
    // UNRESOLVED: Why the final byte field is initialized but the bytes between the fifth byte field and the first sentinel are left untouched is unexplained
}
