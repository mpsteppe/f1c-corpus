// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051D247
// Canonical corpus name: GridOccupancyBoundingBoxScan
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GridOccupancyBoundingBoxScan_0051d247.c

void UnknownObject::GridOccupancyBoundingBoxScan()
{
    // Scans a 3D occupancy grid of 16-bit cells located via *(this+0x1A4)+0x18 to tighten an axis-aligned bounding box held in a2[0..5]. Shrinks minX/maxX, minY/maxY, minZ/maxZ inward until each face meets an occupied (non-zero) cell, writing the tightened bounds back into a2[0..5]. Computes a squared-magnitude descriptor into a2[6], counts all remaining occupied cells into v44, stores the count in a2[7], and returns it.
    // ASSIGNMENT: Load grid row-pointer array base v28 = *(DWORD*)(*(DWORD*)(a1+0x1A4) + 0x18); rows are indexed as v28 + 4*coord. [field:this:0x000001A4, field:*(this+0x1A4):0x00000018, source:raw]
    // ASSIGNMENT: Read initial bounding box extents from a2: a2[0]=minX, a2[1]=maxX, a2[2]=minY, a2[3]=maxY, a2[4]=minZ, a2[5]=maxZ into locals. [source:raw, function:0x0051D247]
    // GUARD: Only scan the X direction if minX (a2[0]) is less than maxX (a2[1]). [source:raw]
    // LOOP: Shrink minX: advance X while the whole row slab at that X is empty (all cells zero); when an occupied cell is found, write tightened minX back to *a2. [source:raw]
    // LOOP: Shrink maxX: step X down from maxX while its slab is empty; on first occupied cell write tightened maxX to a2[1]. [source:raw]
    // GUARD: Only scan the Y direction if minY (a2[2]) is less than maxY (a2[3]). [source:raw]
    // LOOP: Shrink minY: advance Y while the row at that Y is empty; write tightened minY to a2[2] on first occupied cell. [source:raw]
    // LOOP: Shrink maxY: step Y down from maxY while empty; write tightened maxY to a2[3] on first occupied cell. [source:raw]
    // GUARD: Only scan the Z direction if minZ (a2[4]) is less than maxZ (a2[5]). [source:raw]
    // LOOP: Shrink minZ: advance Z while the column at that Z is empty; write tightened minZ to a2[4] on first occupied cell. [source:raw]
    // LOOP: Shrink maxZ: step Z down from maxZ while empty; write tightened maxZ to a2[5] on first occupied cell. [source:raw]
    // CALCULATION: Compute a2[6] = 16*(maxX-minX)*16*(maxX-minX) + 12*(maxY-minY)*12*(maxY-minY) + 8*(maxZ-minZ)*8*(maxZ-minZ), a scaled squared-extent descriptor. [source:raw]
    // LOOP: Iterate every cell within the tightened bounding box; increment v44 for each non-zero 16-bit cell. [source:raw, function:0x0051D247]
    // ASSIGNMENT: Store the occupied-cell count into a2[7]. [source:raw]
    // RETURN: Return v44 (occupied-cell count) as the function result. [source:raw, function:0x0051D247]

    // Conservative worker pseudocode:
    //   rows = *(DWORD*)(*(DWORD*)(a1 + 0x1A4) + 0x18);
    //   minX=a2[0]; maxX=a2[1]; minY=a2[2]; maxY=a2[3]; minZ=a2[4]; maxZ=a2[5];
    //   shrink each of the six face bounds inward until the corresponding grid slab/row/column holds a non-zero 16-bit cell;
    //   write tightened bounds back to a2[0..5];
    //   a2[6] = 16*dx*16*dx + 12*dy*12*dy + 8*dz*8*dz;
    //   count non-zero cells in the tightened box into count;
    //   a2[7] = count; return count;
    // UNRESOLVED: Exact grid cell layout (cells per row = 32, byte stride per row = 64) is inferred from pointer arithmetic (2 * (z + 32*y)) and is not separately confirmed.
    // UNRESOLVED: Purpose and units of the a2[6] scaled squared-extent formula (16/12/8 coefficients) are unknown.
    // UNRESOLVED: Owner object type behind this+0x1A4 is unknown.
}
