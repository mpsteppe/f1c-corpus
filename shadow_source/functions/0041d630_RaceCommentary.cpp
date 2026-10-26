// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041D630
// Canonical corpus name: RaceCommentary
// Owner: RaceCommentarySystem [DERIVED]
// Raw source: functions/RaceCommentary_0041d630.c

void RaceCommentarySystem::RaceCommentary()
{
    // Race commentary dispatcher. Guarded by a race-session flag and a nonzero clock float, it builds a track-intro commentary record by matching the active track-configuration name (struct pointer = dword_8AC490 + 396 * dword_8AC48C, name at +260) against 17 track-name literals, then iterates grid/standings positions v5=1..dword_5C329C, scans vehicle-slot pointers dword_7C54F0 for each position, counts retirements (status +16484 == 2), tracks the best lap-time car (+16540), emits player-relative commentary (start at 474, position change 459/460/461/397), and finally emits a wrap-up commentary (454/455/456/476) about retirements and the best-lap driver. Every record is built via DriverDataTableLookupAndTimeConversion and committed with InsertDriverTableEntry(flt_5EA618, ...).
    // GUARD: Entry guard: proceed only if race-session flag dword_7D0308 is set and float flt_7CF3C8 is nonzero. [source:raw, global:0x007D0308, global:0x007CF3C8]
    // CALL: Initialize local commentary-record buffer v20 with sentinel values via StructInitWithSentinelValues. [source:raw, callee:0x004144D0]
    // CALCULATION: Compute active track-configuration entry pointer: dword_8AC490 + 396 * dword_8AC48C (array base plus 396-byte stride times index). [source:raw, global:0x008AC490, global:0x008AC48C]
    // ASSIGNMENT: Initialize state: v0=-1, v17=1.0e16 (large best-time sentinel), v16=-1, v15=0 (retirement counter), v18=-1, v2=477 (default commentary id). [source:raw]
    // GUARD: If computed track-config pointer v1 is nonzero, take track-name string pointer at config offset +260 into v3. [source:raw]
    // CALL: sub_566810 compares config+260 string against 'Albert Park'; on match set commentary id 447. [source:raw, callee:0x00566810, global:0x005C26E0]
    // CALL: sub_566810 compares config+260 string against 'Interlagos'; on match set commentary id 450. [source:raw, callee:0x00566810, global:0x005C26D4]
    // CALL: sub_566810 compares config+260 string against 'Imola'; on match set commentary id 471. [source:raw, callee:0x00566810, global:0x005C26CC]
    // CALL: sub_566810 compares config+260 string against 'Monaco'; on match set commentary id 467. [source:raw, callee:0x00566810, global:0x005C26C4]
    // CALL: sub_566810 compares config+260 string against 'Barcelona'; on match set commentary id 472. [source:raw, callee:0x00566810, global:0x005C26B8]
    // CALL: sub_566810 compares config+260 string against 'Montreal'; on match set commentary id 452. [source:raw, callee:0x00566810, global:0x005C26AC]
    // CALL: sub_566810 compares config+260 string against 'Magny-Cours'; on match set commentary id 457. [source:raw, callee:0x00566810, global:0x005C26A0]
    // CALL: sub_566810 compares config+260 string against 'Silverstone'; on match set commentary id 451. [source:raw, callee:0x00566810, global:0x005C2694]
    // CALL: sub_566810 compares config+260 string against 'A1 Ring'; on match set commentary id 448. [source:raw, callee:0x00566810, global:0x005C2688]
    // CALL: sub_566810 compares config+260 string against 'Hockenheim'; on match set commentary id 458. [source:raw, callee:0x00566810, global:0x005C267C]
    // CALL: sub_566810 compares config+260 string against 'Hungaroring'; on match set commentary id 462. [source:raw, callee:0x00566810, global:0x005C2670]
    // CALL: sub_566810 compares config+260 string against 'Spa-Francorchamps'; on match set commentary id 449. [source:raw, callee:0x00566810, global:0x005C265C]
    // CALL: sub_566810 compares config+260 string against 'Monza'; on match set commentary id 463. [source:raw, callee:0x00566810, global:0x005C2654]
    // CALL: sub_566810 compares config+260 string against 'Nurburgring'; on match set commentary id 453. [source:raw, callee:0x00566810, global:0x005C2648]
    // CALL: sub_566810 compares config+260 string against 'Sepang'; on match set commentary id 466. [source:raw, callee:0x00566810, global:0x005C2640]
    // CALL: sub_566810 compares config+260 string against 'Suzuka'; on match set commentary id 464. [source:raw, callee:0x00566810, global:0x005C2638]
    // CALL: sub_566810 compares config+260 string against 'Indianapolis'; on match set commentary id 473. [source:raw, callee:0x00566810, global:0x005C2628]
    // CALL: Build track-intro commentary record: DriverDataTableLookupAndTimeConversion(v20, track_commentary_id v2, -1, -1, -1, -1, -2.0, -2.0) with unused time params at -2.0. [source:raw, callee:0x004144F0]
    // CALL: Commit track-intro record: InsertDriverTableEntry(flt_5EA618, v20). [source:raw, callee:0x00418560, global:0x005EA618]
    // LOOP: Outer loop over grid/standings positions v5 from 1 through v19 (v19 = dword_5C329C, the active position count). [source:raw, global:0x005C329C]
    // LOOP: Inner scan v7=0..v4-1 over vehicle-slot pointers dword_7C54F0[v7] to locate the car whose index field at offset +16480 equals current position v5. [source:raw, global:0x007C54F0]
    // GUARD: When the matched vehicle's status field at +16484 equals 2 (retired/DNF), increment retirement counter v15 and record last-retired slot v18 = v7 and v0 = v16. [source:raw, global:0x007C54F0]
    // GUARD: Break inner scan when the current slot is the player's car (dword_7C54E8 set and equal to slot pointer) or v5 <= 6, and slot status != 2. [source:raw, global:0x007C54E8]
    // CALCULATION: Best-lap tracking: if candidate slot's lap-time float at +16540 is not -1.0 and is below current best v17, update v17, v0 and v16 to that slot. [source:raw, global:0x007C54F0]
    // CALL: Build position-change commentary record id v11 (397 default; 465 when v4==22 and slot index at +16480 == 22) with driver id from +18588 and position v5. [source:raw, callee:0x004144F0, global:0x007C54F0]
    // CALL: Commit position-change record: InsertDriverTableEntry(flt_5EA618, v20). [source:raw, callee:0x00418560, global:0x005EA618]
    // GUARD: Player-relative block: applies when dword_7C54E8 is set, equals the current slot pointer, and that slot's status at +16484 != 2. [source:raw, global:0x007C54E8]
    // CALL: If v5==1 and global dword_7D2DE8 is clear, build race-start commentary 474 and commit it to the driver table. [source:raw, global:0x007D2DE8, callee:0x004144F0, callee:0x00418560]
    // CALCULATION: v13 = position field at slot+16472; choose commentary id v14 = 459 when v5 > v13 (position gained), 460 when v5 <= v13 and v5 > 6, 397 when v5 == v13, else 461 when v5 < v13. [source:raw, global:0x007C54F0]
    // CALL: Build commentary record with id v14 and position v13, then commit it via InsertDriverTableEntry. [source:raw, callee:0x004144F0, callee:0x00418560, global:0x007C54F0]
    // GUARD: After the scan loop, if best-lap slot v0 >= 0, emit a wrap-up commentary record. [source:raw]
    // STATE_TRANSITION: Choose wrap-up commentary id from retirement counter v15: >1 retirements -> 454; exactly 1 with v18<0 -> 455; exactly 1 with v18>=0 -> 456; 0 retirements -> 476. Driver ids passed from slots at +18588 (v18 and/or v0). [source:raw, global:0x007C54F0]
    // CALL: Build final wrap-up commentary record via DriverDataTableLookupAndTimeConversion and commit it with InsertDriverTableEntry. [source:raw, callee:0x004144F0, callee:0x00418560, global:0x007C54F0]

    // Conservative worker pseudocode:
    //   if (dword_7D0308 && flt_7CF3C8 != 0.0) {
    //     StructInitWithSentinelValues(record);
    //     trackCfg = dword_8AC490 + 396 * dword_8AC48C;
    //     bestTime = 1.0e16; bestSlot = -1; retirements = 0; lastRetired = -1;
    //     commentId = 477;
    //     if (trackCfg && match(trackCfg+260, trackNameLiterals))
    //       commentId = <per-track id 447..473>;
    //     emit(commentId, -1,-1,-1,-1,-2.0,-2.0);
    //     for (pos = 1; pos <= dword_5C329C; pos++) {
    //       slot = find(dword_7C54F0, index == pos);
    //       if (slot.status == 2) { retirements++; bestSlot = v16; lastRetired = v7; }
    //       if (isPlayer(slot) && slot.status != 2) break;
    //       if (slot.lapTime != -1.0 && slot.lapTime < bestTime)
    //         { bestTime = slot.lapTime; bestSlot = v7; v16 = v7; }
    //       emit(positions == 22 ? 465 : 397, slot.driver, pos, -1,-1,-2.0,-2.0);
    //       if (isPlayer(slot)) {
    //         if (pos == 1 && !dword_7D2DE8) emit(474, ...);
    //         emit(459/460/461/397 by pos vs slot.position, slot.position, ...);
    //       }
    //     }
    //     if (bestSlot >= 0)
    //       emit(retirements > 1 ? 454 : retirements == 1 ? (lastRetired<0 ? 455 : 456) : 476, ...);
    //   }
    // UNRESOLVED: Semantic meaning of commentary ids 447-476 is DERIVED; mapping to actual audio/text resources is not established.
    // UNRESOLVED: Slot field offsets +16480/+16484/+16540/+16472/+18588 and config offset +260 are inferred from usage, not confirmed against a struct definition.
    // UNRESOLVED: Globals flt_59E440 and flt_59E670 are listed in the packet globals but are not referenced by the raw source; no operation uses them.
    // UNRESOLVED: Caller sub_46BF10 (0x0046BF10) is the only caller, but its invocation context and timing are unknown.
}
