// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B92A
// Canonical corpus name: sub_58B92A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58B92A_0058b92a.c

void UnknownObject::DriveLetterPathResolution()
{
    // Resolves a file path to its absolute form. When FileName is non-NULL, validates it via sub_58B9FF, prepends a drive letter (low byte + 64, i.e. 'A'-'Z') and the ':.\' relative-path prefix in place, then calls GetFullPathNameA into a stack buffer. When FileName is NULL, calls GetCurrentDirectoryA instead. The resolved length (FullPathNameA + 1, including NUL) is bounds-checked against 0x104. Result is written into the caller-provided buffer (a2) when a2 is non-NULL and large enough, otherwise into memory allocated via MallocWrapperForNhMalloc. The final resolved-string copy/return is delegated to sub_58FCA0. Failure paths write TLS error codes (15 and 13 for validation failure, 34 for a too-small caller buffer, 12 for allocation failure) and return 0.
    // GUARD: Branch on FileName: non-NULL takes the drive-letter resolution path; NULL takes the GetCurrentDirectoryA path. [source:raw]
    // CALL: Validate FileName string format with sub_58B9FF; a zero return means validation failed. [callee:0x0058B9FF, source:raw]
    // GUARD: On sub_58B9FF failure, write TLS error code 15 through TLSOffsetGetter_afd8 and TLS error code 13 through TLSOffsetGetter, then return 0. [callee:0x0058AFCF, callee:0x0058AFD8, source:raw]
    // CALCULATION: Build the drive-letter relative path in place: low byte of FileName set to v3 + 64 ('A'-'Z'), followed by strcpy of ':.' at FileName + 1. [source:raw]
    // CALL: GetFullPathNameA resolves the drive-letter path into Buffer (capacity 0x104), capturing FilePart. [global:0x0059E184, source:raw]
    // CALL: GetCurrentDirectoryA copies the current working directory into Buffer (capacity 0x104). [global:0x0059E1B0, source:raw]
    // GUARD: A zero return from GetFullPathNameA or GetCurrentDirectoryA (FullPathNameA == 0) returns 0 without an error code. [global:0x0059E184, global:0x0059E1B0, source:raw]
    // CALCULATION: v6 = FullPathNameA + 1, the resolved path length including the terminating NUL. [source:raw]
    // GUARD: If unsigned v6 exceeds 0x104 the resolved path is too long; return 0 without an error code. [source:raw]
    // GUARD: Caller-provided buffer path (a2 != 0): if v6 > a3, write TLS error code 34 through TLSOffsetGetter and return 0. [callee:0x0058AFCF, source:raw]
    // CALCULATION: No caller buffer (a2 == 0): v6 = max(v6, a3), then v7 = MallocWrapperForNhMalloc(v6) allocates the output buffer. [callee:0x0058A935, source:raw]
    // GUARD: Allocation failure (v7 == 0) writes TLS error code 12 through TLSOffsetGetter and returns 0. [callee:0x0058AFCF, source:raw]
    // CALL: sub_58FCA0(v7) copies the resolved path into the output buffer; its return value becomes the function result. [callee:0x0058FCA0, source:raw]
    // RETURN: Return the result of sub_58FCA0 (resolved path buffer or 0 on failure). [callee:0x0058FCA0, source:raw]

    // Conservative worker pseudocode:
    //   // FileName: relative path (drive letter prepended in place); a2/a3: optional output buffer + capacity.
    //   if (FileName) {
    //       if (!sub_58B9FF(FileName)) { TLSOffsetGetter_afd8() = 15; TLSOffsetGetter() = 13; return 0; }
    //       (byte)FileName = (byte)FileName + 64;   // drive letter 'A'-'Z'
    //       strcpy((char*)&FileName + 1, ":.");  // relative-prefix
    //       len = GetFullPathNameA(&FileName, 0x104, Buffer, &FilePart);
    //   } else {
    //       len = GetCurrentDirectoryA(0x104, Buffer);
    //   }
    //   if (!len) return 0;
    //   need = len + 1;
    //   if ((unsigned)need > 0x104) return 0;
    //   if (a2) {
    //       if (need > a3) { TLSOffsetGetter() = 34; return 0; }
    //       out = a2;
    //   } else {
    //       if (need <= a3) need = a3;
    //       out = MallocWrapperForNhMalloc(need);
    //       if (!out) { TLSOffsetGetter() = 12; return 0; }
    //   }
    //   return sub_58FCA0(out);
    // UNRESOLVED: The exact semantics of sub_58FCA0 (single-field copy vs string copy) are not evidenced here; its return value is taken as the function result.
    // UNRESOLVED: The meaning of the TLS error codes 12/13/15/34 (alloc fail, validation fail, buffer too small) is DERIVED from caller context, not confirmed.
    // UNRESOLVED: Which drive letter results from v3 + 64 depends on the caller-supplied FileName; the target drive is not evidenced in this function.
    // UNRESOLVED: Whether the non-zero return is a pointer to the resolved path or a status code depends on sub_58FCA0's contract.
    // UNRESOLVED: Owner and class membership are unknown; the caller name SemaphoreGuardedQueryCall is itself a DERIVED proposal.
}
