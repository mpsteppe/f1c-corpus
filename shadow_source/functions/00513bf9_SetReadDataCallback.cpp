// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513BF9
// Canonical corpus name: sub_513BF9
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_513BF9_00513bf9.c

void UnknownObject::SetReadDataCallback()
{
    // Configures a data-read callback on a structure. Stores the user data pointer a2 at this+0x54 and the read callback a3 at this+0x50. If the write callback slot this+0x4C was already non-null, it clears that slot to 0 and emits an error through CallbackDispatch (with string fragments aItSAnErrorToSe and aSameStructureR) about setting both read_data_fn and write_data_fn in the same structure. Always clears this+0x120 to 0 and returns the read callback a3.
    // GUARD: Read the write callback slot this+0x4C and test whether it is 0 (no existing write callback). [source:raw, field:this:0x0000004C, guard:0]
    // ASSIGNMENT: Store the user data pointer a2 into the read-data user-data slot at this+0x54. [source:raw, field:this:0x00000054]
    // ASSIGNMENT: Store the read callback a3 into the read callback slot at this+0x50. [source:raw, field:this:0x00000050]
    // STATE_TRANSITION: When a write callback was already present (this+0x4C != 0), clear it to 0 and report the conflict by calling CallbackDispatch with the error strings aItSAnErrorToSe (0x005AF520) and aSameStructureR (0x005AF4EC). [source:raw, field:this:0x0000004C, callee:0x00511887, global:0x005AF520, global:0x005AF4EC]
    // ASSIGNMENT: Clear the state field at this+0x120 to 0. [source:raw, field:this:0x00000120]
    // RETURN: Return the read callback pointer a3. [source:raw]

    // Conservative worker pseudocode:
    //   int (*SetReadDataCallback(int* self, int userData, int (*readFn)(int, int)))(int, int) {
    //     int hadWrite = self[19] != 0;
    //     self[21] = userData;
    //     self[20] = readFn;
    //     if (hadWrite) {
    //       self[19] = 0;
    //       CallbackDispatch(self, "It's an error to set both read_data_fn and write_data_fn in the ");
    //       CallbackDispatch(self, "same structure.  Resetting write_data_fn to NULL.");
    //     }
    //     self[72] = 0;
    //     return readFn;
    //   }
    // UNRESOLVED: Owner type of the callback structure is unknown; callers are sub_50210E (0x0050210E) and sub_5118E6 (0x005118E6).
    // UNRESOLVED: The exact wording and dispatch semantics of CallbackDispatch (0x00511887) are not defined here.
}
