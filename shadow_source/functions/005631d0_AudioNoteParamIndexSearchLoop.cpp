// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005631D0
// Canonical corpus name: AudioNoteParamIndexSearchLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioNoteParamIndexSearchLoop_005631d0.c

void UnknownObject::AudioNoteParamIndexSearchLoop()
{
    // Linear search over an element array for an index whose element matches two criteria: its short field (via ShortFieldGetter, 005644A0) equals a3 and its value under sub_563E70 (00563E70) equals a2. Elements are reached through LinearInterpolation (005648B0) applied to the base pointer stored at a1+4. Returns the matching index, or -1 when a4 <= 0 or no element matches within the first a4 elements. Called by TwoStepDispatch (005631A0) and sub_563410 (00563410).
    // ASSIGNMENT: Initialize the search index v4 to 0. [source:raw]
    // GUARD: Guard on the element count a4: when a4 <= 0 the search is empty and the function returns -1 immediately. [source:raw]
    // LOOP: Iterate the index v4 from 0 upward while v4 < a4, breaking out early when a match is found. [source:raw]
    // CALCULATION: Resolve element pointer for index v4: call LinearInterpolation(*(DWORD*)(a1 + 4), v4) and dereference the returned pointer into v6. [callee:0x005648B0, source:raw]
    // CALL: Call ShortFieldGetter(v6) to extract a short field of the element at index v4. [callee:0x005644A0, source:raw]
    // CALL: Call sub_563E70(v6) to compute the element's comparison value at index v4. [callee:0x00563E70, source:raw]
    // GUARD: Match condition: break out of the loop when a3 == ShortFieldGetter(v6) AND sub_563E70(v6) == a2. [callee:0x00563E70, callee:0x005644A0, source:raw]
    // GUARD: Termination condition: after incrementing v4, if v4 >= a4 the search ends with no match and the function returns -1. [source:raw]
    // RETURN: Return the matching index v4 when the match condition holds, otherwise -1 for no match. [source:raw]
    // CALL: Called by TwoStepDispatch (005631A0) and sub_563410 (00563410) to locate an index by element content. [caller:0x005631A0, caller:0x00563410, source:raw]

    // Conservative worker pseudocode:
    //   int AudioNoteParamIndexSearchLoop(int a1, int a2, int a3, int a4) {
    //     for (int i = 0; i < a4; ++i) {
    //       int v6 = *(int*)LinearInterpolation(*(int*)(a1 + 4), i);
    //       if (a3 == ShortFieldGetter(v6) && sub_563E70(v6) == a2) return i;
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: The element array's element type and the base pointer stored at a1+4 are not defined here
    // UNRESOLVED: The semantics of sub_563E70 (00563E70) and the meaning of the ShortFieldGetter (005644A0) field are unknown; the exact match criteria cannot be interpreted beyond the equality test
    // UNRESOLVED: LinearInterpolation (005648B0) may not perform ordinary array indexing; its interpolation semantics are not defined in this function
}
