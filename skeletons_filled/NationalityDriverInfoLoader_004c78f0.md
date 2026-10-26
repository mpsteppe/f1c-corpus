## NationalityDriverInfoLoader_004c78f0 — Nationality/career driver info loader

**Summary:** Loads driver nationality info, name, short/long descriptions, and abbreviation from a data array (indexed by a2). Sets the driver's full name, nationality display string, short description, long description, abbreviation code, and nationality flag path. Stores driver index at +0x4898.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47F230 (0047f230), AIDriverCountSetup (004bfd90), sub_4C0850 (004c0850), TwoCallDelegation (004c7b20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4677 | RW | 0 | null terminator byte for nationality path buffer |
| this | 0x46B7 | RW | 0 | null terminator byte for short description buffer |
| this | 0x46F7 | RW | 0 | null terminator byte for long description buffer |
| this | 0x4898 | RW | — | driver index stored from parameter a2 |

**Written-by note (persistence):**
- this 0x4677: set to 0 as string terminator; persists
- this 0x46B7: set to 0 as string terminator; persists
- this 0x46F7: set to 0 as string terminator; persists
- this 0x4898: written unconditionally with driver index; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c73b8 | aNationality | R | aNationality [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c6980 | SetDriverName | set driver full name and derive abbreviation |
| 004c69b0 | ShortStringSet | set short string (abbreviation code) from nationality data entry |
| 00567970 | DataEntryAccessor | access data entry by index to retrieve nationality string |
| 005679c0 | StringKeyedLinkedListSearch | search linked list for "Nationality" section |
| 00568210 | AudioChannelStop | validate driver name is non-empty (used as boolean check) |
| 00587dd0 | sub_587DD0 | bounded string copy (strncpy-like) |

**Guard conditions:** Guard: if AudioChannelStop(this+17952) (driver name check) succeeds, look up nationality data section and copy nationality display string. If name is empty or section missing, fall back to default path byte_5EA438.
