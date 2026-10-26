// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C1050
// Canonical corpus name: sub_4C1050
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C1050_004c1050.c

void UnknownObject::SessionInitAndTrackLoad()
{
    // Initializes a race session once the session config is resolved: loads the track scene, resets the AI world, zeroes the dword at +0xB118, resets 103 entity entries (stride 109 dwords) setting the active flag at +0x1AC to 1, transitions session state for the remaining empty slots (stride 18624 bytes up to 1918272), clamps the game-state global dword_7D00EC from the value at +0xB14C, and copies the two path strings at +0xAF6C and +0xAF74 (registering the second into a global list). Returns 0.
    // CALL: FlagsGetter(this) reads the session flags. [callee:0x004C11D0, source:raw]
    // CALL: SessionConfigReader(flags) resolves the session configuration record. [callee:0x004C11E0, source:raw]
    // GUARD: All initialization runs only when the session config record is non-null. [source:raw]
    // ASSIGNMENT: Take the track path string from the config record, falling back to byte_5EA438 when it is empty. [global:0x005EA438, source:raw]
    // CALL: TrackSceneLoader(path) loads the track scene. [callee:0x004C55B0, source:raw]
    // CALL: AIW(0) resets the AI world. [callee:0x004C54F0, source:raw]
    // ASSIGNMENT: Zero the dword at index 11334 (byte offset +0xB118). [field:this:0x0000B118, source:raw]
    // CALL: sub_4C0850(this + 11227) initializes the entry at byte offset +0xAF6C. [callee:0x004C0850, field:this:0x0000AF6C, source:raw]
    // LOOP: For each of 103 entity entries (stride 109 dwords), set the dword at index 107 (byte offset +0x1AC) to 1 and call sub_4C0850 on the entry. [field:this:0x000001AC, callee:0x004C0850, source:raw]
    // CALL: ActiveEntityCounter(this) counts the active entities; adding 1 yields the first empty slot. [callee:0x004C1370, source:raw]
    // LOOP: For the remaining empty slots (stride 18624 bytes from the first empty slot up to 1918272), call SessionStateTransition(-1, 0) for each. [callee:0x004EF5A0, source:raw]
    // CALL: sub_4B1190((int)byte_7CE498, -1.0) configures the auto-load entry with -1.0. [callee:0x004B1190, global:0x007CE498, source:raw]
    // ASSIGNMENT: Copy the dword at index 11347 (byte offset +0xB14C) into the game-state global dword_7D00EC. [field:this:0x0000B14C, global:0x007D00EC, source:raw]
    // GUARD: Clamp dword_7D00EC into the range bounded by dword_7D00F4 (minimum) and dword_7D00F8 (maximum). [global:0x007D00EC, global:0x007D00F4, global:0x007D00F8, source:raw]
    // ASSIGNMENT: Read the path string at index 11227 (byte offset +0xAF6C), defaulting to byte_5EA438, and copy it with StringCopyWithBufferRealloc. [field:this:0x0000AF6C, global:0x005EA438, callee:0x00566650, source:raw]
    // ASSIGNMENT: Read the path string at index 11229 (byte offset +0xAF74), defaulting to byte_5EA438, and copy it with StringCopyWithBufferRealloc. [field:this:0x0000AF74, global:0x005EA438, callee:0x00566650, source:raw]
    // CALL: ShortComputation_5730(&dword_5EA5E8, path) registers the second path string (index 11229) against the global list. [callee:0x00415730, global:0x005EA5E8, field:this:0x0000AF74, source:raw]
    // RETURN: Return 0 after initialization (the config-record guard was the only exit condition; an empty record also returns 0). [source:raw]

    // Conservative worker pseudocode:
    //   char SessionInitAndTrackLoad(int* this) {
    //     if (!SessionConfigReader(FlagsGetter(this))) return 0;
    //     const char* track = *SessionConfigReader(FlagsGetter(this));
    //     if (!track) track = byte_5EA438;
    //     TrackSceneLoader(track);
    //     AIW(0);
    //     this[11334] = 0;
    //     sub_4C0850(this + 11227);
    //     for (int* e = this, n = 103; n; e += 109, --n) {
    //       e[107] = 1;
    //       sub_4C0850(e);
    //     }
    //     int firstEmpty = ActiveEntityCounter(this) + 1;
    //     if (firstEmpty < 103)
    //       for (int off = 18624 * firstEmpty; off < 1918272; off += 18624)
    //         SessionStateTransition(-1, 0);
    //     sub_4B1190((int)byte_7CE498, -1.0);
    //     dword_7D00EC = this[11347];
    //     if (dword_7D00EC < dword_7D00F4) dword_7D00EC = dword_7D00F4;
    //     else if (dword_7D00EC > dword_7D00F8) dword_7D00EC = dword_7D00F8;
    //     const char* p1 = this[11227]; if (!p1) p1 = byte_5EA438;
    //     StringCopyWithBufferRealloc(p1);
    //     const char* p2 = this[11229]; if (!p2) p2 = byte_5EA438;
    //     StringCopyWithBufferRealloc(p2);
    //     const char* p3 = this[11229]; if (!p3) p3 = byte_5EA438;
    //     ShortComputation_5730((int**)&dword_5EA5E8, (int)p3);
    //     return 0;
    //   }
    // UNRESOLVED: dword_7CE64C, dword_7CE668, dword_7D2E48 and unk_8AC368 are listed as accessed globals but do not appear in the raw source; their role is unknown.
    // UNRESOLVED: The exact meaning of the per-entity stride (109 dwords), the active flag at +0x1AC, and the SessionStateTransition(-1, 0) call depends on the session/entity array layout.
}
