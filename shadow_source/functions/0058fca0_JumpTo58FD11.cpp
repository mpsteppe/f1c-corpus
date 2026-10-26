// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058FCA0
// Canonical corpus name: sub_58FCA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58FCA0_0058fca0.c

void UnknownObject::JumpTo58FD11()
{
    // Zero-body jump thunk: unconditionally transfers control to 0x58FD11 via JUMPOUT and never continues in this frame. No fields, globals, guards, callees, or subsystems are evidenced. The function is reached from 17 call sites.
    // RETURN: Unconditional control transfer (JUMPOUT) to 0x58FD11; execution never returns locally into this frame. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_58FCA0() {
    //     JUMPOUT(0x58FD11); // unconditional control transfer; no local return
    //   }
    // UNRESOLVED: JUMPOUT target 0x58FD11 has no packet callee entry; whether it is a tail call into another routine, a jump-table dispatch, or a plain JMP cannot be determined from this packet.
    // UNRESOLVED: Enclosing subsystem and object owner are unknown; the only evidence is the raw jump source and the 17 call sites.
}
