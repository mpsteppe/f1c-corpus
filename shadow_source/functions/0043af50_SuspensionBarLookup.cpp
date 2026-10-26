// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043AF50
// Canonical corpus name: SuspensionBarLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionBarLookup_0043af50.c

void UnknownObject::SuspensionBarLookup()
{
    // Suspension anti-roll-bar lookup by name. Searches a struct array by string via LinearSearchInStructArrayByString(a1); on a hit, selects one of two 3-double rows from the entry (v3[2] or v3[4] depending on whether v3[1] equals a2), forms dot-product components of a rotation from those rows and a2's coordinate offsets, and writes the transformed position into the six-double output a3. On a miss, zeroes a3 and, when dword_7C569C != 5 and StringSplitLoop(1, aDDevF119992002, 2726) returns nonzero, logs aDebugLogWrite-style error via DebugLogWrite(&dword_8AD25C, aCouldNotFindSu). Called from SteeringGeometryComputation (0x0043B590).
    // CALL: Call LinearSearchInStructArrayByString(a1); the returned pointer v3 selects the matching struct-array entry. [callee:0x0056EB30, source:raw]
    // GUARD: Branch on whether the search returned a null entry (not found) versus a hit. [callee:0x0056EB30, source:raw]
    // CALCULATION: Select the rotation row v5 = (v3[1] == a2) ? v3[2] : v3[4], then compute v6 = a2+44 * v5[2] + a2+36 * v5[1] + a2+28 * v5[0], v7 = a2+52 * v5[0] + a2+68 * v5[2] + a2+60 * v5[1], v8 = a2+76 * v5[0] + a2+92 * v5[2], v9 = a2+84 * v5[1]. [source:raw]
    // ASSIGNMENT: Write the transformed position into a3: a3[0] = v6 + a2+4, a3[8] = v7 + a2+12, a3[16] = v8 + v9 + a2+20. [source:raw]
    // GUARD: On the not-found path, gate the debug log on dword_7C569C != 5 and on StringSplitLoop(1, aDDevF119992002, 2726) returning nonzero. [global:0x007C569C, global:0x005C421C, callee:0x004D7A50, source:raw]
    // CALL: When the guards pass, call DebugLogWrite with the debug message buffer dword_8AD25C and the aCouldNotFindSu error string. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C4248, source:raw]
    // ASSIGNMENT: On the not-found path, zero all six dwords of the output a3 (a3+0x0 through a3+0x14). [source:raw]
    // RETURN: Return a3 (the output pointer) on both paths. [source:raw]

    // Conservative worker pseudocode:
    //   int SuspensionBarLookup(int a1, int a2, int a3) {
    //       _DWORD* v3 = LinearSearchInStructArrayByString(a1);
    //       if (v3) {
    //           double* v5 = (v3[1] == a2) ? (double*)v3[2] : (double*)v3[4];
    //           double v6 = *(double*)(a2+44) * v5[2] + *(double*)(a2+36) * v5[1] + *v5 * *(double*)(a2+28);
    //           double v7 = *(double*)(a2+52) * *v5 + *(double*)(a2+68) * v5[2] + *(double*)(a2+60) * v5[1];
    //           double v8 = *(double*)(a2+76) * *v5 + *(double*)(a2+92) * v5[2];
    //           double v9 = *(double*)(a2+84) * v5[1];
    //           *(double*)a3       = v6 + *(double*)(a2+4);
    //           *(double*)(a3+8)   = v7 + *(double*)(a2+12);
    //           *(double*)(a3+16)  = v8 + v9 + *(double*)(a2+20);
    //       } else {
    //           if (dword_7C569C != 5) {
    //               if (StringSplitLoop(1, aDDevF119992002, 2726))
    //                   DebugLogWrite(&dword_8AD25C, aCouldNotFindSu);
    //           }
    //           for (i in 0..5) *(_DWORD*)(a3 + i*4) = 0;
    //       }
    //       return a3;
    //   }
    // UNRESOLVED: The layout of the searched struct-array entry (v3[0..4]) beyond row selection is not evidenced in the packet.
    // UNRESOLVED: The meaning of the raw a2+offset doubles (28..92) as position/rotation-matrix inputs is inferred from the arithmetic and existing analysis.
    // UNRESOLVED: Owner is unknown; the raw source is a free __stdcall function with no this pointer and no owning class evidenced.
}
