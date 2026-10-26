// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B950
// Canonical corpus name: StringCursorReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCursorReset_0048b950.c

void UnknownObject::StringCursorReset()
{
    // Edit-text cursor reset with a mode flag a2. When a2 is non-zero: point the cursor (this+0x2F4) at the buffer start (this+0x2F0), clear the buffer's first byte, then scan the default-string buffer at this+0x1E7 for its terminator; if its length is not 1, reload it via EditBufferStringUpdate. When a2 is zero: scan the current buffer from this+0x2F0 to its terminator, position the cursor at the end, and invoke the vtable entry at +44 with argument 1. Returns the update result (0 in the reload path).
    // ASSIGNMENT: Initialize countdown v3 = -1 before the string-scan loops. [source:raw, function:0x0048B950, abi:lead]
    // GUARD: Branch on mode flag a2: non-zero path clears the buffer and reloads the default; zero path moves the cursor to the current buffer end. [source:raw]
    // ASSIGNMENT: Non-zero mode: set cursor this+0x2F4 to buffer start this+0x2F0 and write 0 to the buffer's first byte, clearing the displayed text. [source:raw, field:this:0x000002F0, field:this:0x000002F4]
    // LOOP: Non-zero mode: scan the default-string buffer at this+0x1E7 until its null terminator, counting down v3. [source:raw]
    // GUARD: Guard: if (-v3 != 2) i.e. the default string is longer than one character, reload it into the edit buffer. [source:raw]
    // CALL: EditBufferStringUpdate(this, default string at this+0x1E7) reloads the edit buffer with the default value. [source:raw, callee:0x0048B810]
    // LOOP: Zero mode: scan the current buffer from this+0x2F0 to its null terminator to find the string end. [source:raw, field:this:0x000002F0]
    // CALCULATION: Zero mode: set cursor this+0x2F4 to buffer start plus the scanned length, i.e. position it after the last character. [source:raw, field:this:0x000002F0, field:this:0x000002F4]
    // CALL: Zero mode: virtual call through the vtable pointer at this+0 (entry at +44) with arguments (this, 1) to refresh the cursor view. [source:raw, field:this:0x00000000]
    // RETURN: Return the reload/virtual-call result, or 0 when the default string was not reloaded. [source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall StringCursorReset(int* this, char a2) {
    //     int v3 = -1;
    //     if (a2) {
    //       _BYTE* v4 = (_BYTE*)this[188];
    //       this[189] = (int)v4;
    //       *v4 = 0;
    //       int result = 0;
    //       do { if (!v3) break; v7 = *((char*)this + 487)++ == 0; --v3; } while (!v7);
    //       if (-v3 != 2) return EditBufferStringUpdate(this, (const char*)this + 487);
    //     } else {
    //       _BYTE* v8 = (_BYTE*)this[188];
    //       do { if (!v3) break; v7 = *v8++ == 0; --v3; } while (!v7);
    //       this[189] = this[188] + -v3 - 2;
    //       return (*(int (__thiscall**)(int*, int))(*(int*)this + 44))(this, 1);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: This is an edit-text control method, but the owning control class is unknown.
    // UNRESOLVED: field:obj:0x0000002C is listed as accessed but has no visible reference in the decompiled source.
    // UNRESOLVED: Purpose of the vtable entry at +44 (called with argument 1) is unknown.
    // UNRESOLVED: The embedded default-string buffer at this+0x1E7 has no dedicated field evidence reference.
}
