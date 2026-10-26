// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4360
// Canonical corpus name: StreamReadWithScale
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamReadWithScale_004b4360.c

void UnknownObject::StreamReadWithScale()
{
    // __stdcall stream-value reader with conditional scaling. Copies input a3 into local v3, then calls FileWriteWithBackendDispatch to populate a 4-byte header at v3. Based on header bits it either stores the incoming float a2 directly at v3+4 or scales a single byte read from the stream by the global double dbl_5ACD28 (0.0001670000056037679) added to a2 before storing at v3+4. Finally it reads a payload of (header >> 8) & 0x3FF bytes into v3+8 and returns 0. Despite the callee name, the surrounding reads indicate backend read/dispatch behavior.
    // ASSIGNMENT: Copy input parameter a3 into local v3 (esi). [source:raw]
    // CALL: Call FileWriteWithBackendDispatch(a3, 4); the 4-byte header later tested at v3 is populated by this call. [callee:0x00566C00, source:raw]
    // GUARD: Branch on header bits: when (*(DWORD*)v3 & 0xE0000000) != 0x20000000 or (*(DWORD*)v3 & 0xFC0000) != 0, store a2 raw; otherwise treat the value as a scaled-byte form. [source:raw]
    // ASSIGNMENT: In the non-scaled branch, store the float a2 directly into *(float*)(v3 + 4). [source:raw]
    // CALL: In the scaled branch, call FileWriteWithBackendDispatch(&a3, 1) to read a single byte into a3. [callee:0x00566C00, source:raw]
    // CALCULATION: Truncate to unsigned byte: a3 = (unsigned __int8)a3. [source:raw]
    // CALCULATION: Compute the scaled value: (double)(unsigned __int8)a3 * dbl_5ACD28 + a2, where dbl_5ACD28 is the global double 0.0001670000056037679. [global:0x005ACD28, source:raw]
    // ASSIGNMENT: Store the scaled result into *(float*)(v3 + 4). [source:raw]
    // CALL: Call FileWriteWithBackendDispatch(v3 + 8, (*(_DWORD*)v3 >> 8) & 0x3FF) to read a payload of (header >> 8) & 0x3FF bytes into v3 + 8. [callee:0x00566C00, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   char StreamReadWithScale(int a1, float a2, int a3) {
    //     int v3 = a3;
    //     FileWriteWithBackendDispatch(v3, 4);
    //     if ((*(int*)v3 & 0xE0000000) != 0x20000000 || (*(int*)v3 & 0xFC0000) != 0)
    //       *(float*)(v3 + 4) = a2;
    //     else {
    //       FileWriteWithBackendDispatch(&a3, 1);
    //       a3 = (unsigned __int8)a3;
    //       *(float*)(v3 + 4) = (double)(unsigned __int8)a3 * dbl_5ACD28 + a2;
    //     }
    //     FileWriteWithBackendDispatch(v3 + 8, (*(int*)v3 >> 8) & 0x3FF);
    //     return 0;
    //   }
    // UNRESOLVED: The callee is named FileWriteWithBackendDispatch but reads stream data here; its actual backend read/write direction is unknown.
    // UNRESOLVED: Semantics of the bitmask selection (0xE0000000 vs 0x20000000, 0xFC0000) between raw-float and scaled-byte storage are only structurally inferred.
    // UNRESOLVED: Meaning of the buffer layout offsets 0 (header), 4 (value), 8 (payload) is unknown.
    // UNRESOLVED: Parameter a1 is unused in this function.
    // UNRESOLVED: What the 0x3FF payload size corresponds to (max 1023 bytes) is unknown.
}
