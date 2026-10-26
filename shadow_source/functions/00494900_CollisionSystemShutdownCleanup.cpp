// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494900
// Canonical corpus name: CollisionSystemShutdownCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionSystemShutdownCleanup_00494900.c

void UnknownObject::CollisionSystemShutdownCleanup()
{
    // Shutdown cleanup over six adjacent global handle slots (0x7CDE04..0x7CDE2C): for each of the three cascade-cleanup slots (0x7CDE0C, 0x7CDE18, 0x7CDE24) calls ResourceCascadeCleanup when non-zero then zeroes the slot; for each of the four destructor slot pairs (0x7CDE04/0x7CDE08, 0x7CDE10/0x7CDE14, 0x7CDE1C/0x7CDE20, 0x7CDE28/0x7CDE2C) runs DestructorWithConditionalFreeFlagClear, calls EmptyStub_7470 and FreeWrapper_7bcf on the cached pointer, then zeroes both slots. Returns the last cleanup result (defaulting to dword_7CDE24's prior value).
    // GUARD: If dword_7CDE0C is non-zero, call ResourceCascadeCleanup(dword_7CDE0C) and zero dword_7CDE0C. [global:0x007CDE0C, callee:0x005539F0, source:raw]
    // GUARD: If dword_7CDE04 is non-zero: run DestructorWithConditionalFreeFlagClear, call EmptyStub_7470(dword_7CDE04), free the cached pointer via FreeWrapper_7bcf, then zero dword_7CDE04 and dword_7CDE08. [global:0x007CDE04, global:0x007CDE08, callee:0x005502C0, callee:0x00557470, callee:0x00587BCF, source:raw]
    // GUARD: If dword_7CDE18 is non-zero, call ResourceCascadeCleanup(dword_7CDE18) and zero dword_7CDE18. [global:0x007CDE18, callee:0x005539F0, source:raw]
    // GUARD: If dword_7CDE10 is non-zero: run DestructorWithConditionalFreeFlagClear, call EmptyStub_7470(dword_7CDE10), free the cached pointer via FreeWrapper_7bcf, then zero dword_7CDE10 and dword_7CDE14. [global:0x007CDE10, global:0x007CDE14, callee:0x005502C0, callee:0x00557470, callee:0x00587BCF, source:raw]
    // GUARD: Seed result = dword_7CDE24; if non-zero, call ResourceCascadeCleanup(dword_7CDE24) and zero dword_7CDE24. [global:0x007CDE24, callee:0x005539F0, source:raw]
    // GUARD: If dword_7CDE1C is non-zero: run DestructorWithConditionalFreeFlagClear, call EmptyStub_7470(dword_7CDE1C), free the cached pointer via FreeWrapper_7bcf, then zero dword_7CDE1C and dword_7CDE20. [global:0x007CDE1C, global:0x007CDE20, callee:0x005502C0, callee:0x00557470, callee:0x00587BCF, source:raw]
    // GUARD: If dword_7CDE28 is non-zero: run DestructorWithConditionalFreeFlagClear, call EmptyStub_7470(dword_7CDE28), free the cached pointer via FreeWrapper_7bcf, then zero dword_7CDE28 and dword_7CDE2C. [global:0x007CDE28, global:0x007CDE2C, callee:0x005502C0, callee:0x00557470, callee:0x00587BCF, source:raw]
    // RETURN: Return the accumulated result value. [function:0x00494900, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionSystemShutdownCleanup() {
    //       if (dword_7CDE0C) { ResourceCascadeCleanup(dword_7CDE0C); dword_7CDE0C = 0; }
    //       if (dword_7CDE04) {
    //           DestructorWithConditionalFreeFlagClear();
    //           void *p0 = (void *)dword_7CDE04;
    //           if (dword_7CDE04) { EmptyStub_7470(dword_7CDE04); FreeWrapper_7bcf(p0); }
    //           dword_7CDE04 = 0; dword_7CDE08 = 0;
    //       }
    //       if (dword_7CDE18) { ResourceCascadeCleanup(dword_7CDE18); dword_7CDE18 = 0; }
    //       if (dword_7CDE10) {
    //           DestructorWithConditionalFreeFlagClear();
    //           void *p1 = (void *)dword_7CDE10;
    //           if (dword_7CDE10) { EmptyStub_7470(dword_7CDE10); FreeWrapper_7bcf(p1); }
    //           dword_7CDE10 = 0; dword_7CDE14 = 0;
    //       }
    //       int result = dword_7CDE24;
    //       if (dword_7CDE24) { result = ResourceCascadeCleanup(dword_7CDE24); dword_7CDE24 = 0; }
    //       if (dword_7CDE1C) {
    //           result = DestructorWithConditionalFreeFlagClear();
    //           void *p3 = (void *)dword_7CDE1C;
    //           if (dword_7CDE1C) { EmptyStub_7470(dword_7CDE1C); result = FreeWrapper_7bcf(p3); }
    //           dword_7CDE1C = 0; dword_7CDE20 = 0;
    //       }
    //       if (dword_7CDE28) {
    //           result = DestructorWithConditionalFreeFlagClear();
    //           void *p4 = (void *)dword_7CDE28;
    //           if (dword_7CDE28) { EmptyStub_7470(dword_7CDE28); result = FreeWrapper_7bcf(p4); }
    //           dword_7CDE28 = 0; dword_7CDE2C = 0;
    //       }
    //       return result;
    //   }
    // UNRESOLVED: dword_8AFE64 is listed as read (R) in the packet's globals but does not appear in the decompiled body; it is not consumed by any operation evidenced here.
    // UNRESOLVED: The distinction between ResourceCascadeCleanup slots (0x7CDE0C, 0x7CDE18, 0x7CDE24) and DestructorWithConditionalFreeFlagClear slots (0x7CDE04, 0x7CDE10, 0x7CDE1C, 0x7CDE28) is structural, not semantic: what each global holds is unevidenced beyond the two cleanup call families.
    // UNRESOLVED: The accumulated return value has no consumer evidenced in this packet.
}
