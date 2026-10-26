// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C03A0
// Canonical corpus name: AlternatingInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AlternatingInit_004c03a0.c

void UnknownObject::AlternatingInit()
{
    // Straight-line initializer that writes six alternating sentinel literals into this[0..5]: 0 at offsets 0x0/0x8/0x10/0x14 and 18446744073709551615 (i.e. -1) at offsets 0x4/0xC, then returns this. No reads, no globals, no guards, no calls. Called from PlayerCareerStatsGameOptionsLoader (004C18B0) and TrackSceneNodeAdd (004C28D0).
    // ASSIGNMENT: Sets field at offset 0x0 to 0: *this = 0 [field:this:0x00000000]
    // ASSIGNMENT: Sets field at offset 0x4 to the sentinel literal 18446744073709551615 (a -1 marker): this[1] = -1 [field:this:0x00000004]
    // ASSIGNMENT: Sets field at offset 0x8 to 0: this[2] = 0 [field:this:0x00000008]
    // ASSIGNMENT: Sets field at offset 0xC to the sentinel literal 18446744073709551615 (a -1 marker): this[3] = -1 [field:this:0x0000000C]
    // ASSIGNMENT: Sets field at offset 0x10 to 0: this[4] = 0 [field:this:0x00000010]
    // ASSIGNMENT: Sets field at offset 0x14 to 0: this[5] = 0 [field:this:0x00000014]
    // RETURN: Returns this (the initialized object) [function:0x004C03A0, source:raw]
    // CALL: Invoked from PlayerCareerStatsGameOptionsLoader (004C18B0) and TrackSceneNodeAdd (004C28D0) as a field-initialization step [caller:0x004C18B0, caller:0x004C28D0]

    // Conservative worker pseudocode:
    //   *this = 0;
    //   this[1] = -1;
    //   this[2] = 0;
    //   this[3] = -1;
    //   this[4] = 0;
    //   this[5] = 0;
    //   return this;
    // UNRESOLVED: The object type and the meaning of the alternating 0 / -1 pattern (e.g. active/inactive pair sentinels) are not evidenced
    // UNRESOLVED: The two callers (career-stats options loader and track-scene node addition) share no documented type relationship, so the ownership is ambiguous
}
