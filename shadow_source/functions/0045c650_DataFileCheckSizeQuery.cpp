// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C650
// Canonical corpus name: DataFileCheckSizeQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DataFileCheckSizeQuery_0045c650.c

void UnknownObject::DataFileCheckSizeQuery()
{
    // Data-file size query. Initializes an output size accumulator to zero, optionally adds a value extracted by UtilityFunction_8a60 using the selector byte at this+0x1, copies the input path into a bounded local buffer, strips any trailing '.' extension, then scans a global array (dword_8AC490, stride 396) for an entry whose name at offset 4 matches the stripped path. On match, adds the entry's size field at offset 392 to the accumulator. Returns a success flag (false when the UtilityFunction_8a60 extraction fails, or when no entry matches before the scan counter reaches dword_8AC488). The array-as-scene-descriptor interpretation is DERIVED from the existing analysis fill and is not independently proven.
    // ASSIGNMENT: *a3 = 0 — output size accumulator initialized to zero. [source:raw]
    // ASSIGNMENT: v9 = 1 — success flag defaults to true. [source:raw]
    // CALL: UtilityFunction_8a60(this[1], &v10) — extract a parameter value into v10 using the selector byte at this+0x1. [callee:0x00568A60, field:this:0x00000001, source:raw]
    // GUARD: Extraction result gate — when UtilityFunction_8a60 returns true, add v10 to the output size; otherwise the success flag is cleared. [callee:0x00568A60, source:raw]
    // CALCULATION: *a3 += v10 — accumulate the extracted size into the output. [source:raw]
    // ASSIGNMENT: v9 = 0 — extraction failed; mark the function result false. [source:raw]
    // CALL: sub_587DD0(v11, a2, 511) — copy the input path a2 into the local buffer v11, bounded to 511 characters. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: v11[511] = 0 — force null termination of the copied buffer. [source:raw]
    // CALCULATION: strlen(v11) — v3 set to the pointer at the end of the copied string. [source:raw]
    // GUARD: v3 > v11 — only attempt the extension strip when the copied string is non-empty. [source:raw]
    // LOOP: Scan v3 backward for '.' (ASCII 46); terminate at the dot when found, otherwise skip the strip. [source:raw]
    // ASSIGNMENT: *v3 = 0 — truncate the string at the extension dot, stripping the trailing extension. [source:raw]
    // ASSIGNMENT: v4 = dword_8AC488, v5 = 0 — load the entry count and reset the scanned counter. [global:0x008AC488, source:raw]
    // GUARD: dword_8AC488 > 0 — only scan the array when it contains at least one entry. [global:0x008AC488, source:raw]
    // LOOP: for i = 0 stepping by 396 — iterate array entries by stride. [source:raw]
    // CALCULATION: v7 = i + dword_8AC490 — compute the current entry base pointer. [global:0x008AC490, source:raw]
    // CALL: sub_588410(v11, entry + 4) — compare the stripped filename against the entry name at offset 4. [callee:0x00588410, global:0x008AC490, source:raw]
    // GUARD: sub_588410 returns 0 (name match) — exit the loop to accumulate the size; a non-zero result continues scanning. [callee:0x00588410, source:raw]
    // GUARD: ++v5 >= v4 — all entries scanned without a match; return the success flag early. [global:0x008AC488, source:raw]
    // CALCULATION: *a3 += *(entry + 392) — add the matched entry's size field at offset 392 to the output. [global:0x008AC490, source:raw]
    // RETURN: Return v9 — the success flag reflecting the extraction result and whether a matching entry was found. [source:raw]

    // Conservative worker pseudocode:
    //   *a3 = 0;
    //   char ok = 1;
    //   if (UtilityFunction_8a60(this[1], &extracted_size))
    //       *a3 += extracted_size;
    //   else
    //       ok = 0;
    //   char filename_buf[512];
    //   sub_587DD0(filename_buf, a2, 511);
    //   filename_buf[511] = 0;
    //   char *p = filename_buf + strlen(filename_buf);
    //   if (p > filename_buf) {
    //       while (*p != '.') {
    //           if (--p <= filename_buf) goto scan;
    //       }
    //       *p = 0;
    //   }
    //   scan:
    //   int entry_count = dword_8AC488;
    //   int scanned = 0;
    //   if (entry_count > 0) {
    //       for (int i = 0; ; i += 396) {
    //           char *entry_ptr = (char*)dword_8AC490 + i;
    //           if (!sub_588410(filename_buf, entry_ptr + 4))
    //               break;
    //           if (++scanned >= entry_count)
    //               return ok;
    //       }
    //       *a3 += *(int*)((char*)dword_8AC490 + i + 392);
    //   }
    //   return ok;
    // UNRESOLVED: Semantic role of the dword_8AC490 array entries (scene descriptors per existing-analysis prose) and offset 392 as a file size are DERIVED, not independently proven.
    // UNRESOLVED: Semantics of the UtilityFunction_8a60 extraction (selector byte at this+0x1) and how v10 relates to a file size are unresolved.
    // UNRESOLVED: No class-ownership evidence: callers sub_45C0C0 and ParticleSoundEffectSpawner were not examined in this packet.
    // UNRESOLVED: The legacy ABI name Data_File_Check_Size_Query identifies the function but provides no owning class.
}
