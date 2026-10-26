// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599534
// Canonical corpus name: BufferBoundaryMarkerCheckSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferBoundaryMarkerCheckSet_00599534.c

void UnknownObject::BufferBoundaryMarkerCheckAndSet()
{
    // Checks and updates a boundary marker byte stored one byte before a data block whose pointer lives at this+0x4. If the block pointer is non-null, reads the marker byte at data[-1]; if the marker is non-zero and not the 0xFF sentinel, runs boundary validation through sub_599560 with the value at this+0x8. After the check, unconditionally rewrites the marker byte at data[-1] to 0xFF (sentinel). Returns the prior marker value (with the return register's high bytes retaining pointer bits via the decompiler's LOBYTE aliasing).
    // GUARD: Load the data block pointer from this+0x4; if it is NULL, skip all marker processing. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Read the boundary marker byte at (data pointer - 1), the byte immediately preceding the block. [field:this:0x00000004, source:raw]
    // GUARD: If the marker byte is non-zero and not the 0xFF sentinel, run boundary validation; an unset (0) or sentinel marker skips it. [field:this:0x00000004, source:raw]
    // CALL: sub_599560(value at this+0x8, 0) validates the buffer boundary; its byte result is captured into the return value. [field:this:0x00000008, callee:0x00599560, source:raw]
    // GUARD: Reload the data block pointer from this+0x4; only write the sentinel when it is non-NULL. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the 0xFF sentinel byte at (data pointer - 1), unconditionally re-arming the boundary marker. [field:this:0x00000004, source:raw]
    // RETURN: Return the previous marker value (marker byte read at the start, or the sub_599560 validation result when that path ran). [source:raw]

    // Conservative worker pseudocode:
    //   data = this->block /* +0x4 * /;
    //   if (data) {
    //       marker = *(byte*)(data - 1);
    //       if (marker && marker != 0xFF)
    //           marker = sub_599560(this->value /* +0x8 * /, 0);
    //   }
    //   data = this->block;
    //   if (data) *(byte*)(data - 1) = 0xFF;
    //   return marker;
    // UNRESOLVED: The object owning the data block at this+0x4 and the boundary-marker convention (a sentinel byte at block[-1]) is unidentified; owner is UnknownObject.
    // UNRESOLVED: The return value mixes the prior marker byte with the sub_599560 result through LOBYTE aliasing of v2; the exact intended return register content is ambiguous.
    // UNRESOLVED: The meaning of the 0 second argument to sub_599560 is unknown.
}
