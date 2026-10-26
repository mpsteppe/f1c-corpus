// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C2C0
// Canonical corpus name: EngineInitBlock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EngineInitBlock_0053c2c0.c

void UnknownObject::EngineInitBlock()
{
    // Engine-state block initializer: zeroes the whole block through GlobalZeroInit_c2a0, explicitly clears the first, second and eleventh dword fields, runs an init sub-routine with argument 1, writes three global engine/renderer constants (a flag zeroed, an audio mix constant 0x1000100010001 and a playback constant 0x100000000000000), flushes MMX state with _m_empty(), and returns the block pointer. Unconditional; no guards.
    // CALL: Zero-initialize the entire engine block via GlobalZeroInit_c2a0(this). [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Clear the first dword field: *this = 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the second dword field: this[1] = 0. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Clear the eleventh dword field (byte offset 0x2C): this[11] = 0. [field:this:0x0000002C, source:raw]
    // CALL: Run the init sub-routine sub_556260(1). [callee:0x00556260, source:raw]
    // ASSIGNMENT: Write global renderer/engine state flag: qword_8B6C20 = 0. [global:0x008B6C20, source:raw]
    // ASSIGNMENT: Write global audio mix constant: qword_8B8E40 = 0x1000100010001. [global:0x008B8E40, source:raw]
    // ASSIGNMENT: Write global audio playback constant: qword_8B8ED8 = 0x100000000000000. [global:0x008B8ED8, source:raw]
    // CALL: Flush MMX state via the _m_empty() intrinsic. [source:raw]
    // RETURN: Return the block pointer (this). [source:raw]
    // CALL: Invoked by SystemInitAllocatorWrapper (0x0053D470) during system initialization. [caller:0x0053D470]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   *this = 0; this[1] = 0; this[11] = 0;
    //   sub_556260(1);
    //   qword_8B6C20 = 0;
    //   qword_8B8E40 = 0x1000100010001;
    //   qword_8B8ED8 = 0x100000000000000;
    //   _m_empty();
    //   return this;
    // UNRESOLVED: unk_8B6BD0 is flagged by packet facts as read but appears nowhere in the raw decompiled source; its role is unverifiable here.
    // UNRESOLVED: The three global qword values have no grounded semantic label beyond the DERIVED audio/renderer hints in prior analysis.
}
