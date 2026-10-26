// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00546430
// Canonical corpus name: FAILCallChainSaysAccumulatesButFunctionZEROS0x94
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILCallChainSaysAccumulatesButFunctionZEROS0x94_00546430.c

void UnknownObject::ResetCounterFieldsIfBitClear()
{
    // Conditionally resets two dword fields at this+0x94 and this+0x98 to zero when bit 2 of the byte at this+0x9C is clear; otherwise the function returns immediately and leaves both fields untouched. Despite the canonical call-chain name suggesting accumulation, the raw body only ever zeroes these fields, so this reads as a conditional state reset rather than an accumulation step.
    // GUARD: Read the byte at this+0x9C; if (value & 2) != 0, skip the zeroing block and fall through to the early return. [field:this:0x0000009C, source:raw]
    // ASSIGNMENT: Set result to 0. [source:raw]
    // ASSIGNMENT: Zero the dword field at this+148 (this+0x94). [field:this:0x00000094, source:raw]
    // ASSIGNMENT: Zero the dword field at this+152 (this+0x98). [field:this:0x00000098, source:raw]
    // RETURN: Return result, which is 0 on the zeroing path and unassigned on the guarded-out path. [source:raw]

    // Conservative worker pseudocode:
    //   int ResetCounterFieldsIfBitClear(void *this) {
    //     if ((*(unsigned char *)((char *)this + 0x9C) & 2) == 0) {
    //       *(unsigned int *)((char *)this + 0x94) = 0;
    //       *(unsigned int *)((char *)this + 0x98) = 0;
    //       return 0;
    //     }
    //     return <unassigned>;
    //   }
    // UNRESOLVED: Semantic purpose of the fields at this+0x94 and this+0x98 (canonical name implies accumulation, but the body only zeroes them).
    // UNRESOLVED: Meaning of bit 2 in the flag byte at this+0x9C.
    // UNRESOLVED: Return value on the guarded-out path is unassigned by the body.
    // UNRESOLVED: Invoked by LinkedListAccumulation (00548810); the reset may be a step in a larger accumulation flow whose context is not visible here.
}
