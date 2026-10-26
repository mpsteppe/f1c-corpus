// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00518C1E
// Canonical corpus name: sub_518C1E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_518C1E_00518c1e.c

void UnknownObject::PNGParseGammaChunk()
{
    // Parses and validates a PNG gAMA (gamma) chunk during image decode. Reads the chunk-state flags at this+0x58 to enforce chunk ordering (IHDR required first, no gAMA after IDAT, no duplicate gAMA when the metadata pointer's +8 flag word marks it seen, no gAMA out of place when PLTE seen), aborts with GuardedCallWithLongjmp on a missing IHDR, and dispatches warnings through CallbackDispatch for ordering, duplicate, sRGB-conflict and bad-length conditions. Requires a 4-byte payload, reads it through sub_517F58, converts the big-endian bytes to an integer with ByteArrayToInt, scales it by ~1e-5 (0.0000099999997) to a gamma float stored at this+0x130, then records it via FlagSetterFloatStore. Gamma values near the sRGB constant (45455) within 500 are accepted even when sRGB is present; otherwise the value is ignored with a warning.
    // GUARD: Read flags word at this+0x58; branch on IHDR-seen bit (bit 0). Zero means IHDR not yet seen. [field:this:0x00000058, source:raw]
    // GUARD: When IHDR seen, test IDAT-seen bit (bit 2). If set, a gAMA chunk is invalid at this point. [field:this:0x00000058, source:raw]
    // CALL: CallbackDispatch(this, 'Invalid gAMA after IDAT'): warning for gAMA arriving after image data. [callee:0x00511887, global:0x005AFDA8]
    // GUARD: When IDAT not yet seen, test PLTE-seen bit (bit 1) of the this+0x58 flags word. [field:this:0x00000058, source:raw]
    // CALL: CallbackDispatch(this, 'Out of place gAMA chunk'): warning when PLTE was already seen. [callee:0x00511887, global:0x005AFD90]
    // GUARD: When PLTE not seen: if metadata pointer a2 is non-null, read its flag word at a2+8. [source:raw]
    // GUARD: If a2+8 bit 0 is set and bit 11 (0x800) is clear, the gAMA chunk is a duplicate. [source:raw]
    // CALL: CallbackDispatch(this, 'Duplicate gAMA chunk'): warning for a repeated gAMA chunk. [callee:0x00511887, global:0x005AFD78]
    // CALL: GuardedCallWithLongjmp(this, 'Missing IHDR before gAMA'): abort path when IHDR was not seen first. [callee:0x00511869, global:0x005AFDDC]
    // GUARD: Require chunk data length a3 to equal 4 (a gAMA payload is exactly four bytes). [source:raw]
    // CALL: CallbackDispatch(this, 'Incorrect gAMA chunk length'): warning when a3 != 4. [callee:0x00511887, global:0x005AFDC0]
    // CALL: sub_518828(this, a3): chunk error/consumption hook invoked with the offending length on the bad-length path, then function returns. [callee:0x00518828, source:raw]
    // CALL: sub_517F58(this, local buffer, 4): read four bytes of gAMA payload into a stack buffer. [callee:0x00517F58]
    // GUARD: Call sub_518828(this, 0); continue parsing only when it returns zero (no error state reported). [callee:0x00518828, source:raw]
    // CALL: ByteArrayToInt: convert the four payload bytes to an integer gamma value. [callee:0x00517F35]
    // GUARD: Proceed only if the gamma integer is non-zero. [source:raw]
    // GUARD: If a2+8 sRGB-present bit (bit 11, 0x800) is set and the gamma integer deviates from the sRGB constant 45455.0 by more than 500.0, the value is treated as incorrect; the float/double constant globals provide the 45455.0/500.0 operands. [source:raw, global:0x005AD260, global:0x005ADB14, global:0x005AFD68, global:0x005AFD70]
    // CALL: CallbackDispatch(this, 'Ignoring incorrect gAMA value when sRGB is also present'): warning when the sRGB-conflict check rejects the gamma value. [callee:0x00511887, global:0x005AFD30]
    // CALCULATION: gammaFloat = gammaInteger * 0.0000099999997 (~1e-5); the float/double constant globals supply the scale operands (exact global-to-literal assignment not resolvable from packet). [source:raw, global:0x005AD260, global:0x005ADB14, global:0x005AFD68, global:0x005AFD70]
    // ASSIGNMENT: Store the computed gamma float at this+0x130. [field:this:0x00000130]
    // CALL: FlagSetterFloatStore(this, a2, gammaFloat): persist the gamma float on the metadata state and set its associated flag. [callee:0x00513A56, field:this:0x00000130]
    // RETURN: Function terminates after the parse-and-store path or after a warning/abort path. [function:0x00518C1E]

    // Conservative worker pseudocode:
    //   flags = *(u32*)(this + 0x58);
    //   if (flags & 1) {
    //       if (flags & 4) { CallbackDispatch(this, "Invalid gAMA after IDAT"); goto error; }
    //       if (flags & 2) { CallbackDispatch(this, "Out of place gAMA chunk"); }
    //       else if (meta) { f = *(u32*)(meta + 8); if ((f & 1) && !(f & 0x800)) { CallbackDispatch(this, "Duplicate gAMA chunk"); goto error; } }
    //   } else {
    //       GuardedCallWithLongjmp(this, "Missing IHDR before gAMA");
    //   }
    //   if (len != 4) { CallbackDispatch(this, "Incorrect gAMA chunk length"); error: sub_518828(this, len); return; }
    //   sub_517F58(this, &buf, 4);
    //   if (!sub_518828(this, 0)) {
    //       g = ByteArrayToInt(&buf);
    //       if (g) {
    //           if ((*(u32*)(meta + 8) & 0x800) && fabs((double)g - 45455.0) > 500.0)
    //               CallbackDispatch(this, "Ignoring incorrect gAMA value when sRGB is also present");
    //           else { gf = (double)g * 0.0000099999997; *(float*)(this + 0x130) = gf; FlagSetterFloatStore(this, meta, gf); }
    //       }
    //   }
    // UNRESOLVED: Exact assignment of the float/double constant globals (0x005AD260, 0x005ADB14, 0x005AFD68, 0x005AFD70) to the source literals 45455.0, 500.0 and 0.0000099999997 is not determinable from packet evidence.
    // UNRESOLVED: Semantics of the a2 (meta) pointer's +8 flag word (bit 0 seen-marker, bit 11 sRGB-present) are inferred from usage only; no named-field evidence.
    // UNRESOLVED: sub_518828 exact behavior and the meaning of its non-zero return are not resolved from this packet.
    // UNRESOLVED: sub_517F58 internal read semantics (buffer fill, stream advance) not resolved from this packet.
    // UNRESOLVED: this+0x58 bit assignments (0=IHDR seen, 1=PLTE seen, 2=IDAT seen) are DERIVED from the ordering checks; not independently confirmed.
    // UNRESOLVED: Owner class of the function is unknown; no RTTI or constructor evidence in packet.
}
