// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541500
// Canonical corpus name: SceneStateSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneStateSetup_00541500.c

void UnknownObject::SceneStateSetup()
{
    // __thiscall scene-state creation. Bails out (returns 0) unless the guard flag at this+0x13D8 is non-zero. Builds a 26-dword parameter block on the stack, memset to zero, then fills it according to mode a2 (a2 == 1 sets indices 0 and 19 to type-specific values; a2 == 2 or 4 set index 0 to 1 and index 19 to the float square root of the FLT_MAX double constant). Defaults fill identity-like float bit patterns into several slots. Calls the object at this+0x1100 through vtable slot 176 (offset 0xB0) with (this+0x1100 object, this[1261], params) and stores the result into this[0]. Returns -1 on failure; on success increments the counter this+0x13B4 and returns its previous value.
    // GUARD: Guard on this[1270] (this+0x13D8) being non-zero; otherwise return 0 immediately. [field:this:0x000013D8, source:raw]
    // ASSIGNMENT: Zero the 26-dword stack parameter block v7 with memset(v7, 0, sizeof(v7)). [source:raw]
    // ASSIGNMENT: Mode a2 == 1: set v7[0] = 3 and v7[19] = 1399379109. [source:raw]
    // ASSIGNMENT: Mode a2 == 2 or a2 == 4: set v7[0] = 1 and the float at v7[19] = sqrt(3.402823466385289e38), the square root of the FLT_MAX double constant. [global:0x005AD208, source:raw]
    // ASSIGNMENT: Explicit zeroing: v7[18] = 0, memset(&v7[13], 0, 16), memset(&v7[9], 0, 12). [source:raw]
    // ASSIGNMENT: Load v4 = this[1261] (this+0x13B4) and v5 = this[1088] (this+0x1100). [field:this:0x000013B4, field:this:0x00001100, source:raw]
    // ASSIGNMENT: Default-initialize parameter slots with the numeric literals 1065353216 (v7[1], v7[2], v7[3], v7[5], v7[6], v7[7], v7[21]), -1082130432 (v7[17]) and 0 (v7[22], v7[23]); the literals are left as-is without decoding. [source:raw]
    // CALL: Indirect __stdcall call through vtable slot 176 (*(*v5 + 0xB0)) on the object at this+0x1100, passing (v5, v4, v7), and store the returned handle into *this (this+0x0). [field:*(this+0x1100):0x000000B0, field:this:0x00000000, source:raw]
    // GUARD: Guard on the creation result v6; if non-zero (failure), return -1. [source:raw]
    // ASSIGNMENT: Increment the scene-state counter: this[1261] (this+0x13B4) = result + 1, keeping the prior value as the return value. [field:this:0x000013B4, source:raw]
    // RETURN: Return the previous counter value on success, -1 on creation failure, or 0 when the guard flag is clear. [source:raw]
    // CALL: Called by StringCopyWithFlagUnion (0x0055D2A0) to create a scene state object. [caller:0x0055D2A0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_541500(int *this, int mode) {
    //     if (!this[1270]) return 0;
    //     _DWORD params[26];
    //     memset(params, 0, sizeof(params));
    //     if (mode == 1) { params[0] = 3; params[19] = 1399379109; }
    //     else if (mode == 2 || mode == 4) { params[0] = 1; *(float*)&params[19] = sqrt(3.402823466385289e38); }
    //     params[18] = 0;
    //     memset(&params[13], 0, 16);
    //     memset(&params[9], 0, 12);
    //     params[1] = 1065353216; params[2] = 1065353216; params[3] = 1065353216;
    //     params[5] = 1065353216; params[6] = 1065353216; params[7] = 1065353216;
    //     params[17] = -1082130432;
    //     params[21] = 1065353216; params[22] = 0; params[23] = 0;
    //     int handle = (*(int (__stdcall **)(int, int, _DWORD*))(*(_DWORD*)this[1088] + 176))(this[1088], this[1261], params);
    //     *this = handle;
    //     if (handle) return -1;
    //     int prev = this[1261];
    //     this[1261] = prev + 1;
    //     return prev;
    //   }
    // UNRESOLVED: Semantics of the three mode groups (a2 == 1 vs a2 == 2/4) and of the 26-dword parameter block layout are unknown.
    // UNRESOLVED: The literals 1065353216 and -1082130432 are plausibly IEEE-754 float bit patterns, but per evidence rules they are not decoded here.
    // UNRESOLVED: Meaning of the guard flag this+0x13D8 and the identity of the vtable-bearing object at this+0x1100 are unknown.
    // UNRESOLVED: The sqrt input constant 3.402823466385289e38 is recorded against the double global dbl_5AD208 (0x005AD208); its production site is not shown in this function.
}
