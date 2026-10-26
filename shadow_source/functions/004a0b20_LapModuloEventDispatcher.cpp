// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0B20
// Canonical corpus name: sub_4A0B20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0B20_004a0b20.c

void UnknownObject::LapModuloEventDispatcher()
{
    // Dispatches in-race milestone events based on lap number modulo 5 and driver position. Called on lap completion. Event 13 is dispatched when the driver's data at +0x4894 matches the current player vehicle field at offset 18580 and lap % 5 == 1. Event 19 is dispatched when position is 1, lap >= 2, and (lap + 3) % 5 == 0 (i.e. lap % 5 == 2). Returns 0 in all paths.
    // ASSIGNMENT: Load lap number from this+0x403C into a local. [source:raw, field:this:0x0000403C]
    // GUARD: Dispatch context: this function is invoked on lap completion by LapCompletion. [caller:0x004BC4E0]
    // GUARD: First condition: this+0x4894 equals the value at current player vehicle (dword_7C54F0[dword_7C54DC]) + 18580, and lap % 5 == 1. [source:raw, field:this:0x00004894, global:0x007C54DC, global:0x007C54F0]
    // CALL: When the first condition holds, dispatch event 13 via sub_4D8760(13, 0). [callee:0x004D8760]
    // GUARD: Second condition: this+0x4060 (position) equals 1 and lap >= 2 and (lap + 3) % 5 == 0. [source:raw, field:this:0x00004060, guard:0]
    // CALL: When the second condition holds, dispatch event 19 via sub_4D8760(19, 0). [callee:0x004D8760]
    // RETURN: Return 0 regardless of whether either event was dispatched. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A0B20(int *a1) {
    //     int lap = a1[0x403C / 4];
    //     if (a1[0x4894 / 4] == *(int *)(dword_7C54F0[dword_7C54DC] + 18580) && lap % 5 == 1)
    //       sub_4D8760(13, 0);
    //     if (a1[0x4060 / 4] == 1 && lap >= 2 && (lap + 3) % 5 == 0)
    //       sub_4D8760(19, 0);
    //     return 0;
    //   }
    // UNRESOLVED: The global dword_8AD298 is listed in the packet globals but does not appear in the provided raw source text; its role in this function is unclear.
    // UNRESOLVED: The meaning of event IDs 13 and 19 and the semantic role of the compared field at vehicle offset 18580 depend on the event system and are not established here.
}
