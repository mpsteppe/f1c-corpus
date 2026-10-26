## __tzset_lk_005c98c9 — MSVC CRT timezone initialization (locked)

**Summary:** Initializes global timezone state from the `TZ` environment variable or the Windows `GetTimeZoneInformation` API. Called under a critical section lock; populates `_timezone` (offset in seconds), `_daylight` (DST flag), `_dstbias`, and `_tzname` (standard/daylight name strings).

**Called by:** LazyInitSingletonWithFlagGuard [structural] (005c989b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d523c | GetTimeZoneInformation | R | Windows API to query system timezone (used when TZ env var absent) |
| 005d529c | WideCharToMultiByte | R | Windows API to convert wide timezone name strings to ANSI multi-byte |
| 005f6fb0 | VarName | R | unknown |
| 00626420 | dword_626420 | RW | Stores timezone offset from UTC in seconds (the `_timezone` CRT global) |
| 00626424 | dword_626424 | W | Stores daylight saving time flag (the `_daylight` CRT global) |
| 00626428 | dword_626428 | W | Stores DST bias offset in seconds (the `_dstbias` CRT global) |
| 006264ac | lpMultiByteStr | R | Buffer for standard timezone abbreviation string (the `_tzname[0]` CRT global, 64 bytes) |
| 006264b0 | off_6264B0 | R | Buffer for daylight timezone abbreviation string (the `_tzname[1]` CRT global, 64 bytes) |
| 006264b8 | dword_6264B8 | W | Reset to -1 on each call; likely timezone-related state flag |
| 006264c8 | dword_6264C8 | W | Reset to -1 on each call; likely timezone-related state flag |
| 007ff1f8 | CodePage | R | System ANSI code page used for WideCharToMultiByte conversion |
| 007ff270 | dword_7FF270 | W | Flag set to 1 when using Windows API path (not TZ env var) |
| 007ff278 | TimeZoneInformation | R | Windows TIME_ZONE_INFORMATION structure populated by GetTimeZoneInformation |
| 007ff27c | byte_7FF27C | R | Field within TimeZoneInformation structure (StandardDate or Bias area) |
| 007ff2be | byte_7FF2BE | R | Field within TimeZoneInformation structure |
| 007ff2cc | byte_7FF2CC | R | Field within TimeZoneInformation structure |
| 007ff2d0 | byte_7FF2D0 | R | Field within TimeZoneInformation structure |
| 007ff312 | byte_7FF312 | R | Field within TimeZoneInformation structure |
| 007ff320 | byte_7FF320 | R | Field within TimeZoneInformation structure |
| 007ff324 | dword_7FF324 | RW | Cached TZ environment variable string pointer; used to detect TZ changes between calls |
| ff00000000005ef3 | byte_FF00000000005EF3 | R | unknown |
| ff00000000005efc | byte_FF00000000005EFC | R | unknown |
| ff00000000005efd | byte_FF00000000005EFD | R | unknown |
| ff00000000005efe | byte_FF00000000005EFE | R | unknown |
| ff00000000005eff | byte_FF00000000005EFF | R | unknown |
| ff00000000005f00 | byte_FF00000000005F00 | R | unknown |
| ff00000000005f01 | byte_FF00000000005F01 | R | unknown |
| ff00000000005f02 | byte_FF00000000005F02 | R | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005beab0 | _strncpy | Copy up to 3 characters to extract timezone abbreviation from TZ string |
| 005bebfe | _atol | Parse numeric offset (hours, minutes, seconds) from TZ string |
| 005c1a4e | _malloc | Allocate buffer to store a copy of the TZ environment variable value |
| 005c1b88 | sub_5C1B88 | Likely `_free` — deallocates the previously cached TZ string before replacing it |
| 005c5210 | _strlen | Measure length of TZ string to allocate correctly sized buffer |
| 005c52b4 | CriticalSectionLazyInitEnter [structural] | Acquire critical section (lock 12) to serialize timezone initialization |
| 005c5315 | __unlock | Release critical section (unlock 12) after timezone state update |
| 005c6e40 | _strcmp | Compare new TZ value against cached value to detect changes |
| 005c6f50 | _strcpy | Copy TZ environment variable value into newly allocated buffer |
| 005ce695 | _getenv | Retrieve the `TZ` environment variable value |

**Guard conditions:**

1. **TZ env var absent** (`!v0` after `getenv("TZ")`): Takes Windows API path — calls `GetTimeZoneInformation`, computes offset from `Bias`/`StandardBias`/`DaylightBias`, converts timezone names via `WideCharToMultiByte`. BLOCKED if `GetTimeZoneInformation` returns -1 (early return). PASSES otherwise.

2. **TZ env var present but empty** (`*v0 == 0`): SKIP — unlocks and returns without updating state. BLOCKED (no re-parse).

3. **TZ env var present and unchanged** (`dword_7FF324 != NULL && strcmp(v0, dword_7FF324) == 0`): SKIP — unlocks and returns. BLOCKED (cached value matches).

4. **TZ env var present, non-empty, and new/changed** (`*v0 && (!dword_7FF324 || strcmp(v0, dword_7FF324) != 0)`): PASSES — parses TZ string:
   - Extracts first 3 chars as standard timezone name into `lpMultiByteStr`
   - Checks 4th char for `-` sign (negative UTC offset) — sets `v8 = 1`
   - Parses offset: hours × 3600, optional `:MM` minutes × 60, optional `:SS` seconds
   - Negates offset if `v8` was set
   - If remaining characters exist after offset, copies next 3 chars as DST name into `off_6264B0`
   - If no remaining chars, zeroes DST name buffer

5. **Windows API path, name conversion failure** (`WideCharToMultiByte` returns 0 or `UsedDefaultChar` is TRUE): Zero-terminates the name buffer at position 0 (empty string).

6. **Windows API path, name conversion success**: Null-terminates at position 63 (last byte of 64-byte buffer).

**String literals referenced (deterministic):**

- `,db`
- `,db`
- `,db`
- `,db`
- `,db`
- `ldb`
- `ldb`
- `ldb`
- `ldb`
- `ldb`
