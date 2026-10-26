// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00534B10
// Canonical corpus name: sub_534B10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_534B10_00534b10.c

void UnknownObject::openFileStreamContext()
{
    // Allocates and initializes a file stream context object based on a mode string. Parses the mode characters ('r' sets read mode, 'w'/'a' set write mode, 'f' sets binary flag=1, 'h' sets flag=2), skips digit characters, and copies remaining characters into a scratch path buffer. Allocates a 16KB (0x4000) stream buffer, wires a memory-allocator object, resolves the underlying file handle either from an existing handle argument or by opening the path, writes the 'CCCC' header when opening for write, and validates the header when opening for read. On any allocation or open failure the partial context is freed through FileHandleDestructorWithModeCheck and 0 is returned.
    // GUARD: Abort and return 0 when the file path string a1 is null. [source:raw, function:0x00534B10]
    // GUARD: Abort and return 0 when the mode string a2 is null. [source:raw, function:0x00534B10]
    // CALL: Allocate a 97-byte stream context object via MallocWrapperForNhMalloc. [callee:0x0058A935]
    // GUARD: Abort and return 0 when the context allocation returns null. [source:raw]
    // ASSIGNMENT: Zero-initialize context dword fields at +0, +4, +12, +16, +32, +36, +40, +56, +60, +64, +68, +72, +80 and +88. [source:raw]
    // CALL: Create a memory allocator object at context +76 via sub_536E90(0). [callee:0x00536E90]
    // CALL: Allocate strlen(a1)+1 bytes for the file-name copy via MallocWrapperForNhMalloc; store at context +84. [callee:0x0058A935]
    // GUARD: Jump to cleanup when the name-buffer allocation fails. [source:raw]
    // ASSIGNMENT: Copy the path string a1 into the name buffer with strcpy. [source:raw]
    // LOOP: Parse the mode string a2: 'r' (0x72) sets the mode byte at context +92 to 'r', 'w' (0x77) or 'a' (0x61) sets it to 'w'; digit characters below 0x30 or above 0x39 are skipped; 'f' sets flags to 1, 'h' sets flags to 2; all remaining characters are copied into the scratch path buffer v18. Iterates until the NUL terminator or until the scratch buffer is full. [guard:0, guard:1, guard:2, guard:3, field:this:0x00000000, source:raw]
    // GUARD: Abort when the parsed mode byte at context +92 was never set. [source:raw]
    // CALL: Cleanup path: free the partial context via FileHandleDestructorWithModeCheck and return 0. [callee:0x00534EE0, source:raw]
    // RETURN: Return 0 on every failure path. [source:raw, function:0x00534B10]
    // CALL: Write mode (mode byte == 'w'): initialize the compression stream via sub_535C10(8, -15, 8, flags, a113_0, 56). [callee:0x00535C10, global:0x005DA7A0]
    // CALL: Write mode: allocate a 0x4000-byte output buffer via MallocWrapperForNhMalloc; store it at context +72 and +12. [callee:0x0058A935]
    // GUARD: Write mode: jump to cleanup when compression init failed or the output buffer is null. [source:raw]
    // CALL: Read mode (mode byte != 'w'): allocate a 0x4000-byte input buffer via MallocWrapperForNhMalloc; store it at context +68 and +0. [callee:0x0058A935]
    // CALL: Read mode: initialize the decompression stream via sub_5356A0(a113_0, 56). [callee:0x005356A0, global:0x005DA7A0]
    // GUARD: Read mode: jump to cleanup when decompression init failed or the input buffer is null. [source:raw]
    // ASSIGNMENT: Set the context buffer size at +16 to 0x4000. [source:raw]
    // ASSIGNMENT: Clear the thread-local-storage error slot via TLSOffsetGetter. [callee:0x0058AFCF]
    // CALL: Resolve the underlying file handle: when handle argument a3 is >= 0 open from it via sub_58AE69(a3, v18), otherwise open the path a1 via sub_587DB0(a1, v18); store the result at context +64. [callee:0x0058AE69, callee:0x00587DB0]
    // GUARD: Jump to cleanup when the resolved file handle is null. [source:raw]
    // CALL: Write mode: emit the 'CCCC' format header via StringFormatWithNestedIO(handle, aCCCCCCCCCC). [callee:0x005887B1, global:0x005DA788]
    // ASSIGNMENT: Write mode: set context +93 to 10. [source:raw]
    // CALL: Read mode: validate the stream header via sub_534D50(context). [callee:0x00534D50]
    // ASSIGNMENT: Read mode: set context +93 to FileSizeQueryWrapper(handle) minus the stored value at context +4. [callee:0x0058ACE6]
    // RETURN: Return the constructed file stream context object. [source:raw, function:0x00534B10]

    // Conservative worker pseudocode:
    //   void *openFileStreamContext(const char *path, const char *mode, int existingHandle) {
    //     if (!path || !mode) return 0;
    //     ctx = MallocWrapperForNhMalloc(97);
    //     if (!ctx) return 0;
    //     memset(ctx->dwords, 0, sizeof field area);
    //     ctx->allocator = sub_536E90(0);
    //     nameBuf = MallocWrapperForNhMalloc(strlen(path) + 1);
    //     ctx->name = nameBuf;
    //     if (!nameBuf) goto cleanup;
    //     strcpy(nameBuf, path);
    //     ctx->modeChar = 0;
    //     flags = 0; scratch = pathScratch;
    //     do {
    //       if (*mode == 'r') ctx->modeChar = 'r';
    //       if (*mode == 'w' || *mode == 'a') ctx->modeChar = 'w';
    //       if (*mode < '0' || *mode > '9') {
    //         if (*mode == 'f') flags = 1;
    //         else if (*mode == 'h') flags = 2;
    //         else *scratch++ = *mode;
    //       }
    //     } while (*mode++ && scratch < pathScratchEnd);
    //     if (!ctx->modeChar) goto cleanup;
    //     if (ctx->modeChar == 'w') {
    //       if (sub_535C10(8, -15, 8, flags, a113_0, 56)) goto cleanup;
    //       ctx->outBuf = ctx->bufA = MallocWrapperForNhMalloc(0x4000);
    //       if (!ctx->bufA) goto cleanup;
    //     } else {
    //       ctx->inBuf = ctx->bufB = MallocWrapperForNhMalloc(0x4000);
    //       if (sub_5356A0(a113_0, 56) || !ctx->bufB) goto cleanup;
    //     }
    //     ctx->bufSize = 0x4000;
    //     *TLSOffsetGetter() = 0;
    //     ctx->handle = (existingHandle >= 0) ? sub_58AE69(existingHandle, pathScratch)
    //                                       : sub_587DB0(path, pathScratch);
    //     if (!ctx->handle) goto cleanup;
    //     if (ctx->modeChar == 'w') {
    //       StringFormatWithNestedIO(ctx->handle, aCCCCCCCCCC);
    //       ctx->state = 10;
    //     } else {
    //       sub_534D50(ctx);
    //       ctx->state = FileSizeQueryWrapper(ctx->handle) - ctx->size;
    //     }
    //     return ctx;
    //   cleanup:
    //     FileHandleDestructorWithModeCheck(ctx);
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of context +93 state field: write mode sets a constant 10, read mode sets FileSizeQueryWrapper(handle) minus context +4; exact semantics unknown.
    // UNRESOLVED: Role of the scratch path buffer v18 passed to sub_58AE69 / sub_587DB0 is not established.
    // UNRESOLVED: Globals dword_5DA780 and dword_5DA784 appear in the packet evidence but not in the raw function text; their role is unidentified.
}
