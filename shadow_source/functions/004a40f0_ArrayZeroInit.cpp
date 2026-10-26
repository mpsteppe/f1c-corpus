// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A40F0
// Canonical corpus name: ArrayZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayZeroInit_004a40f0.c

void UnknownObject::ArrayZeroInit()
{
    // Zero-initializes the struct pointed to by this: memsets the first 0x1A0 bytes to zero and explicitly writes DWORD 0 at offset 0x1A0 (this[104]), the trailing field just beyond the memset range, then returns 0. Existing analysis frames it as a full-struct reset called by Game_Restart (0x0042D7A0). Legacy ABI lead names it Array_Zero_Init.
    // ASSIGNMENT: Write DWORD 0 at this[104], i.e. offset 0x1A0, the trailing field beyond the memset range. [field:this:0x000001A0]
    // CALL: Call memset(this, 0, 0x1A0) to zero the first 0x1A0 bytes of the struct. [source:raw]
    // RETURN: Return integer result 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A40F0(int* this) {
    //     this[104] = 0;
    //     memset(this, 0, 0x1A0);
    //     return 0;
    //   }
    // UNRESOLVED: Struct type of this and the field name for offset 0x1A0 are unknown; memset is a library call absent from the packet callee list.
    // UNRESOLVED: Only known caller is Game_Restart (0x0042D7A0), consistent with the existing analysis note that this is a game-restart state reset.
}
