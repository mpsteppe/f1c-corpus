// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CDC70
// Canonical corpus name: sub_4CDC70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CDC70_004cdc70.c

void UnknownObject::TrackSurfaceTokenToFloat()
{
    // stdcall: parses a track surface material token into a float. Reads a string token via sub_565520(a2, buffer, 0). If the token begins with a digit (48-57) or '.' (46) it is parsed directly as a float via sub_58850F. Otherwise it walks a linked list headed by a4 (next pointer at +36), compares names with strcmp and returns the float value at +32 on match. On no match (or null list head) it runs an error split/debug log path and returns 0.
    // CALL: Call sub_565520(a2, v7, 0) to read the token string into the 128-byte buffer v7; store the status in v4. [callee:0x00565520, source:raw]
    // GUARD: When v4 is zero (token read failed) return v4 (0) immediately. [source:raw]
    // GUARD: When the first token byte v7[0] is in [48,57] (digit) or equals 46 ('.') treat the token as a numeric literal. [source:raw]
    // CALL: Convert the numeric token to float via sub_58850F(v7), store the result in *a3 and return v4. [callee:0x0058850F, source:raw]
    // LOOP: Walk the linked list starting at a4: compare v7 with the entry name via strcmp; on mismatch follow the next pointer at entry+36; stop when a null next pointer is found. [source:raw]
    // ASSIGNMENT: On a strcmp match, store the entry's float value at entry+32 into *a3 and return v4. [source:raw]
    // CALL: On lookup failure, call StringSplitLoop(1, aDDevF119992002_25, 2231) and, if it returns non-zero, write a debug message via DebugLogWrite(&dword_8AD25C, aCouldNotFindTr). [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3624, global:0x005D37E8, global:0x008AD25C, source:raw]
    // RETURN: Return 0 on the failure path (or when no matching list entry exists). [source:raw]
    // CALL: Called by TrackSurfaceMaterialLoader (0x004CDD80) to resolve a surface token to its numeric value. [caller:0x004CDD80, source:raw]

    // Conservative worker pseudocode:
    //   int TrackSurfaceTokenToFloat(int a1, int a2, float *a3, int a4) {
    //     char buf[128];
    //     int ok = sub_565520(a2, buf, 0);
    //     if (!ok) return ok;
    //     if ((buf[0] >= 48 && buf[0] <= 57) || buf[0] == 46) {
    //       *a3 = sub_58850F(buf);
    //       return ok;
    //     }
    //     int p = a4;
    //     if (a4) {
    //       while (strcmp(buf, (const char *)p)) {
    //         p = *(int *)(p + 36);
    //         if (!p) goto fail;
    //       }
    //       *a3 = *(float *)(p + 32);
    //       return ok;
    //     }
    //   fail:
    //     if (StringSplitLoop(1, aDDevF119992002_25, 2231))
    //       DebugLogWrite(&dword_8AD25C, aCouldNotFindTr);
    //     return 0;
    //   }
    // UNRESOLVED: The linked-list entry layout (name string and float at +32/+36) has no field evidence refs in the packet; offsets are described from the raw source only.
    // UNRESOLVED: Meaning of a1 (unused in the raw source) and the role of the literal 2231 passed to StringSplitLoop are unresolved.
    // UNRESOLVED: The exact identity of the linked list head a4 and the token source a2 are caller-specific.
}
