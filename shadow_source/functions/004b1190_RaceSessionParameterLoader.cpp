// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1190
// Canonical corpus name: sub_4B1190
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B1190_004b1190.c

void UnknownObject::RaceSessionParameterLoader()
{
    // Initializes race-session parameters (qualifying laps, race laps, race time) with default values that are clamped to per-parameter bounds, then, when the season races section is found, overrides them from string-keyed data entries, clamping and scaling the race laps and race time by a time multiplier a2. The section path comes from this+0x154 (falling back to global byte_5EA438). Recon-pit open/close values are also loaded into session globals.
    // ASSIGNMENT: Set the default qualifying laps at this+0x200C to 12 and clamp it into the bounds [this+0x2014, this+0x2018] [field:this:0x0000200C, field:this:0x00002014, field:this:0x00002018, source:raw]
    // ASSIGNMENT: Set the default race laps at this+0x2108 to 5 and clamp it into the bounds [this+0x2110, this+0x2114] [field:this:0x00002108, field:this:0x00002110, field:this:0x00002114, source:raw]
    // ASSIGNMENT: Set the default race time at this+0x2204 to 15 and clamp it into the bounds [this+0x220C, this+0x2210] [field:this:0x00002204, field:this:0x0000220C, field:this:0x00002210, source:raw]
    // GUARD: Time multiplier a2 falls back to the stored float at this+0x2300 when <= 0, and is floored at 0.05 [field:this:0x00002300, source:raw]
    // ASSIGNMENT: Select the season-section path string from this+0x154, defaulting to the global byte_5EA438 when the pointer is null [field:this:0x00000154, global:0x005EA438, source:raw]
    // CALL: SeasonRacesSectionFinder(path) locates the races section; a non-null result gates all the parameter lookups below [callee:0x004C5840, source:raw]
    // CALL: StringKeyedLinkedListSearch on the QualifyLaps key (aQualifylaps), then DataEntryAccessor plus sub_587ECE extract the integer value; stored into this+0x200C and clamped to the bounds [callee:0x005679C0, callee:0x00567970, callee:0x00587ECE, global:0x005D231C, field:this:0x0000200C, field:this:0x00002014, field:this:0x00002018, source:raw]
    // CALL: StringKeyedLinkedListSearch on the RaceLaps key (aRacelaps), then DataEntryAccessor plus sub_587ECE extract the integer value; stored into this+0x2108, clamped, scaled by the multiplier via CRTFtol with a floor of 1, then clamped again [callee:0x005679C0, callee:0x00567970, callee:0x00587ECE, callee:0x00587BDC, global:0x005C7444, field:this:0x00002108, field:this:0x00002110, field:this:0x00002114, source:raw]
    // CALL: StringKeyedLinkedListSearch on the RaceTime key, then DataEntryAccessor plus sub_587ECE extract the integer value; stored into this+0x2204, clamped, rounded and scaled via CRTFtol(value*a2 + 0.5), then clamped again [callee:0x005679C0, callee:0x00567970, callee:0x00587ECE, callee:0x00587BDC, field:this:0x00002204, field:this:0x0000220C, field:this:0x00002210, source:raw]
    // CALL: StringKeyedLinkedListSearch on the recon-pit-open key, then DataEntryAccessor plus sub_587ECE; the result is stored to a session global controlling the recon pit open window [callee:0x005679C0, callee:0x00567970, callee:0x00587ECE, source:raw]
    // CALL: StringKeyedLinkedListSearch on the recon-pit-closed key, then DataEntryAccessor plus sub_587ECE; the result is stored to a session global controlling the recon pit close window [callee:0x005679C0, callee:0x00567970, callee:0x00587ECE, source:raw]
    // RETURN: Return the season-section result (non-null iff the data-load path was taken) [source:raw]
    // CALL: Invoked by sub_4B0EF0 (004b0ef0) and sub_4C1050 (004c1050) [caller:0x004B0EF0, caller:0x004C1050]

    // Conservative worker pseudocode:
    //   clampDefault(this+0x200C, 12, this+0x2014, this+0x2018);
    //   clampDefault(this+0x2108, 5,  this+0x2110, this+0x2114);
    //   clampDefault(this+0x2204, 15, this+0x220C, this+0x2210);
    //   if (a2 <= 0.0) a2 = this+0x2300;
    //   if (a2 < 0.05) a2 = 0.05;
    //   path = this+0x154; if (!path) path = byte_5EA438;
    //   section = SeasonRacesSectionFinder(path);
    //   if (section) {
    //     e = StringKeyedLinkedListSearch(aQualifylaps);
    //     if (e) clampStore(this+0x200C, sub_587ECE(DataEntryAccessor(e)), this+0x2014, this+0x2018);
    //     e = StringKeyedLinkedListSearch(aRacelaps);
    //     if (e) { v = sub_587ECE(DataEntryAccessor(e));
    //               v = clamp(v, this+0x2110, this+0x2114); v = CRTFtol(v*a2); if (v<1) v=1;
    //               clampStore(this+0x2108, v, this+0x2110, this+0x2114); }
    //     e = StringKeyedLinkedListSearch(reconPitOpenKey);
    //     if (e) sessionGlobalOpen = sub_587ECE(DataEntryAccessor(e));
    //     e = StringKeyedLinkedListSearch(reconPitClosedKey);
    //     if (e) sessionGlobalClosed = sub_587ECE(DataEntryAccessor(e));
    //     e = StringKeyedLinkedListSearch(raceTimeKey);
    //     if (e) { v = sub_587ECE(DataEntryAccessor(e));
    //               v = clamp(v, this+0x220C, this+0x2210); v = CRTFtol(v*a2 + 0.5);
    //               clampStore(this+0x2204, v, this+0x220C, this+0x2210); }
    //   }
    //   return section;
    // UNRESOLVED: flt_59E440, flt_59E448, flt_59E450 and unk_8AC368 are listed as read by the function but have no visible role in the source; likely FP constant loads (multiplier clamps) and a data neighbor the decompiler did not surface
    // UNRESOLVED: The RaceTime, recon-pit-open and recon-pit-closed string keys and their global write targets are not present in the packet evidence set, so those writes are only described generically
    // UNRESOLVED: The differing race-laps scaling (floor of 1) versus race-time scaling (round via +0.5) is preserved from source, but the semantic intent is inferred
}
