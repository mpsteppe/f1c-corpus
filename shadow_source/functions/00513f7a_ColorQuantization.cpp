// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513F7A
// Canonical corpus name: ColorQuantization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ColorQuantization_00513f7a.c

void UnknownObject::ColorQuantization()
{
    // Iterative color-bound optimization. Quantizes 16 float samples to N levels (6 or 8) by refining a min/max bound pair through coefficient-table weighted error accumulation, then writes clamped [0,1] output bounds to *a1 (min) and *a2 (max) and returns a2.
    // GUARD: select coefficient table pair by level count: a4 == 6 uses unk_5AF5C4 and unk_5AF5AC, otherwise unk_5AF58C and unk_5AF56C [global:0x005AF5C4, global:0x005AF5AC, global:0x005AF58C, global:0x005AF56C, source:raw]
    // ASSIGNMENT: initialize min bound v36 = 1.0 and max bound v35 = 0.0 [source:raw]
    // LOOP: scan all 16 float samples at a3 computing running min v36 and max v35 [source:raw]
    // GUARD: a4 == 8 uses an unclamped min/max scan; otherwise the scan is clamped to samples inside (0,1) [source:raw]
    // CALCULATION: v25 = a4 - 1 and v28 = (float)(a4 - 1) provide the level step divisor [source:raw]
    // CALL: call FPUControlWordMerger() to configure the FPU control/rounding word for the quantization arithmetic [callee:0x00513E5D]
    // LOOP: iterate up to 8 refinement passes; break early when the current range v35 - v36 is below 0.00390625 [source:raw]
    // CALCULATION: compute step scale v27 = (a4 - 1) / (v35 - v36) [source:raw]
    // CALCULATION: reconstruct level values v24[j] = v35 * tableB[j] + v36 * tableA[j] from the selected coefficient tables; for a4 == 6 force v24[6] = 0.0 and v24[7] = 1.0 [global:0x005AF5C4, global:0x005AF5AC, global:0x005AF58C, global:0x005AF56C, source:raw]
    // LOOP: for each of the 16 samples compute the quantized index v15 and accumulate error-weighted sums v34/v32 (min side) and v33/v31 (max side) [source:raw]
    // GUARD: for a4 == 6 skip samples at or beyond the outer bounds, i.e. (v35 + 1.0) * 0.5 <= sample or v36 * 0.5 >= sample [source:raw]
    // CALCULATION: update bounds: v36 -= v34 / v32 when v32 > 0.0, v35 -= v33 / v31 when v31 > 0.0, then swap if v36 > v35 [source:raw]
    // GUARD: break the refinement loop when both squared error sums v34 * v34 and v33 * v33 are below 0.015625 [source:raw]
    // CALCULATION: clamp the refined bounds v36 and v35 into [0,1] [source:raw]
    // ASSIGNMENT: write output bounds: *a1 = v36 (min bound) and *a2 = v35 (max bound) [field:this:0x00000000, source:raw]
    // RETURN: return a2, the max-bound output pointer [source:raw]

    // Conservative worker pseudocode:
    //   // table selection by level count
    //   if (levels == 6) { coef_a = tbl_5AF5C4; coef_b = tbl_5AF5AC; }
    //   else             { coef_a = tbl_5AF58C; coef_b = tbl_5AF56C; }
    //   min_b = 1.0f; max_b = 0.0f;
    //   for (k = 0; k < 16; k++) {
    //       s = samples[k];
    //       if (levels == 8) { min_b = fminf(min_b, s); max_b = fmaxf(max_b, s); }
    //       else             { if (s > 0.0f && s < min_b) min_b = s; if (s < 1.0f && s > max_b) max_b = s; }
    //   }
    //   FPUControlWordMerger();
    //   for (pass = 0; pass < 8; pass++) {
    //       range = max_b - min_b;
    //       if (range < 0.00390625f) break;
    //       step = (float)(levels - 1) / range;
    //       for (j = 0; j < levels; j++) level[j] = max_b * coef_b[j] + min_b * coef_a[j];
    //       if (levels == 6) { level[6] = 0.0f; level[7] = 1.0f; }
    //       e_min = 0.0f; d_min = 0.0f; e_max = 0.0f; d_max = 0.0f;
    //       for (k = 0; k < 16; k++) {
    //           idx = nearest level index for samples[k];
    //           err = samples[k] - level[idx];
    //           e_min += err * coef_a[idx]; d_min += coef_a[idx] * coef_a[idx];
    //           e_max += err * coef_b[idx]; d_max += coef_b[idx] * coef_b[idx];
    //       }
    //       if (d_min > 0.0f) min_b = min_b - e_min / d_min;
    //       if (d_max > 0.0f) max_b = max_b - e_max / d_max;
    //       if (min_b > max_b) swap(min_b, max_b);
    //       if (e_min * e_min < 0.015625f && e_max * e_max < 0.015625f) break;
    //   }
    //   *a1 = clamp(min_b, 0.0f, 1.0f);
    //   *a2 = clamp(max_b, 0.0f, 1.0f);
    //   return a2;
    // UNRESOLVED: globals flt_59E43C, flt_59E440, flt_59E450, flt_59E778, flt_5AC988, flt_5ADB14 and dword_8B00A0 appear in the packet global list but not in the visible decompiled body; they may be consumed inside FPUControlWordMerger or be mis-attributed
    // UNRESOLVED: the output *a2 (max bound) has no field evidence ref; only *a1 maps to field:this:0x00000000
    // UNRESOLVED: the per-sample index selection and skip rules for the non-6 case are only partially visible in the decompilation
}
