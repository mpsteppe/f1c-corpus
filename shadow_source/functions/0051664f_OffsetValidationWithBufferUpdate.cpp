// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051664F
// Canonical corpus name: OffsetValidationWithBufferUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OffsetValidationWithBufferUpdate_0051664f.c

void UnknownObject::OffsetValidationWithBufferUpdate()
{
    // Validates a write request (offset a3, size a4) against an indexed buffer managed at a2 and returns the byte pointer at which the write lands. Three checks run in sequence. First a capacity guard: if a3+a4 exceeds the buffer capacity at a2+4, or a4 exceeds the max element size at a2+12, or the element array at a2+0 is null, an error (code 20) is dispatched through the error object a1's vtable. Second a position-window check against the current write position at a2+24 and the window length at a2+16: out-of-window requests force a reposition, dispatching sub_5164A6 (flag 1) when a pending-reprocess flag at a2+33 is set, erroring (code 68) when reprocess is disallowed at a2+34, then repositioning a2+24 either to a3 or to (a3+a4 minus window) clamped to zero, and finally dispatching sub_5164A6 (flag 0). Third a written-position bound at a2+28: when a3+a4 exceeds it, the bound is extended to a3+a4 (when a5 is set, erroring with code 20 first if a3 is past the old bound), and if the zero-fill flag at a2+32 is set the gap elements are zero-filled via MemoryZeroFill with element size (a2+8)<<7. When a5 is set the pending flag at a2+33 is raised and the resulting pointer is returned; otherwise errors on out-of-bounds writes.
    // CALCULATION: Compute the requested end offset v6 = a3 + a4 [source:raw]
    // GUARD: Capacity/validity guard: error when a3+a4 exceeds the capacity at a2+4, or a4 exceeds the max element size at a2+12, or the element array at a2+0 is null [source:raw]
    // ASSIGNMENT: On the capacity/validity failure, write error code 20 into the error object at a1+0x14 [field:obj:0x00000014, source:raw]
    // CALL: Dispatch the failure: call the error object's vtable entry (the first dword of a1) with a1 as argument [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // GUARD: Position-window guard: the write is out of window when a3 is below the write position at a2+24, or v6 exceeds position plus window length at a2+16; the reposition path then runs [source:raw]
    // GUARD: When reprocess is disallowed (byte at a2+34 is zero), write error code 68 into a1+0x14 and dispatch it through the error object's vtable [field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // CALL: When the pending-reprocess flag at a2+33 is set, dispatch sub_5164A6(a2, a1, 1) and clear the flag at a2+33 [callee:0x005164A6, source:raw]
    // ASSIGNMENT: Reposition the write position at a2+24: when a3 is at or below the old position it becomes v6 minus the window length at a2+16 clamped to zero; otherwise it becomes a3 [source:raw]
    // CALL: Dispatch the reposition completion: sub_5164A6(a2, a1, 0) [callee:0x005164A6, source:raw]
    // GUARD: Written-position bound guard: the extend path runs only when the bound at a2+28 is below the requested end v6 [source:raw]
    // ASSIGNMENT: When the written bound at a2+28 is below the start a3: if a5 is set, write error code 20 into a1+0x14 and dispatch it, then adopt a3 as the new start; if a5 is set the bound at a2+28 is extended to v6 [field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // LOOP: When the zero-fill flag at a2+32 is set, walk every element index in [write position, v14) and zero-fill it through MemoryZeroFill with byte size (element stride at a2+8) shifted left by 7 [callee:0x005159A8, source:raw]
    // CALL: Per-gap-element zero-fill: MemoryZeroFill invoked with the element pointer (from a2+0 + 4*index) and the fixed fill size [callee:0x005159A8, source:raw]
    // STATE_TRANSITION: On the non-zero-fill path with a5 set, raise the pending-reprocess flag at a2+33 to 1 [source:raw]
    // RETURN: Compute and return the write pointer: element array base at a2+0 plus 4 times (a3 minus the write position at a2+24) [source:raw]
    // RETURN: When a5 is clear and the write is out of bounds at the written-position guard, write error code 20 into a1+0x14, dispatch it through the error object, and fall through to the pointer computation path [field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int end = a3 + a4;
    //   if (end > *(dword*)(a2 + 4) || a4 > *(dword*)(a2 + 12) || !*(dword*)a2) {
    //     *(dword*)(*(dword*)a1 + 20) = 20; (*(void(__cdecl**)(int))*a1)(a1);
    //   }
    //   unsigned int pos = *(dword*)(a2 + 24);
    //   if (a3 < pos || end > pos + *(dword*)(a2 + 16)) {
    //     if (!*(byte*)(a2 + 34)) { *(dword*)(*(dword*)a1 + 20) = 68; (*(void(__cdecl**)(int))*a1)(a1); }
    //     if (*(byte*)(a2 + 33)) { sub_5164A6(a2, a1, 1); *(byte*)(a2 + 33) = 0; }
    //     if (a3 <= *(dword*)(a2 + 24)) { int n = (int)(end - *(dword*)(a2 + 16)); if (n < 0) n = 0; *(dword*)(a2 + 24) = n; }
    //     else *(dword*)(a2 + 24) = a3;
    //     sub_5164A6(a2, a1, 0);
    //   }
    //   unsigned int bound = *(dword*)(a2 + 28);
    //   if (bound < end) {
    //     if (bound < a3) { if (a5) { *(dword*)(*(dword*)a1 + 20) = 20; (*(void(__cdecl**)(int))*a1)(a1); } bound = a3; }
    //     if (a5) *(dword*)(a2 + 28) = end;
    //     if (*(byte*)(a2 + 32)) {
    //       unsigned int size = *(dword*)(a2 + 8) << 7;
    //       for (unsigned int i = *(dword*)(a2 + 24); i < end; ++i) MemoryZeroFill(*(void**)(*(dword*)a2 + 4 * i), size);
    //     } else if (!a5) { *(dword*)(*(dword*)a1 + 20) = 20; (*(void(__cdecl**)(int))*a1)(a1); }
    //   }
    //   if (a5) *(byte*)(a2 + 33) = 1;
    //   return *(dword*)a2 + 4 * (a3 - *(dword*)(a2 + 24));
    // UNRESOLVED: The buffer manager struct at a2 is typed only through its raw offsets (+4 capacity, +8 element stride, +12 max element size, +16 window length, +24 write position, +28 written bound, +32 zero-fill flag, +33 pending-reprocess flag, +34 reprocess-allowed flag); the enclosing class and element type are unestablished
    // UNRESOLVED: sub_5164A6's internal dispatch semantics (flag 1 vs flag 0) are not visible in this packet
    // UNRESOLVED: field:obj:0x00000000 and field:this:0x00000000 both resolve to the first dword of a1 but were extracted under different base labels; no distinct objects are evidenced
    // UNRESOLVED: The error dispatch at (**(void(__cdecl***)(int))a1)(a1) is a vtable call whose concrete handler is not evidenced here
}
