// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046B830
// Canonical corpus name: sub_46B830
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46B830_0046b830.c

void UnknownObject::VehicleTimeGapFormatter()
{
    // Formats a vehicle time gap or speed string for the FTIM timer display. For race-style sessions (session type 0-6) it scans the vehicle array for the leader vehicle, computes the lap-time gap to it, and writes an "MM:SS.fff" string into the caller's buffer. For session type 7 (qualifying/time-attack) it computes average speed from a distance counter, a track reference constant, and elapsed time, converts to metric or imperial via a global flag, and writes a "%6.2f" speed string.
    // ASSIGNMENT: Load the vehicle pointer for slot a1 from the global vehicle-pointer array and initialize the output buffer by copying the default string asc_5C6A94 into a2. [source:raw, global:0x007C54F0, global:0x005C6A94]
    // GUARD: Proceed only when the slot's vehicle pointer is non-null and the global session type dword_7C56A4 is non-negative. [source:raw, global:0x007C56A4]
    // GUARD: Race-session branch: when session type is 6 or lower, and the vehicle's session-state field at offset 16484 is not 3, compute the gap to the leader. [source:raw]
    // GUARD: Scan-guard: only run the leader search when the global vehicle count dword_5C329C is positive. [source:raw, global:0x005C329C]
    // LOOP: Linear scan over the vehicle array from index 0: find the first vehicle whose session-state field at offset 16480 equals 1 (leader). Return early without formatting when the count is exhausted. [source:raw, global:0x007C54F0]
    // GUARD: Leader pointer found and both the leader's lap time (offset 16540) and this vehicle's lap time (offset 16540) are positive before computing the gap. [source:raw]
    // CALCULATION: Compute the lap-time gap as v11 - v13 (this vehicle's time minus leader's time). [source:raw]
    // CALL: Call InterruptDispatch with the raw gap value. [source:raw, callee:0x0058957A]
    // CALCULATION: Convert the gap to whole minutes with CRTFtol of (gap * 0.016666668). [source:raw, callee:0x00587BDC]
    // CALL: Format the buffer as "%02.2d:%06.3f" with the minutes and the remaining gap seconds. [source:raw, callee:0x0058815F, global:0x005C6A7C]
    // GUARD: Time-attack branch: session type equals 7, vehicle session-state is 1, and the elapsed-time field at offset 16568 is positive. [source:raw]
    // CALCULATION: Compute speed as (distance counter at offset 16444 * track reference constant flt_5EA3FC) / elapsed time at offset 16568. [source:raw, global:0x005EA3FC]
    // CALCULATION: Convert speed by global unit flag byte_7D0474: metric multiply by 0.001, else imperial multiply by 0.0006213711922373339. [source:raw, global:0x007D0474]
    // CALL: Format the buffer as "%6.2f" with the converted speed scaled by 3600.0. [source:raw, callee:0x0058815F, global:0x005C6A8C]

    // Conservative worker pseudocode:
    //   void sub_46B830(int slot, char* out, int unused) {
    //     int v = gVehiclePtrs[slot];
    //     strcpy(out, defaultString_5C6A94);
    //     if (v && gSessionType >= 0) {
    //       if (gSessionType <= 6) {
    //         if (*(int*)(v + 16484) != 3) {
    //           if (gVehicleCount > 0) {
    //             int i = 0;
    //             while (*(int*)(gVehiclePtrs[i] + 16480) != 1) {
    //               if (++i >= gVehicleCount) return;
    //             }
    //             int lead = gVehiclePtrs[i];
    //             if (lead) {
    //               float tLead = *(float*)(lead + 16540);
    //               float tSelf = *(float*)(v + 16540);
    //               if (tLead > 0.0f && tSelf > 0.0f) {
    //                 float gap = tSelf - tLead;
    //                 InterruptDispatch(gap);
    //                 int minutes = CRTFtol(gap * 0.016666668);
    //                 SprintfChecked(out, "%02.2d:%06.3f", minutes, gap);
    //               }
    //             }
    //           }
    //         }
    //       }
    //       else if (gSessionType == 7 && *(int*)(v + 16484) == 1 && *(float*)(v + 16568) > 0.0f) {
    //         double speed = (double)*(int*)(v + 16444) * flt_5EA3FC / *(float*)(v + 16568);
    //         double conv = gMetricFlag ? speed * 0.001 : speed * 0.0006213711922373339;
    //         SprintfChecked(out, "%6.2f", conv * 3600.0);
    //       }
    //     }
    //   }
    // UNRESOLVED: Semantics of vehicle offsets 16480/16484 (session state codes), 16540 (lap time), 16568 (elapsed time) and 16444 (distance counter) are grounded only by this function's usage.
    // UNRESOLVED: Purpose of the InterruptDispatch call on the gap value is unclear.
    // UNRESOLVED: Global byte_7D0474 interpreted as metric/imperial flag; identity of the flag owner unknown.
    // UNRESOLVED: Globals flt_59E440, flt_59E9C0, dbl_59E9C8, dbl_59EA08, dbl_59FB48 and dbl_59FB50 are listed in the packet's global table but never referenced by the raw source.
}
