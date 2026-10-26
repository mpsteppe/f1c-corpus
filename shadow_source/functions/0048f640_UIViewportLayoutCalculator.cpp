// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048F640
// Canonical corpus name: UIViewportLayoutCalculator
// Owner: UIViewportLayoutCalculator [DERIVED]
// Raw source: functions/UIViewportLayoutCalculator_0048f640.c

void UIViewportLayoutCalculator::UIViewportLayoutCalculator()
{
    // Computes a tile-grid layout for a viewport. Reads viewport bounds (0x120/0x124 and 0x140/0x144), walks the child linked list seeded at this[0xF0] to accumulate maximum tile width into this[0x160] and maximum tile height into this[0x164], then computes column/row counts (this[0x158], this[0x15C]) and a total/scroll value (this[0x16C]) based on layout mode this[0x100] (0 = vertical, 1 = horizontal). On overflow of the viewport bounds it resets the state flag this[0x104] and invokes a virtual reset method through vtable+0x40. Always calls UITileGrid (0x0048F870) and returns the result of a virtual call through vtable+0x2C with argument 1.
    // ASSIGNMENT: Initialize computed outputs to zero: this[0x160] = 0, this[0x164] = 0, this[0x158] = 0, this[0x15C] = 0, this[0x16C] = 0 [field:this:0x00000160, field:this:0x00000164, field:this:0x00000158, field:this:0x0000015C, field:this:0x0000016C, source:raw]
    // CALCULATION: Read viewport bounds: v2 = this[0x120], v3 = this[0x124] so v6 = v3 - v2; v5 = this[0x140], v4 = this[0x144] so v8 = v4 - v5 [field:this:0x00000120, field:this:0x00000124, field:this:0x00000140, field:this:0x00000144, source:raw]
    // ASSIGNMENT: Seed the iteration cursor: this[0xF8] = linked-list head this[0xF0]; first node v9 = *head when head non-null, else v9 = 0 [field:this:0x000000F0, field:this:0x000000F8, source:raw]
    // LOOP: Walk the child linked list (element count i = this[0xFC]) while the current node is non-null: accumulate maximum node width (node+0xC) into this[0x160] and maximum node height (node+0x10) into this[0x164]; advance the cursor this[0xF8] via the node next pointer at node+4, stopping when it is null [field:*(this+0xF0):0x0000000C, field:*(this+0xF0):0x00000010, field:this:0x000000FC, field:this:0x000000F8, field:this:0x00000160, field:this:0x00000164, source:raw]
    // GUARD: Layout mode dispatch: read mode this[0x100]; value 0 takes the vertical branch, value 1 takes the horizontal branch, values above 1 fall through without computation [field:this:0x00000100, source:raw]
    // CALCULATION: Horizontal mode (mode == 1): when max width this[0x160] is non-zero, rows this[0x15C] = v6 / (this[0x160] + spacing this[0x150]) [field:this:0x00000150, field:this:0x00000160, field:this:0x0000015C, source:raw]
    // CALCULATION: Horizontal mode: columns this[0x158] and total this[0x16C] = i / rows this[0x15C] when rows is non-zero, each rounded up by +1 when i % rows > 0; when rows is zero, total this[0x16C] = i [field:this:0x00000158, field:this:0x0000015C, field:this:0x0000016C, source:raw]
    // CALCULATION: Horizontal mode: v18 = spacing this[0x154] + max height this[0x164]; when v18 is non-zero, total this[0x16C] -= v8 / v18, clamp total to >= 0 when negative, then total *= v18 [field:this:0x00000154, field:this:0x00000164, field:this:0x0000016C, guard:0, source:raw]
    // CALCULATION: Vertical mode (mode == 0): when max height this[0x164] is non-zero, columns this[0x158] = v8 / (this[0x164] + spacing this[0x154]) [field:this:0x00000154, field:this:0x00000164, field:this:0x00000158, source:raw]
    // CALCULATION: Vertical mode: when prior rows this[0x15C] is non-zero, rows = i / prior rows; when columns this[0x158] is non-zero and i % columns > 0, increment rows this[0x15C] [field:this:0x00000158, field:this:0x0000015C, source:raw]
    // CALCULATION: Vertical mode: when max width this[0x160] is non-zero, total this[0x16C] = rows this[0x15C] - v6 / this[0x160]; clamp total to >= 0 when negative [field:this:0x00000160, field:this:0x0000015C, field:this:0x0000016C, guard:0, source:raw]
    // GUARD: Overflow test: if rows this[0x15C] * (max width this[0x160] + spacing this[0x150]) > v6 OR columns this[0x158] * (max height this[0x164] + spacing this[0x154]) > v8, take the reset path [field:this:0x00000158, field:this:0x0000015C, field:this:0x00000150, field:this:0x00000154, field:this:0x00000160, field:this:0x00000164, source:raw]
    // ASSIGNMENT: On overflow, reset the state flag this[0x104] = 0 [field:this:0x00000104, source:raw]
    // CALL: On overflow, invoke virtual thiscall through vtable this[0x0] at slot +0x40 with (this, 0) to reset state [field:this:0x00000000, field:obj:0x00000040, source:raw]
    // CALL: Invoke UITileGrid (0x0048F870) with this to update tile positions [callee:0x0048F870, source:raw]
    // RETURN: Return the result of the virtual thiscall through vtable this[0x0] at slot +0x2C with (this, 1) [field:this:0x00000000, field:obj:0x0000002C, function:0x0048F640, source:raw]
    // CALL: Invoked by ObjectNameComparison (00477280), GameFilterSetup (00477830), and ProfileBitmapBrowser (00477CB0) [caller:0x00477280, caller:0x00477830, caller:0x00477CB0]

    // Conservative worker pseudocode:
    //   this[0x160] = 0; this[0x164] = 0; this[0x158] = 0; this[0x15C] = 0; this[0x16C] = 0;
    //   v6 = this[0x124] - this[0x120];
    //   v8 = this[0x144] - this[0x140];
    //   this[0xF8] = this[0xF0];
    //   node = (this[0xF0]) ? *(int*)this[0xF0] : 0;
    //   i = this[0xFC];
    //   while (node) {
    //     if (this[0x160] < *(int*)(node + 0xC)) this[0x160] = *(int*)(node + 0xC);
    //     if (this[0x164] < *(int*)(node + 0x10)) this[0x164] = *(int*)(node + 0x10);
    //     node = (this[0xF8]) ? *(int**)(this[0xF8] + 4) : 0;
    //     this[0xF8] = node;
    //   }
    //   mode = this[0x100];
    //   if (mode) {
    //     if (mode == 1) {
    //       if (this[0x160]) this[0x15C] = v6 / (this[0x160] + this[0x150]);
    //       if (this[0x15C]) {
    //         this[0x158] = i / this[0x15C];
    //         if (i % this[0x15C] > 0) ++this[0x158];
    //         this[0x16C] = i / this[0x15C];
    //         if (i % this[0x15C] > 0) this[0x16C] = i / this[0x15C] + 1;
    //       } else {
    //         this[0x16C] = i;
    //       }
    //       v18 = this[0x154] + this[0x164];
    //       if (v18) this[0x16C] -= v8 / v18;
    //       if (this[0x16C] < 0) this[0x16C] = 0;
    //       this[0x16C] *= v18;
    //     }
    //   } else {
    //     if (this[0x164]) this[0x158] = v8 / (this[0x164] + this[0x154]);
    //     if (this[0x15C]) this[0x15C] = i / this[0x15C];
    //     if (this[0x158] && i % this[0x158] > 0) ++this[0x15C];
    //     if (this[0x160]) this[0x16C] = this[0x15C] - v6 / this[0x160];
    //     if (this[0x16C] < 0) this[0x16C] = 0;
    //   }
    //   if (this[0x15C] * (this[0x160] + this[0x150]) > v6 ||
    //       this[0x158] * (this[0x164] + this[0x154]) > v8) {
    //     this[0x104] = 0;
    //     (**(void (__thiscall **)(void*, void*))(this[0x0] + 0x40))(this, 0);
    //   }
    //   UITileGrid(this);
    //   return (**(int (__thiscall **)(void*, int))(this[0x0] + 0x2C))(this, 1);
    // UNRESOLVED: Identities of the two virtual methods invoked through vtable slot +0x2C (return path, argument 1) and vtable slot +0x40 (overflow reset path, argument 0) are not known from this function alone
    // UNRESOLVED: The orientation of the viewport bound pairs (which pair is width vs height) is inferred from the arithmetic and is not proven here
    // UNRESOLVED: Layout mode values greater than 1 are read but produce no computation in this function
    // UNRESOLVED: The exact meaning of the state flag at this[0x104] beyond 'reset to 0 on overflow' is not established
    // UNRESOLVED: The spacing terms this[0x150] and this[0x154] are named generically; their per-axis roles are inferred
}
