// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA150
// Canonical corpus name: ConditionalStateUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalStateUpdate_004ba150.c

void UnknownObject::ConditionalStateUpdate()
{
    // Session-flag-gated update: when the session active flag at this+0x0 equals 1 and the packed trigger flag read by PackedFlagRead_9a00 at this+2 is not set, loads the session time from dbl_8AFEA0 and passes it together with a pointer to the session message count dword_7D2E50 to CallWrapper_9870.
    // GUARD: Guard this[0] == 1: the session active flag must be set for the body to run. [field:this:0x00000000, guard:0, source:raw]
    // CALL: PackedFlagRead_9a00 reads a packed bit flag from this+2 used as the trigger check. [callee:0x004B9A00, source:raw]
    // GUARD: Guard the negated result of PackedFlagRead_9a00: the body only runs while the packed trigger flag at this+2 is not yet set. [callee:0x004B9A00, source:raw]
    // ASSIGNMENT: v2 = dbl_8AFEA0: load the current session time global. [global:0x008AFEA0, source:raw]
    // CALL: CallWrapper_9870(v1, &dword_7D2E50, 0, v2): process the session update passing the session message count dword_7D2E50 and the session time v2. [callee:0x004B9870, global:0x007D2E50, global:0x008AFEA0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4BA150(int *this) {
    //     if (this[0] == 1 && !PackedFlagRead_9a00(this + 2)) {
    //       double v2 = dbl_8AFEA0;
    //       CallWrapper_9870(v1, &dword_7D2E50, 0, v2);
    //     }
    //   }
    // UNRESOLVED: v1 (held in ecx) is read by CallWrapper_9870 but never assigned in this function; the packet's raw source leaves it undefined.
    // UNRESOLVED: The packed flag read by PackedFlagRead_9a00 at this+2 is a session/trigger flag; its bit layout and setter are not established in this packet.
}
