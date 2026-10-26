// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040DC00
// Canonical corpus name: StringPathExtensionManipulation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringPathExtensionManipulation_0040dc00.c

void UnknownObject::BuildPathWithExtensionAndInvoke()
{
    // Builds a file path string and hands it to a callback. Selects a base path from dword_7CE5D0 (falling back to byte_5EA438 when null), concatenates it with the dot-extension string off_5BEB4C into a heap buffer, terminates it, then scans backward from the end for a '.' (46) and truncates the string there to strip any existing extension. Appends the path-separator word_5BEB48 and the extension off_5BEB4C onto the end of the string, invokes FunctionCallWrapper_dbe0 with the result, frees the buffer, and returns the callback's return value. Returns 0 when the allocation fails.
    // GUARD: Select base path: dword_7CE5D0 when non-null, otherwise the default byte_5EA438 [global:0x007CE5D0, global:0x005EA438, source:raw]
    // CALCULATION: Compute v1 = strlen(base path) + 1 and v2 = strlen(off_5BEB4C) + 1; total buffer size is v1 + v2 [global:0x005BEB4C, source:raw]
    // CALL: Allocate the concatenation buffer of v1 + v2 bytes via OperatorNewNhMallocWrapper [callee:0x00587C03, source:raw]
    // GUARD: Return 0 immediately when the allocation failed (null buffer) [source:raw]
    // CALL: Copy the selected base path into the buffer for v6 bytes via sub_587DD0, then place a null terminator at v3[v6] [callee:0x00587DD0, source:raw]
    // LOOP: Walk v7 backward from the end of the copied string while the byte is not '.' (46); when it reaches the buffer start without finding a dot, skip the truncation; otherwise write 0 at the dot to strip the existing extension [source:raw]
    // ASSIGNMENT: Append the path-separator word_5BEB48 (2 bytes) and the extension off_5BEB4C (4 bytes) at the end of the string [global:0x005BEB48, global:0x005BEB4C, source:raw]
    // CALL: Invoke FunctionCallWrapper_dbe0 with the constructed path string and capture its return value [callee:0x0040DBE0, source:raw]
    // CALL: Free the temporary path buffer via FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // RETURN: Return the value returned by FunctionCallWrapper_dbe0 (or 0 on allocation failure) [source:raw]
    // CALL: Invoked by Steward_Restart as part of the restart path building a track/configuration file path [caller:0x004D3CF0, source:raw]

    // Conservative worker pseudocode:
    //   base = dword_7CE5D0 ? dword_7CE5D0 : &byte_5EA438;
    //   v1 = strlen(base) + 1;
    //   v2 = strlen((const char*)&off_5BEB4C) + 1;
    //   buf = OperatorNewNhMallocWrapper(v1 + v2);
    //   if (!buf) return 0;
    //   len = v1 + v2 - 1;
    //   sub_587DD0(buf, base, len);
    //   buf[len] = 0;
    //   p = &buf[strlen(buf)];
    //   if (p > buf) {
    //       while (*p != 46) {
    //           if (--p <= buf) goto append;
    //       }
    //       *p = 0;
    //   }
    //   append:
    //   *(WORD*)&buf[strlen(buf)] = word_5BEB48;
    //   *(DWORD*)&buf[strlen(buf)] = off_5BEB4C;
    //   ret = FunctionCallWrapper_dbe0((int)buf);
    //   FreeWrapper_7bcf(buf);
    //   return ret;
    // UNRESOLVED: The 46 literal is interpreted as the '.' path-extension separator; the packet only states the literal value, not its meaning.
    // UNRESOLVED: word_5BEB48 and off_5BEB4C are assumed to be a path separator and a dot-extension string respectively; their exact contents are not evidenced in the packet.
    // UNRESOLVED: The identity and contract of the callback FunctionCallWrapper_dbe0 are unknown.
    // UNRESOLVED: Whether dword_7CE5D0 is a track path or some other configuration path is not proven by the packet.
}
