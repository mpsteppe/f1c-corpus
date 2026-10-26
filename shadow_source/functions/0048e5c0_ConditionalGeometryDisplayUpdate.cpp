// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E5C0
// Canonical corpus name: ConditionalGeometryDisplayUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalGeometryDisplayUpdate_0048e5c0.c

void UnknownObject::ConditionalGeometryDisplayUpdate()
{
    // Calls the virtual method at vtable+0xA0 (entry 160) to query whether the video/geometry resource needs a reload. When the query returns 0 (no reload needed), reads the source rectangle stored at this[0xE8..0xF4] (this[58..61]), obtains the render surface via Accessor(), and copies that region to the display with RenderSurfaceFillCopy. Returns the reload-query result.
    // CALL: Invoke virtual method at vtable+0xA0 (entry 160) on this to query whether the geometry/resource reload is needed; result held in v2. [field:obj:0x000000A0, field:this:0x00000000, source:raw]
    // GUARD: If the reload-query result v2 is zero (reload not needed), proceed to copy the render surface region to the display. [field:obj:0x000000A0, source:raw]
    // ASSIGNMENT: Load the source rectangle from this[58..61]: X from this+0xE8, Y from this+0xEC, width from this+0xF0, height from this+0xF4. [field:this:0x000000E8, field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, source:raw]
    // CALL: Call Accessor() to obtain the render surface pointer used for the fill copy. [callee:0x00490920, source:raw]
    // CALL: Call RenderSurfaceFillCopy(surface, x, y, width, height) to copy the selected render surface region to the display. [callee:0x004918D0, field:this:0x000000E8, field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, source:raw]
    // RETURN: Return the reload-query result v2 (the reload-needed value, or the copy outcome byte after the guard branch). [field:obj:0x000000A0, source:raw]

    // Conservative worker pseudocode:
    //   reloadNeeded = this->vtbl[40](this);
    //   if (reloadNeeded == 0) {
    //       rect = { this->srcRectX, this->srcRectY, this->srcRectW, this->srcRectH };
    //       surface = Accessor();
    //       return RenderSurfaceFillCopy(surface, rect);
    //   }
    //   return reloadNeeded;
    // UNRESOLVED: The identity and semantics of the vtable+0xA0 method (reload-needed query) are unknown.
    // UNRESOLVED: Whether the copy is a blit to display or to a different destination surface is not established by the packet.
}
