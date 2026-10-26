// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004366E0
// Canonical corpus name: BestFitPlaneFitting
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BestFitPlaneFitting_004366e0.c

void UnknownObject::BestFitPlaneFitting()
{
    // Fits a plane to a2 points at a1 (stride 28 bytes, doubles at offsets +0/+8/+16) by accumulating least-squares normal-equation sums and solving the resulting 3x4 augmented system via sub_5677B0; on a failed solve writes a normalized fallback plane. The canonical/ABI name (BestFitPlaneFitting / Best_Fit_Plane_Fitting) supports the plane-fit reading, but ownership and exact output layout (a3/a4 written via dword stores) are unresolved.
    // ASSIGNMENT: Zero the 12-element double accumulator array v21 and build the 3-element row-pointer array v20 pointing at v21, v21+4 and v21+8 to form a 3x4 augmented matrix. [source:raw, function:0x004366E0]
    // GUARD: Accumulate sums only when a2 > 0; otherwise skip straight to the solve. [source:raw, function:0x004366E0]
    // LOOP: Iterate a2 points at 28-byte stride (x at +0, y at +8, z at +16): v21[0] += x*x; v21[1] += z*x; v21[2] += x; v21[3] += y*x; v21[4] += z*x; v21[5] += z*z; v21[6] += z; v21[7] += z*y; v21[8] += x; v21[9] += z; v21[10] += 1.0; v21[11] += y. [source:raw, function:0x004366E0]
    // CALL: Solve the 3x4 augmented system by calling sub_5677B0(v20, 3); a nonzero return indicates a solved (non-degenerate) system. [source:raw, callee:0x005677B0, function:0x004366E0]
    // ASSIGNMENT: On successful solve, write six dwords to a3 (0, 0, 0, 1072693248, 0, 0 - interpretable as the double triple 0.0, 0.0, 1.0) and copy the double at a1+8 into a4. [source:raw, function:0x004366E0]
    // CALCULATION: On failed solve, compute a normalized fallback plane: v18 = 1/sqrt(v21[7]*v21[7] + v21[3]*v21[3] + 1.0); set a3[0] = -(v21[3]*v18), a3[1] = v18, a3[2] = -(v21[7]*v18) and a4[0] = v18 * v21[11]. [source:raw, function:0x004366E0]
    // RETURN: Return a4 as the result pointer. [source:raw, function:0x004366E0]

    // Conservative worker pseudocode:
    //   // Accumulate least-squares normal-equation terms over a2 points (stride 28).
    //   for (i = 0; i < a2; ++i) {
    //       x = *(double*)(a1 + 28*i + 0); y = *(double*)(a1 + 28*i + 8); z = *(double*)(a1 + 28*i + 16);
    //       v21[0]+=x*x; v21[1]+=z*x; v21[2]+=x; v21[3]+=y*x; v21[4]+=z*x; v21[5]+=z*z;
    //       v21[6]+=z; v21[7]+=z*y; v21[8]+=x; v21[9]+=z; v21[10]+=1.0; v21[11]+=y;
    //   }
    //   if (sub_5677B0(v20, 3)) {  // solved 3x4 system
    //       write_dwords(a3, 0,0,0,1072693248,0,0); a4 = *(double*)(a1+8);
    //   } else {
    //       v18 = 1/sqrt(v21[7]*v21[7] + v21[3]*v21[3] + 1.0);
    //       a3[0] = -(v21[3]*v18); a3[1] = v18; a3[2] = -(v21[7]*v18);
    //       a4[0] = v18 * v21[11];
    //   }
    //   return a4;
    // UNRESOLVED: Global dbl_59E420 is marked read but does not appear in the decompiled source; it may be folded into an x87 constant.
    // UNRESOLVED: Exact output layout of a3/a4 is ambiguous: a3 and a4 are declared long double* but written via dword stores.
    // UNRESOLVED: The plane-fit interpretation depends on the packet's canonical/ABI naming; no caller-side confirmation was examined.
}
