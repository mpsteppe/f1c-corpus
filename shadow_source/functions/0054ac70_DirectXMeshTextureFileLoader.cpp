// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054AC70
// Canonical corpus name: sub_54AC70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54AC70_0054ac70.c

void UnknownObject::DirectXMeshTextureFileLoader()
{
    // Loads and parses a binary mesh/texture file for the DirectX rendering pipeline. Reads the file through ThreadSafeReadWrapper_803f into the global buffers dword_8B8F30/dword_8B8F34 (optionally decompressed via sub_59B260 when a decryption context a5 and its flag bit 0x10 indicate so, otherwise a size probe via FileSizeQueryWrapper when a5 is null). Identifies the format by a 16-byte magic (aCubeMts410 texture vs aCubeMts401 mesh), builds the corresponding D3D resource (D3DTextureResourceCreation or DirectXMeshVertexBufferParsingAndLoading, first on a fresh object then on the existing context at dword_8B8F28+272), copies the payload into the caller's *a4 output buffer, walks the linked sub-object list calling sub_547710, then cleans up both buffers. Errors report through sub_53C590 with the aErrorAllocatin / aErrorReadingSc / aErrorReadingMe / aWrongMtsVersio strings and return -1.
    // GUARD: A non-null a5 context selects the indexed/compressed read branch; a null a5 falls back to a plain file-size probe. [source:raw]
    // CALCULATION: Compute the table offset v8 = a5[73]<<8 + a5[74] and read the format flag byte at v8 from the context table. [source:raw]
    // GUARD: Flag bit 0x10 on the table byte selects the compressed/decrypted sub-branch that reads through the secondary buffer dword_8B8F34. [source:raw]
    // CALL: Allocate dword_8B8F30 (size from table+8) and dword_8B8F34 (size v9 from table+12) via OperatorNewNhMallocWrapper, then ThreadSafeReadWrapper_803f(dword_8B8F34, 1, v9, a2) reads the compressed payload; a short read frees both buffers, clears the globals and returns -1. [callee:0x00587C03, global:0x008B8F30, global:0x008B8F34, callee:0x0058803F, callee:0x00587BCF, source:raw]
    // CALL: sub_59B260(dword_8B8F34, v9) decompresses the payload into the secondary buffer. [callee:0x0059B260, global:0x008B8F34, source:raw]
    // CALL: Uncompressed indexed path: size v31 read from table+8, allocate dword_8B8F30 for it, then ThreadSafeReadWrapper_803f(dword_8B8F30, 1, v31, a2). [callee:0x00587C03, global:0x008B8F30, callee:0x0058803F, source:raw]
    // CALCULATION: Null-context path: capture FileSizeQueryWrapper(a2), seek to end with sub_587F64(a2, 0, 2), re-query the size and subtract to get v31, then restore the position with sub_587F64(a2, v17, 0); allocate dword_8B8F30 and read the whole tail. [callee:0x0058ACE6, callee:0x00587F64, callee:0x00587C03, global:0x008B8F30, callee:0x0058803F, source:raw]
    // GUARD: If the read count v16 does not equal the expected v31, free dword_8B8F30, clear it and return -1. [global:0x008B8F30, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Reset the read cursor global dword_8B8F3C to 0 before parsing begins. [global:0x008B8F3C, source:raw]
    // CALL: Seed parser state: ShortComputation_a5b0() captures a base cursor, GlobalStateVariableSetter(dword_8B8F30, v11, 0) initializes the buffer cursor, and ArithmeticComparison_a5c0(v29, ...) reads the first 16 bytes of the magic which is strcmp'd against aCubeMts410 to choose the texture branch. [callee:0x0054A5B0, callee:0x0054A580, callee:0x0054A5C0, global:0x008B8F30, global:0x005DBFC0, source:raw]
    // CALL: Texture branch: allocate a 48-byte object, MultiFieldZeroInitConstructor(v24) initializes it, then D3DTextureResourceCreation(v21, this); on failure the object is EmptyStub_7470'd, freed, and sub_53C590(-1, aErrorAllocatin) reports before returning -1. [callee:0x00587C03, callee:0x005473D0, callee:0x00548190, callee:0x00557470, callee:0x00587BCF, callee:0x0053C590, global:0x005DBF9C, source:raw]
    // CALL: D3DTextureResourceCreation(*(dword_8B8F28 + 272), this) loads into the existing D3D context; a failure reports sub_53C590(-1, aErrorReadingSc) and returns -1. [global:0x008B8F28, callee:0x00548190, callee:0x0053C590, global:0x005DBF78, source:raw]
    // CALL: Texture payload copy: allocate *a4 with size a3 minus the consumed cursor, sub_54C320(0), then ArithmeticComparison_a5c0(*a4, dword_8B8F30, v25) copies the pixels; a mismatch frees *a4 (EmptyStub_7470 + FreeWrapper_7bcf), reports aErrorReadingMe and returns -1. [callee:0x00587C03, callee:0x0054C320, callee:0x0054A5C0, callee:0x00557470, callee:0x00587BCF, callee:0x0053C590, global:0x005DBF60, source:raw]
    // CALL: Mesh branch: allocate a 48-byte object and MultiFieldZeroInitConstructor it, then DirectXMeshVertexBufferParsingAndLoading(v15, this); on failure the object is EmptyStub_7470'd, freed, and sub_53C590(-1, aErrorAllocatin) reports before returning -1. [callee:0x00587C03, callee:0x005473D0, callee:0x00547B40, callee:0x00557470, callee:0x00587BCF, callee:0x0053C590, global:0x005DBF9C, source:raw]
    // CALL: DirectXMeshVertexBufferParsingAndLoading(*(dword_8B8F28 + 272), this) parses the mesh into the existing D3D context; failure reports sub_53C590(-1, aErrorReadingSc). [global:0x008B8F28, callee:0x00547B40, callee:0x0053C590, global:0x005DBF78, source:raw]
    // CALL: Allocate raw mesh buffer v19 of size v18 = consumed cursor - base + a3, call sub_54E9B0(0), then ArithmeticComparison_a5c0(v19, dword_8B8F30, v18) reads the mesh bytes; a mismatch jumps to the shared cleanup that frees v19 and reports aErrorReadingMe. [callee:0x00587C03, callee:0x0054E9B0, callee:0x0054A5C0, callee:0x00587BCF, callee:0x0053C590, global:0x005DBF60, source:raw]
    // GUARD: strcmp(v19, aCubeMts401) verifies the older mesh magic; a mismatch frees v19 and reports sub_53C590(-1, aWrongMtsVersio) before returning -1. [callee:0x00587BCF, callee:0x0053C590, global:0x005DBF50, global:0x005DBF3C, source:raw]
    // CALL: Mesh payload copy: allocate *a4 with size v20 = v18 + 96, call sub_54C320(0), qmemcpy(*a4 + 328, v19 + 232, v20 - 328), then sub_54B190(v19, *a4) performs the vertex/layout transform and v19 is freed. [callee:0x00587C03, callee:0x0054C320, callee:0x0054B190, callee:0x00587BCF, source:raw]
    // CALL: sub_54C510(v21, v22) finalizes the parsed object; a non-zero result returns -1. [callee:0x0054C510, source:raw]
    // CALL: BitmaskClear(64, 32, 0) clears the resource bitmask that guards the finalize walk. [callee:0x0054B330, source:raw]
    // LOOP: Walk the linked sub-object list starting at v21[9] via the +48-dword next pointer, calling sub_547710(v21, i) for each element. [callee:0x00547710, source:raw]
    // CALL: TwoListCleanup(v21) tears down the two parser lists, then EmptyStub_7470(v21) and FreeWrapper_7bcf(v21) release the parser object. [callee:0x00547420, callee:0x00557470, callee:0x00587BCF, source:raw]
    // CALL: Free dword_8B8F30 and dword_8B8F34 if still set, zero both globals, and return 0 on success; invoked by sub_54A870 (0054a870). [global:0x008B8F30, global:0x008B8F34, callee:0x00587BCF, function:0x0054AC70, caller:0x0054A870, source:raw]

    // Conservative worker pseudocode:
    //   int DirectXMeshTextureFileLoader(void *this, int fd, int a3, void **out, int ctx) {
    //     if (ctx) {
    //       v8 = ctx[73]<<8 + ctx[74];
    //       if (*(BYTE*)v8 & 0x10) {
    //         dword_8B8F30 = alloc(*(v8+8)); dword_8B8F34 = alloc(*(v8+12));
    //         if (read(dword_8B8F34, 1, *(v8+12), fd) != *(v8+12)) { free both; return -1; }
    //         sub_59B260(dword_8B8F34, *(v8+12));
    //       } else {
    //         v31 = *(v8+8); dword_8B8F30 = alloc(v31);
    //         if (read(dword_8B8F30, 1, v31, fd) != v31) { free; return -1; }
    //       }
    //     } else {
    //       v17 = filesize(fd); seek(fd, 0, 2); v31 = filesize(fd) - v17; seek(fd, v17, 0);
    //       dword_8B8F34 = 0; dword_8B8F30 = alloc(v31);
    //       if (read(dword_8B8F30, 1, v31, fd) != v31) { free; return -1; }
    //     }
    //     dword_8B8F3C = 0; base = ShortComputation_a5b0();
    //     GlobalStateVariableSetter(dword_8B8F30, base, 0);
    //     read magic16;
    //     if (!strcmp(magic, aCubeMts410)) {
    //       obj = ZeroInit(alloc(48));
    //       if (D3DTextureResourceCreation(obj, this)) { EmptyStub_7470(obj); free(obj); sub_53C590(-1, aErrorAllocatin); return -1; }
    //       if (D3DTextureResourceCreation(*(dword_8B8F28+272), this)) { sub_53C590(-1, aErrorReadingSc); return -1; }
    //       *out = alloc(a3 - ShortComputation_a5b0()); sub_54C320(0);
    //       if (ArithmeticComparison_a5c0(*out, dword_8B8F30, size) != size) { free(*out); sub_53C590(-1, aErrorReadingMe); return -1; }
    //       off = 0;
    //     } else {
    //       obj = ZeroInit(alloc(48));
    //       if (DirectXMeshVertexBufferParsingAndLoading(obj, this)) { free; sub_53C590(-1, aErrorAllocatin); return -1; }
    //       if (DirectXMeshVertexBufferParsingAndLoading(*(dword_8B8F28+272), this)) { sub_53C590(-1, aErrorReadingSc); return -1; }
    //       v18 = base - ShortComputation_a5b0() + a3; buf = alloc(v18); sub_54E9B0(0);
    //       if (ArithmeticComparison_a5c0(buf, dword_8B8F30, v18) != v18) { free(buf); sub_53C590(-1, aErrorReadingMe); return -1; }
    //       if (strcmp(buf, aCubeMts401)) { free(buf); sub_53C590(-1, aWrongMtsVersio); return -1; }
    //       *out = alloc(v18 + 96); sub_54C320(0);
    //       memcpy(*out+328, buf+232, v18+96-328); sub_54B190(buf, *out); free(buf);
    //       off = 96;
    //     }
    //     if (sub_54C510(obj, off)) return -1;
    //     BitmaskClear(64, 32, 0);
    //     for (i = obj[9]; i; i = i[48]) sub_547710(obj, i);
    //     TwoListCleanup(obj); EmptyStub_7470(obj); free(obj);
    //     if (dword_8B8F30) free(dword_8B8F30); if (dword_8B8F34) free(dword_8B8F34);
    //     dword_8B8F30 = dword_8B8F34 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The exact meaning of the format flag bit 0x10 and the layout of the a5 context table (+292/+296 and the +8/+12 size slots) come from the raw offsets only and are not defined here.
    // UNRESOLVED: The ownership semantics of the *a4 output buffer and the 96-byte header offset (328 = 232 + 96) are inferred from the surrounding arithmetic and are not independently verified.
}
