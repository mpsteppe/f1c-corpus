// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BED6
// Canonical corpus name: AVIPlayerCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AVIPlayerCleanup_0045bed6.c

void UnknownObject::AVIPlayerCleanup()
{
    // Teardown of an AVI playback struct at a2 (with a1 as the sentinel value to test against). If the resource pointer at a2+68 (0x44) differs from a1 it is released via sub_53CB90 and the field is reset to a1; if the pointer at a2+80 (0x50) differs from a1 it is freed via FreeWrapper_7bcf and reset to a1. The struct is then zero-initialized by WideStructZeroInit(a2) and the AVI file system is shut down with AVIFileExit().
    // GUARD: Guard: only release the resource at a2+68 when its value differs from the sentinel a1. [source:raw]
    // CALL: Release the resource at offset +68 (0x44) via sub_53CB90. [callee:0x0053CB90, source:raw]
    // ASSIGNMENT: Reset a2+68 to the sentinel a1 after the release. [source:raw]
    // GUARD: Guard: only free the pointer at a2+80 when its value differs from the sentinel a1. [source:raw]
    // CALL: Free the heap resource at offset +80 (0x50) via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Reset a2+80 to the sentinel a1 after the free. [source:raw]
    // CALL: Zero-initialize the playback struct a2 via WideStructZeroInit. [callee:0x0045BF10, source:raw]
    // CALL: Shut down the AVI file system via AVIFileExit(). [source:raw]

    // Conservative worker pseudocode:
    //   if (*(DWORD*)(a2+68) != a1) {
    //     sub_53CB90(*(DWORD*)(a2+68));
    //     *(DWORD*)(a2+68) = a1;
    //   }
    //   if (*(DWORD*)(a2+80) != a1) {
    //     FreeWrapper_7bcf(*(LPVOID*)(a2+80));
    //     *(DWORD*)(a2+80) = a1;
    //   }
    //   WideStructZeroInit(a2);
    //   AVIFileExit();
    // UNRESOLVED: The global dword_8AFE64 (0x008AFE64) is flagged in packet facts as RaceTimeDelta (DERIVED) but appears nowhere in the raw decompiled source; its relationship to this function is not verifiable.
    // UNRESOLVED: The identity of the sentinel a1 value and the exact resource types held at offsets +68 (0x44) and +80 (0x50) are unknown from this function alone.
    // UNRESOLVED: AVIFileExit is named by the raw source but has no callee entry in the packet, so it is referenced through source:raw only.
}
