## sub_4D41CD_004d41cd — FilterAndRebuildList

**Summary:** Scans the item list at 0x90 applying a comparison filter driven by the context argument a2 (mode at a2+8, name index at a2+12): each item's name (resolved via sub_4CE200 when the index is valid, else element+0xA0 or WindowName) is compared against WindowName as threshold — numeric < / > for modes 0/1, string < / > for modes 2/3 — the last matching item is turned into a node by sub_4CD3E0 and appended to a rebuilt list, whose position is remembered so the previous selection (0x248) can be restored; when the source list is empty the rebuilt list is installed into 0x90/0x94 and sub_4D4060 is invoked to select the found entry.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | element next-link (+0x8C) read while walking the 0x90 list to position v12 |
| *(this+0x11C) | 0xA0 | R | — | element name string (+0xA0) used when no valid context name index is supplied |
| this | 0x90 | RW | — | source list head; read throughout and replaced by the rebuilt list when it is null at the end |
| this | 0x94 | RW | — | item count; bounds the passes and is restored (to the original value) when the rebuilt list is installed |
| this | 0x130 | R | — | unknown (no direct access visible in this body; reached through a called path) |
| this | 0x248 | RW | 0 | selection index: reset to 0, set to each tested position, decremented once per outer pass |

**Written-by note (persistence):**
- this 0x90: written only in the final empty-list branch (installed = rebuilt list); a poke otherwise survives until such a call.
- this 0x94: written only in that same final branch (restored count); otherwise untouched.
- this 0x248: rewritten many times per call (reset to 0, set to candidate positions, decremented per pass); an external poke is overwritten by the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d4524 | jpt_4D4334 | R | jump table for the switch on the comparison mode at a2+8 (values 0–3) |
| 006f16bc | WindowName | R | name fallback for elements and the threshold string passed to _atol / __stricmp in the filter cases |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd3e0 | sub_4CD3E0 | builds the node for the selected candidate (v32); result is appended to the rebuilt list |
| 004ce200 | sub_4CE200 | returns the name string for a given index (used when the context index at a2+12 is >= 0) |
| 004d4060 | sub_4D4060 | final selection call with the found position and a3=0 (no window jump) when the source list was empty |
| 00615860 | StringCopyWithBufferRealloc [structural] | string copy/realloc applied to the resolved name candidates |
| 006308d8 | j_j__free | heap release used during the routine (listed in coverage; no direct call visible in the shown body) |
| 00631a35 | _atol | converts the candidate name and WindowName to numbers for the numeric comparison modes 0 and 1 |
| 00631c0d | __stricmp | case-insensitive string comparisons with WindowName for modes 2 and 3 |

**Guard conditions:** Outer loop runs while the count at 0x94 (re-read each pass) is > 0. Per pass: name source depends on a2+12 — index >= 0 → sub_4CE200, otherwise element+0xA0, otherwise WindowName, else name null. Filter switch on a2+8: case 0 selects when atol(name) < atol(WindowName); case 1 selects when atol(name) > threshold; case 2 selects when __stricmp(name, WindowName) < 0; case 3 selects when __stricmp > 0; default case selects nothing. Null names never select. v30 (= position equals the old 0x248 value) records the position of the matching node in the rebuilt list (v38). Final branch only when 0x90 is null: install rebuilt list + restored count, then sub_4D4060(v4, v38, 0); otherwise the original count is returned.
