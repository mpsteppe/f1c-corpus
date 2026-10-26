// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041B980
// Canonical corpus name: TeamNameDisplayIDLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TeamNameDisplayIDLookup_0041b980.c

void UnknownObject::TeamNameDisplayIDLookup()
{
    // Matches the team-name string at offset +252 of the struct pointed to by a1 against a hardcoded chain of 44 season 1999-2002 team name constants via sub_566810. First match selects a numeric display ID (293-336); a sentinel-initialized float array v3 is then passed with that ID to DriverDataTableLookupAndTimeConversion, and the resolved driver data entry is inserted into the UI driver table at flt_5EA618 via InsertDriverTableEntry. Whole function gated on dword_7D0308 (race active), flt_7CF3C8 != 0.0, and a1 non-null. Called from UIRenderUpdateChain (0x00476D70); part of the UI team display system.
    // GUARD: Function body executes only if dword_7D0308 is non-zero (race active), flt_7CF3C8 is non-zero, and pointer parameter a1 is non-null; otherwise returns immediately. [global:0x007D0308, global:0x007CF3C8, function:0x0041B980, source:raw]
    // CALL: StructInitWithSentinelValues(v3) initializes the 8-float local array v3 with sentinel/default values before the driver lookup. [callee:0x004144D0, source:raw]
    // CALCULATION: v1 = a1 + 252: derives pointer to the team-name field (assumed string) at offset +252 of the struct pointed to by a1. [function:0x0041B980, source:raw]
    // GUARD: If sub_566810(v1, a1999Arrows) matches, display ID = 293. [callee:0x00566810, global:0x005C29A0, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Bar) matches, display ID = 294. [callee:0x00566810, global:0x005C2994, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Benetton) matches, display ID = 295. [callee:0x00566810, global:0x005C2984, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Ferrari) matches, display ID = 296. [callee:0x00566810, global:0x005C2974, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Jordan) matches, display ID = 297. [callee:0x00566810, global:0x005C2968, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Mclaren) matches, display ID = 298. [callee:0x00566810, global:0x005C2958, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Minardi) matches, display ID = 299. [callee:0x00566810, global:0x005C2948, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Prost) matches, display ID = 300. [callee:0x00566810, global:0x005C293C, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Sauber) matches, display ID = 301. [callee:0x00566810, global:0x005C2930, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Stewart) matches, display ID = 302. [callee:0x00566810, global:0x005C2920, source:raw]
    // GUARD: Else if sub_566810(v1, a1999Williams) matches, display ID = 303. [callee:0x00566810, global:0x005C2910, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Arrows) matches, display ID = 304. [callee:0x00566810, global:0x005C2904, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Bar) matches, display ID = 305. [callee:0x00566810, global:0x005C28F8, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Benetton) matches, display ID = 306. [callee:0x00566810, global:0x005C28E8, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Ferrari) matches, display ID = 307. [callee:0x00566810, global:0x005C28D8, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Jaguar) matches, display ID = 308. [callee:0x00566810, global:0x005C28CC, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Jordan) matches, display ID = 309. [callee:0x00566810, global:0x005C28C0, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Mclaren) matches, display ID = 310. [callee:0x00566810, global:0x005C28B0, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Minardi) matches, display ID = 311. [callee:0x00566810, global:0x005C28A0, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Prost) matches, display ID = 312. [callee:0x00566810, global:0x005C2894, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Sauber) matches, display ID = 313. [callee:0x00566810, global:0x005C2888, source:raw]
    // GUARD: Else if sub_566810(v1, a2000Williams) matches, display ID = 314. [callee:0x00566810, global:0x005C2878, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Arrows) matches, display ID = 315. [callee:0x00566810, global:0x005C286C, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Bar) matches, display ID = 316. [callee:0x00566810, global:0x005C2860, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Benetton) matches, display ID = 317. [callee:0x00566810, global:0x005C2850, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Ferrari) matches, display ID = 318. [callee:0x00566810, global:0x005C2840, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Jaguar) matches, display ID = 319. [callee:0x00566810, global:0x005C2834, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Jordan) matches, display ID = 320. [callee:0x00566810, global:0x005C2828, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Mclaren) matches, display ID = 321. [callee:0x00566810, global:0x005C2818, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Minardi) matches, display ID = 322. [callee:0x00566810, global:0x005C2808, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Prost) matches, display ID = 323. [callee:0x00566810, global:0x005C27FC, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Sauber) matches, display ID = 324. [callee:0x00566810, global:0x005C27F0, source:raw]
    // GUARD: Else if sub_566810(v1, a2001Williams) matches, display ID = 325. [callee:0x00566810, global:0x005C27E0, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Arrows) matches, display ID = 326. [callee:0x00566810, global:0x005C27D4, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Bar) matches, display ID = 327. [callee:0x00566810, global:0x005C27C8, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Ferrari) matches, display ID = 328. [callee:0x00566810, global:0x005C27B8, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Jaguar) matches, display ID = 329. [callee:0x00566810, global:0x005C27AC, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Jordan) matches, display ID = 330. [callee:0x00566810, global:0x005C27A0, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Mclaren) matches, display ID = 331. [callee:0x00566810, global:0x005C2790, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Minardi) matches, display ID = 332. [callee:0x00566810, global:0x005C2780, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Renault) matches, display ID = 333. [callee:0x00566810, global:0x005C2770, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Sauber) matches, display ID = 334. [callee:0x00566810, global:0x005C2764, source:raw]
    // GUARD: Else if sub_566810(v1, a2002Toyota) matches, display ID = 335. [callee:0x00566810, global:0x005C2758, source:raw]
    // GUARD: Else branch: if sub_566810(v1, a2002Williams) does NOT match, return immediately without inserting; if it matches, display ID = 336. [callee:0x00566810, global:0x005C2748, source:raw]
    // CALL: DriverDataTableLookupAndTimeConversion(v3, v2, -1, -1, -1, -1, -2.0, -2.0) resolves the driver data entry for the chosen display ID v2 into the sentinel-initialized v3 array, with default/unset time and lap arguments. [callee:0x004144F0, source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v3) inserts the resolved driver entry (v3) into the UI driver table at flt_5EA618. [callee:0x00418560, global:0x005EA618, source:raw]
    // RETURN: Implicit returns: exit without insertion when the gate fails, or when the team-name chain produces no match (a2002Williams also fails). [function:0x0041B980, source:raw]

    // Conservative worker pseudocode:
    //   void TeamNameDisplayIDLookup(int a1) {
    //       if (!dword_7D0308 || flt_7CF3C8 == 0.0f || !a1) return;
    //       float v3[8];
    //       StructInitWithSentinelValues(v3);
    //       int teamName = a1 + 252;
    //       int id;
    //       if      (sub_566810(teamName, a1999Arrows))   id = 293;
    //       else if (sub_566810(teamName, a1999Bar))      id = 294;
    //       ... // chain of 44 season 1999-2002 team-name matches, IDs 293-336
    //       else if (sub_566810(teamName, a2002Toyota))   id = 335;
    //       else if (!sub_566810(teamName, a2002Williams)) return; else id = 336;
    //       DriverDataTableLookupAndTimeConversion(v3, id, -1, -1, -1, -1, -2.0, -2.0);
    //       InsertDriverTableEntry(flt_5EA618, v3);
    //   }
    // UNRESOLVED: flt_59E440 (0x0059E440) is listed as a referenced global in the packet/skeleton but does not appear in the raw decompiled source; role unaccounted.
    // UNRESOLVED: sub_566810 (0x00566810) is used as a team-name string comparison (evidenced by team-name constants and the string-at-offset +252 usage), but its exact signature and return contract are not confirmed.
    // UNRESOLVED: The struct at a1+252 is treated as a team-name string field; exact field type and struct identity are unknown (packet field list is empty).
    // UNRESOLVED: DriverDataTableLookupAndTimeConversion and InsertDriverTableEntry are invoked with inferred data-flow (v3 as driver entry buffer); their full contracts are not confirmed.
    // UNRESOLVED: Literal arguments -1, -1, -1, -1, -2.0, -2.0 to DriverDataTableLookupAndTimeConversion are preserved as given but their semantic meaning is unknown.
}
