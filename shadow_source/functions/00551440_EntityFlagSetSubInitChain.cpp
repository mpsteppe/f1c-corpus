// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551440
// Canonical corpus name: EntityFlagSetSubInitChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EntityFlagSetSubInitChain_00551440.c

void UnknownObject::EntityFlagSetSubInitChain()
{
    // Sets flag bits on the entity data struct, copies parameter-table data into per-entity data block 0, starts and resets a high-resolution timer via QueryPerformanceCounter, and zeroes the timer accumulator field. Returns the reset call's value.
    // CALCULATION: this[1] := (this[1] & 0xFFFE0FFF) | 0x2000 — mask the flags word at offset 0x4 with 0xFFFE0FFF and set flag bit 0x2000 [field:this:0x00000004, source:raw]
    // CALL: PerEntityDataBlockCopyFromParameterTable(this, 0, 0) — copy parameter-table data into per-entity data block index 0 [callee:0x00551390, source:raw]
    // CALL: TimerStartViaQueryPerformanceCounter(*this) — start the high-resolution timer using the handle stored at offset 0x0 [callee:0x005563E0, field:this:0x00000000, source:raw]
    // CALL: HighResolutionTimerReset(*this) — reset the high-resolution timer using the handle at offset 0x0; its return value becomes result [callee:0x00556440, field:this:0x00000000, source:raw]
    // ASSIGNMENT: this[4] := 0 — zero the timer accumulator field at offset 0x10 [field:this:0x00000010, source:raw]
    // RETURN: return result from HighResolutionTimerReset [function:0x00551440, source:raw]

    // Conservative worker pseudocode:
    //   this[1] = (this[1] & 0xFFFE0FFF) | 0x2000;
    //   PerEntityDataBlockCopyFromParameterTable(this, 0, 0);
    //   TimerStartViaQueryPerformanceCounter(*this);
    //   result = HighResolutionTimerReset(*this);
    //   this[4] = 0;
    //   return result;
    // UNRESOLVED: Meaning of the flag bits set/cleared in the flags word at offset 0x4 (mask 0xFFFE0FFF, set bit 0x2000) is unknown.
    // UNRESOLVED: Semantics of the handle at offset 0x0 used as the timer handle are unknown.
    // UNRESOLVED: The owning object type is unidentified; the this pointer is a generic _DWORD*.
}
