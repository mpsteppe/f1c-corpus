## NetworkMessageEventComparisonWithShortMasking_0057b840 — MatchNetworkMessageEventToQuery

**Summary:** Compares network event structure (referenced by this[7]) against two-component query key from a2. Two alternative match patterns within the event are tried; returns true if either matches.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50), NetworkReceivePacket (0057e940), ThreadSafeMutexQueueWithTimedWait (0057ee80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | pointer to network event comparison data structure |
| this | 0x1E | R | — | first match WORD field (compared with HIWORD(*a2)) |
| this | 0x20 | R | — | first match DWORD field (compared with a2[1]) |
| this | 0x2E | R | — | second match WORD field (compared with HIWORD(*a2)) |
| this | 0x30 | R | — | second match DWORD field (compared with a2[1]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if this[7] (event pointer) is NULL → return false (blocked). If non-null, compare against both match patterns; true if either pattern matches.
