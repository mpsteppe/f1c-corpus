// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00460CB0
// Canonical corpus name: ClearPlayerSlots
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClearPlayerSlots_00460cb0.c

void UnknownObject::ClearPlayerSlots()
{
    // Resets the player-slot bookkeeping on the session object: clears the slot count at this+0x3E14 to 0, sentinel-fills the two parallel 104-element arrays (node IDs at this+0x3C74, slot dwords at this+0x3E18) with -1, invokes UtilityFunction_a800 with the field at this+0x3FB8, and optionally zero-initializes each remaining slot struct. When the session phase at this+0x3FC4 is not 3, each slot entry at this+0x1D4 that is not already -1 is validated by linear search in the node-ID array; missing entries trigger a debug report and are reset to -1.
    // ASSIGNMENT: Player slot count at this+0x3E14 is reset to 0 [field:this:0x00003E14, source:raw]
    // LOOP: Two parallel 104-element arrays are sentinel-filled with -1: the node-ID array at this+0x3C74 and the slot dword array at this+0x3E18 [field:this:0x00003C74, field:this:0x00003E18, source:raw]
    // CALL: UtilityFunction_a800 is invoked with the object field read from this+0x3FB8 [callee:0x0057A800, field:this:0x00003FB8, source:raw]
    // GUARD: When argument a2 is non-zero, the per-slot struct initialization runs [source:raw]
    // LOOP: StructFieldZeroInitWithDefaults zero-initializes each remaining slot struct (140-byte stride) starting from the first unused entry (dword index 35*count+229) for (104-count) entries [callee:0x00461480, field:this:0x00003E14, source:raw]
    // GUARD: Slot validation only runs when the session phase at this+0x3FC4 is not 3 [guard:1, field:this:0x00003FC4, source:raw]
    // LOOP: Iterate over the 104 slot entries at this+0x1D4 [field:this:0x000001D4, source:raw]
    // GUARD: Only entries that are not the -1 sentinel are validated against the node-ID array [guard:0, field:this:0x000001D4, source:raw]
    // LOOP: Linear search of the current slot count entries in the node-ID array at this+0x3C74 for the slot entry's value [field:this:0x00003C74, field:this:0x00003E14, source:raw]
    // GUARD: When the value is not found (or the count is empty) and the session type dword_7C569C is not 5, the stale-slot debug report is emitted [global:0x007C569C, source:raw]
    // CALL: StringSplitLoop(1, aDDevF119992002_1, 4745) is a debug-initialization call; when it succeeds DebugLogWrite(&dword_8AD25C, aMarkingSlotDAs) writes the stale-slot marking message [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C5CE4, global:0x005C6098, global:0x008AD25C, source:raw]
    // ASSIGNMENT: The stale slot entry at this+0x1D4 is reset to -1 [field:this:0x000001D4, source:raw]
    // RETURN: Return the last validation result v5 (0 unless a stale-entry report path ran) [source:raw]
    // CALL: Invoked by NetCommPlayerSlotSync (0045fc50), SynchronizeWithServer (00464290) and SessionScoringUpdate (004643c0) [caller:0x0045FC50, caller:0x00464290, caller:0x004643C0]

    // Conservative worker pseudocode:
    //   this[3973] = 0;
    //   for (i = 0; i < 104; i++) { this[3869+i] = -1; this[3974+i] = -1; }
    //   UtilityFunction_a800(this[4078]);
    //   if (a2) for (e = &this[35*count+229]; i < 104-count; i++) StructFieldZeroInitWithDefaults(e += 140/4);
    //   if (this[4081] != 3) {
    //     for (i = 0; i < 104; i++) {
    //       if (this[117+i] != -1) {
    //         for (j = 0; j < count; j++) if (this[3869+j] == this[117+i]) break;
    //         if (j >= count) {
    //           if (dword_7C569C != 5) {
    //             StringSplitLoop(1, aDDevF119992002_1, 4745);
    //             DebugLogWrite(&dword_8AD25C, aMarkingSlotDAs);
    //           }
    //           this[117+i] = -1;
    //         }
    //       }
    //     }
    //   }
    //   return v5;
    // UNRESOLVED: Global dbl_8AFEA0 is listed as read by the function but has no visible role in the source; likely a debug timestamp consumed by the debug-log path at assembly level
    // UNRESOLVED: The semantic distinction between the node-ID array (this+0x3C74) and the slot dword array (this+0x3E18) is inferred from the validation lookup; both are bulk-initialized to -1 here
    // UNRESOLVED: The exact meaning of slot index arithmetic (35*count+229 dwords, 140-byte stride) for the slot structs is inferred from the fill, not proven
}
