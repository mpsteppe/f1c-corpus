## StateResetAndConditionalInit_00475530 — UINetworkBrowserStateReset

**Summary:** Resets multi-client password flag, refreshes the network game browser UI list, and conditionally starts LAN network discovery if not already initialized and not in internet mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17C | RW | 1 | Network-update-started flag: 0=not started, set to 1 after StartNetworkUpdate |

**Written-by note (persistence):**
- this 0x17C: set conditionally (only when LAN mode and flag byte allows); external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd850 | byte_7CD850 | W | MultiClientPassword [DERIVED] — reset to 0 (clear password) |
| 007d0e74 | dword_7D0E74 | R | NetworkType [DERIVED] — 0=LAN, 1=Internet |
| 007d0fac | byte_7D0FAC | R | LAN discovery enable flag — if 0, skips StartNetworkUpdate |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461de0 | StartNetworkUpdate | Starts LAN network discovery/broadcast |
| 00475150 | sub_475150 | Refreshes UI network game browser list |

**Guard conditions:** StartNetworkUpdate call (line 16) PASSES only when ALL three conditions met: dword_7D0E74 == 0 (LAN mode) AND byte_7D0FAC != 0 (discovery enabled) AND this[0x17C] == 0 (not started). If any condition fails, network discovery is BLOCKED but UI refresh still happens.