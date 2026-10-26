// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551CE0
// Canonical corpus name: BinkVideoClose
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinkVideoClose_00551ce0.c

void UnknownObject::BinkVideoClose()
{
    // Closes a Bink video handle. Reads the Bink handle stored at this+0x0, passes it to BinkClose (imported at 0x0059E338), and returns 0. Called by ConditionalFreeWithBinkClose (0x00551F80).
    // CALL: Call BinkClose with this[0] (the Bink handle at this+0x0). [global:0x0059E338, field:this:0x00000000, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   BinkClose(this[0]);
    //   return 0;
    // UNRESOLVED: Owner object holding the Bink handle at +0x0 is unknown.
    // UNRESOLVED: Whether this[0] is guaranteed a valid handle versus NULL is unverified; BinkClose's NULL handling is external behavior.
}
