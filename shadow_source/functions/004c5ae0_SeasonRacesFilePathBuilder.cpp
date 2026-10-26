// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5AE0
// Canonical corpus name: SeasonRacesSectionWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonRacesSectionWriter_004c5ae0.c

void UnknownObject::SeasonRacesFilePathBuilder()
{
    // Builds a season-races file path on a stack buffer: seeds with the first byte of the default directory global byte_5EA438, copies input a1 through sub_587DD0 with a 511-byte limit, strips the file extension by truncating at the last '.', then appends a suffix made from dword_5C5D24 followed by byte_5C5D28. Resolves the 'seasonraces' audio channel via AudioChannelStop; if absent, creates it via FileDataProcessor. Finally loads/decodes the audio file from the built path with AudioFileLoadDecode and returns its result.
    // ASSIGNMENT: Initialize the stack path buffer: seed v6[0] with byte_5EA438[0], then zero-fill the remaining 508 bytes. [global:0x005EA438, source:raw]
    // CALL: sub_587DD0(v6, a1, 511): copy input path a1 into the buffer with a 511-byte size limit. [callee:0x00587DD0, source:raw]
    // CALCULATION: Strip the file extension: scan backwards from the string end for '.', truncating the string at that byte. [source:raw]
    // ASSIGNMENT: Append the suffix to the end of the path string: write dword_5C5D24 (4 bytes) then byte_5C5D28. [global:0x005C5D24, global:0x005C5D28, source:raw]
    // CALL: v4 = AudioChannelStop(aSeasonraces): look up the existing 'seasonraces' audio data channel. [global:0x005D31C8, callee:0x00568210, source:raw]
    // GUARD: If AudioChannelStop returned 0 (channel absent), v4 = FileDataProcessor(aSeasonraces, 0, 0, 0) to create the data channel. [global:0x005D31C8, callee:0x00567FB0, source:raw]
    // RETURN: return AudioFileLoadDecode(v6, v4): load and decode the audio file at the built path using the channel handle. [callee:0x00567F40, source:raw]

    // Conservative worker pseudocode:
    //   char buf[512];
    //   buf[0] = byte_5EA438[0]; memset(buf + 1, 0, 508);
    //   sub_587DD0(buf, a1, 511);
    //   for (p = buf + strlen(buf); p > buf && *p != '.'; --p);
    //   if (p > buf) *p = 0;
    //   p = buf + strlen(buf) + 1;
    //   *(_DWORD *)(p - 4) = dword_5C5D24; p[4] = byte_5C5D28;
    //   v4 = AudioChannelStop(aSeasonraces);
    //   if (!v4) v4 = FileDataProcessor(aSeasonraces, 0, 0, 0);
    //   return AudioFileLoadDecode(buf, v4);
    // UNRESOLVED: global:0x008AD3B4 (dword_8AD3B4) is listed in the packet globals but not referenced in the raw source; assumed GameDataDir via existing analysis, unverified.
    // UNRESOLVED: Semantics of the dword_5C5D24 / byte_5C5D28 suffix constants (e.g. file-extension fragment) are unconfirmed.
    // UNRESOLVED: Return contract of AudioFileLoadDecode and whether the FileDataProcessor handle is a valid channel substitute are unconfirmed.
}
