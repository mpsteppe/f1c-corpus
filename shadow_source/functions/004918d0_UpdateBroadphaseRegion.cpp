// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004918D0
// Canonical corpus name: RenderSurfaceFillCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderSurfaceFillCopy_004918d0.c

void UnknownObject::UpdateBroadphaseRegion()
{
    // Dispatches a broadphase collision update for the screen-region AABB (a2-a5). Returns 0 without any update when either extent a4 or a5 is non-positive. Otherwise asks the race-phase timer predicate sub_4F9B20 (reading global unk_8AFE18) whether the full update is allowed: if so it iterates every stored broadphase structure in the this header's array (count = **this, 16-byte stride) calling CollisionBroadphaseBuilder on each; if not it updates only the current ring-bucket slot (array base + 16 * index) and returns 1. Called from many render/draw paths (UI scroll views, blits, overlays, dialogs, bitmap draw, guarded draw dispatches).
    // GUARD: Entry guard: if a4 <= 0 or a5 <= 0 (zero or negative region extent), return 0 immediately and perform no broadphase update. [source:raw, function:0x004918D0]
    // CALL: Evaluate the race-phase timer predicate sub_4F9B20(&unk_8AFE18): a non-zero result selects the full-update path over all buckets, a zero result selects the single-bucket path. [callee:0x004F9B20, global:0x008AFE18, source:raw]
    // ASSIGNMENT: Full-update path: read the bucket count v7 from **this (header first dword at this+0x0); if the count is not positive, skip the loop and return 1. [field:this:0x00000000, source:raw]
    // LOOP: Iterate all buckets: for each of the v7 entries CollisionBroadphaseBuilder((void***)((*this)[2] + v8), a2, a3, a4, a5) updates one 16-byte element, then v8 advances by 16 and the counter decrements until exhausted. [callee:0x00490EE0, source:raw]
    // CALL: Single-bucket path (timer predicate false): CollisionBroadphaseBuilder((void***)((*this)[2] + 16 * (*this)[1]), a2, a3, a4, a5) updates only the current ring-bucket slot selected by the header index. [callee:0x00490EE0, field:this:0x00000000, source:raw]
    // CALL: The CollisionBroadphaseBuilder target elements are 16-byte structures whose first three dwords (obj+0x0, obj+0x4, obj+0x8) form the broadphase substructure head consumed by the callee on both paths. [field:obj:0x00000000, field:obj:0x00000004, field:obj:0x00000008, callee:0x00490EE0, source:raw]
    // RETURN: Return 1 on both timer-success paths (after the full loop or the single-bucket call) and return 0 when the extent guard rejects the region. [source:raw]

    // Conservative worker pseudocode:
    //   char UpdateBroadphaseRegion(int** this, short x, short y, int w, int h) {
    //     if (w <= 0 || h <= 0) return 0;
    //     if (sub_4F9B20(&unk_8AFE18)) {
    //       int n = **this;
    //       for (int i = 0; i < n; i++)
    //         CollisionBroadphaseBuilder((void***)((*this)[2] + i*16), x, y, w, h);
    //     } else {
    //       CollisionBroadphaseBuilder((void***)((*this)[2] + 16 * (*this)[1]), x, y, w, h);
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The semantics of sub_4F9B20 and unk_8AFE18 (race-phase timer) and of CollisionBroadphaseBuilder's in-memory element layout are inherited from existing analysis; the callee bodies are not evidenced in this packet.
    // UNRESOLVED: The obj+0x4 and obj+0x8 dwords are listed in the packet field evidence but are not read directly by this function; their roles inside the 16-byte broadphase element are inferred, not proven.
    // UNRESOLVED: this is an int** header: only the this+0x0 count dword is captured in the field evidence; the (*this)[1] index and (*this)[2] array-base dwords are referenced from the raw source only.
    // UNRESOLVED: The canonical corpus name RenderSurfaceFillCopy does not match the broadphase-update semantics shown by the source; the proposed name follows the existing analysis instead.
}
