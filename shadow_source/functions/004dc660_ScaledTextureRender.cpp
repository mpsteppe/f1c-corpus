// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC660
// Canonical corpus name: ScaledTextureRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScaledTextureRender_004dc660.c

void UnknownObject::ScaledTextureRender()
{
    // Renders a scaled texture: looks up a texture/string object by name via WideStringLinkedListSearch, temporarily scales its stored factors at +92 and +96 by the incoming scale parameters, computes an aligned screen position from the target object's alignment dimensions, renders through sub_553070 with the resolved device, then restores the original scale factors and color value.
    // GUARD: If the device pointer a9 is null, fall back to the stored render device global dword_8B8DC8. [global:0x008B8DC8]
    // GUARD: Skip the whole body unless both the texture name a1 and the target object a2 are non-null. [source:raw]
    // CALL: Look up the texture/string object by name a1 through WideStringLinkedListSearch; null result skips rendering. [callee:0x0053D1F0]
    // ASSIGNMENT: Capture the texture object's stored scale factors at +92 and +96 and the target's field at +72, and overwrite the scale factors with the incoming a7/a8 multipliers. [source:raw]
    // CALL: Invoke FieldSetterAt0x48 on a5, setting a field at offset 0x48 on the texture object. [callee:0x00552FC0]
    // CALL: Convert the scaled dimensions a3 and a4 to integers via CRTFtol, dividing by the just-scaled factors. [callee:0x00587BDC]
    // CALL: Retrieve base alignment dimensions from the target object a2 via sub_5531F0, clearing a8 and a7 first. [callee:0x005531F0]
    // CALL: Compute the aligned screen position from the integer dimensions and alignment flags via AlignmentPositionSwitch. [callee:0x004DC340]
    // CALL: Render the texture at the computed position through sub_553070 with the resolved device a9. [callee:0x00553070]
    // ASSIGNMENT: Restore the texture object's original field at +72 and original scale factors at +92 and +96. [source:raw]
    // RETURN: Return the device pointer (original a9 or the fallback dword_8B8DC8) on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   int ScaledTextureRender(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7, int a8, int a9) {
    //     if (!a9) a9 = dword_8B8DC8;
    //     if (!a1 || !a2) return a9;
    //     void *tex = WideStringLinkedListSearch(a1);
    //     if (!tex) return a9;
    //     float sx = *(float *)(tex + 92), sy = *(float *)(tex + 96);
    //     int saved72 = *(int *)(tex + 72);
    //     *(float *)(tex + 92) = *(float *)&a7 * sx;
    //     *(float *)(tex + 96) = *(float *)&a8 * *(float *)(tex + 96);
    //     FieldSetterAt0x48(a5);
    //     a3 = CRTFtol((double)a3 / *(float *)(tex + 92));
    //     a4 = CRTFtol((double)a4 / *(float *)(tex + 96));
    //     *(float *)&a8 = 0.0; *(float *)&a7 = 0.0;
    //     sub_5531F0(a2, &a8, &a7, 0);
    //     AlignmentPositionSwitch(a3, a4, a8, a7, a6, &a3, &a4);
    //     sub_553070(a2, a3, a4, a9);
    //     *(int *)(tex + 72) = saved72;
    //     *(float *)(tex + 92) = sx;
    //     *(float *)(tex + 96) = sy;
    //     return a9;
    //   }
    // UNRESOLVED: The packet's fact table lists a read of dword_8AFE64, but the raw decompiled source does not reference it; its role in this function is unknown.
    // UNRESOLVED: Exact semantics of the restored field at +72 (called a color value in prior analysis) are not proven from this packet alone.
    // UNRESOLVED: Ownership of this function is unconfirmed; the packet owner is UnknownObject.
}
