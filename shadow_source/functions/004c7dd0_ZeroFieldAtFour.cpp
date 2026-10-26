// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7DD0
// Canonical corpus name: FieldZero4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldZero4_004c7dd0.c

void UnknownObject::ZeroFieldAtFour()
{
    // Thiscall helper that writes 0 into the DWORD field at offset +0x4 of the receiver object (this[1]). Unconditional single-field zeroing; used as a state/reset flag clear. Existing corpus analysis records that Sound_Restart (004C8B20) invokes it during audio restart, and that the field persists at 0 until written again.
    // ASSIGNMENT: Write 0 into the DWORD field at offset +0x4 of the receiver (this[1]). [field:this:0x00000004, source:raw]
    // CALL: Invoked by Sound_Restart (004C8B20) to reset the +0x4 field during an audio restart sequence. [caller:0x004C8B20]

    // Conservative worker pseudocode:
    //   void sub_4C7DD0(_DWORD* this) {
    //     this[1] = 0;
    //   }
    // UNRESOLVED: Identity of the receiver object class and the semantic meaning of the zeroed +0x4 field (candidate: state/reset flag per existing analysis) are not established from this packet.
    // UNRESOLVED: Whether the +0x4 field is genuinely a sound-related state flag depends on Sound_Restart (004C8B20), which is not evidenced here.
}
