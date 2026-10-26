// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FE350
// Canonical corpus name: sub_4FE350
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FE350_004fe350.c

void UnknownObject::SessionWeatherDataInitializer()
{
    // __thiscall that initializes per-session weather, temperature and wetness state for a race-session data object. It builds a candidate list of session-type names (via SessionTypeNameLookup keyed on the global dword_7C56A4), searches the shared data-entry linked lists for the best matching session entry by a minutes/tick count, then reads 'conditions', track/on-path/off-path wetness, ambient temperature and track temperature entries, clamps the off-path wetness to be at least the on-path value, and finally builds a time-keyed linked list of weather snapshots (timestamp, ambient temp, wetness multiplier) starting from the selected session entry and walking the 'minute' entries. Returns -1 when no session entry is found, 0 on success.
    // ASSIGNMENT: Seed the default base wetness v49 = 0.3 and clear the candidate-name slots v52/v53. [source:raw]
    // CALL: Resolve session-name candidates: v51 = SessionTypeNameLookup(dword_7C56A4, 0) and v54 = SessionTypeNameLookup(7, 0). [callee:0x0042CE30, global:0x007C56A4, source:raw]
    // STATE_TRANSITION: Switch on dword_7C56A4 through jump table jpt_4FE397: session types map to up to two candidate session names, all resolved with SessionTypeNameLookup (v52/v53 slots of the (&v51)[0..3] candidate array). [global:0x004FE7A0, callee:0x0042CE30, global:0x007C56A4, source:raw]
    // LOOP: Scan the candidate-name array (&v51)[v6] for the first non-null slot (v6 in 0..3); StringKeyedLinkedListSearch on that name yields the matching data entry a2, which stops the scan. [callee:0x005679C0, source:raw]
    // RETURN: Return -1 when no data entry matched any candidate session name. [source:raw]
    // CALCULATION: Compute the tick cutoff v50 = CRTFtol(100.0 / flt_8ACF9C + 0.5), a frames-per-unit conversion used as the lower bound for entry selection. [callee:0x00587BDC, global:0x008ACF9C, source:raw]
    // CALL: Read the selected entry's count v8 = sub_587ECE(DataEntryAccessor(a2)) and clamp it to 100 when non-positive. [callee:0x00567970, callee:0x00587ECE, source:raw]
    // LOOP: Walk the linked list from a2 via ShortComputation_adb0, skipping entries whose StringPointerAccessor name equals the session name (sub_588410 match); select the entry whose count v12 is >= v50 and strictly below the running best v8. [callee:0x0049ADB0, callee:0x00499E20, callee:0x00588410, callee:0x00567970, callee:0x00587ECE, source:raw]
    // RETURN: Return -1 when no qualifying entry survived the best-fit scan. [source:raw]
    // ASSIGNMENT: Apply defaults: this+0x20, this+0x24, this+0x28 and this+0x2C = 0; this+0x30 = 20.0; this+0x34 = 22.0. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: Look up the aConditions entry; when present, v49 = WeatherNameWetnessMultiplier(DataEntryAccessor(...)) and sub_4FDE00(this, v49) applies the base wetness. [callee:0x005679C0, global:0x005D7028, callee:0x00567970, callee:0x004FE0D0, callee:0x004FDE00, source:raw]
    // CALL: Look up the aTrackwetness entry; when present, this+0x28 and this+0x2C are both set to WeatherSeverityGripMultiplier(DataEntryAccessor(...)). [callee:0x005679C0, global:0x005D7018, callee:0x00567970, callee:0x004FE1E0, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALL: Look up the aOnpathwetness entry; when present, this+0x28 = WeatherSeverityGripMultiplier(DataEntryAccessor(...)). [callee:0x005679C0, global:0x005D7008, callee:0x00567970, callee:0x004FE1E0, field:this:0x00000028, source:raw]
    // CALL: Look up the aOffpathwetness_0 entry; when present, this+0x2C = WeatherSeverityGripMultiplier(DataEntryAccessor(...)). [callee:0x005679C0, global:0x005D6FF8, callee:0x00567970, callee:0x004FE1E0, field:this:0x0000002C, source:raw]
    // GUARD: Clamp off-path wetness: when this+0x2C < this+0x28, set this+0x2C = this+0x28. [field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALL: Look up the aAmbienttemp entry; when present, this+0x30 = sub_4FE2B0(...) and this+0x34 = this+0x30 + 2.0. [callee:0x005679C0, global:0x005D6FEC, callee:0x00567970, callee:0x004FE2B0, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: Look up the aTracktemp entry; when present, this+0x34 = sub_4FE2B0(DataEntryAccessor(...)). [callee:0x005679C0, global:0x005D6FE0, callee:0x00567970, callee:0x004FE2B0, field:this:0x00000034, source:raw]
    // CALL: Allocate the head weather node (16 bytes via OperatorNewNhMallocWrapper, initialized by FloatArrayInitializer), store it at this+0x3C, then write node time 0, node ambient this+0x30 and node wetness v49, and set this+0x38 to the same node (head/tail cursor). [callee:0x00587C03, callee:0x004FC9A0, field:this:0x00000038, field:this:0x0000003C, field:*(this+0x38):0x0000000C, field:*(*(this+0x38)+0xC):0x00000000, field:*(*(this+0x38)+0xC):0x00000004, field:*(*(this+0x38)+0xC):0x00000008, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Choose the per-minute time scale v56 = flt_5EA408; when flt_5EA408 is below 16.0 or above 1024.0, fall back to 92.0. [global:0x005EA408, source:raw]
    // LOOP: Build the time-keyed weather snapshot chain from the aMinute entries: allocate a node per minute, copy the previous node's ambient/wetness into it, set its time from sub_58850F(DataEntryAccessor(...)) * 60.0 (later iterations scale by v56), refresh wetness from aConditions and ambient from aAmbienttemp, advance through ShortComputation_adb0, and stop at the off_5C330C terminator. [callee:0x005679C0, global:0x005D6FD8, global:0x005C330C, callee:0x0058850F, callee:0x00587C03, callee:0x004FC9A0, callee:0x004FE0D0, callee:0x004FE2B0, callee:0x0049ADB0, callee:0x00499E20, callee:0x00588410, field:*(this+0x38):0x00000004, field:*(this+0x38):0x00000008, field:*(this+0x38):0x0000000C, field:*(*(this+0x38)+0xC):0x00000000, field:*(*(this+0x38)+0xC):0x00000004, field:*(*(this+0x38)+0xC):0x00000008, field:this:0x00000038, source:raw]
    // CALL: Fallback when no aMinute entry exists: resolve the chain seed from StringKeyedLinkedListSearch(&off_5C330C) and continue the snapshot walk from there. [callee:0x005679C0, global:0x005C330C, source:raw]
    // RETURN: Return 0 on success. [source:raw]
    // CALL: Invoked by sub_4FCC30 and sub_4FE7C0 to initialize session weather data. [caller:0x004FCC30, caller:0x004FE7C0, source:raw]

    // Conservative worker pseudocode:
    //   int SessionWeatherDataInitializer(float* this, DWORD* a2) {
    //     float base_wetness = 0.3;
    //     char** cand = SessionTypeNameLookup(dword_7C56A4, 0);
    //     cand[1] = cand[2] = 0; cand[3] = SessionTypeNameLookup(7, 0);
    //     switch (dword_7C56A4) { /* fill cand[1]/cand[2] from SessionTypeNameLookup per session type * / }
    //     for (int i = 0; i < 4; i++) if (cand[i]) { a2 = StringKeyedLinkedListSearch(cand[i]); if (a2) break; }
    //     if (!a2) return -1;
    //     int lo = CRTFtol(100.0/flt_8ACF9C + 0.5);
    //     int best = sub_587ECE(DataEntryAccessor(a2)); if (best <= 0) best = 100;
    //     for (DWORD* n = a2; n = ShortComputation_adb0(n);) {
    //       if (!sub_588410(StringPointerAccessor(n), cand[i])) {
    //         int c = sub_587ECE(DataEntryAccessor(n)); if (c <= 0) c = 100;
    //         if (c >= lo && c < best) { a2 = n; best = c; }
    //       }
    //     }
    //     if (!a2) return -1;
    //     this[8]=this[9]=this[10]=this[11]=0; this[12]=20.0; this[13]=22.0;
    //     if (e=aConditions) base_wetness = WeatherNameWetnessMultiplier(DataEntryAccessor(e)), sub_4FDE00(this, base_wetness);
    //     if (e=aTrackwetness)  this[10]=this[11]=WeatherSeverityGripMultiplier(DataEntryAccessor(e));
    //     if (e=aOnpathwetness) this[10]=WeatherSeverityGripMultiplier(DataEntryAccessor(e));
    //     if (e=aOffpathwetness_0) this[11]=WeatherSeverityGripMultiplier(DataEntryAccessor(e));
    //     if (this[11] < this[10]) this[11] = this[10];
    //     if (e=aAmbienttemp) { this[12]=sub_4FE2B0(DataEntryAccessor(e)); this[13]=this[12]+2.0; }
    //     if (e=aTracktemp) this[13]=sub_4FE2B0(DataEntryAccessor(e));
    //     this[15] = FloatArrayInitializer(OperatorNewNhMallocWrapper(16));
    //     this[15][0]=0; this[15][4]=this[12]; this[15][8]=base_wetness; this[14]=this[15];
    //     float scale = flt_5EA408; if (scale < 16.0 || scale > 1024.0) scale = 92.0;
    //     DWORD* m = StringKeyedLinkedListSearch(aMinute);
    //     if (!m) m = StringKeyedLinkedListSearch(&off_5C330C);
    //     while (m) {
    //       for (double t = sub_58850F(DataEntryAccessor(m)) * 60.0; ; t = sub_58850F(DataEntryAccessor(m)) * scale) {
    //         DWORD* node = FloatArrayInitializer(OperatorNewNhMallocWrapper(16));
    //         *(this[14]+12) = node; node[4] = this[14][4]; node[8] = this[14][8];
    //         this[14] = node; node[0] = t; node[12] = 0;
    //         if (e=aConditions)  node[8] = WeatherNameWetnessMultiplier(DataEntryAccessor(e));
    //         if (e=aAmbienttemp) node[4] = sub_4FE2B0(DataEntryAccessor(e));
    //         m = ShortComputation_adb0(m);
    //         if (!m) break;
    //         if (!sub_588410(StringPointerAccessor(m), aMinute)) continue;
    //         if (sub_588410(StringPointerAccessor(m), &off_5C330C)) break;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Relationship between the this+0x38 (tail/cursor) and this+0x3C (first-node) pointers and the exact role of the *(this+0x3C)+4/+8 fields.
    // UNRESOLVED: Meaning of the off_5C330C terminator string and of sub_4FDE00's transformation of the base wetness value.
    // UNRESOLVED: Interpretation of the sub_58850F minute values and the 60.0 / v56 scaling mix inside the snapshot loop.
}
