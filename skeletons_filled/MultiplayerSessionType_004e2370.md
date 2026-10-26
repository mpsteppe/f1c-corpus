## MultiplayerSessionType_004e2370 — MultiplayerSessionType

**Summary:** Configures multiplayer session mode — maps session type enum (a2) to mode value at offset 0xB6C, then initializes 4 session slots at 0x1EC (74-DWORD stride) to -1. Part of multiplayer/session management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F18C0 (004f18c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1EC | RW | 18446744073709551615 | First of 4 session slot entries, initialized to -1 (invalid) |
| this | 0xB6C | RW | 0 | Session mode/type value (0-3 based on a2 enum) |

**Written-by note (persistence):**
- this 0x1EC: recalc every frame — external poke does NOT persist
- this 0xB6C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Switch on a2 (session type): cases 1-6 map to mode values 0-3; default copies a2 directly to mode. After switch, unconditionally initializes 4 slots at 0x1EC to -1. No early returns.
