// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D5F70
// Canonical corpus name: TireSlipCurveBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireSlipCurveBuilder_004d5f70.c

void UnknownObject::TireSlipCurveBuilder()
{
    // Parses a tire slip-curve definition (header fields Name and Step, then a Data section of slip/force points), builds a cubic Hermite spline through the points with per-segment coefficients stored in an allocated array at this+0x14, finds the peak grip slip angle, and normalizes every coefficient by the peak force. Rejects non-positive step, fewer than three points, and a non-zero first data point with debug logging.
    // LOOP: Iterate the file sections via ConditionalDispatchBasedOnFlag over the 384-byte parse buffer, reading each line with sub_5651B0 until a terminal line kind (v4 == 1 or v4 == 4) ends parsing. [callee:0x00566CC0, callee:0x005651B0, source:raw]
    // GUARD: The parse state flag v43 selects header parsing versus data-point parsing: until the Data section is entered, lines are treated as header fields. [source:raw]
    // CALL: Parse the header Name field (sub_5654A0 against the aName token) and store the resulting string via StringCopyWithBufferRealloc. [callee:0x005654A0, callee:0x00566650, global:0x005D4710, source:raw]
    // CALL: Parse the header Step field (sub_565AA0 against the aStep token) into the step value v58. [callee:0x00565AA0, global:0x005D4708, source:raw]
    // STATE_TRANSITION: When sub_587C20 matches the aData section token, the parse state flag v43 is set so subsequent lines are parsed as data points. [callee:0x00587C20, global:0x005D4700, source:raw]
    // LOOP: Tokenize data points with sub_5897CA against the unk_5D46FC token; each accepted point line is parsed by StrlenFormatCallWrapper using the off_5D46F8 format string into v56. [callee:0x005897CA, global:0x005D46FC, global:0x005D46F8, callee:0x005887ED, source:raw]
    // GUARD: Grow the temporary point buffer v48 by 128 points (8*(v44+128) bytes) once the point index v3 reaches the capacity v44, allocating with OperatorNewNhMallocWrapper, copying the prior points across, and freeing the old buffer. [callee:0x00587C03, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Append the parsed double v56 at v48[v39] and advance the count v3 and index v49/v39. [source:raw]
    // GUARD: Malformed point lines fall back to StringSplitLoop(1, aDDevF119992002_4, 287) and, when it returns true, log 'skipping unexpected' through DebugLogWrite to the dword_8AD25C log sink. [callee:0x004D7A50, global:0x005D45E4, callee:0x004D7AA0, global:0x005D46BC, global:0x008AD25C, source:raw]
    // GUARD: Reject a non-positive step: v58 <= 0.0 triggers StringSplitLoop(1, aDDevF119992002_4, 301) and logs the aTireSlipCurveS error before returning. [callee:0x004D7A50, global:0x005D45E4, callee:0x004D7AA0, global:0x005D4684, global:0x008AD25C, source:raw]
    // GUARD: Reject fewer than 3 data points (v3 < 3) via StringSplitLoop(1, aDDevF119992002_4, 310) and the aNeedAtLeastDDa error log. [callee:0x004D7A50, global:0x005D45E4, callee:0x004D7AA0, global:0x005D4648, global:0x008AD25C, source:raw]
    // GUARD: Reject a first data point that is not 0.0 (v48[0]) via StringSplitLoop(1, aDDevF119992002_4, 318) and the aFirstDataPoint error log. [callee:0x004D7A50, global:0x005D45E4, callee:0x004D7AA0, global:0x005D4610, global:0x008AD25C, source:raw]
    // ASSIGNMENT: Store the data-point count to this+0x10 (this[4]) and allocate the spline coefficient array at this+0x14 (this[5]) with 32 bytes per segment. [field:this:0x00000010, field:this:0x00000014, callee:0x00587C03, source:raw]
    // GUARD: The initial slope v11 uses a two-point difference when the count this+0x10 is <= 3, else a central-difference blend over the first four points. [guard:0, field:this:0x00000010, source:raw]
    // CALL: For each spline segment, build the Hermite basis and solve it with sub_5677B0(v85, 4); the four cubic coefficients are written into the segment at offsets 0x0, 0x8, 0x10 and 0x18 of the array at this+0x14. [callee:0x005677B0, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000008, field:*(this+0x14):0x00000010, field:*(this+0x14):0x00000018, field:this:0x00000014, source:raw]
    // LOOP: Finalize the last segment by writing zero coefficients for the cubic, quadratic and linear terms and the final data point (v48[v14]) as the constant term at this+0x14. [field:this:0x00000014, source:raw]
    // LOOP: Peak search: reset this+0x8 and this+0xC to zero, then evaluate each segment cubic at the segment start, at the two extremum candidates from the derivative roots, and at the segment end; whenever a higher force is found, store the slip angle in this+0x8 as a double (this[1]). [field:this:0x00000008, field:this:0x0000000C, field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000008, field:*(this+0x14):0x00000010, field:*(this+0x14):0x00000018, source:raw]
    // CALCULATION: Normalize the curve: scale every coefficient at offsets 0x0, 0x8, 0x10 and 0x18 of each segment by 1.0/peakForce (v55), so the peak grip force maps to unit magnitude. [field:*(this+0x14):0x00000000, field:*(this+0x14):0x00000008, field:*(this+0x14):0x00000010, field:*(this+0x14):0x00000018, source:raw]
    // RETURN: Free the temporary point buffer v48 via FreeWrapper_7bcf and return. [callee:0x00587BCF, source:raw]
    // CALL: Invoked by TireBrandFileParser (004D7150) as the tire-brand file load path. [caller:0x004D7150, source:raw]

    // Conservative worker pseudocode:
    //   // Parse header fields until the Data section, then collect doubles.
    //   memset(buf384, 0, sizeof(buf384)); step = 0.01; in_data = 0;
    //   while (ConditionalDispatchBasedOnFlag(buf384, 384)) {
    //     kind = sub_5651B0(line);
    //     if (kind == 1 || kind == 4) break;
    //     if (kind != 0) continue;
    //     if (!in_data) {
    //       if (sub_5654A0("Name", name)) StringCopyWithBufferRealloc(name);
    //       sub_565AA0("Step", &step, 0, 0, 0);
    //       if (sub_587C20(buf384, "Data")) in_data = 1;
    //     } else {
    //       for (tok = sub_5897CA(buf384, &unk_5D46FC); tok;
    //            tok = sub_5897CA(0, &unk_5D46FC)) {
    //         if (StrlenFormatCallWrapper(tok, off_5D46F8, &val) == 1) {
    //           if (count >= cap) { grow v48 by 128; copy; free old; }
    //           v48[count++] = val;
    //         } else if (StringSplitLoop(1, aDDevF119992002_4, 287))
    //           DebugLogWrite(&dword_8AD25C, aSkippingUnexpe);
    //       }
    //     }
    //   }
    //   if (step <= 0.0) return err(aTireSlipCurveS, 301);
    //   if (count < 3) return err(aNeedAtLeastDDa, 310);
    //   if (v48[0] != 0.0) return err(aFirstDataPoint, 318);
    //   this[4] = count;
    //   this[5] = OperatorNewNhMallocWrapper(32 * count);
    //   // Build cubic Hermite segments (sub_5677B0), then peak-search and normalize.
    //   return FreeWrapper_7bcf(v48);
    // UNRESOLVED: Six read-only doubles (dbl_59E420, dbl_59E430, dbl_59E7D8, dbl_59E7E0, dbl_59E880, dbl_59EC10) are flagged by packet facts but never appear in the raw decompiled source; likely step or peak constants, unverifiable from this packet.
    // UNRESOLVED: byte_5EA438 is flagged as read but absent from the raw decompiled source; its role in this function is unknown.
    // UNRESOLVED: The exact Hermite basis layout (v85 pointer set over the v59 double plus stride-5 offsets) and the internal semantics of sub_5677B0 are only partially recoverable from this packet.
}
