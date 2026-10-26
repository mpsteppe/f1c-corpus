// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004607A0
// Canonical corpus name: ParticleSoundEffectSpawner
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleSoundEffectSpawner_004607a0.c

void UnknownObject::ParticleSoundEffectSpawner()
{
    // Path and data-file resolution for a particle/sound asset driven by the two season/race index bytes at this+0x1B768 and this+0x1B769. Stores the pair via TwoByteFieldSetter, reports progress via ProgressBarEventEncode, and derives a random value mixing a masked hash-derived quantity with RandLCGRandomNumberGenerator. Builds candidate paths from global directories (dword_7CE64C, dword_7CE5D0, dword_5EC3D8, dword_7D0434, each falling back to byte_5EA438), queries file sizes through sub_45C400, ParserDispatchWrapper and DataFileCheckSizeQuery, appends the season/race suffix (dword_5C5D24 + byte_5C5D28), formats the final track path from aSS with StringFormatWithBufferOverflowCheck, and returns TextureCreationWrapper(v23, 2, -1, -1). Called from NetCommSessionMessageDispatcher.
    // CALL: Store the two season/race index bytes at this+0x1B768 and this+0x1B769 through TwoByteFieldSetter on the data object at this+112468 [callee:0x0045C3C0, field:this:0x0001B768, field:this:0x0001B769, source:raw]
    // CALL: Report progress via ProgressBarEventEncode with parameters 4, 36, 20, 0, the low dword of the session-time value dbl_8AFEA0, and 1 [callee:0x004B33B0, global:0x008AFEA0, source:raw]
    // CALCULATION: Compute a hash checksum from the two season/race index bytes via HashChecksumComputation and store it in the 16-bit field v24 [callee:0x00460770, field:this:0x0001B768, field:this:0x0001B769, source:raw]
    // CALCULATION: Derive a random 16-bit quantity: combine (dbl_8AFEA0-derived value masked with 0xFFFC shifted left 6) with the low byte of RandLCGRandomNumberGenerator [callee:0x005884ED, global:0x008AFEA0, source:raw]
    // CALL: Resolve a candidate data path: take dword_7CE64C (falling back to byte_5EA438 when empty), pass it through ConditionalDispatch_40b0, read the path string at dispatch-result+8 (again falling back to byte_5EA438), and query the file size via sub_45C400 into v26, else 0 [callee:0x004C40B0, callee:0x0045C400, global:0x007CE64C, global:0x005EA438, source:raw]
    // CALL: Initialize the 512-byte path buffer from the first byte of byte_5EA438, clear the remaining 0x1FC bytes, and run sub_4CEEF0 on the buffer with 512 [callee:0x004CEEF0, global:0x005EA438, source:raw]
    // CALL: Parse the buffer through ParserDispatchWrapper; on success compute v27 as dword_8ACED8 plus the parsed value minus 1413405834, else leave v27 as 0 [callee:0x0045C3D0, global:0x008ACED8, source:raw]
    // CALL: Append the current track path dword_7CE5D0 (falling back to byte_5EA438) into the buffer with sub_587DD0 limited to 511, then strip the file extension by scanning backward for the '.' byte 46 and truncating there [callee:0x00587DD0, global:0x007CE5D0, global:0x005EA438, source:raw]
    // ASSIGNMENT: Append the season/race suffix to the buffer tail: write the dword dword_5C5D24 and the following byte byte_5C5D28 [global:0x005C5D24, global:0x005C5D28, source:raw]
    // CALL: Query the season-path file size via DataFileCheckSizeQuery, storing the size in v28 when the query succeeds, else 0 [callee:0x0045C650, source:raw]
    // CALL: Format the final track path with StringFormatWithBufferOverflowCheck using the aSS format and the dword_5EC3D8 and dword_7D0434 directory globals (each falling back to byte_5EA438), then query its file size via DataFileCheckSizeQuery into v29 [callee:0x0058815F, callee:0x0045C650, global:0x005BE860, global:0x005EC3D8, global:0x007D0434, global:0x005EA438, source:raw]
    // RETURN: Create the target texture via TextureCreationWrapper with arguments v23, 2, -1, -1 and return its handle [callee:0x00462250, function:0x004607A0, source:raw]
    // CALL: Invoked from NetCommSessionMessageDispatcher (0045D890) [caller:0x0045D890, source:raw]

    // Conservative worker pseudocode:
    //   TwoByteFieldSetter(this + 112468, this[0x1B768], this[0x1B769]);
    //   v16 = dbl_8AFEA0;
    //   ProgressBarEventEncode(4, 36, 20, 0, LODWORD(v16), 1);
    //   v24 = HashChecksumComputation(this[0x1B768], this[0x1B769]);
    //   v25 = ((dbl_8AFEA0 & 0xFFFC) << 6) + (byte)RandLCGRandomNumberGenerator();
    //   path = dword_7CE64C ? dword_7CE64C : byte_5EA438;
    //   v26 = (p = ConditionalDispatch_40b0(path)) && sub_45C400(this + 112468, *(p + 8) ? *(p + 8) : byte_5EA438, &size) ? size : 0;
    //   v20[0] = byte_5EA438[0]; memset(v20 + 1, 0, 0x1FC);
    //   sub_4CEEF0(v20, 512);
    //   v27 = ParserDispatchWrapper(this + 112468, v20, &size) ? dword_8ACED8 + size - 1413405834 : 0;
    //   sub_587DD0(v20, dword_7CE5D0 ? dword_7CE5D0 : byte_5EA438, 511);
    //   for (p = v20 + strlen(v20); p > v20 && *p != 46; --p);
    //   if (p > v20) *p = 0;
    //   tail = v20 + strlen(v20) + 1;
    //   *(dword*)--tail = dword_5C5D24; tail[4] = byte_5C5D28;
    //   v28 = DataFileCheckSizeQuery(this + 112468, v20, &size) ? size : 0;
    //   StringFormatWithBufferOverflowCheck(v20, aSS, dword_5EC3D8 ? dword_5EC3D8 : byte_5EA438, dword_7D0434 ? dword_7D0434 : byte_5EA438);
    //   v29 = DataFileCheckSizeQuery(this + 112468, v20, &size) ? size : 0;
    //   return TextureCreationWrapper(v23, 2, -1, -1);
    // UNRESOLVED: Global dword_8ACEA0 (0x008ACEA0) and unk_8AC388 (0x008AC388) are listed in the packet global evidence but do not appear as operands in the decompiled body; their use is outside the visible function
    // UNRESOLVED: The interpretation of the two bytes at this+0x1B768 and this+0x1B769 as season/race indices is inherited from the existing analysis (DERIVED), not proven by this function
    // UNRESOLVED: The arithmetic dword_8ACED8 plus parsed size minus 1413405834 is opaque; dword_8ACED8 is treated only as a checksum/base offset constant
    // UNRESOLVED: Internal behavior of helper callees sub_45C400, sub_587DD0, sub_4CEEF0, ParserDispatchWrapper, ConditionalDispatch_40b0, DataFileCheckSizeQuery and TextureCreationWrapper is not established
    // UNRESOLVED: The role of the random 16-bit value v25 in the overall asset selection is unclear
}
