// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054BDC0
// Canonical corpus name: UIElementBitfieldStateSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIElementBitfieldStateSetter_0054bdc0.c

void UnknownObject::UIElementBitfieldStateSetter()
{
    // Walks a linked list of UI elements whose head is this[129] (this+0x204) and next pointer is element[4] (element+0x10). For each element it applies a bitfield state mask over the state-entry array (pointer element[71], count element[70]): every entry is rewritten to a2 | (~a3 & old), setting bits from a2 and clearing bits from a3. When bit 5 (0x20) of a2 is set, a color word is derived from the global color/texture counter at dword_8B8F28+432, applied to each sub-element color slot (cleared to 0xFF000000 then OR-ed, 64-byte stride from v5[8]+24), the global counter is advanced, and the wrappers SingleCallWrapper_e0e0(v5, 6) / Wrapper_e0f0(v5, 4) run. When bit 5 of a2 is clear and bit 5 of a3 is set, per-entry state-change callbacks dispatch on the low 2 bits of the new state (sub_55D900 / sub_55DA50 / sub_55E320), plus sub_55EB30(v5) when the element flag bit 0x400000 is set.
    // LOOP: Outer traversal: iterate the UI element linked list; head read from this[129] (this+0x204), next element from element[4] (element+0x10). [field:this:0x00000204, source:raw]
    // ASSIGNMENT: For each element, load the state-entry array pointer v5 = element[71] (element+0x11C) and reset the per-element iteration index to 0. [source:raw]
    // GUARD: The per-element state loop only runs when the state entry count is greater than 0 (packet guard on this+0x32C; raw source reads the count at element[70], element+0x118). [guard:0, field:this:0x0000032C, source:raw]
    // CALCULATION: Rewrite the state entry: v7 = a2 | (~a3 & *v5), stored back into *v5. Bits set in a2 are forced on; bits set in a3 are cleared. [source:raw]
    // GUARD: Branch on bit 5: color/texture processing is selected when (a2 & 0x20) is nonzero. [source:raw]
    // CALCULATION: Derive a color word v8 from the global color counter at dword_8B8F28 + 432 by extracting, recombining and shifting its low bit fields. [global:0x008B8F28, source:raw]
    // CALL: SingleCallWrapper_e0e0(v5, 6) opens the color update on the state entry. [callee:0x0054E0E0, source:raw]
    // GUARD: The sub-element color loop only runs when the sub-element count (v5[2] at v5+8) is greater than 0 (packet guard on this+0x338). [guard:1, field:this:0x00000338, source:raw]
    // LOOP: For each sub-element at 64-byte stride starting at v5[8]+24: clear the color slot to 0xFF000000 then OR in the computed color v8. [source:raw]
    // CALCULATION: Advance the global color/texture counter at dword_8B8F28 + 432. [global:0x008B8F28, source:raw]
    // CALL: Wrapper_e0f0(v5, 4) finalizes the color update pass. [callee:0x0054E0F0, source:raw]
    // GUARD: Else branch: when bit 5 of a2 is clear and bit 5 of a3 is set, dispatch per-entry state-change callbacks selected by the low 2 bits of the new state v7. [source:raw]
    // CALL: When the low 2 bits of v7 are zero, call sub_55D900(0). [callee:0x0055D900, source:raw]
    // CALL: When the low 2 bits of v7 are 1, call sub_55DA50(0). [callee:0x0055DA50, source:raw]
    // CALL: When the low 2 bits of v7 are 2, call sub_55E320(0). [callee:0x0055E320, source:raw]
    // CALL: After a state-change dispatch, when the element flag bit (element[5] & 0x400000) is set, call sub_55EB30(v5). [callee:0x0055EB30, source:raw]
    // CALCULATION: Advance the state-entry pointer by 16 dwords (v5 += 16) and continue while the iteration index stays below the entry count (element[70], element+0x118). [source:raw]

    // Conservative worker pseudocode:
    //   void sub_54BDC0(_DWORD *this, int a2, int a3, int a4) {
    //     for (elem = this[129]; elem; elem = elem[4]) {
    //       entry = elem[71];
    //       for (n = 0; n < elem[70]; n++, entry += 16) {
    //         v = a2 | (~a3 & *entry);
    //         *entry = v;
    //         if (a2 & 0x20) {
    //           color = derive(dword_8B8F28 + 432);
    //           SingleCallWrapper_e0e0(entry, 6);
    //           for (s = 0; s < entry[2]; s++) {
    //             slot = entry[8] + 24 + s * 64;
    //             *slot = (*slot & 0xFF000000) | color;
    //           }
    //           ++*(_DWORD *)(dword_8B8F28 + 432);
    //           Wrapper_e0f0(entry, 4);
    //         } else if (a3 & 0x20) {
    //           if (v & 3) { (v & 1) ? sub_55DA50(0) : sub_55E320(0); }
    //           else sub_55D900(0);
    //           if (elem[5] & 0x400000) sub_55EB30(entry);
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: Packet field facts attribute several offsets (this+0x224, this+0x228, this+0x330, this+0x350, and the guard bases 0x32C/0x338) to `this`, but the decompiled text reaches the same data through the element pointer (element+0x10/+0x14/+0x118/+0x11C) and a global counter (dword_8B8F28+0x1B0). Base-object attribution of these offsets is unresolved; per raw source the color counter increment targets the global, contradicting the prose claim that this+0x330 is the counter.
    // UNRESOLVED: this+0x224, this+0x228 and this+0x350 are recorded as read during state processing; the prose attributes them to the callees (SingleCallWrapper_e0e0 / Wrapper_e0f0 / sub_55EB30). Which callee reads which field is not established from raw source.
    // UNRESOLVED: Semantics of the encoded color word v8 and the sub-element layout (64-byte stride, color slot at v5[8]+24) are not confirmed.
    // UNRESOLVED: Parameter a4 is unused in the decompiled body; its role is unknown.
}
