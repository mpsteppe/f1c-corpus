// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464D30
// Canonical corpus name: sub_464D30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_464D30_00464d30.c

void UnknownObject::CollisionStateReset()
{
    // Reinitializes a collision/physics-tracking state object. Stores the input pointer a2 into field this+0x0, resets the performance timer at this+0x4, sets the float at this+0x64 to 1.0f and clears this+0x60 and this+0x68, walks and frees four linked lists of allocated nodes (heads at this+0x6C, this+0x7C, this+0xE5B0 and this+0xE5C0) via FreeWrapper_7bcf, clears all list-head and trailing fields after each walk, reinitializes a collision-sensor array starting at this+0x8C with a 560-byte stride via CollisionSensorInit, clears this+0xE40C, and returns the CollisionSensorInit result.
    // ASSIGNMENT: Store the input pointer a2 into field this+0x0. [field:this:0x00000000, source:raw]
    // CALL: Reset the performance timer at this+0x4 via TimerResetUsingQueryPerformanceCounter(this + 1). [callee:0x00568C60, source:raw]
    // ASSIGNMENT: Set the float at this+0x64 (this[25]) to 1065353216 (1.0f), and clear this+0x68 (this[26]) and this+0x60 (this[24]) to 0. [field:this:0x00000064, field:this:0x00000068, field:this:0x00000060, source:raw]
    // LOOP: First linked-list walk: start at head this[27] (this+0x6C) and traverse nodes while the pointer is non-null; each node carries its next pointer at node+4 and a flag byte at node+8; when the flag byte is zero free the node payload *node, then always free the node itself via FreeWrapper_7bcf. [field:this:0x0000006C, field:*(this+0x70):0x00000004, guard:0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: After the first walk, clear the list state: this[27] = 0 (0x6C), this[28] = 0 (0x70), this[29] = 0 (0x74), this[30] = 0 (0x78). [field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, source:raw]
    // LOOP: Second linked-list walk: start at head this[31] (this+0x7C), traverse nodes while non-null, freeing node payload and node via FreeWrapper_7bcf exactly as the first walk. [field:this:0x0000007C, field:*(this+0x80):0x00000004, guard:1, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: After the second walk, clear the list state: this[31] = 0 (0x7C), this[32] = 0 (0x80), this[33] = 0 (0x84), this[34] = 0 (0x88). [field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, source:raw]
    // LOOP: Collision-sensor reinitialization: iterate the sensor array starting at this + 35 (this+0x8C) with a 560-byte stride, calling CollisionSensorInit on each entry; the decompiler renders the loop as a do/while driven by the internal variables v10/v11, so the exact iteration bound is not directly visible. [callee:0x00464A40, source:raw]
    // ASSIGNMENT: Clear this[14595] (this+0xE40C) to 0 after the sensor reinitialization. [field:this:0x0000E40C, source:raw]
    // LOOP: Third linked-list walk: start at head this[14700] (this+0xE5B0), traverse nodes while non-null, freeing node payload and node via FreeWrapper_7bcf. [field:this:0x0000E5B0, field:*(this+0xE5B4):0x00000004, guard:2, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: After the third walk, clear the list state: this[14700] = 0 (0xE5B0), this[14701] = 0 (0xE5B4), this[14702] = 0 (0xE5B8), this[14703] = 0 (0xE5BC). [field:this:0x0000E5B0, field:this:0x0000E5B4, field:this:0x0000E5B8, field:this:0x0000E5BC, source:raw]
    // LOOP: Fourth linked-list walk: start at head this[14704] (this+0xE5C0), traverse nodes while non-null, freeing node payload and node via FreeWrapper_7bcf. [field:this:0x0000E5C0, field:*(this+0xE5C4):0x00000004, guard:3, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: After the fourth walk, clear the list state: this[14704] = 0 (0xE5C0), this[14705] = 0 (0xE5C4), this[14706] = 0 (0xE5C8), this[14707] = 0 (0xE5CC). [field:this:0x0000E5C0, field:this:0x0000E5C4, field:this:0x0000E5C8, field:this:0x0000E5CC, source:raw]
    // RETURN: Return the last CollisionSensorInit result from the sensor-reinitialization loop. [function:0x00464D30, callee:0x00464A40, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = a2;
    //   TimerResetUsingQueryPerformanceCounter(this + 1);
    //   this[25] = 1.0f;  this[26] = 0;  this[24] = 0;
    //   for each list head in (this+0x6C, this+0x7C, this+0xE5B0, this+0xE5C0):
    //     while (node = head) {
    //       next = *(node + 4);
    //       if (*(byte*)(node + 8) == 0) FreeWrapper_7bcf(*(void**)node);
    //       FreeWrapper_7bcf(node);
    //       head = next;
    //     }
    //     clear head and the three trailing list-state fields;
    //   reinitialize collision sensors from this+0x8C with 560-byte stride via CollisionSensorInit;
    //   this[14595] = 0;
    //   return result;
    // UNRESOLVED: The four packet guards (guard:0..guard:3, fields 0x74 / 0x84 / 0xE5B8 / 0xE5C8 == 0) are attributed to the four linked-list walk terminators; the raw source tests the traversal pointer for null while the guard offsets are the trailing list-state fields cleared after each walk, so the exact guard-to-loop mapping is a reconstruction choice, not packet-stated.
    // UNRESOLVED: The linked-list node layout (next at node+4, flag byte at node+8, payload at node+0) is inferred from the uniform walk/free pattern and is not independently evidenced.
    // UNRESOLVED: The sensor do/while loop's iteration bound is obscured by the decompiler variables v10/v11; only the start (this+0x8C) and the 560-byte stride are visible.
    // UNRESOLVED: The semantics of the input value a2 stored at this+0x0 are not evidenced beyond the existing-analysis label postProcessInput (CONFIRMED in the fill, not independently reproduced here).
    // UNRESOLVED: The legacy ABI label 'Unidentified_464d30' (abi:lead) is generic and uninformative.
}
