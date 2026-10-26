// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E38D0
// Canonical corpus name: TimerClampAndProcess
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerClampAndProcess_004e38d0.c

void UnknownObject::TimerClampAndProcess()
{
    // Clamps the timer/array counter at this[746] (offset 0xBA8) into [0, 11], then iterates count times calling DualArrayDestructor on each entry of a dual-array region starting at this+747 with a stride of 187 dwords (748 bytes). Resets the counter to 0 afterwards and returns the last counter value read. Used on the vehicle reset path via VehicleResetClear.
    // ASSIGNMENT: Read the counter at this[746] (offset 0xBA8) into local v2 before clamping. [field:this:0x00000BA8, source:raw]
    // GUARD: Clamp the counter: when v2 < 0 set this[746] = 0; when v2 > 11 set this[746] = 11; otherwise leave it unchanged. [field:this:0x00000BA8, source:raw]
    // LOOP: do-while loop over the clamped count using local counter v4, stepping the entry pointer v5 forward by 187 dwords per iteration. [field:this:0x00000BA8, source:raw]
    // CALL: Invoke DualArrayDestructor on the current entry pointer (this + 747 + i * 187); the counter this[746] is re-read each iteration for the loop condition. [callee:0x004DED20, field:this:0x00000BA8, source:raw]
    // ASSIGNMENT: Reset this[746] to 0 after the destruction loop. [field:this:0x00000BA8, source:raw]
    // RETURN: Return result, the last counter value read from this[746]. [field:this:0x00000BA8, source:raw]
    // CALL: Called by VehicleResetClear (0x004E09E0) as part of vehicle reset teardown. [caller:0x004E09E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4E38D0(_DWORD *this) {
    //     int n = this[746];
    //     if (n < 0) this[746] = 0;
    //     else if (n > 11) this[746] = 11;
    //     int result = this[746];
    //     for (int i = 0; i < result; ++i)
    //       DualArrayDestructor(this + 747 + i * 187);
    //     this[746] = 0;
    //     return result;
    //   }
    // UNRESOLVED: The element type and full capacity of the dual-array region starting at this+747 are not proven by the packet; only the counter at 0xBA8 and the 187-dword stride are evidenced.
    // UNRESOLVED: The clamp bounds [0, 11] suggest a bounded array of 11 tracked entries, but the storage layout beyond this[747] is unconfirmed.
    // UNRESOLVED: Ownership/class of the containing object is UNKNOWN; only the caller VehicleResetClear relationship is evidenced.
}
