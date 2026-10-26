// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588D95
// Canonical corpus name: sub_588D95
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588D95_00588d95.c

void UnknownObject::SessionCreateOrReinit()
{
    // Creates or reinitializes a session structure. Lazily allocates an 849-byte buffer into dword_5E64F4 when it is null, clears its first byte, and calls a setup routine with a session-flag argument. Then iterates a subsystem setup table from off_5E6500 to off_5E6530 in three-entry steps, appending a ";" delimiter and calling a compare routine on each table entry; a matching entry clears the match flag. When a match occurred the session buffer is returned; otherwise the buffer is torn down, dword_5E64F4 cleared to 0, and the fallback pointer off_5E650C returned. Called by sub_588A34.
    // GUARD: If dword_5E64F4 is null, lazily allocate the 849-byte session buffer with MallocWrapperForNhMalloc and store it back into dword_5E64F4. [global:0x005E64F4, callee:0x0058A935, source:raw]
    // ASSIGNMENT: Clear the first byte of the session buffer. [global:0x005E64F4, source:raw]
    // CALL: BatchFunctionCallOverVarargs(dword_5E64F4, 3) performs the initial session setup call. [callee:0x00588F66, global:0x005E64F4, source:raw]
    // LOOP: Iterate the subsystem setup table from off_5E6500 to off_5E6530, advancing three pointer entries (12 bytes) per step. [global:0x005E6500, global:0x005E6530, source:raw]
    // CALL: sub_58FCB0(dword_5E64F4, ";") appends the ";" delimiter to the session buffer. [callee:0x0058FCB0, global:0x005E64F4, source:raw]
    // CALCULATION: Load compare value v5 from the table entry three slots ahead (v2[3]). [global:0x005E6500, source:raw]
    // CALL: sub_58FB90(*v3, v5) compares the current table entry against the loaded value; a non-zero result clears the match flag v1. [callee:0x0058FB90, global:0x005E6500, source:raw]
    // CALL: BatchFunctionCallOverVarargs(dword_5E64F4, 3) runs the setup routine on each iteration. [callee:0x00588F66, global:0x005E64F4, source:raw]
    // GUARD: If the match flag v1 stayed set (no table entry matched), fall through to teardown; otherwise return the session buffer. [global:0x005E64F4, source:raw]
    // CALL: sub_58AA6F(dword_5E64F4) tears down the session buffer, then dword_5E64F4 is cleared to 0. [callee:0x0058AA6F, global:0x005E64F4, source:raw]
    // RETURN: Return the session buffer on match, otherwise the fallback pointer off_5E650C. [global:0x005E64F4, global:0x005E650C, function:0x00588D95, source:raw]
    // CALL: Invoked by sub_588A34. [caller:0x00588A34, source:raw]

    // Conservative worker pseudocode:
    //   if (!dword_5E64F4)
    //       dword_5E64F4 = MallocWrapperForNhMalloc(849);
    //   byte0(dword_5E64F4) = 0;
    //   BatchFunctionCallOverVarargs(dword_5E64F4, 3);
    //   v1 = 1;
    //   for (v2 = v3 = &off_5E6500; (int)v2 < (int)&off_5E6530; v2 += 3, v3 = v2) {
    //       sub_58FCB0(dword_5E64F4, ";");
    //       if (sub_58FB90(*v3, v2[3]))
    //           v1 = 0;
    //       BatchFunctionCallOverVarargs(dword_5E64F4, 3);
    //   }
    //   if (v1) {
    //       sub_58AA6F(dword_5E64F4);
    //       dword_5E64F4 = 0;
    //       return off_5E650C;
    //   }
    //   return dword_5E64F4;
    // UNRESOLVED: Globals asc_5B8C74 (format specifier) and asc_5C30AC (delimiter) are flagged read but never appear in the raw decompiled source; no packet evidence maps them to the ";" literal passed to sub_58FCB0.
    // UNRESOLVED: off_5E64FC is flagged read but the raw iteration begins at off_5E6500; its role is unestablished.
}
