// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540DF0
// Canonical corpus name: sub_540DF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_540DF0_00540df0.c

void UnknownObject::DeviceBufferCreateFromDescriptor()
{
    // Creates a device vertex/index buffer by invoking the vtable method at byte offset 92 (slot 23) on the sub-object at this[1088] (byte offset 0x1100), driven by the descriptor a2. Builds a usage/format flag word from this[1102] (byte 0x1138) and a2[0] bits, computes a2[2]*a2[3] as a size, and passes a2[1], a mode argument and a2+8 as a trailing data pointer. Stores the returned handle in this[0]. Returns 0 on success; logs an invalid-parameter error for a null descriptor and an error-creating error when the handle is non-zero, both returning -1.
    // ASSIGNMENT: Initialize flags v3 = 0 and mode v4 = 0; when this[1102] (byte 0x1138) is zero set base usage flag 16. [source:raw, field:this:0x00001138]
    // GUARD: Guard on descriptor a2 non-null; when null log sub_53C590(-1, aInvalidParamet) and return -1. [source:raw, callee:0x0053C590, global:0x005DBCD0]
    // CALCULATION: Read v5 = a2[0]; descriptor bit 0x2 ORs usage 8 and bit 0x10 also ORs usage 8 into v3. [source:raw]
    // CALCULATION: Descriptor bit 0x20 inspects this[1272] (byte 0x13E0): value 0 sets mode v4 = 2 and ORs 0x200; value 1 ORs 0x210 and skips the 0x200; otherwise (value 2) ORs 0x200. [source:raw, field:this:0x000013E0]
    // CALL: Invoke the vtable method at byte offset 92 on *(this[1088]) (byte 0x1100) with (this[1088], a2[2] * a2[3], v3, a2[1], v4, a2 + 8). [source:raw, field:this:0x00001100, field:*(this+0x1100):0x0000005C]
    // ASSIGNMENT: Store the returned handle in this[0] (byte offset 0x0). [source:raw, field:this:0x00000000]
    // GUARD: Return 0 when the handle is zero (success). [source:raw]
    // CALL: Failure path: log sub_53C590(-1, aErrorCreatingV) and return -1 when the handle is non-zero. [source:raw, callee:0x0053C590, global:0x005DBD40]
    // CALL: Listed as the buffer-creation helper invoked by surface/vertex-buffer setup paths including TextureSurfaceAllocation and VertexBufferSurfaceInit. [caller:0x0053EB70, caller:0x00540940, caller:0x00541340, caller:0x005527C0, caller:0x00553370, caller:0x00558310]

    // Conservative worker pseudocode:
    //   int sub_540DF0(int* this, int* a2) {
    //     int flags = 0, mode = 0;
    //     if (!this[1102]) flags = 16;
    //     if (!a2) { sub_53C590(-1, aInvalidParamet); return -1; }
    //     if (a2[0] & 2) flags |= 8;
    //     if (a2[0] & 0x10) flags |= 8;
    //     if (a2[0] & 0x20) {
    //       int m = this[1272];
    //       if (m == 0) { mode = 2; flags |= 0x200; }
    //       else if (m == 1) flags |= 0x210;
    //       else flags |= 0x200;
    //     }
    //     int handle = (vtable_at(this[1088], 92))(this[1088], a2[2] * a2[3], flags, a2[1], mode, a2 + 8);
    //     this[0] = handle;
    //     if (!handle) return 0;
    //     sub_53C590(-1, aErrorCreatingV);
    //     return -1;
    //   }
    // UNRESOLVED: Semantic meaning of the usage/format flag bits (8, 0x200, 0x210, base 16) and the descriptor bit fields is not documented
    // UNRESOLVED: Meaning of the this[1272] mode values (0/1/2) that select between the 0x210 and 0x200 paths is unknown
    // UNRESOLVED: Identity of the vtable method at byte offset 92 (slot 23) on the sub-object is unnamed
}
