// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563E80
// Canonical corpus name: IndexBoundsCheckedArrayRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexBoundsCheckedArrayRead_00563e80.c

void UnknownObject::IndexBoundsCheckedArrayRead()
{
    // Bounds-checked array element read: validates the requested index against the element count returned by sub_563E70 for the array pointer at a1+4, and on success returns the dword element addressed by LinearInterpolation over that array pointer; returns 0 on out-of-range.
    // GUARD: If the requested index a2 is negative, return 0. [source:raw]
    // CALL: Query the element count for the array pointer stored at a1+4 via sub_563E70. [callee:0x00563E70]
    // GUARD: If the requested index a2 is greater than or equal to the element count, return 0. [callee:0x00563E70, source:raw]
    // CALL: Resolve the element address by calling LinearInterpolation on the array pointer at a1+4 with index a2. [callee:0x005648B0]
    // RETURN: Return the dword read from the resolved element address. [source:raw]

    // Conservative worker pseudocode:
    //   array = *(void**)(a1 + 4);
    //   if (a2 < 0 || a2 >= sub_563E70(array))
    //       return 0;
    //   return *(dword*)LinearInterpolation(array, a2);
    // UNRESOLVED: The element layout behind *(a1+4) and the indexing semantics of LinearInterpolation (0x005648B0) are not evidenced in this packet.
    // UNRESOLVED: Why the sole recorded caller SendJoinRequest (0x00462C00) performs this bounds-checked read is out of scope for this packet.
}
