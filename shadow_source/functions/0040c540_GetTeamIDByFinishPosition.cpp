// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C540
// Canonical corpus name: GetTeamIDByFinishPosition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GetTeamIDByFinishPosition_0040c540.c

void UnknownObject::GetTeamIDByFinishPosition()
{
    // Reads the finish position of entry a1 from the dword_5F0738 table (dword index 4656 * a1), derives a target position by shifting it one place forward when a2 >= 0 or one place backward otherwise, clamps the target into [1, dword_5C329C], then scans the active-vehicle pointer table dword_7C54F0 for the car whose live position field (offset 16480) equals the target and returns that car's team-ID field (offset 18580). Returns 0 when no matching car is found. Invoked from CameraTargetRaceLeader.
    // ASSIGNMENT: Read the finish position of entry a1: v2 = dword_5F0738[4656 * a1]. [global:0x005F0738, source:raw]
    // CALCULATION: Select the target position: start with v4 = v2 - 1, then use v4 = v2 + 1 when a2 >= 0. [source:raw]
    // GUARD: Clamp the target into range: when v4 >= 1 cap it at 1 if it exceeds dword_5C329C; otherwise set v4 = dword_5C329C. [global:0x005C329C, source:raw]
    // LOOP: Scan the active-vehicle table dword_7C54F0 with index v5 while the live position field at dword_7C54F0[v5] + 16480 does not equal v4; if v5 reaches dword_5C329C, return 0 (no match). [global:0x007C54F0, global:0x005C329C, source:raw]
    // RETURN: On a match return the team-ID field at dword_7C54F0[v5] + 18580 of the car found at the target position. [global:0x007C54F0, source:raw]

    // Conservative worker pseudocode:
    //   int GetTeamIDByFinishPosition(int entry, int direction) {
    //     int pos    = dword_5F0738[4656 * entry];       // finish position of entry
    //     int target = (direction >= 0) ? pos + 1 : pos - 1;
    //     if (target >= 1) { if (target > dword_5C329C) target = 1; }
    //     else target = dword_5C329C;
    //     for (int i = 0; i < dword_5C329C; ++i) {
    //       if (*(int*)(dword_7C54F0[i] + 16480) == target)  // live position field
    //         return *(int*)(dword_7C54F0[i] + 18580);       // team ID of matched car
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: dword_5F0738 is a dword-indexed table with a stride of 4656 entries per index; its element layout beyond the finish-position value is not present in this packet.
    // UNRESOLVED: The vehicle fields at byte offsets 16480 and 18580 (position and team ID) carry no field evidence refs in this packet; their semantic names are inferred from the canonical name and the CameraTargetRaceLeader caller context.
    // UNRESOLVED: a2 is treated as a direction sign for the +/- 1 shift; whether it carries a wider semantic (such as a screen-side bias) is not determinable here.
}
