// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040CD60
// Canonical corpus name: SessionPhaseDecode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionPhaseDecode_0040cd60.c

void UnknownObject::SessionPhaseDecode()
{
    // Session phase decoder called from multiple per-frame systems (audio, random state machine, session dispatch). When the current session pointer at this+0x18 equals the expected session pointer at this+0x8, reads the phase dword at session+0x4C and maps values 0 through 4 onto the same value stored at this+0xC; an unmapped phase leaves this+0xC unchanged. When the session pointers do not match, stores the fallback value 5 at this+0xC. Returns the stored this+0xC value in both paths.
    // GUARD: Compare the current session pointer at this+0x18 against the expected session pointer at this+0x8; equality selects the decode path, mismatch the fallback path. [field:this:0x00000018, field:this:0x00000008, source:raw]
    // STATE_TRANSITION: Read the phase dword at session+0x4C and switch on it via the jump table; cases 0 through 4 store the identical value into this+0xC, the default case leaves this+0xC unchanged. [field:this:0x0000004C, field:this:0x0000000C, global:0x0040CDBC, source:raw]
    // ASSIGNMENT: On session-pointer mismatch, store the fallback value 5 into this+0xC. [field:this:0x0000000C, source:raw]
    // RETURN: Return the stored phase value at this+0xC. [field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40CD60(this) {
    //     if (this[6] == this[2]) {
    //       switch (*(session + 0x4C)) {
    //         case 0: this[3] = 0; break;
    //         case 1: this[3] = 1; break;
    //         case 2: this[3] = 2; break;
    //         case 3: this[3] = 3; break;
    //         case 4: this[3] = 4; break;
    //         default: return this[3];
    //       }
    //       return this[3];
    //     }
    //     this[3] = 5;
    //     return this[3];
    //   }
    // UNRESOLVED: The jump table jpt_40CD70 at 0x0040CDBC implements the switch but the five target addresses are not individually evidenced; the identity mapping 0-4 to 0-4 comes from the raw source.
    // UNRESOLVED: The meaning of the phase enum values 0-4 (and the fallback 5) at the session object is unknown.
    // UNRESOLVED: Why some callers (audio controller, random state machine) share this decoder rather than owning it is not established.
}
