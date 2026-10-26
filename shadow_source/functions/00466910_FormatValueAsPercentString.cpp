// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466910
// Canonical corpus name: SetupValueDisplayFormatter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetupValueDisplayFormatter_00466910.c

void UnknownObject::FormatValueAsPercentString()
{
    // Formats a percent value as a string. It initializes a local 61-byte buffer from global byte_5EA438 (first byte plus zero fill), fetches a float pointer via a virtual call through vtable entry at offset 0xB4, and when the result is non-null converts the float to an integer percentage with CRTFtol(value*100.0+0.5), formats it as "%d%%" via StringFormatWithBufferOverflowCheck, and stores the result with StringCopyWithBufferRealloc. Returns 0. Invoked by ParameterValueClampingAcrossArray and SuspensionFloatClamp.
    // ASSIGNMENT: Initialize the local 61-byte buffer: copy the first byte of global byte_5EA438 into buffer[0], then zero-fill the remaining 60 bytes and the trailing word and byte. [source:raw, global:0x005EA438]
    // CALL: Load the vtable pointer from *this and invoke the virtual method at vtable offset 0xB4 to obtain a float pointer used as the percent value source. [source:raw, field:this:0x00000000, field:obj:0x000000B4]
    // GUARD: Guard on the float pointer returned by the vtable+0xB4 call: if non-null, format the percentage; if null, skip formatting and jump to the string-store step. [source:raw, field:obj:0x000000B4]
    // CALCULATION: Convert the dereferenced float to an integer percent value: CRTFtol(*p * 100.0 + 0.5), rounding half away from zero before truncation. [source:raw, callee:0x00587BDC]
    // CALL: Format the integer percent value into the buffer using the "%d%%" format string (global aD) via StringFormatWithBufferOverflowCheck. [source:raw, callee:0x0058815F, global:0x005C37CC]
    // CALL: Store the formatted buffer into the persistent string buffer via StringCopyWithBufferRealloc. [source:raw, callee:0x00566650]
    // RETURN: Return the decimal literal 0. [source:raw]

    // Conservative worker pseudocode:
    //   int FormatValueAsPercentString(int *this)
    //   {
    //     char buf[61];
    //     int vtbl = *this;
    //     buf[0] = byte_5EA438[0];
    //     memset(&buf[1], 0, 60);
    //     float *p = (float *)(*(int (**)(int *))(vtbl + 180))(this);
    //     if (p)
    //     {
    //       int n = CRTFtol(*p * 100.0 + 0.5);
    //       StringFormatWithBufferOverflowCheck(buf, "%d%%", n);
    //     }
    //     StringCopyWithBufferRealloc(buf);
    //     return 0;
    //   }
    // UNRESOLVED: Globals flt_59E450 and flt_59E6F8 are listed in the packet but absent from the raw source; any role they play in this function is not evidenced.
    // UNRESOLVED: byte_5EA438 semantics are unknown; only its first byte is copied into the local buffer.
    // UNRESOLVED: The vtable+0xB4 getter returns a float pointer, but the owner of the vtable and the meaning of the returned value are not established.
}
