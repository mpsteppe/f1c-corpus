// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054B950
// Canonical corpus name: SceneNodePositionGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneNodePositionGetter_0054b950.c

void UnknownObject::SceneNodePositionGetter()
{
    // Lazily computes a scene node's world position transform via an indirect D3D device wrapper call when the node's cache flag (bit 0x20000000 at node+20, this+0x218) is clear, then conditionally writes the node's X/Y/Z coordinates (this+0x2EC/0x2F0/0x2F4) into up to three caller-provided output pointers. Returns the third output pointer.
    // ASSIGNMENT: Load scene node pointer from this+0x204 (this[129]); source of all subsequent position/flag reads. [field:this:0x00000204, source:raw]
    // GUARD: If bit 0x20000000 at node+20 (this+0x218) is clear, the transform is not yet cached and recomputation proceeds; otherwise the cached path is taken. [field:this:0x00000218, source:raw]
    // CALL: Indirect call through D3DDeviceWrapperPtr vtable+4 (*(dword_8B8F24+4)) with arguments dword_8B8F24, node+220, node+232, and this+104; recomputes the node transform into caller-side buffers. [global:0x008B8F24, source:raw]
    // ASSIGNMENT: Set cache flag bit 0x20000000 at node+20 (this+0x218) after recomputation so subsequent reads skip the D3D call. [field:this:0x00000218, source:raw]
    // GUARD: If outX (a2) is non-null, write the node X coordinate read from this+0x2EC into *a2. [field:this:0x000002EC, source:raw]
    // GUARD: If outY (a3) is non-null, write the node Y coordinate read from this+0x2F0 into *a3. [field:this:0x000002F0, source:raw]
    // GUARD: If outZ (a4) is non-null, write the node Z coordinate read from this+0x2F4 into *a4. [field:this:0x000002F4, source:raw]
    // RETURN: Return outZ (a4) as the function result; the return value is the last output pointer. [source:raw, function:0x0054B950]

    // Conservative worker pseudocode:
    //   node = this[129]; /* node pointer at this+0x204 * /
    //   if ((*(node + 20) & 0x20000000) == 0) {
    //       (*(void (__cdecl **)(int, int, int, _DWORD *))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, node + 220, node + 232, this + 104);
    //       *(node + 20) |= 0x20000000;
    //   }
    //   if (a2) *a2 = *(node + 232); /* X via this+0x2EC * /
    //   if (a3) *a3 = *(node + 236); /* Y via this+0x2F0 * /
    //   if (a4) *a4 = *(node + 240); /* Z via this+0x2F4 * /
    //   return a4;
    // UNRESOLVED: Identity of the indirect transform function behind D3DDeviceWrapperPtr vtable+4 is not resolved; only the call site is known.
    // UNRESOLVED: The transform destination is this+104 (this[104]) in the raw source, while the field table lists this+0x218 as RW; the destination buffer semantic is unconfirmed and the field table's 'cached position data' interpretation of this+0x218 conflicts with the raw flag access.
    // UNRESOLVED: Semantic purpose of the node+220 (0xDC) transform input argument is unknown.
    // UNRESOLVED: Coordinate origin/space of the values at this+0x2EC/0x2F0/0x2F4 is not established from the packet.
}
