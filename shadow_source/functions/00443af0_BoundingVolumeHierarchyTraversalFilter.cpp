// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00443AF0
// Canonical corpus name: BoundingVolumeHierarchyTraversalFilter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundingVolumeHierarchyTraversalFilter_00443af0.c

void UnknownObject::BoundingVolumeHierarchyTraversalFilter()
{
    // Filters bounding-volume-hierarchy traversal by comparing double-precision distance thresholds against an input value a2. Returns TRUE when a relevant volume extends beyond the test distance, FALSE when all checked volumes are within it. Three mode-dependent paths are selected by the mode dword at this+0x1E14 (==1, ==2, else default). Used by the vehicle main physics update for collision pruning.
    // GUARD: Mode guard: read the mode dword at this+0x1E14; when it equals 1 take the mode-1 filter path. [guard:1, field:this:0x00001E14, source:raw]
    // GUARD: Mode guard: when the mode dword at this+0x1E14 does not equal 2, fall through to the default filter path (LABEL_7). [guard:0, field:this:0x00001E14, source:raw]
    // GUARD: Mode-1 path: return FALSE when the threshold at this+0x3D0 is <= a2 or the threshold at this+0x834 is <= a2. [field:this:0x000003D0, field:this:0x00000834, source:raw]
    // STATE_TRANSITION: Mode-1 path falls through to the default LABEL_7 block when both thresholds exceed a2. [source:raw]
    // GUARD: Default path: return FALSE when the threshold at this+0xC98 is <= a2. [field:this:0x00000C98, source:raw]
    // RETURN: Default path: return TRUE only when the threshold at this+0x10FC is > a2 (the volume extends beyond the test distance). [field:this:0x000010FC, source:raw]
    // GUARD: Mode-2 path: return FALSE when the threshold at this+0x3D0 is <= a2. [field:this:0x000003D0, source:raw]
    // RETURN: Mode-2 path: return TRUE only when the threshold at this+0x834 is > a2. [field:this:0x00000834, source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_443AF0(int this, double a2) {
    //     if (*(int*)(this + 0x1E14) == 1) {
    //       if (*(double*)(this+0x3D0) <= a2 || *(double*)(this+0x834) <= a2) return 0;
    //     } else if (*(int*)(this + 0x1E14) != 2) {
    //       /* default * /
    //       if (*(double*)(this+0xC98) <= a2) return 0;
    //       return *(double*)(this+0x10FC) > a2;
    //     } else {
    //       /* mode 2 * /
    //       if (*(double*)(this+0x3D0) <= a2) return 0;
    //       return *(double*)(this+0x834) > a2;
    //     }
    //     /* mode-1 fall-through shares the default check * /
    //     if (*(double*)(this+0xC98) <= a2) return 0;
    //     return *(double*)(this+0x10FC) > a2;
    //   }
    // UNRESOLVED: The four double thresholds (this+0x3D0, +0x834, +0xC98, +0x10FC) and the mode selector (+0x1E14) are interpreted as bounding-volume extents for collision pruning per the existing analysis; that is DERIVED.
    // UNRESOLVED: The exact geometric meaning of input a2 (test distance) is unresolved.
    // UNRESOLVED: Why mode 1 shares the default path after its combined threshold check rather than having its own final comparison is a structural oddity left as-is from the raw source.
}
