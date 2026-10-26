// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C320
// Canonical corpus name: sub_54C320
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54C320_0054c320.c

void UnknownObject::InitializeTextureMtsHeader()
{
    // __thiscall default-header initializer: copies the MTS format string literal stored at aCubeMts410 into the start of the object, clears dword index 5 and sets dword index 6 to raw constant 1065353216, zeroes a 0x60-byte region at byte offset 28 and another 0x60-byte region at byte offset 124, clears a block of dword fields spanning indices 55..81, clears dword index 4, and stores raw constants 1176256512 and 6 at dword indices 62 and 63. Returns 0. Called by sub_54AC70 immediately after it allocates the caller output buffer during an MTS texture/mesh file load.
    // CALL: strcpy(this, aCubeMts410) copies the MTS format string literal stored at the read-only global 0x005DBFC0 into the start of the object; the copy destination v2 is this. [global:0x005DBFC0, source:raw]
    // ASSIGNMENT: dword index 5 cleared to 0 and dword index 6 set to raw constant 1065353216 (a default header value preserved verbatim). [source:raw]
    // ASSIGNMENT: memset(v2 + 28, 0, 0x60) zeroes the 0x60-byte region starting at byte offset 28. [source:raw]
    // ASSIGNMENT: memset(v2 + 124, 0, 0x60) zeroes the 0x60-byte region starting at byte offset 124. [source:raw]
    // ASSIGNMENT: A block of dword fields spanning indices 55..81 (byte offsets 220..324) is cleared to 0; the raw source lists each index explicitly. [source:raw]
    // ASSIGNMENT: dword index 4 cleared to 0. [source:raw]
    // ASSIGNMENT: dword index 62 set to raw constant 1176256512 and dword index 63 set to 6 (trailing header value pair preserved verbatim). [source:raw]
    // RETURN: Returns 0. [source:raw]
    // CALL: Invoked by sub_54AC70 right after it allocates the caller output buffer (both the texture branch and the mesh branch of the MTS loader), stamping the header before the payload is copied in. [caller:0x0054AC70, function:0x0054C320, source:raw]

    // Conservative worker pseudocode:
    //   char *v2 = strcpy(this, aCubeMts410);
    //   ((DWORD*)v2)[5] = 0;
    //   ((DWORD*)v2)[6] = 1065353216;
    //   memset(v2 + 28, 0, 0x60);
    //   memset(v2 + 124, 0, 0x60);
    //   // dword indices 55..81 cleared individually in the raw source
    //   ((DWORD*)v2)[4] = 0;
    //   ((DWORD*)v2)[62] = 1176256512;
    //   ((DWORD*)v2)[63] = 6;
    //   return 0;
    // UNRESOLVED: The raw constants 1065353216, 1176256512 and 6 (dword indices 6, 62, 63) are preserved verbatim; their semantic meaning is not defined by this packet.
    // UNRESOLVED: The string at aCubeMts410 is the texture-format magic only per the caller's strcmp against it in sub_54AC70; the literal bytes are not present in this packet.
    // UNRESOLVED: The effective this pointer at the caller's sub_54C320(0) call sites is register-supplied (__thiscall) and not visible in the decompiled call, so the exact object stamped is caller-context dependent.
    // UNRESOLVED: The layout and purpose of each zeroed header field are unknown; the object type owning them is unknown (owner UnknownObject).
}
