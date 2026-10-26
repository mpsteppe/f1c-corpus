// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048F870
// Canonical corpus name: UITileGrid
// Owner: UITileGrid [DERIVED]
// Raw source: functions/UITileGrid_0048f870.c

void UITileGrid::UITileGrid()
{
    // Computes screen positions for tiles in a grid-based UI layout and places each tile. Reads two values into locals through DualFieldRead, then computes the number of columns that fit between grid start this[0x120] and end this[0x124] using cell width plus spacing (this[0x160] + this[0x150]), clamped to the maximum this[0xFC], and the leftover width v18. While the row count this[0x158] is positive it walks rows and columns, finds the tile node for each linear index by advancing the linked list seeded at this[0xF0] through each node's +4 next pointer, and reads the tile object from the node's first field. The tile X is this[0x120] + column * (this[0x150] + this[0x160]) minus an offset from this[0x168], shifted by v18/2 (center, this[0xE0] == 1) or v18 (right, this[0xE0] == 2); the tile Y is this[0x140] + row * (this[0x154] + this[0x164]) minus an offset. Each tile is placed through sub_48EA20. On completion invokes the vtable slot at byte offset 44 on this with argument 1 and returns its result. Called by sub_48F1A0, UIViewportLayoutCalculator (0x0048F640), DecrementCounterWithClamp (0x0048FAF0) and sub_48FB30.
    // ASSIGNMENT: Initialize the two stack locals to 0 (v20 = 0, v19 = 0) before the dual read. [source:raw]
    // CALL: DualFieldRead(&v20, &v19) reads two values into the locals used by the layout calculation. [callee:0x00498880, source:raw]
    // CALCULATION: Compute the fitted column count: v2 = this[72] (this+0x120), v3 = this[88] + this[84] (this+0x160 + this+0x150), v4 = (this[73] - v2) / v3 with this[73] at this+0x124, then clamp v4 to at most this[63] (this+0xFC). [field:this:0x00000120, field:this:0x00000124, field:this:0x00000160, field:this:0x00000150, field:this:0x000000FC, source:raw]
    // CALCULATION: Compute the leftover width v18 = this[73] (this+0x124) - v4 * v3 - v2 (this+0x120) after the fitted columns are laid out. [field:this:0x00000124, field:this:0x00000120, source:raw]
    // GUARD: Enter the row/column walk only when the row count this[86] (this+0x158) is greater than 0. [guard:2, field:this:0x00000158, source:raw]
    // LOOP: Outer row loop: advance the row index v17; when the row index reaches this[86] (this+0x158), stop and invoke the vtable slot at byte offset 44 on this (vtable this[0x0]) with argument 1. [field:this:0x00000158, field:this:0x00000000, source:raw]
    // LOOP: Inner column loop: iterate columns while the column count this[87] (this+0x15C) is positive; for each linear index v8 = column + row * this[87], when v8 is in [0, this[63]) (this+0xFC) walk the tile linked list from this[60] (this+0xF0), advancing through each node's +4 next pointer, to reach the node at index v8. [field:this:0x0000015C, field:this:0x000000FC, field:this:0x000000F0, field:*(this+0xF4):0x00000004, source:raw]
    // GUARD: When the reached list node is non-null, read the tile object from the node's first field (*(this+0xF4) offset 0); when that is non-null, take the break-out path with the tile object. [field:*(this+0xF4):0x00000000, source:raw]
    // GUARD: Alignment sub-type dispatch on this[64] (this+0x100): value 0 takes v12 = this[90] (this+0x168) as the X offset, value 1 takes v13 = this[90] as the Y offset, and other values leave both offsets at 0. [field:this:0x00000100, field:this:0x00000168, source:raw]
    // CALCULATION: Compute the tile X: v14 = this[72] (this+0x120) + column * (this[84] + this[88], i.e. this+0x150 + this+0x160) - v12. [field:this:0x00000120, field:this:0x00000150, field:this:0x00000160, source:raw]
    // GUARD: Alignment mode dispatch on this[56] (this+0xE0): when equal to 1 (center), add v15 = v18/2 to the X; when not equal to 2 (left), fall through to place the tile with the plain X; when equal to 2 (right), add v15 = v18 to the X. [guard:0, guard:1, field:this:0x000000E0, source:raw]
    // CALCULATION: Compute the tile Y: this[80] (this+0x140) + row * (this[85] + this[89], i.e. this+0x154 + this+0x164) - v13. [field:this:0x00000140, field:this:0x00000154, field:this:0x00000164, source:raw]
    // CALL: Place the tile: sub_48EA20(tile object, X, Y). [callee:0x0048EA20, source:raw]
    // RETURN: When no rows remain (or the row count is not positive), invoke the vtable slot at byte offset 44 on this (vtable this[0x0]) with argument 1 and return its result. [field:this:0x00000000, function:0x0048F870, source:raw]
    // CALL: Invoked by sub_48F1A0 (0x0048F1A0), UIViewportLayoutCalculator (0x0048F640), DecrementCounterWithClamp (0x0048FAF0) and sub_48FB30 (0x0048FB30). [caller:0x0048F1A0, caller:0x0048F640, caller:0x0048FAF0, caller:0x0048FB30]

    // Conservative worker pseudocode:
    //   int UITileGrid(_DWORD* this) {
    //     int v20 = 0, v19 = 0;
    //     DualFieldRead(&v20, &v19);
    //     int stride = this[88] + this[84];
    //     int v4 = (this[73] - this[72]) / stride;
    //     if (v4 >= this[63]) v4 = this[63];
    //     int v18 = this[73] - v4 * stride - this[72];
    //     int row = 0;
    //     if (this[86] > 0) {
    //       for (int r = 0; ; ) {
    //         int cols = this[87];
    //         if (cols > 0) {
    //           for (int c = 0; ; ) {
    //             int idx = c + r * cols;
    //             if (idx >= 0 && idx < this[63]) {
    //               int node = this[60];
    //               if (idx > 0) {
    //                 while (node) {
    //                   node = *(int*)(node + 4);
    //                   if (--idx <= 0) break;
    //                 }
    //               }
    //               if (node && *(_DWORD**)node) {
    //                 int tile = *(_DWORD**)node;
    //                 int sub = this[64];
    //                 int xoff = 0, yoff = 0;
    //                 if (sub == 0) xoff = this[90];
    //                 else if (sub == 1) yoff = this[90];
    //                 int x = this[72] + c * (this[84] + this[88]) - xoff;
    //                 int y = this[80] + r * (this[85] + this[89]) - yoff;
    //                 if (this[56] == 1) x += v18 / 2;
    //                 else if (this[56] == 2) x += v18;
    //                 sub_48EA20(tile, x, y);
    //               }
    //             }
    //             if (++c >= cols) break;
    //           }
    //         }
    //         if (++r >= this[86])
    //           return (*(int (__thiscall **)(_DWORD*, int))(*this + 44))(this, 1);
    //       }
    //     }
    //     return (*(int (__thiscall **)(_DWORD*, int))(*this + 44))(this, 1);
    //   }
    // UNRESOLVED: field:obj:0x0000002C is listed in the packet but does not appear in the raw source text; its role here is unknown.
    // UNRESOLVED: The identity and semantics of the vtable slot at byte offset 44 invoked on completion (an on-complete callback with argument 1) are not established from this function alone.
    // UNRESOLVED: The exact meaning of the two values read by DualFieldRead into the stack locals is not established; they may be input coordinates or sizes consumed by the layout.
    // UNRESOLVED: The per-field names (cell width, spacing, row/column counts) are inferred from the layout arithmetic and are not independently verified.
}
