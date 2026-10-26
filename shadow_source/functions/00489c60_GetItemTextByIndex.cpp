// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489C60
// Canonical corpus name: UIItemTextAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIItemTextAccessor_00489c60.c

void UnknownObject::GetItemTextByIndex()
{
    // Indexed text lookup over a linked list of UI items. this+0x90 holds the list head and this+0x94 holds the item count; when index a2 is in [0, count), walks the head node forward a2 steps via the next-node pointer at +0x8C and returns the string pointer at +0xA0. Returns byte_5EA438 as the default when the index is out of range, a node is missing mid-walk, or the target string is null. Called by sub_46BA20 (0046BA20).
    // GUARD: Bounds check: return the byte_5EA438 default unless a2 is in [0, this+0x94) where this+0x94 is the item count [field:this:0x00000094, global:0x005EA438, source:raw]
    // GUARD: Head check: seed the walk from v3 = this+0x90 (list head, this[36]); when it is null, fall through and return the default [field:this:0x00000090, source:raw]
    // LOOP: Iteration: while v4 < a2, advance v3 to *(v3 + 0x8C) (next-node link) and increment v4; if v3 becomes null mid-walk, return the byte_5EA438 default [field:*(this+0x11C):0x0000008C, global:0x005EA438, source:raw]
    // ASSIGNMENT: Read result = *(v3 + 0xA0) (string text field of the reached node); when result is null return the byte_5EA438 default instead [field:*(this+0x11C):0x000000A0, global:0x005EA438, source:raw]
    // RETURN: Return the resolved string pointer, or byte_5EA438 when the index was out of range or any step of the lookup failed [function:0x00489C60, global:0x005EA438, source:raw]
    // CALL: Consumed by sub_46BA20 (0046BA20) to fetch the text of the item at a given index [caller:0x0046BA20, source:raw]

    // Conservative worker pseudocode:
    //   result = byte_5EA438;
    //   if (a2 < this[0x94/4] && a2 >= 0) {
    //       v3 = this[0x90/4];
    //       if (v3) {
    //           v4 = 0;
    //           while (v4 < a2) {
    //               v3 = *(v3 + 0x8C);
    //               ++v4;
    //               if (!v3) return result;
    //           }
    //           result = *(v3 + 0xA0);
    //           if (!result) return byte_5EA438;
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The deterministic field facts address the node's next-pointer and string fields through base *(this+0x11C) while the raw decompiled body seeds the walk from this[36] (+0x90); whether those two addressing forms denote the same list storage is not proven here
}
