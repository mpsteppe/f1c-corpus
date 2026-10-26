// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D2A0
// Canonical corpus name: StringCopyWithFlagUnion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyWithFlagUnion_0055d2a0.c

void UnknownObject::StringCopyWithFlagUnion()
{
    // ORs parameter a3 into the flags dword at this+0x0, copies the NUL-terminated string at a2 into the destination buffer at this+88 (offset 0x58) using the mapping v5 = this+88-a2, then stores the SceneStateSetup(dword_8B78A0, a3) result into this+0x4 and returns 0. Unconditional; used for sound/scene property initialization from sub_545430.
    // ASSIGNMENT: OR parameter a3 into the flags dword at this+0x0 [field:this:0x00000000, source:raw]
    // LOOP: Byte-copy loop from a2 into the buffer at this+88 via offset v5 = this+88-a2; repeats until the copied byte v6 is zero [source:raw]
    // CALL: Call SceneStateSetup(dword_8B78A0, a3), passing the SoundManager global and the flag bits [callee:0x00541500, global:0x008B78A0, source:raw]
    // ASSIGNMENT: Store the SceneStateSetup result into this+0x4 [field:this:0x00000004, source:raw]
    // RETURN: Return 0 [source:raw]
    // CALL: Called by sub_545430 (0x00545430) [caller:0x00545430]

    // Conservative worker pseudocode:
    //   *(_DWORD*)this |= a3;
    //   {
    //     char *src = a2;
    //     int v5 = this + 88 - a2;
    //     char c;
    //     do {
    //       c = *src;
    //       src[v5] = c;
    //       ++src;
    //     } while (c);
    //   }
    //   *((_DWORD*)this + 1) = SceneStateSetup(dword_8B78A0, a3);
    //   return 0;
    // UNRESOLVED: The destination field at this+88 (0x58) has no field evidence ref in this packet; the copy target is inferred from the raw source only
    // UNRESOLVED: Semantics of the dword_8B78A0 global (SoundManager) and of the SceneStateSetup result stored at this+0x4 are not evidenced in this packet
}
