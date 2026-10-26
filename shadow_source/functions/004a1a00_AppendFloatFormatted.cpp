// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1A00
// Canonical corpus name: StringFormatCopyWithFloat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFormatCopyWithFloat_004a1a00.c

void UnknownObject::AppendFloatFormatted()
{
    // CRT-style string helper: reads the float pointed to by a2, formats it into a local buffer with the '%.5f' format string (literal at 0x005CD130) via StringFormatWithBufferOverflowCheck, then appends the formatted text to the destination string a1 with strcat. Always returns 0.
    // ASSIGNMENT: Read the value to format: v3 = *a2 (a float promoted to double). [source:raw]
    // ASSIGNMENT: Initialize the local buffer as an empty string: v4[0] = 0. [source:raw]
    // CALL: Format the value into the buffer: StringFormatWithBufferOverflowCheck(v4, "%.5f", v3); the format literal a5f lives at global 0x005CD130. [callee:0x0058815F, global:0x005CD130, source:raw]
    // CALL: Append the formatted text to the destination: strcat(a1, v4). [source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]
    // CALL: Invoked by ConfigKeyValueWrite (0x004B1E20) to append a float value while writing a config key. [caller:0x004B1E20, source:raw]

    // Conservative worker pseudocode:
    //   int AppendFloatFormatted(char *dest, float *value) {
    //     double v = *value;
    //     char buf[32];
    //     buf[0] = 0;
    //     StringFormatWithBufferOverflowCheck(buf, "%.5f", v);
    //     strcat(dest, buf);
    //     return 0;
    //   }
    // UNRESOLVED: The owner type is unknown; this is a standalone CRT-style helper with no class association evidenced.
    // UNRESOLVED: The destination buffer a1 capacity and lifetime are caller-managed; the strcat is safe only if the caller reserved enough space.
    // UNRESOLVED: Whether the fixed '%.5f' precision represents a specific game quantity (time, scalar, etc.) is not evidenced here.
}
