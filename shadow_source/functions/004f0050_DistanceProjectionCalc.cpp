// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F0050
// Canonical corpus name: DistanceProjectionCalc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DistanceProjectionCalc_004f0050.c

void UnknownObject::DistanceProjectionCalc()
{
    // Computes a projected signed distance by fetching a position-monitor struct via PositionChangeMonitor, differencing two position pointers to form a direction vector, and projecting the vehicle's position offsets (this+0x34D4/0x34D8/0x34DC) against the monitor origin along the normalized direction, added to a stored distance. Returns the stored distance directly when the direction vector is zero, and clamps the result with flt_5EA3FC[0] (floor at 0.0 / ceiling at the threshold).
    // CALL: v2 = PositionChangeMonitor(this) returns the position-monitor struct [callee:0x004E9630, source:raw]
    // CALCULATION: load two position pointers from the monitor (p1 = *(v2+272), p0 = *(v2+268)) and form the direction vector v8 = p1[0]-p0[0], v9 = p1[1]-p0[1], v10 = p1[2]-p0[2] [source:raw]
    // GUARD: if v8 == 0.0 and v9 == 0.0 and v10 == 0.0 (zero direction), return the stored distance *(float*)(v2+72) directly [source:raw]
    // CALCULATION: normalize the direction: v6 = 1/sqrt(v10*v10 + v9*v9 + v8*v8); v11 = v8*v6; v12 = v9*v6 [source:raw]
    // CALCULATION: v7 = projected distance = dot(normalized direction, vehicle offset - monitor origin) + stored distance: v6*v10*(this+0x34DC - *(float*)(v2+8)) + v12*(this+0x34D8 - *(float*)(v2+4)) + v11*(this+0x34D4 - *(float*)(v2+0)) + *(float*)(v2+72) [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // CALCULATION: clamp v7 against flt_5EA3FC[0]: if negative, v7 += flt_5EA3FC[0] and return 0.0 if still negative; if greater than the threshold, v7 -= flt_5EA3FC[0] and return the threshold if still above it [global:0x005EA3FC, source:raw]
    // RETURN: return the clamped projected distance [source:raw]

    // Conservative worker pseudocode:
    //   mon = PositionChangeMonitor(this);
    //   p1 = *(float**)(mon+272); p0 = *(float**)(mon+268);
    //   dx = p1[0]-p0[0]; dy = p1[1]-p0[1]; dz = p1[2]-p0[2];
    //   if (dx == 0.0 && dy == 0.0 && dz == 0.0) return *(float*)(mon+72);
    //   inv = 1/sqrt(dx*dx + dy*dy + dz*dz);
    //   proj = inv*dz*(this+0x34DC - *(float*)(mon+8))
    //        + inv*dy*(this+0x34D8 - *(float*)(mon+4))
    //        + inv*dx*(this+0x34D4 - *(float*)(mon+0))
    //        + *(float*)(mon+72);
    //   if (proj < 0.0) { proj += flt_5EA3FC[0]; if (proj < 0.0) return 0.0; }
    //   else if (proj > flt_5EA3FC[0]) { proj -= flt_5EA3FC[0]; if (proj > flt_5EA3FC[0]) return flt_5EA3FC[0]; }
    //   return proj;
    // UNRESOLVED: Globals flt_59E43C and flt_59E440 are listed in the packet globals but do not appear in the raw source body; their role in this function is unconfirmed (possible extraction/analysis mismatch).
    // UNRESOLVED: Semantic labels (TrackRefSpeed for flt_5EA3FC, position-monitor offsets, stored distance) are DERIVED from existing_analysis prose; the raw source shows only the arithmetic.
}
