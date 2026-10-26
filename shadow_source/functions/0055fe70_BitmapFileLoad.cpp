// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055FE70
// Canonical corpus name: sub_55FE70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55FE70_0055fe70.c

void UnknownObject::BitmapFileLoad()
{
    // Loads a bitmap resource from the archive by filename. Validates the filename via sub_560230 (returning -2 with a logged message when it cannot be located), then reads the resource-table entry pointer from this[73] << 8 + this[74] (fields this+0x124 and this+0x128) and its two sizes at entry+8 and entry+12. Allocates two buffers, reads the bitmap data from the archive through the file handle at this+0x10 (either raw into the first buffer or processed via ThreadSafeReadWrapper_803f plus sub_59B260 into the second buffer depending on the entry flag byte), hands the loaded data to ResourceLoadWithOutput against the dword_8B78A0 (0x008B78A0) manager global, then frees both buffers and returns 0. Any failure frees both buffers, logs an error message and returns -1.
    // GUARD: If sub_560230(a2) returns nonzero (the bitmap file cannot be located), format the 'Could not locate bitmap file %s' message from the aCouldNotLocate (0x005DBD94) string into the local buffer via StringFormatWithBufferOverflowCheck, report it through sub_53C590 with level -2, and return -2. [callee:0x00560230, callee:0x0058815F, callee:0x0053C590, global:0x005DBD94, source:raw]
    // CALCULATION: Compute the resource-table entry pointer v10 = (this[73] << 8) + this[74], i.e. the byte index at this+0x124 shifted left 8 and added to the table base pointer at this+0x128, and read the two data sizes v15 and v16 from entry+8 and entry+12. [field:this:0x00000124, field:this:0x00000128, source:raw]
    // CALL: Allocate two buffers via OperatorNewNhMallocWrapper, sized v15 (entry+8) and v16 (entry+12), to hold the bitmap data. [callee:0x00587C03, field:this:0x00000124, field:this:0x00000128, source:raw]
    // GUARD: Branch on the flag byte at the resource-table entry (entry & 0x10): if set, read processed data into the second buffer via ThreadSafeReadWrapper_803f using the file handle at this+0x10 and post-process it with sub_59B260; otherwise read raw data into the first buffer. A short read or post-process failure jumps to the error path. [callee:0x0058803F, callee:0x0059B260, field:this:0x00000010, field:this:0x00000124, field:this:0x00000128, source:raw]
    // CALL: Call ResourceLoadWithOutput(dword_8B78A0, v12, v15, a3, a4, a5) to load the decoded bitmap data into the resource manager referenced by the dword_8B78A0 (0x008B78A0) global, returning output pointers through a3/a4. [callee:0x00540050, global:0x008B78A0, source:raw]
    // GUARD: On any load, read, or post-process failure, free both buffers, format the 'Error loading bit map %s' message from the aErrorLoadingBi (0x005DC608) string using the filename at entry+20, report it through sub_53C590 with level -1, and return -1. [callee:0x00587BCF, callee:0x0058815F, callee:0x0053C590, global:0x005DC608, source:raw]
    // RETURN: Success path: free both buffers and return 0. [callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   int BitmapFileLoad(char* name, void** outA, void** outB, int arg5) {
    //     if (sub_560230(name)) {
    //       StringFormatWithBufferOverflowCheck(buf, "Could not locate bitmap file %s", name);
    //       sub_53C590(-2, buf); return -2;
    //     }
    //     entry = (byte*)(this[73] << 8) + this[74];
    //     sizeRaw = *(int*)(entry + 8); sizeProc = *(int*)(entry + 12);
    //     bufRaw = OperatorNewNhMallocWrapper(sizeRaw);
    //     bufProc = OperatorNewNhMallocWrapper(sizeProc);
    //     if (entry[0] & 0x10) {
    //       if (ThreadSafeReadWrapper_803f(bufProc, 1, sizeProc, this[4]) != sizeProc || sub_59B260(bufProc, sizeProc)) goto fail;
    //     } else if (ThreadSafeReadWrapper_803f(bufRaw, 1, sizeRaw, this[4]) != sizeRaw) goto fail;
    //     if (ResourceLoadWithOutput(dword_8B78A0, bufRaw, sizeRaw, outA, outB, arg5)) goto fail;
    //     FreeWrapper_7bcf(bufRaw); FreeWrapper_7bcf(bufProc); return 0;
    //   fail:
    //     FreeWrapper_7bcf(bufRaw); FreeWrapper_7bcf(bufProc);
    //     StringFormatWithBufferOverflowCheck(buf, "Error loading bit map %s", entry + 20);
    //     sub_53C590(-1, buf); return -1;
    //   }
    // UNRESOLVED: The internal layout of the resource-table entry (flag byte semantics of entry & 0x10 and the filename at entry+20) is not further evidenced by this packet.
    // UNRESOLVED: What sub_59B260 does to the processed buffer (decompress/transform) is not visible in this packet.
    // UNRESOLVED: The a3/a4 output contract of ResourceLoadWithOutput is not evidenced here.
}
