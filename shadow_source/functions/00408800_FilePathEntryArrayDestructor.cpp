// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408800
// Canonical corpus name: FilePathEntryArrayDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilePathEntryArrayDestructor_00408800.c

void UnknownObject::FilePathEntryArrayDestructor()
{
    // Two-path destructor selected by flag a2. When (a2 & 2) is set, treats this as a pointer one DWORD past an array header: reads the element count from *(this - 1), walks the 200-byte-stride array in reverse calling ShortComputation_62a0 on each element, and frees the header block at this - 1. When (a2 & 2) is clear, treats this as a single element: calls ShortComputation_62a0 on this directly. On both paths, (a2 & 1) additionally triggers FreeWrapper_7bcf on the block; the function returns the base pointer it processed.
    // GUARD: Branch on flag (a2 & 2) != 0 selecting the array-header path over the single-element path. [source:raw]
    // CALCULATION: Read the array count v3 = *(this - 1), seed the reverse walk v5 = &this[50 * v3] and counter v6 = v3 - 1. [source:raw]
    // GUARD: Guard on (v3 - 1) >= 0; a zero or negative count skips the element loop. [source:raw]
    // LOOP: do-while over v3 elements: step the walk pointer back 200 bytes and call ShortComputation_62a0 on each element in reverse order. [source:raw, callee:0x004562A0]
    // GUARD: On the array path, branch on (a2 & 1) to decide whether to free the header block. [source:raw]
    // CALL: Free the array header block at this - 1 via FreeWrapper_7bcf. [source:raw, callee:0x00587BCF]
    // RETURN: Return the processed base pointer this - 1 on the array path. [source:raw]
    // CALL: Single-element path: call ShortComputation_62a0 on this. [source:raw, callee:0x004562A0]
    // GUARD: On the single-element path, branch on (a2 & 1) to decide whether to free this. [source:raw]
    // CALL: Free the single element block this via FreeWrapper_7bcf. [source:raw, callee:0x00587BCF]
    // RETURN: Return the processed base pointer this on the single-element path. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_408800(DWORD *this, char flags) {
    //     if (flags & 2) {
    //       int count = *(this - 1);
    //       char *p = (char *)(this - 1);
    //       char *cur = (char *)&this[50 * count];
    //       if (count - 1 >= 0) {
    //         int n = count;
    //         do { cur -= 200; ShortComputation_62a0(cur); --n; } while (n);
    //       }
    //       if (flags & 1) FreeWrapper_7bcf(p);
    //       return p;
    //     } else {
    //       ShortComputation_62a0(this);
    //       if (flags & 1) FreeWrapper_7bcf(this);
    //       return (char *)this;
    //     }
    //   }
    // UNRESOLVED: Meaning of ShortComputation_62a0 as the per-element/instance cleanup callback is unknown.
    // UNRESOLVED: Semantics of the 200-byte element stride (50 DWORDs) and the count header at this - 1 are unverified.
    // UNRESOLVED: Flag semantics for bits 0x1 and 0x2 are inferred from the two branches only.
    // UNRESOLVED: Owner object type is unidentified (no callers recorded in the packet).
}
