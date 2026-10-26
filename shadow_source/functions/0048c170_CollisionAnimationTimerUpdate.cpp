// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048C170
// Canonical corpus name: CollisionAnimationTimerUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionAnimationTimerUpdate_0048c170.c

void UnknownObject::CollisionAnimationTimerUpdate()
{
    // Advances a collision/animation timer accumulator at this+0x318. Returns -1 early when ByteFieldGetterAt100(this) reports a block flag or when the enable byte at this+0x304 is zero. Otherwise adds the external float value dereferenced from this+0x40 onto the accumulator, dampens the accumulator toward 0.75 (0.5*(v3-0.75) correction) when the FPU flags are clear, converts the running value via CRTFtol, and - when ShortComputation_6720 returns a positive count - dispatches that many calls through a __stdcall function pointer at receiver offset 184, passing the boolean (result == 4). Returns 0 on normal completion.
    // GUARD: Block guard: if ByteFieldGetterAt100(this) returns nonzero, return -1 immediately. [callee:0x00486710, source:raw]
    // GUARD: Enable guard: if the byte at this+0x304 is zero, return -1 immediately. [field:this:0x00000304, source:raw]
    // CALCULATION: Accumulate the timer: v3 = FloatFieldAccessor(*(this+0x40)) + *(this+0x318), then write *(this+0x318) = v3. [field:this:0x00000040, field:this:0x00000318, callee:0x00498730, source:raw]
    // GUARD: If the FPU status flags (C0|C2) from the addition are set, return 0 early. [source:raw]
    // CALCULATION: Dampen the accumulator toward 0.75: *(this+0x318) = v3 - 0.5*(v3 - 0.75). [field:this:0x00000318, source:raw]
    // CALL: CRTFtol(v3) converts the running accumulator value to integer; the result is unused. [callee:0x00587BDC, source:raw]
    // GUARD: If ShortComputation_6720(this) returns true and its count output v7 is positive, run the dispatch loop. [callee:0x00486720, source:raw]
    // LOOP: Repeat v7 times: recompute ShortComputation_6720(this), then call a __stdcall function pointer loaded from receiver offset v10+184 with the boolean (result == 4). [callee:0x00486720, source:raw]
    // RETURN: Return 0 on normal completion; -1 is returned by either early block guard. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionAnimationTimerUpdate(int this) {
    //     if (ByteFieldGetterAt100((_BYTE*)this)) return -1;
    //     if (!*(_BYTE*)(this + 772)) return -1;
    //     v3 = FloatFieldAccessor((float*)*(_DWORD*)(this + 64)) + *(float*)(this + 792);
    //     *(float*)(this + 792) = v3;
    //     if (C0 || C2) return 0;
    //     *(float*)(this + 792) = v3 - 0.5f*(v3 - 0.75f);
    //     CRTFtol(v3);
    //     if (ShortComputation_6720(this) && v7 > 0) {
    //       do { v9 = ShortComputation_6720(this); (*(__stdcall fn)(v10 + 184))(v9 == 4); } while (--v8);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Read-only globals flt_59E450, flt_59E7FC and flt_59E908 are flagged by packet facts but never appear in the raw decompiled source.
    // UNRESOLVED: The indirect __stdcall target loaded from receiver offset 184 is unknown; the receiver comes from ShortComputation_6720 output.
    // UNRESOLVED: The external float source dereferenced at this+0x40 and the enable/block flags are not type-defined by this packet.
    // UNRESOLVED: No static callers are recorded in the packet, so the call context is unknown.
}
