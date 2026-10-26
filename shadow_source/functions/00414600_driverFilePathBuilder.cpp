// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414600
// Canonical corpus name: sub_414600
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_414600_00414600.c

void UnknownObject::driverFilePathBuilder()
{
    // Builds candidate driver asset file paths for two name variants (pws and tv) across four suffixes (Fb, Fe, Sb, Se). Each path is built with StringFormatWithBufferOverflowCheck using a directory prefix (this[0], defaulting to byte_5EA438) and a base directory global dword_5EC470 (also defaulting to byte_5EA438). FilePathExtensionCheck verifies each candidate against the per-variant/suffix string buffers at this+4/+9/+14/+19 (pws) and this+24/+29/+34/+39 (tv); existing files are registered via DriverNameIDLookup with this[2] as the id. Returns 1 only when flag a2 is non-zero, no candidate check failed, and TextFormatStructInitializer reset the format struct; otherwise returns 0. Callers include NamedEntryLookupInFormatList (0x00415230) and VehicleListBuilderFromGlobalArray (0x00415780).
    // ASSIGNMENT: Select the driver name string from this[0], falling back to byte_5EA438 when null. [field:this:0x00000000, global:0x005EA438, source:raw]
    // ASSIGNMENT: Select the base directory prefix from dword_5EC470, falling back to byte_5EA438 when null. [global:0x005EC470, global:0x005EA438, source:raw]
    // CALL: Build the pws variant path prefix into v10 with the '%spws%s_' format (aSpwsS global) using the base directory and driver name via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005C23AC, source:raw]
    // CALL: For each pws suffix (Fb at aFb, Fe at aFe, Sb at aSb, Se at aSe) build the full path into v9 by appending the suffix to the prefix via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005C23A8, global:0x005C23A4, global:0x005C23A0, global:0x005C239C, source:raw]
    // GUARD: For each pws suffix, FilePathExtensionCheck tests the candidate path against the string buffers at this+4, this+9, this+14, this+19; a failing check sets the sticky failure flag. [callee:0x00414900, field:this:0x00000000, source:raw]
    // CALL: For each pws suffix whose file exists, register it via DriverNameIDLookup with this[2] as the id and variant/suffix flag combinations (0,1,1), (0,1,0), (0,0,1), (0,0,0). [callee:0x00415D90, field:this:0x00000008, source:raw]
    // CALL: Build the tv variant path prefix into v10 with the '%stv%s_' format (aStvS global) using the base directory and driver name via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005C2394, source:raw]
    // GUARD: For each tv suffix, FilePathExtensionCheck tests the candidate path against the string buffers at this+24, this+29, this+34, this+39; a failing check sets the sticky failure flag. [callee:0x00414900, field:this:0x00000000, source:raw]
    // CALL: For each tv suffix whose file exists, register it via DriverNameIDLookup with this[2] as the id and variant/suffix flag combinations (1,1,1), (1,1,0), (1,0,1), (1,0,0). [callee:0x00415D90, field:this:0x00000008, source:raw]
    // GUARD: If the flag a2 is zero or any candidate file check failed (sticky flag set), return 0. [source:raw]
    // CALL: On success reset the text format struct via TextFormatStructInitializer and return 1. [callee:0x004149A0, source:raw]
    // RETURN: Return 1 on full success, 0 when a2 is zero or any candidate file check failed. [function:0x00414600, source:raw]

    // Conservative worker pseudocode:
    //   name = this[0] ? this[0] : &byte_5EA438;
    //   base = dword_5EC470 ? dword_5EC470 : &byte_5EA438;
    //   ok = 1;
    //   for (variant in {pws, tv}) {
    //     StringFormatWithBufferOverflowCheck(v10, variant_format, base, name);
    //     for (i = 0; i < 4; i++) {
    //       StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, suffix[i]);
    //       if (FilePathExtensionCheck(v9, buf)) DriverNameIDLookup(buf, this[2], variant_flag, fbse_flags);
    //       else ok = 0;
    //     }
    //   }
    //   if (!a2 || !ok) return 0;
    //   TextFormatStructInitializer(this);
    //   return 1;
    // UNRESOLVED: The roles of globals aSS (0x005BE860) and dword_5EA5E8 (0x005EA5E8) are not readable from the raw source text of this function; they are referenced by the packet evidence but their use is unresolved.
    // UNRESOLVED: The exact meaning of the three flag arguments passed to DriverNameIDLookup (variant pws/tv and suffix Fb/Fe/Sb/Se encodings) is not established from this packet.
    // UNRESOLVED: The target offset of the string buffers at this+4/+9/+14/+19 and this+24/+29/+34/+39 is inferred from the raw source only; the packet field evidence covers only this[0] and this[2].
}
