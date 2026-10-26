// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00518D29
// Canonical corpus name: sub_518D29
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_518D29_00518d29.c

void UnknownObject::parseSrgbChunk()
{
    // Parses and validates a PNG sRGB chunk against the parser flags register at this+0x58: enforces chunk ordering (IHDR must have been seen, sRGB invalid after IDAT, out-of-place / duplicate sRGB reported), validates the required 1-byte chunk length and the rendering-intent value, optionally warns when a stored gamma at this+0x130 is inconsistent with sRGB, and stores the rendering intent via sub_513B51. Errors are reported through CallbackDispatch; ordering/length failures abort through a shared consume-and-return path.
    // GUARD: Read PNG flags register at this+0x58 (a1+88). If IHDR-seen bit (bit 0) is clear, call GuardedCallWithLongjmp(a1, "Missing IHDR before sRGB") which longjmps/aborts the chunk parse. [field:this:0x00000058, callee:0x00511869, global:0x005AFE74, source:raw]
    // GUARD: If IDAT-seen bit (bit 2) of the flags register is set, call CallbackDispatch(a1, "Invalid sRGB after IDAT") and jump to the shared error path (consume chunk then return). [field:this:0x00000058, callee:0x00511887, global:0x005AFE40]
    // GUARD: Else if PLTE-seen bit (bit 1) of the flags register is set, call CallbackDispatch(a1, "Out of place sRGB chunk"); parsing continues past this check. [field:this:0x00000058, callee:0x00511887, global:0x005AFE28]
    // GUARD: Else if chunk data pointer a2 is non-null and byte a2[9] has bit 3 set (duplicate sRGB already recorded in the chunk data), call CallbackDispatch(a1, "Duplicate sRGB chunk") and jump to the shared error path. [callee:0x00511887, global:0x005AFE10]
    // GUARD: If chunk length a3 != 1, call CallbackDispatch(v3, "Incorrect sRGB chunk length") and fall into the shared error path. [callee:0x00511887, global:0x005AFE58]
    // CALL: Shared error path: call sub_518828(v3, a3) to consume/skip the malformed sRGB chunk with the reported length, then return. [callee:0x00518828]
    // CALL: Feed the sRGB data byte into the CRC accumulator: call sub_517F58(v3, &a1 + 3, 1). The decompiler expression &a1+3 resolves to the low byte of a1, i.e. the rendering-intent byte read from the chunk. [callee:0x00517F58]
    // CALL: Call sub_518828(v3, 0) to finalize consumption of the chunk; a non-zero return value causes early return without storing the sRGB intent. [callee:0x00518828]
    // GUARD: Read rendering intent v5 = HIBYTE(a1) (decompiler artifact for the intent byte). If v5 >= 4, call CallbackDispatch(v3, "Unknown sRGB intent"). [callee:0x00511887, global:0x005AFDFC]
    // GUARD: If byte a2[8] has bit 0 set (gAMA present) and fabs(gamma at this+0x130 * 100000.0 + 0.5 - 45455.0) > 500.0, call CallbackDispatch(v3, "Ignoring incorrect gAMA value when sRGB is also present"). Floating literals 100000.0, 45455.0, 500.0 load from globals 0x0059E880, 0x005AFD68, 0x005AFD70, 0x005AFDF8; packet evidence does not disambiguate which global holds which literal. [field:this:0x00000130, global:0x005AFD30, global:0x0059E880, global:0x005AFD68, global:0x005AFD70, global:0x005AFDF8]
    // CALL: Store the sRGB chunk data: call sub_513B51(v3, __SPAIR64__(v5, a2)), recording rendering intent v5 and chunk pointer a2 on the parser object. [callee:0x00513B51]
    // RETURN: Normal return after storing the sRGB intent; the function is void. This terminates sub_518D29. [function:0x00518D29]

    // Conservative worker pseudocode:
    //   flags = read_dword(parser + 0x58)
    //   if (flags & 1) == 0: GuardedCallWithLongjmp(parser, "Missing IHDR before sRGB")
    //   if (flags & 4) != 0: CallbackDispatch(parser, "Invalid sRGB after IDAT"); goto error_path
    //   else if (flags & 2) != 0: CallbackDispatch(parser, "Out of place sRGB chunk")
    //   else if (chunkData && (byte(chunkData + 9) & 8) != 0): CallbackDispatch(parser, "Duplicate sRGB chunk"); goto error_path
    //   if (chunkLength != 1): CallbackDispatch(parser, "Incorrect sRGB chunk length"); error_path: consume_chunk(parser, chunkLength); return
    //   crc_feed(parser, intent_byte, 1)
    //   if consume_chunk(parser, 0) == 0:
    //       intent = intent_byte
    //       if intent < 4:
    //           if (byte(chunkData + 8) & 1) != 0 and fabs(gamma(parser + 0x130) * 100000.0 + 0.5 - 45455.0) > 500.0:
    //               CallbackDispatch(parser, "Ignoring incorrect gAMA value when sRGB is also present")
    //           store_srgb_intent(parser, intent, chunkData)
    //       else:
    //           CallbackDispatch(parser, "Unknown sRGB intent")
    // UNRESOLVED: Mapping of literal constants 100000.0 / 45455.0 / 500.0 to globals 0x0059E880, 0x005AFD68, 0x005AFD70, 0x005AFDF8 is not determinable from packet evidence; the per-global literal split is unknown.
    // UNRESOLVED: Flags-register bit meanings (bit 0 = IHDR seen, bit 1 = PLTE seen, bit 2 = IDAT seen) are DERIVED from existing analysis prose, not independently confirmed by this packet.
    // UNRESOLVED: Sub-byte checks on the chunk buffer (byte a2[8] bit 0 as gAMA-present, byte a2[9] bit 3 as duplicate-sRGB flag) dereference chunk data, not the 'this' object; the packet supplies no field evidence refs for them.
    // UNRESOLVED: Decompiler expressions &a1 + 3 and HIBYTE(a1) are artifacts used to extract the rendering-intent byte from a1; the actual chunk payload layout is not confirmed.
    // UNRESOLVED: sub_518828 return semantics (non-zero meaning CRC failure vs other error) are inferred from the branch; exact meaning not confirmed.
    // UNRESOLVED: Caller context: sub_5119E9 (0x005119E9) invokes this parser; its chunk-dispatch framing is not analyzed here.
}
