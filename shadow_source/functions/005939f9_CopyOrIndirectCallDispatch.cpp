// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005939F9
// Canonical corpus name: sub_5939F9
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5939F9_005939f9.c

void UnknownObject::CopyOrIndirectCallDispatch()
{
    // Dispatch helper that either performs a bounded copy or invokes an indirect code pointer, selected by flags in the byte at a3 and the byte at a4. Early-returns on null/empty structures at a3+4 and a3+8. When bit 8 of *a3 is set it writes a single dword from a1+24 into *v5 and fixes it up through SEHFrameOffsetCalculationHelper. When *a4 bit 1 is clear it copies via sub_58B130 (plain copy when the code pointer at a4+24 is null, otherwise validated indirect call through that pointer under an interlocked/jump-table guard). When *a4 bit 1 is set it copies via sub_58B130 and, when the copied count is 4 and *v5 is nonzero, reapplies the SEH-frame offset fixup. Invalid read/write combinations fall through to SEHGuardedFunctionPointerCall.
    // GUARD: Read pointer at a3+4; when null, or when the byte at result+8 is zero, return that pointer value early. [source:raw]
    // GUARD: Read pointer at a3+8; when null, return it early. [source:raw]
    // CALCULATION: Compute destination v5 = (value at a3+8) + a2 + 12. [source:raw]
    // GUARD: Branch on bit 8 of the flag byte at a3: the single-dword fixup path is taken when set. [source:raw]
    // GUARD: Validate the source pointer at a1+24 (IsBadReadPtrWrapper) and destination v5 (IsBadWritePtrWrapper). [field:this:0x00000018, callee:0x00597321, callee:0x0059733D, source:raw]
    // ASSIGNMENT: Store the dword at a1+24 into *v5, then overwrite *v5 with SEHFrameOffsetCalculationHelper applied to that value against a4+8. [field:this:0x00000018, callee:0x00593C24, source:raw]
    // RETURN: When the bit-8 validation fails, return the result of SEHGuardedFunctionPointerCall. [callee:0x00593CFD, source:raw]
    // GUARD: Branch on bit 1 of the flag byte at a4 and on the code pointer at a4+24. [source:raw]
    // CALL: When the code pointer at a4+24 is null: copy via sub_58B130(v5, SEHFrameOffsetCalculationHelper(a1+24, a4+8), count at a4+20). [callee:0x0058B130, callee:0x00593C24, field:this:0x00000018, source:raw]
    // CALL: When a4+24 holds a validated code pointer (CodePointerValidation) and bit 4 of *a4 is set: run SEHFrameOffsetCalculationHelper, then LOCKUNLOCKAroundIndirectCallViaJumpTable(v5, a4+24). [callee:0x00597359, callee:0x00593C24, callee:0x0058A32A, source:raw]
    // CALL: When a4+24 holds a validated code pointer and bit 4 of *a4 is clear: run SEHFrameOffsetCalculationHelper, then AtomicLOCKUNLOCKWithIndirectCall(v5, a4+24). [callee:0x00597359, callee:0x00593C24, callee:0x0058A323, source:raw]
    // CALL: When bit 1 of *a4 is set: copy via sub_58B130(v5, source at a1+24, count at a4+20) after validating readability of a1+24 and writability of v5. [callee:0x0058B130, field:this:0x00000018, callee:0x00597321, callee:0x0059733D, source:raw]
    // GUARD: When the copied count at a4+20 equals 4 and *v5 is nonzero: apply SEHFrameOffsetCalculationHelper(*v5, a4+8) and store the result back into *v5. [callee:0x00593C24, source:raw]
    // RETURN: Failure paths (failed read/write validation) return the result of SEHGuardedFunctionPointerCall; success returns the copy result. [callee:0x00593CFD, function:0x005939F9, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_5939F9(int a1, int a2, int a3, int a4) {
    //     unsigned int r = *(unsigned int*)(a3 + 4);
    //     if (!r || !*(char*)(r + 8)) return r;
    //     r = *(unsigned int*)(a3 + 8);
    //     if (!r) return r;
    //     unsigned int *v5 = (unsigned int*)(r + a2 + 12);
    //     if (*(char*)a3 & 8) {
    //       if (IsBadReadPtrWrapper(*(void**)(a1 + 24)) && IsBadWritePtrWrapper(v5)) {
    //         unsigned int v6 = *(unsigned int*)(a1 + 24);
    //         *v5 = v6;
    //         *v5 = SEHFrameOffsetCalculationHelper(v6, a4 + 8);
    //         return *v5;
    //       }
    //       return SEHGuardedFunctionPointerCall();
    //     }
    //     if (!(*(char*)a4 & 1)) {
    //       void *src = *(void**)(a1 + 24);
    //       if (!*(unsigned int*)(a4 + 24)) {
    //         if (IsBadReadPtrWrapper(src) && IsBadWritePtrWrapper(v5))
    //           return sub_58B130((unsigned int)v5, SEHFrameOffsetCalculationHelper(*(unsigned int*)(a1 + 24), a4 + 8), *(unsigned int*)(a4 + 20));
    //         return SEHGuardedFunctionPointerCall();
    //       }
    //       if (IsBadReadPtrWrapper(src) && IsBadWritePtrWrapper(v5) && CodePointerValidation(*(FARPROC*)(a4 + 24))) {
    //         SEHFrameOffsetCalculationHelper(*(unsigned int*)(a1 + 24), a4 + 8);
    //         if (*(char*)a4 & 4) return LOCKUNLOCKAroundIndirectCallViaJumpTable((int)v5, *(unsigned int*)(a4 + 24));
    //         return AtomicLOCKUNLOCKWithIndirectCall((int)v5, *(unsigned int*)(a4 + 24));
    //       }
    //       return SEHGuardedFunctionPointerCall();
    //     }
    //     if (!IsBadReadPtrWrapper(*(void**)(a1 + 24)) || !IsBadWritePtrWrapper(v5))
    //       return SEHGuardedFunctionPointerCall();
    //     r = sub_58B130((unsigned int)v5, *(unsigned int*)(a1 + 24), *(unsigned int*)(a4 + 20));
    //     if (*(unsigned int*)(a4 + 20) == 4) {
    //       r = *v5;
    //       if (r) { r = SEHFrameOffsetCalculationHelper(r, a4 + 8); *v5 = r; }
    //     }
    //     return r;
    //   }
    // UNRESOLVED: The packet attributes globals ScriptFrameProcessor, stru_5B9968, and four TEB-relative byte globals, but the raw decompiled source shown here does not reference them; their role in this function is unresolved.
    // UNRESOLVED: Whether the a3/a4 flag bytes belong to a shared copy descriptor or to distinct caller-owned descriptors is not established.
    // UNRESOLVED: Semantics of sub_58B130 (assumed bounded copy) and of the interlocked indirect-call helpers are inferred from callee names and the copy/guard structure, not from independent evidence.
    // UNRESOLVED: Single known caller is MultiArgRenderingDispatchWithLayout (0x00593839); its argument layout is not examined in this packet.
}
