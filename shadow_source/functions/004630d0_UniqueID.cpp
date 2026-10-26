// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004630D0
// Canonical corpus name: UniqueID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UniqueID_004630d0.c

void UnknownObject::UniqueID()
{
    // Validates and retrieves a 128-byte unique identifier. Queries the sub-object pointed to at obj+0x3FB8 (reached through the primary pointer at this+0x0) via VTableQueryWithStackBufferResult, then runs a COM check on the resulting handle. When the COM check passes, expects a 128-byte copy into the caller-provided buffer and returns true only if the copy consumed exactly 128 bytes; otherwise returns false. Always releases the queried sub-object via VTableCallViaOffset0x7c before returning.
    // CALL: Read the primary pointer at this+0x0, then load the sub-object pointer at obj+0x3FB8 and call VTableQueryWithStackBufferResult on it, storing the result handle in v4. [field:this:0x00000000, field:obj:0x00003FB8, callee:0x0057A880, source:raw]
    // GUARD: Guard on COMVTableCallVia0xc4(v4): when it returns non-zero the identifier-copy block is skipped and the function falls through to the sub-object release, then returns false. [callee:0x0057A8E0, source:raw]
    // ASSIGNMENT: Set the expected size v6 = 128 (byte count of the unique identifier) before the copy. [source:raw]
    // CALL: Copy the 128-byte unique identifier from the queried sub-object into the caller buffer a2 via ByteAlignedMemoryCopyFromStruct(a2, &v6). [callee:0x0057A230, source:raw]
    // ASSIGNMENT: Set the result v3 = (v6 == 128), i.e. true only when the copy wrote exactly 128 bytes. [source:raw]
    // CALL: Release/cleanup the queried sub-object: call VTableCallViaOffset0x7c with the sub-object pointer at obj+0x3FB8 and the query handle v4. [field:obj:0x00003FB8, callee:0x0057A8B0, source:raw]
    // RETURN: Return v3: true when the COM check passed and the copy consumed exactly 128 bytes, false otherwise. [source:raw]
    // CALL: Called by ClientGridDisplayTimer (0x00460380), WeatherSurfaceUpdate (0x004628A0), AutoJoinRetryLoop (0x004637A0) and MultiplayerSessionJoinHandler (0x0046DE10) to validate/read the unique identifier. [caller:0x00460380, caller:0x004628A0, caller:0x004637A0, caller:0x0046DE10, source:raw]

    // Conservative worker pseudocode:
    //   bool UniqueID(void *this, int outBuffer) {
    //     bool ok = false;
    //     int handle = VTableQueryWithStackBufferResult(*(_DWORD *)(*(_DWORD *)this + 0x3FB8));
    //     if (!COMVTableCallVia0xc4(handle)) {
    //       int size = 128;
    //       ByteAlignedMemoryCopyFromStruct(outBuffer, &size);
    //       ok = (size == 128);
    //     }
    //     VTableCallViaOffset0x7c(*(_DWORD *)(*(_DWORD *)this + 0x3FB8), handle);
    //     return ok;
    //   }
    // UNRESOLVED: Identity and payload semantics of the 128-byte unique identifier are unknown; the queried sub-object at obj+0x3FB8 is opaque here.
    // UNRESOLVED: Exact meaning of the COMVTableCallVia0xc4 result (validity vs error code) and whether VTableCallViaOffset0x7c performs a release, reset or other cleanup are unresolved.
    // UNRESOLVED: Whether the caller buffer a2 is guaranteed 128 bytes and how v6 is interpreted as an in/out size by ByteAlignedMemoryCopyFromStruct are unresolved.
}
