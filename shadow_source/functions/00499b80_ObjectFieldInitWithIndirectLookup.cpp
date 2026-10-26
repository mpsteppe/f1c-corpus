// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499B80
// Canonical corpus name: ObjectFieldInitWithIndirectLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectFieldInitWithIndirectLookup_00499b80.c

void UnknownObject::ObjectFieldInitWithIndirectLookup()
{
    // Constructor-style initializer. Stores parameter a2 into this+0x20 and zeroes this+0x0 and this+0x8. If a2 is non-null, reads two values through a two-level pointer indirection from a2+12 (offsets +28 into this+0x4 and +32 into this+0xC); otherwise this+0x4 is zeroed and this+0xC stays 0. Returns a2 if null, else the dereferenced a2+12 value. Called by ProfileIconDFTBmpDefaultIconLoader (00478020).
    // ASSIGNMENT: Store parameter a2 into this+0x20 [field:this:0x00000020]
    // ASSIGNMENT: Zero this+0x0 [field:this:0x00000000]
    // ASSIGNMENT: Zero this+0x8 [field:this:0x00000008]
    // GUARD: If a2 is non-null, populate this+0x4 and this+0xC via the indirect lookups; otherwise zero this+0x4 and leave this+0xC at 0 [source:raw, function:0x00499B80]
    // CALCULATION: Two-level indirect read: result = *(a2+12), then this+0x4 = *(result+28) [field:this:0x00000004, source:raw]
    // CALCULATION: Second indirect read: v3 = *(*(a2+12)+32) [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store v3 (0 when a2 is null) into this+0xC [field:this:0x0000000C]
    // ASSIGNMENT: When a2 is null, zero this+0x4 [field:this:0x00000004]
    // RETURN: Return a2 when null, otherwise the dereferenced a2+12 value [function:0x00499B80, source:raw]

    // Conservative worker pseudocode:
    //   this[8] = a2;
    //   this[0] = 0;
    //   this[2] = 0;
    //   if (a2) {
    //     this[1] = *(*(a2+12)+28);
    //     result = *(a2+12);
    //     v3 = *(result+32);
    //   } else {
    //     this[1] = 0;
    //   }
    //   this[3] = v3;
    //   return result;
    // UNRESOLVED: The object pointed to by a2+12 and the meaning of its +28 and +32 fields are unknown; the purpose of the copied values in this+0x4 and this+0xC is not resolvable from this packet
}
