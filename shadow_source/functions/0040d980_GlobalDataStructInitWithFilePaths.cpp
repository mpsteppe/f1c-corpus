// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D980
// Canonical corpus name: GlobalDataStructInitWithFilePaths
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalDataStructInitWithFilePaths_0040d980.c

void UnknownObject::GlobalDataStructInitWithFilePaths()
{
    // Initializer for a global data structure. Runs ConstraintSolverParamInit on the sub-struct at this+20 bytes (this+5 DWORDs), zero-initializes the sub-struct at this+76 bytes (this+19 DWORDs) via StructZeroInit_7a00, then stores four global pointers (dword_5EA510, flt_5EA618, dword_5EB978, unk_5EC6D0) into pointer fields this+0x4..0x10, clears the head flag at this+0x0, re-initializes the this+19 sub-struct with F_9PointerArrayCleanup, clears six counter/index fields (this[33..36] and this[38..39] = offsets 0x84..0x90 and 0x98..0x9C), sets the byte threshold at this+0xA0 to 124, sets the sentinel field this+0x94 to -1, and returns this. Invoked by Wrapper_0030 (004D0030).
    // CALL: ConstraintSolverParamInit(this + 5) initializes the sub-struct starting at this+0x14 [callee:0x00434860, source:raw]
    // CALL: StructZeroInit_7a00(this + 19) zero-fills the sub-struct starting at this+0x4C [callee:0x00567A00, source:raw]
    // ASSIGNMENT: this[1] = &dword_5EA510, storing the global pointer into this+0x4 [field:this:0x00000004, global:0x005EA510, source:raw]
    // ASSIGNMENT: this[2] = &flt_5EA618, storing the global pointer into this+0x8 [field:this:0x00000008, global:0x005EA618, source:raw]
    // ASSIGNMENT: this[3] = &dword_5EB978, storing the global pointer into this+0xC [field:this:0x0000000C, global:0x005EB978, source:raw]
    // ASSIGNMENT: this[4] = &unk_5EC6D0, storing the global pointer into this+0x10 [field:this:0x00000010, global:0x005EC6D0, source:raw]
    // ASSIGNMENT: *this = 0, clearing the primary state/flags field at this+0x0 [field:this:0x00000000, source:raw]
    // CALL: F_9PointerArrayCleanup(this + 19) re-initializes the sub-struct at this+0x4C [callee:0x00567F10, source:raw]
    // ASSIGNMENT: this[33] = 0, this[34] = 0, this[35] = 0, this[36] = 0, clearing counter/index fields at offsets 0x84, 0x88, 0x8C, 0x90 [field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090, source:raw]
    // ASSIGNMENT: this[38] = 0, this[39] = 0, clearing counter/index fields at offsets 0x98 and 0x9C [field:this:0x00000098, field:this:0x0000009C, source:raw]
    // ASSIGNMENT: *((_BYTE *)this + 160) = 124, setting the byte threshold field at this+0xA0 to 124 [field:this:0x000000A0, source:raw]
    // ASSIGNMENT: this[37] = -1, setting the sentinel/invalid-index field at this+0x94 to -1 [field:this:0x00000094, source:raw]
    // RETURN: Return this (the initialized structure pointer) [function:0x0040D980, source:raw]
    // CALL: Invoked by Wrapper_0030 (004D0030) [caller:0x004D0030]

    // Conservative worker pseudocode:
    //   ConstraintSolverParamInit(this + 5);
    //   StructZeroInit_7a00(this + 19);
    //   this[1] = &dword_5EA510;
    //   this[2] = &flt_5EA618;
    //   this[3] = &dword_5EB978;
    //   this[4] = &unk_5EC6D0;
    //   *this = 0;
    //   F_9PointerArrayCleanup(this + 19);
    //   this[33] = 0; this[34] = 0; this[38] = 0; this[39] = 0;
    //   this[35] = 0; this[36] = 0;
    //   *((_BYTE *)this + 160) = 124;
    //   this[37] = -1;
    //   return this;
    // UNRESOLVED: The four stored global pointers (dword_5EA510, flt_5EA618, dword_5EB978, unk_5EC6D0) are only named as data locations; their referenced object types and purposes are not proven
    // UNRESOLVED: F_9PointerArrayCleanup is invoked on the same this+19 sub-struct that StructZeroInit_7a00 already initialized; whether this is a re-init or a distinct ownership action is unknown
    // UNRESOLVED: Field semantics for the cleared counter fields (0x84..0x90, 0x98, 0x9C), the byte threshold 0xA0 and the sentinel 0x94 are inferred from the fill analysis only
}
