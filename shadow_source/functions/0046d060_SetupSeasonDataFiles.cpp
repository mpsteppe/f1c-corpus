// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046D060
// Canonical corpus name: SeasonDataFileSetupChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonDataFileSetupChain_0046d060.c

void UnknownObject::SetupSeasonDataFiles()
{
    // Season data-file setup chain: initializes a session structure on the stack, writes the vehicle setup file for the current track name (dword_7CE668) or the default directory (byte_5EA438) when no track is selected, triggers the auto-load config file processing at byte_7CE498, deallocates the score-slot array, and frees a stack scratch buffer if non-null.
    // CALL: SessionStructInit(v2) initializes a session structure on the stack before the setup chain proceeds. [callee:0x0042E320]
    // ASSIGNMENT: The setup path is taken from dword_7CE668 (current track name); when null it falls back to the default application directory byte_5EA438. [global:0x007CE668, global:0x005EA438]
    // CALL: VehicleSetupFileWriter(v2, path, 0) writes the vehicle setup file for the resolved track path using the initialized session structure. [callee:0x0042FD00, global:0x007CE668, global:0x005EA438]
    // CALL: sub_4B0770(byte_7CE498, 1) triggers processing of the auto-load config file referenced by byte_7CE498 with parameter 1. [callee:0x004B0770, global:0x007CE498]
    // CALL: ScoreSlotDeallocator(v4) deallocates the score-slot array built on the stack. [callee:0x0042DDD0]
    // CALL: If the stack scratch pointer v3 is non-null it is freed through FreeWrapper_7bcf, otherwise null is returned. [callee:0x00587BCF]
    // RETURN: Returns null when no scratch pointer was pending; otherwise returns after freeing it. [source:raw]

    // Conservative worker pseudocode:
    //   SessionStructInit(session)
    //   path = dword_7CE668 or byte_5EA438
    //   VehicleSetupFileWriter(session, path, 0)
    //   sub_4B0770(byte_7CE498, 1)
    //   ScoreSlotDeallocator(score_array)
    //   if scratch: FreeWrapper_7bcf(scratch)
    //   return 0
    // UNRESOLVED: The stack slot v3 is read before any write in the decompiled body; it is an uninitialized-scratch artifact whose source-level meaning (owned heap pointer vs leftover stack garbage) is unclear.
    // UNRESOLVED: callee __alloca_probe is the compiler-emitted stack probe for the large frame; its presence carries no call-site semantics.
}
