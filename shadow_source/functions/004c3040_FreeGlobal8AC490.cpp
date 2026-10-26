// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3040
// Canonical corpus name: sub_4C3040
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C3040_004c3040.c

void UnknownObject::FreeGlobal8AC490()
{
    // Teardown wrapper: if the global pointer dword_8AC490 is non-zero, free it through FreeWrapper_7bcf and clear the global to null; otherwise just return the stored value.
    // GUARD: Load dword_8AC490 into result and branch on it; proceed only while the global pointer is non-null. [function:0x004C3040, source:raw]
    // CALL: Invoke FreeWrapper_7bcf with the stored global pointer dword_8AC490 cast to LPVOID, storing its return value into result. [function:0x004C3040, source:raw]
    // ASSIGNMENT: Set dword_8AC490 to null after the free completes. [function:0x004C3040, source:raw]
    // RETURN: Return result, which is the freed wrapper result in the guarded path and the original global value in the early path. [function:0x004C3040, source:raw]

    // Conservative worker pseudocode:
    //   result = dword_8AC490;
    //   if (dword_8AC490) { result = FreeWrapper_7bcf((LPVOID)dword_8AC490); dword_8AC490 = 0; }
    //   return result;
    // UNRESOLVED: The raw source operates on dword_8AC490 and FreeWrapper_7bcf, but the packet globals list names global:0x008AC368, which does not appear in the raw source; the address discrepancy is unresolved.
    // UNRESOLVED: Purpose of FreeWrapper_7bcf and the allocation behind dword_8AC490 is unknown.
}
