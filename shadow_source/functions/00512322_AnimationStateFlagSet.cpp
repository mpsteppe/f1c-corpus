// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512322
// Canonical corpus name: AnimationStateFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AnimationStateFlagSet_00512322.c

void UnknownObject::AnimationStateFlagSet()
{
    // Sets bit 0x10 on the flags DWORD at offset 0x60 of the object when the animation-state byte at offset 0x117 equals 16. Returns the object pointer a1 unchanged.
    // ASSIGNMENT: Seed the return value with the object pointer a1. [source:raw]
    // GUARD: Guard: proceed only when the byte at this+0x117 equals 16 (animation-state value). [guard:0, field:this:0x00000117]
    // ASSIGNMENT: OR bit 0x10 into the flags DWORD at this+0x60, leaving all other bits intact. [field:this:0x00000060]
    // RETURN: Return the object pointer a1 regardless of whether the flag was set. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_512322(int obj) {
    //     if (*(BYTE *)(obj + 0x117) == 16)
    //       *(DWORD *)(obj + 0x60) |= 0x10;
    //     return obj;
    //   }
    // UNRESOLVED: Meaning of animation-state value 16 at this+0x117 (candidate: a specific animation phase) is not established.
    // UNRESOLVED: Meaning of flag bit 0x10 at this+0x60 (which animation behavior it enables) is unknown.
    // UNRESOLVED: Object type is unknown; caller sub_50210E (0x0050210E) owns the semantics.
}
