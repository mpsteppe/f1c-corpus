// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047B730
// Canonical corpus name: MenuCursorNavigationHelper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuCursorNavigationHelper_0047b730.c

void UnknownObject::MenuTextWrapPositionSearch()
{
    // Menu text word-wrap measurer. Fetches the text string through **(this+0xE0) (falling back to byte_5EA438), binary-searches with a step starting at 32 for the largest offset from a2 whose a2-prefixed substring still fits the width constraint this+0x100, measuring each candidate with TextRenderToSurface after temporarily nulling the probe character and (when this+0xC8 exists) routing the resource path through sub_498560(*(*(this+0xC8)+0x40)). When the found position is non-null it backtracks to the nearest word boundary (space 0x20 or 0xFF), then scans forward to return the final wrap offset. Called by the four menu layout/cursor helpers.
    // ASSIGNMENT: v3 = **(this + 0xE0) fetches the text string pointer; if null, fall back to the global default byte_5EA438. [field:this:0x000000E0, field:*(this+0xE0):0x00000000, global:0x005EA438, source:raw]
    // CALCULATION: v4 = strlen(v3) + 1 computes the string length including the terminator. [source:raw]
    // LOOP: Binary search with step v6 (starting at 32) for the largest offset v5 from a2 whose substring fits: probe v7 = v6 + v5 while v7 <= v4 - 1; on a failing probe halve the step (v6 /= 2); continue while v6 > 0. [source:raw]
    // CALL: If the object at this+0xC8 exists, sub_498560(*(*(this + 0xC8) + 0x40)) processes the resource path; a null path falls back to byte_5EA438. [field:this:0x000000C8, field:*(this+0xC8):0x00000040, callee:0x00498560, global:0x005EA438, source:raw]
    // CALL: TextRenderToSurface(&v3[a2], &v17, v18, 1) measures the rendered width of the a2-prefixed substring into v17, with the probe character v15 temporarily nulled and restored. [callee:0x004983B0, source:raw]
    // CALCULATION: If the measured width v17 <= this+0x100, accept the candidate (v16 = v7); otherwise halve the step (v6 /= 2). [field:this:0x00000100, source:raw]
    // GUARD: If the character at the found offset v5 is non-null, backtrack from v5-1 toward a2 to the nearest word boundary (space 0x20 or 0xFF) and advance one character past it. [source:raw]
    // RETURN: Scan forward from a2 to v5, stopping before the first 0xFF terminator, and return the final wrap offset. Used by the four menu layout/cursor helpers. [function:0x0047B730, caller:0x0047B850, caller:0x0047B9C0, caller:0x0047BC30, caller:0x0047BC90, source:raw]

    // Conservative worker pseudocode:
    //   v3 = **(this + 0xE0); if (!v3) v3 = byte_5EA438;
    //   v4 = strlen(v3) + 1; v5 = a2; v6 = 32;
    //   do {
    //       v7 = v6 + v5;
    //       if (v7 <= v4 - 1) {
    //           v15 = v3[v7]; v3[v7] = 0;
    //           if (*(this + 0xC8)) sub_498560(*(*(this + 0xC8) + 0x40));
    //           TextRenderToSurface(&v3[a2], &v17, v18, 1);
    //           v3[v7] = v15;
    //           if (v17 <= *(this + 0x100)) v5 = v7; else v6 /= 2;
    //       } else v6 /= 2;
    //   } while (v6 > 0);
    //   if (v3[v5]) backtrack to nearest space/0xFF boundary between a2 and v5;
    //   return wrap offset at/after v5;
    // UNRESOLVED: The exact semantics of sub_498560's resource-path processing and the layout of the v18 render surface are outside this packet.
}
