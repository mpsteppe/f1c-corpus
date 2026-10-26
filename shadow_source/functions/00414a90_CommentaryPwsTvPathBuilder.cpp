// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414A90
// Canonical corpus name: sub_414A90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_414A90_00414a90.c

void UnknownObject::CommentaryPwsTvPathBuilder()
{
    // Builds and validates commentary file paths in pws and tv subdirectories. Resolves the driver-name string from *this and the season directory/name globals dword_5EC3D8/dword_5EC428 (each with byte_5EA438 as the null fallback), formats a directory prefix, then appends the TB/TE tokens and the extension strings at off_5C23CC/off_5C23C8. For each candidate path it checks existence via FilePathExtensionCheck against slots this+3, this+8, this+13, this+18 (pws block) and this+23, this+28, this+33, this+38 (tv block), dispatching matching slots to sub_417640 (TB/TE commentary lookup) or sub_417AF0 (extension lookup) with this[2] as the index argument and a block flag 0/1. Called by NameListBuilderFromVehicleArray (0x004159B0).
    // ASSIGNMENT: Resolve the base path components for the pws prefix: the driver name from *this (this+0) falling back to byte_5EA438 when null, dword_5EC428 falling back to byte_5EA438, and dword_5EC3D8 falling back to byte_5EA438. [field:this:0x00000000, global:0x005EA438, global:0x005EC428, global:0x005EC3D8, source:raw]
    // CALL: Format the pws directory prefix into v12 with StringFormatWithBufferOverflowCheck using the aSSSPwsS format string. [callee:0x0058815F, global:0x005C23D8, source:raw]
    // CALL: Append the TB token (aTb) to the prefix via the aSS append format, producing the first candidate path in v11. [callee:0x0058815F, global:0x005BE860, global:0x005C23D4, source:raw]
    // GUARD: When FilePathExtensionCheck confirms the first pws path against the this+3 slot, call sub_417640(this+3, this[2], 0, 1) to run the commentary lookup for that slot. [callee:0x00414900, callee:0x00417640, field:this:0x00000008, source:raw]
    // CALL: Append the TE token (aTe), check the this+8 slot via FilePathExtensionCheck, and on match call sub_417640(this+8, this[2], 0, 0). [callee:0x0058815F, global:0x005BE860, global:0x005C23D0, callee:0x00414900, callee:0x00417640, field:this:0x00000008, source:raw]
    // CALL: Append the extension string at off_5C23CC, check the this+13 slot via FilePathExtensionCheck, and on match call sub_417AF0(this+13, this[2], 0, 1). [callee:0x0058815F, global:0x005BE860, global:0x005C23CC, callee:0x00414900, callee:0x00417AF0, field:this:0x00000008, source:raw]
    // CALL: Append the extension string at off_5C23C8, check the this+18 slot via FilePathExtensionCheck, and on match call sub_417AF0(this+18, this[2], 0, 0). [callee:0x0058815F, global:0x005BE860, global:0x005C23C8, callee:0x00414900, callee:0x00417AF0, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Resolve the base path components for the tv prefix: the driver name from *this (this+0) falling back to byte_5EA438 when null, dword_5EC428 falling back to byte_5EA438, and dword_5EC3D8 falling back to byte_5EA438. [field:this:0x00000000, global:0x005EA438, global:0x005EC428, global:0x005EC3D8, source:raw]
    // CALL: Format the tv directory prefix into v12 with StringFormatWithBufferOverflowCheck using the aSSSTvS format string. [callee:0x0058815F, global:0x005C23B8, source:raw]
    // CALL: Append the TB token (aTb), check the this+23 slot via FilePathExtensionCheck, and on match call sub_417640(this+23, this[2], 1, 1). [callee:0x0058815F, global:0x005BE860, global:0x005C23D4, callee:0x00414900, callee:0x00417640, field:this:0x00000008, source:raw]
    // CALL: Append the TE token (aTe), check the this+28 slot via FilePathExtensionCheck, and on match call sub_417640(this+28, this[2], 1, 0). [callee:0x0058815F, global:0x005BE860, global:0x005C23D0, callee:0x00414900, callee:0x00417640, field:this:0x00000008, source:raw]
    // CALL: Append the extension string at off_5C23CC, check the this+33 slot via FilePathExtensionCheck, and on match call sub_417AF0(this+33, this[2], 1, 1). [callee:0x0058815F, global:0x005BE860, global:0x005C23CC, callee:0x00414900, callee:0x00417AF0, field:this:0x00000008, source:raw]
    // CALL: Append the extension string at off_5C23C8, check the this+38 slot via FilePathExtensionCheck, and on match call sub_417AF0(this+38, this[2], 1, 0). [callee:0x0058815F, global:0x005BE860, global:0x005C23C8, callee:0x00414900, callee:0x00417AF0, field:this:0x00000008, source:raw]
    // RETURN: Return 0 unconditionally after processing both the pws and tv path blocks. [function:0x00414A90, source:raw]

    // Conservative worker pseudocode:
    //   build pws prefix from driver-name / dword_5EC428 / dword_5EC3D8 (byte_5EA438 fallbacks)
    //   for each append token (TB, TE, off_5C23CC, off_5C23C8) at slots this+3/8/13/18:
    //     if FilePathExtensionCheck(candidate, slot): sub_417640 or sub_417AF0 (slot, this[2], 0, flag)
    //   build tv prefix the same way
    //   for each append token at slots this+23/28/33/38:
    //     if FilePathExtensionCheck(candidate, slot): sub_417640 or sub_417AF0 (slot, this[2], 1, flag)
    //   return 0
    // UNRESOLVED: The exact strings at off_5C23CC and off_5C23C8 (file extensions) are not recovered from this packet.
    // UNRESOLVED: Whether the TE and TB tokens describe commentary text blocks or file extensions is inferred from the fill naming, not packet-confirmed.
    // UNRESOLVED: dword_5EA5E8 is listed as a referenced global but never appears in the rendered raw source; its role here is unresolved.
}
