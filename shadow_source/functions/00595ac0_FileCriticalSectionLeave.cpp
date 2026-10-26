// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595AC0
// Canonical corpus name: FileCriticalSectionLeave
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileCriticalSectionLeave_00595ac0.c

void UnknownObject::FileCriticalSectionLeave()
{
    // Releases the per-file critical section for file index a1. The section is embedded at offset +12 of a 36-byte record inside the bucket dword_8D4920[a1 >> 5]; the entry within the bucket is selected by a1 & 0x1F. Called from multiple file-I/O sites as the leave half of a guarded per-file access.
    // CALCULATION: Compute the per-file critical section address: dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 12, i.e. bucket = a1/32, record = a1%32, record stride 36 bytes, critical section at record offset +12. [global:0x008D4920, source:raw]
    // CALL: Call LeaveCriticalSection on the computed LPCRITICAL_SECTION to release the lock guarding file index a1. [global:0x0059E170, source:raw]
    // CALL: Invoked from nine file-I/O call sites (sub_58C331, sub_58C724, sub_58C9B4, sub_58E22B, sub_592891, sub_595AF9, sub_595F11, sub_59B650, sub_59B760) as the common leave path after file operations. [caller:0x0058C331, caller:0x0058C724, caller:0x0058C9B4, caller:0x0058E22B, caller:0x00592891, caller:0x00595AF9, caller:0x00595F11, caller:0x0059B650, caller:0x0059B760]

    // Conservative worker pseudocode:
    //   // a1 = file index; 32 records per bucket, 36-byte record, CRITICAL_SECTION at +12
    //   LPCRITICAL_SECTION cs = (LPCRITICAL_SECTION)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 12);
    //   LeaveCriticalSection(cs);
    // UNRESOLVED: a1 is a file/index identifier; the exact resource table it indexes is unresolved here.
    // UNRESOLVED: The +12 offset and 36-byte stride imply an embedded CRITICAL_SECTION inside a larger per-file record; the record layout is unknown.
    // UNRESOLVED: Bucket base array dword_8D4920 allocation/ownership is unresolved.
}
