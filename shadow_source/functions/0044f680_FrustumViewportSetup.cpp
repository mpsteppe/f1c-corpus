// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F680
// Canonical corpus name: FrustumViewportSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FrustumViewportSetup_0044f680.c

void UnknownObject::FrustumViewportSetup()
{
    // Configures a viewport rectangle from top a3, left a2, right a4 and bottom a5: stores the four bounds into this, computes the center X ((left+right)>>1) and center Y ((top+bottom)>>1), precomputes the reciprocal half-width 1.0/((right-left)*0.5) and reciprocal half-height 1.0/((bottom-top)*0.5) for projection scaling, and returns the right-minus-left width difference.
    // ASSIGNMENT: Store the right bound a4 into the viewport field at this+0xC (dword index 3). [field:this:0x0000000C]
    // CALCULATION: Compute result = a4 - a2, the width of the viewport in pixels. [source:raw]
    // CALCULATION: Store center X as (left + right) >> 1 into this+0x10 (dword index 4). [source:raw, field:this:0x00000010]
    // ASSIGNMENT: Store the bottom bound a5 into this+0x4 (dword index 1). [field:this:0x00000004]
    // ASSIGNMENT: Store the top bound a3 into this+0x0 (dword index 0). [field:this:0x00000000]
    // ASSIGNMENT: Store the left bound a2 into this+0x8 (dword index 2). [field:this:0x00000008]
    // CALCULATION: Store center Y as (top + bottom) >> 1 into this+0x14 (dword index 5). [source:raw, field:this:0x00000014]
    // CALCULATION: Store the reciprocal half-width 1.0 / ((right - left) * 0.5) into this+0x18 (float index 6). [source:raw, field:this:0x00000018]
    // CALCULATION: Store the reciprocal half-height 1.0 / ((bottom - top) * 0.5) into this+0x1C (float index 7). [source:raw, field:this:0x0000001C]
    // RETURN: Return result = a4 - a2, the viewport width difference. [source:raw]

    // Conservative worker pseudocode:
    //   // Viewport rectangle setup: bounds, centers and reciprocal projection factors.
    //   int width = right - left;
    //   dword[3] = right;
    //   dword[4] = (left + right) >> 1;
    //   dword[1] = bottom;
    //   dword[0] = top;
    //   dword[2] = left;
    //   dword[5] = (top + bottom) >> 1;
    //   float[6] = 1.0f / ((right - left) * 0.5f);
    //   float[7] = 1.0f / ((bottom - top) * 0.5f);
    //   return width;
    // UNRESOLVED: The exact pixel meaning of the top, left, right and bottom arguments relative to screen coordinates depends on the callers (sub_44F4E0, HWInput_Restart).
    // UNRESOLVED: The field layout as a generic frustum or viewport object is inferred from the coordinate math, not from a named type.
}
