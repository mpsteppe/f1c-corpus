// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6B80
// Canonical corpus name: RegistrationWrapper_6b80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RegistrationWrapper_6b80_004f6b80.c

void UnknownObject::RegistrationWrapper_6b80()
{
    // Trivial registration wrapper structurally identical to the neighboring callback registration stub: forwards the address of the cleanup routine TireWearPropertyCleanup_6b90 (0x004F6B90) to BooleanToIntConversion (0x00587B3E) and returns the result. No writes to globals, no guards, no callees beyond the conversion helper.
    // CALL: Call BooleanToIntConversion (0x00587B3E) passing the address of the read-only global function pointer TireWearPropertyCleanup_6b90 (0x004F6B90) [callee:0x00587B3E, global:0x004F6B90, function:0x004F6B80, source:raw]
    // RETURN: Return the conversion result directly; wrapper has no other side effects [abi:lead, function:0x004F6B80, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)TireWearPropertyCleanup_6b90);
    // UNRESOLVED: Distinct meaning of this wrapper versus the adjacent callback registration stub is not resolvable from this packet (separate cleanup pointer at 0x004F6B90, otherwise identical shape)
    // UNRESOLVED: Semantics of BooleanToIntConversion at 0x00587B3E unknown
}
