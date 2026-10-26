// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D8E0
// Canonical corpus name: sub_53D8E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53D8E0_0053d8e0.c

void UnknownObject::formatGuidToHexString()
{
    // Formats a 16-byte binary GUID/UUID structure into the standard hyphenated hex string via StringFormatWithBufferOverflowCheck (0x0058815F) using the format literal at 0x005DBC5C. Reads the four data groups: a 32-bit value at +0x0, two 16-bit values at +0x4 and +0x6, and eight bytes at +0x8 through +0xF. Called from VidMan_Enter (0x004FA000).
    // CALCULATION: Reads the 16-byte GUID payload from a1: Data1 (uint32) at +0x0, Data2 (uint16) at +0x4, Data3 (uint16) at +0x6, and eight Data4 bytes at +0x8, +0x9, +0xA, +0xB, +0xC, +0xD, +0xE, +0xF. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000006, field:this:0x00000008, field:this:0x00000009, field:this:0x0000000A, field:this:0x0000000B, field:this:0x0000000C, field:this:0x0000000D, field:this:0x0000000E, field:this:0x0000000F, source:raw]
    // CALL: Calls StringFormatWithBufferOverflowCheck(0x0058815F) with the output buffer a2, the format literal at 0x005DBC5C ("%.8X-%.4X-%.4X-%.2X%.2X-%.2X%.2X%.2X%.2X%.2X%.2X"), and the eleven GUID fields in the canonical ordering. Reached from caller VidMan_Enter. [callee:0x0058815F, global:0x005DBC5C, caller:0x004FA000, source:raw]
    // RETURN: Returns the result of the format call unchanged. [function:0x0053D8E0, source:raw]

    // Conservative worker pseudocode:
    //   int formatGuidToHexString(const void *guid, char *out) {
    //     return StringFormatWithBufferOverflowCheck(
    //       out, "%.8X-%.4X-%.4X-%.2X%.2X-%.2X%.2X%.2X%.2X%.2X%.2X",
    //       *(uint32_t*)guid, *(uint16_t*)((char*)guid+4), *(uint16_t*)((char*)guid+6),
    //       *((uint8_t*)guid+8), *((uint8_t*)guid+9), *((uint8_t*)guid+10),
    //       *((uint8_t*)guid+11), *((uint8_t*)guid+12), *((uint8_t*)guid+13),
    //       *((uint8_t*)guid+14), *((uint8_t*)guid+15));
    //   }
    // UNRESOLVED: The caller VidMan_Enter's use of the produced string (where the formatted GUID is consumed) is not present in the packet.
    // UNRESOLVED: The GUID's semantic role (device identifier, adapter GUID, registry key) is unresolved.
}
