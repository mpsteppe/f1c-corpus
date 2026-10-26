// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559F00
// Canonical corpus name: sub_559F00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_559F00_00559f00.c

void UnknownObject::ParseUpTo4IntArgsFromLookup()
{
    // Calls sub_559D80(this, a2) to look up a property; if the lookup succeeds, seeds the parse position from this[195] (the token pointer at this+0x30C) plus one, then parses up to four integers with CallWrapperWith0 (each call advancing the shared position through a2). Each parsed value is stored into the corresponding optional output pointer a3, a4, a5 or a6 only when that pointer is non-null. Returns 1 when the lookup succeeded, 0 when it failed. Called by sub_55A060, sub_55A500, SceneNode and SceneFileTopLevelParser.
    // CALL: sub_559D80(this, a2) lookup that supplies the string content to parse; its non-zero result gates all parsing [callee:0x00559D80, source:raw]
    // GUARD: If the sub_559D80 lookup returns 0, skip parsing entirely and return 0 (failure) [callee:0x00559D80, source:raw]
    // ASSIGNMENT: Seed the parse position from this[195] (token pointer at this+0x30C) plus one, set the success flag v7 = 1, and store the seeded position back into a2 [field:this:0x0000030C, source:raw]
    // CALL: Parse the first integer with CallWrapperWith0 from the current position, advance the shared position, and store the result into *a3 when a3 is non-null [callee:0x00589278, source:raw]
    // CALL: Parse the second integer with CallWrapperWith0 from the current position, advance the shared position, and store the result into *a4 when a4 is non-null [callee:0x00589278, source:raw]
    // CALL: Parse the third integer with CallWrapperWith0 from the current position, advance the shared position, and store the result into *a5 when a5 is non-null [callee:0x00589278, source:raw]
    // CALL: Parse the fourth integer with CallWrapperWith0 from the current position and store the result into *a6 when a6 is non-null [callee:0x00589278, source:raw]
    // RETURN: Return the success flag v7 (1 if the lookup succeeded, 0 if it failed) [function:0x00559F00, source:raw]

    // Conservative worker pseudocode:
    //   int ParseUpTo4IntArgsFromLookup(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6) {
    //     int v7 = 0;
    //     if (sub_559D80(this, a2)) {
    //       int v10 = this[195] + 1;
    //       v7 = 1;
    //       a2 = v10;
    //       if (a3) { *a3 = CallWrapperWith0(v10, &a2, 10); v10 = a2 + 1; }
    //       if (a4) { *a4 = CallWrapperWith0(v10, &a2, 10); v10 = a2 + 1; }
    //       if (a5) { *a5 = CallWrapperWith0(v10, &a2, 10); v10 = a2 + 1; }
    //       if (a6) { *a6 = CallWrapperWith0(v10, &a2, 10); }
    //     }
    //     return v7;
    //   }
    // UNRESOLVED: The meaning of the constant 10 passed to CallWrapperWith0 and the exact string format consumed from the token pointer at this+0x30C are not established from this packet
    // UNRESOLVED: What sub_559D80 actually looks up, and why the parse position starts at this[195]+1, is not visible from this function alone
    // UNRESOLVED: The purpose of the four parsed integers for the callers (sub_55A060, sub_55A500, SceneNode, SceneFileTopLevelParser) is not established here
}
