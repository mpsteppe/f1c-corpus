// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C590
// Canonical corpus name: sub_53C590
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53C590_0053c590.c

void UnknownObject::CopyStringToGlobalBuffer()
{
    // Copies a null-terminated string from source pointer a2 into the global byte buffer byte_8B6AC8, including the terminating null, using a do-while loop indexed by the difference between the current source position and a2. Returns the source pointer advanced past the copied region. The int argument a1 is unused in the decompiled body. Matches the String_Copy_to_Global_Buffer ABI lead.
    // ASSIGNMENT: Initialize scan pointer result to the source pointer a2. [source:raw]
    // GUARD: Guard on a2 being non-null; when the source pointer is null the copy loop is skipped entirely. [source:raw]
    // LOOP: do-while loop over source characters; iterates while the previously loaded character is non-zero, so the terminating null is copied and the loop exits after it. [source:raw]
    // ASSIGNMENT: Load the current source character into v3. [source:raw]
    // ASSIGNMENT: Write the current source character into the global buffer byte_8B6AC8 at index (result - a2), forming a fixed-destination copy of the string into the global scratch buffer. [source:raw, global:0x008B6AC8, abi:lead]
    // CALCULATION: Advance the scan pointer result by one byte. [source:raw]
    // RETURN: Return result, the source pointer advanced one byte past the copied terminator. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_53C590(int a1, char *a2) {
    //     char *src = a2;
    //     if (src) {
    //       char c;
    //       do {
    //         c = *src;
    //         byte_8B6AC8[(src - a2)] = c;
    //         ++src;
    //       } while (c);
    //     }
    //     return src;
    //   }
    // UNRESOLVED: Role of the int argument a1: not referenced anywhere in the decompiled body.
    // UNRESOLVED: Size of the global buffer byte_8B6AC8 is unknown; there is no bounds guard, so a source string longer than the buffer would overrun it (unverified).
    // UNRESOLVED: Return pointer points one byte past the copied terminator rather than to the buffer start; whether callers use that pointer is not shown here.
}
