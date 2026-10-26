// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5EA0
// Canonical corpus name: sub_4A5EA0
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/sub_4A5EA0_004a5ea0.c

void F1CPitMachine::PitsUnderRedHandler()
{
    // One-shot handler for the 'entering pits under red flag' scenario. Guarded by the latch this[0x180]: on first pass it records a state change to 2 via StateChangeNotify, captures the owner vehicle pointer *this, sets this[0x180]=1, updates the AI session phase via AISessionPhaseChange(dword_5EB978, owner), and processes the vehicle pit state via sub_4BC240(owner + 16436). When the race-start gate flag dword_8ACFC8 is 2 and penalties are enabled (dword_7CEF84), it either disqualifies the driver via DisqualificationHandler(aEnteringPitsUn) when the session type dword_7C56A4 is 7, or applies a time penalty via sub_4BBA90(aEnteringPitsUn, 1000.0).
    // GUARD: Read the one-shot latch this[0x180]; if it is already nonzero (handled), skip the entire body. [field:this:0x00000180, source:raw]
    // CALL: Record the state change to 2 via StateChangeNotify(this, 2). [callee:0x004A5C80, source:raw]
    // ASSIGNMENT: Capture v3 = *this (owner vehicle pointer) and set this[0x180] = 1 to mark the scenario handled. [field:this:0x00000000, field:this:0x00000180, source:raw]
    // CALL: Update the AI session phase via AISessionPhaseChange(dword_5EB978, v3). [callee:0x0041A2B0, global:0x005EB978, source:raw]
    // CALL: Process the vehicle pit state via sub_4BC240(*this + 16436). [callee:0x004BC240, field:this:0x00000000, source:raw]
    // GUARD: Proceed to the penalty/disqualification path only when the race-start gate flag dword_8ACFC8 equals 2. [global:0x008ACFC8, source:raw]
    // GUARD: Proceed only when penalties are enabled, i.e. dword_7CEF84 is nonzero. [global:0x007CEF84, source:raw]
    // GUARD: When the session type dword_7C56A4 equals 7, disqualify via DisqualificationHandler(aEnteringPitsUn); otherwise apply a time penalty via sub_4BBA90(aEnteringPitsUn, 1000.0). [global:0x007C56A4, global:0x005CD680, callee:0x004BC0E0, callee:0x004BBA90, source:raw]
    // RETURN: Return the latch value when skipped, or the gate-derived value on the penalty path. [source:raw]

    // Conservative worker pseudocode:
    //   char PitsUnderRedHandler(byte* this) {
    //     char result = this[384];
    //     if (!result) {
    //       StateChangeNotify((int)this, 2);
    //       v3 = *(dword*)this;
    //       this[384] = 1;
    //       AISessionPhaseChange(dword_5EB978, v3);
    //       sub_4BC240(*(dword*)this + 16436);
    //       if (dword_8ACFC8 == 2) {
    //         if (dword_7CEF84) {
    //           if (dword_7C56A4 == 7) return DisqualificationHandler(aEnteringPitsUn);
    //           else return sub_4BBA90((int)aEnteringPitsUn, 1000.0);
    //         }
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The literal 16436 (= 0x4034, the vehicle pit-state slot passed to sub_4BC240) is spelled only in the raw source and has no packet field evidence reference.
    // UNRESOLVED: The interpretation of dword_8ACFC8 as the race-start gate flag and dword_7CEF84 as the penalties-enabled flag is DERIVED from the existing analysis, not proven by this packet.
    // UNRESOLVED: The units and effect of the 1000.0 penalty argument to sub_4BBA90 are not described by this packet.
}
