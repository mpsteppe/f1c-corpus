// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005053EC
// Canonical corpus name: MemoryAllocation_53ec
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocation_53ec_005053ec.c

void UnknownObject::InterpolationCoordinateTableAllocator()
{
    // Allocates a 16-byte-per-entry table via OperatorNewNhMallocWrapper(16 * a1) and fills each entry with adjacent source indices and two blend weights for bilinear interpolation. Fractional source coordinate v6 = v15 * (a2/a1) - 0.5 is passed through sub_5895A2; edge clamping/wrapping depends on flag a3. Used by sub_5054EC and VertexBufferAllocationAndStageTransformation.
    // CALL: Allocate the coordinate table with OperatorNewNhMallocWrapper(16 * a1) bytes (16 bytes per entry) [callee:0x00587C03, source:raw]
    // GUARD: If the allocation returns NULL, return NULL immediately without filling the table [source:raw]
    // ASSIGNMENT: Store stack value v5 (read from uninitialized slot v14) into workspace global dword_8B0098 [global:0x008B0098, source:raw]
    // LOOP: Iterate v15 from 0 while v15 < a1, producing one table entry per iteration [source:raw]
    // CALCULATION: Compute source-scale ratio v11 = (double)a2 / (double)a1 [source:raw]
    // CALCULATION: Compute fractional source coordinate v6 = v15 * v11 - 0.5 [source:raw]
    // CALL: Call sub_5895A2(v6) to compute the fractional interpolation value from the coordinate [callee:0x005895A2, source:raw]
    // GUARD: Edge handling: when first index v7 < 0, set v7 = a2 - 1 if a3 nonzero else 0 [source:raw]
    // GUARD: Edge handling: when second index v8 >= a2, set v8 = a2 - 1 if a3 zero else 0 [source:raw]
    // ASSIGNMENT: Store first adjacent source index v7 at the entry's int slot 0 and second adjacent source index v8 at the entry's int slot 2 [source:raw]
    // ASSIGNMENT: Store blend weight v9 = 1.0 - (v13 - v12) at the entry's float slot +4 and complementary weight 1.0 - v9 at the entry's float slot +12, then advance v4 by 4 ints to the next entry [source:raw]
    // RETURN: Return the filled table base pointer v10 to the caller [function:0x005053EC, source:raw]
    // CALL: Invoked by sub_5054EC (005054EC) and VertexBufferAllocationAndStageTransformation (005058D2) to build the interpolation coordinate table used during vertex stage transformation [caller:0x005054EC, caller:0x005058D2, source:raw]

    // Conservative worker pseudocode:
    //   result = OperatorNewNhMallocWrapper(16 * a1);
    //   if (!result) return result;
    //   v10 = result; v4 = result;
    //   dword_8B0098 = v5; /* v5 reads uninitialized stack slot v14 * /
    //   v15 = 0;
    //   for (; v15 < a1; ++v15) {
    //     v11 = (double)a2 / (double)a1;
    //     v6 = v15 * v11 - 0.5;
    //     sub_5895A2(v6);
    //     v7 = (int)v6 + 1;
    //     if (v7 < 0) v7 = a3 ? a2 - 1 : 0;
    //     if (v8 >= a2) v8 = a3 == 0 ? a2 - 1 : 0;
    //     *v4 = v7;
    //     v4[2] = v8;
    //     v9 = 1.0 - (v6 - v12);
    //     *((float *)v4 + 1) = v9;
    //     *((float *)v4 + 3) = 1.0 - v9;
    //     v4 += 4;
    //   }
    //   return v10;
    // UNRESOLVED: Packet facts flag three read-only float globals (flt_59E43C, flt_59E450, flt_5ADB14) but none appear in the raw decompiled source; per prior analysis they are consumed inside sub_5895A2, not verifiable here
    // UNRESOLVED: The store dword_8B0098 = v5 copies an uninitialized stack slot (v14 alias); likely a decompiler artifact of a workspace reuse for sub_5895A2, exact intent unknown
    // UNRESOLVED: The declared_name 'if' in the packet is a decompiler leftover, not a meaningful identifier
}
