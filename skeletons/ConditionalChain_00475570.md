## ConditionalChain_00475570 — UINetworkBrowserConditionalUpdate

**Summary:** Calls a conditional network function on the game module manager, then refreshes the UI network game browser list if a state change is detected.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461f70 | ConditionalFunctionCall | Conditional network state update/reset |
| 00462140 | ShortComputation_2140 | Returns non-zero if network state changed (needs UI refresh) |
| 00475150 | sub_475150 | Refreshes UI network game browser list |

**Guard conditions:** sub_475150 (line 5) PASSES only when ShortComputation_2140 returns non-zero. If it returns zero, UI refresh is BLOCKED/skipped.
