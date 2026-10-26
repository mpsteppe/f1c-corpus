// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D590
// Canonical corpus name: InputDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InputDispatch_0048d590.c

void UnknownObject::InputDispatch()
{
    // UI list navigation input dispatch: scans an array of a4 short input codes at a3 until it finds code 203 (previous) or 205 (next) or exhausts the array. A code-205 hit increments the selection (either the int32 index at this+0xE0 in integer mode, or a mutable counter behind the vtable slot at offset 0xB4 in pointer mode), a code-203 hit decrements it, then signals the change via the vtable slot at offset 0x2C and returns 1; otherwise returns 0.
    // ASSIGNMENT: Initialize result to 0 and the array counter v5 to 0. [source:raw]
    // GUARD: Guard on a4 (input code count) being greater than 0; when a4 is not positive, skip the scan and return result 0. [source:raw]
    // LOOP: Iterate the short array at a3 by dword index v5; the loop exits when the current code equals 203, when a 205 branch jumps past it, or when v5 reaches a4. [source:raw]
    // GUARD: Current short code at a3 + 2*v5 equal to 203 selects the decrement (previous) handling path. [source:raw]
    // GUARD: Current short code at a3 + 2*v5 equal to 205 selects the increment (next) handling path. [source:raw]
    // GUARD: The byte flag at this+0xF0 selects the storage mode: non-zero means pointer mode (mutate a counter object), zero means integer mode (mutate this[56]). [field:this:0x000000F0]
    // CALL: In pointer mode, resolve the mutable counter via the vtable slot at byte offset 0xB4 (this, a2); when it returns non-null, increment the pointed-to counter. [field:this:0x00000000, field:obj:0x000000B4]
    // CALL: After mutating the counter in pointer mode, invoke the post-update callback at vtable slot 0xA4. [field:this:0x00000000, field:obj:0x000000A4]
    // STATE_TRANSITION: Set a2 to 1, invoke the change signal at vtable slot 0x2C, and set result to 1 to record that navigation occurred. [field:this:0x00000000, field:obj:0x0000002C]
    // ASSIGNMENT: In integer mode, increment the selected index stored at this[56] (byte offset 0xE0). [field:this:0x000000E0]
    // CALL: In integer mode, run ShortComputation_8970 after the index change. [callee:0x00488970]
    // ASSIGNMENT: On code 203 (previous): in pointer mode decrement the counter resolved from vtable slot 0xB4 and invoke the 0xA4 callback; in integer mode decrement this[56] (byte offset 0xE0) and run ShortComputation_8970. [field:this:0x000000E0, field:obj:0x000000B4, field:obj:0x000000A4, callee:0x00488970, field:this:0x000000F0]
    // RETURN: Return result: 1 if any navigation code was processed, otherwise 0. [function:0x0048D590, source:raw]

    // Conservative worker pseudocode:
    //   char InputDispatch(void* this, int a2, short* a3, int a4) {
    //     char result = 0;
    //     int v5 = 0;
    //     if (a4 > 0) {
    //       while (a3[v5] != 203) {
    //         if (a3[v5] == 205) {
    //           if (*(char*)this + 240) {
    //             int* v7 = (*(int* (__thiscall **)(void*, int))(*(void**)this + 180))(this, a2);
    //             if (v7) { (*v7)++; (*(void (__thiscall **)(void*))(*(void**)this + 164))(this); a2 = 1; }
    //           } else {
    //             ((int*)this)[56]++; ShortComputation_8970(this);
    //           }
    //           a2 = 1;
    //           (*(void (__thiscall **)(void*))(*(void**)this + 44))(this);
    //           result = 1;
    //           goto done;
    //         }
    //         if (++v5 >= a4) return result;
    //       }
    //       if (*(char*)this + 240) {
    //         int* v8 = (*(int* (__thiscall **)(void*, int))(*(void**)this + 180))(this, a2);
    //         if (v8) { (*v8)--; (*(void (__thiscall **)(void*))(*(void**)this + 164))(this); }
    //       } else {
    //         ((int*)this)[56]--; ShortComputation_8970(this);
    //       }
    //       a2 = 1;
    //       (*(void (__thiscall **)(void*))(*(void**)this + 44))(this);
    //       result = 1;
    //     done:;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The storage-mode byte at this+0xF0 and the pointer-mode counter resolved through vtable slot 0xB4 are not fully classified; the distinction is inferred from the two parallel mutation paths.
    // UNRESOLVED: Semantic meaning of input codes 203 and 205 as previous/next navigation is taken from existing analysis and not independently proven.
    // UNRESOLVED: The purpose of argument a2 and why it is reset to 1 after processing is not resolved.
}
