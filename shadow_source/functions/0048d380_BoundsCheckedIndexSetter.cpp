// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D380
// Canonical corpus name: BoundsCheckedIndexSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundsCheckedIndexSetter_0048d380.c

void UnknownObject::BoundsCheckedIndexSetter()
{
    // Bounds-checked setter on a container object. Returns a2 unchanged; only if a2 >= 0 and a2 < item-count (this+0x328) is the selected index (this+0x338) overwritten with a2. The owning object class is unidentified (offsets 0x328/0x338 suggest a small menu/list widget rather than the vehicle struct).
    // GUARD: Accept only 0 <= a2 < count read from this+0x328 (this[202]); the index write is gated on this bounds check passing. [abi:lead, field:this:0x00000328, function:0x0048D380, source:raw]
    // ASSIGNMENT: this[206] (this+0x338) = a2: store the validated selected index. [field:this:0x00000338, source:raw]
    // RETURN: Return the original argument a2 unchanged, whether or not the write occurred. [function:0x0048D380, source:raw]

    // Conservative worker pseudocode:
    //   int SetSelectedIndexBounded(int index) {
    //       if (index >= 0 && index < this->itemCount)   // itemCount at this+0x328
    //           this->selectedIndex = index;             // selectedIndex at this+0x338
    //       return index;
    //   }
    // UNRESOLVED: Owning class and object type unknown; callers are absent from the packet (no static frame path).
    // UNRESOLVED: Semantics of count at +0x328 and selected index at +0x338 (menu/list selection) unconfirmed.
    // UNRESOLVED: No caller context to explain why the original argument is returned rather than the stored value.
}
