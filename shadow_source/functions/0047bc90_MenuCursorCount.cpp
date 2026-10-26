// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BC90
// Canonical corpus name: MenuCursorCount_bc90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuCursorCount_bc90_0047bc90.c

void UnknownObject::MenuCursorCount()
{
    // Menu cursor count measurer (__thiscall): loads the menu text pointer from field this+0xE0 (falling back to the global byte_5EA438), computes its length plus the terminator, then walks the cursor index forward one step at a time via MenuCursorNavigationHelper, counting each reachable cursor position (starting at 1) until the helper returns the same index (no movement) or reaches the final text position whose preceding character is a non-(-1) terminator, and returns the total number of cursor positions.
    // ASSIGNMENT: v2 = *this[56] loads the menu text pointer stored at field this+0xE0. [field:this:0x000000E0, source:raw]
    // GUARD: When the field pointer is null, fall back to the global default text source byte_5EA438. [global:0x005EA438, source:raw]
    // CALCULATION: v3 = strlen(v2) + 1 computes the text length including the terminating character. [source:raw]
    // ASSIGNMENT: v4 = 1 seeds the cursor position count at one before the loop. [source:raw]
    // LOOP: Iterate the cursor index i starting at 0; each iteration advances i to the helper's returned index v6 until a break condition is met. [source:raw]
    // CALL: v6 = MenuCursorNavigationHelper(this, i) advances the cursor from index i to the next navigation position. [callee:0x0047B730, source:raw]
    // GUARD: Break when the helper returns the same index (i == v6, no movement) or when v6 is the final text position (v6 == v3 - 1) and the preceding character v2[v6 - 1] is not the -1 terminator character. [source:raw]
    // STATE_TRANSITION: ++v4 increments the cursor position count on every reachable position. [source:raw]
    // RETURN: Return the total number of cursor positions v4. [function:0x0047BC90, source:raw]
    // CALL: Called by BoundedCounterUpdate, sub_47BCF0, UtilityFunction_bd90 and sub_47BE00 to measure the cursor position range of a menu. [caller:0x0047BAE0, caller:0x0047BCF0, caller:0x0047BD90, caller:0x0047BE00, source:raw]

    // Conservative worker pseudocode:
    //   int MenuCursorCount(DWORD** this) {
    //     const char* v2 = (const char*)*this[56];
    //     if (!v2) v2 = byte_5EA438;
    //     unsigned int v3 = strlen(v2) + 1;
    //     int v4 = 1;
    //     for (int i = 0; ; i = v6) {
    //       int v6 = MenuCursorNavigationHelper((int)this, i);
    //       if (i == v6 || (v6 == v3 - 1 && v2[v6 - 1] != -1)) break;
    //       ++v4;
    //     }
    //     return v4;
    //   }
    // UNRESOLVED: The navigation semantics of MenuCursorNavigationHelper (0x0047B730) and the meaning of the -1 terminator character are inferred from usage and resolved in the helper's own function.
    // UNRESOLVED: Whether the count includes the final cursor position depends on the helper's boundary behavior, which is outside this packet.
}
