// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563230
// Canonical corpus name: ArrayOfStructStrideSearchByID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayOfStructStrideSearchByID_00563230.c

void UnknownObject::ArrayOfStructStrideSearchByID()
{
    // Searches a container's array of 7-dword-stride elements for an ID value equal to a2 and returns the zero-based element index, or -1 when no element matches. The element count is read from the container at offset 108 and the array base pointer at offset 8 (elements are examined starting 4 bytes into that array). Called by NetworkConnection.
    // ASSIGNMENT: Reads the element count from the container at offset 108 [source:raw]
    // GUARD: Returns -1 when the element count is not positive [source:raw]
    // LOOP: Iterates over the 7-dword-stride elements starting from the base pointer at offset 8 plus 4, comparing each element's first dword to a2 [source:raw]
    // GUARD: Returns -1 when the scan index reaches the element count without a match [source:raw]
    // RETURN: Returns the element index when the element's first dword equals a2 [source:raw, function:0x00563230]

    // Conservative worker pseudocode:
    //   count = container[108];
    //   if (count <= 0) return -1;
    //   for (index = 0, elem = container[8] + 4; ; index++, elem += 7) {
    //       if (*elem == id) return index;
    //       if (index + 1 >= count) return -1;
    //   }
}
