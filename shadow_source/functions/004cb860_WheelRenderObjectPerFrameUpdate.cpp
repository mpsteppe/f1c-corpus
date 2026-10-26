// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CB860
// Canonical corpus name: WheelRenderObjectPerFrameUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelRenderObjectPerFrameUpdate_004cb860.c

void UnknownObject::WheelRenderObjectPerFrameUpdate()
{
    // Per-frame update for wheel render objects. Iterates the object list owned by a1 (count at a1+100, entry pointer array at a1+104), removes expired objects outside their lifetime window [v5[2], v5[3]], interpolates each object's world position from base, velocity and elapsed time, scales it by a frame-time factor, resolves a direction offset from the vehicle's orientation fields, then evaluates visibility against the player vehicle or nearby AI drivers depending on the global render mode dword_7CFA28, and finally writes texture and color flags through a set of bounded array helpers. Takes elapsed time a2 in ST(0) or from global dbl_8AFEA0 unless the render-mode global dword_8AB6E4 selects Delegation.
    // GUARD: Select elapsed-time source: if global render mode dword_8AB6E4 equals 2 call Delegation(&dword_8AB6EC); otherwise default a2 to global dbl_8AFEA0. [global:0x008AB6E4, global:0x008AB6EC, global:0x008AFEA0, callee:0x004B9CE0]
    // ASSIGNMENT: Load object count result = *(a1 + 100) and store elapsed time v31 = a2 before the iteration loop. [field:this:0x00000064, function:0x004CB860]
    // LOOP: Loop over the object list: entry pointer v5 = *(*(a1 + 104) + 4 * index); iterate while index < count. [field:this:0x00000068]
    // GUARD: Expiry check: if elapsed v31 is outside the object's lifetime window (v31 > v5[3] or v31 < v5[2]) call ArrayElementRemoval(a1, v5) and decrement the index to revisit the shifted slot. [callee:0x004CB5A0]
    // CALCULATION: Compute time-in-window v26 = v31 - v5[2] and interpolate the object position from base (v5[11], v5[12], v5[13]) plus v26 scaled by velocity components (v5[14], v5[15], v5[16]). [source:raw]
    // CALCULATION: Scale by the object's frame-time factor: v10 = v26 * *(a1 + 64), then pass v10 to sub_5881F0. [field:this:0x00000040, callee:0x005881F0]
    // CALCULATION: Resolve world-space placement from vehicle fields: direction = v5[26] scaled by (a1+36), (a1+40), (a1+44) added to (a1+24), (a1+28), (a1+32); final position adds scaled direction to (a1+12), (a1+16), (a1+20), with a midpoint v35 = 0.5 * intermediate Y. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // GUARD: Player visibility path: when global mode dword_7CFA28 == 1 read the player entry at dword_7C54F0[dword_7C54DC] + 1860, and if its X/Z distance from the object is below flt_5D3490 call RaySphereIntersection with the midpoint radius. [global:0x007CFA28, global:0x007C54DC, global:0x007C54F0, global:0x005D3490, callee:0x004CBDD0]
    // GUARD: AI driver path: when dword_7CFA28 is in (1, 3] call FindDriversInRange(flt_8AC4E0, v25, flt_5D3494, &v38); stride v37 is read from dword_7C54E0 + 18580 when nonzero, else 104, and is skipped when (dword_7CFA28 & 1) is zero. [global:0x007CFA28, global:0x007C54E0, global:0x008AC4E0, global:0x005D3494, callee:0x004C9C70]
    // LOOP: Iterate the found driver list (count v38[0]); for each driver read its position at +1848, +1852, +1856, and if X/Z distance is below flt_5D3490 and the driver id does not equal v37, call RaySphereIntersection against it. [callee:0x004CBDD0, global:0x005D3490]
    // CALL: Set the texture layer flag via TextureLayerFlagSet(v5[0], v27, v28, v29). [callee:0x00558C60]
    // CALL: Set the array element color flags via ArrayElementFlagSetWithBoundsCheck(v5[0], v32, v33, v34). [callee:0x00558CB0]
    // CALCULATION: Compute the color/alpha factor v24: when the earlier comparison flags are set and v21 <= v5[5] use v26 * v5[8] * v5[10], else v5[10]; otherwise use (1.0 - (v21 - v5[6]) * v5[9]) * v5[10]. [source:raw]
    // CALL: Write the packed color value (v24 << 24) + 0xFFFFFF via BoundsCheckedArrayWrite(v5[0], value). [callee:0x00558CF0]
    // LOOP: Reload result = *(a1 + 100) and advance the loop index; repeat until all objects are processed. [field:this:0x00000064]
    // RETURN: Return the final object count. [source:raw]

    // Conservative worker pseudocode:
    //   int WheelRenderObjectPerFrameUpdate(this, double a2) {
    //     if (dword_8AB6E4 == 2) Delegation(&dword_8AB6EC); else a2 = dbl_8AFEA0;
    //     int count = this->count;
    //     float elapsed = a2;
    //     for (int i = 0; i < count; ++i) {
    //       float* obj = this->objects[i];
    //       if (elapsed > obj[3] || elapsed < obj[2]) { ArrayElementRemoval(this, obj); --i; continue; }
    //       float t = elapsed - obj[2];
    //       float px = obj[11] + t * obj[14], py = obj[12] + t * obj[15], pz = obj[13] + t * obj[16];
    //       float scale = t * this->scale64;
    //       sub_5881F0(scale);
    //       float dx = obj[26] * this->f36 + this->f24, dy = obj[26] * this->f40 + this->f28, dz = obj[26] * this->f44 + this->f32;
    //       float wx = this->f12 + dx * scale, wy = this->f16 + dy * scale, wz = this->f20 + dz * scale;
    //       float mid = wy * 0.5;
    //       if (dword_7CFA28 == 1) {
    //         int* pe = *(int**)dword_7C54F0[dword_7C54DC] + 1860;
    //         if (fabs(pe[0] - px) < flt_5D3490 && fabs(pe[2] - pz) < flt_5D3490) RaySphereIntersection(&px, obj + 21, mid, pe);
    //       } else if (dword_7CFA28 > 1 && dword_7CFA28 <= 3) {
    //         int stride = dword_7C54E0 ? *(int*)(dword_7C54E0 + 18580) : 104;
    //         if (!(dword_7CFA28 & 1)) stride = dword_7C54E0 ? *(int*)(dword_7C54E0 + 18580) : 104;
    //         int found[2];
    //         int* ids = FindDriversInRange(flt_8AC4E0, pz + px, flt_5D3494, found);
    //         for (int j = 0; j < found[0]; ++j) {
    //           int* drv = *(int**)((int)ids + 4 * j);
    //           if (fabs(*(float*)drv - px) < flt_5D3490 && fabs(*(float*)(drv + 2) - pz) < flt_5D3490 && stride != *(int*)(drv + 1))
    //             RaySphereIntersection(&px, obj + 21, mid, drv);
    //         }
    //       }
    //       TextureLayerFlagSet(obj[0], px, py, pz);
    //       ArrayElementFlagSetWithBoundsCheck(obj[0], wx, wy, wz);
    //       int factor = (flags && t <= obj[5]) ? (int)(t * obj[8] * obj[10]) : (int)obj[10];
    //       if (!flags) factor = (int)((1.0 - (t - obj[6]) * obj[9]) * obj[10]);
    //       BoundsCheckedArrayWrite(obj[0], (factor << 24) + 0xFFFFFF);
    //       count = this->count;
    //     }
    //     return count;
    //   }
    // UNRESOLVED: Globals flt_59E43C and flt_59E450 are listed in the packet but do not appear in the raw source text; their role in this function is unknown.
    // UNRESOLVED: Owner class of a1 (render object manager) is unknown; fields are read-only here so no write-back contract is exposed.
    // UNRESOLVED: sub_5881F0 is called with the scaled time factor; its exact operation is not analyzed in this packet.
}
