// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2C70
// Canonical corpus name: ScoringGateValueSelect
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScoringGateValueSelect_004e2c70.c

void UnknownObject::ScoringGateValueSelect()
{
    // Selects the timestamp/value written to a scoring field (offset 0x984) of the object in ecx. When the scoring gate flag dword_8AB6E4 equals 2, delegates to Delegation(&dword_8AB6EC) and stores the x87 result; otherwise stores the global default dbl_8AFEA0. Called by sub_4B3400 (0x004B3400).
    // GUARD: Branch on scoring gate flag dword_8AB6E4: take the delegation path when it equals 2, otherwise the default path. [global:0x008AB6E4, source:raw]
    // CALL: Call Delegation(&dword_8AB6EC) to obtain the gate-specific value; the x87 result (a2) is consumed by the following store. [callee:0x004B9CE0, global:0x008AB6EC, source:raw]
    // ASSIGNMENT: Store the delegated x87 result as a float into the scoring field at a1 + 0x984 (2436). [field:this:0x00000984, source:raw]
    // ASSIGNMENT: Default path: store the global double dbl_8AFEA0 as a float into the scoring field at a1 + 0x984 (2436). [global:0x008AFEA0, field:this:0x00000984, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4E2C70(int *scoring_obj, double delegated) {
    //     if (dword_8AB6E4 == 2) {
    //       delegated = Delegation(&dword_8AB6EC);
    //       *(float*)((char*)scoring_obj + 2436) = (float)delegated;
    //     } else {
    //       *(float*)((char*)scoring_obj + 2436) = (float)dbl_8AFEA0;
    //     }
    //   }
    // UNRESOLVED: What Delegation computes for gate type 2, and the meaning of the global dword_8AB6EC it receives, are outside this function.
    // UNRESOLVED: Whether the stored value is a timestamp, lap time, or score is unproven here.
    // UNRESOLVED: The double dbl_8AFEA0 is used as a single-precision float here; its source (session time per prior analysis) is not established by this packet.
}
