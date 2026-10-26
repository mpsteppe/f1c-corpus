// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050CDFF
// Canonical corpus name: F_4x4MatrixTranspose
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4MatrixTranspose_0050cdff.c

void UnknownObject::MatrixTranspose4x4()
{
    // Transpose of a 4x4 float matrix (row-major, 16 floats at +0x00..+0x3C) written from a2 into a1. The six off-diagonal symmetric pairs are unconditionally swapped via temporaries; the four diagonal elements (+0x00, +0x14, +0x28, +0x3C) are copied only when a1 != a2, which makes the routine support in-place transposition. Returns a1 (the destination pointer).
    // ASSIGNMENT: Swap elements at +0x04 and +0x10: save a2+4 in v2, write a2+16 into a1+4, then write v2 into a1+16 (transpose pair (0,1)/(1,0)) [field:this:0x00000004, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Swap elements at +0x08 and +0x20: save a2+8 in v4, write a2+32 into a1+8, then write v4 into a1+32 (transpose pair (0,2)/(2,0)) [field:this:0x00000008, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Swap elements at +0x0C and +0x30: save a2+12 in v5, write a2+48 into a1+12, then write v5 into a1+48 (transpose pair (0,3)/(3,0)) [field:this:0x0000000C, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Swap elements at +0x18 and +0x24: save a2+24 in v6, write a2+36 into a1+24, then write v6 into a1+36 (transpose pair (1,2)/(2,1)) [field:this:0x00000018, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Swap elements at +0x1C and +0x34: save a2+28 in v7, write a2+52 into a1+28, then write v7 into a1+52 (transpose pair (1,3)/(3,1)) [field:this:0x0000001C, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Swap elements at +0x2C and +0x38: save a2+44 in v8, write a2+56 into a1+44, then write v8 into a1+56 (transpose pair (2,3)/(3,2)) [field:this:0x0000002C, field:this:0x00000038, source:raw]
    // GUARD: When a1 != a2 the diagonal elements are copied from a2 to a1; when a1 == a2 they are already in place (in-place transpose support) [source:raw, function:0x0050CDFF]
    // ASSIGNMENT: Copy the four diagonal elements +0x00, +0x14, +0x28, +0x3C from a2 to a1 inside the a1 != a2 guard [field:this:0x00000000, field:this:0x00000014, field:this:0x00000028, field:this:0x0000003C, source:raw]
    // RETURN: Return a1, the destination matrix pointer [source:raw, function:0x0050CDFF]

    // Conservative worker pseudocode:
    //   // Transpose a row-major 4x4 float matrix from a2 into a1; a1 == a2 transposes in place.
    //   v2 = *(float*)(a2 + 4);   *(float*)(a1 + 4)  = *(float*)(a2 + 16); *(float*)(a1 + 16) = v2;
    //   v4 = *(float*)(a2 + 8);   *(DWORD*)(a1 + 8)  = *(DWORD*)(a2 + 32); *(float*)(a1 + 32) = v4;
    //   v5 = *(float*)(a2 + 12);  *(DWORD*)(a1 + 12) = *(DWORD*)(a2 + 48); *(float*)(a1 + 48) = v5;
    //   v6 = *(float*)(a2 + 24);  *(DWORD*)(a1 + 24) = *(DWORD*)(a2 + 36); *(float*)(a1 + 36) = v6;
    //   v7 = *(float*)(a2 + 28);  *(DWORD*)(a1 + 28) = *(DWORD*)(a2 + 52); *(float*)(a1 + 52) = v7;
    //   v8 = *(float*)(a2 + 44);  *(DWORD*)(a1 + 44) = *(DWORD*)(a2 + 56); *(float*)(a1 + 56) = v8;
    //   if (a1 != a2) {
    //     *(DWORD*)a1       = *(DWORD*)a2;
    //     *(DWORD*)(a1 + 20) = *(DWORD*)(a2 + 20);
    //     *(DWORD*)(a1 + 40) = *(DWORD*)(a2 + 40);
    //     *(DWORD*)(a1 + 60) = *(DWORD*)(a2 + 60);
    //   }
    //   return a1;
    // UNRESOLVED: Owner object is unknown: a1/a2 are raw 16-float buffers with no vtable, subsystem, or string evidence; prelabel cluster_copy from the structural twin F_4x4MatrixMultiply (0050cbb6) is DERIVED, not proven
}
