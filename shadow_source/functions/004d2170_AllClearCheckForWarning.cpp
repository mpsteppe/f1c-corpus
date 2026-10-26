// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D2170
// Canonical corpus name: sub_4D2170
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D2170_004d2170.c

void UnknownObject::AllClearCheckForWarning()
{
    // Readiness gate used by sub_4D4580 (0x004D4580): returns 1 when the stored trigger timestamp this+0xB4 plus 30 seconds is <= the session time dbl_8AFEA0 (cooldown elapsed) AND every vehicle in the array at dword_7C54F0 (count bounded by dword_5C329C) passes the per-vehicle check sub_4BC9B0 at base+16436 with zero flags; returns 0 when the cooldown has not elapsed or any vehicle fails. An empty field (vehicle count <= 0) trivially returns 1. All semantics DERIVED from raw source; owner UNKNOWN.
    // GUARD: Cooldown guard: this+0xB4 (last trigger timestamp) plus 30.0 must be <= session time dbl_8AFEA0. If not elapsed, skip the loop and return 0. [field:this:0x000000B4, global:0x008AFEA0, source:raw]
    // GUARD: Vehicle-count guard: if dword_5C329C (vehicle count) <= 0, return 1 immediately (trivially all vehicles pass). [global:0x005C329C, source:raw]
    // LOOP: Iterate v1 over the vehicle pointer array dword_7C54F0 while v1 < dword_5C329C; for each slot call sub_4BC9B0 on the vehicle base + 16436 with arguments (0, 0). If the whole array passes, return 1. [callee:0x004BC9B0, global:0x005C329C, global:0x007C54F0, source:raw]
    // RETURN: Return 1 when the cooldown elapsed and every vehicle passed sub_4BC9B0 (or the vehicle count is zero). [function:0x004D2170, source:raw]
    // RETURN: Return 0 when a vehicle fails sub_4BC9B0 (loop exits via the if) or when the cooldown has not elapsed. [function:0x004D2170, source:raw]
    // CALL: Per-vehicle readiness check: call sub_4BC9B0 with the vehicle object at dword_7C54F0[v1] + 16436 as first argument and two zero arguments; non-zero return keeps the loop going, zero return ends the loop with result 0. [callee:0x004BC9B0, global:0x007C54F0, source:raw]
    // UNKNOWN: Caller relationship: this gate is called by sub_4D4580 at 0x004D4580; the consumed result of the gate at that call site is outside this packet. [caller:0x004D4580, function:0x004D2170]

    // Conservative worker pseudocode:
    //   // Delayed all-clear check: cooldown expired AND every vehicle reports clear.
    //   bool AllClearCheckForWarning(float* this) {
    //       if (this[45] + 30.0 > dbl_8AFEA0) return false;   // cooldown not elapsed
    //       if (dword_5C329C <= 0) return true;               // no vehicles -> trivially clear
    //       for (int v1 = 0; v1 < dword_5C329C; ++v1) {
    //           if (!sub_4BC9B0((int*)(dword_7C54F0[v1] + 16436), 0, 0))
    //               return false;
    //       }
    //       return true;
    //   }
    // UNRESOLVED: Owner class of the this object (holding the last-trigger timestamp at +0xB4) is UNKNOWN.
    // UNRESOLVED: flt_59E468 is listed in the packet as a read global but does not appear in the raw source text; its role here is unexplained.
    // UNRESOLVED: The exact semantics of sub_4BC9B0 (which condition on the vehicle flags at +16436 makes a vehicle 'clear') are DERIVED from its boolean use, not proven.
    // UNRESOLVED: The meaning of the +16436 vehicle offset is DERIVED from the raw source (dword_7C54F0[v1] + 16436) and not independently identified.
}
