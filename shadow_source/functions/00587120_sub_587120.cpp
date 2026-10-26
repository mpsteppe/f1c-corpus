// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587120
// Canonical corpus name: sub_587120
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587120_00587120.c

void UnknownObject::sub_587120()
{
    // Buffer-copy helper on a __thiscall object: reads the requested size v4 from the in/out size pointer a3, requires FieldAccessor(this + 1) to exceed it, then calls BufferQueryReturnPtrSizeIfValid(&v7, &a3) to obtain a source buffer pointer v7 and an available size. Copies min(*a3, available) bytes into *a2 when the computed size is positive and *a2 is non-null, storing the copied size back into *a3 and returning 0; otherwise it nulls *a2 and *a3 and returns 1.
    // ASSIGNMENT: Read the requested size v4 from *a3. [source:raw]
    // GUARD: If FieldAccessor(this + 1) is greater than the requested size v4, jump to the failure path (LABEL_8). [callee:0x0053D880, source:raw]
    // CALL: Call BufferQueryReturnPtrSizeIfValid(&v7, &a3) to obtain the source buffer pointer v7 and the available size; a falsy (0) result jumps to the failure path. [callee:0x00587580, source:raw]
    // CALCULATION: Compute v5 as the smaller of the original requested size (*v3) and the available size (a3 as returned by the buffer query). [source:raw]
    // GUARD: Proceed only when the computed copy size v5 is positive and the destination *a2 is non-null. [source:raw]
    // ASSIGNMENT: Copy v5 bytes from the source buffer v7 into the destination *a2 (qmemcpy), store v5 back into *v3, and return 0 on success. [source:raw]
    // ASSIGNMENT: Failure path (LABEL_8): clear *a2 to 0, clear *v3 to 0, and return 1. [source:raw]

    // Conservative worker pseudocode:
    //   v4 = *a3;
    //   if (FieldAccessor(this + 1) > v4) goto fail;
    //   if (!BufferQueryReturnPtrSizeIfValid(&v7, &a3)) goto fail;
    //   v5 = min(*v3, a3);
    //   if (v5 > 0 && *a2) {
    //     qmemcpy(*a2, v7, v5);
    //     *v3 = v5;
    //     return 0;
    //   }
    //   fail:
    //     *a2 = 0; *v3 = 0; return 1;
    // UNRESOLVED: FieldAccessor(this + 1) reads the field at this+4 (this is a _DWORD pointer, so +1 element); its meaning as a size/capacity guard is inferred, not independently evidenced.
    // UNRESOLVED: The backing store that BufferQueryReturnPtrSizeIfValid reads from (which internal buffer of the object) is unresolved.
    // UNRESOLVED: The owning class of the this pointer is unknown, and no callers are recorded in the packet, so the invocation context is unresolved.
}
