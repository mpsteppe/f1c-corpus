// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592DFA
// Canonical corpus name: sub_592DFA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592DFA_00592dfa.c

void UnknownObject::GetEnvironmentStringsBlock()
{
    // Returns a malloc'd copy of the process environment strings block in a single encoding. The first call tries the Unicode variant (GetEnvironmentStringsW) and caches the winning variant in dword_8D41A8; on later calls the cache selects the path directly. The Unicode path sizes the block by scanning the double-NUL terminator, converts it to multibyte via WideCharToMultiByte into a MallocWrapperForNhMalloc buffer, and frees the buffer again if the conversion fails. The ANSI path copies the block with MemoryCopy_cc00. Returns NULL on any allocation, fetch, or conversion failure.
    // ASSIGNMENT: Initialize the return buffer and both environment-block pointers to NULL; read the cached variant flag dword_8D41A8. [global:0x008D41A8, source:raw]
    // GUARD: Branch on the cached flag: 0 = uninitialized, 1 = Unicode path selected, 2 = ANSI path selected; any other value returns NULL. [global:0x008D41A8, source:raw]
    // CALL: When uninitialized, fetch the Unicode environment block via GetEnvironmentStringsW; on success record flag 1 in dword_8D41A8. [global:0x0059E10C, global:0x008D41A8, source:raw]
    // LOOP: Measure the double-NUL-terminated Unicode block: scan to the final terminator and compute size = end - start + 1. [source:raw]
    // CALL: Query the required multibyte buffer size via WideCharToMultiByte with a NULL destination buffer. [global:0x0059E228, source:raw]
    // CALL: Allocate the buffer via MallocWrapperForNhMalloc and perform the WideCharToMultiByte conversion; on conversion failure free the buffer via sub_58AA6F and return NULL. [callee:0x0058A935, callee:0x0058AA6F, global:0x0059E228, source:raw]
    // CALL: Free the Unicode environment block via FreeEnvironmentStringsW and return the converted multibyte buffer. [global:0x0059E114, source:raw]
    // CALL: When uninitialized and the Unicode fetch failed (or the cached flag is 2), fetch the ANSI environment block via GetEnvironmentStrings; on success record flag 2 in dword_8D41A8. [global:0x0059E110, global:0x008D41A8, source:raw]
    // LOOP: Measure the double-NUL-terminated ANSI block: scan to the final terminator and compute size = end - start + 1. [source:raw]
    // CALL: Allocate a buffer via MallocWrapperForNhMalloc and copy the block with MemoryCopy_cc00; then free the ANSI block via FreeEnvironmentStringsA. [callee:0x0058A935, callee:0x0058CC00, global:0x0059E118, source:raw]
    // RETURN: Return the malloc'd environment block copy, or NULL on any fetch, allocation, or conversion failure path. [source:raw]

    // Conservative worker pseudocode:
    //   CHAR* GetEnvironmentStringsBlock() {
    //     CHAR* out = NULL;
    //     WCHAR* wenv = NULL;
    //     LPCH aenv = NULL;
    //     if (dword_8D41A8 == 1) goto unicode_path;
    //     if (dword_8D41A8 == 2) goto ansi_path;
    //     if (dword_8D41A8 != 0) return NULL;
    //     wenv = GetEnvironmentStringsW();
    //     if (!wenv) { aenv = GetEnvironmentStrings(); if (!aenv) return NULL; dword_8D41A8 = 2; goto ansi_path; }
    //     dword_8D41A8 = 1;
    //   unicode_path:
    //     if (!wenv) wenv = GetEnvironmentStringsW();
    //     if (!wenv) return NULL;
    //     { int len = 0; WCHAR* p = wenv; while (*p) { while (*p) ++p; ++p; } len = p - wenv; }
    //     int need = WideCharToMultiByte(0, 0, wenv, len, 0, 0, 0, 0);
    //     if (need) {
    //       CHAR* buf = (CHAR*)MallocWrapperForNhMalloc(need);
    //       if (buf) {
    //         if (!WideCharToMultiByte(0, 0, wenv, len, buf, need, 0, 0)) { sub_58AA6F(buf); buf = NULL; }
    //         out = buf;
    //       }
    //     }
    //     FreeEnvironmentStringsW(wenv);
    //     return out;
    //   ansi_path:
    //     if (!aenv) aenv = GetEnvironmentStrings();
    //     if (!aenv) return NULL;
    //     { int len = 0; LPCH p = aenv; while (*p) { while (*p) ++p; ++p; } len = p - aenv; }
    //     CHAR* buf = (CHAR*)MallocWrapperForNhMalloc(len);
    //     if (buf) MemoryCopy_cc00(buf, aenv, len);
    //     FreeEnvironmentStringsA(aenv);
    //     return buf;
    //   }
    // UNRESOLVED: Returned buffer lifetime is caller-managed (caller 0x0058A19E is expected to free it); the environment block is treated as the double-NUL-terminated CRT format.
    // UNRESOLVED: sub_58AA6F is inferred to free the buffer from its use immediately after a failed conversion; its full contract is outside this packet.
    // UNRESOLVED: The cached flag dword_8D41A8 persists across calls and assumes the process environment does not change between calls.
}
