// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042BDD0
// Canonical corpus name: sub_42BDD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_42BDD0_0042bdd0.c

void UnknownObject::FormatVehicleRaceTimeDisplay()
{
    // Formats a vehicle timing line into the caller-supplied string buffer. In a race session (dword_7C56A4 == 7) it emits the vehicle's full race time (h:mm:ss.fff) when finished, otherwise the gap to the current leader expressed as +m:ss.fff time difference, +N laps, or a resolved label string; outside a race session it emits the raw session time (m:ss.fff) or the placeholder "--:--.---" when the stored time is negative. A final status field decides whether a retirement/out label is written through the string table (returning 3) or whether the function returns 0 without producing a status label.
    // GUARD: Invalid index guard: if a1 < 0 or a1 >= dword_5C329C, return 0 without writing the output string [global:0x005C329C, source:raw]
    // ASSIGNMENT: Resolve the vehicle pointer: v2 = dword_7C54F0[a1] [global:0x007C54F0, source:raw]
    // GUARD: Session branch: when dword_7C56A4 == 7 the race-time formatting path is taken; otherwise the session-time path [global:0x007C56A4, source:raw]
    // ASSIGNMENT: Race path setup: v4 = a2, clear *a2 to 0, read v5 = *(int*)(v2 + 16444) as the laps-completed counter [source:raw]
    // GUARD: Race formatting only proceeds when v5 > 0 and the status field *(int*)(v2 + 16484) == 1 [source:raw]
    // GUARD: Finished/leader branch: when *(int*)(v2 + 16480) == 1 format the vehicle's own race time; otherwise compute the gap to the leader [source:raw]
    // CALCULATION: Read the race time v23 = *(float*)(v2 + 16568) and convert it to whole hours: v21 = CRTFtol(v23 * 0.00027777778) [callee:0x00587BDC, source:raw]
    // CALL: InterruptDispatch(v23), then convert the hour remainder to minutes: v15 = CRTFtol((v23 - v21 * 3600.0) * 0.016666668) [callee:0x0058957A, callee:0x00587BDC, source:raw]
    // CALL: Format the finished race time: StringFormatWithBufferOverflowCheck(v4, "%d:%02.2d:%06.3f", v21, v15, v23) [callee:0x0058815F, source:raw]
    // LOOP: Linear scan of the vehicle array dword_7C54F0[0 .. dword_5C329C) for the first vehicle whose offset-16480 field equals 1 (the leader); if the scan exhausts the array, fall through to the LABEL_27 default [global:0x007C54F0, global:0x005C329C, source:raw]
    // ASSIGNMENT: When a leader pointer v7 is found, compute the lap difference v8 = *(int*)(v7 + 16444) - v5; the branch taken depends on whether v8 equals 1, is <= 0, or is greater than 1 [source:raw]
    // CALL: One-lap-down case: BinarySearchInStringTable(byte_5EC4C0, &off_5C330C, byte_5EC4CC); on success copy the off_5C330C label bytes into byte_5EC4CC until the NUL terminator [callee:0x00423A00, global:0x005EC4C0, global:0x005C330C, global:0x005EC4CC, source:raw]
    // CALL: Emit the one-lap label: StringFormatWithBufferOverflowCheck(a2, "+%d %s", 1, byte_5EC4CC) [callee:0x0058815F, global:0x005EC4CC, source:raw]
    // CALCULATION: Leader-behind-in-laps case: compute the time gap v13 = *(float*)(v2 + 16568) - *(float*)(v7 + 16568); call InterruptDispatch(v13); convert to minutes v14 = CRTFtol(v13 * 0.016666668) [callee:0x0058957A, callee:0x00587BDC, source:raw]
    // CALL: Emit the time gap: StringFormatWithBufferOverflowCheck(v4, "+%d:%06.3f", v14, v13) [callee:0x0058815F, source:raw]
    // CALL: Multiple-laps-down case: BinarySearchInStringTable(byte_5EC4C0, aLaps_1, byte_5EC4CC); on success copy the aLaps_1 label into byte_5EC4CC, then StringFormatWithBufferOverflowCheck(a2, "+%d %s", v8, byte_5EC4CC) [callee:0x00423A00, global:0x005EC4C0, global:0x005C32FC, global:0x005EC4CC, callee:0x0058815F, source:raw]
    // GUARD: LABEL_27 default for the race path: if the buffer is still empty (strlen(v4) == 0), write the placeholder via StringFormatWithBufferOverflowCheck(v4, "%s", "--:--.---") [callee:0x0058815F, source:raw]
    // ASSIGNMENT: Non-race session path: read the session time v20 = *(float*)(v2 + 16540) [source:raw]
    // GUARD: When v20 < 0.0, write the placeholder StringFormatWithBufferOverflowCheck(a2, "--:--.---"); otherwise format the raw session time [callee:0x0058815F, source:raw]
    // CALL: Valid session time path: InterruptDispatch(v20); v3 = CRTFtol(v20 * 0.016666668); StringFormatWithBufferOverflowCheck(a2, "%d:%06.3f", v3, v20) [callee:0x0058957A, callee:0x00587BDC, callee:0x0058815F, source:raw]
    // ASSIGNMENT: Read the final status field v16 = *(int*)(v2 + 16484) [source:raw]
    // GUARD: Status gate: if v16 != 3 and (dword_7C56A4 != 7 or v16 != 2), return 0; otherwise a status label is emitted [global:0x007C56A4, source:raw]
    // CALL: Status 3 (retired) case: v17 = off_5C3298; if BinarySearchInStringTable(byte_5EC4C0, off_5C3298, byte_5EC4CC) succeeds, copy v17 (or clear the buffer when null) into byte_5EC4CC; then strcpy(v4, byte_5EC4CC) and return 3 [callee:0x00423A00, global:0x005C3298, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Status 2 in a race session: resolve the failure category v19 = FailureCategoryNameLookup(*(int*)(v2 + 16488)); on a successful string-table lookup copy it (or clear when null) into byte_5EC4CC; then strcpy(v4, byte_5EC4CC) and return 3 [callee:0x004BB730, callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // RETURN: Function returns 0 when the vehicle index is out of range or the status gate is not satisfied, and 3 once a retirement/out status label has been emitted into the buffer [function:0x0042BDD0, source:raw]

    // Conservative worker pseudocode:
    //   if (a1 < 0 || a1 >= dword_5C329C) return 0;
    //   veh = dword_7C54F0[a1];
    //   *a2 = 0;
    //   if (dword_7C56A4 == 7) {
    //       laps = *(int*)(veh + 16444);
    //       if (laps > 0 && *(int*)(veh + 16484) == 1) {
    //           if (*(int*)(veh + 16480) == 1) {
    //               t = *(float*)(veh + 16568);
    //               hours = CRTFtol(t * 0.00027777778);
    //               InterruptDispatch(t);
    //               minutes = CRTFtol((t - hours * 3600.0) * 0.016666668);
    //               StringFormatWithBufferOverflowCheck(a2, "%d:%02.2d:%06.3f", hours, minutes, t);
    //           } else {
    //               for (i = 0; i < dword_5C329C; ++i)
    //                   if (*(int*)(dword_7C54F0[i] + 16480) == 1) break;
    //               if (i < dword_5C329C) {
    //                   leader = dword_7C54F0[i];
    //                   diff = *(int*)(leader + 16444) - laps;
    //                   if (diff == 1) {
    //                       if (BinarySearchInStringTable(byte_5EC4C0, &off_5C330C, byte_5EC4CC))
    //                           copy off_5C330C bytes into byte_5EC4CC up to NUL;
    //                       StringFormatWithBufferOverflowCheck(a2, "+%d %s", 1, byte_5EC4CC);
    //                   } else if (diff <= 0) {
    //                       gap = *(float*)(veh + 16568) - *(float*)(leader + 16568);
    //                       InterruptDispatch(gap);
    //                       gm = CRTFtol(gap * 0.016666668);
    //                       StringFormatWithBufferOverflowCheck(a2, "+%d:%06.3f", gm, gap);
    //                   } else {
    //                       if (BinarySearchInStringTable(byte_5EC4C0, aLaps_1, byte_5EC4CC))
    //                           copy aLaps_1 bytes into byte_5EC4CC up to NUL;
    //                       StringFormatWithBufferOverflowCheck(a2, "+%d %s", diff, byte_5EC4CC);
    //                   }
    //               }
    //           }
    //       }
    //       if (!strlen(a2)) StringFormatWithBufferOverflowCheck(a2, "%s", "--:--.---");
    //   } else {
    //       t = *(float*)(veh + 16540);
    //       if (t < 0.0) StringFormatWithBufferOverflowCheck(a2, "--:--.---");
    //       else {
    //           InterruptDispatch(t);
    //           m = CRTFtol(t * 0.016666668);
    //           StringFormatWithBufferOverflowCheck(a2, "%d:%06.3f", m, t);
    //       }
    //   }
    //   status = *(int*)(veh + 16484);
    //   if (status != 3 && (dword_7C56A4 != 7 || status != 2)) return 0;
    //   if (status == 3) {
    //       key = off_5C3298;
    //       if (BinarySearchInStringTable(byte_5EC4C0, key, byte_5EC4CC))
    //           copy key (or clear buffer when null) into byte_5EC4CC;
    //       strcpy(a2, byte_5EC4CC);
    //       return 3;
    //   } else {
    //       key = FailureCategoryNameLookup(*(int*)(veh + 16488));
    //       if (BinarySearchInStringTable(byte_5EC4C0, key, byte_5EC4CC))
    //           copy key (or clear buffer when null) into byte_5EC4CC;
    //       strcpy(a2, byte_5EC4CC);
    //       return 3;
    //   }
    // UNRESOLVED: The roles of the vehicle field offsets (16444 laps counter, 16480 leader/finished flag, 16484 status, 16488 failure-category id, 16540 session time, 16568 race time) are inferred from the decompiled read/format pattern only; the packet declares no fields
    // UNRESOLVED: Eleven read-only globals (flt_59E440, asc_59E9A4, flt_59E9B8, flt_59E9BC, flt_59E9C0, dbl_59E9C8, aS_4, aD022d063f, aD063f_0, aDS_5, aD063f) are flagged by packet facts but appear nowhere in the raw decompiled source
    // UNRESOLVED: The exact meaning of status values 2 and 3 (and their mapping to the off_5C3298 label versus the FailureCategoryNameLookup result) is inferred from the formatting output only
}
