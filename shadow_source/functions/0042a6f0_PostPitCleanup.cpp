// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042A6F0
// Canonical corpus name: PostPitCleanup
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/PostPitCleanup_0042a6f0.c

void F1CVehicle::PostPitCleanup()
{
    // Post-pit-exit cleanup. Fills a sentinel slot, reads the tire-change flag byte, increments a tire-change counter when the flag is clear, clears timeOfNextExit for race sessions (SessionType == 7), and sets the next pit exit timestamp to session time + 4.0. Returns the tire-change flag byte.
    // CALL: Call SentinelSlotFill on a slot address derived from this (this + 0x4034). [callee:0x004BD760, function:0x0042A6F0, source:raw]
    // ASSIGNMENT: Read the tire-change flag byte at this + 0x4584 and hold it as the return value. [field:this:0x00004584, source:raw]
    // GUARD: If the tire-change flag byte is zero, increment the tire-change counter dword at this + 0x45E0. [field:this:0x00004584, field:this:0x000045E0, source:raw]
    // GUARD: If SessionType global dword_7C56A4 equals 7, clear this + 0x4534 (timeOfNextExit). [global:0x007C56A4, source:raw]
    // ASSIGNMENT: Set this + 0x4534 (timeOfNextExit) to 0 when SessionType == 7. [field:this:0x00004534, global:0x007C56A4, source:raw]
    // ASSIGNMENT: Set this + 0x447C (next pit exit timestamp) to dbl_8AFEA0 (session time) + 4.0. [field:this:0x0000447C, global:0x008AFEA0, source:raw]
    // RETURN: Return the saved tire-change flag byte. [field:this:0x00004584, source:raw]

    // Conservative worker pseudocode:
    //   uint8_t PostPitCleanup(F1CVehicle* this) {
    //     SentinelSlotFill((uint8_t*)this + 0x4034);
    //     uint8_t result = *(uint8_t*)(this + 0x4584);
    //     if (result == 0) {
    //       ++*(uint32_t*)(this + 0x45E0);
    //     }
    //     if (dword_7C56A4 == 7) {
    //       *(uint32_t*)(this + 0x4534) = 0;
    //     }
    //     *(float*)(this + 0x447C) = (float)dbl_8AFEA0 + 4.0f;
    //     return result;
    //   }
    // UNRESOLVED: Packet lists global flt_59E46C (0x0059E46C) as read, but the raw source contains no use of it; it may be folded by the compiler or belong to a neighboring function.
    // UNRESOLVED: Slot base offset 0x4034 passed to SentinelSlotFill is not listed in the packet fields array; only described via the callee call.
}
