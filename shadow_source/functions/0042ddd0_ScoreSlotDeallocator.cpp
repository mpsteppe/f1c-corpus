// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DDD0
// Canonical corpus name: ScoreSlotDeallocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScoreSlotDeallocator_0042ddd0.c

void UnknownObject::ScoreSlotDeallocator()
{
    // Deallocator for a four-slot score/configuration object. Saves this+0x4 and this+0xC, zeroes this+0x0 and both pointers, calls FreeWrapper on the saved buffers when non-null, then zeroes this+0x8 and this+0xC. Returns the result of the final FreeWrapper call (or the saved this+0xC pointer when null).
    // ASSIGNMENT: Save the first buffer pointer from this+0x4 and clear this+0x0 to 0 [field:this:0x00000004, field:this:0x00000000, source:raw]
    // GUARD: Only call FreeWrapper on the saved this+0x4 buffer when it is non-null [field:this:0x00000004, source:raw]
    // CALL: FreeWrapper_7bcf releases the buffer previously held at this+0x4 [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Clear this+0x4 and this+0x8 to 0 after releasing the first buffer [field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: Save this+0xC and call FreeWrapper on it only when it is non-null [field:this:0x0000000C, source:raw]
    // CALL: FreeWrapper_7bcf releases the buffer previously held at this+0xC [callee:0x00587BCF, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear this+0xC to 0, completing the zeroing of all four slots [field:this:0x0000000C, source:raw]
    // RETURN: Return the saved this+0xC pointer (or the FreeWrapper result); invoked by sub_42DC00, GearRatioConfigFileReader, TireModelInit, sub_45C400, SeasonDataFileSetupChain, TelemetryDataDump, sub_4E3360 and LargeConfigFunctionWithPhysicsConstants [function:0x0042DDD0, caller:0x0042DC00, caller:0x0042DE10, caller:0x0043E050, caller:0x0045C400, caller:0x0046D060, caller:0x004D4A80, caller:0x004E3360, caller:0x004E45B0, source:raw]

    // Conservative worker pseudocode:
    //   saved1 = this[1];
    //   *this = 0;
    //   if (saved1) FreeWrapper_7bcf(saved1);
    //   this[1] = 0;
    //   this[2] = 0;
    //   saved3 = this[3];
    //   if (saved3) result = FreeWrapper_7bcf(saved3); else result = saved3;
    //   this[3] = 0;
    //   return result;
    // UNRESOLVED: The four slots are all reset to 0 on every frame by the callers, so the persistent meaning of each slot (which one is count versus buffer) cannot be established from this packet alone
}
