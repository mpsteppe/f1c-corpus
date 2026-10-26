// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054E9B0
// Canonical corpus name: sub_54E9B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54E9B0_0054e9b0.c

void UnknownObject::InitializeMeshMtsHeader()
{
    // __thiscall default-header initializer: copies the MTS format string literal stored at aCubeMts401 into the start of the object, clears dword indices 4 and 5 and sets dword index 6 to raw constant 1065353216, zeroes a 0x60-byte region at byte offset 28, clears a block of dword fields spanning indices 31..57, and stores raw constants 1176256512 and 6 at dword indices 38 and 39. Returns 0. Called by sub_54AC70 right after it allocates an intermediate mesh buffer, before the file payload is read over it and the payload magic is verified.
    // CALL: strcpy(this, aCubeMts401) copies the MTS format string literal stored at the read-only global 0x005DBF50 into the start of the object; the copy destination v2 is this. [global:0x005DBF50, source:raw]
    // ASSIGNMENT: dword index 4 cleared to 0, dword index 5 cleared to 0 and dword index 6 set to raw constant 1065353216 (a default header value preserved verbatim). [source:raw]
    // ASSIGNMENT: memset(v2 + 28, 0, 0x60) zeroes the 0x60-byte region starting at byte offset 28. [source:raw]
    // ASSIGNMENT: A block of dword fields spanning indices 31..57 (byte offsets 124..228) is cleared to 0; the raw source lists each index explicitly. [source:raw]
    // ASSIGNMENT: dword index 38 set to raw constant 1176256512 and dword index 39 set to 6 (trailing header value pair preserved verbatim). [source:raw]
    // RETURN: Returns 0. [source:raw]
    // CALL: Invoked by sub_54AC70 right after it allocates the intermediate raw mesh buffer, before the payload is read over it and then strcmp'd against aCubeMts401 by the caller. [caller:0x0054AC70, function:0x0054E9B0, source:raw]

    // Conservative worker pseudocode:
    //   char *v2 = strcpy(this, aCubeMts401);
    //   ((DWORD*)v2)[4] = 0;
    //   ((DWORD*)v2)[5] = 0;
    //   ((DWORD*)v2)[6] = 1065353216;
    //   memset(v2 + 28, 0, 0x60);
    //   // dword indices 31..57 cleared individually in the raw source
    //   ((DWORD*)v2)[38] = 1176256512;
    //   ((DWORD*)v2)[39] = 6;
    //   return 0;
    // UNRESOLVED: The raw constants 1065353216, 1176256512 and 6 (dword indices 6, 38, 39) are preserved verbatim; their semantic meaning is not defined by this packet.
    // UNRESOLVED: The string at aCubeMts401 is the mesh-format magic only per the caller's strcmp against it in sub_54AC70; the literal bytes are not present in this packet.
    // UNRESOLVED: The effective this pointer at the caller's sub_54E9B0(0) call site is register-supplied (__thiscall) and not visible in the decompiled call, so the exact object stamped is caller-context dependent.
    // UNRESOLVED: The header layouts of the sibling initializer InitializeTextureMtsHeader and of this function use different field indices (55..81/62/63 versus 31..57/38/39); whether they are two views of one struct or two distinct structs is unknown.
    // UNRESOLVED: The layout and purpose of each zeroed header field are unknown; the object type owning them is unknown (owner UnknownObject).
}
