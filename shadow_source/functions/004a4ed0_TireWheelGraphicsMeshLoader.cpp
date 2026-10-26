// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A4ED0
// Canonical corpus name: TireWheelGraphicsMeshLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireWheelGraphicsMeshLoader_004a4ed0.c

void UnknownObject::TireWheelGraphicsMeshLoader()
{
    // Loads tire/wheel graphics mesh references (.MTS files) for a wheel position selected by matching argument a4 against the LF/RF/LR/RR tire-name strings. Initializes a 384-byte conditional-dispatch parse session, then loops reading tokens: recursively loads nested instance meshes, extracts the meshfile path, reads lodin/lodout LOD distance bounds and applies the caller's detail level a6 as a range gate, and handles the shadowobject token. On acceptance it allocates a 72-byte mesh record, copies the meshfile path (appending .MTS when absent), stores a shadow/normal flag at offset 64, and links the record into the per-wheel-position singly linked list rooted at a5 + 4*wheelIndex. Also called by sub_4A51C0 (caller:0x004A51C0).
    // GUARD: Guard on sub_588410(a4, aLftire): if a4 matches the LF tire-name string, enter the nested wheel-index selection; otherwise assign v6 = 0. [callee:0x00588410, global:0x005C6754]
    // GUARD: Nested guard on sub_588410(a4, aRftire): if a4 matches the RF tire-name string, enter the next selection level; otherwise assign v6 = 1. [callee:0x00588410, global:0x005C675C]
    // GUARD: Nested guard on sub_588410(a4, aLrtire): if a4 matches the LR tire-name string, assign v6 = (sub_588410(a4, aRrtire) != 0) ? -1 : 3; otherwise assign v6 = 2. [callee:0x00588410, global:0x005C6764, global:0x005C676C]
    // ASSIGNMENT: v7 = a3: a3 is retained in v7, forwarded to the recursive nested-instance mesh load, and re-seeded at every outer-loop re-dispatch. [source:raw]
    // CALL: Zero the 384-byte dispatch section buffer v24 with memset(v24, 0, sizeof(v24)). [source:raw]
    // ASSIGNMENT: Initialize local dispatch state: v19 = 0, v23 = 0, v21 = 0, v22 = 0, v20 = 1. [source:raw]
    // CALL: Open/begin the conditional dispatch parse session: result = ConditionalDispatchBasedOnFlag(v24, 384). [callee:0x00566CC0]
    // GUARD: If the initial dispatch returns nonzero, enter the token-processing loop; otherwise fall through to the final return. [callee:0x00566CC0]
    // LOOP: Token-processing loop over the dispatch session: read one token per iteration, recurse on instance entries, and collect tire mesh records while the dispatch remains active. [callee:0x005651B0, callee:0x00566CC0, callee:0x00565520]
    // CALL: sub_5651B0(v18) advances/reads the next token into the 384-byte buffer v18. [callee:0x005651B0]
    // GUARD: If sub_5651B0 returns nonzero, skip the rest of the iteration (goto LABEL_24, the re-dispatch point). [callee:0x005651B0]
    // GUARD: If strcmp(v24, asc_5CC4F4) == 0 (dispatch section name equals the UI compare token), return result and terminate the parse. [global:0x005CC4F4]
    // RETURN: Return result when the section name equals asc_5CC4F4. [global:0x005CC4F4, source:raw]
    // GUARD: If sub_565520(aInstance, v17, 0) succeeds (instance token present), the parsed value lands in v17 and the function recurses for the nested instance. [callee:0x00565520, global:0x005CD620]
    // CALL: Recursive call TireWheelGraphicsMeshLoader(v7, v17, a5, LODWORD(a6)) loads the nested instance's tire/wheel mesh with the caller's detail level a6. [callee:0x004A4ED0]
    // GUARD: If v6 == -1 (no recognized tire position), skip mesh collection for this iteration (goto LABEL_24). [source:raw]
    // GUARD: If sub_565520(aMeshfile, v16, 0) fails (no meshfile token), continue the loop (goto LABEL_24); otherwise v16 holds the meshfile path. [callee:0x00565520, global:0x005CD614]
    // ASSIGNMENT: Initialize LOD defaults before parsing: v12[0] = -1.0 and v11 = -1.0. [source:raw]
    // CALL: sub_565870(aLodin, v12, 0, 0, 0, 0, 0, 0, 0) parses the lodin token into v12[0]. [callee:0x00565870, global:0x005CD60C]
    // CALL: sub_565870(aLodout, &v11, 0, 0, 0, 0, 0, 0, 0) parses the lodout token into v11. [callee:0x00565870, global:0x005CD604]
    // GUARD: LOD range check: if a6 < v12[0] or a6 >= v11, skip this mesh entry (goto LABEL_24); the entry only applies when the caller's detail level a6 is inside [lodin, lodout). [source:raw]
    // ASSIGNMENT: Seed the 61-byte buffer v13 from byte_5EA438[0], zero the remainder (memset v13+1 for 0x3C bytes), and set v14 = 0, v15 = 0. [global:0x005EA438, source:raw]
    // GUARD: If sub_565520(aShadowobject, v13, 0) fails (no shadowobject token) or sub_588410(v13, aTrue) matches, break out of the loop to the allocation path. [callee:0x00565520, global:0x005CD5F4, callee:0x00588410, global:0x005C596C]
    // ASSIGNMENT: v9 = 1 marks the record as a normal (non-shadow) mesh before the allocation path. [source:raw]
    // GUARD: If detail level dword_7CF884 >= 2, jump directly to the allocation path (load the mesh regardless). [global:0x007CF884]
    // ASSIGNMENT: Break path: v9 = 0 marks the record as a shadow mesh before allocation. [source:raw]
    // CALL: Allocate a 72-byte mesh info record: v10 = OperatorNewNhMallocWrapper(72). [callee:0x00587C03]
    // ASSIGNMENT: Copy the meshfile path v16 into the new record v10 (strcpy). [source:raw]
    // CALL: sub_566810(v10, aMts) checks whether the record's path already carries the .MTS suffix. [callee:0x00566810, global:0x005CD5EC]
    // ASSIGNMENT: If the suffix test fails, append ".MTS" to the record path (strcat). [global:0x005CD5EC, source:raw]
    // ASSIGNMENT: Store the mesh flag: byte at v10 + 64 = v9 (shadow vs normal marker). [source:raw]
    // ASSIGNMENT: Link the record into the per-wheel-position list: *(DWORD*)(v10 + 68) = *(DWORD*)(a5 + 4*v6) (previous head), then *(DWORD*)(a5 + 4*v6) = v10 (new head). [source:raw]
    // STATE_TRANSITION: Outer-loop re-dispatch (LABEL_24): v7 = a3, then result = ConditionalDispatchBasedOnFlag(v24, 384); if result is zero, return result (session end). [callee:0x00566CC0]
    // RETURN: Return result when the conditional dispatch reports the session end, or on fall-through after the initial dispatch returns zero. [callee:0x00566CC0]

    // Conservative worker pseudocode:
    //   int TireWheelGraphicsMeshLoader(int a1, int a2, int a3, int a4, int a5, float a6) {
    //       int v6, v7, result, v9, v10;
    //       float v11; float v12[2];
    //       CHAR v13[61]; __int16 v14; char v15;
    //       char v16[64]; CHAR v17[64]; _BYTE v18[384];
    //       int v19, v21, v22, v23; char v20; char v24[384];
    //   
    //       if (sub_588410(a4, aLftire))
    //           if (sub_588410(a4, aRftire))
    //               if (sub_588410(a4, aLrtire))
    //                   v6 = sub_588410(a4, aRrtire) != 0 ? -1 : 3;
    //               else v6 = 2;
    //           else v6 = 1;
    //       else v6 = 0;
    //       v7 = a3;
    //       memset(v24, 0, sizeof(v24)); v19 = 0; v23 = 0; v21 = 0; v22 = 0; v20 = 1;
    //       result = ConditionalDispatchBasedOnFlag(v24, 384);
    //       if (result) {
    //           for (;;) {
    //               result = sub_5651B0(v18);
    //               if (result) goto re_dispatch;
    //               if (!strcmp(v24, asc_5CC4F4)) return result;
    //               if (sub_565520(aInstance, v17, 0))
    //                   TireWheelGraphicsMeshLoader(v7, v17, a5, LODWORD(a6));
    //               if (v6 == -1) goto re_dispatch;
    //               if (!sub_565520(aMeshfile, v16, 0)) goto re_dispatch;
    //               v12[0] = -1.0; v11 = -1.0;
    //               sub_565870(aLodin, v12, 0,0,0,0,0,0,0);
    //               sub_565870(aLodout, &v11, 0,0,0,0,0,0,0);
    //               if (a6 < (double)v12[0] || a6 >= (double)v11) goto re_dispatch;
    //               v13[0] = byte_5EA438[0]; memset(&v13[1], 0, 0x3C); v14 = 0; v15 = 0;
    //               if (!sub_565520(aShadowobject, v13, 0) || sub_588410(v13, aTrue)) break;
    //               v9 = 1;
    //               if (dword_7CF884 >= 2) goto alloc;
    //           re_dispatch:
    //               v7 = a3;
    //               result = ConditionalDispatchBasedOnFlag(v24, 384);
    //               if (!result) return result;
    //           }
    //           v9 = 0;
    //       alloc:
    //           v10 = OperatorNewNhMallocWrapper(72);
    //           if (v10) {
    //               strcpy((char*)v10, v16);
    //               if (!sub_566810(v10, aMts)) strcat((char*)v10, ".MTS");
    //               *(_BYTE*)(v10 + 64) = v9;
    //               *(_DWORD*)(v10 + 68) = *(_DWORD*)(a5 + 4*v6);
    //               *(_DWORD*)(a5 + 4*v6) = v10;
    //           }
    //           goto re_dispatch;
    //       }
    //       return result;
    //   }
    // UNRESOLVED: sub_588410(a4, name) match semantics unverified (nonzero-on-match vs strcmp-style zero-on-match). The nested tire-name guards assign v6 from {-1,0,1,2,3}; under a strcmp-style reading the mapping is LF/RF/LR/RR to 0/1/2/3 with -1 sentinel, but the reachable single-match path of the literal code only yields lftire->1 / else->0.
    // UNRESOLVED: byte_5CD5F0 (0x005CD5F0) appears in the packet global list but is not referenced anywhere in the raw function text; its role here is unknown.
    // UNRESOLVED: v9 flag semantics at record offset 64 (shadow vs normal) and the break condition (shadowobject token absent OR parsed value equals aTrue) are ambiguous; the dword_7CF884 >= 2 detail-level gate also forces the allocation path.
    // UNRESOLVED: The strcmp guard compares the pre-parse v24 buffer against asc_5CC4F4; the exact section/dispatch semantics of ConditionalDispatchBasedOnFlag are unverified.
    // UNRESOLVED: Caller sub_4A51C0 (caller:0x004A51C0) calls this function, but the caller-side context that determines a4/a5/a6 is not established from this packet.
}
