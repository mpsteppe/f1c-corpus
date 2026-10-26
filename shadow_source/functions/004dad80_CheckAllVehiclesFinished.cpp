// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DAD80
// Canonical corpus name: sub_4DAD80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DAD80_004dad80.c

void UnknownObject::CheckAllVehiclesFinished()
{
    // Returns whether race completion is confirmed, combining a race-end condition, a stored count at this+0x20, and a walk over trailing vehicles. Reads the race-end boolean from ArithmeticComparison_ae80 and the vehicle tally from dword_5C329C. The result flag starts false and is set true if the race-end condition holds or this+0x20 equals the tally. When the finished count from sub_4DA990 matches the tracked count read from the player vehicle pointer (dword_7C54E8 + 16480) and that tracked count has not reached the tally, it scans the trailing vehicles (via sub_4D1B50 over dword_8ACEE0 indexing dword_5F073C at stride 4656) under a one-shot flag at this+0x28, and clears the flag if the scan reaches the end of the grid. Writes 1 to this+0x28 to mark the one-shot check as done.
    // ASSIGNMENT: Initialize the result flag to 0 (false) before any checks. [source:raw]
    // CALL: Read the race-end condition via ArithmeticComparison_ae80(). [callee:0x004DAE80, source:raw]
    // ASSIGNMENT: Read the vehicle tally from dword_5C329C. [global:0x005C329C, source:raw]
    // GUARD: Set the result flag when either the race-end condition holds or this+0x20 equals the vehicle tally. [field:this:0x00000020, global:0x005C329C, source:raw]
    // ASSIGNMENT: Read the tracked vehicle count from the player vehicle pointer dword_7C54E8 at offset +16480. [global:0x007C54E8, source:raw]
    // CALL: Compute the finished count via sub_4DA990(this). [callee:0x004DA990, source:raw]
    // GUARD: Proceed with the trailing-vehicle walk only when the finished count equals the tracked count and the tracked count has not yet reached the tally in dword_5C329C. [global:0x005C329C, source:raw]
    // GUARD: One-shot flag: only perform the trailing-vehicle walk when this+0x28 (byte at +40) equals 1. [guard:0, field:this:0x00000028, source:raw]
    // LOOP: Walk indices forward from the tracked count, stopping when a trailing vehicle is not finished; each index resolves through sub_4D1B50 over dword_8ACEE0 and indexes dword_5F073C at stride 4656. The walk terminates at the tally in dword_5C329C. [callee:0x004D1B50, global:0x008ACEE0, global:0x005F073C, global:0x005C329C, source:raw]
    // STATE_TRANSITION: If the walk reached the end of the grid (all trailing vehicles finished), clear the result flag; then mark the one-shot flag handled by writing 1 to this+0x28. [field:this:0x00000028, source:raw]
    // RETURN: Return whether race completion is confirmed. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4DAD80(int this) {
    //     char result = 0;
    //     int raceEnd = ArithmeticComparison_ae80();
    //     int tally = dword_5C329C;
    //     if (raceEnd || *(int*)(this + 32) == tally) result = 1;
    //     int tracked = *(int*)(dword_7C54E8 + 16480);
    //     if (sub_4DA990(this) == tracked && tracked != tally) {
    //       result = 1;
    //       if (*(char*)(this + 40) == 1) {
    //         int i = tracked + 1;
    //         int reachedEnd = (i == tally);
    //         if (i < tally) {
    //           do {
    //             if (!dword_5F073C[4656 * sub_4D1B50(dword_8ACEE0, i - 1)]) break;
    //             ++i;
    //           } while (i < tally);
    //           reachedEnd = (i == tally);
    //         }
    //         if (reachedEnd) result = 0;
    //       }
    //       *(char*)(this + 40) = 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The meaning of this+0x20 (stored count) and how it is populated is not established here.
    // UNRESOLVED: The interpretation of dword_5F073C entries as per-vehicle finish state and the 4656 stride depend on the vehicle array layout.
    // UNRESOLVED: The exact condition evaluated by ArithmeticComparison_ae80 is not visible in this function.
}
