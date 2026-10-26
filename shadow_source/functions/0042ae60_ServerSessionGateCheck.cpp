// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AE60
// Canonical corpus name: ServerSessionGateCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ServerSessionGateCheck_0042ae60.c

void UnknownObject::ServerSessionGateCheck()
{
    // Boolean gate for session type 5 used by the overtaking path. Returns 0 when the global session type (dword_7C56A4) is not 5, and also returns 0 when the vehicle is on lap 2 (this+0x4094 == 2) while not being called to the box (this+0x454C != 1). Otherwise returns 1, allowing the caller to proceed. Invoked per-frame by Overtaking (0042AF70).
    // GUARD: Session-type gate: when dword_7C56A4 is not equal to 5 the function returns 0 immediately [global:0x007C56A4]
    // GUARD: Lap/pit gate: returns 0 when this+0x454C (callToBox) is not 1 AND this+0x4094 (lapOfRun) is equal to 2, i.e. on lap 2 without a pit call [field:this:0x0000454C, field:this:0x00004094, guard:0, guard:1]
    // RETURN: Returns 1 when the session type is 5 and either the vehicle is called to the box or it is not yet on lap 2 [source:raw]
    // CALL: Invoked per-frame from Overtaking (0042AF70) as the session gate for its decision logic [caller:0x0042AF70]

    // Conservative worker pseudocode:
    //   if (dword_7C56A4 != 5) return 0;
    //   if (this[0x454C/4] != 1 && this[0x4094/4] == 2) return 0;
    //   return 1;
    // UNRESOLVED: Field names callToBox (this+0x454C) and lapOfRun (this+0x4094) come from the skeleton fill and are not established by this packet
}
