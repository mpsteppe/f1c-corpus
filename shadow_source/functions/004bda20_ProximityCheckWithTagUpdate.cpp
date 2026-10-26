// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BDA20
// Canonical corpus name: ProximityCheckWithTagUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProximityCheckWithTagUpdate_004bda20.c

void UnknownObject::ProximityCheckWithTagUpdate()
{
    // Proximity grid tag updater (sub_4BDA20, legacy ABI name Proximity_Check_with_Tag_Update). Iterates two dynamic arrays of child objects (first array: count at this[1]/offset 0x4, data pointer at this[2]/offset 0x8; second array: count at this[4]/offset 0x10, data pointer at this[5]/offset 0x14). In the first array each object whose tag v7[1] differs from a2 and whose type field v7[8] differs from a3 is retagged to a2 and dispatched through SwitchBasedStateHandler; the second array retags every object whose tag v13[1] differs from a2. Both loops gate on the decompiled x87 flag expression !(v9 | v10), whose real meaning is not evidenced. Returns this[4].
    // ASSIGNMENT: Read the first-array element count from this[1] (offset 0x4) and the second-array element count from this[4] (offset 0x10) as loop bounds. [field:this:0x00000004, field:this:0x00000010, source:raw]
    // LOOP: Iterate the first array for i in [0, count): element v7 = *(_DWORD **)(this[2] + 4*i) using the data pointer at this[2] (offset 0x8). [field:this:0x00000008, source:raw]
    // GUARD: First-array element guard: when the decompiled flag expression !(v9 | v10) holds and v7[8] != a3 and v7[1] != a2, proceed to retag the element. [source:raw]
    // ASSIGNMENT: Retag the first-array element v7[1] = a2 and dispatch its state transition with SwitchBasedStateHandler(v7, a3). [callee:0x0040F380, source:raw]
    // LOOP: Iterate the second array for j in [0, this[4]): element v13 = *(_DWORD **)(this[5] + 4*j) using the data pointer at this[5] (offset 0x14), re-reading the bound each iteration. [field:this:0x00000014, source:raw]
    // GUARD: Second-array element guard: when !(v15 | v16) holds and v13[1] != a2, proceed to retag the element (no type-field check in this loop). [source:raw]
    // ASSIGNMENT: Retag the second-array element v13[1] = a2 and dispatch its state transition with SwitchBasedStateHandler(v13, a3). [callee:0x0040F380, source:raw]
    // RETURN: Return this[4] (the second-array element count). [field:this:0x00000010, source:raw]
    // CALL: Called from GridCellIterate (0x004BE340) as part of the proximity grid cell iteration path. [caller:0x004BE340, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < this[1]; ++i) {
    //       v7 = *(_DWORD **)(this[2] + 4*i);
    //       if (!(v9 | v10) && v7[8] != a3 && v7[1] != a2) { v7[1] = a2; SwitchBasedStateHandler(v7, a3); }
    //   }
    //   for (j = 0; j < this[4]; ++j) {
    //       v13 = *(_DWORD **)(this[5] + 4*j);
    //       if (!(v15 | v16) && v13[1] != a2) { v13[1] = a2; SwitchBasedStateHandler(v13, a3); }
    //   }
    //   return this[4];
    // UNRESOLVED: The guards !(v9 | v10) and !(v15 | v16) read uninitialized locals from the decompiled x87/FPU comparison; the real flag semantics are not evidenced by the packet.
    // UNRESOLVED: Child object layout (tag field at [1], type field at [8]) is on the pointed-to object, not on the packet's this fields; only the dword indices are visible.
    // UNRESOLVED: The type-field check v7[8] != a3 appears only in the first loop; the second loop omits it, which may or may not be intentional.
}
