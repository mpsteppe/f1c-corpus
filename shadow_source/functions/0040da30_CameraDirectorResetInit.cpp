// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040DA30
// Canonical corpus name: CameraDirectorResetInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraDirectorResetInit_0040da30.c

void UnknownObject::CameraDirectorResetInit()
{
    // Resets the camera director object: saves and clears a byte flag at this+0xA0, sets the state at this+0x0 to 1, zeroes counter fields at this+0x84/0x8C/0x90/0x98/0x9C, conditionally clears a sub-object flag at *(this+0x4)+0x24, dispatches an in-progress session phase read from this+0x90, publishes the active vehicle pointer for the index at this+0x94 to globals dword_7C54DC/dword_7C54E0, clears the pointer array region at this+76, then ensures the sub-struct at this+0x88 exists (re-initializing an existing one or allocating and initializing a new 48-byte one), falling back to state -1 on allocation failure.
    // ASSIGNMENT: Save the byte flag at this+0xA0 (this[160]) into a local, set the state at this+0x0 to 1, and zero the counter fields at this+0x84, this+0x98 and this+0x9C. [field:this:0x000000A0, field:this:0x00000000, field:this:0x00000084, field:this:0x00000098, field:this:0x0000009C, source:raw]
    // GUARD: If the saved flag at this+0xA0 was set, clear the byte at offset +0x24 inside the sub-object pointed to by this+0x4. [field:*(this+0x4):0x00000024, field:this:0x00000004, source:raw]
    // CALL: Read the pending session phase from this+0x90, zero the flag at this+0xA0, and when the phase id is non-zero call SessionPhaseDispatchWithCascadeChecks(subobject at this+0x4, phase, 1). [field:this:0x00000090, field:this:0x000000A0, callee:0x0040D1B0, source:raw]
    // GUARD: If the vehicle/player index at this+0x94 is non-negative, look up the active pointer at dword_7C54F0[index] and publish the index to dword_7C54DC and the pointer to dword_7C54E0. [field:this:0x00000094, global:0x007C54F0, global:0x007C54DC, global:0x007C54E0, source:raw]
    // ASSIGNMENT: Reset the fields at this+0x8C and this+0x90 to zero and the vehicle index at this+0x94 to -1. [field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094, source:raw]
    // CALL: Run F_9PointerArrayCleanup on the pointer-array region at this+76 bytes (this + 0x4C). [callee:0x00567F10, source:raw]
    // GUARD: Ensure the sub-struct at this+0x88 is valid: if already present, re-initialize it with StructFieldInit; otherwise allocate 48 bytes via OperatorNewNhMallocWrapper, initialize it with SimpleSetterWithSubCall(new, this) and store the result at this+0x88 (storing 0 when allocation fails). [field:this:0x00000088, callee:0x0040D490, callee:0x00587C03, callee:0x0040D470, source:raw]
    // GUARD: If the sub-struct at this+0x88 is still null after the ensure step, set the state at this+0x0 to -1 as an error marker. [field:this:0x00000088, field:this:0x00000000, source:raw]
    // RETURN: Return the sub-struct pointer (the initialized existing object, the newly allocated object, or 0 on allocation failure). [source:raw]
    // CALL: Called by Steward_Restart (0x004D3CF0) and Steward_Post (0x004D4600) on session restart / post paths to reset camera director state. [caller:0x004D3CF0, caller:0x004D4600, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_40DA30(char *this) {
    //     char flag = this[0xA0];
    //     *(_DWORD*)this = 1;
    //     *(_DWORD*)(this + 0x84) = 0; *(_DWORD*)(this + 0x98) = 0; *(_DWORD*)(this + 0x9C) = 0;
    //     if (flag) *(_BYTE*)(*(_DWORD*)(this + 0x4) + 0x24) = 0;
    //     if (*(_DWORD*)(this + 0x90)) SessionPhaseDispatchWithCascadeChecks(*(_DWORD*)(this + 0x4), *(_DWORD*)(this + 0x90), 1);
    //     this[0xA0] = 0;
    //     if (*(_DWORD*)(this + 0x94) >= 0) {
    //       dword_7C54DC = *(_DWORD*)(this + 0x94);
    //       dword_7C54E0 = dword_7C54F0[dword_7C54DC];
    //     }
    //     *(_DWORD*)(this + 0x8C) = 0; *(_DWORD*)(this + 0x90) = 0; *(_DWORD*)(this + 0x94) = -1;
    //     F_9PointerArrayCleanup(this + 76);
    //     if (*(_DWORD*)(this + 0x88)) result = StructFieldInit(*(_DWORD*)(this + 0x88));
    //     else {
    //       _DWORD* obj = OperatorNewNhMallocWrapper(48);
    //       result = obj ? SimpleSetterWithSubCall(obj, (int)this) : 0;
    //       *(_DWORD*)(this + 0x88) = result;
    //     }
    //     if (!*(_DWORD*)(this + 0x88)) *(_DWORD*)this = -1;
    //     return result;
    //   }
    // UNRESOLVED: The identity of the sub-object at this+0x4 and the meaning of the cleared byte at its +0x24 are not established by this packet.
    // UNRESOLVED: The sub-struct at this+0x88 and the payload of the pointer array at this+76 are unknown beyond the allocation size 48.
    // UNRESOLVED: The state value 1 and error value -1 at this+0x0 are read from the literal assignments; the full state enum is unknown.
}
