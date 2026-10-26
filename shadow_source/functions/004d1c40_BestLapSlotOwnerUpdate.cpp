// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1C40
// Canonical corpus name: sub_4D1C40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D1C40_004d1c40.c

void UnknownObject::BestLapSlotOwnerUpdate()
{
    // Per-slot best-lap-time ownership update. this is a byte array whose element this[a2+400] records which driver currently owns slot a2. A non-zero force flag a4 bypasses the comparison and forcibly installs a3 as the slot owner. Otherwise the current owner index is read, and ownership changes when the current owner is invalid (>= vehicle count dword_5C329C) or when the new driver's lap time (flt_5F0774 indexed by a2 + 4656*a3) is valid and no worse than the current owner's time (flt_5F0774 indexed by 4656*oldOwner + a2). On a takeover, AIOvertakeDefendStateChange is notified with the game-state pointer dword_5EB978, the slot, the new driver and the old driver, then the slot owner is written and 1 is returned; otherwise 0.
    // GUARD: If the force flag a4 is non-zero, control jumps directly to the assignment, skipping both the time comparison and the AI notification [source:raw]
    // CALCULATION: Read the current slot owner index as an unsigned byte at element this[a2+400] into v5 [source:raw]
    // GUARD: Takeover fires when the current owner index v5 is at or beyond the vehicle count dword_5C329C, i.e. the recorded owner is out of range and therefore invalid [global:0x005C329C, source:raw]
    // CALCULATION: Compute the new driver's lap-time table index v6 = a2 + 4656*a3 and the current owner's index 4656*v5 + a2, reading both times from the float table flt_5F0774 [global:0x005F0774, source:raw]
    // GUARD: Alternative takeover condition: the new time flt_5F0774[v6] is not the -1.0 invalid sentinel AND the current owner's time is at least the new time (new time no worse than the existing best) [global:0x005F0774, source:raw]
    // CALL: Notify AIOvertakeDefendStateChange with the game-state pointer dword_5EB978, the slot a2, the new driver a3 and the old owner index this[a2+400] (read before the assignment) [callee:0x00419690, global:0x005EB978, source:raw]
    // ASSIGNMENT: Write the new owner a3 into the slot element this[a2+400] [source:raw]
    // RETURN: Return 1 when the slot owner was updated (forced or takeover), 0 when the new time is invalid or the existing best is strictly better; invoked from the LapCompletion path (004BC4E0) [caller:0x004BC4E0, function:0x004D1C40, source:raw]

    // Conservative worker pseudocode:
    //   if (a4) goto assign;
    //   oldOwner = (byte)this[a2 + 400];
    //   validOwner = oldOwner < dword_5C329C;
    //   newTime = flt_5F0774[a2 + 4656*a3];
    //   oldTime = validOwner ? flt_5F0774[4656*oldOwner + a2] : 0;
    //   takeover = !validOwner || (newTime != -1.0 && oldTime >= newTime);
    //   if (takeover) {
    //     AIOvertakeDefendStateChange(dword_5EB978, a2, a3, oldOwner);
    //   assign:
    //     this[a2 + 400] = a3;
    //     return 1;
    //   }
    //   return 0;
    // UNRESOLVED: flt_59E670 is flagged as a packet global but appears nowhere in the raw decompiled source; its purpose cannot be established from this packet
    // UNRESOLVED: The 4656-byte stride of the flt_5F0774 lap-time table is not proven to be the vehicle struct stride from this function alone
}
