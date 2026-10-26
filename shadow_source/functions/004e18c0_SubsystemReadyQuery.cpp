// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E18C0
// Canonical corpus name: SubsystemReadyQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SubsystemReadyQuery_004e18c0.c

void UnknownObject::SubsystemReadyQuery()
{
    // Queries the readiness of a subsystem indexed by a2 (0-13). For subsystems 0-3 the check uses a 296-byte-stride slot array anchored at this+324; for subsystems 4-5 dedicated pointer and ready-byte fields at this+0x5E4/+0x624 and this+0x628/+0x668; for subsystems 6-13 a 68-byte-stride slot array anchored at this+1236. Returns 1 when the subsystem slot pointer is allocated AND its ready byte (offset+64) is zero, 0 otherwise. The default case (unknown index) returns 0.
    // STATE_TRANSITION: Dispatch on subsystem index a2 through the switch jump table jpt_4E18D0, partitioning into cases 0-3 (stride-296 array at this+324), cases 4-5 (dedicated fields), cases 6-13 (stride-68 array at this+1236), and the default case. [global:0x004E1948, source:raw]
    // GUARD: For subsystems 0-3 and 6-13: select slot pointer at 296*a2+this+324 (or 68*a2+this+1236) and treat the subsystem as not ready when the pointer is NULL or the ready byte at slot+64 is non-zero. [source:raw]
    // GUARD: For subsystem 4: check pointer this+0x5E4 (must be non-NULL) and dedicated ready byte this+0x624 (must be zero) before reporting ready. [field:this:0x000005E4, field:this:0x00000624, source:raw]
    // GUARD: For subsystem 5: check pointer this+0x628 (must be non-NULL) and dedicated ready byte this+0x668 (must be zero) before reporting ready. [field:this:0x00000628, field:this:0x00000668, source:raw]
    // RETURN: Return 1 for a ready subsystem (pointer allocated AND ready byte zero) and 0 otherwise, including for an out-of-range subsystem index. [source:raw]

    // Conservative worker pseudocode:
    //   int SubsystemReadyQuery(int this, int a2) {
    //     switch (a2) {
    //       case 0..3:  slot = (int*)(this + 324 + 296 * a2);
    //                   return slot != 0 && *(byte*)((char*)slot + 64) == 0 ? 1 : 0;
    //       case 4:     return *(int*)(this + 0x5E4) != 0 && *(byte*)(this + 0x624) == 0 ? 1 : 0;
    //       case 5:     return *(int*)(this + 0x628) != 0 && *(byte*)(this + 0x668) == 0 ? 1 : 0;
    //       case 6..13: slot = (int*)(this + 1236 + 68 * a2);
    //                   return slot != 0 && *(byte*)((char*)slot + 64) == 0 ? 1 : 0;
    //       default:    return 0;
    //     }
    //   }
    // UNRESOLVED: The stride-296 and stride-68 slot arrays (anchored at this+324 and this+1236) come from raw-source constants; the packet does not name the slot object or its owner.
    // UNRESOLVED: The exact meaning of the ready byte (offset+64 into each slot) is not stated by the packet; it is read as a boolean zero/non-zero flag.
    // UNRESOLVED: byte_4E1958 follows the jump table in memory and is flagged as data; it is not referenced by the function body.
    // UNRESOLVED: Callers SetupCarLightingAndRender and EffectDataTableInitialization show call sites but their subsystems/ownership semantics are not resolved.
}
