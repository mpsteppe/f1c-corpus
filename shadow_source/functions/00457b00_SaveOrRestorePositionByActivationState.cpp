// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457B00
// Canonical corpus name: StateActivatedPositionSaveRestore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateActivatedPositionSaveRestore_00457b00.c

void UnknownObject::SaveOrRestorePositionByActivationState()
{
    // Saves or restores a 3-DWORD position vector based on an activation flag at this+0x9C. When the flag is clear and a2 equals 1, copies the current position (this+0x18, this+0x1C, this+0x20) into the saved slot (this+0x90, this+0x94, this+0x98) and sets the flag to 1. When the flag equals 1 and a2 is 0, VectorCopy restores the three DWORDs from the saved slot to the base position and clears the flag to 0. Called from CameraShake and CollisionResponseWithRandomPerturbation.
    // GUARD: Read the activation flag byte at this+0x9C and branch: the save path runs only when the flag is clear and a2 equals 1, the restore path only when the flag equals 1 and a2 is 0. [field:this:0x0000009C, source:raw]
    // GUARD: Restore branch: active when the flag at this+0x9C equals 1 and a2 is 0. [field:this:0x0000009C, source:raw]
    // CALL: VectorCopy copies three DWORDs from the saved position slot at this+0x90 to the base position at this+0x0. [callee:0x00456130, source:raw]
    // ASSIGNMENT: Clear the activation flag at this+0x9C to 0 after restoring the position. [field:this:0x0000009C, source:raw]
    // ASSIGNMENT: Save X: copy the value at this+0x18 into the saved slot at this+0x90. [field:this:0x00000018, field:this:0x00000090, source:raw]
    // ASSIGNMENT: Save Y: copy the value at this+0x1C into the saved slot at this+0x94. [field:this:0x0000001C, field:this:0x00000094, source:raw]
    // ASSIGNMENT: Save Z: copy the value at this+0x20 into the saved slot at this+0x98. [field:this:0x00000020, field:this:0x00000098, source:raw]
    // ASSIGNMENT: Set the activation flag at this+0x9C to 1, marking the position as saved. [field:this:0x0000009C, source:raw]
    // RETURN: Return the last byte value: the flag byte on the save and early-exit paths, or the VectorCopy result on the restore path. [source:raw]

    // Conservative worker pseudocode:
    //   // Save or restore a 3-DWORD position based on the activation flag at +0x9C.
    //   // flag = byte at this+0x9C; saved slot = this+0x90/0x94/0x98; current = this+0x18/0x1C/0x20
    //   if (flag != 0 || a2 != 1) {
    //     if (flag == 1 && a2 == 0) {
    //       VectorCopy(this, this + 0x90);   // saved slot -> base position (3 DWORDs)
    //       flag = 0;                        // this+0x9C
    //     }
    //   } else {
    //     *(dword*)(this + 0x90) = *(dword*)(this + 0x18);
    //     *(dword*)(this + 0x94) = *(dword*)(this + 0x1C);
    //     *(dword*)(this + 0x98) = *(dword*)(this + 0x20);
    //     flag = 1;                          // this+0x9C
    //   }
    //   return flag or VectorCopy result;
    // UNRESOLVED: Owner type and identity of the object that carries the current position, the saved slot and the activation flag are unknown.
    // UNRESOLVED: The meaning of the two activation states and the exact role of the base position written by VectorCopy depend on the callers CameraShake and CollisionResponseWithRandomPerturbation.
}
