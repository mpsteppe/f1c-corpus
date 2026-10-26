// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494C15
// Canonical corpus name: GDIFontByteUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GDIFontByteUpdate_00494c15.c

void UnknownObject::GDIFontByteUpdate()
{
    // Increments the byte at a2 + 94 by the char value a1, then returns the stock GDI object selected by GetStockObject((unsigned __int16)__ES__). The byte-increment shape and the declared GDI-focus legacy ABI name suggest a font bitmap byte update, but the object at a2 and the GetStockObject argument are not explained by this packet alone.
    // CALCULATION: Add char a1 to the byte at a2 + 94, storing the result back to a2 + 94. [function:0x00494C15, source:raw]
    // CALL: Call GetStockObject with the unsigned 16-bit value of the __ES__ segment register; result captured as HGDIOBJ. [abi:lead, function:0x00494C15, source:raw]
    // RETURN: Return the HGDIOBJ produced by GetStockObject. [abi:lead, function:0x00494C15, source:raw]

    // Conservative worker pseudocode:
    //   *(byte*)(a2 + 94) += a1;
    //   return GetStockObject((unsigned __int16)__ES__);
    // UNRESOLVED: The object at a2 and the purpose of the incremented byte at displacement 94 (0x5E) are not established from this packet.
    // UNRESOLVED: Arguments a3 through a12 are declared but never used in the body; their role is unknown.
    // UNRESOLVED: The __ES__ segment value feeding GetStockObject is a decompiler artifact and its intended stock-object argument is unknown.
    // UNRESOLVED: The legacy GDI_font_byte_update ABI name suggests font handling but has no independent evidence in this packet.
}
