// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BE760
// Canonical corpus name: sub_4BE760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BE760_004be760.c

void UnknownObject::AIPerformanceSpeedCalc()
{
    // Computes an AI performance target speed into this+0x34C (init 600.0f) by scanning the live vehicle pointer array dword_7C54F0 (count dword_5C329C) in two passes. Pass one finds the nearest leader ahead (vehicle +16540 speed above 1.0, below the current best, slot state +13000 == 1); its value becomes v15 and this+0x360 == 7 selects a qualifying-performance source at vehicle +17604 instead of race source +17600 for the candidate v17. Pass two finds the next vehicle within 115% of v15 (speed above 0.0 and above v16, state 1); its source value becomes v4. When no valid distances are found (v16 <= 1.0 or v15 == v16, or v15 >= 9000.0) it falls back to season-config data: StringKeyedLinkedListSearch over off_5D2634[0] (a2 outside [3,5]) or off_5D2630[0], DataEntryAccessor, sub_58850F, then writes this+0x348 = a4, sets the this+0x342 activation byte, and blends this+0x34C by 15% toward the season value. Otherwise it derives the target by interpolation between the two lead vehicles and clamps it to a 97% floor of v15.
    // ASSIGNMENT: Initialize the AI target speed field this+0x34C to 600.0f (bit pattern 1142292480). [field:this:0x0000034C, source:raw]
    // ASSIGNMENT: Seed the scan locals: nearest-leader distance v15 = 99999.898, second-lead distance v16 = 0.0, candidate v17 = 0.0, target candidate v4 = 10.0. [source:raw]
    // LOOP: Pass one over the live vehicle pointer array dword_7C54F0, bounded by the vehicle count dword_5C329C. [global:0x007C54F0, global:0x005C329C, source:raw]
    // GUARD: Nearest-leader selection: a vehicle qualifies when its +16540 speed is above 1.0, below the current best v15, and its +13000 slot state equals 1; the winning speed becomes v15 and the candidate v17 is read from vehicle +17604 (qualifying) or +17600 (race) depending on this+0x360 == 7. [field:this:0x00000360, guard:0, source:raw]
    // GUARD: If no plausible leader distance was found (v15 >= 9000.0) skip pass two and jump to the season-config fallback. [source:raw]
    // LOOP: Pass two over the same vehicle array to find the next vehicle within 115% of v15 whose +16540 speed is above 0.0 and above v16, with slot state +13000 == 1; its speed becomes v16 and its +17600/+17604 value (selected by this+0x360 == 7) becomes the target candidate v4. [global:0x007C54F0, global:0x005C329C, field:this:0x00000360, guard:0, source:raw]
    // GUARD: Fallback trigger: when the second-lead speed v16 is at most 1.0 or equals v15, use the season-config path. [source:raw]
    // CALL: Season-config fallback: when a3 is non-NULL and SeasonRacesSectionFinder(a3) succeeds, StringKeyedLinkedListSearch picks the list off_5D2634[0] (a2 outside [3,5]) or off_5D2630[0] (a2 inside [3,5]); DataEntryAccessor(v12) resolves the entry and sub_58850F(v13) yields the target speed stored back into this+0x34C. [callee:0x004C5840, callee:0x005679C0, callee:0x00567970, callee:0x0058850F, global:0x005D2634, global:0x005D2630, field:this:0x0000034C, source:raw]
    // ASSIGNMENT: Fallback write-back: this+0x348 = a4, activation byte this+0x342 set to 1, then this+0x34C blended toward the season value: this+0x34C = 0.15000001 * this+0x34C * (1.0 - a4) + this+0x34C. [field:this:0x00000348, field:this:0x00000342, field:this:0x0000034C, source:raw]
    // CALCULATION: Distance-derived path: gap v10 = v17 - v4 clamped to a minimum of 0.0099999998, activation byte this+0x342 set to 1, target v11 = v15 - (v16 - v15) / v10 * (1.0 - v17) written to this+0x34C, then clamped to the floor v15 * 0.97000003 when lower. [field:this:0x00000342, field:this:0x0000034C, source:raw]

    // Conservative worker pseudocode:
    //   void AIPerformanceSpeedCalc(int this, int a2, int a3, float a4) {
    //     *(float*)(this+0x34C) = 600.0f;                  // 1142292480
    //     v15 = 99999.898f; v16 = 0.0f; v17 = 0.0f; v4 = 10.0f;
    //     if (dword_5C329C > 0) {
    //       // pass 1: nearest leader
    //       for (i = 0; i < dword_5C329C; ++i) {
    //         veh = dword_7C54F0[i];
    //         if (*(float*)(veh+16540) > 1.0f && *(float*)(veh+16540) < v15 && *(int*)(veh+13000) == 1) {
    //           v15 = *(float*)(veh+16540);
    //           v17 = (*(int*)(this+0x360) == 7) ? *(float*)(veh+17604) : *(float*)(veh+17600);
    //         }
    //       }
    //       if (v15 < 9000.0f) {
    //         // pass 2: second lead within 115%
    //         for (i = 0; i < dword_5C329C; ++i) {
    //           veh = dword_7C54F0[i];
    //           if (*(float*)(veh+16540) > 0.0f && *(float*)(veh+16540) > v16
    //               && v15 * 1.15f > *(float*)(veh+16540) && *(int*)(veh+13000) == 1) {
    //             v16 = *(float*)(veh+16540);
    //             v4 = (*(int*)(this+0x360) == 7) ? *(float*)(veh+17604) : *(float*)(veh+17600);
    //           }
    //         }
    //       }
    //     }
    //     if (v16 <= 1.0f || v15 == v16) {
    //       // fallback: season config
    //       if (a3 && SeasonRacesSectionFinder(a3)) {
    //         entry = (a2 < 3 || a2 > 5) ? StringKeyedLinkedListSearch(off_5D2634[0]) : StringKeyedLinkedListSearch(off_5D2630[0]);
    //         if (entry) *(float*)(this+0x34C) = sub_58850F(DataEntryAccessor(entry));
    //       }
    //       *(float*)(this+0x348) = a4;
    //       *(byte*)(this+0x342) = 1;
    //       *(float*)(this+0x34C) = 0.15000001f * *(float*)(this+0x34C) * (1.0f - a4) + *(float*)(this+0x34C);
    //     } else {
    //       // distance-derived target
    //       v10 = v17 - v4; if (v10 < 0.0099999998f) v10 = 0.0099999998f;
    //       *(byte*)(this+0x342) = 1;
    //       *(float*)(this+0x34C) = v15 - (v16 - v15) / v10 * (1.0f - v17);
    //       if (*(float*)(this+0x34C) < v15 * 0.97000003f) *(float*)(this+0x34C) = v15 * 0.97000003f;
    //     }
    //   }
    // UNRESOLVED: Ten read-only globals (flt_59E43C, flt_59E440, flt_59E444, flt_59E5FC, dword_5ACDAC, flt_5ACDB8, flt_5ACDC4, flt_5ACDC8, flt_5ACDCC, unk_8AC368) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them physics/frame-rate constants and setup values, all unverifiable from this packet
    // UNRESOLVED: The vehicle-source offsets +16540, +17600, +17604 and +13000 are accessed on dword_7C54F0 entries and are not packet field evidence, so their field identities remain unconfirmed
    // UNRESOLVED: The exact meaning of a2's [3,5] session range and of the qualifying/race split at this+0x360 == 7 depends on caller context
}
