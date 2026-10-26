// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456130
// Canonical corpus name: VectorCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VectorCopy_00456130.c

void UnknownObject::VectorCopy()
{
    // Three-component vector copy (__thiscall): when source a2 is non-null, copies three consecutive dwords from a2 into the destination struct at byte offsets 0x18, 0x1C and 0x20 (elements [6],[7],[8] of the dword view of this). Returns the third source dword a2[2], or a2 itself when the source is null. Matches the Vector_Copy ABI shape.
    // GUARD: Guard on a2: when the source pointer is null the copy is skipped and a2 is returned as-is. [source:raw, abi:lead]
    // ASSIGNMENT: Copy source dword 0 into destination byte offset 0x18 (this + 6). [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Copy source dword 1 into destination byte offset 0x1C (v3[1]). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Copy source dword 2 into destination byte offset 0x20 (v3[2]) and keep it as the return value. [field:this:0x00000020, source:raw]
    // RETURN: Return the third copied dword a2[2] (as a pointer-sized value), or a2 when the source was null. [source:raw, function:0x00456130]
    // CALL: Invoked by sub_457000 (0x00457000), sub_4572B0 (0x004572B0), CollisionResponseWithRandomPerturbation (0x00457A00), StateActivatedPositionSaveRestore (0x00457B00), F_2DTransformStructCopy (0x00457B60), sub_4585E0 (0x004585E0), sub_458DF0 (0x00458DF0), ComponentTransformInitializer (0x00459010) and sub_459330 (0x00459330) to populate a three-component transform/position field. [caller:0x00457000, caller:0x004572B0, caller:0x00457A00, caller:0x00457B00, caller:0x00457B60, caller:0x004585E0, caller:0x00458DF0, caller:0x00459010, caller:0x00459330, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_456130(_DWORD *dst, _DWORD *src) {
    //     if (!src) return src;
    //     dst[6] = src[0];
    //     dst[7] = src[1];
    //     dst[8] = src[2];
    //     return (_DWORD *)src[2];
    //   }
    // UNRESOLVED: Whether the copied triple at +0x18 is position, velocity or another 3D quantity depends on the owning struct, which is unknown here
    // UNRESOLVED: Why the caller receives the third source dword as the return value is not documented in this function
}
