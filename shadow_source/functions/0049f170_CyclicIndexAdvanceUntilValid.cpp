// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F170
// Canonical corpus name: sub_49F170
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49F170_0049f170.c

void UnknownObject::CyclicIndexAdvanceUntilValid()
{
    // Advances or decrements the cyclic index at this+0x4 (range 0-4) in a direction chosen by a2, re-wrapping at the 0/4 bounds, and keeps stepping until the 5-entry table reached through dword_7C54E8+13004 has a value greater than 1 at entry offset 40 + (index << 6). Returns the table base pointer. Used to select the next valid slot when the current one is not usable.
    // ASSIGNMENT: Seed the scan base: result = dword_7C54E8 + 13004, pointing into the player vehicle structure where the 5-entry candidate table lives. [global:0x007C54E8, source:raw]
    // ASSIGNMENT: Read the current cyclic index: v3 = this[1] (this+0x4). [field:this:0x00000004, source:raw]
    // GUARD: a2 selects the stepping direction: non-zero takes the decrement/backward path, zero takes the increment/forward path. [source:raw]
    // CALCULATION: Backward step: v4 = v3 - 1 written to this[1]; when v4 drops below 0 the index wraps to 4 (cyclic 0-4 decrement). [field:this:0x00000004, source:raw]
    // CALCULATION: Forward step: v5 = v3 + 1 written to this[1]; when v5 reaches 5 the index wraps to 0 (cyclic 0-4 increment). [field:this:0x00000004, source:raw]
    // LOOP: do-while scan: continue stepping the index while the 64-byte-strided entry at result + (this[1] << 6) + 40 holds a value <= 1; the first entry with value > 1 stops the loop. [global:0x007C54E8, field:this:0x00000004, source:raw]
    // RETURN: Return the table base pointer result (dword_7C54E8 + 13004). [global:0x007C54E8, source:raw]
    // CALL: Invoked by sub_49F1C0 (0049F1C0) and ModeBasedDispatch (0049F790) to move the cyclic selection to the next entry that passes the value>1 validity check. [caller:0x0049F1C0, caller:0x0049F790, source:raw]

    // Conservative worker pseudocode:
    //   int CyclicIndexAdvanceUntilValid(SelectionObj* this, int backward) {
    //     char* table = dword_7C54E8 + 13004;
    //     do {
    //       int idx = this->index;             /* this+0x4 * /
    //       if (backward) {
    //         idx = idx - 1;
    //         this->index = (idx < 0) ? 4 : idx;
    //       } else {
    //         idx = idx + 1;
    //         this->index = (idx >= 5) ? 0 : idx;
    //       }
    //     } while (*(int*)(table + (this->index << 6) + 40) <= 1);
    //     return table;
    //   }
    // UNRESOLVED: The candidate table at dword_7C54E8+13004 has no element layout defined in this packet; only the 64-byte stride and the selector value read at +40 are evidenced.
    // UNRESOLVED: The meaning of the per-entry value (values <= 1 are skipped) depends on the table owner, which is not resolved here.
}
