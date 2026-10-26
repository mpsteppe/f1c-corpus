// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047B910
// Canonical corpus name: MenuItemRenderHelper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuItemRenderHelper_0047b910.c

void UnknownObject::MenuItemRenderHelper()
{
    // Menu-item text-fit measurer (__thiscall): loads a text buffer pointer from field this+0xE0 (falling back to the global byte_5EA438), then measures the text character by character with TextRenderToSurface against an available-width constraint a2, returning the character index at which the menu-item text must be truncated.
    // ASSIGNMENT: Load the text buffer pointer stored at field this+0xE0 (this[56]); v4 = *this[56]. [field:this:0x000000E0]
    // GUARD: When the field pointer is null, fall back to the global default text source byte_5EA438. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Initialize scan index v5 = a3 + 1, equality flag v6 = (a3 + 1 == a4), and previous-width v11 = 0. [source:raw]
    // GUARD: Skip the measurement loop entirely when a3 + 1 >= a4 (no characters left to measure). [source:raw]
    // LOOP: Scan characters v5 from a3 + 1 upward while v5 < a4; on each iteration temporarily null-terminate the buffer at v5, measure, restore the original character, and break when the measured width reaches the available width. [source:raw]
    // CALL: Measure the rendered width of the substring &v4[a3]..v5 by calling TextRenderToSurface(&v4[a3], &a2, v12, 1); the measured width updates a2 and the previous width is saved in v11. [callee:0x004983B0, source:raw]
    // GUARD: Break the loop when the measured width a2 is no longer less than the original available width v7 (kept before the loop). [source:raw]
    // CALCULATION: Mid-point correction: when v7 <= (v11 + a2) / 2, step the index back one character (--v5) to compensate for the last character's over-width. [source:raw]
    // GUARD: Final tail correction: when the scan reached a4 (v6), v5 > a3, and the character at v4[v5] is non-null, step v5 back by one. [source:raw]
    // RETURN: Return the final character index v5 at which the menu-item text is considered to fit. [source:raw]
    // CALL: Called by MenuItemLayoutCalculator (0x0047B850) and MenuCursorPositioning (0x0047B9C0) to determine the visible text length for a menu item. [caller:0x0047B850, caller:0x0047B9C0, source:raw]

    // Conservative worker pseudocode:
    //   int MenuItemRenderHelper(DWORD** this, int availWidth, int a3, int a4) {
    //     char* v4 = (char*)*this[56];
    //     if (!v4) v4 = byte_5EA438;
    //     int v5 = a3 + 1;
    //     bool v6 = (a3 + 1 == a4);
    //     int v11 = 0;
    //     if (a3 + 1 < a4) {
    //       int v7 = availWidth;
    //       for (;;) {
    //         char v8 = v4[v5];
    //         char* v9 = &v4[a3];
    //         v4[v5] = 0;
    //         TextRenderToSurface(v9, &availWidth, v12, 1);
    //         v4[v5] = v8;
    //         if (v7 <= availWidth) break;
    //         v11 = availWidth;
    //         if (++v5 >= a4) goto done;
    //       }
    //       if (v7 <= (v11 + availWidth) / 2) --v5;
    //     done: v6 = (v5 == a4);
    //     }
    //     if (v6 && v5 > a3 && v4[v5]) --v5;
    //     return v5;
    //   }
    // UNRESOLVED: Purpose of the double indirection on this[56] and exact contents of the fallback global byte_5EA438 are outside this packet.
    // UNRESOLVED: TextRenderToSurface's exact width-update contract for a2 is assumed from usage; confirmed in its own function.
    // UNRESOLVED: The (v11 + a2) / 2 midpoint correction's display rationale is inferred and not independently documented.
}
