// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E3360
// Canonical corpus name: sub_4E3360
// Owner: VehicleAudioConfigObject [DERIVED]
// Raw source: functions/sub_4E3360_004e3360.c

void VehicleAudioConfigObject::LoadVehicleAudioConfig()
{
    // Parses the vehicle audio/sound configuration: resolves the vehicle name from the vehicle-database array via dword_8AC394, parses its .hdv file, opens the audio stream, reads restriction-sphere and force-field-sphere records (counting and allocating per-record slots), initializes per-vehicle audio playback sub-slots (base slot, two conditional slots, and 8 stride-68 group entries) through sub_4DE610, then frees all scratch allocations. Returns the last scratch allocation pointer (freed if non-null).
    // CALL: Initialize local session struct (SessionStructInit) and scratch tyre-model data (TireModelDataInit). [callee:0x0042E320, callee:0x004F34E0, source:raw]
    // ASSIGNMENT: Resolve the vehicle name pointer as *(dword_8AC394 + 8 + 1060 * *(*this + 18584)), reading the vehicle index through this+0x0 and the obj+0x4898 slot field; fall back to byte_5EA438 when null. [field:this:0x00000000, field:obj:0x00004898, global:0x008AC394, global:0x005EA438, source:raw]
    // CALL: Parse the resolved vehicle name into the session struct via TheSvmHdvVehicleFileParser(name, v42, 2). [callee:0x004F4270, source:raw]
    // ASSIGNMENT: Take the audio data path from v40 (fallback byte_5EA438), initialize the float vector v18 via FloatVectorInit, zero the counter v27 and the v28/v35 scratch blocks (ZeroInitSmallStruct for v28, memset for v35, v30/v32/v33/v34 = 0, v31 = 1). [global:0x005EA438, callee:0x004DD450, callee:0x005668B0, source:raw]
    // LOOP: When AudioStreamOpen(v4, 0) succeeds, loop while ConditionalDispatchBasedOnFlag(v35, 384); for each non-terminal record (sub_5651B0 check) count aRestrictionsph hits into v27 and aForcefieldsphe hits into v3 via sub_565870. [callee:0x00566B20, callee:0x00566CC0, callee:0x005651B0, callee:0x00565870, global:0x005D4E7C, global:0x005D4E68, source:raw]
    // ASSIGNMENT: Allocate the force-field record buffer via OperatorNewNhMallocWrapper(24 * v3 + 4) with a leading count header and zeroed 24-byte-stride slots (v22), and the restriction record buffer via OperatorNewNhMallocWrapper(20 * v27). [callee:0x00587C03, source:raw]
    // CALL: Initialize the conditional-alloc state v28 via ConditionalAllocInitDispatch and set the restriction limit scalar v26 = 1.0. [callee:0x00566D30, source:raw]
    // LOOP: Second dispatch pass while ConditionalDispatchBasedOnFlag(v35, 384): aDefaultlimit doubles v18 (v18 = v18 * v18), aRestrictionlim loads v26, aRestrictionsph fills a restriction record (center v23/v24/v25, radius v17*v17, limit v26*v26, slot index v19++), and aForcefieldsphe fills a force-field record (center, radius v17*v17, two zero fields, slot index v21++). [global:0x005D4E58, global:0x005D4E44, global:0x005D4E7C, global:0x005D4E68, callee:0x00565870, callee:0x005651B0, source:raw]
    // CALL: Close the conditional file handle / dispatch via ConditionalFileHandleCloseWithFlagDispatch(v28). [callee:0x00566B90, source:raw]
    // ASSIGNMENT: Set the active sub-slot count this+0xBA8 to 1; it is incremented for every enabled sub-slot initialized below. [field:this:0x00000BA8, source:raw]
    // CALL: Initialize the base audio sub-slot via sub_4DE610(this + 747, &v18, this + 1). [callee:0x004DE610, source:raw]
    // GUARD: When the second sub-slot pointer this+0x5E4 is non-null and both enable flag bytes at this+0x624 and this+0x625 are set, compute index v11 = 187 * this[746]++ and call sub_4DE610(&this[v11 + 747], &v18, this + 377). [field:this:0x000005E4, field:this:0x00000624, field:this:0x00000625, field:this:0x00000BA8, callee:0x004DE610, source:raw]
    // GUARD: When the third sub-slot pointer this+0x628 is non-null and both enable flag bytes at this+0x668 and this+0x669 are set, compute index v12 = 187 * this[746]++ and call sub_4DE610(&this[v12 + 747], &v18, this + 394). [field:this:0x00000628, field:this:0x00000668, field:this:0x00000669, field:this:0x00000BA8, callee:0x004DE610, source:raw]
    // LOOP: Iterate 8 group entries at 68-byte stride starting from this+411 (base this+0x668): for each entry whose dword and the enable flag bytes at this+0x66C / this+0x6AC / this+0x6AD are set, call sub_4DE610 at index 187 * this[746]++ + 747. [field:this:0x00000668, field:this:0x00000669, field:this:0x0000066C, field:this:0x000006AC, field:this:0x000006AD, field:this:0x00000BA8, callee:0x004DE610, source:raw]
    // CALL: Tear down the conditional state v28 via SubCallWithConditionalFieldFree and the float-vector scratch v18 via ArrayCleanupWithDestructorLoop. [callee:0x005668D0, callee:0x004DD470, source:raw]
    // CALL: Free all scratch allocations v41, v40, v39, v38, v37, v36[0] via FreeWrapper_7bcf and the score/timing scratch v44 via ScoreSlotDeallocator. [callee:0x00587BCF, callee:0x0042DDD0, source:raw]
    // RETURN: Return the last scratch allocation pointer v43, freeing it first via FreeWrapper_7bcf when non-null. Invoked from VehicleGraphicsSceneLoader. [caller:0x004DFCE0, function:0x004E3360, source:raw]

    // Conservative worker pseudocode:
    //   SessionStructInit(v42); TireModelDataInit(v36);
    //   name = vehicle_db_name(*this->state + 18584) ?: byte_5EA438;
    //   TheSvmHdvVehicleFileParser(name, v42, 2);
    //   path = v40 ?: byte_5EA438; FloatVectorInit(&v18); zero local scratch;
    //   if (AudioStreamOpen(path, 0)) {
    //       while (ConditionalDispatchBasedOnFlag(v35, 384)) {
    //           if (!sub_5651B0(v29)) {
    //               if (sub_565870(aRestrictionsph, ...)) v27++;
    //               if (sub_565870(aForcefieldsphe, ...)) v3++;
    //           }
    //       }
    //       v22 = alloc(24 * v3 + 4) with count header; v20 = alloc(20 * v27);
    //       ConditionalAllocInitDispatch(v28); v26 = 1.0;
    //       while (ConditionalDispatchBasedOnFlag(v35, 384)) {
    //           if (!sub_5651B0(v29)) {
    //               sub_565870(aDefaultlimit, &v18, ...) and v18 = v18 * v18;
    //               sub_565870(aRestrictionlim, &v26, ...);
    //               sub_565870(aRestrictionsph, ...) -> fill 20-byte restriction record;
    //               sub_565870(aForcefieldsphe, ...) -> fill 24-byte force-field record;
    //           }
    //       }
    //       ConditionalFileHandleCloseWithFlagDispatch(v28);
    //   }
    //   this[746] = 1;
    //   sub_4DE610(this + 747, &v18, this + 1);
    //   if (this[377] && byte(0x624) && byte(0x625)) sub_4DE610(&this[187 * this[746]++ + 747], &v18, this + 377);
    //   if (this[394] && byte(0x668) && byte(0x669)) sub_4DE610(&this[187 * this[746]++ + 747], &v18, this + 394);
    //   for (i = 0; i < 8; i++) { p = this + 411 + 68*i; if (*(DWORD*)p && p[64] && p[65]) sub_4DE610(&this[187 * this[746]++ + 747], &v18, p); }
    //   SubCallWithConditionalFieldFree(v28); ArrayCleanupWithDestructorLoop(&v18);
    //   free v41/v40/v39/v38/v37/v36[0]; ScoreSlotDeallocator(v44);
    //   return v43 ? FreeWrapper_7bcf(v43) : v43;
    // UNRESOLVED: The stride-68 group-entry loop checks dword and two enable bytes per entry; the exact mapping of the packet fields 0x66C/0x6AC/0x6AD onto the per-entry enable bytes of the first/last iterated slots is inferred from usage, not confirmed by names.
    // UNRESOLVED: sub_565870 reads four string tokens (aRestrictionlim, aDefaultlimit, aForcefieldsphe, aRestrictionsph) into coordinates/radius/limit scalars; the physical meaning of the sphere records is DERIVED from the token names.
    // UNRESOLVED: Owner identity is DERIVED from usage and the existing VehicleAudioConfigLoader analysis; the LEGACY ABI lead (Track_Limit_Penalty_Zone_System) disagrees and is not relied on.
}
