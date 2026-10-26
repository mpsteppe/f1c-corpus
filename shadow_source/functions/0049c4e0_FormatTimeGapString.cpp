// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C4E0
// Canonical corpus name: sub_49C4E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C4E0_0049c4e0.c

void UnknownObject::FormatTimeGapString()
{
    // Formats a time gap between the race-state object behind dword_7C54E0 and a target object into a string written to the caller's a1 buffer. Copies a leading prefix into a1 first, then reads the target pointer from dword_7C54E0 + 16596. When the target is valid and LapTimeGapCalculation succeeds, a gap value v7 drives two formatting branches: v7 <= 0 renders a "+MM:SS.FFF" time string (via fabs + SpatialGridCell into the same buffer), otherwise v7 renders as " +N %s" where the pluralizer is chosen by off_5CCE74 vs aLaps_0 and is normalized through the string table in byte_5EC4CC. All paths return 0.
    // ASSIGNMENT: Copy the leading prefix string asc_5CCE54 into the destination buffer a1 via strcpy and keep the buffer pointer in v2 [global:0x005CCE54, source:raw]
    // GUARD: If the dword at dword_7C54E0 + 16484 is non-zero, return 0 immediately (suppression/debug flag blocks formatting) [global:0x007C54E0, source:raw]
    // ASSIGNMENT: v3 = *(dword_7C54E0 + 16596) reads the target object pointer that the gap is measured against [global:0x007C54E0, source:raw]
    // GUARD: Return 0 when the target pointer v3 is null, when *(v3 + 16484) is non-zero, or when LapTimeGapCalculation(dword_7C54E0, v3, (float*)&a1, &v7) reports failure [callee:0x0049B6D0, global:0x007C54E0, source:raw]
    // ASSIGNMENT: v4 = v7 captures the gap value for the later lap-count formatting branch [source:raw]
    // GUARD: Branch on v7 <= 0: the time-gap formatting path; otherwise the lap-count formatting path [source:raw]
    // CALL: Time path: take the absolute value of the float gap in the a1 buffer, then SpatialGridCell splits it into minutes/seconds components stored back into v7 and the a1 float buffer [callee:0x0049B630, source:raw]
    // CALL: Time path: StringFormatWithBufferOverflowCheck(v2, "+%.2d:%06.3f", v7, *(float*)&a1) renders the "+MM:SS.FFF" gap string into the destination buffer [callee:0x0058815F, source:raw]
    // ASSIGNMENT: Lap path: v5 = off_5CCE74 as the default pluralizer string, replaced by aLaps_0 when v7 != 1 [global:0x005CCE74, global:0x005CCE6C, source:raw]
    // CALL: Lap path: BinarySearchInStringTable(byte_5EC4C0, v5, byte_5EC4CC) looks the pluralizer up in the sorted string table; on a match v5 is copied into byte_5EC4CC, or byte_5EC4CC is cleared when v5 is null [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Lap path: StringFormatWithBufferOverflowCheck(v2, " +%d %s", v4, byte_5EC4CC) renders the " +N laps" gap string into the destination buffer [callee:0x0058815F, global:0x005EC4CC, source:raw]
    // RETURN: Every control-flow path returns 0 [source:raw]
    // CALL: Reached from sub_49D700 and DrawDebugTextOverlay as a HUD/overlay gap-string helper [caller:0x0049D700, caller:0x004DBB60, source:raw]

    // Conservative worker pseudocode:
    //   int sub_49C4E0(char* a1, int a2) {
    //     char* buf = strcpy(a1, asc_5CCE54);
    //     if (*(DWORD*)(dword_7C54E0 + 16484)) return 0;
    //     target = *(DWORD*)(dword_7C54E0 + 16596);
    //     if (!target || *(DWORD*)(target + 16484) || LapTimeGapCalculation(dword_7C54E0, target, (float*)&a1, &v7)) return 0;
    //     gap = v7;
    //     if (v7 <= 0) {
    //       *(float*)&a1 = fabs(*(float*)&a1);
    //       SpatialGridCell(*(float*)&a1, &v7, (float*)&a1);
    //       StringFormatWithBufferOverflowCheck(buf, "+%.2d:%06.3f", v7, *(float*)&a1);
    //     } else {
    //       s = off_5CCE74;
    //       if (v7 != 1) s = aLaps_0;
    //       if (BinarySearchInStringTable(byte_5EC4C0, s, byte_5EC4CC)) {
    //         if (s) strcpy(byte_5EC4CC, s); else byte_5EC4CC[0] = 0;
    //       }
    //       StringFormatWithBufferOverflowCheck(buf, " +%d %s", gap, byte_5EC4CC);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The packet declares globals 0x005CCE44 (a2d063f_0) and 0x005CCE78 (aDS_2) for this function, but the raw source text makes no explicit reference to either; they sit adjacent to the referenced literals in the 0x005CCE44..0x005CCE78 string block and may be consumed indirectly, so their role here is unresolved.
    // UNRESOLVED: The exact meaning of the two dword_7C54E0 offsets 16484 and 16596 (and the mirror offset 16484 on the target object) is only known by caller context; the raw source shows pointer arithmetic only.
    // UNRESOLVED: Whether the constant return 0 on all paths denotes success, failure, or a void-like convention is not evident from the raw source.
    // UNRESOLVED: The semantics of dword_7C54E0 + 16484 as a suppression flag and of the shared string-table buffer byte_5EC4CC are inferred from caller intent, not confirmed by this function alone.
}
