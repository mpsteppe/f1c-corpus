// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2B10
// Canonical corpus name: FunctionCallWrapper_2b10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_2b10_004b2b10.c

void UnknownObject::FloatToBitfield10BitsPacker()
{
    // Scales the input float by 3.0, truncates it to an integer, and packs the result into the upper 10 bits (bits 22-31) of the dword at this+0x30 while preserving its lower 22 bits with the mask 0xFF3FFFFF. Stores the combined value back to this+0x30 and returns it.
    // CALCULATION: Scale the input: v3 = a2 * 3.0 (packet flags flt_59E478 as the floating constant behind this multiply). [global:0x0059E478, source:raw]
    // CALCULATION: Truncate and shift: (int)v3 << 22 places the integer into bits 22-31 of the result dword. [source:raw]
    // CALCULATION: Mask the existing field: this[12] & 0xFF3FFFFF preserves the lower 22 bits of the dword at this+0x30. [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Combine and store: result = ((int)v3 << 22) | (this[12] & 0xFF3FFFFF), then this[12] = result. [field:this:0x00000030, source:raw]
    // RETURN: Return the updated dword stored at this+0x30. [field:this:0x00000030, source:raw]
    // CALL: Invoked by SetupCarLightingAndRender (004C71C0) to write a scaled float into the 10-bit field at this+0x30 as part of car lighting setup. [caller:0x004C71C0, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int FloatToBitfield10BitsPacker(BitfieldObj* this, float value) {
    //     float scaled = value * 3.0f;
    //     unsigned int packed = ((unsigned int)(int)scaled << 22) | (this->packed & 0xFF3FFFFF);
    //     this->packed = packed;      /* this+0x30 * /
    //     return packed;
    //   }
    // UNRESOLVED: flt_59E478 is flagged by packet facts but never appears as an explicit global load in the raw decompiled source (which shows the literal 3.0); its role as the constant's storage versus a steering-center boost is unverified.
    // UNRESOLVED: The meaning of the 10-bit field at this+0x30 and which consumers read those upper bits is not defined in this packet.
}
