// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00518BD4
// Canonical corpus name: sub_518BD4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_518BD4_00518bd4.c

void UnknownObject::PngIendChunkHandler()
{
    // PNG IEND (image end) chunk handler. Reads the image-state flag register at this+0x58 and, when both the bit 0 (0x1) and bit 2 (0x4) flags are set (image data present), sets the done bits 0x18, warns through CallbackDispatch with the 'Incorrect IEND chunk length' string when the chunk length a3 is non-zero, and runs the CRC error check sub_518828 before returning its result. When either flag is clear it calls GuardedCallWithLongjmp with the 'No image in file' string and returns its result when a2 is zero.
    // ASSIGNMENT: Read the image-state flag register dword at this+0x58 into v3 [field:this:0x00000058, source:raw]
    // GUARD: Guard: the image-present branch requires both bit 0 (0x1, IHDR seen) and bit 2 (0x4, IDAT seen) set; when either is clear, GuardedCallWithLongjmp(a1, 'No image in file') is evaluated into result and the block still runs when a2 is non-zero [field:this:0x00000058, callee:0x00511869, global:0x005AFD1C, source:raw]
    // ASSIGNMENT: Set the done bits 0x18 on the flag register at this+0x58 (unconditional inside the image-present branch) [field:this:0x00000058, source:raw]
    // GUARD: Guard: when the IEND chunk length a3 is non-zero, dispatch the 'Incorrect IEND chunk length' warning through CallbackDispatch(a1, ...) [callee:0x00511887, global:0x005AFD00, source:raw]
    // CALL: Run the CRC error check sub_518828(a1, a3); its return value is returned as the function result [callee:0x00518828, source:raw]
    // RETURN: Return: when the guard fails, return the GuardedCallWithLongjmp result; called from sub_5119E9 (0x005119E9) [callee:0x00511869, caller:0x005119E9, function:0x00518BD4, source:raw]

    // Conservative worker pseudocode:
    //   int PngIendChunkHandler(int a1, int a2, unsigned int a3) {
    //     uint32_t flags = *(uint32_t*)(a1 + 0x58);
    //     int result;
    //     bool imagePresent = (flags & 0x1) && (flags & 0x4);
    //     if (!imagePresent)
    //       result = GuardedCallWithLongjmp(a1, "No image in file");
    //     if (imagePresent || a2) {
    //       *(uint32_t*)(a1 + 0x58) |= 0x18;
    //       if (a3) CallbackDispatch(a1, "Incorrect IEND chunk length");
    //       return sub_518828(a1, a3);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact meaning of bits 0 and 2 (interpreted from surrounding PNG-decoder context as IHDR/IDAT seen flags) is DERIVED, not independently proven here.
    // UNRESOLVED: GuardedCallWithLongjmp's abort behavior is only known from its name; the actual longjmp contract is not visible in this function.
    // UNRESOLVED: The origin and meaning of a2 (only tested for non-zero after the guard call) are not established.
}
