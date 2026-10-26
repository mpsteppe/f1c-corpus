// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005930E8
// Canonical corpus name: PEImageBaseAddressDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PEImageBaseAddressDetection_005930e8.c

void UnknownObject::ReadPEHeaderLinkerVersion()
{
    // Reads the current process image's PE optional-header linker version into the caller's buffer. After zeroing the output dword at a1, resolves the image base with GetModuleHandleA(0); when the image starts with the 'MZ' DOS signature word (23117) and the e_lfanew field (DWORD at index 15) is nonzero, walks from the DOS header to the PE header and stores the optional-header MajorLinkerVersion (byte +26) at a1 + 0 and MinorLinkerVersion (byte +27) at a1 + 1. Returns the minor linker version byte on success; otherwise returns the low byte of the unmodified module base (effectively 0 for 64 KB-aligned images).
    // ASSIGNMENT: Zero-initialize the caller's output buffer: *(DWORD *)a1 = 0. [field:this:0x00000000, source:raw]
    // CALL: Resolve the current process image base via GetModuleHandleA(0). [global:0x0059E21C, source:raw]
    // GUARD: Proceed only when the image starts with the 'MZ' DOS signature word (23117). [source:raw]
    // CALCULATION: Read the PE header offset v2 = *(DWORD *)(base + 15 dwords) (the e_lfanew field). [source:raw]
    // GUARD: Proceed only when v2 is nonzero (a PE header is present). [source:raw]
    // CALCULATION: Walk from the DOS header to the PE header: base += v2. [source:raw]
    // ASSIGNMENT: Store the optional-header MajorLinkerVersion (byte +26) at a1 + 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the optional-header MinorLinkerVersion (byte +27) at a1 + 1. [field:this:0x00000001, source:raw]
    // RETURN: Return the low byte of the (possibly advanced) image base: the minor linker version byte on the success path. [source:raw]
    // CALL: Called by sub_593115 (0x00593115). [caller:0x00593115]

    // Conservative worker pseudocode:
    //   char sub_5930E8(char *out) {
    //     *(DWORD *)out = 0;
    //     HMODULE img = GetModuleHandleA(0);
    //     if (*(WORD *)img == 23117) {
    //       int peOff = *((DWORD *)img + 15);
    //       if (peOff) {
    //         img = (HMODULE)((char *)img + peOff);
    //         out[0] = *(BYTE *)((char *)img + 26);
    //         out[1] = *(BYTE *)((char *)img + 27);
    //       }
    //     }
    //     return (char)img;
    //   }
    // UNRESOLVED: The packet canonical label PEImageBaseAddressDetection is a misnomer for this function; it reads the linker version, not the image base.
    // UNRESOLVED: The PE optional-header type (PE32 / PE32+) is not validated before reading bytes +26/+27.
    // UNRESOLVED: On the MZ-signature failure path the returned low byte of the module base has no meaningful use; the caller's (sub_593115) expectation is unknown.
}
