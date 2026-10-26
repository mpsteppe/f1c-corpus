// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051DF18
// Canonical corpus name: SymmetricArrayInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SymmetricArrayInit_0051df18.c

void UnknownObject::SymmetricArrayInit()
{
    // Allocates and initializes a 256-entry symmetric offset table. Reads a context pointer from this+0x1A4, calls an allocator through the vtable at this+0x4 (count 1, size 2044), advances the returned block by 1020 bytes to center it, stores the centered pointer at context+0x28, then fills 256 signed entries symmetrically about the midpoint: entries +0..+15 count upward against mirrored negative entries, entries +16..+47 continue counting upward while the negative side mirrors the positive value, and entries +48..+255 mirror the positive value unchanged. Returns the centered buffer pointer.
    // CALCULATION: Read the context pointer from this+0x1A4 into v1 [field:this:0x000001A4, source:raw]
    // CALL: Invoke the allocator function at offset 0 of the vtable stored at this+0x4 with arguments (this, 1, 2044), then add 1020 to its return value to center the buffer; result holds the centered pointer [field:this:0x00000004, field:*(this+0x4):0x00000000, source:raw]
    // ASSIGNMENT: Store the centered allocation result into the context object at +0x28 [field:*(this+0x1A4):0x00000028, source:raw]
    // LOOP: First pass (index v4 = 0..15): write v3 ascending at result+4*v4 while writing v5 (starting 0, descending toward -15) at the mirrored location through the descending pointer v6 [source:raw]
    // LOOP: Second pass (index v4 = 16..47): write v3 at result+4*v4 and -v3 at the descending pointer v7, advancing v3 only on even iterations (v4 & 1 == 0) [source:raw]
    // LOOP: Third pass (index v4 = 48..255): write v3 at result+4*v4 and -v3 at the descending pointer v8 with no further counter adjustment [source:raw]
    // RETURN: Return the centered buffer pointer; the caller (sub_51DFCB, 0x0051DFCB) consumes the result [caller:0x0051DFCB, function:0x0051DF18, source:raw]

    // Conservative worker pseudocode:
    //   context = *(this + 0x1A4);
    //   result = allocator_vtable0(this, 1, 2044) + 1020;
    //   *(context + 0x28) = result;
    //   for (i = 0; i < 16; ++i) { result[i] = i; result[0 - i] = -i; }
    //   for (i = 16; i < 48; ++i) { result[i] = value; result[0 - i] = -value; if ((i & 1) == 0) ++value; }
    //   for (i = 48; i <= 255; ++i) { result[i] = value; result[0 - i] = -value; }
    //   return result;
    // UNRESOLVED: The concrete allocator behind the vtable call at this+0x4 offset 0 is not named in the packet; only the vtable indirection is evidenced
    // UNRESOLVED: The asymmetric counting rule in the second pass (advance on even iterations only) is reproduced literally from the raw source but its semantic intent versus the first and third passes is undocumented
}
