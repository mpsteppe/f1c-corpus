// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB810
// Canonical corpus name: sub_4BB810
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BB810_004bb810.c

void UnknownObject::SessionLapDataAllocator()
{
    // Allocates and initializes per-lap session data. Resets the struct via StructResetReinitializer, sets mode flags (this+0xC = 2 and this+0x60 = 0 for session type dword_7C56A4 == 7, else 0 and 1), clears this+0x30, reads the lap count from dword_8ACF8C capped at 128 into this+0x88, allocates three arrays via OperatorNewNhMallocWrapper (two 4*lapCount float arrays at this+0x8C and this+0x90, one lapCount byte array at this+0x94), records the count, and fills every element: both float arrays with int -1082130432 (float -1.0f sentinel) and the byte array with 0.
    // STATE_TRANSITION: Invoked per frame from SceneRenderUpdate (frame-path enabled). [caller:0x004C6D90, function:0x004BB810]
    // CALL: StructResetReinitializer resets the struct state before allocation. [callee:0x004BB950]
    // ASSIGNMENT: Clear this+0x30; then set this+0xC = 2 and this+0x60 = 0 when session type dword_7C56A4 == 7, otherwise this+0xC = 0 and this+0x60 = 1. [field:this:0x00000030, field:this:0x0000000C, field:this:0x00000060, global:0x007C56A4]
    // GUARD: Read the lap count from dword_8ACF8C, cap at 128, and store into this+0x88. [global:0x008ACF8C, field:this:0x00000088]
    // CALL: Allocate three arrays via OperatorNewNhMallocWrapper: 4 * this+0x88 floats at this+0x8C, 4 * this+0x88 floats at this+0x90, and this+0x88 bytes at this+0x94. [callee:0x00587C03, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094]
    // ASSIGNMENT: Record the element count at this+0x94 and zero this+0x98. [field:this:0x00000094, field:this:0x00000098]
    // LOOP: Initialize each of the this+0x88 entries: both float arrays (this+0x8C, this+0x90) get int -1082130432 (IEEE-754 float -1.0f sentinel) and the byte array (this+0x94) gets 0. [field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094, field:this:0x00000088]
    // RETURN: Returns the element count. [source:raw]

    // Conservative worker pseudocode:
    //   StructResetReinitializer()
    //   this->dword[0x30] = 0
    //   if (dword_7C56A4 == 7) { this->dword[0xC] = 2; this->dword[0x60] = 0 }
    //   else { this->dword[0xC] = 0; this->dword[0x60] = 1 }
    //   count = min(dword_8ACF8C, 128)
    //   this->dword[0x88] = count
    //   this->ptr[0x8C] = OperatorNewNhMallocWrapper(4 * count)
    //   this->ptr[0x90] = OperatorNewNhMallocWrapper(4 * count)
    //   this->ptr[0x94] = OperatorNewNhMallocWrapper(count)
    //   this->dword[0x98] = 0
    //   for (result = 0; result < count; ++result) {
    //       this->ptr[0x8C][result] = -1082130432
    //       this->ptr[0x90][result] = -1082130432
    //       this->byte_ptr[0x94][result] = 0
    //   }
    //   return result
    // UNRESOLVED: Int literal -1082130432 equals the IEEE-754 float -1.0f bit pattern (DERIVED); the raw source only shows the integer.
    // UNRESOLVED: abi:lead LEGACY name Vehicle_Array_Buffer_Allocator conflicts with the SessionLapDataAllocator interpretation; owner remains UnknownObject.
}
