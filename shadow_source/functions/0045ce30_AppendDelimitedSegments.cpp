// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045CE30
// Canonical corpus name: ShortComputation_ce30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_ce30_0045ce30.c

void UnknownObject::AppendDelimitedSegments()
{
    // String assembly helper (__fastcall). Copies the string at a1 into a local buffer, copies a2 into a second local buffer, runs both through ShortComputation_cf30 (0x0045CF30), then appends both transformed segments to a3 separated by the 16-bit global word_5C2AAC. Returns the length of the appended region measured from the original end of a3. The a1 copy is an inline byte loop (the v8 - a1 index is a fixed compiler-constant displacement), so the effective layout is: a3, word_5C2AAC, transform(a1), word_5C2AAC, transform(a2). Callers sit on debug/network formatting paths (DebugFloatFormatString, SceneTextureApply, BooleanParameterFormatDispatch, NetworkScorePingDisplay).
    // ASSIGNMENT: NUL-terminate both local buffers v8 and v9 (v8[0] = 0, v9[0] = 0) before use. [source:raw]
    // LOOP: Inline byte copy: copies the string at a1 into the local buffer v8 until the terminating NUL is consumed; the v8 - a1 index difference is a fixed compiler-time displacement, not a data-dependent pointer chase. [source:raw]
    // CALL: strcpy copies the second input a2 into the local buffer v9. [source:raw]
    // CALL: ShortComputation_cf30(v8) runs the first copied segment through the shared transform. [callee:0x0045CF30, source:raw]
    // CALL: ShortComputation_cf30(v9) runs the second copied segment through the same transform. [callee:0x0045CF30, source:raw]
    // CALCULATION: v6 = strlen(a3) + 1 records the first byte past the pre-existing a3 content; the appended region will be measured from there. [source:raw]
    // ASSIGNMENT: Writes the read-only 16-bit global word_5C2AAC at a3 + strlen(a3), overwriting the old NUL terminator as a separator word. [global:0x005C2AAC, source:raw]
    // CALL: strcat(a3, v8) appends the first transformed segment. [source:raw]
    // ASSIGNMENT: Writes word_5C2AAC again at the new end of a3, separating the two appended segments. [global:0x005C2AAC, source:raw]
    // CALL: strcat(a3, v9) appends the second transformed segment. [source:raw]
    // RETURN: Returns strlen(&a3[v6 - 1]), i.e. the length of the appended content starting at the original end of a3, including the inserted word_5C2AAC separators. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_45CE30(char* a1, const char* a2, char* a3) {
    //     char v8[64]; char v9[128];
    //     v8[0] = 0; v9[0] = 0;
    //     strcpy(v8, a1);
    //     strcpy(v9, a2);
    //     ShortComputation_cf30(v8);
    //     ShortComputation_cf30(v9);
    //     unsigned int v6 = strlen(a3) + 1;
    //     *(WORD*)&a3[strlen(a3)] = word_5C2AAC;
    //     strcat(a3, v8);
    //     *(WORD*)&a3[strlen(a3)] = word_5C2AAC;
    //     strcat(a3, v9);
    //     return strlen(&a3[v6 - 1]);
    //   }
    // UNRESOLVED: word_5C2AAC is a read-only 16-bit global inserted between segments; whether it is a visible delimiter or a record marker is not evidenced here.
    // UNRESOLVED: The transformation performed by ShortComputation_cf30 (0x0045CF30) is opaque from this packet; both segments pass through it.
    // UNRESOLVED: Callers span debug string formatting, scene texture apply and network score display; the concrete format being assembled is not established.
}
