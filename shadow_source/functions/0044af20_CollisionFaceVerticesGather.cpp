// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044AF20
// Canonical corpus name: CollisionFaceVerticesGather
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionFaceVerticesGather_0044af20.c

void UnknownObject::CollisionFaceVerticesGather()
{
    // Gathers six component values from three vertex-source pointers referenced by the input array a2 into the output buffer a1. Reads source 0 (deref of *(a2)) at offsets 0 and 8, source 1 (deref of *(a2+4)) at offsets 8 and 16, and source 2 (deref of *(a2+8)) at offset 16 and 0, writing them to a1[0..5]. Returns the source-2 pointer.
    // ASSIGNMENT: Write a1[0] from the first value of the first vertex source: dereference *(a2) and copy its first dword. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write a1[1] from the value at offset +8 of the first vertex source (*(*(_DWORD*)a2 + 8)). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write a1[2] from the value at offset +8 of the second vertex source (*(*(_DWORD*)(a2+4) + 8)). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write a1[3] from the value at offset +16 of the second vertex source (*(*(_DWORD*)(a2+4) + 16)). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write a1[4] from the value at offset +16 of the third vertex source (*(*(_DWORD*)(a2+8) + 16)). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write a1[5] from the first value of the third vertex source: dereference the pointer stored at a2+8 and copy its first dword. [field:this:0x00000014, source:raw]
    // RETURN: Return the pointer to the third vertex source, which is the pointer value stored at a2+8. [function:0x0044AF20, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* CollisionFaceVerticesGather(_DWORD* out, int in) {
    //     out[0] = **(int**)in;
    //     out[1] = *(int*)(*(int*)in + 8);
    //     out[2] = *(int*)(*(int*)(in + 4) + 8);
    //     out[3] = *(int*)(*(int*)(in + 4) + 16);
    //     out[4] = *(int*)(*(int*)(in + 8) + 16);
    //     int* src2 = *(int**)(in + 8);
    //     out[5] = *src2;
    //     return src2;
    //   }
    // UNRESOLVED: The layout of the input array a2 (three vertex-source pointers) and the meaning of the component offsets +8 and +16 within each source are not evidenced.
    // UNRESOLVED: The output values are treated as raw dwords; whether they are vertex coordinates, indices, or other components is not evidenced.
    // UNRESOLVED: The function is a straight-line gather with no guards; whether a2 can alias a1 is unknown.
}
