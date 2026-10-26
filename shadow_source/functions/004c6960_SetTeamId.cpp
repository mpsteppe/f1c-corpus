// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6960
// Canonical corpus name: TeamIDSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TeamIDSetter_004c6960.c

void UnknownObject::SetTeamId()
{
    // Team-identifier setter: writes the same value a2 to five dword fields of the vehicle/team object (this[1] +0x4, this[4] +0x10, this[3252] +0x32D0, this[4110] +0x4038, this[4645] +0x4894) so every sub-structure agrees on team identity, then returns the value written. Called by SeasonScoringReset and AIDriverCountSetup.
    // ASSIGNMENT: Write the team id a2 to this[4645] (+0x4894). [field:this:0x00004894, source:raw]
    // ASSIGNMENT: Write the team id a2 to this[1] (+0x4). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the team id a2 to this[4] (+0x10). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write the team id a2 to this[3252] (+0x32D0). [field:this:0x000032D0, source:raw]
    // ASSIGNMENT: Write the team id a2 to this[4110] (+0x4038). [field:this:0x00004038, source:raw]
    // RETURN: Return the team id a2 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int SetTeamId(_DWORD *this, int teamId) {
    //     this[4645] = teamId;
    //     this[1] = teamId;
    //     this[4] = teamId;
    //     this[3252] = teamId;
    //     this[4110] = teamId;
    //     return teamId;
    //   }
    // UNRESOLVED: The role of each of the five offsets (which sub-structure each field belongs to) is not established by this packet alone.
    // UNRESOLVED: No guard or callee evidence is present; the writes are unconditional.
}
