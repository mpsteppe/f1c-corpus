// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004582E0
// Canonical corpus name: BufferAllocCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferAllocCopy_004582e0.c

void UnknownObject::KeyframeArrayDeepCopy()
{
    // Allocates a new keyframe array and deep-copies every element from a source described by a2 (pointer at a2[0], count at a2[1]). Proceeds only when the source pointer is non-null and the count is at least 4. Calls UtilityFunction_8020, stores the count into this[1], allocates 28*count + 4 bytes through OperatorNewNhMallocWrapper, stores the count in the header word and the payload pointer (header + 4) into this[0]. Then loops v3 over the count, resolving each source element through StridedArrayElementPointer (handles a source stride other than 28) and copying all 7 fields (dwords at +0,+4,+8,+12,+16,+20 and a float at +24) into the new buffer. Finally calls sub_457EE0 to recompute cumulative arc lengths. Returns this.
    // GUARD: When the source array pointer a2[0] is null the whole operation is skipped [source:raw]
    // GUARD: v5 = a2[1] reads the source element count; allocation and copy proceed only when v5 is at least 4 [source:raw]
    // CALL: UtilityFunction_8020(this) is invoked before the allocation [callee:0x00458020, source:raw]
    // ASSIGNMENT: this[1] = v5 stores the source count into the destination holder [field:this:0x00000004, source:raw]
    // CALL: OperatorNewNhMallocWrapper(28 * v5 + 4) allocates 4 header bytes plus 28 bytes per element; on success the header word *v6 receives the count and the payload v7 = v6 + 1 (else v7 = 0) is stored into this[0] [callee:0x00587C03, field:this:0x00000000, source:raw]
    // LOOP: For each index v3 below v5: StridedArrayElementPointer(v2, v3) resolves the source element pointer, and all 7 fields are copied into the new buffer at v9 = v11 + this[0] (dwords at +0,+4,+8,+12,+16,+20 and a float at +24); v3 increments and v11 advances by 28 per element [callee:0x004582A0, source:raw]
    // CALL: sub_457EE0((float *)this) recomputes the cumulative arc lengths over the freshly copied keyframe array [callee:0x00457EE0, source:raw]
    // RETURN: Returns this, the destination holder [function:0x004582E0, source:raw]
    // CALL: Invoked by sub_459330 [caller:0x00459330, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2[0]) return this;
    //   v5 = a2[1];
    //   if (v5 >= 4) {
    //     UtilityFunction_8020(this);
    //     this[1] = v5;
    //     v6 = OperatorNewNhMallocWrapper(28 * v5 + 4);
    //     this[0] = v6 ? v6 + 1 : 0;
    //     if (v6) *v6 = v5;
    //     for (v3 = 0, v11 = 0; v3 < v5; ++v3, v11 += 28) {
    //       v8 = StridedArrayElementPointer(a2, v3);
    //       v9 = v11 + this[0];
    //       *(DWORD*)v9       = *(DWORD*)(v8);
    //       *(DWORD*)(v9 + 4)  = *(DWORD*)(v8 + 4);
    //       *(DWORD*)(v9 + 8)  = *(DWORD*)(v8 + 8);
    //       *(DWORD*)(v9 + 12) = *(DWORD*)(v8 + 12);
    //       *(DWORD*)(v9 + 16) = *(DWORD*)(v8 + 16);
    //       *(DWORD*)(v9 + 20) = *(DWORD*)(v8 + 20);
    //       *(float*)(v9 + 24) = *(float*)(v8 + 24);
    //     }
    //     sub_457EE0((float*)this);
    //   }
    //   return this;
    // UNRESOLVED: What UtilityFunction_8020 initializes before the allocation is not established from this packet
    // UNRESOLVED: sub_457EE0's exact precompute semantics (cumulative arc length) come from the existing analysis prose, not from this packet's raw source
    // UNRESOLVED: The source stride handled by StridedArrayElementPointer is unspecified here; the copy assumes a fixed 28-byte destination element
}
