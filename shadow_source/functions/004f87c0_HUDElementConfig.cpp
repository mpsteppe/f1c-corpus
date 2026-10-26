// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F87C0
// Canonical corpus name: HUDElementConfig
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HUDElementConfig_004f87c0.c

void UnknownObject::HUDElementConfig()
{
    // Configures an indexed HUD/feedback element: dereferences this to read a flag at *(this) + 0x32C8 that selects the gain source (flt_7CF35C when non-zero, flt_7CF338 plus an index increment of 1 when zero). Selects element result = this + 8*a2, writes gain = v6 * a4, writes magnitude a5, sets the byte at result+180 to 1, clamps the index v5 to [0, 3] (or 0 when negative), and clears the byte at result+196.
    // GUARD: Dereference this to read the flag at (*(DWORD*)this + 0x32C8); non-zero selects flt_7CF35C as gain source and keeps a3, zero selects flt_7CF338 and sets v5 = a3 + 1. [field:this:0x00000000, field:obj:0x000032C8, global:0x007CF35C, global:0x007CF338, source:raw]
    // ASSIGNMENT: v6 = flt_7CF35C when the flag at obj+0x32C8 is non-zero. [global:0x007CF35C, source:raw]
    // ASSIGNMENT: v6 = flt_7CF338 and v5 = a3 + 1 when the flag at obj+0x32C8 is zero. [global:0x007CF338, source:raw]
    // ASSIGNMENT: result = &this[8 * a2], the base of the indexed element. [source:raw]
    // CALCULATION: Write result[47] = v6 * a4 (selected gain multiplied by a4). [source:raw]
    // ASSIGNMENT: Write this[8 * a2 + 48] = a5 (magnitude value). [source:raw]
    // ASSIGNMENT: Set byte at result + 180 to 1 (enable marker). [source:raw]
    // GUARD: If v5 >= 0, clamp v5 into [0, 3]: store v5 into result[46] when v5 <= 3, else store 3; then clear byte at result + 196. [source:raw]
    // ASSIGNMENT: If v5 < 0, write result[46] = 0.0 and clear byte at result + 196. [source:raw]
    // RETURN: Return result, the base of the configured indexed element. [function:0x004F87C0, source:raw]

    // Conservative worker pseudocode:
    //   float *HUDElementConfig(float *this, int a2, int a3, float a4, float a5) {
    //       int v5 = a3;
    //       double v6;
    //       if (*(int *)(*(int *)this + 0x32C8))
    //           v6 = flt_7CF35C;
    //       else {
    //           v6 = flt_7CF338;
    //           v5 = a3 + 1;
    //       }
    //       float *result = &this[8 * a2];
    //       result[47] = (float)(v6 * a4);
    //       this[8 * a2 + 48] = a5;
    //       *((char *)result + 180) = 1;
    //       if (v5 >= 0) {
    //           *(int *)(result + 46) = v5 <= 3 ? v5 : 3;
    //           *((char *)result + 196) = 0;
    //       } else {
    //           result[46] = 0.0f;
    //           *((char *)result + 196) = 0;
    //       }
    //       return result;
    //   }
    // UNRESOLVED: Element stride (8 floats per index a2) is inferred from the indexed writes; element structure layout beyond the written slots is not evidenced.
    // UNRESOLVED: Specific HUD semantics of the gain/magnitude/index fields are not established.
}
