// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457000
// Canonical corpus name: sub_457000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_457000_00457000.c

void UnknownObject::StructDeepCopyFromSource()
{
    // Deep-copies a source struct into the destination object `this`. Dereferences the string pointer at source+4 and copies the string with buffer reallocation, copies the leading 3D vectors via the vector-copy helpers, then pulls a sequence of float/dword/byte values out of the source through several two-or-three-value getter helpers and stores them at destination offsets 0x30..0x6C. A direct float, a direct byte, and a long tail of raw dword copies finish the transfer up to offset 0xC4. Returns the destination pointer.
    // CALL: Null-safe pointer dereference of the string pointer stored at source+4. [callee:0x00415C30]
    // CALL: Copy the source string (dereferenced from source+4) into the destination string buffer, reallocating as needed. [callee:0x00566650]
    // CALL: Copy the first 3D vector from source+12 into the destination struct's leading vector fields via the vector-to-struct copy helper. [callee:0x00456110]
    // CALL: Copy a second 3D vector from source+24 into the destination struct via the plain vector copy helper. [callee:0x00456130]
    // CALL: Read two values from the source via the 0x30/0x34 accessor helper. [callee:0x00456040]
    // ASSIGNMENT: Store the two accessor values into destination fields at 0x30 and 0x34. [field:this:0x00000030, field:this:0x00000034]
    // CALL: Read two values from the source via the dual-field accessor helper. [callee:0x00456060]
    // ASSIGNMENT: Store the two accessor values into destination fields at 0x38 and 0x3C. [field:this:0x00000038, field:this:0x0000003C]
    // CALL: Read two values from the source via the short-computation accessor helper. [callee:0x00456080]
    // ASSIGNMENT: Store the two accessor values into destination fields at 0x40 and 0x44. [field:this:0x00000040, field:this:0x00000044]
    // ASSIGNMENT: Copy the float at source+72 directly into destination field 0x48. [field:this:0x00000048]
    // CALL: Read two values from the source via the second dual-field accessor helper. [callee:0x004560A0]
    // ASSIGNMENT: Store the two accessor values into destination fields at 0x4C and 0x50. [field:this:0x0000004C, field:this:0x00000050]
    // CALL: Read the viewport/rect dimension pair from the source via the rect-viewport accessor helper. [callee:0x004560C0]
    // ASSIGNMENT: Store the two accessor values into destination fields at 0x54 and 0x58. [field:this:0x00000054, field:this:0x00000058]
    // ASSIGNMENT: Copy the float at source+92 directly into destination field 0x5C. [field:this:0x0000005C]
    // ASSIGNMENT: Copy the byte at source+96 directly into destination field 0x60. [field:this:0x00000060]
    // CALL: Read three values from the source via the multi-field accessor helper. [callee:0x004560E0]
    // ASSIGNMENT: Store the three accessor values into destination fields at 0x64, 0x68 and 0x6C (one float and one dword interleaved). [field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C]
    // ASSIGNMENT: Copy the raw dword tail from source+112 through source+184 into destination fields 0x70..0xB8. [field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, field:this:0x000000A0, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, field:this:0x000000B0, field:this:0x000000B4, field:this:0x000000B8]
    // ASSIGNMENT: Copy the final three dwords from source+188, source+192 and source+196 into destination fields 0xBC, 0xC0 and 0xC4. [field:this:0x000000BC, field:this:0x000000C0, field:this:0x000000C4]
    // RETURN: Return the destination pointer. [source:raw]

    // Conservative worker pseudocode:
    //   // Deep copy of a camera/viewport parameter struct into `this`.
    //   src = a2;
    //   str = NullSafePointerDereference(src + 4);
    //   StringCopyWithBufferRealloc(str);
    //   F_3VectorCopyToStruct(this, src + 12);
    //   VectorCopy(this, src + 24);
    //   get2(src, &a, &b);      this[0x30] = a; this[0x34] = b;
    //   get2(src, &a, &b);      this[0x38] = a; this[0x3C] = b;
    //   get2(src, &a, &b);      this[0x40] = a; this[0x44] = b;
    //   this[0x48] = src[0x48];
    //   get2(src, &a, &b);      this[0x4C] = a; this[0x50] = b;
    //   get2(src, &a, &b);      this[0x54] = a; this[0x58] = b;
    //   this[0x5C] = src[0x5C];
    //   this[0x60] = src[0x60];
    //   get3(src, &a, &b, &c);  this[0x64] = a; this[0x68] = b; this[0x6C] = c;
    //   memcpy_dwords(this + 0x70, src + 0x70, (0xC4 - 0x70 + 4) / 4);
    //   return this;
    // UNRESOLVED: The getter helpers (0x00456040, 0x00456060, 0x00456080, 0x004560A0, 0x004560C0, 0x004560E0) perform source-side reads whose exact field semantics are not visible here; this function only stores their outputs.
    // UNRESOLVED: The destination of the string copy (StringCopyWithBufferRealloc) is not explicit in the raw source; it is assumed to target the destination struct's string buffer.
    // UNRESOLVED: F_3VectorCopyToStruct and VectorCopy write leading vector fields below 0x30 that are not part of the packet field evidence list.
    // UNRESOLVED: The dword slot between offsets 0x78 and 0x80 is skipped by the tail copy; whether this is intentional or a gap in the source struct is unresolved.
}
