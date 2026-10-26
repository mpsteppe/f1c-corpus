// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456110
// Canonical corpus name: F_3VectorCopyToStruct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3VectorCopyToStruct_00456110.c

void UnknownObject::F_3VectorCopyToStruct()
{
    // Triple-dword copy (__thiscall): when source a2 is non-null, copies three consecutive dwords from a2 into the destination struct at byte offsets 0xC, 0x10 and 0x14 (elements [3],[4],[5] of the dword view of this). Returns the third source dword a2[2], or a2 itself when the source is null. Structural twin of TripleFieldSetter (0040acc6) per the cluster prelabel.
    // GUARD: Guard on a2: when the source pointer is null the copy is skipped and a2 is returned as-is. [source:raw]
    // ASSIGNMENT: Copy source dword 0 into destination byte offset 0xC (this + 3). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Copy source dword 1 into destination byte offset 0x10 (v3[1]). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Copy source dword 2 into destination byte offset 0x14 (v3[2]) and keep it as the return value. [field:this:0x00000014, source:raw]
    // RETURN: Return the third copied dword a2[2] (as a pointer-sized value), or a2 when the source was null. [source:raw, function:0x00456110]
    // CALL: Invoked by sub_457000 (0x00457000), sub_4572B0 (0x004572B0), F_2DTransformStructCopy (0x00457B60), sub_4585E0 (0x004585E0), SuspensionWheelForceCalculation (0x00459070) and sub_459330 (0x00459330) to seed a three-component destination field. [caller:0x00457000, caller:0x004572B0, caller:0x00457B60, caller:0x004585E0, caller:0x00459070, caller:0x00459330, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_456110(_DWORD *dst, _DWORD *src) {
    //     if (!src) return src;
    //     dst[3] = src[0];
    //     dst[4] = src[1];
    //     dst[5] = src[2];
    //     return (_DWORD *)src[2];
    //   }
    // UNRESOLVED: Meaning of the copied three-dword value (possibly a 3D vector stored at +0xC) depends on the owning struct, which is unknown here
    // UNRESOLVED: Why the caller receives the third source dword as the return value is not documented in this function
}
