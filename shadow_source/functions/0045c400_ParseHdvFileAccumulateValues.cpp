// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C400
// Canonical corpus name: sub_45C400
// Owner: HdvVehicleFileParserHelper [DERIVED]
// Raw source: functions/sub_45C400_0045c400.c

void HdvVehicleFileParserHelper::ParseHdvFileAccumulateValues()
{
    // Parses a .hdv vehicle file into a session struct, then accumulates a set of parameter values into the caller's output dword via repeated UtilityFunction_8a60 selector calls (using the selector byte at this+0x1), adds the tyre-model data contribution, frees all parsed-data allocations, and returns an AND-combined success flag (zeroed whenever any selector call fails, but parsing continues).
    // ASSIGNMENT: Set the success flag v4 = 1, initialize the local session struct via SessionStructInit and scratch tyre-model data via TireModelDataInit. [callee:0x0042E320, callee:0x004F34E0, source:raw]
    // CALL: Parse the vehicle .hdv file a2 into the session struct via TheSvmHdvVehicleFileParser(a2, v13, 2), then zero the output accumulator (*a3 = 0). [callee:0x004F4270, source:raw]
    // LOOP: Accumulate six parameter values: repeatedly call UtilityFunction_8a60(this[1], &v6); on a non-zero return add v6 to *a3, otherwise clear v4; then add the tyre-model contribution v7[2] to *a3. [callee:0x00568A60, field:this:0x00000001, source:raw]
    // CALL: Free all parsed-data allocations: v12, v11, v10, v9, v8, v7[0] and v14 via FreeWrapper_7bcf, and the score/timing scratch v15 via ScoreSlotDeallocator. [callee:0x00587BCF, callee:0x0042DDD0, source:raw]
    // RETURN: Return the combined success flag v4 (1 only if every UtilityFunction_8a60 call succeeded). Invoked from sub_45C0C0 and ParticleSoundEffectSpawner. [caller:0x0045C0C0, caller:0x004607A0, function:0x0045C400, source:raw]

    // Conservative worker pseudocode:
    //   ok = 1;
    //   SessionStructInit(v13); TireModelDataInit(v7);
    //   TheSvmHdvVehicleFileParser(a2, v13, 2);
    //   *a3 = 0;
    //   for (i = 0; i < 6; i++) {
    //       if (UtilityFunction_8a60(this[1], &v6)) *a3 += v6;
    //       else ok = 0;
    //   }
    //   *a3 += v7[2];
    //   free v12/v11/v10/v9/v8/v7[0]; ScoreSlotDeallocator(v15); free v14;
    //   return ok;
    // UNRESOLVED: The packet lists global byte_5EA438 as referenced, but the decompiled body of this function contains no direct reference to it; the intended fallback use is unconfirmed.
    // UNRESOLVED: The selector semantics of UtilityFunction_8a60 and which six specific parameter keys are selected by this[1] are not resolvable from this packet alone.
}
