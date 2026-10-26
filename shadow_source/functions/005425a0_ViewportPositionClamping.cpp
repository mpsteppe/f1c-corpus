// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005425A0
// Canonical corpus name: ViewportPositionClamping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ViewportPositionClamping_005425a0.c

void UnknownObject::ViewportPositionClamping()
{
    // Projects the 3D point a2 to screen space via an indirect call through slot +4 of the object behind global 0x008B8F24, passing a 3-float result buffer and this+0x15C as the fourth argument. Divides by the perspective w component (v9[2]), truncates the two screen axes to integers with CRTFtol into a3[0..1], then clamps each axis to the viewport bounds: X in [this[26], this[26]+this[21]], Y in [this[25], this[25]+this[22]]. Returns the clamped Y value.
    // CALL: Indirect __cdecl call through slot +4 of the object behind global 0x008B8F24, passing (0x008B8F24, a2, v9, this + 0x15C); transforms the 3D point a2 into a 3-float screen-space result v9. [global:0x008B8F24, source:raw]
    // CALCULATION: v4 = 1.0 / v9[2]; perspective divide by the w component of the transformed coordinate. [source:raw]
    // CALL: *a3 = CRTFtol(v4); truncate the projected coordinate to an integer screen X pixel. [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: a3[1] = CRTFtol(v4); truncate the projected coordinate to an integer screen Y pixel. [callee:0x00587BDC, source:raw]
    // GUARD: X minimum clamp: if *a3 <= this[26] (offset 0x68) then *a3 = this[26]. [field:this:0x00000068, source:raw]
    // GUARD: X maximum clamp: if *a3 >= this[26] + this[21] (0x68 + 0x54) then *a3 = that sum. [field:this:0x00000068, field:this:0x00000054, source:raw]
    // GUARD: Y minimum clamp: if a3[1] <= this[25] (offset 0x64) then a3[1] = this[25]. [field:this:0x00000064, source:raw]
    // GUARD: Y maximum clamp: if a3[1] >= this[25] + this[22] (0x64 + 0x58) then a3[1] = that sum. [field:this:0x00000064, field:this:0x00000058, source:raw]
    // RETURN: Return the clamped Y value (a3[1]) as the integer result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5425A0(DWORD *this, int a2, int *a3) {
    //     float v9[3];
    //     (*(void (__cdecl **)(int, int, float *, DWORD *))(*(DWORD *)dword_8B8F24 + 4))(dword_8B8F24, a2, v9, this + 87);
    //     double v4 = 1.0 / v9[2];
    //     *a3 = CRTFtol(v4);
    //     a3[1] = CRTFtol(v4);
    //     if (*a3 <= this[26]) *a3 = this[26];
    //     if (*a3 >= this[26] + this[21]) *a3 = this[26] + this[21];
    //     if (a3[1] <= this[25]) a3[1] = this[25];
    //     if (a3[1] >= this[25] + this[22]) a3[1] = this[25] + this[22];
    //     return a3[1];
    //   }
    // UNRESOLVED: Global 0x0059E43C (flt_59E43C) is listed as a read global but does not appear in the raw source text; it cannot be tied to an operation here.
    // UNRESOLVED: Identity and implementation of the indirect call target behind global 0x008B8F24 slot +4 are unresolved (D3D transform wrapper).
    // UNRESOLVED: The sub-object at this + 0x15C (this[87]) passed to the transform is unnamed.
    // UNRESOLVED: Interpreting this[21]/this[22] (0x54/0x58) as viewport extents added to minima this[25]/this[26] (0x64/0x68) is derived from the clamp shape, not confirmed.
}
