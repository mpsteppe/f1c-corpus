// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046B5F0
// Canonical corpus name: FTIMTimerBitmapSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FTIMTimerBitmapSelector_0046b5f0.c

void UnknownObject::FTIMTimerBitmapSelector()
{
    // Builds the composite display string for an FTIM timer overlay entry for one vehicle. Fetches the vehicle pointer from dword_7C54F0 by index a2, formats the lap count and total/current lap pair with session-type awareness, copies the driver/vehicle name strings, selects an outline color string (red/green/grey) from a sub_42BDD0 state, and concatenates up to six 48-byte component buffers into the output buffer a3 separated by the path delimiter word_5C692C, skipping components that fail the this[0x17C] filter. Returns 1.
    // ASSIGNMENT: Clear the outline output buffer a4 to an empty string at entry. [source:raw]
    // ASSIGNMENT: Load the vehicle pointer for index a2 from the vehicle pointer array dword_7C54F0. [global:0x007C54F0]
    // CALL: Format the lap number (vehicle + 16480) as decimal into component buffer v17 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F]
    // CALL: Copy the first 47 characters of the vehicle name string (vehicle + 17952) into component buffer v18 via sub_587DD0 and null-terminate it. [callee:0x00587DD0]
    // CALL: Copy the first 47 characters of the second name string (vehicle + 18104) into component buffer v19 via sub_587DD0 and null-terminate it. [callee:0x00587DD0]
    // GUARD: Branch on session type dword_7C56A4 being 5 or 7 to choose the lap fraction format (%d/%s) versus plain lap format (%d). [global:0x007C56A4]
    // CALCULATION: Format the total race laps dword_8ACF8C into v16; when the sentinel 0x7FFFFFFF is present, use the asc_5C6A78 placeholder string instead of a number. [global:0x008ACF8C, global:0x005C6A78]
    // CALCULATION: Clamp the current lap (vehicle + 16444) to at least 0 and, when it exceeds the total and dword_7CE814 is clear, to the total lap count. [global:0x007CE814]
    // CALL: Format the current/total lap pair as "%d/%s" into component buffer v20 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F]
    // CALL: In the non-fraction branch, format the non-negative clamped current lap as "%d" into component buffer v20. [callee:0x0058815F]
    // CALL: Derive an outline-state selector from sub_42BDD0(a2, v21) minus 1 and strcpy the matching outline color string (aFtim14redoutli, aFtim14greenout, or aFtim14greyoutl) into the output buffer a4. [callee:0x0042BDD0, global:0x005C6A28, global:0x005C6A40, global:0x005C6A58]
    // CALL: Copy a 47-character slice into component buffer v22 via sub_46B830 and null-terminate it. [callee:0x0046B830]
    // LOOP: Concatenate the six 48-byte component buffers (v17, v18, v19, v20, v21, v22) into the output buffer a3, inserting the path delimiter word_5C692C between consecutive included components. [global:0x005C692C]
    // GUARD: Filter components: when this[0x17C] equals 1, only component indices 0, 1, and 4 are appended; otherwise all six components are appended. [field:this:0x0000017C, guard:0]
    // RETURN: Return 1 on success. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_46B5F0(void *this, int index, char *out, char *outline) {
    //     if (outline) *outline = 0;
    //     vehicle = dword_7C54F0[index];
    //     StringFormat(v17, "%d", vehicle->lap_number);
    //     sub_587DD0(v18, vehicle->name_a, 47); v18[47] = 0;
    //     sub_587DD0(v19, vehicle->name_b, 47); v19[47] = 0;
    //     if (dword_7C56A4 == 5 || dword_7C56A4 == 7) {
    //       total = dword_8ACF8C;
    //       cur = vehicle->lap_count;
    //       if (dword_8ACF8C == 0x7FFFFFFF) StringFormat(v16, asc_5C6A78);
    //       else StringFormat(v16, "%d", dword_8ACF8C);
    //       if (cur < 0) cur = 0;
    //       else if (cur > total && !dword_7CE814) cur = total;
    //       StringFormat(v20, "%d/%s", cur, v16);
    //     } else {
    //       StringFormat(v20, "%d", vehicle->lap_count < 0 ? 0 : vehicle->lap_count);
    //     }
    //     state = sub_42BDD0(index, v21) - 1;
    //     if (state == 0) strcpy(outline, aFtim14redoutli);
    //     else if (state == 1) strcpy(outline, aFtim14greenout);
    //     else if (state == 2) strcpy(outline, aFtim14greyoutl);
    //     sub_46B830(index, v22, 47);
    //     *out = 0;
    //     for (i = 0; i < 6; ++i) {
    //       if (this->mask != 1 || (i <= 1 || i == 4)) {
    //         if (out[0]) append_delimiter(out, word_5C692C);
    //         strcat(out, component[i]);
    //       }
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The exact use of globals aD_1 (0x005C3280), aDS_4 (0x005C6A70), and unk_5EC6D0 is not visible in the rendered Hex-Rays body even though the packet lists them as read globals; their role in the display-string assembly is unresolved.
    // UNRESOLVED: sub_42BDD0's return semantics (which value maps to red/green/grey) and sub_46B830's source fields are defined outside this packet.
    // UNRESOLVED: The vehicles at dword_7C54F0 are the active grid; the far-offset fields accessed on them (lap count at +16444/+16480, name strings at +17952/+18104) are named from existing analysis only.
}
