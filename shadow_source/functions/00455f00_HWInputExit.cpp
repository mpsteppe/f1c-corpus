// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455F00
// Canonical corpus name: HWInput_Exit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HWInput_Exit_00455f00.c

void UnknownObject::HWInputExit()
{
    // Hardware-input subsystem teardown. Logs an entry debug message, destructs two collision objects (this+1121 and this+866), cleans up the cursor resource (this+815) and collision culling (this+1), releases the DirectInput device via its vtable Release method and clears the stored pointer, then — when a global render flag is 1 — unloads the input module and marks this+0x1B10 as -1.
    // GUARD: StringSplitLoop(2, aDDevF119992002_13, 5321) gates the entry log; on non-zero DebugLogWrite(&dword_8AD25C, aEnteredHwinput_4) writes the HWInput exit-entry message [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C56A4, global:0x005C5734, global:0x008AD25C, source:raw]
    // CALL: CollisionObjectDestructor(this + 1121) destroys the first collision object in the manager [callee:0x0044FBE0, source:raw]
    // CALL: CollisionObjectDestructor(this + 866) destroys the second collision object in the manager [callee:0x0044FBE0, source:raw]
    // CALL: CursorResourceCleanup(this + 815) releases the cursor resource handles [callee:0x0044F5F0, source:raw]
    // CALL: CollisionCullCleanup(this + 1) cleans up the collision-culling data [callee:0x0044EFE0, source:raw]
    // GUARD: Device release only proceeds when the pointer at *this (obj) is non-zero [field:obj:0x00000000, source:raw]
    // CALL: Virtual Release call through the device vtable at obj+0x8 (offset 8) is made on *this, then this+0x0 is cleared to 0 [field:*(obj+0x0):0x00000008, field:this:0x00000000, source:raw]
    // ASSIGNMENT: this+0x0 is written to literal 0 after the device Release [field:this:0x00000000, source:raw]
    // GUARD: Module unload only runs when the global byte_7D13A0 equals 1 [global:0x007D13A0, source:raw]
    // CALL: ModuleUnload() unloads the input module; this[1732] (this+0x1B10) is then set to -1 [callee:0x004F8C90, field:this:0x00001B10, source:raw]
    // ASSIGNMENT: this+0x1B10 is written to -1 as the module-unloaded marker [field:this:0x00001B10, source:raw]
    // RETURN: Return the last result (device Release or ModuleUnload result); the function is invoked from GameExit (0x0042DB20) [caller:0x0042DB20, source:raw]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(2, aDDevF119992002_13, 5321)) DebugLogWrite(&dword_8AD25C, aEnteredHwinput_4);
    //   CollisionObjectDestructor(this + 1121);
    //   CollisionObjectDestructor(this + 866);
    //   CursorResourceCleanup(this + 815);
    //   CollisionCullCleanup(this + 1);
    //   result = (int)*this;
    //   if (*this) { result = (*(*(_DWORD*)*this + 8))(*this); *this = 0; }
    //   if (byte_7D13A0 == 1) { result = ModuleUnload(); this[1732] = (HCURSOR)-1; }
    //   return result;
    // UNRESOLVED: The element strides (this+1121, this+866, this+815, this+1, this[1732]) are raw-source element offsets; their byte equivalents are not packet evidence refs
    // UNRESOLVED: The identity of the object that owns this manager (abi lead 'HWInput_Exit') is not established beyond the legacy ABI name
    // UNRESOLVED: The render flag byte_7D13A0's exact meaning is not documented by this packet
}
