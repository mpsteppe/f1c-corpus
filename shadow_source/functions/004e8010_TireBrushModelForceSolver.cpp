// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E8010
// Canonical corpus name: TireBrushModelForceSolver
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireBrushModelForceSolver_004e8010.c

void UnknownObject::TireBrushModelForceSolver()
{
    // Per-frame tire force solver on the vehicle object: iterates 15 normalized slip-ratio samples, and for each sample accumulates brush-model longitudinal/lateral force contributions over the four per-wheel records (stride 248 bytes from base 13868) with load-transfer sign patterns, storing a per-wheel 15-entry force array. Then derives a corner-weight/average-load value from load-transfer mode, normalizes per-wheel vertical loads, applies wet/dry grip scaling (flag a2) to the 15-entry lookup table at 15424/15488, and finally runs a 15-iteration bisection solve that inverts a slope lookup (via sub_5895A2 with linear interpolation) to produce vertical-force/slip solutions written to an output array at 15616. Reads many tire/geometry/weight fields and a set of module float constants.
    // ASSIGNMENT: Read grip/wet constants flt_7D0278 and flt_7D029C; compute v87 = 1.0 / flt_7D029C and v5 = 1.0 / (0.071428575 * flt_7D0278), then store the inverse-slip factor into the four per-wheel fields at 15356, 15420, 15484, 15548 and the related value at 15612. [global:0x007D0278, global:0x007D029C, field:this:0x00003BFC, field:this:0x00003C3C, field:this:0x00003C7C, field:this:0x00003CBC, field:this:0x00003CFC, source:raw]
    // CALCULATION: Load-geometry normalization: v94 = 1.0 / (fabs(13964 + 13716 - 14212 - 14460) * 0.5) and v90 = 1.0 / (fabs(13708 - 13956 + 14204 - 14452) * 0.5), combining per-axle corner-weight geometry fields. [field:this:0x0000368C, field:this:0x00003594, field:this:0x00003784, field:this:0x0000387C, field:this:0x0000358C, field:this:0x00003684, field:this:0x0000377C, field:this:0x00003874, source:raw]
    // LOOP: 15-iteration outer loop over slip samples (counter v76): per-sample slip factor v74 = v76 * flt_7D0278 * 0.071428575. [global:0x007D0278, source:raw]
    // LOOP: Inner 4-wheel accumulation over the wheel record array at base 13868 (stride 62 dwords): reads the slip input at +72 per wheel, clamps it to the per-wheel cap, and accumulates v8; then v12 = v8 * the field at 16420, and precomputes v83 = v94 * v12 * 0.5 and v81 = v12 * v90 * 0.5. [field:this:0x0000362C, field:this:0x00003674, field:this:0x00004024, source:raw]
    // LOOP: Four load-transfer summation variants over the wheels (front/rear and left/right sign patterns), gated by the load-transfer mode field at 14772, producing the four per-wheel force accumulations v15, v20, v27, v34. [field:this:0x000039B4, source:raw]
    // ASSIGNMENT: Store the four accumulated force samples into the per-wheel output arrays at bases 15488 and 15552 (and adjacent slots), advancing one sample per outer iteration. [field:this:0x00003C80, field:this:0x00003CC0, source:raw]
    // STATE_TRANSITION: Load-transfer mode selector on the field at 14772: mode 0 averages fields 14584 and 14336, mode 1 averages fields 14584, 14336, 14088 and 13840 (quarter), mode 2 averages fields 14088 and 13840; the result (halved or quartered) is stored to the field at 15680. [field:this:0x000039B4, field:this:0x000038F8, field:this:0x00003800, field:this:0x00003708, field:this:0x00003610, field:this:0x00003D40, source:raw]
    // LOOP: Corner-weight normalization over the wheel array at base 13840: picks front weight field 14896 or rear weight field 14916 by index, accumulates weight/load per wheel, then v51 = sum * the field at 13592 and stores it to the field at 15676. [field:this:0x00003610, field:this:0x00003A30, field:this:0x00003A44, field:this:0x00003518, field:this:0x00003D3C, source:raw]
    // CALCULATION: Per-wheel vertical-load scratch array: v54 = field 14960 * 4096.0 - field 13588 * -9.8100004; for each wheel at base 13840, v98[i] = 0.0 when the wheel load is not positive, else v54 / load * the field at +40 (13880); the field at 15684 is seeded from the field at 14956. [field:this:0x00003610, field:this:0x00003638, field:this:0x00003A6C, field:this:0x00003A70, field:this:0x00003514, field:this:0x00003D44, source:raw]
    // ASSIGNMENT: Write the blended vertical load to the field at 15684: ((v98[3] + v98[2]) * 0.27500001 + (v98[1] + v98[0]) * 0.22499999) * 0.00024414062 + prior value. [field:this:0x00003D44, source:raw]
    // GUARD: Grip-mode branch on a2: wet path scales the field at 15676 by 0.92 and rescales all 15 entries of the lookup tables at base 15424 by 1.0 / field 15348 times 0.92/0.84 factors; dry path scales the field at 15676 by flt_7D020C and multiplies the same table entries by flt_7D0230, flt_7D0254 and 0.97000003. [field:this:0x00003D3C, field:this:0x00003BF4, field:this:0x00003C40, global:0x007D020C, global:0x007D0230, global:0x007D0254, source:raw]
    // LOOP: 15-iteration vertical-force bisection solve (counter v60, output pointer at base 15616): per sample v96 = v77 * v87 * 0.071428575, then an inner bisection loop over v75 starting at 128.0 with step v82 halved each pass, breaking when v82 falls below 0.4. [source:raw]
    // CALCULATION: Per-iteration load math inside the bisection: v86 = v75 * field 13588 * v75 * v96 and v62 = v75 * v75 * field 14960 - (v75 * v75 * 0.0 - 9.8100004) * field 13588. [field:this:0x00003514, field:this:0x00003A70, source:raw]
    // CALCULATION: Slope lookup and interpolation: v63 = v62 * field 15420 and v66 = v62 * field 15484; after sub_5895A2 the integer parts are clamped to 0..13 and linearly interpolated between the table pairs at bases 15424 and 15488; the maximum of the two interpolated values is kept. [field:this:0x00003C3C, field:this:0x00003C7C, field:this:0x00003C40, field:this:0x00003C80, source:raw]
    // CALL: Call sub_5895A2 with the slope values v63 and v66 to extract their fractional parts for table indexing. [callee:0x005895A2, source:raw]
    // CALCULATION: Bisection convergence: v84 = (v86 == 0.0) ? 1024.0 : v68 / v86; update the bracket v75 by +/- v82 and halve v82 each pass. [source:raw]
    // CALCULATION: Final interpolation of the solved value: v71 = v84 - v97; when zero, keep v75, otherwise v72 = (v84 - 1.0) / v71 clamped to [-1.0, 2.0] giving v73 = v72 * (v95 - v75) + v75 (or the lower-clamped variant); clamp v73 >= 0 and store into the output array at base 15616. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_4E8010(int this, char gripMode) {
    //     // Normalize slip factors into 4 per-wheel inverse-slip fields.
    //     for (sample = 0; sample < 15; ++sample) {
    //       s = sample * flt_7D0278 * 0.071428575;
    //       // For each of 4 wheels: accumulate clamped brush force terms
    //       // from wheel record (base 13868, stride 248) into v8.
    //       v12 = v8 * this[16420];
    //       // Four sign-variant accumulations (load transfer by mode at 14772)
    //       // -> v15, v20, v27, v34 stored into per-wheel force arrays at 15488/15552.
    //     }
    //     // Load-transfer average -> field 15680; corner weights -> field 15676.
    //     // Per-wheel vertical loads v98; blended load -> field 15684.
    //     // Wet/dry grip scaling of 15-entry lookup tables (base 15424).
    //     for (sample = 0; sample < 15; ++sample) {
    //       // Bisection over v75 in [0,128]: solve slope lookup
    //       // via sub_5895A2 + linear interp (tables at 15424/15488);
    //       // write solution to output array at base 15616.
    //     }
    //   }
    // UNRESOLVED: Eighteen module float constants (0x0059E420, 0x0059E438, 0x0059E43C, 0x0059E440, 0x0059E450, 0x0059E670, 0x0059E7F8, 0x0059E800, 0x0059E8C8, 0x005ACB44, 0x005ACDC4, 0x005ACEB8, 0x005ACEE8, 0x005AD1B0, 0x005AD1B4, 0x005AD1B8, 0x005AD1BC, 0x005AD1C0) are read (R) per static facts but do not appear as named globals in the Hex-Rays source; they are believed to back the FPU literals (0.071428575, 0.27500001, 0.22499999, 0.92, etc.) folded by the decompiler. Mapping each constant to a specific global is not established.
    // UNRESOLVED: Per-wheel record stride and the meaning of each wheel sub-field (slip cap, grip, weight) are DERIVED from the 62-dword stride pattern, not proven.
    // UNRESOLVED: The physical interpretation of the bisection output (vertical force vs slip limit per sample) is DERIVED from the brush-model structure; the owning vehicle class and exact field names are UNKNOWN.
    // UNRESOLVED: The lookup tables at 15424 and 15488 and their 15-entry layout are inferred from the clamped index 0..13 interpolation; table identity is unknown.
}
