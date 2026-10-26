// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049DA60
// Canonical corpus name: TimestampedRenderStringUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimestampedRenderStringUpdate_0049da60.c

void UnknownObject::TimestampedRenderStringUpdate()
{
    // HUD text-row updater. Always renders a dual-text baseline via DualTextDisplay from three globals, then, when this[2] (offset 0x8) is non-null, formats a value string with sub_49C8F0 and a label string with sub_49C960 into a 64-byte stack buffer and renders both with StringFormatAndRender at a Y position offset from dword_5CCBBC + dword_5CCBB8. Returns the guard value when the render path is skipped.
    // ASSIGNMENT: Load globals into locals: v1 = dword_5CCBB8, v3 = dword_7CE238, v4 = dword_5CCBC0. [global:0x005CCBB8, global:0x007CE238, global:0x005CCBC0, source:raw]
    // CALL: Always render the dual-text baseline: DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8). [callee:0x0049E410, global:0x005CCBC0, global:0x007CE238, global:0x005CCBB8, source:raw]
    // ASSIGNMENT: Read this[2] (offset 0x8) into result; this value also serves as the render guard. [field:this:0x00000008, source:raw]
    // GUARD: Guard on result (this[2], offset 0x8) being non-zero; the string render path runs only then. [field:this:0x00000008, source:raw]
    // CALCULATION: Compute the Y position as v6 = dword_5CCBBC + dword_5CCBB8. [global:0x005CCBBC, global:0x005CCBB8, source:raw]
    // CALL: Initialize/format the 64-byte value buffer: sub_49C8F0(buffer, 64). [callee:0x0049C8F0, source:raw]
    // CALL: Render the value row: StringFormatAndRender(buffer, v4, v6, this[2], *(this[5] + 84), 1), reading the label source through this+0x14 (this[5]). [callee:0x0049F6A0, field:this:0x00000014, field:this:0x00000068, source:raw]
    // CALL: Finalize/format the label buffer: sub_49C960(buffer, 64). [callee:0x0049C960, source:raw]
    // RETURN: Render the label row and return its result: StringFormatAndRender(buffer, v3, v6, this[2], *(this[5] + 84), 0). [callee:0x0049F6A0, field:this:0x00000014, field:this:0x00000068, source:raw]
    // RETURN: When the guard fails, return the stored result (this[2], which was zero). [source:raw]

    // Conservative worker pseudocode:
    //   int TimestampedRenderStringUpdate(int* this) {
    //     int v1 = dword_5CCBB8;
    //     int v3 = dword_7CE238;
    //     int v4 = dword_5CCBC0;
    //     DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8);
    //     int result = this[2];
    //     if (result) {
    //       int v6 = dword_5CCBBC + v1;
    //       char buffer[64];
    //       sub_49C8F0(buffer, 64);
    //       StringFormatAndRender(buffer, v4, v6, this[2], *(int*)(this[5] + 84), 1);
    //       sub_49C960(buffer, 64);
    //       return StringFormatAndRender(buffer, v3, v6, this[2], *(int*)(this[5] + 84), 0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Globals dword_7CE048 and unk_7CE234 are listed in the packet globals but are not referenced by this function's raw source; their role here is unknown.
    // UNRESOLVED: Semantics of this[2] (render surface/texture) and of the sub-struct read through this[5] plus 84 are owner-dependent.
    // UNRESOLVED: Exact meaning of the dual-text / StringFormatAndRender numeric arguments is not resolvable from this function alone.
    // UNRESOLVED: This function is called by sub_49D5D0; that caller's role is out of scope here.
}
