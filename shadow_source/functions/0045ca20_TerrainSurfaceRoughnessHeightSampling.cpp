// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045CA20
// Canonical corpus name: TerrainSurfaceRoughnessHeightSampling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TerrainSurfaceRoughnessHeightSampling_0045ca20.c

void UnknownObject::TerrainSurfaceRoughnessHeightSampling()
{
    // Samples terrain surface roughness/height at index a2. Returns a fallback height 0.0 (true) when the surface type lookup rejects the index, and the sentinel 9.9989996 (false) when the roughness byte is zero or on forced re-sample. Otherwise decodes the packed height field, computes a weighted average over a clamped sample window, caches the result at this[4*a2+4388] when the surface type is 16, and stores a penetration compensation short at this[2*a2+4804]. On the per-frame path; called by NetCommSessionMessageDispatcher, PhysicsIntegrationStep_e620, SessionSynchronizer, TerrainHeightComparison and ShortComputation_2530.
    // GUARD: Surface type guard: if dword_5EF9A0[4656 * a2] != 2, set *a3 = 0.0 and return 1 (true) without sampling. [global:0x005EF9A0, source:raw]
    // CALL: Read the bounded roughness byte: v7 = BoundedByteArrayAccessor(this, a2). [callee:0x0045C780, source:raw]
    // GUARD: If the roughness byte v7 is zero, set *a3 = 9.9989996 and return 0 (false). [source:raw]
    // GUARD: Cached-height fast path: if this[4 * a2 + 4388] > 0.0, set *a3 to that cached value and return 1 (true). [source:raw]
    // GUARD: Forced re-sample guard: if a4's low byte is set and the surface type v7 != 16, set *a3 = 9.9989996 and return v7 == 16. [source:raw]
    // ASSIGNMENT: Copy sizeof(v17) bytes of packed height data from this[32 * a2 + 1060] into the local v17 short array via qmemcpy. [source:raw]
    // CALL: Decode/process the packed height field: sub_5890AA(v17, v7, 2, sub_45C760), passing the wavelet/height-field decoder sub_45C760 as a function pointer. [callee:0x005890AA, global:0x0045C760, source:raw]
    // CALCULATION: Compute the sample-window size as v7 * 0.33399999, clamped to a minimum of 1.0, and convert to an integer window via CRTFtol. [callee:0x00587BDC, source:raw]
    // CALCULATION: Weight v9 = 1.0 / window_size used to normalize each sample in the accumulation. [source:raw]
    // CALCULATION: Establish the averaging window: start v11 = (v7 - window) / 2 and end v12 = v11 + window. [source:raw]
    // LOOP: Accumulate the weighted average over [v11, v12): ShortToFloatConversion(v17[i], &a4) converts each short sample, then *a3 += a4 * v9. [callee:0x0045C7C0, source:raw]
    // GUARD: Surface type 16 cache/penetration path: store *a3 at this[4 * a2 + 4388]. If flt_7D108C >= *a3 >= 0.0, FloatToShortViaFtol(0.0, &this[2 * a2 + 4804]); otherwise compute penetration v15 = flt_7D108C * 0.25 - *a3 and store it via FloatToShortViaFtol(v15, &this[2 * a2 + 4804]). [global:0x007D108C, callee:0x0045C7A0, source:raw]
    // RETURN: Return v7 == 16 on the type-16 and forced re-sample paths. [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_45CA20(byte* this, uint a2, float* a3, float a4) {
    //     if (dword_5EF9A0[4656 * a2] != 2) { *a3 = 0.0f; return true; }
    //     int v7 = BoundedByteArrayAccessor(this, a2);
    //     if (!v7) { *a3 = 9.9989996f; return false; }
    //     if (*(float*)&this[4 * a2 + 4388] > 0.0f) { *a3 = *(float*)&this[4 * a2 + 4388]; return true; }
    //     bool res = v7 == 16;
    //     if (LOBYTE(a4) && v7 != 16) { *a3 = 9.9989996f; return res; }
    //     short v17[16]; memcpy(v17, &this[32 * a2 + 1060], sizeof(v17));
    //     sub_5890AA(v17, v7, 2, sub_45C760);
    //     double win = (double)v7 * 0.33399999; if (win < 1.0) win = 1.0;
    //     int w = CRTFtol(win); float inv = 1.0f / (float)w;
    //     int lo = (v7 - w) / 2; int hi = lo + w; *a3 = 0.0f;
    //     for (int i = lo; i < hi; ++i) { ShortToFloatConversion(v17[i], &a4); *a3 += a4 * inv; }
    //     if (v7 == 16) {
    //       *(float*)&this[4 * a2 + 4388] = *a3;
    //       if (flt_7D108C >= *a3 && *a3 >= 0.0f) { FloatToShortViaFtol(0.0f, &this[2 * a2 + 4804]); return v7 == 16; }
    //       FloatToShortViaFtol(flt_7D108C * 0.25f - *a3, &this[2 * a2 + 4804]);
    //     }
    //     return v7 == 16;
    //   }
    // UNRESOLVED: v6 is read in this[4 * v6 + 4388] and this[32 * v6 + 1060] but never written in the reconstruction; decompiler artifact whose value is likely derived from the index a2.
    // UNRESOLVED: Globals flt_59E43C, flt_59E440, flt_59E7F8 and flt_59F0C0 are listed in the packet but do not appear in the raw reconstruction; their role here is unclear.
    // UNRESOLVED: Semantics of the byte-array accessor BoundedByteArrayAccessor and the sub_5890AA decoding routine are not defined by this packet.
    // UNRESOLVED: Meaning of the sentinel height 9.9989996 (invalid/unreachable surface marker) is not stated in the packet.
}
