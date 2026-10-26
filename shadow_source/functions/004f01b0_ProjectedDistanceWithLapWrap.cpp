// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F01B0
// Canonical corpus name: sub_4F01B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F01B0_004f01b0.c

void UnknownObject::ProjectedDistanceWithLapWrap()
{
    // Computes an interpolated along-track distance for the current position relative to a track segment, with lap-wraparound correction of the three waypoint distances based on a session state flag. Reads the position monitor via PositionChangeMonitor, obtains two waypoint objects and a stored session flag, projects the current position (this+0x34D4/0x34D8/0x34DC) onto the segment between the waypoints, and interpolates the stored per-waypoint distances by the clamped projection factor. Returns one of the stored distances or an interpolated blend depending on where the projection falls; returns the first waypoint distance when the segment length is zero.
    // CALL: Call PositionChangeMonitor(this) to obtain the position monitor object v2 used for waypoint pointers and stored distances. [source:raw, callee:0x004E9630]
    // ASSIGNMENT: Load the session state flag from the object referenced by this, at offset 0x4040 (16448), into v3. [source:raw, field:this:0x00000000, field:obj:0x00004040]
    // ASSIGNMENT: Read the three stored along-track distances: one from v2, and one from each of the two waypoint objects obtained from v2; seed v15, result, and v16. [source:raw]
    // GUARD: Branch on the session state flag v3: state 0 and state 2 select different lap-wraparound correction directions for each of the three distances. [source:raw]
    // CALCULATION: For each of the three tracked objects, adjust its stored distance by flt_5EA408: add it when the per-object state is 0 under flag 2, subtract it when the per-object state is 2 under flag 0. [source:raw, global:0x005EA408]
    // CALCULATION: Form the segment vector as the difference between the two waypoint positions (each read as x/y/z at offsets 0/4/8). [source:raw]
    // GUARD: Compute the segment length via sqrt of the squared components; if the length is zero, return the first stored distance v15. [source:raw]
    // CALCULATION: Normalize the segment direction by 1/length, then project the monitor-relative position and the current position (this+0x34D4/0x34D8/0x34DC) onto that direction to produce the projection scalars v19 and v17. [source:raw, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC]
    // GUARD: Classify the projection v17: beyond the segment end returns the third distance v16, inside the segment interpolates between v15 and v16 by the projection ratio, before the start blends between result and v15. [source:raw]
    // RETURN: Return the selected or interpolated distance; when the projection is not positive, return the second stored distance (result). [source:raw]

    // Conservative worker pseudocode:
    //   double sub_4F01B0(int this) {
    //     int mon = PositionChangeMonitor(this);
    //     int state = *(int*)(*(int*)this + 0x4040);
    //     float d0 = *(float*)(mon + 144);
    //     int w0 = *(int*)(mon + 268), w1 = *(int*)(mon + 272);
    //     float d1 = *(float*)(w0 + 144), d2 = *(float*)(w1 + 144);
    //     apply_lap_wrap(state, mon, w0, w1, d0, d1, d2, flt_5EA408);
    //     vec seg = pos(w1) - pos(w0);
    //     double len = sqrt(seg.x^2 + seg.y^2 + seg.z^2);
    //     if (len == 0.0) return d0;
    //     vec n = seg / len;
    //     double p1 = dot(pos(mon) - pos(w0), n);
    //     double p2 = dot(this.pos - pos(w0), n);
    //     if (p2 <= 0.0) return d1;
    //     if (p2 >= len) return d2;
    //     if (p2 >= p1) return (p2 - p1) / (len - p1) * (d2 - d0) + d0;
    //     return d1 + p2 / p1 * (d0 - d1);
    //   }
    // UNRESOLVED: flt_59E43C and flt_59E440 appear in the packet but have no direct reference in the raw decompiled source; their roles in this function are not established.
    // UNRESOLVED: Identity of the three tracked objects' per-object state at offset 68 and the exact meaning of the stored distance values at offset 144 are caller-domain details not resolved here.
    // UNRESOLVED: The two waypoint objects and the object holding the session flag are obtained through offsets in the monitor object that have no named packet field.
}
