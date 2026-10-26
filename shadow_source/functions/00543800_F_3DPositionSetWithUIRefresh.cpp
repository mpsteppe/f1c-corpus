// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543800
// Canonical corpus name: F_3DPositionSetWithUIRefresh
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DPositionSetWithUIRefresh_00543800.c

void UnknownObject::F_3DPositionSetWithUIRefresh()
{
    // Converts the three integer components a2/a3/a4 (0-255 range) to normalized floats by multiplying by 0.0039215689 (1/255) and stores them at this[95..97] (offsets 0x17C, 0x180, 0x184). Dispatches a color update through VTableDispatchWithFieldCheck on the object behind global 0x008B78A0 with a packed value a4 + ((a3 + (a2 << 8)) << 8), then ORs the 0x800 refresh flag into offset +236 of the UI root context behind global 0x008B8F28. Returns that UI root pointer.
    // ASSIGNMENT: this[95] (offset 0x17C) = a2 * 0.0039215689 (1/255); normalize the X/red byte component to a float. [field:this:0x0000017C, global:0x0059E460, source:raw]
    // ASSIGNMENT: this[96] (offset 0x180) = a3 * 0.0039215689; normalize the Y/green byte component to a float. [field:this:0x00000180, global:0x0059E460, source:raw]
    // ASSIGNMENT: this[97] (offset 0x184) = a4 * 0.0039215689; normalize the Z/blue byte component to a float. [field:this:0x00000184, global:0x0059E460, source:raw]
    // CALL: VTableDispatchWithFieldCheck((_DWORD **)dword_8B78A0, a4 + ((a3 + (a2 << 8)) << 8)); dispatch a combined color update on the object behind global 0x008B78A0. [callee:0x00541670, global:0x008B78A0, source:raw]
    // STATE_TRANSITION: result = dword_8B8F28; OR 0x800 into the dword at offset +236 (0xEC) of the UI root context behind global 0x008B8F28 to flag a UI refresh. [global:0x008B8F28, source:raw]
    // RETURN: Return the UI root context pointer (global 0x008B8F28) as the function result. [global:0x008B8F28, source:raw]

    // Conservative worker pseudocode:
    //   int sub_543800(float *this, int a2, int a3, int a4) {
    //     this[95] = (double)a2 * 0.0039215689;
    //     this[96] = (double)a3 * 0.0039215689;
    //     this[97] = (double)a4 * 0.0039215689;
    //     VTableDispatchWithFieldCheck((_DWORD **)dword_8B78A0, a4 + ((a3 + (a2 << 8)) << 8));
    //     int result = dword_8B8F28;
    //     *(_DWORD *)(dword_8B8F28 + 236) |= 0x800;
    //     return result;
    //   }
    // UNRESOLVED: The object behind global 0x008B78A0 and the vtable method invoked by VTableDispatchWithFieldCheck are unknown.
    // UNRESOLVED: The UI root object behind global 0x008B8F28 and the meaning of the 0x800 flag bit at offset +236 are not resolved here.
    // UNRESOLVED: Interpreting a2/a3/a4 as color (R/G/B) components rather than 3D position (X/Y/Z) components is derived from the 1/255 normalization and the existing analysis; the owning object type is unknown.
}
