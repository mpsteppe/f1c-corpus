// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455E70
// Canonical corpus name: HWInput_Post
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HWInput_Post_00455e70.c

void UnknownObject::HWInput_Post()
{
    // HWInput post-frame teardown hook. Optionally logs a message when the session type is not 5 and the debug-log condition holds, fills collision data, destructs the array at a1 + 1376 when the a1[1637] flag is set, destructs the collision objects at a1 + 1121 and a1 + 866, cleans up collision culling at a1 + 1, and releases the DirectInput-style device interface behind *a1 (virtual method at vtable + 8) when present, clearing the pointer. Called by Game_Post.
    // GUARD: Log guard: if dword_7C569C != 5 and StringSplitLoop(2, aDDevF119992002_13, 5299) is true, write DebugLogWrite(&dword_8AD25C, aEnteredHwinput_3). [global:0x007C569C, callee:0x004D7A50, global:0x005C56A4, source:raw]
    // CALL: Write the post-entry message to the debug log buffer dword_8AD25C. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C571C, source:raw]
    // CALL: Fill collision data buffers: CollisionDataFill(a1 + 1, a2, 1). [callee:0x0044F070, source:raw]
    // GUARD: If the flag a1[1637] is nonzero, destruct the array at a1 + 1376 via ArrayDestructorViaVirtualDispatch. [callee:0x004526C0, source:raw]
    // CALL: Destruct the collision object at a1 + 1121 via CollisionObjectDestructor. [callee:0x0044FBE0, source:raw]
    // CALL: Destruct the collision object at a1 + 866 via CollisionObjectDestructor. [callee:0x0044FBE0, source:raw]
    // CALL: Clean up collision culling data at a1 + 1 via CollisionCullCleanup. [callee:0x0044EFE0, source:raw]
    // GUARD: Device release: result = *a1; if *a1 is nonzero, call the virtual Release method at offset 8 of its vtable and then clear *a1 = 0. [source:raw]
    // RETURN: Return the device release result (or the original *a1 value when it was zero). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_455E70(int* a1, int a2) {
    //     if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_13, 5299)) DebugLogWrite(&dword_8AD25C, aEnteredHwinput_3);
    //     CollisionDataFill(a1 + 1, a2, 1);
    //     if (a1[1637]) ArrayDestructorViaVirtualDispatch(a1 + 1376);
    //     CollisionObjectDestructor(a1 + 1121);
    //     CollisionObjectDestructor(a1 + 866);
    //     CollisionCullCleanup(a1 + 1);
    //     int result = *a1;
    //     if (*a1) { result = (*(int (__stdcall**)(int))(*(_DWORD*)result + 8))(*a1); *a1 = 0; }
    //     return result;
    //   }
    // UNRESOLVED: Identity of the virtual interface behind *a1 and of its Release method at vtable + 8 is not stated in the packet; inferred as a DirectInput-style device interface.
    // UNRESOLVED: Meaning of the a1[1637] presence flag and the array/collision objects at a1 + 1376, a1 + 1121 and a1 + 866 depends on the owner object layout, which this packet does not define.
    // UNRESOLVED: StringSplitLoop condition semantics (constants 2 and 5299) are not defined here.
}
