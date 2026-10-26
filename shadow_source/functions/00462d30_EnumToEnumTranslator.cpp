// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462D30
// Canonical corpus name: EnumToEnumTranslator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EnumToEnumTranslator_00462d30.c

void UnknownObject::EnumToEnumTranslator()
{
    // Join-session error enum translator. Reads the sub-object pointer at this+0x0, then the argument at obj+0x3FB8, and calls SingleDelegationCall_a900 as a gate: if it returns non-zero (delegation active) the function returns 0. Otherwise sub_57A590 converts the input enum a2 into an intermediate value v2, which is then mapped 0->0, 2->1, 3->2, 5->4, with every other value (including 1 and 4) mapped to 3. Callers recorded in existing analysis: AutoJoinRetryLoop and MultiplayerSessionJoinHandler.
    // GUARD: Read sub-object pointer at this+0x0 and read the argument at obj+0x3FB8, then call SingleDelegationCall_a900; a non-zero result (delegation active) blocks and returns 0 [field:this:0x00000000, field:obj:0x00003FB8, callee:0x0057A900, source:raw]
    // CALL: Convert input enum a2 into intermediate value v2 via sub_57A590 [callee:0x0057A590, source:raw]
    // GUARD: v2 == 0 returns 0 (unknown or invalid intermediate value) [source:raw]
    // CALCULATION: Compute v3 = v2 - 2 and v4 = v3 - 1 to discriminate intermediate values 2, 3 and 5 [source:raw]
    // STATE_TRANSITION: v2 == 2 maps to return 1 [source:raw]
    // STATE_TRANSITION: v2 == 3 maps to return 2 [source:raw]
    // STATE_TRANSITION: v2 == 5 maps to return 4 [source:raw]
    // RETURN: Default mapping returns 3, which also covers intermediate values 1 and 4 [source:raw]

    // Conservative worker pseudocode:
    //   int translateJoinError(int thisPtr, int a2) {
    //     if (SingleDelegationCall_a900(*(int*)(*(int*)thisPtr + 0x3FB8)))
    //       return 0;
    //     int v2 = sub_57A590(a2);
    //     if (v2 == 0) return 0;
    //     if (v2 == 2) return 1;
    //     if (v2 == 3) return 2;
    //     if (v2 == 5) return 4;
    //     return 3;
    //   }
    // UNRESOLVED: Semantics of the input conversion done by sub_57A590 are unknown; the intermediate enum values are not named
    // UNRESOLVED: SingleDelegationCall_a900 delegation semantics: a non-zero result blocks and returns 0, but the meaning of the guard state is not resolved
    // UNRESOLVED: Caller relationships to AutoJoinRetryLoop and MultiplayerSessionJoinHandler come from existing_analysis only and are not exercised by an operation here
}
