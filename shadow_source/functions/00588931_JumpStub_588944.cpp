// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588931
// Canonical corpus name: sub_588931
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588931_00588931.c

void UnknownObject::JumpStub_588944()
{
    // Jump stub (JUMPOUT to 0x588944): the raw body only transfers control to 0x588944, forwarding argument a1. The real implementation continues at the jump target. The read of unk_5E63D0 (0x005E63D0) is not visible in this stub body. Called from sub_593C50.
    // STATE_TRANSITION: Transfers control to 0x588944 (JUMPOUT) with argument a1 forwarded unchanged; the function body continues at that address. [function:0x00588931, source:raw]

    // Conservative worker pseudocode:
    //   // JUMPOUT to 0x588944; body continues there
    // UNRESOLVED: Actual behavior lives at 0x588944, outside this stub.
    // UNRESOLVED: Read of unk_5E63D0 (0x005E63D0) is not visible in the JUMPOUT body; likely consumed by code at the jump target.
}
