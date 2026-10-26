// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004056A0
// Canonical corpus name: MemoryAllocation_56a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocation_56a0_004056a0.c

void UnknownObject::WavHeaderBuilder()
{
    // Builds a complete RIFF/WAVE header (RIFF, WAVE, fmt and data chunks) at buffer offset this + 68 via repeated sub_405670 appends, using audio parameters read from the input header a2: data size selected by flag bits, sample rate, bits per sample, channel count, block align and byte rate. Returns the buffer position after the final 'data' size field.
    // GUARD: Read the flag byte at a2 + 27; if bits 0x20 and 4 are both set, take the data-size source from a2 + 32, otherwise from a2 + 4. [source:raw]
    // CALCULATION: Compute the RIFF chunk size v20 = selected data size + 36 (fixed RIFF/WAVE/fmt/data prefix). [source:raw]
    // CALCULATION: Extract audio format fields from a2: sample rate v6 = u16 at a2 + 24, bits per sample = u8 at a2 + 26, channel count v23 = (flag bit 1) + 1, block align v26 = (channels * bits) >> 3, byte rate v25 = sample rate * block align; v22 = 1 (PCM format tag), v21 = 16 (fmt chunk length). [source:raw]
    // CALL: Emit the RIFF container chunk into the buffer at this + 68: append the 'RIFF' id (global aRiff), the 4-byte v20 size, then the 'WAVE' tag (global aWave), each via sub_405670. [global:0x005BE844, global:0x005BE83C, callee:0x00405670, source:raw]
    // CALL: Emit the fmt sub-chunk: append the 'fmt ' id (global aFmt), then 4-byte length v21, 2-byte PCM tag v22, 2-byte channels v23, 4-byte sample rate v24, 4-byte byte rate v25, 2-byte block align v26, 2-byte bits v27 via sub_405670. [global:0x005BE834, callee:0x00405670, source:raw]
    // CALL: Emit the data sub-chunk: append the 'data' id (global aData_0) then the 4-byte payload size (selected data size) via sub_405670. [global:0x005BE82C, callee:0x00405670, source:raw]
    // RETURN: Return the buffer position after the final 'data' size field (end of the header). [source:raw]

    // Conservative worker pseudocode:
    //   char *WavHeaderBuilder(char *this, char *hdr) {
    //     char flags = *(hdr + 27);
    //     int data_size = ((flags & 0x20) && (flags & 4)) ? *(int *)(hdr + 32) : *(int *)(hdr + 4);
    //     int riff_size = data_size + 36;
    //     unsigned int sample_rate = *(unsigned short *)(hdr + 24);
    //     unsigned short bits = *(unsigned char *)(hdr + 26);
    //     int channels = ((flags & 1) != 0) + 1;
    //     int block_align = (channels * bits) >> 3;
    //     int byte_rate = sample_rate * block_align;
    //     char *p = this + 68;
    //     int fmt_len = 16;
    //     int fmt_tag = 1;
    //     p = sub_405670(p, "RIFF", 4); p = sub_405670(p, &riff_size, 4);
    //     p = sub_405670(p, "WAVE", 4);
    //     p = sub_405670(p, "fmt ", 4); p = sub_405670(p, &fmt_len, 4);
    //     p = sub_405670(p, &fmt_tag, 2); p = sub_405670(p, &channels, 2);
    //     p = sub_405670(p, &sample_rate, 4); p = sub_405670(p, &byte_rate, 4);
    //     p = sub_405670(p, &block_align, 2); p = sub_405670(p, &bits, 2);
    //     p = sub_405670(p, "data", 4); return sub_405670(p, &data_size, 4);
    //   }
    // UNRESOLVED: Flag-bit selection (0x20 / 4) of the data-size source (a2 + 32 vs a2 + 4) is DERIVED, not confirmed.
    // UNRESOLVED: Mapping of a2 header fields to WAV parameters (sample rate at +24, bits at +26) is DERIVED from the chunk layout.
    // UNRESOLVED: Owner object type is UNKNOWN; only the caller BinaryDataDeserialization (0x004054E0) is known.
}
