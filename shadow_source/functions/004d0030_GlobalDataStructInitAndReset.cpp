// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D0030
// Canonical corpus name: Wrapper_0030
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Wrapper_0030_004d0030.c

void UnknownObject::GlobalDataStructInitAndReset()
{
    // Initializes the global data struct at 0x008ACEE0 and resets a large block of adjacent control globals. Calls GlobalDataStructInitWithFilePaths(dword_8ACEE0) first, zeroes a run of control words, installs sentinel defaults (dword_8ACF8C = 0x7FFFFFFF, flt_8ACF9C = 1.0, unk_8ACF98 = 1172373504), fills 0x68 bytes at byte_8AD008 with 0xFF, sets unk_8AD070/unk_8AD072 to -1, zeroes the remaining control globals, then clears 104 consecutive dwords via a 52-iteration double-store loop. Returns the global struct pointer dword_8ACEE0.
    // CALL: Call GlobalDataStructInitWithFilePaths with the global data struct pointer dword_8ACEE0 to set up file-path-derived configuration [global:0x008ACEE0, source:raw]
    // ASSIGNMENT: Zero the control globals unk_8ACFC0, unk_8ACFC4, dword_8ACFCC, unk_8ACFD0, dword_8ACFD8, unk_8ACFDC and struct slots dword_8ACEE0[41] and dword_8ACEE0[42] [source:raw]
    // ASSIGNMENT: Install sentinel defaults: dword_8ACF8C = 0x7FFFFFFF, flt_8ACF90 = 0.0, flt_8ACF94 = 0.0, unk_8ACF98 = 1172373504, flt_8ACF9C = 1.0, byte_8ACFA0 = 0, flt_8ACFB4 = 0.0, byte_8ACFA3 = 0, flt_8ACFB0 = 0.0 [source:raw]
    // ASSIGNMENT: Zero the remaining control globals unk_8ACFE8, dword_8ACFEC, dword_8ACFF0, unk_8ACFF4, unk_8ACFF8, unk_8ACFFC, unk_8AD000 and unk_8AD004 [source:raw]
    // ASSIGNMENT: Fill 0x68 bytes at byte_8AD008 with 0xFF via memset [source:raw]
    // ASSIGNMENT: Set unk_8AD070 and unk_8AD072 to -1, and zero dword_8AD074, dword_8AD078, dword_8AD07C, dword_8AD080, dword_8AD084, unk_8AD088 and unk_8AD08C [source:raw]
    // LOOP: Run 52 iterations starting with v0 = &unk_8AD160: each iteration zeroes *(v0 - 52) and *v0, then advances v0; together the writes clear 104 consecutive dwords across the trailing control block [source:raw]
    // RETURN: Return the initialized global data struct pointer dword_8ACEE0 [function:0x004D0030, global:0x008ACEE0, source:raw]

    // Conservative worker pseudocode:
    //   GlobalDataStructInitWithFilePaths(dword_8ACEE0);
    //   unk_8ACFC0 = 0; unk_8ACFC4 = 0; dword_8ACFCC = 0; unk_8ACFD0 = 0; dword_8ACFD8 = 0; unk_8ACFDC = 0;
    //   dword_8ACEE0[41] = 0; dword_8ACEE0[42] = 0;
    //   dword_8ACF8C = 0x7FFFFFFF; flt_8ACF90 = 0.0; flt_8ACF94 = 0.0; unk_8ACF98 = 1172373504; flt_8ACF9C = 1.0;
    //   byte_8ACFA0 = 0; flt_8ACFB4 = 0.0; byte_8ACFA3 = 0; flt_8ACFB0 = 0.0;
    //   unk_8ACFE8 = 0; dword_8ACFEC = 0; dword_8ACFF0 = 0; unk_8ACFF4 = 0; unk_8ACFF8 = 0; unk_8ACFFC = 0; unk_8AD000 = 0; unk_8AD004 = 0;
    //   memset(byte_8AD008, 0xFF, 0x68);
    //   unk_8AD070 = -1; unk_8AD072 = -1; dword_8AD074 = 0; dword_8AD078 = 0; dword_8AD07C = 0; dword_8AD080 = 0; dword_8AD084 = 0; unk_8AD088 = 0; unk_8AD08C = 0;
    //   v0 = &unk_8AD160; v1 = 52;
    //   do { *(v0 - 52) = 0; *v0++ = 0; } while (--v1);
    //   return dword_8ACEE0;
    // UNRESOLVED: The semantic roles of the reset control globals (8ACFC0..8AD08C) are not established; the raw source names are decompiler-generated
    // UNRESOLVED: The byte_8AD008 0xFF-filled block and the trailing 104-dword cleared block are only characterized as reset state; their meaning (e.g. handle tables or key arrays) is unknown
    // UNRESOLVED: The value 1172373504 at unk_8ACF98 is left as the raw decimal literal; its numeric interpretation (e.g. float bit pattern) is not decoded to avoid synthesizing a representation absent from the packet
}
