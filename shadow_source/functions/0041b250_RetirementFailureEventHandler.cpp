// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041B250
// Canonical corpus name: sub_41B250
// Owner: SessionState [DERIVED]
// Raw source: functions/sub_41B250_0041b250.c

void SessionState::RetirementFailureEventHandler()
{
    // Handles retirement/failure commentary events during a championship weekend session. Gated by race-active, track-state, session-type (7), race-phase (!= 8) and championship-mode (!= 5) flags. Builds a sentinel-initialized driver-table entry; when the retiring vehicle is the player (field +0x4894 matches the player vehicle's field +0x4894) the reason code maps to event IDs 119 (=1), 118 (=7), or 117 (other). For AI vehicles it derives a context index (FloatRangeIndexLookup on field +0x4044, default 3) and maps the reason code to event IDs 235 (=1), 238 (=4), 236 (=9), or 237 (other) using field +0x489C as context. Inserts the entry into the session event table at flt_5EA618 only when the built entry is not the -1 sentinel.
    // GUARD: Session-state gate: only proceed when race active (dword_7D0308 nonzero), track state nonzero (flt_7CF3C8), session type is 7 (dword_7C56A4), race phase is not 8 (dword_7C56A8), and championship mode is not 5 (dword_7D0410). [global:0x007D0308, global:0x007CF3C8, global:0x007C56A4, global:0x007C56A8, global:0x007D0410, source:raw]
    // CALL: StructInitWithSentinelValues(v4) resets the 8-word driver-table entry buffer to sentinel values before any lookup fills it. [callee:0x004144D0, source:raw]
    // GUARD: Player identity check: compare field +0x4894 of the live player vehicle (dword_7C54E8) with field +0x4894 of this vehicle; equality selects the player-commentary path, otherwise the AI-commentary path. [global:0x007C54E8, field:this:0x00004894, source:raw]
    // CALL: Player path, reason code == 1: DriverDataTableLookupAndTimeConversion with event 119. [field:this:0x00004068, guard:2, callee:0x004144F0, source:raw]
    // CALL: Player path, reason code == 7: DriverDataTableLookupAndTimeConversion with event 118. [field:this:0x00004068, guard:1, callee:0x004144F0, source:raw]
    // CALL: Player path, any other reason code: DriverDataTableLookupAndTimeConversion with event 117. [field:this:0x00004068, callee:0x004144F0, source:raw]
    // CALCULATION: AI path context index: default lookupIndex = 3; when float field +0x4044 is greater than 0.0 the index comes from FloatRangeIndexLookup(field +0x4044) and a zero result falls back to 3. [field:this:0x00004044, callee:0x004D7C10, source:raw]
    // CALL: AI path, reason code == 1 (engine): DriverDataTableLookupAndTimeConversion with event 235, field +0x489C as context value and the computed lookupIndex. [field:this:0x00004068, guard:2, field:this:0x0000489C, callee:0x004144F0, source:raw]
    // CALL: AI path, reason code == 4 (brake): DriverDataTableLookupAndTimeConversion with event 238, field +0x489C as context value and the computed lookupIndex. [field:this:0x00004068, guard:0, field:this:0x0000489C, callee:0x004144F0, source:raw]
    // CALL: AI path, reason code == 9 (fuel): DriverDataTableLookupAndTimeConversion with event 236, field +0x489C as context value and the computed lookupIndex. [field:this:0x00004068, guard:3, field:this:0x0000489C, callee:0x004144F0, source:raw]
    // CALL: AI path, any other reason code: DriverDataTableLookupAndTimeConversion with event 237, field +0x489C as context value and the computed lookupIndex. [field:this:0x00004068, guard:0, field:this:0x0000489C, callee:0x004144F0, source:raw]
    // GUARD: Sentinel check: only insert when the first word of the built entry (driverTableEntry[0]) is not -1, i.e. the lookup produced a valid entry. [source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v4) appends the built driver-table entry to the session event table referenced by flt_5EA618. [callee:0x00418560, global:0x005EA618, source:raw]

    // Conservative worker pseudocode:
    //   if raceActive && trackState != 0 && sessionType == 7 && phase != 8 && championshipMode != 5:
    //       StructInitWithSentinelValues(entry)
    //       if playerVehicle.driverId == this.driverId:
    //           if reason == 1:  lookup(entry, 119, -1, -1, -1, -1, -2.0, -2.0)
    //           else if reason == 7:  lookup(entry, 118, -1, -1, -1, -1, -2.0, -2.0)
    //           else:  lookup(entry, 117, -1, -1, -1, -1, -2.0, -2.0)
    //       else if phase != 8:
    //           index = 3
    //           if this.rangeValue > 0.0:
    //               index = FloatRangeIndexLookup(this.rangeValue)
    //               if index == 0:  index = 3
    //           if reason == 1:  lookup(entry, 235, this.context, index, -1, -1, -2.0, -2.0)
    //           else if reason == 4:  lookup(entry, 238, this.context, index, -1, -1, -2.0, -2.0)
    //           else if reason == 9:  lookup(entry, 236, this.context, index, -1, -1, -2.0, -2.0)
    //           else:  lookup(entry, 237, this.context, index, -1, -1, -2.0, -2.0)
    //       if entry[0] != -1:
    //           InsertDriverTableEntry(flt_5EA618, entry)
    // UNRESOLVED: flt_59E440 is listed as read by the packet but never appears in the decompiled source text; no grounded operation could be derived for it.
    // UNRESOLVED: dword_8AD264 is listed as read by the packet but is not referenced in the decompiled source; prior analysis labels it a penalty-message queue handled elsewhere.
    // UNRESOLVED: The inner `else if (dword_7C56A8 != 8)` on the AI path duplicates the outer phase guard and has no distinct behavior in the raw text.
    // UNRESOLVED: Reason-code value 7 (event 118) and the semantics of event IDs 117-119/235-238 come from the prior-analysis fill, not from the raw decompile.
    // UNRESOLVED: The exact interpretation of field +0x489C as a context index (retired driver index vs. grid position) is not established by this packet alone.
}
