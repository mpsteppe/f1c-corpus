// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051E7D7
// Canonical corpus name: AudioSynthesis3ChannelSampleGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioSynthesis3ChannelSampleGenerator_0051e7d7.c

void UnknownObject::GenerateThreeChannelTableSamples()
{
    // Three-channel sample generator. Loads a synthesis context from this+0x1A4, a per-channel component table base from context+0x18 (three dwords v16/v15/v13 read through it), and the per-pixel width from this+0x5C. For each of a4 pixels it advances a rolling 4-bit phase counter at context+0x30 and computes three table bases by (phase << 6) + context+0x34/+0x38/+0x3C. For each of v18 samples it sums one byte from each of three source channels, each offset by a table entry indexed by a 4-bit counter v23, and writes the accumulated byte to the destination. Writes back the advanced phase counter and returns the context pointer.
    // ASSIGNMENT: Load synthesis context pointer result = *(this + 0x1A4). [field:this:0x000001A4, source:raw]
    // ASSIGNMENT: Load component table base v5 = result[6] (context+0x18) and read the three component offsets v16 = v5[0], v15 = v5[1], v13 = v5[2], which the fill treats as component table base pointers for channels 0/1/2. [field:*(this+0x1A4):0x00000018, field:*(this+0x1A4):0x0000001C, field:*(this+0x1A4):0x00000020, source:raw]
    // ASSIGNMENT: Read per-pixel sample width v18 = *(this + 0x5C); it gates the inner per-sample loop. [field:this:0x0000005C, source:raw]
    // GUARD: If pixel count a4 is not greater than 0, skip the outer pixel loop entirely. [source:raw]
    // LOOP: Outer loop over a4 pixels: capture phase v12 = result[12] (context+0x30) and destination pointer *a3, then derive three table bases v9 = (v12 << 6) + context+0x34, v8 = (v12 << 6) + context+0x38, v14 = (v12 << 6) + context+0x3C. [field:*(this+0x1A4):0x00000030, field:*(this+0x1A4):0x00000034, field:*(this+0x1A4):0x00000038, field:*(this+0x1A4):0x0000003C, source:raw]
    // LOOP: Inner loop over v18 samples: read one byte from each of the three source channels, each at (channel byte + phase-table entry [v9/v8/v14 + 4*v23] + additive offset v16/v15/v13); sum the three bytes and write the result to destination *v22. The table index v23 is a 4-bit counter advanced with & 0xF. [field:this:0x0000005C, field:*(this+0x1A4):0x00000034, field:*(this+0x1A4):0x00000038, field:*(this+0x1A4):0x0000003C, source:raw]
    // STATE_TRANSITION: Advance the 4-bit phase counter: context+0x30 = (v12 + 1) & 0xF; persist it across pixels as generator state. [field:*(this+0x1A4):0x00000030, source:raw]
    // RETURN: Return the synthesis context pointer result. [function:0x0051E7D7, source:raw]

    // Conservative worker pseudocode:
    //   ctx = *(this + 0x1A4);
    //   tbl = *(ctx + 0x18);
    //   o0 = tbl[0]; o1 = tbl[1]; o2 = tbl[2];
    //   width = *(this + 0x5C);
    //   if (pixelCount > 0) {
    //       do {
    //           phase = ctx->phase;
    //           b0 = (phase << 6) + ctx->t0;
    //           b1 = (phase << 6) + ctx->t1;
    //           b2 = (phase << 6) + ctx->t2;
    //           if (width > 0) {
    //               idx = 0;
    //               do {
    //                   *dst = src0[srcOff0 + tbl0[idx] + o0]
    //                         + src1[srcOff1 + tbl1[idx] + o1]
    //                         + src2[srcOff2 + tbl2[idx] + o2];
    //                   ++dst; idx = (idx + 1) & 0xF;
    //               } while (--width != 0);
    //           }
    //           ++srcRow;
    //           ctx->phase = (phase + 1) & 0xF;
    //       } while (--pixelCount != 0);
    //   }
    //   return ctx;
    // UNRESOLVED: The relationship between the 0x1C/0x20 fields and v5[1]/v5[2] is taken from the fill (component table base pointers); the raw source reads them only through the pointer v5 = result[6], so the inline-vs-indirect layout of the three component offsets is unresolved.
    // UNRESOLVED: The byte sums are not clamped or saturated inside this function; any scaling/limit step must live elsewhere.
    // UNRESOLVED: The exact meaning of the (phase << 6) stride (64 dwords per phase bucket) is DERIVED from the arithmetic; the phase-table element layout is not defined by packet evidence.
    // UNRESOLVED: Owner object identity is unknown; the context at this+0x1A4 is a synthesis/audio sub-object with persistent 4-bit phase state.
}
