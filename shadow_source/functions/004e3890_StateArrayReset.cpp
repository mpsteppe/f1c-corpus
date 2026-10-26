// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E3890
// Canonical corpus name: StateArrayReset
// Owner: VehicleRespawnState [DERIVED]
// Raw source: functions/StateArrayReset_004e3890.c

void VehicleRespawnState::StateArrayReset()
{
    // Resets an array of per-vehicle state entries. Reads the entry count at this+0xBA8; if greater than zero, iterates entries with a 187-float (748-byte) stride starting at this+747 floats, calling sub_4DF110(entry, 0.0, -1) on each and clearing the entry's sixth float (this+0xBC4) to 0.0. Called by VehicleRespawnReset.
    // GUARD: Read the entry count from this+0xBA8; if it is not greater than zero the loop is skipped entirely. [field:this:0x00000BA8, source:raw]
    // ASSIGNMENT: Initialize the entry pointer at this+747 floats (start of the entry array); entries advance by a 187-float stride. [field:this:0x00000BC4, source:raw]
    // LOOP: Iterate while the running index is below the count at this+0xBA8; the count is re-read from this+0xBA8 each iteration for the loop bound. [field:this:0x00000BA8, source:raw]
    // CALL: Call sub_4DF110(current_entry, 0.0, -1) to reset the entry's state with a zero value and -1 sentinel. [callee:0x004DF110, source:raw]
    // ASSIGNMENT: Clear the entry's sixth float at this+0xBC4 to 0.0. [field:this:0x00000BC4, source:raw]
    // RETURN: Return the last-read count from this+0xBA8. VehicleRespawnReset (0x004E0800) calls this during respawn reset. [function:0x004E3890, caller:0x004E0800]

    // Conservative worker pseudocode:
    //   count = this->entry_count;
    //   if (count > 0) {
    //       for (entry = &this->entries[0]; index < count; entry += 187, index++) {
    //           sub_4DF110(entry, 0.0, -1);
    //           entry[6] = 0.0;
    //       }
    //   }
    //   return count;
    // UNRESOLVED: Semantics of sub_4DF110's arguments (0.0 value, -1 sentinel) and the full entry layout beyond the sixth float are not visible in this function.
    // UNRESOLVED: Existing analysis names sub_4DF110 'ContactConstraintSolverUpdate'; that name is unverified.
    // UNRESOLVED: Entry stride (187 floats) and base (this+747 floats) are derived from the raw source addressing and are not independently corroborated.
}
