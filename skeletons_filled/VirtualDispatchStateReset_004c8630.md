## VirtualDispatchStateReset_004c8630 — Audio mixer state reset

**Summary:** Resets audio mixer state: calls vtable offset 12 on AudioMixerPtr to stop/clear audio, and clears the active flag at this[16] to 0 (deactivate sound device).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Sound_Restart (004c8b20), Sound_Exit (004c8d00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 0 | active flag — cleared to 0 to deactivate sound device |

**Written-by note (persistence):**
- this 0x10: set to 0 unconditionally; persists as deactivated flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac4c8 | dword_8AC4C8 | R | AudioMixerPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard: if AudioMixerPtr exists (dword_8AC4C8 non-zero), call vtable offset 12 to stop audio. The active flag clear always executes regardless.
