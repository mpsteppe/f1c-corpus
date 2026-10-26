// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7150
// Canonical corpus name: TireBrandFileParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireBrandFileParser_004d7150.c

void UnknownObject::ParseTireBrandDataFile()
{
    // Parses a tire physics data file containing SlipCurve and Compound sections. Clears the object arrays (ArrayBlockCleanup), derives the base file name from the path a2 (backslash scan, dot truncation), opens the file via AudioStreamOpen(a2, 1), and makes two passes over the token stream. The first pass counts entries into this+0x8 (slip curves) and this+0x10 (compounds) and allocates two typed arrays stored at this+0xC (24-byte slip-curve entries) and this+0x14 (680-byte compound entries). The second pass fills the arrays via TireSlipCurveBuilder and sub_4D6B00, validating counts against this+0x8/this+0x10 and reporting errors through DebugLogWrite. Invoked by TireBrandLoader (004D7660).
    // CALL: Reset the object arrays with ArrayBlockCleanup(this), record the source path via StringCopyWithBufferRealloc(a2), and seed the count field at this+0x8 with UtilityFunction_8a60(91, this + 8). [callee:0x004D7050, callee:0x00566650, callee:0x00568A60, field:this:0x00000008, source:raw]
    // CALCULATION: Derive the file name from a2: scan backward from the end for the backslash (92), then copy at most 63 chars into SrcStr via sub_587DD0 and null-terminate. [callee:0x00587DD0, source:raw]
    // CALCULATION: Strip the extension: scan SrcStr backward for the dot (46) and truncate there. [source:raw]
    // CALL: Normalize the name: sub_589901(SrcStr), then StringCopyWithBufferRealloc(SrcStr); ZeroInitSmallStruct(v24) initializes the token-scan context. [callee:0x00589901, callee:0x00566650, callee:0x005668B0, source:raw]
    // GUARD: Open the file via AudioStreamOpen(a2, 1); parsing continues only when the open succeeds. [callee:0x00566B20, source:raw]
    // LOOP: First counting pass: iterate lines via ConditionalDispatchBasedOnFlag(v32, 384), each read into v26 by sub_5651B0; sub_587C20 matches the section token - aSlipcurve increments this+0x8, aCompound increments this+0x10. [callee:0x00566CC0, callee:0x005651B0, callee:0x00587C20, global:0x005D4944, global:0x005D4938, field:this:0x00000008, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Allocate the slip-curve array: OperatorNewNhMallocWrapper(24 * this+0x8 + 4); store the count at the header and initialize each 24-byte entry (0, -1, 0); store the array pointer at this+0xC. [callee:0x00587C03, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Allocate the compound array: OperatorNewNhMallocWrapper(680 * this+0x10 + 4); store the count header and initialize each 680-byte entry, calling PhysicsStateStructureInitializer on the two state sub-blocks; store the array pointer at this+0x14. [callee:0x00587C03, callee:0x004D68A0, field:this:0x00000010, field:this:0x00000014, source:raw]
    // GUARD: When the compound count or its array is empty, StringSplitLoop(1, aDDevF119992002_4, 893) gates DebugLogWrite(&dword_8AD25C, aNoCompoundsFou) to report the missing section. [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D45E4, global:0x005D491C, global:0x008AD25C, source:raw]
    // CALL: ConditionalAllocInitDispatch(v24) finalizes the scan context before the second pass. [callee:0x00566D30, source:raw]
    // LOOP: Second filling pass: iterate ConditionalDispatchBasedOnFlag(v32, 384) lines again; sub_5651B0 reads into v26; aSlipcurve lines call TireSlipCurveBuilder at advancing 24-byte offsets and aCompound lines call sub_4D6B00 at 680-byte offsets. [callee:0x00566CC0, callee:0x005651B0, callee:0x00587C20, callee:0x004D5F70, callee:0x004D6B00, global:0x005D4944, global:0x005D4938, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // GUARD: Overflow checks inside the second pass: a slip-curve line past this+0x8 logs aBadSyntaxInFil and a compound line past this+0x10 logs aBadSyntaxInFil_0; each gated by StringSplitLoop(1, aDDevF119992002_4, line) then DebugLogWrite(&dword_8AD25C, ...), then the pass breaks. [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D45E4, global:0x005D48E0, global:0x005D48A8, global:0x008AD25C, field:this:0x00000008, field:this:0x00000010, source:raw]
    // GUARD: Final count check: when the filled counts differ from this+0x8/this+0x10, StringSplitLoop(1, aDDevF119992002_4, 941) gates DebugLogWrite(&dword_8AD25C, aBadSyntaxInFil_1). [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D45E4, global:0x005D4880, global:0x008AD25C, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALL: Close the file handle via ConditionalFileHandleCloseWithFlagDispatch(v24). [callee:0x00566B90, source:raw]
    // GUARD: Open-failure path: the else branch logs aCouldNotOpenS via StringSplitLoop(1, aDDevF119992002_4, 870) gating DebugLogWrite(&dword_8AD25C, ...). [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D45E4, global:0x005C6810, global:0x008AD25C, source:raw]
    // RETURN: Return the result of SubCallWithConditionalFieldFree(v24), releasing the scan context; the function is invoked by TireBrandLoader (004D7660). [callee:0x005668D0, caller:0x004D7660, function:0x004D7150, source:raw]

    // Conservative worker pseudocode:
    //   ArrayBlockCleanup(this);
    //   StringCopyWithBufferRealloc(a2);
    //   UtilityFunction_8a60(91, this + 8);
    //   filename = last_segment(a2);  /* backslash scan * /
    //   strip_extension(filename);     /* dot scan * /
    //   sub_589901(filename); StringCopyWithBufferRealloc(filename);
    //   ZeroInitSmallStruct(ctx);
    //   if (AudioStreamOpen(a2, 1)) {
    //     /* pass 1: count * /
    //     while (next_line(line)) {
    //       if (match(line, aSlipcurve)) ++this[2];
    //       else if (match(line, aCompound)) ++this[4];
    //     }
    //     this[3] = alloc_slip_curves(this[2]);  /* 24 bytes each * /
    //     this[5] = alloc_compounds(this[4]);    /* 680 bytes each * /
    //     if ((!this[4] || !this[5]) && log_gate(893)) DebugLogWrite(..., aNoCompoundsFou);
    //     /* pass 2: fill * /
    //     while (next_line(line)) {
    //       if (match(line, aSlipcurve)) {
    //         if (n >= this[2]) { if (log_gate(913)) DebugLogWrite(..., aBadSyntaxInFil); break; }
    //         TireSlipCurveBuilder(ptr, ctx); ptr += 24;
    //       }
    //       if (match(line, aCompound)) {
    //         if (m >= this[4]) { if (log_gate(928)) DebugLogWrite(..., aBadSyntaxInFil_0); break; }
    //         sub_4D6B00(ptr, ctx); ptr += 680;
    //       }
    //     }
    //     if ((n != this[2] || m != this[4]) && log_gate(941)) DebugLogWrite(..., aBadSyntaxInFil_1);
    //     close_file(ctx);
    //   } else if (log_gate(870)) {
    //     DebugLogWrite(..., aCouldNotOpenS);
    //   }
    //   return SubCallWithConditionalFieldFree(ctx);
    // UNRESOLVED: sub_587C20 is the token matcher and sub_5651B0 the line reader; their exact contracts are not established by this packet, only their usage.
    // UNRESOLVED: The slip-curve and compound array layouts (24-byte and 680-byte entries, count-at-header) are read directly from the raw source; the semantic meaning of each entry field is not asserted here.
    // UNRESOLVED: The debug line numbers passed to StringSplitLoop (893, 913, 928, 941, 870) identify source locations and carry no runtime semantics.
    // UNRESOLVED: The exact parsing contract of TireSlipCurveBuilder (004D5F70) and sub_4D6B00 is not established by this packet.
}
