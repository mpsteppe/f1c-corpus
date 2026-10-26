// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8220
// Canonical corpus name: RaceInitWithConstants
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceInitWithConstants_004d8220.c

void UnknownObject::RaceInitWithConstants()
{
    // Unconditional race-struct initialization: calls a general struct utility, then stores two normalized values computed from global pixels at offsets 0xE4 and 0xE8 (this[57] = dword_5D6D60 * 0.00078125001, this[58] = dword_5D6D64 * 0.0009765625), then runs a sub-component init, five per-index batch inits for indices 1..5, an audio/timer init, and returns the result of a finalization step called with (-1, 0). No branches.
    // CALL: Call UtilityFunction_8720(this) general struct utility initialization. [callee:0x004D8720]
    // ASSIGNMENT: Set this[57] (offset 0xE4) to dword_5D6D60 * 0.00078125001. [field:this:0x000000E4, global:0x005D6D60]
    // ASSIGNMENT: Set this[58] (offset 0xE8) to dword_5D6D64 * 0.0009765625. [field:this:0x000000E8, global:0x005D6D64]
    // CALL: Call sub_4D8AB0(this) sub-component init. [callee:0x004D8AB0]
    // LOOP: Per-index batch init: sub_4D8CF0 called for indices 1 through 5. [callee:0x004D8CF0]
    // CALL: Call sub_4D88D0(this) audio/timer sub-component init. [callee:0x004D88D0]
    // CALL: Call sub_4D8760(-1, 0) finalization step; its result is returned. [callee:0x004D8760]
    // RETURN: Return the finalization step's result. [callee:0x004D8760, source:raw]

    // Conservative worker pseudocode:
    //   int RaceInitWithConstants(float* this) {
    //     UtilityFunction_8720(this);
    //     this[57] = (double)dword_5D6D60 * 0.00078125001;
    //     this[58] = (double)dword_5D6D64 * 0.0009765625;
    //     sub_4D8AB0(this);
    //     sub_4D8CF0(1); sub_4D8CF0(2); sub_4D8CF0(3); sub_4D8CF0(4); sub_4D8CF0(5);
    //     sub_4D88D0(this);
    //     return sub_4D8760(-1, 0);
    //   }
    // UNRESOLVED: The meanings of the scaled values at offsets 0xE4/0xE8 (fill labels them normalized screen dimensions, DERIVED; 0.00078125001 ~ 1/1280, 0.0009765625 ~ 1/1024) are not proven here.
    // UNRESOLVED: Globals flt_5ACF38 and flt_5ACF3C are listed as read but do not appear in the decompiled text; role unresolved.
    // UNRESOLVED: The semantics of the sub_4D8760 arguments (-1, 0) and its returned status are unknown.
    // UNRESOLVED: Owner is unknown; called only from OnScreen_Init (0049efa0).
}
