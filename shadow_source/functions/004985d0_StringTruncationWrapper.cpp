// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004985D0
// Canonical corpus name: StringTruncationWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringTruncationWrapper_004985d0.c

void UnknownObject::StringTruncationWrapper()
{
    // Renders a text string through TextRenderToSurface and, when the measured width (*a3) exceeds the caller's limit a2, truncates the string by nulling trailing characters one at a time and re-measuring until the width fits or the string is fully consumed. Returns 0 when the string is NULL, otherwise the last measured result (which is 0 when the string eventually fits or is emptied).
    // GUARD: Guard: all work happens only when the input string a3 is non-NULL; otherwise the function returns the initial result 0. [function:0x004985D0, source:raw]
    // ASSIGNMENT: Initializes result to 0 and v4 to the input string a3 before the guard. [source:raw]
    // ASSIGNMENT: When the string is present, resets the output pointers: a3 is set to 0 (via the local copy) and v9 to 0 before measurement. [function:0x004985D0, source:raw]
    // CALL: First measurement: TextRenderToSurface(this, v4, &a3, &v9, a4) computes the rendered width into a3 and height into v9. [callee:0x004983B0, function:0x004985D0, source:raw]
    // ASSIGNMENT: Sets result to a2 (the width limit) as the default return after the first measurement. [function:0x004985D0, source:raw]
    // GUARD: Guard: enters the truncation loop only when the measured width (int)a3 is greater than the limit a2. [function:0x004985D0, source:raw]
    // CALCULATION: Computes v7 = &v4[strlen(v4) + 1], a pointer one past the string's NUL terminator, as the starting point of backward truncation. [function:0x004985D0, source:raw]
    // LOOP: Truncation loop: while the measured width still exceeds a2, decrement v7, null the character now at v7 (removing one trailing character), and re-measure via TextRenderToSurface(this, v4, &a3, &v9, v8). The loop breaks early when v7 walks back to the start of the string (v4 == v7), so an emptied string also terminates the loop. [callee:0x004983B0, function:0x004985D0, source:raw]
    // RETURN: Returns result: 0 when the input string was NULL or the final measurement fits, otherwise the value of the last re-measurement. [function:0x004985D0, source:raw]

    // Conservative worker pseudocode:
    //   int StringTruncationWrapper(const char *self, int maxWidth, const char *text, char flags) {
    //     const char *orig = text;
    //     int result = 0;
    //     if (text) {
    //       int width = 0, height = 0;
    //       TextRenderToSurface(self, orig, &width, &height, flags);
    //       result = maxWidth;
    //       if (width > maxWidth) {
    //         result = 0;
    //         char *cur = (char *)&orig[strlen(orig) + 1];
    //         do {
    //           if ((const char *)cur == orig) break;
    //           *--cur = 0;
    //           result = TextRenderToSurface(self, orig, &width, &height, flags);
    //         } while (width > maxWidth);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: a3 is treated as both an output width pointer and, after the first call, the string source for re-measurement; the exact decompiler register reuse is an artifact, and the true parameter contract (single string vs. separate width output) is not fully resolved.
    // UNRESOLVED: The owning render object and the meaning of the a4 flag passed to TextRenderToSurface are outside this function's evidence.
}
