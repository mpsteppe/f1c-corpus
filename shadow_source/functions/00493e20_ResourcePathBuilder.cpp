// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00493E20
// Canonical corpus name: ResourcePathBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourcePathBuilder_00493e20.c

void UnknownObject::ResourcePathBuilder()
{
    // Builds a resource file path into a 256-byte stack buffer by prepending a number of directory prefix strings derived from the parser nesting depth (4 * this[101]), then appending the filename a2 and a two-byte terminator word_5C30B4. Returns -1 when the filename is null or empty. When the write-mode flag at this+410 is set and the write stream this[1] exists, the assembled path is written to the stream via StringFormatWithNestedIO. Returns 0 on success.
    // ASSIGNMENT: Snapshot the this pointer and the filename argument a2 into locals before any buffer work. [source:raw]
    // CALCULATION: Compute the prefix repeat count v4 as 4 * this[101] (dword index 101, byte offset 0x194), the parser nesting depth. [field:this:0x00000194, source:raw]
    // ASSIGNMENT: Zero-initialize the 256-byte local path buffer v10. [source:raw]
    // GUARD: Guard: if the filename a2 is null, return -1. [source:raw]
    // GUARD: Guard: if the filename a2 is empty (strlen == 0), return -1. [source:raw]
    // LOOP: Repeat v4 times: choose the prefix string word_5C406C, or word_5C32D8 when the repeat count exceeds 4, and append the chosen prefix to the buffer with strcat. [global:0x005C406C, global:0x005C32D8, source:raw]
    // CALL: Append the filename a2 to the buffer with strcat after any prefix repetitions. [source:raw]
    // ASSIGNMENT: Append the two-byte terminator value word_5C30B4 at the end of the built string. [global:0x005C30B4, source:raw]
    // GUARD: Guard: proceed to stream output only when the write-mode flag byte at this+410 (offset 0x19A) is non-zero. [field:this:0x0000019A, source:raw]
    // CALL: Guard then call: if the write stream this[1] (byte offset 0x4) is non-zero, write the assembled path string to it via StringFormatWithNestedIO using the format string aS_4. [callee:0x005887B1, field:this:0x00000004, global:0x005C2C18, source:raw]
    // RETURN: Return 0 after a successful build (or -1 on the null/empty filename paths). [source:raw]

    // Conservative worker pseudocode:
    //   int ResourcePathBuilder(void *this, const char *filename) {
    //     char buf[256] = {0};
    //     if (!filename) return -1;
    //     if (strlen(filename) == 0) return -1;
    //     int count = 4 * this[101];
    //     for (int i = count; i > 0; --i) {
    //       const char *prefix = (count > 4) ? (const char *)&word_5C32D8 : (const char *)&word_5C406C;
    //       strcat(buf, prefix);
    //     }
    //     strcat(buf, filename);
    //     *(unsigned short *)(buf + strlen(buf)) = word_5C30B4;
    //     if (*(char *)((char *)this + 410)) {
    //       if (this[1]) StringFormatWithNestedIO(this[1], aS_4);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The exact contents of the prefix strings word_5C406C and word_5C32D8 and the terminator word_5C30B4 are not visible in the raw source; the directory/preference interpretation is DERIVED.
    // UNRESOLVED: StringFormatWithNestedIO is called with only the stream and format string here; the actual path text is not passed in the visible call, so how the buffer reaches the stream is unresolved.
    // UNRESOLVED: The relationship between the this pointer and the resource subsystem (parser owner object) is unresolved; owner stays UnknownObject.
}
