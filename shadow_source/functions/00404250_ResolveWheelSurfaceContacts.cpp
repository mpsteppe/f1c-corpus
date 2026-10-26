// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404250
// Canonical corpus name: SurfaceHeightfieldCollisionCallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SurfaceHeightfieldCollisionCallback_00404250.c

void UnknownObject::ResolveWheelSurfaceContacts()
{
    // Per-wheel surface collision pass over the wheel array at this+0x134 (count at this+0x130, 316-byte stride). Computes a grip scale 1.0 - (flt_8AFEE8 + flt_8AFEEC)*0.5 stored at this+0x170 and, per wheel, drives sub_4FB260 (scale) and sub_4FAF60 (wheel base) callbacks. Invokes CountedLoopCallToElementUpdate, MemoryAllocation and ShortComputation_4790, then resets the phase flag this+0x174 to -1. For each wheel element, when element+300 >= this+0x10, runs SpatialNearestNeighborQueryWithPlaneTest (dword_5EA2C0) to find the hit surface, stores the hit pointer at element+276 and the contact offset at element+24, and propagates a per-surface value into element+296 from the hit chain (+268/+292 or +272/+288). A second query (flag 0) handles the element+300 == 1 case with a signed plane-distance bound test (+80/+84), clearing the contact (element+276 = 0, element+296 = -1) when out of bounds. Returns the loop counter.
    // ASSIGNMENT: Read the wheel count from this+0x130 and compute the grip scale 1.0 - (flt_8AFEE8 + flt_8AFEEC)*0.5, stored at this+0x170. [field:this:0x00000130, field:this:0x00000170, global:0x008AFEE8, global:0x008AFEEC, function:0x00404250, source:raw]
    // GUARD: guard:1 - if the wheel count at this+0x130 is > 0, enter the first per-wheel loop. [guard:1, field:this:0x00000130, function:0x00404250, source:raw]
    // LOOP: Loop count times, advancing the wheel offset by 316 per iteration, calling sub_4FB260 with the stored grip scale (this+0x170) on each pass. [field:this:0x00000130, field:this:0x00000170, callee:0x004FB260, function:0x00404250, source:raw]
    // GUARD: guard:1 - if the wheel count at this+0x130 is > 0, enter the second per-wheel loop. [guard:1, field:this:0x00000130, function:0x00404250, source:raw]
    // LOOP: Loop count times, calling sub_4FAF60 with the wheel base (this+0x134) plus the running offset advanced by 316 per iteration. [field:this:0x00000130, field:this:0x00000134, callee:0x004FAF60, function:0x00404250, source:raw]
    // CALL: CountedLoopCallToElementUpdate(this). [callee:0x004047D0, function:0x00404250, source:raw]
    // CALL: MemoryAllocation(this). [callee:0x004046B0, function:0x00404250, source:raw]
    // CALL: ShortComputation_4790(this), whose result seeds the returned counter. [callee:0x00404790, function:0x00404250, source:raw]
    // ASSIGNMENT: Reset the phase flag: this+0x174 = -1. [field:this:0x00000174, function:0x00404250, source:raw]
    // GUARD: guard:0 - if the wheel count at this+0x130 is <= 0, skip the spatial-resolution loop entirely. [guard:0, field:this:0x00000130, function:0x00404250, source:raw]
    // LOOP: Per-wheel loop over the 316-stride wheel array (base this+0x134): when the element's +300 field >= this+0x10, query the nearest neighbor with SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, element, 1); on a hit store the hit pointer at element+276, compute the contact height (hit+40/hit+32 dot product against element deltas) at element+24, and propagate the element+296 value from the hit chain (+268+292, or +272+288 when +268 is null). [field:this:0x00000134, field:this:0x00000010, callee:0x004038E0, global:0x005EA2C0, function:0x00404250, source:raw]
    // CALCULATION: Secondary plane test when the element's +300 field == 1 and element+276 is still null: query with SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, element, 0); compute the signed plane distance v21 from the hit's +40/+32 fields; depending on sign, compare |v21| against the hit's +84/+80 bounds - clearing the contact (element+276 = 0, element+296 = -1) when out of bounds, otherwise accepting the hit and copying element+296 from the hit chain. [field:this:0x00000134, callee:0x004038E0, global:0x005EA2C0, function:0x00404250, source:raw]
    // RETURN: Return the loop counter (v22 + 1). [function:0x00404250, source:raw]

    // Conservative worker pseudocode:
    //   count = this->wheelCount;               // this+0x130
    //   this->gripScale = 1.0f - (flt_8AFEE8 + flt_8AFEEC) * 0.5f;  // +0x170
    //   if (count > 0)
    //     for (off = 0; off < count; off++, v4 += 316) sub_4FB260(this->gripScale);
    //   if (count > 0)
    //     for (off = 0; off < count; off++, v6 += 316) sub_4FAF60(off + this->wheelBase);  // +0x134
    //   CountedLoopCallToElementUpdate(this);
    //   MemoryAllocation(this);
    //   result = ShortComputation_4790(this);
    //   this->phase = -1;                       // +0x174
    //   for (off = 0; off < count; off += 316) {
    //     elem = this->wheelBase + off;
    //     if (elem[+300] >= this->threshold) {   // this+0x10
    //       hit = SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, elem, 1);
    //       if (hit != 0) {
    //         elem[+276] = hit;
    //         elem[+24] = hit[+40]*(elem[+8]-hit[+8]) + hit[+32]*(elem[+0]-hit[+0]);
    //         if (hit[+268]) elem[+296] = hit[+268][+292];
    //         else if (hit[+272]) elem[+296] = hit[+272][+288];
    //       }
    //     }
    //     if (elem[+300] == 1 && elem[+276] == 0) {
    //       hit = SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, elem, 0);
    //       if (hit != 0) {
    //         v = hit[+40]*(elem[+8]-hit[+8]) + hit[+32]*(elem[+0]-hit[+0]);
    //         if (v >= 0) {
    //           if (v >= hit[+84]) { elem[+276] = 0; elem[+296] = -1; }
    //           else { elem[+276] = hit; elem[+296] = hit[+268][+292]; }
    //         } else {
    //           if (-v >= hit[+80]) { elem[+276] = 0; elem[+296] = -1; }
    //           else { elem[+276] = hit; elem[+296] = hit[+268][+292]; }
    //         }
    //       }
    //     }
    //     result = i + 1;
    //   }
    //   return result;
    // UNRESOLVED: Globals flt_59E43C, flt_59E440 and flt_59E450 are listed as read but do not appear in the raw source text of this function.
    // UNRESOLVED: Caller Game_Restart (0042d7a0) invokes this during restart, but the owning object type is unidentified.
}
