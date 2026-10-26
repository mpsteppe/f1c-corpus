// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056068E
// Canonical corpus name: sub_56068E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56068E_0056068e.c

void UnknownObject::TextureDecodePixelKernel_A()
{
    // Image/texture pixel-processing kernel over a 16-bit pixel buffer. Computes three channel LUT offsets from nibbles packed in parameter a7 (dword_5DD828/5DD824/5DD820, each 32 * (byte >> 4)), sets up a per-row width (dword_5DD814) and row stride (dword_5DD81C), then runs nested do-while loops (a5 rows x a4 pixels) combining byte_5DD8CC clip-table remaps against byte_5DECCC multiply LUT rows selected by dword_5DD878 (32 * a8). Each 16-bit pixel is transformed with rotate operations and written back in place. No guard conditions; the full rectangle is always processed.
    // ASSIGNMENT: Store parameter a4 into dword_5DD814 as the per-row pixel count (rectangle width). [global:0x005DD814]
    // ASSIGNMENT: Set dword_5DD878 = 32 * a8, the LUT row base offset selecting which byte_5DECCC row is used. [global:0x005DD878]
    // CALCULATION: Compute the working pixel pointer v8 = a1 + a2 + a2 + a6 * a3, entering the destination buffer at an offset derived from parameters a1/a2/a3/a6. [source:raw]
    // ASSIGNMENT: Store row stride delta dword_5DD81C = a6 - 2 * a4, used to advance to the next scan line after each row. [global:0x005DD81C]
    // ASSIGNMENT: Seed dword_5DD818 = a5 as the outer row countdown counter. [global:0x005DD818]
    // ASSIGNMENT: Set dword_5DD828 = 32 * ((uint8)a7 >> 4), the first channel lookup-table offset from the low nibble of a7. [global:0x005DD828]
    // ASSIGNMENT: Set dword_5DD824 = 32 * (BYTE1(a7) >> 4), the second channel lookup-table offset from the next nibble of a7. [global:0x005DD824]
    // ASSIGNMENT: Set dword_5DD820 = 32 * (BYTE2(a7) >> 4), the third channel lookup-table offset from the high nibble of a7. [global:0x005DD820]
    // LOOP: Outer do-while loop iterating over a5 rows, counting down dword_5DD818 until it is <= 1. [global:0x005DD818, function:0x0056068E]
    // LOOP: Inner do-while loop iterating over a4 pixels per row, counting down from dword_5DD814 until it is <= 1. [global:0x005DD814]
    // CALCULATION: Per-pixel decode combining two lookup tables: byte_5DECCC is indexed by dword_5DD878 + byte_5DD8CC[channel-nibble index], where byte_5DD8CC acts as a clip/remap table over the low 5 bits of the source pixel. [global:0x005DECCC, global:0x005DD8CC]
    // CALCULATION: Combine the three channel lookups (dword_5DD828 / dword_5DD824 / dword_5DD820) with rotate-right operations, then write the transformed value (ROR(v12, 22)) back to the current 16-bit pixel and advance the pointer. [global:0x005DD828, global:0x005DD824, global:0x005DD820]
    // CALCULATION: After each row, advance the pixel pointer by the row stride dword_5DD81C to reach the next scan line. [global:0x005DD81C]

    // Conservative worker pseudocode:
    //   void TextureDecodePixelKernel_A(int a1, int a2, int a3, int width, int rows, int a6, int a7, int lutRow) {
    //     dword_5DD814 = width;
    //     dword_5DD878 = 32 * lutRow;
    //     WORD *px = (WORD *)(a1 + a2 + a2 + a6 * a3);
    //     dword_5DD81C = a6 - 2 * width;
    //     dword_5DD818 = rows;
    //     dword_5DD828 = 32 * ((unsigned __int8)a7 >> 4);
    //     dword_5DD824 = 32 * (BYTE1(a7) >> 4);
    //     dword_5DD820 = 32 * (BYTE2(a7) >> 4);
    //     do {
    //       int n = dword_5DD814;
    //       do {
    //         int v10 = ror16(*px, 5);
    //         int v11 = ror(byte_5DECCC[dword_5DD878 + byte_5DD8CC[dword_5DD828 + ((*px & 0x1F) >> 1)]], 5);
    //         LOBYTE(v11) = byte_5DECCC[dword_5DD878 + byte_5DD8CC[dword_5DD824 + ((v10 & 0x1F) >> 1)]];
    //         int v12 = ror(v11, 5);
    //         LOBYTE(v12) = byte_5DECCC[dword_5DD878 + byte_5DD8CC[dword_5DD820 + ((ror(v10, 5) & 0x1F) >> 1)]];
    //         *px++ = ror(v12, 22);
    //       } while (--n > 0);
    //       px = (WORD *)((char *)px + dword_5DD81C);
    //     } while (--dword_5DD818 > 0);
    //   }
    // UNRESOLVED: Exact meaning of byte_5DD8CC (clip/remap) and byte_5DECCC (multiply) table contents is not evidenced in this packet; names derive from prior analysis only.
    // UNRESOLVED: Semantics of parameter a7's nibble packing (which channels map to dword_5DD828/5DD824/5DD820) are unconfirmed.
    // UNRESOLVED: Callers and the pixel format / draw context are unknown; no static callers were found.
}
