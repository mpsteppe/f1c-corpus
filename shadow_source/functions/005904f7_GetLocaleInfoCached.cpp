// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005904F7
// Canonical corpus name: sub_5904F7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5904F7_005904f7.c

void UnknownObject::GetLocaleInfoCached()
{
    // Locale info lookup with a cached table. Binary-searches a static table of locale IDs (dword_5E6D60, 11 dwords per entry) for the requested Locale; when found, returns one of several per-entry cached strings selected by LCType (1, 3, 7, 0xB, 0x1001, 0x1002, 0x1004). Copies the cached string into lpLCData via sub_587DD0 with a length limit of cchData-1, NUL-terminates, and returns 1. Any miss (locale not found, unsupported LCType, null cached pointer, or cchData below 1) falls back to the Win32 GetLocaleInfoA API.
    // LOOP: Binary search over the locale table: window bounds seeded to v4=0 and v5=26, midpoint dword read from dword_5E6D60 at index 11*v6; narrows the window by Locale comparison. [global:0x005E6D60, source:raw]
    // GUARD: When the search window collapses (v4 > v5) the locale is not cached; fall back to GetLocaleInfoA. [global:0x0059E13C, source:raw]
    // STATE_TRANSITION: Switch on LCType to select the cached string source: case 1 reads from a040a (44*v6), case 3 from unk_5E6D70, case 7 from unk_5E6D78, case 0xB from unk_5E6D7C, case 0x1001 from off_5E6D6C (11*v6), case 0x1002 from off_5E6D74, case 0x1004 from a1252; default falls back to GetLocaleInfoA. [global:0x005E6D64, global:0x005E6D70, global:0x005E6D78, global:0x005E6D7C, global:0x005E6D6C, global:0x005E6D74, global:0x005E6D84, global:0x0059E13C, source:raw]
    // GUARD: When the selected cached pointer is null or cchData is below 1, fall back to GetLocaleInfoA. [global:0x0059E13C, source:raw]
    // CALL: Copy at most cchData-1 bytes of the cached string into lpLCData via sub_587DD0. [callee:0x00587DD0]
    // ASSIGNMENT: NUL-terminate lpLCData at index cchData-1 and return 1. [source:raw]
    // RETURN: Return the GetLocaleInfoA result on any fallback path. [global:0x0059E13C, source:raw]

    // Conservative worker pseudocode:
    //   int GetLocaleInfoCached(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData) {
    //     int lo = 0, hi = 26;
    //     for (;;) {
    //       int mid = (lo + hi) / 2;
    //       unsigned int key = dword_5E6D60[11 * mid];
    //       if (Locale == key) {
    //         char* v9 = 0;
    //         switch (LCType) {
    //           case 1:   v9 = &a040a[44 * mid]; break;
    //           case 3:   v9 = (char*)&unk_5E6D70 + 44 * mid; break;
    //           case 7:   v9 = (char*)&unk_5E6D78 + 44 * mid; break;
    //           case 0xB: v9 = (char*)&unk_5E6D7C + 44 * mid; break;
    //           case 0x1001: v9 = (&off_5E6D6C)[11 * mid]; break;
    //           case 0x1002: v9 = (&off_5E6D74)[11 * mid]; break;
    //           case 0x1004: v9 = &a1252[44 * mid]; break;
    //           default: return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
    //         }
    //         if (!v9 || cchData < 1) return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
    //         sub_587DD0(lpLCData, v9, cchData - 1);
    //         lpLCData[cchData - 1] = 0;
    //         return 1;
    //       }
    //       if (Locale >= key) lo = mid + 1; else hi = mid - 1;
    //       if (lo > hi) return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
    //     }
    //   }
    // UNRESOLVED: Table entry layout (11 dwords per locale with 44-byte per-entry string slots) is only evidenced through the indexing arithmetic, not by a struct definition.
    // UNRESOLVED: The LCType values 1, 3, 7, 0xB, 0x1001, 0x1002, 0x1004 map to specific Win32 locale data types but the cached semantics are not evidenced per column.
    // UNRESOLVED: Table size bound (v5=26) is a hard-coded count with no evidenced table-length symbol.
}
