// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00424AC0
// Canonical corpus name: AIDifficultyInterpolation
// Owner: AIDifficultyCurve [DERIVED]
// Raw source: functions/AIDifficultyInterpolation_00424ac0.c

void AIDifficultyCurve::interpolateAIDifficulty()
{
    // Maps the AI difficulty slider (dword_7D01A0) onto an interpolated ability value using three anchor constants (flt_5EA3DC low, flt_5EA3E0 mid, flt_5EA3E4 high). Slider values above 100 use linear interpolation between the mid and high anchors; values at or below 100 interpolate between the low and mid anchors. Returns the interpolated double.
    // GUARD: Guard: branch on dword_7D01A0 (AIDifficultySlider) > 100 to select the high-range branch; otherwise fall through to the low/mid branch. [global:0x007D01A0]
    // CALCULATION: High branch: return v0 + (flt_5EA3E4 - v0) * ((double)(dword_7D01A0 - 100) * 0.050000001) where v0 = flt_5EA3E0, i.e. linear interpolation from mid to high as the slider exceeds 100. [global:0x005EA3E0, global:0x005EA3E4, global:0x007D01A0]
    // CALCULATION: Low branch: return (double)(dword_7D01A0 - 70) * 0.033333335 * (flt_5EA3E0 - flt_5EA3DC) + flt_5EA3DC, i.e. linear interpolation from low to mid as the slider rises from 70. [global:0x007D01A0, global:0x005EA3E0, global:0x005EA3DC]

    // Conservative worker pseudocode:
    //   mid = flt_5EA3E0
    //   if (dword_7D01A0 > 100)
    //       return mid + (flt_5EA3E4 - mid) * (slider - 100) * 0.05
    //   else
    //       return (slider - 70) * 0.033333335 * (mid - flt_5EA3DC) + flt_5EA3DC
    // UNRESOLVED: The exact meanings of the three anchor constants (flt_5EA3DC / flt_5EA3E0 / flt_5EA3E4) are not confirmed by the packet; named low/mid/high by position in the interpolation.
    // UNRESOLVED: The normalization points 70 and 100 (and the 0.05 / 0.033333335 slopes) are literals from the raw source; their tuning rationale is unknown.
    // UNRESOLVED: globals flt_59E448 and flt_59E474 are listed as read in the packet but do not appear in the raw decompiled body, so their role is unknown.
}
