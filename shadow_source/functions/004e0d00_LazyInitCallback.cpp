// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E0D00
// Canonical corpus name: LazyInitCallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LazyInitCallback_004e0d00.c

void UnknownObject::LazyInitCallback()
{
    // One-time lazy initialization of a UI element. Guards on the a2 parameter block (NULL element or already-initialized flag at a2+64), then moves the element's doubly-linked-list node to the front, applies position and color values read from the a2 block, marks the element initialized, plays the UI activation sound effect via the sound index at this+0x964, and finally registers/updates the element in global lookup arrays against the global registry handle dword_5EA560 unless a global mode flag equals 2. Returns a helper result, the registry path result, or the initially read element pointer depending on the branch taken.
    // GUARD: Read the first dword of the a2 parameter block; if it is zero (no element), return that value immediately without initializing. [source:raw, function:0x004E0D00]
    // GUARD: When the initialized flag at a2+64 is non-zero, skip the initialization body and fall through to the return. [source:raw]
    // CALL: Move the element's doubly-linked-list node to the front of its list via DoublyLinkedListNodeMover, passing the element pointer and the constant 0. [callee:0x0054BA00, source:raw]
    // CALL: Apply position and color values read from the a2 block (six arguments at byte offsets +4, +8, +12, +16, +20, +24) to the element via sub_54B4D0. [callee:0x0054B4D0, source:raw]
    // ASSIGNMENT: Set the initialized flag at a2+64 to 1 so the initialization body runs only once. [source:raw]
    // CALL: Play the UI activation sound effect using the sound-effect index read from this at dword offset 601 (field this+0x964) via AudioSoundEffectController. [callee:0x004E0ED0, field:this:0x00000964, source:raw]
    // GUARD: When the global mode flag dword_8AB6E4 equals 2, skip the registry lookup tail. [source:raw]
    // LOOP: Otherwise scan up to three global lookup arrays for an entry whose first dword matches the element pointer: a 202-dword-stride array at unk_5EA5B0, a 198-dword-stride array at unk_5EA5BC and a third 198-dword-stride array at unk_5EA5C8, each with a +208 dword offset header; the arrays are indexed via the global registry handle dword_5EA560. [global:0x005EA560, source:raw]
    // CALL: On a match, if the matched entry's first value is not -1, update the registry entry through helper sub_410AF0 passing dword_5EA560 and the entry pointer; otherwise hand the entry to the registry lookup helper and return its result. [global:0x005EA560, source:raw]
    // RETURN: Return the dispatched helper result, the initially read element pointer, or the loop-index result depending on the branch taken. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4E0D00(void* this, void* a2) {
    //     int node = *(int*)a2;
    //     if (!node) return node;
    //     if (*(byte*)(a2 + 64)) return node;
    //     DoublyLinkedListNodeMover(node, 0);
    //     sub_54B4D0(*(int*)(a2+4), *(int*)(a2+8), *(int*)(a2+12),
    //                *(float*)(a2+16), *(float*)(a2+20), *(float*)(a2+24));
    //     *(byte*)(a2 + 64) = 1;
    //     AudioSoundEffectController(this[601]);
    //     // tail: registry lookup/update over up to three global arrays
    //     // using dword_5EA560 unless dword_8AB6E4 == 2
    //     return ...;
    //   }
    // UNRESOLVED: The registry lookup tail uses globals unk_5EA5A8, unk_5EA5B0, unk_5EA5AC, unk_5EA5B4, unk_5EA5B8, unk_5EA5BC, unk_5EA5C0, unk_5EA5C4 and unk_5EA5C8 plus dword_8AB6E4 and dword_8AB710 that are present in the raw source but absent from the packet's structured fact surface; their exact layout and meaning are unresolved.
    // UNRESOLVED: Semantics of the helper calls sub_410AF0, ArithmeticComparison_df90 and NestedLoopCall in the registry tail are unresolved.
    // UNRESOLVED: Meaning of the -1 entry sentinel and of the mode flag constant 2 is unresolved.
    // UNRESOLVED: Identity and purpose of the this object (only field this+0x964 read) are unknown.
    // UNRESOLVED: The exact layout of the a2 parameter block beyond the offsets used is unknown.
}
