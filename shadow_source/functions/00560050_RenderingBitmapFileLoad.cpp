// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560050
// Canonical corpus name: sub_560050
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_560050_00560050.c

void UnknownObject::RenderingBitmapFileLoad()
{
    // Loads a bitmap file into the rendering composition system, gated by the audio-initialized global at 0x8B8E28. Validates the filename, resolves a resource-table entry through this+0x128 and this+0x124, allocates raw-data buffers, reads and optionally post-processes the bitmap data, hands it to RenderingCompositionSetup, then frees the buffers. Logs an error and returns a negative status on any failure.
    // GUARD: If sub_560230(a3) reports the filename as invalid, format the "Could not locate bitmap file %s" message via StringFormatWithBufferOverflowCheck, log it through sub_53C590(-2, v15) and return -2. [callee:0x00560230, callee:0x0058815F, callee:0x0053C590, global:0x005DBD94]
    // GUARD: If the initialization flag at dword_8B8E28 is set, proceed with the bitmap load path. [global:0x008B8E28]
    // CALCULATION: Resolve the resource-table entry: take the table pointer at this+0x128, index it by this+0x124 shifted left 8, and read the two size fields at entry+8 and entry+12. [field:this:0x00000128, field:this:0x00000124]
    // CALL: Allocate two raw-data buffers with OperatorNewNhMallocWrapper using the two sizes read from the resource entry. [callee:0x00587C03]
    // CALL: Read the bitmap data from the file handle at this+0x10 using ThreadSafeReadWrapper_803f; when the flag bit 0x10 of the resource entry is set, read into the second buffer and post-process it with sub_59B260, otherwise read into the first buffer, failing if the byte count does not match. [field:this:0x00000010, callee:0x0058803F, callee:0x0059B260]
    // CALL: Hand the loaded buffer to RenderingCompositionSetup(dword_8B78A0, v10, v13, a2, 1, 0) to register the bitmap in the composition system. [callee:0x0053FED0, global:0x008B78A0]
    // GUARD: On any read or setup failure: free both buffers via FreeWrapper_7bcf, format the "Error loading bit map %s" message using the entry filename, log it through sub_53C590(-1, v15) and return -1. [callee:0x00587BCF, callee:0x0058815F, callee:0x0053C590, global:0x005DC608]
    // CALL: Success path: free both allocated buffers with FreeWrapper_7bcf and return 0. [callee:0x00587BCF]

    // Conservative worker pseudocode:
    //   int RenderingBitmapFileLoad(DWORD* a2, const char* a3) {
    //     char msg[256];
    //     if (sub_560230(a3)) { StringFormatWithBufferOverflowCheck(msg, "Could not locate bitmap file %s", a3); sub_53C590(-2, msg); return -2; }
    //     if (dword_8B8E28) {
    //       int size1 = *(this+0x128 + (this[73]<<8) + 8);
    //       int size2 = *(this+0x128 + (this[73]<<8) + 12);
    //       void* buf1 = OperatorNewNhMallocWrapper(size1);
    //       void* buf2 = OperatorNewNhMallocWrapper(size2);
    //       int handle = this[4];
    //       bool ok;
    //       if (flag byte 0x10 set) ok = (ThreadSafeReadWrapper_803f(buf2, 1, size2, handle)==size2 && sub_59B260(buf2, size2)==0);
    //       else ok = (ThreadSafeReadWrapper_803f(buf1, 1, size1, handle)==size1);
    //       if (ok && !RenderingCompositionSetup(dword_8B78A0, buf1, size1, a2, 1, 0)) {
    //         FreeWrapper_7bcf(buf1); FreeWrapper_7bcf(buf2); return 0;
    //       }
    //       FreeWrapper_7bcf(buf1); FreeWrapper_7bcf(buf2);
    //       StringFormatWithBufferOverflowCheck(msg, "Error loading bit map %s", entryFilename);
    //       sub_53C590(-1, msg); return -1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Exact resource-table layout (what the fields at entry+8, entry+12 and entry+20 and the flag bit 0x10 encode) is unverified.
    // UNRESOLVED: Relationship between the entry at this+0x128 and the file handle at this+0x10 is not established; the object owning these fields is unknown.
    // UNRESOLVED: sub_59B260 post-processing semantics are unknown beyond 'decompress/transform'.
}
