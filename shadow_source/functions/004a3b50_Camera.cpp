// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3B50
// Canonical corpus name: Camera
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Camera_004a3b50.c

void UnknownObject::Camera()
{
    // Camera position/yaw update for a 3D object (vehicle/pit-crew camera). Reads the current camera state via RenderCallWithGuard into a float vector and retrieves a scene/camera record through sub_403640(dword_5EA2C0, ...). Depending on a mode field at record+300 (== 1), either tracks a target at record+272 (vector from target to base, optionally normalized, then clamped camera offset computed against the base orientation vectors and perturbed by a ring-buffer noise table flt_8AB274 indexed by dword_8AAE70), or applies a rotation-matrix camera transform (EulerToRotationMatrix) combined with noise. Yaw is computed with atan2. When the object's sound-source handle this[25] (this+0x64) is non-null, computes a bounding box, builds a spatial query against dbl_7C9360 (SpatialGridQuery) and adjusts the camera height on collision. Writes the final position/yaw back with Vec3CopyToStruct.
    // CALL: RenderCallWithGuard(dword_7C54E8, &v37, v41) reads the current camera state vector into the local v37..v41 block. [callee:0x004D1140, global:0x007C54E8]
    // CALL: sub_403640(dword_5EA2C0, &v37, 0) resolves the scene/camera record for the camera position input. [callee:0x00403640, global:0x005EA2C0]
    // GUARD: Branch on the mode field at record+300 (dword index 75): == 1 selects the target-tracking path, otherwise the rotation-matrix path. [source:raw]
    // CALCULATION: Compute the offset vector between the target at record+272 (dword index 68) and the record base (v23/v27/v29 = target - base, per component). [source:raw]
    // CALCULATION: When the squared offset magnitude is > 0, normalize the offset via 1/sqrt(dot). [source:raw]
    // CALCULATION: Compute v40 = dot of (camera position - base) with the normalized offset (view alignment). [source:raw]
    // CALCULATION: Compute a clamped parameter v10 = dot(camera-base, base orientation +0x20..0x28) * 0.3, clamped to the [-2.75, 2.75] window. [source:raw]
    // CALCULATION: Recompute the camera position v37/v38/v39 along the normalized offset scaled by v40 and the clamped orientation terms. [source:raw]
    // CALCULATION: Apply per-frame noise jitter to v37/v39 from the ring buffer flt_8AB274, advancing the counter dword_8AAE70. [global:0x008AAE70, global:0x008AB274]
    // CALCULATION: When v10 < 0, flip the sign of the horizontal offset components v34/v36. [source:raw]
    // CALCULATION: Compute yaw v17 = atan2(v36, v34) for the target-tracking path. [source:raw]
    // CALL: Rotation-matrix path: EulerToRotationMatrix(v41, v45) builds a rotation matrix from the camera angles. [callee:0x00566E40]
    // CALCULATION: Rotation-matrix path: combine noise terms (v33/v26 from flt_8AB274) with the matrix rows to update v37/v38/v39 and compute yaw v17 via atan2. [global:0x008AAE70, global:0x008AB274]
    // GUARD: When the object's sound-source handle this[25] (this+0x64) is non-null, run the spatial collision query path. [field:this:0x00000064]
    // CALL: BoundingBoxComputation(v43) computes the bounding box of the offset vector. [callee:0x004DD550]
    // CALCULATION: Pack the spatial query: position v53[0..2] = current camera position, plus query fields v54..v59 (integers). [source:raw]
    // CALL: SpatialGridQuery(dbl_7C9360, v53) queries the spatial grid at the camera position. [callee:0x0044C4C0, global:0x007C9360]
    // CALCULATION: On a grid hit, adjust the camera height v38 by (v58 - v41[4] - 0.08). [source:raw]
    // ASSIGNMENT: Assemble the yaw output block: v41[0] = 0, v41[1] = v16 - v17, v41[2] = 0. [source:raw]
    // RETURN: Return Vec3CopyToStruct(this, &v37, v41) which writes the computed position and yaw back to the camera object. [callee:0x004A2800]

    // Conservative worker pseudocode:
    //   int Camera(_DWORD *this) {
    //     float cam[3]; int ang[5];
    //     RenderCallWithGuard(dword_7C54E8, cam, ang);
    //     float *rec = sub_403640(dword_5EA2C0, cam, 0);
    //     float pos[3], yaw;
    //     if (((_DWORD*)rec)[75] == 1) {
    //       float *tgt = (float*)((_DWORD*)rec)[68];
    //       float dx = tgt[0]-rec[0], dy = tgt[1]-rec[1], dz = tgt[2]-rec[2];
    //       float len = dx*dx+dy*dy+dz*dz;
    //       if (len > 0) { float s = 1/sqrt(len); dx*=s; dy*=s; dz*=s; }
    //       float align = (cam[0]-rec[0])*dx + (cam[1]-rec[1])*dy + (cam[2]-rec[2])*dz;
    //       float t = (dz*rec[10] + dy*rec[9] + dx*rec[8]) * 0.3;
    //       if (t < 0 || t >= 2.75) { if (t <= 0 && t > -2.75) t = -2.75; } else t = 2.75;
    //       pos[0] = t*rec[8] + rec[0] + dx*align;
    //       pos[1] = t*rec[9] + rec[1] + dy*align;
    //       pos[2] = t*rec[10] + rec[2] + dz*align;
    //       int idx = dword_8AAE70;
    //       pos[0] += flt_8AB274[(unsigned char)dword_8AAE70++] * 0.05;
    //       pos[2] += flt_8AB274[(unsigned char)dword_8AAE70++] * 0.05;
    //       if (t < 0) { dx = -dx; dz = -dz; }
    //       yaw = atan2(dz, dx);
    //     } else {
    //       float n0 = flt_8AB274[(unsigned char)dword_8AAE70++];
    //       float n1 = flt_8AB274[(unsigned char)dword_8AAE70++] * 0.1;
    //       float n2 = n0 * 0.1 - 6.0;
    //       float m[3][3]; EulerToRotationMatrix(ang, m);
    //       pos[0] = m[0][0]*n2 + n1*m[0][1] + cam[0];
    //       pos[1] = m[1][2]*n2 + m[1][1]*n1 + cam[1];
    //       pos[2] = m[2][2]*n2 + m[2][1]*n1 + cam[2];
    //       yaw = atan2(m[1][0], m[0][0] - 1.0);
    //     }
    //     int angOut[5] = { 0, *(int*)(&yaw), 0 };
    //     if (this[25]) {
    //       BoundingBoxComputation(pos);
    //       double q[3] = { pos[0], pos[1], pos[2] };
    //       if (SpatialGridQuery(dbl_7C9360, q)) pos[1] = v58 - *(float*)&ang[4] - 0.08;
    //     }
    //     return Vec3CopyToStruct(this, pos, angOut);
    //   }
    // UNRESOLVED: The 16 global float/int constants in the packet (flt_59E43C, flt_59E440, flt_59E448, flt_59E670, flt_59E84C, flt_59E8B4, flt_59E940, flt_5ACB28, flt_5ACB2C, flt_5ACB30, dword_8ACEE0) do not appear in this function's source text; they are presumed read by callees or compiler-hoisted, semantics unknown.
    // UNRESOLVED: Mode semantics of record+300 (dword index 75) and the target at record+272 are not grounded here.
    // UNRESOLVED: The v58 result and v41[4] used in the spatial-grid height adjustment come from local stack fields whose producers are outside this packet's visible operations.
    // UNRESOLVED: Record type returned by sub_403640 and the meaning of its base-orientation vectors are not established.
}
