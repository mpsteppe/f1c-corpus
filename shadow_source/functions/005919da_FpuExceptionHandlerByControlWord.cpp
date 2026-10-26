// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005919DA
// Canonical corpus name: sub_5919DA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5919DA_005919da.c

void UnknownObject::FpuExceptionHandlerByControlWord()
{
    // Handles the FPU exception bits in a1 (lower 5 bits: divide-by-zero, denormal, underflow, overflow, inexact) against the FPU control word mask a3. Each masked exception bit is cleared in v3 (accumulated from a1 & 0x1F). The underflow branch selects a clamped constant (dbl_5E7718/dbl_5E7728, sign by input) based on rounding-mode bits (a3 & 0xC00); the overflow branch denormalizes or flushes the double via sub_591D88. EmptyStub_1e89 logs each handled exception type (1, 4, 8, 16, 32). Returns TRUE iff all exception bits were consumed (v3 == 0). On-frame per-frame tick path.
    // UNKNOWN: Identity: BOOL __cdecl sub_5919DA(char a1, double *a2, __int16 a3) — FPU exception handling driven by the FPU control word; packet marks on_frame_path [function:0x005919DA, source:raw]
    // ASSIGNMENT: Initialize v3 = a1 & 0x1F: the set of FPU exception bits pending handling [source:raw]
    // GUARD: Divide-by-zero path: when the a1 bit 8 (0x08) exception is set and the control word mask bit 1 (a3 & 1) is set, handle it [source:raw]
    // CALL: EmptyStub_1e89(1) logs the divide-by-zero exception type [callee:0x00591E89, source:raw]
    // ASSIGNMENT: Clear the divide-by-zero bit: v3 = a1 & 0x17 [source:raw]
    // GUARD: Denormal path: when the a1 bit 4 (0x04) exception is set and the mask bit 4 (a3 & 4) is set, handle it [source:raw]
    // CALL: EmptyStub_1e89(4) logs the denormal exception type [callee:0x00591E89, source:raw]
    // ASSIGNMENT: Clear the denormal bit: v3 = a1 & 0x1B [source:raw]
    // GUARD: Underflow path: when the a1 bit 1 (0x01) exception is set and the mask bit 8 (a3 & 8) is set, handle it [source:raw]
    // CALL: EmptyStub_1e89(8) logs the underflow exception type [callee:0x00591E89, source:raw]
    // CALCULATION: Extract rounding-mode bits v4 = a3 & 0xC00. When non-zero, select the underflow result constant by rounding mode: case 1024 (0x400) and 2048 (0x800) choose between -dbl_5E7718 and dbl_5E7728 (or inverse) depending on the sign of *a2; case 3072 (0xC00) starts from dbl_5E7728 and negates on comparison flags; the else branch (a3 & 0xC00 == 0) starts from dbl_5E7718 and negates on comparison flags [global:0x005E7718, global:0x005E7728, source:raw]
    // ASSIGNMENT: Write the selected underflow result constant v7 back through v5 into *a2 [source:raw]
    // ASSIGNMENT: After the underflow branch, clear the underflow bit: v3 = a1 & 0x1E [source:raw]
    // GUARD: Overflow path: when the a1 bit 2 (0x02) exception is set and the mask bit 0x10 (a3 & 0x10) is set, handle it [source:raw]
    // CALCULATION: v13 = (a1 & 0x10) != 0 records the inexact flag; snapshot v19 = *a2 [source:raw]
    // GUARD: When the overflowed value is exactly 0.0, set v13 = 1 (value already exact, nothing to normalize) [source:raw]
    // CALL: sub_591D88(v19, &v20) extracts the binary exponent of the overflowed double; exponent offset v14 = v20 - 1536 [callee:0x00591D88, source:raw]
    // CALCULATION: When v14 < -1021, denormalization loop: right-shift the mantissa of v19 one bit at a time (halving the value), setting v13 on each dropped 1 bit, propagating the guard bit, until the exponent reaches -1021; re-apply the sign v15 [source:raw]
    // GUARD: When the exponent offset is out of range (v14 < -1074), flush to zero: v13 = 1 and v19 = 0.0 [source:raw]
    // ASSIGNMENT: Write back the clamped/denormalized result: *a2 = v19 [source:raw]
    // CALL: When v13 (inexact/sticky flag) is set, EmptyStub_1e89(16) logs the inexact-overflow event [callee:0x00591E89, source:raw]
    // ASSIGNMENT: Clear the overflow bit: v3 = a1 & 0x1D [source:raw]
    // GUARD: Inexact path: when the a1 bit 0x10 exception is set and the mask bit 0x20 (a3 & 0x20) is set, handle it [source:raw]
    // CALL: EmptyStub_1e89(32) logs the inexact exception type [callee:0x00591E89, source:raw]
    // ASSIGNMENT: Clear the inexact bit: v3 &= ~0x10 [source:raw]
    // RETURN: Return TRUE iff all masked exception bits were consumed (v3 == 0); an exception bit with no matching control-word mask bit survives and yields FALSE [source:raw]
    // CALL: Invoked by ConditionalMathWithDAT005e9ad0Flag (0059168F) on the per-frame tick path [caller:0x0059168F]
    // CALL: Invoked by sub_596175 (00596175) [caller:0x00596175]

    // Conservative worker pseudocode:
    //   v3 = a1 & 0x1F;
    //   if ((a1 & 0x08) && (a3 & 0x01)) { EmptyStub_1e89(1); v3 = a1 & 0x17; goto done; }
    //   if ((a1 & 0x04) && (a3 & 0x04)) { EmptyStub_1e89(4); v3 = a1 & 0x1B; goto done; }
    //   if ((a1 & 0x01) && (a3 & 0x08)) {
    //     EmptyStub_1e89(8);
    //     v4 = a3 & 0xC00;
    //     if (v4 == 0x400)      v7 = (*a2 <= 0.0) ? -dbl_5E7718 : dbl_5E7728;
    //     else if (v4 == 0x800) v7 = (*a2 <= 0.0) ? -dbl_5E7728 : dbl_5E7718;
    //     else if (v4 == 0xC00) v7 = flags ? -dbl_5E7728 : dbl_5E7728;
    //     else if (v4 == 0)     v7 = flags ? -dbl_5E7718 : dbl_5E7718;
    //     else { v3 = a1 & 0x1E; goto done; }
    //     *a2 = v7;
    //     v3 = a1 & 0x1E;
    //     goto done;
    //   }
    //   if ((a1 & 0x02) && (a3 & 0x10)) {
    //     v13 = (a1 & 0x10) != 0;
    //     v19 = *a2;
    //     if (v19 == 0.0) v13 = 1;
    //     else {
    //       sub_591D88(v19, &v20);
    //       v14 = v20 - 1536;
    //       if (v14 >= -1074) {
    //         v15 = v19 < 0.0;
    //         v16 = (BYTE6(v19) & 0xF) | 0x10; HIWORD(v19) = v16;
    //         if (v14 < -1021) {
    //           v17 = -1021 - v14;
    //           do { if ((LOBYTE(v19) & 1) && !v13) v13 = 1; LODWORD(v19) >>= 1;
    //                if (BYTE4(v19) & 1) BYTE3(v19) |= 0x80; HIDWORD(v19) >>= 1; --v17; } while (v17);
    //         }
    //         if (v15) v19 = -v19;
    //       } else { v13 = 1; v19 = 0.0; }
    //       *a2 = v19;
    //     }
    //     if (v13) EmptyStub_1e89(16);
    //     v3 = a1 & 0x1D;
    //   }
    //   done:
    //   if ((a1 & 0x10) && (a3 & 0x20)) { EmptyStub_1e89(32); v3 &= ~0x10; }
    //   return v3 == 0;
    // UNRESOLVED: The dbl_5B8CC8 global (DoubleZero) is flagged by packet facts but appears nowhere in the raw decompiled source; its role here is not verifiable
    // UNRESOLVED: The v8/v9/v11/v12 comparison-flag locals driving the case-3072 and default underflow constant negation are decompiler artifacts whose exact comparison is not recoverable from this source
    // UNRESOLVED: The precise meaning of the rounding-mode selection (a3 & 0xC00) as a rounding control is inferred, not proven
}
