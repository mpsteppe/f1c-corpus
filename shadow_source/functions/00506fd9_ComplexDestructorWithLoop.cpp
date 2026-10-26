// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00506FD9
// Canonical corpus name: ComplexDestructorWithLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ComplexDestructorWithLoop_00506fd9.c

void UnknownObject::ComplexDestructorWithLoop()
{
    // Object destructor that installs the off_5ADB90 vtable, frees a 2D slab of child entries via nested loops, then frees two buffer pointers and delegates final cleanup to VtableSetFreeChild. The object's dword index 1071 gates the loop body; index 1072 is the child-row pointer array, indices 1063..1064 bound the outer row loop and 1060..1062 bound the inner column loop (stride 4 dwords / 8 bytes, freeing the second dword of each entry). After the loops it frees index 1070 and index 1072 buffers, stores -1 in a stack marker slot, and returns VtableSetFreeChild(v2).
    // CALL: SEHHandlerInit initializes the structured-exception-handler frame for this function [callee:0x0058A5D8, source:raw]
    // ASSIGNMENT: Install the vtable: the object's first dword is set to the address of off_5ADB90 [global:0x005ADB90, source:raw]
    // ASSIGNMENT: Stack bookkeeping: stores the object pointer at (a1-20) and initializes the marker slot at (a1-4) to 0 [source:raw]
    // GUARD: Child-loop gate: the body only runs when the object's dword index 1071 (byte offset 0x10BC) is non-zero [source:raw]
    // GUARD: Loads the child-row pointer array v3 = index 1072 (byte offset 0x10C0); the loop body requires it to be non-null [source:raw]
    // GUARD: Row-range guard: the outer loop starts v4 = index 1063 (byte offset 0x109C) and only runs while v4 is below index 1064 (byte offset 0x10A0) [source:raw]
    // LOOP: Outer do/while loop walks rows from index 1063 while v4 remains below index 1064 [source:raw]
    // LOOP: Inner for loop walks columns i from index 1060 (byte offset 0x1090) to index 1062 (byte offset 0x1098) in steps of 4 dwords (8 bytes) [source:raw]
    // CALL: Per entry: FreeWrapper_7bcf frees the pointer stored at the second dword of the current 8-byte child entry [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Per entry: the walk pointer at (a1-16) advances by 8 bytes to reach the next child entry [source:raw]
    // CALL: FreeWrapper_7bcf frees the buffer stored at the object's dword index 1070 (byte offset 0x10B8) [callee:0x00587BCF, source:raw]
    // CALL: FreeWrapper_7bcf frees the child-row pointer array stored at the object's dword index 1072 (byte offset 0x10C0) [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: The stack marker slot at (a1-4) is set to -1 before delegating final cleanup [source:raw]
    // RETURN: Returns the result of VtableSetFreeChild(v2), which performs the final vtable reset and child-pointer free [callee:0x00506CCC, source:raw]

    // Conservative worker pseudocode:
    //   SEHHandlerInit();
    //   v2 = v1;
    //   *(a1 - 20) = v1;
    //   *v1 = &off_5ADB90;               // install vtable
    //   *(a1 - 4) = 0;
    //   if (v1[1071]) {
    //       v3 = v1[1072];
    //       if (v3) {
    //           v4 = v1[1063];
    //           *(a1 - 16) = v3;
    //           if (v4 < v1[1064]) {
    //               do {
    //                   for (i = v2[1060]; i < v2[1062]; i += 4) {
    //                       FreeWrapper_7bcf(*(LPVOID*)(*(a1 - 16) + 4));
    //                       *(a1 - 16) += 8;
    //                   }
    //                   ++v4;
    //               } while (v4 < v2[1064]);
    //           }
    //       }
    //   }
    //   FreeWrapper_7bcf((LPVOID)v2[1070]);
    //   FreeWrapper_7bcf((LPVOID)v2[1072]);
    //   *(a1 - 4) = -1;
    //   return VtableSetFreeChild(v2);
    // UNRESOLVED: loc_59C534 is the SEH jump target for the exception path; its role in this function is not visible in the decompiled body
    // UNRESOLVED: The exact storage layout of the freed 8-byte child entries (first dword unused, second dword a heap pointer) is inferred from the +4 dereference and +8 stride, not confirmed
    // UNRESOLVED: VtableSetFreeChild at 0x00506CCC is the final-cleanup delegate; its full behavior is outside this packet
}
