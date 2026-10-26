// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005114D5
// Canonical corpus name: AudioVideoDecodeSubbandLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioVideoDecodeSubbandLoop_005114d5.c

void UnknownObject::AudioVideoDecodeSubbandLoop()
{
    // Marker-scanning loop that classifies a marker byte relative to a reference counter a2 and dispatches decoder states through a sub-object vtable. Initializes dispatcher state to 117 and current marker from this[94]; each iteration classifies the marker into category 1 (expected marker, break), 2 (skip and read next), or 3 (acceptable stop, return). On category 1, this[94] is reset to 0.
    // ASSIGNMENT: Read current marker v3 = a1[94] (+0x178). [field:this:0x00000178]
    // ASSIGNMENT: Write dispatcher state fields: obj+0x14 (+0x14) = 117, obj+0x18 (+0x18) = v3, obj+0x1C (+0x1C) = a2. [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C]
    // CALL: Dispatch through obj vtable entry +0x4 (obj = *a1, this+0x0) with argument -1. [field:obj:0x00000004, field:this:0x00000000]
    // GUARD: Marker classification: v3 < 192 gives category 2 (skip); v3 outside 208-215 or equal to ((a2+1)&7)+208 or ((a2+2)&7)+208 gives category 3; v3 equal to ((a2-1)&7)+208 or ((a2-2)&7)+208 gives category 2; otherwise category 1 (expected marker). [source:raw]
    // ASSIGNMENT: Per iteration write dispatcher state: obj+0x14 (+0x14) = 96, obj+0x18 (+0x18) = v3, obj+0x1C (+0x1C) = category v5. [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C]
    // CALL: Dispatch through obj vtable entry +0x4 with argument 4. [field:obj:0x00000004]
    // STATE_TRANSITION: Category 1: expected marker found, loop breaks. [source:raw]
    // RETURN: Category 3: return 1. [source:raw]
    // CALL: Category 2: call BitstreamTokenReader(a1) to read the next marker; if it returns false, return 0. [callee:0x005110FC]
    // ASSIGNMENT: Re-read marker v3 = a1[94] (+0x178) after skipping the token. [field:this:0x00000178]
    // STATE_TRANSITION: After the expected marker is found, reset a1[94] (+0x178) to 0 and return 1. [field:this:0x00000178]

    // Conservative worker pseudocode:
    //   char AudioVideoDecodeSubbandLoop(_DWORD *a1, int a2) {
    //     int v3 = a1[94];
    //     *(_DWORD*)(*a1 + 20) = 117;
    //     *(_DWORD*)(*a1 + 24) = v3;
    //     *(_DWORD*)(*a1 + 28) = a2;
    //     (*(void (__cdecl **)(_DWORD*, int))(*a1 + 4))(a1, -1);
    //     for (;;) {
    //       int v5;
    //       if (v3 < 192) v5 = 2;
    //       else if (v3 >= 208 && v3 <= 215 && v3 != ((a2+1)&7)+208 && v3 != ((a2+2)&7)+208) {
    //         if (v3 == ((a2-1)&7)+208 || v3 == ((a2-2)&7)+208) v5 = 2;
    //         else v5 = 1;
    //       } else v5 = 3;
    //       *(_DWORD*)(*a1 + 20) = 96;
    //       *(_DWORD*)(*a1 + 24) = v3;
    //       *(_DWORD*)(*a1 + 28) = v5;
    //       (*(void (__cdecl **)(_DWORD*, int))(*a1 + 4))(a1, 4);
    //       if (v5 == 1) break;
    //       if (v5 != 2) return 1;
    //       if (!BitstreamTokenReader(a1)) return 0;
    //       v3 = a1[94];
    //     }
    //     a1[94] = 0;
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of the dispatched states 117 (initial) and 96 (per-iteration) and the dispatch arguments -1 and 4 are not established by the evidence.
    // UNRESOLVED: The a2 reference-counter arithmetic and the meaning of the 208..215 marker range are DERIVED from the raw branch structure only.
    // UNRESOLVED: Role of this+0x0 (pointer to the dispatcher object) is a DERIVED reading from the raw dereferences.
    // UNRESOLVED: Category 2 (skip) is interpreted as an unexpected or out-of-range marker without independent confirmation.
}
