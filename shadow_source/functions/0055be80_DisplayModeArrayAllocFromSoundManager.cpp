// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BE80
// Canonical corpus name: sub_55BE80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55BE80_0055be80.c

void UnknownObject::DisplayModeArrayAllocFromSoundManager()
{
    // Allocates and fills an array of 292-byte display-mode structs from sound-manager entries. Clears the output list head/tail, prepares the sound manager with a3, then for each entry index up to the queried count allocates a struct via OperatorNewNhMallocWrapper, stores the index with DualFieldSetToSameValue, partially zero-initializes it, copies the entry's name string from the sound manager, records the index and zeroes two secondary fields, and registers the struct via DisplayModeEnumeratorWrapper. On zero-init failure it frees the partially built struct and returns the current count. Invoked by RenderUISystemGlobalInit during display/audio initialization.
    // ASSIGNMENT: Clear the output list state: *this = 0 and this[1] = 0. [field:this:0x00000000, field:this:0x00000004, function:0x0055BE80]
    // CALL: sub_53D970(dword_8B78A0, a3): prepare the sound manager referenced by dword_8B78A0 using a3. Called from RenderUISystemGlobalInit. [callee:0x0053D970, global:0x008B78A0, caller:0x0053C360]
    // ASSIGNMENT: Seed the entry counter v4 to 0. [source:raw]
    // CALL: result = FieldAccessor(dword_8B78A0): query the number of sound-manager entries. [callee:0x0053D880, global:0x008B78A0]
    // GUARD: If the queried entry count result is not greater than 0, skip the allocation loop entirely. [source:raw]
    // LOOP: for loop over each entry index v4 while v4 < entry count: build one display-mode struct and store it at this[v4 + 2]. [source:raw]
    // CALL: v7 = OperatorNewNhMallocWrapper(292): allocate a 292-byte display-mode struct. [callee:0x00587C03]
    // ASSIGNMENT: v8 = DualFieldSetToSameValue(v7, v4): store the entry index v4 into the struct; fall back to 0 when the allocation returned null. [callee:0x0055BB50]
    // ASSIGNMENT: Store the new struct pointer into the output array slot this[v4 + 2] (array at this+0x8). [field:this:0x00000008]
    // CALL: PartialStructZeroInit(v8): partially zero the struct; a non-zero return signals failure. [callee:0x0055BB70]
    // GUARD: If PartialStructZeroInit returned non-zero, break out of the loop to the cleanup path. [source:raw]
    // CALL: strcpy((char*)*i + 4, IndexedArrayAccess_d890(dword_8B78A0, v4) + 24): copy the name string from the v4-th sound-manager entry into the struct. [callee:0x0053D890, global:0x008B78A0]
    // ASSIGNMENT: (*i)[65] = v4; (*i)[66] = 0; (*i)[67] = 0: store the index at offset 0x104 and initialize the secondary fields at 0x108 and 0x10C to 0. [field:*(this+0x8):0x00000104, field:*(this+0x8):0x00000108, field:*(this+0x8):0x0000010C]
    // CALL: DisplayModeEnumeratorWrapper(*i): register or enumerate the completed display-mode struct. [callee:0x0055BBF0]
    // CALCULATION: Advance the counters: this[0] = this[0] + 1, this[1] = this[1] + 1 (byte-wise tail advance), and v4 = v4 + 1. [field:this:0x00000000, field:this:0x00000004]
    // CALL: result = FieldAccessor(dword_8B78A0): re-query the entry count to test the loop bound. [callee:0x0053D880, global:0x008B78A0]
    // GUARD: If v4 >= entry count, return result as the normal completion path. [source:raw]
    // RETURN: Return the last queried entry count. [source:raw]
    // CALL: Cleanup path after zero-init failure: EmptyStub_7470(this[v4 + 2]), FreeWrapper_7bcf(v10) on the struct, then clear this[v4 + 2] to 0. [callee:0x00557470, callee:0x00587BCF, field:this:0x00000008]

    // Conservative worker pseudocode:
    //   int sub_55BE80(DisplayModeList* this, int a2, int a3) {
    //     this->count = 0; this->tail = 0;
    //     sub_53D970(gSoundManager, a3);
    //     int idx = 0;
    //     int n = FieldAccessor(gSoundManager);
    //     if (n > 0) {
    //       for (; idx < n; ++idx) {
    //         DisplayMode* dm = (DisplayMode*)OperatorNewNhMallocWrapper(292);
    //         dm = dm ? DualFieldSetToSameValue(dm, idx) : 0;
    //         this->entries[idx] = dm;
    //         if (PartialStructZeroInit(dm)) break;
    //         strcpy((char*)dm + 4, IndexedArrayAccess_d890(gSoundManager, idx) + 24);
    //         dm[65] = idx; dm[66] = 0; dm[67] = 0;
    //         DisplayModeEnumeratorWrapper(dm);
    //         ++this->count; ++this->tail;
    //         n = FieldAccessor(gSoundManager);
    //         if (idx >= n) return n;
    //       }
    //       DisplayMode* bad = this->entries[idx];
    //       if (bad) { EmptyStub_7470(this->entries[idx]); FreeWrapper_7bcf(bad); }
    //       this->entries[idx] = 0;
    //     }
    //     return n;
    //   }
    // UNRESOLVED: Purpose of a2 is unused in the visible body and unknown.
    // UNRESOLVED: dword_8B78A0 is treated as a sound-manager handle; its concrete type is not proven.
    // UNRESOLVED: Relationship between this[1] tail counter and the array at this+0x8 is unverified.
}
