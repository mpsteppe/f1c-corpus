// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00410BC0
// Canonical corpus name: WheelControllerInputDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelControllerInputDecoder_00410bc0.c

void UnknownObject::WheelControllerInputDecoder()
{
    // Decodes a packed 36-byte wheel input record a2 into 13 scaled float values v37, extracts a 6-bit type field from the first dword, then dispatches on it (jump table jpt_410D15) to one of six wheel groups. Each group validates the wheel index from a2+8 against a per-group count field and resolves the per-wheel slot via the group's base pointer; groups 3-5 additionally handle sentinel (-1) slots by looking up a repair-state owner in a 4656-stride global array (dword_5ECF0C / dword_5ED3AC / dword_5ED3F0 / dword_5ED434), initializing the slot via ShortComputation_e770 and RepairServiceStateDispatcher, then converting the slot's physics state from v37 via PhysicsStateVectorConversion. Called once from sub_4B3400.
    // CALCULATION: Decode the packed type field from the first dword of the record: result = ((*(int*)a2 >> 18) & 0x3F) - 1, giving a 6-bit group selector in the range -1..5. [source:raw]
    // CALCULATION: Unpack and scale the input record into v37[13]: v37[0] = *(float*)(a2+4); a packed word from a2+10/12/14 scaled by 0.000030517578 (flt_59E774 region) into v37[1..3]; words from a2+19/21/23 scaled by 0.00048828125 (flt_59E778 region) into v37[4..6]; words from a2+25/27/29 scaled by 0.015625 (flt_59E77C region) into v37[7..9]; and words from a2+31/33/35 scaled by 0.0078125 (flt_59E780 region) into v37[10..12]. [global:0x0059E774, global:0x0059E778, global:0x0059E77C, global:0x0059E780, source:raw]
    // GUARD: Switch on the decoded type field using the jump table jpt_410D15 (0x00410F44) with six dispatch cases; an out-of-range/default case returns the raw decoded value immediately. [global:0x00410F44, source:raw]
    // GUARD: Group 0 (case 0): require wheel index v15 = *(short*)(a2+8) in [0, count at this+0x24), then resolve the slot via base pointer this+0x28. [field:this:0x00000024, field:this:0x00000028, source:raw]
    // GUARD: Group 1 (case 1): require v15 in [0, count at this+0x30), slot resolved via base pointer this+0x34. [field:this:0x00000030, field:this:0x00000034, source:raw]
    // GUARD: Group 2 (case 2): require v15 in [0, count at this+0x3C), slot resolved via base pointer this+0x40. [field:this:0x0000003C, field:this:0x00000040, source:raw]
    // GUARD: Group 3 (case 3): require v15 in [0, count at this+0x48); if v15 < 416, compute subgroup v30 = v15 & 3 and slot address this+0x4C + 36*v15; if the slot sentinel equals -1, look up a repair-state owner in dword_5ECF0C[4656*(v15/4) + 74*v30] and, when non-zero, initialize the slot via ShortComputation_e770, then dispatch repair state RepairServiceStateDispatcher(v30). [field:this:0x00000048, field:this:0x0000004C, global:0x005ECF0C, callee:0x0040E770, callee:0x004ED250, source:raw]
    // GUARD: Group 4 (case 4): require v15 in [0, count at this+0x54); if v15 >= 208 skip directly to conversion; otherwise compute v32 = v15/2 and parity v33 = v15 & 1, resolve slot this+0x58 + 36*v15, and on sentinel -1 read owner from dword_5ED3F0[4656*v32] when odd or dword_5ED3AC[4656*v32] when even, initializing via ShortComputation_e770 and RepairServiceStateDispatcher((v33!=0) + 4). [field:this:0x00000054, field:this:0x00000058, global:0x005ED3AC, global:0x005ED3F0, callee:0x0040E770, callee:0x004ED250, source:raw]
    // GUARD: Group 5 (case 5): require v15 in [0, count at this+0x60); if v15 >= 832 skip initialization; otherwise compute subgroup v35 = v15 & 7, slot this+0x64 + 36*v15, and on sentinel -1 read owner from dword_5ED434[4656*(v15/8) + 17*v35], initializing via ShortComputation_e770 and RepairServiceStateDispatcher(v35 + 6). [field:this:0x00000060, field:this:0x00000064, global:0x005ED434, callee:0x0040E770, callee:0x004ED250, source:raw]
    // CALL: For every group, after bounds/initialization the per-wheel slot's physics state is converted from the scaled v37 vector via PhysicsStateVectorConversion(slot, v37); groups 3-5 with v15 >= 416/208/832 route straight to this conversion without repair-state handling. [callee:0x0040EF70, source:raw]
    // RETURN: Return the decoded type field value; invalid index or default case returns it without conversion, otherwise the converted call result path returns the same decoded value. [source:raw]
    // CALL: Single call site from sub_4B3400, consistent with a wheel input record dispatch reached from the wider input/controller update path. [caller:0x004B3400]

    // Conservative worker pseudocode:
    //   int sub_410BC0(void *this, const char *rec) {
    //     float v37[13];
    //     int type = ((*(int*)rec >> 18) & 0x3F) - 1;
    //     v37[0] = *(float*)(rec+4);
    //     v37[1..3] = pack(rec+10, rec+12, rec+14) * 0.000030517578f;
    //     v37[4..6] = pack(rec+19, rec+21, rec+23) * 0.00048828125f;
    //     v37[7..9] = pack(rec+25, rec+27, rec+29) * 0.015625f;
    //     v37[10..12] = pack(rec+31, rec+33, rec+35) * 0.0078125f;
    //     int w = *(short*)(rec+8);
    //     int *slot, n, base;
    //     switch (type) {
    //       case 0: n=this[0x24/4]; base=this[0x28/4]; break;
    //       case 1: n=this[0x30/4]; base=this[0x34/4]; break;
    //       case 2: n=this[0x3C/4]; base=this[0x40/4]; break;
    //       case 3: n=this[0x48/4]; base=this[0x4C/4]; repairGroup(w); break;
    //       case 4: n=this[0x54/4]; base=this[0x58/4]; repairGroup(w); break;
    //       case 5: n=this[0x60/4]; base=this[0x64/4]; repairGroup(w); break;
    //       default: return type;
    //     }
    //     if (w < 0 || w >= n) return type;
    //     return PhysicsStateVectorConversion((int*)(base + 36*w), v37);
    //   }
    // UNRESOLVED: unk_5EC6E4 is a read reference near the vehicle-array base region but does not appear literally in the decompiled body; its precise role is not established in this scope.
    // UNRESOLVED: The float scale constants flt_59E774/flt_59E778/flt_59E77C/flt_59E780 are referenced by the packet but rendered as inlined literals in the raw source; exact correspondence is inferred from the packed-word decode layout.
    // UNRESOLVED: Slot stride 36 and the per-group 36*v15 indexing are assumed uniform across all six groups from the observed cases.
    // UNRESOLVED: Repair-state owner arrays use stride 4656 (0x1230); the meaning of the 74*v30 / 17*v35 sub-indexing is not decoded here.
}
