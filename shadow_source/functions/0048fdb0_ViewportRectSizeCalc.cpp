// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FDB0
// Canonical corpus name: ViewportRectSizeCalc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ViewportRectSizeCalc_0048fdb0.c

void UnknownObject::ViewportRectSizeCalc()
{
    // Viewport rectangle size calculation (__thiscall): when the source bounding box a2 is non-null, stores its pointer into this+0x30 (this[12]), then computes one axis extent from a2[4] - a2[3] into this+0xC (this[3]) clamped to zero and the other axis extent from a2[2] - a2[1] into this+0x10 (this[4]) also clamped to zero; returns the second axis extent (or null when a2 is null or that axis is non-positive).
    // GUARD: Null gate on a2: when the source bounding box is null, no fields are written and the function returns null. [source:raw]
    // ASSIGNMENT: Store the source bounding-box pointer a2 into this+0x30 (this[12]). [field:this:0x00000030, source:raw]
    // CALCULATION: Compute one axis extent as a2[4] - a2[3]; store 0 into this+0xC (this[3]) when the difference is non-positive, otherwise store the difference plus 1. [field:this:0x0000000C, source:raw]
    // CALCULATION: Compute the other axis extent as a2[2] - a2[1]; store 0 into this+0x10 (this[4], initialized to 0) when the difference is non-positive, otherwise store the difference plus 1. [field:this:0x00000010, source:raw]
    // RETURN: Return value is null when a2 is null or when the a2[2] - a2[1] axis is non-positive; otherwise it is that axis extent plus 1. Static caller is ObjectNameComparison (0x00477280). [caller:0x00477280, function:0x0048FDB0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *ViewportRectSizeCalc(_DWORD *self, _DWORD *box) {
    //     if (!box) return 0;
    //     self[12] = box;                       /* +0x30 * /
    //     int a = box[4] - box[3];             /* one axis * /
    //     self[3] = (a > 0) ? a + 1 : 0;       /* +0xC * /
    //     int b = box[2] - box[1];             /* other axis * /
    //     self[4] = (b > 0) ? b + 1 : 0;       /* +0x10 * /
    //     return (b > 0) ? (_DWORD *)(b + 1) : 0;
    //   }
    // UNRESOLVED: Which rectangle axis maps to a2[4]-a2[3] (width) versus a2[2]-a2[1] (height) is inferred from the existing analysis; the packet does not confirm the semantic labels of the two a2 indexes.
    // UNRESOLVED: The owning viewport/layout class and the meaning of the returned extent to the caller are unidentified.
}
