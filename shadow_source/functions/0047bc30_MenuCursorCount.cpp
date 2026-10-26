// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BC30
// Canonical corpus name: MenuCursorCount
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuCursorCount_0047bc30.c

void UnknownObject::MenuCursorCount()
{
    // Counts wrapped text items up to the cursor position. Reads the source text pointer at this+0xE0 (falling back to a default string global when null), then iterates via MenuCursorNavigationHelper from index 0, incrementing a counter until no further wrap occurs, the cursor limit at this+0xE4 is reached, or an end-of-string delimiter (byte 0xFF) is hit.
    // ASSIGNMENT: Read source text pointer stored at this+0xE0 and dereference it [field:this:0x000000E0, field:*(this+0xE0):0x00000000]
    // GUARD: When the dereferenced text pointer is null, fall back to the default string global byte_5EA438 [global:0x005EA438, field:this:0x000000E0]
    // CALCULATION: Compute text length as strlen(v2) plus 1 [field:*(this+0xE0):0x00000000, global:0x005EA438]
    // LOOP: Iterate cursor indices via MenuCursorNavigationHelper(this, i) starting from 0, advancing i to the value returned by the helper [callee:0x0047B730, field:this:0x000000E4]
    // GUARD: Break loop when index is unchanged, when the cursor limit at this+0xE4 is below the wrapped position, or when at end of string with the previous character not being the 0xFF delimiter [field:this:0x000000E4, callee:0x0047B730]
    // CALCULATION: Increment the line/item counter on each wrapped position before the break conditions [callee:0x0047B730, field:this:0x000000E4]
    // RETURN: Return the accumulated line/item count [function:0x0047BC30]

    // Conservative worker pseudocode:
    //   v2 = **(char const **)(this + 0xE0);
    //   if (v2 == 0) v2 = byte_5EA438;
    //   v3 = strlen(v2) + 1;
    //   v4 = 0;
    //   for (i = 0;; i = v6) {
    //       v6 = MenuCursorNavigationHelper(this, i);
    //       if (i == v6 || *(this + 0xE4) < v6 || (v3 - 1 == v6 && v2[v6 - 1] != 0xFF)) break;
    //       ++v4;
    //   }
    //   return v4;
    // UNRESOLVED: Exact meaning of the cursor limit at this+0xE4 and whether the count is of text lines or of wrapped segments is not established.
}
