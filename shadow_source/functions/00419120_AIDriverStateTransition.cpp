// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00419120
// Canonical corpus name: AIDriverStateTransition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIDriverStateTransition_00419120.c

void UnknownObject::AIDriverStateTransition()
{
    // AI driver state-transition handler. Gated by race active, track condition, race phase (not 8), a real state change and a distinct requested target. For session type 7 and the player vehicle it performs up to two random draws from a trig/noise lookup to pick one of driver behavior tables (198/259/120), resolves a row through DriverDataTableLookupAndTimeConversion into a local record, then on the shared exit path inserts the record with InsertDriverTableEntry and commits the new state into the driver's state field. Invoked by ConditionalFieldSetter (004BC2F0).
    // GUARD: Outer gate: race active (dword_7D0308 nonzero), track condition nonzero (flt_7CF3C8 != 0.0), race phase not 8 (dword_7C56A8 != 8), driver's committed state field (this[a2[4645] + 108]) differs from target a4, and requested state a3 differs from target a4 [source:raw, global:0x007D0308, global:0x007CF3C8, global:0x007C56A8]
    // CALL: StructInitWithSentinelValues(v13) zero-fills the local 8-entry driver-table row buffer [callee:0x004144D0, source:raw]
    // GUARD: Session-type check: only continue when dword_7C56A4 == 7 [global:0x007C56A4, source:raw]
    // GUARD: Player-vehicle match: the driver's slot index a2[4645] must equal the player vehicle pointer's field at dword_7C54E8 + 18580 [global:0x007C54E8, source:raw]
    // GUARD: Downgrade path (a4 != 1 and a4 < a3): compute v5 = vehicle array base unk_5EC6D8 + 18624 * sub_4D1B50(a4), then require byte 13388 of that slot clear, dword 4121 of that slot clear, and a2[4111] >= 1 [source:raw, global:0x005EC6D8, callee:0x004D1B50]
    // GUARD: Session-time window: proceed only when dbl_8AFEA0 - 2.0 is greater than the driver field at this[a2[4645] + 319] [source:raw, global:0x008AFEA0]
    // CALCULATION: First random draw: v9 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] from the lookup table; only continue when v9 < 0.75 [source:raw, global:0x008AAE70, global:0x008AAE74]
    // CALL: ArraySearchReturningIndex(flt_5EA618, 259) and ArraySearchReturningIndex(flt_5EA618, 120) prime the table-lookup machinery for the two candidate behavior tables [callee:0x004189F0, global:0x005EA618, source:raw]
    // CALL: Second random draw v10 = flt_8AAE74[(unsigned __int8)dword_8AAE70++]; when v10 >= 0.25 look up table 120 with target state a4, otherwise table 259 with the slot row discriminator *((_DWORD *)v5 + 4647); both via DriverDataTableLookupAndTimeConversion(v13, index, discriminator, -1, -1, -1, -2.0, -2.0) [source:raw, callee:0x004144F0, global:0x008AAE70, global:0x008AAE74]
    // CALL: Non-downgrade branch: for target state 1 use DriverDataTableLookupAndTimeConversion(v13, 120, 1, ...) after the two ArraySearchReturningIndex primes; the session-mismatch branch uses index 198 with discriminator a2[4647] when a4 == 1 and a2[4111] > 0 [source:raw, callee:0x004144F0, callee:0x004189F0, global:0x005EA618]
    // STATE_TRANSITION: Shared exit (LABEL_24): when the looked-up row was populated (LODWORD(v13[0]) != -1), InsertDriverTableEntry(flt_5EA618, v13) records it and LODWORD(this[a2[4645] + 108]) = a4 commits the target state to the driver's state field [source:raw, callee:0x00418560, global:0x005EA618]
    // CALL: Invoked by ConditionalFieldSetter (004BC2F0) to drive AI driver state transitions [caller:0x004BC2F0, function:0x00419120]

    // Conservative worker pseudocode:
    //   if (race_active && track_condition != 0.0 && phase != 8 && state_field(driver) != a4 && a3 != a4) {
    //     init_row_buffer(v13);
    //     if (session_type == 7) {
    //       if (player_ptr_field == a2[4645]) {
    //         if (a4 != 1) {
    //           if (a4 < a3) {
    //             v5 = VEH_ARRAY_BASE + 18624 * vehicle_index(a4);
    //             if (!v5[13388] && !slot_dword(v5, 4121) && a2[4111] >= 1 && cmp_flags && session_time - 2.0 > this[a2[4645] + 319]) {
    //               if (rand01(draw++) < 0.75) {
    //                 prime_table(259); prime_table(120);
    //                 if (rand01(draw++) >= 0.25) lookup(v13, 120, a4); else lookup(v13, 259, slot_dword(v5, 4647));
    //               }
    //             }
    //           }
    //         } else {
    //           prime_table(259); prime_table(120);
    //           lookup(v13, 120, 1);
    //         }
    //       } else if (a4 == 1 && a2[4111] > 0) {
    //         lookup(v13, 198, a2[4647]);
    //       }
    //     }
    //     if (LODWORD(v13[0]) != -1) {
    //       InsertDriverTableEntry(flt_5EA618, v13);
    //       state_field(driver) = a4;
    //     }
    //   }
    // UNRESOLVED: Comparison flags v7 and v8 (unsigned __int8, c0/c3) are read in the downgrade-path guard before any visible assignment in the decompiled source; their exact condition code source is not recoverable from this packet
    // UNRESOLVED: Six read-only globals flagged by packet facts appear nowhere in the raw decompiled source (flt_59E440, flt_59E7F8, flt_59E7FC, flt_59E800, flt_59E804, dword_8ACEE0); they carry physics/force-feedback-looking names in prior analysis and are likely spurious for this function
    // UNRESOLVED: sub_4D1B50 maps target state a4 to a vehicle slot index for the 18624-byte stride array; the mapping semantics are unverified here
}
