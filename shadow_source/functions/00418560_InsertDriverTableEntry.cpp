// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418560
// Canonical corpus name: InsertDriverTableEntry
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InsertDriverTableEntry_00418560.c

void UnknownObject::InsertDriverTableEntry()
{
    // Inserts an 8-DWORD entry into a 20-slot sorted driver table (first slot at this +0x86C, 32-byte stride). Validates the driver id (not -1) and a score threshold gate, fills entry fields from a driver-lookup table and a score computation, finds the insertion point by empty-slot/time/score ordering, shifts the intervening block with StructCopy, and copies the new entry in. Returns 1 on success, 0 on validation failure or when no insertion position is found. Part of AI/commentary scoring and ranking.
    // GUARD: Return 0 when the driver id (entry DWORD 0) equals -1. [source:raw]
    // CALL: Gate the driver id through ScoreThresholdGateCheck; return 0 when the id fails the threshold. [callee:0x00418B90, source:raw]
    // ASSIGNMENT: Set entry field 1 from the driver-lookup table: a2[1] = dword_5BF9B0[5 * driver_id]. [global:0x005BF9B0, source:raw]
    // CALL: Compute the driver score via ShortComputation_8b70(driver_id) and store it in entry field 7. [callee:0x00418B70, source:raw]
    // LOOP: Scan 20 table slots (first at this +0x86C, stride 8 DWORDs / 32 bytes) recording the candidate insertion index: an empty slot whose time equals -1.0 (0xBF800000), or a slot where the candidate time orders earlier, or equals with a higher score (comparison field at this +0x880 + slot*0x20). [field:this:0x0000086C, field:this:0x00000880, guard:0, source:raw]
    // LOOP: Shift the table block between the recorded boundary and insertion indices one slot (forward or backward) using StructCopy to free the insertion slot. [callee:0x004145C0, field:this:0x0000086C, source:raw]
    // ASSIGNMENT: Copy the incoming entry into the freed insertion slot via StructCopy. [callee:0x004145C0, field:this:0x0000086C, source:raw]
    // RETURN: Return 1 on successful insert, 0 when no valid insertion position was found. [function:0x00418560, source:raw]

    // Conservative worker pseudocode:
    //   if (*(int*)a2 == -1) return 0;
    //   if (!ScoreThresholdGateCheck(*(int*)a2)) return 0;
    //   a2[1] = dword_5BF9B0[5 * *(int*)a2];
    //   a2[7] = ShortComputation_8b70(*(int*)a2);
    //   for (i = 0; i < 20; i++) {
    //     slot = &this[8*i + 537];
    //     if (slot_time <= entry_time) boundary = i;
    //     if (insert < 0 && (slot_time == -1.0f || a2[2] < slot_time || (a2[2] == slot_time && a2[7] > slot_score))) insert = i;
    //   }
    //   if (insert < 0) return 0;
    //   shift block between boundary and insert via StructCopy;
    //   StructCopy(&this[8*insert + 537], a2);
    //   return 1;
    // UNRESOLVED: Semantics of dword_5BF9B0 (team/owner lookup vs other indexed table) and the 5-word stride are unconfirmed.
    // UNRESOLVED: Meaning of entry fields 2 (time) and 7 (score) relative to the scoring subsystem is inferred from sort ordering only.
    // UNRESOLVED: Slot type is 8 DWORDs; the shift/compare uses both float (time) and int (score) interpretations.
}
