// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054D030
// Canonical corpus name: SceneNodeChildrenClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneNodeChildrenClear_0054d030.c

void UnknownObject::SceneNodeChildrenClear()
{
    // __thiscall scene-node cleanup: when the bit 0x8000000 (bit 27) flag at this+0x14 is set, iterates this[70] (count at +0x118) child elements, freeing one audio resource per child via AudioResourceFree on the SoundManager global, then clears the 0x8000000 flag. Returns 0. If the flag is clear, or the count is not positive, the audio loop is skipped but the flag clear is still performed.
    // GUARD: Outer guard on this+0x14 bit 0x8000000: when clear, return 0 immediately without cleanup. [field:this:0x00000014, source:raw]
    // GUARD: Inner guard on this[70] (this+0x118) > 0: the child loop only runs when the count is positive. [field:this:0x00000118, guard:0, source:raw]
    // LOOP: do-while loop over the child count, advancing the element pointer by 64 bytes (this+0x11C base) each iteration. [field:this:0x00000118, field:this:0x0000011C, source:raw]
    // CALL: Call AudioResourceFree(dword_8B78A0, element) once per child to free its audio resource via the SoundManager global. [callee:0x00540CB0, global:0x008B78A0, source:raw]
    // ASSIGNMENT: Clear bit 0x8000000 in this+0x14, marking the cleanup done. [field:this:0x00000014, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_54D030(_DWORD* this) {
    //     if (this[5] & 0x8000000) {
    //       if ((int)this[70] > 0) {
    //         for (int i = 0; i < this[70]; i++)
    //           AudioResourceFree(dword_8B78A0, this[71] + i * 64);
    //       }
    //       this[5] &= ~0x8000000;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Child element type at this+0x11C with 64-byte stride is unidentified.
    // UNRESOLVED: Meaning of bit 0x8000000 in this+0x14 (active/dirty flag per existing analysis) is DERIVED, not confirmed.
    // UNRESOLVED: Role of global dword_8B78A0 (SoundManager candidate) relies on the callee contract.
    // UNRESOLVED: Why the flag bit is cleared even when the count is non-positive is not fully explained.
}
