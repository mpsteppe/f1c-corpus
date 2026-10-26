// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556D60
// Canonical corpus name: sub_556D60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_556D60_00556d60.c

void UnknownObject::RegisterNodeReferences()
{
    // Scene-graph reference registration. Guarded by a2[5] bit 0x2000000 being clear. Reads the record list head a2[71] and, while the record counter a2[70] is positive, walks records in 64-dword strides. For each record, dereferences the object pointer at record+4 and selects a per-type sub-array from the global manager at dword_8B8F28 (by the object flag bits 0x120: case 32 -> element index 116, case 256 -> 110, case 288 -> 114, else fallback element 112), then indexes into that sub-array by the type index at object+160 with stride 528. If the collection has free capacity (used 130 < capacity 129), appends a 16-byte entry at base 131 + 16*used holding {this, a2, record, object} and increments used. Clears flags at record+56 (0x200 unless a2[5] bit 0x1000000 is set; 0x100 unless a2[5] bit 0x20 is set). Completes by setting a2[5] |= 0x1000020.
    // GUARD: If (a2[5] & 0x2000000) == 0, proceed; otherwise the whole body is skipped. [source:raw]
    // GUARD: v3 = a2[71]; enter the walk only while (int)a2[70] > 0. [source:raw]
    // LOOP: Loop over records: v5 = *(v3 + 4); if ((*(v5 + 156) & 0x120) == 0) break out to the fallback selection. Each iteration advances v3 by 64 and increments v10 until v10 >= a2[70]. [source:raw]
    // STATE_TRANSITION: Select sub-array base by object type flags (*(v5 + 156) & 0x120): case 32 -> v7 = v4[116]; case 256 -> v7 = v4[110]; case 288 -> v7 = v4[114]; fallback when flag bit is clear -> v7 = v4[112], where v4 is the global manager object at dword_8B8F28. [global:0x008B8F28, source:raw]
    // CALCULATION: v6 = v7 + 528 * *(v5 + 160): index the per-type collection by the object's type index with 528-dword stride. [source:raw]
    // GUARD: If v6[130] < v6[129] (used below capacity), append a 16-byte entry: v9 = v6[131] + 16 * v6[130]; *v9 = this; v9[1] = a2; v9[2] = v3; v9[3] = *(v3 + 4); then ++v6[130]. [source:raw]
    // GUARD: If (a2[5] & 0x1000000) == 0, clear the 0x200 flag at *(v3 + 56). [source:raw]
    // GUARD: If (a2[5] & 0x20) == 0, clear the 0x100 flag at *(v3 + 56). [source:raw]
    // STATE_TRANSITION: On completion set a2[5] |= 0x1000020 to mark the registration done. [source:raw]
    // RETURN: Void function; no value returned. [function:0x00556D60, source:raw]
    // CALL: Called from SceneNodeStateUpdateWithTransform (0x005569F0) and sub_556B10 (0x00556B10) during scene-node state updates. [caller:0x005569F0, caller:0x00556B10]

    // Conservative worker pseudocode:
    //   void RegisterNodeReferences(void *this, _DWORD *a2, int a3) {
    //       if ((a2[5] & 0x2000000) != 0) return;
    //       v3 = a2[71];
    //       if ((int)a2[70] > 0) {
    //           v4 = (int*)dword_8B8F28;
    //           while (1) {
    //               v5 = *(v3 + 4);
    //               if ((*(v5 + 156) & 0x120) == 0) { v7 = v4[112]; }
    //               else switch (*(v5 + 156) & 0x120) {
    //                   case 32:  v7 = v4[116]; break;
    //                   case 256: v7 = v4[110]; break;
    //                   case 288: v7 = v4[114]; break;
    //               }
    //               v6 = v7 + 528 * *(v5 + 160);
    //               if (v6[130] < v6[129]) {
    //                   v9 = v6[131] + 16 * v6[130];
    //                   *v9 = this; v9[1] = a2; v9[2] = v3; v9[3] = *(v3 + 4);
    //                   ++v6[130];
    //               }
    //               if ((a2[5] & 0x1000000) == 0) *(v3 + 56) &= ~0x200;
    //               if ((a2[5] & 0x20) == 0)     *(v3 + 56) &= ~0x100;
    //               v3 += 64;
    //               if (++v10 >= a2[70]) break;
    //           }
    //       }
    //       a2[5] |= 0x1000020;
    //   }
    // UNRESOLVED: The identity and layout of the global manager at dword_8B8F28 (sub-array elements 110/112/114/116, stride 528) is not established by this packet.
    // UNRESOLVED: The meanings of the object type flags (0x120), the appended 16-byte entry {this, a2, record, object}, and the a2[5] bit flags (0x2000000, 0x1000000, 0x20, 0x1000020) are inferred from the flag arithmetic only.
    // UNRESOLVED: The unused parameter a3 appears in the prototype but is not referenced in the body.
}
