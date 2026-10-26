## sub_41EDB0_0041edb0 — GDB unlock-file scanner

**Summary:** Enumerates `*.GDB` files under the game data path, parses each file's `UnlockGold`/`UnlockPass` values into 16-byte records, and appends them to the object's linked list at this+0x74; returns the number of enumerated files.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | RW | 0 | count of enumerated GDB files, reset to 0 at entry then set from sub_615D30; also the return value |
| this | 0x74 | RW | — | linked-list head pointer (list header base = this+0x74) |
| this | 0x78 | RW | — | linked-list tail pointer (last appended entry) |
| this | 0x7C | RW | — | first list entry, set only when the list was empty (initial element anchor) |
| this | 0x80 | RW | — | list element counter, incremented on every append |

**Written-by note (persistence):**
- this 0x50: written at entry (0) and again at the end (enumeration result); recalculated on every call — an external poke would be overwritten by the next call.
- this 0x74: rewritten on every call via sub_41ED50 (list re-initialized), then appended to; a poke does not survive.
- this 0x78: recalculated on every append within the call; overwritten by the next call.
- this 0x7C: only written when the list was empty at least once during the call; otherwise retains its previous value.
- this 0x80: incremented per append; the value is relative, not reset explicitly at entry (sub_41ED50 handles initialization).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e166c | SEH_41EDB0 | R | SEH scope record for the function |
| 006f16bc | WindowName | R | fallback path/name string when the global path pointer is null |
| 006f1f34 | aSS | R | `%s%s` path format used with the file name returned by the enumeration |
| 006f3048 | aUnlockpass | R | `UnlockPass` config entry name parsed via atol |
| 006f3054 | aUnlockgold | R | `UnlockGold` config entry name parsed via atol |
| 006f3060 | aGdb | R | `*.GDB` file search pattern |
| 0091ca70 | dword_91CA70 | R | pointer to a global path string (dereferenced once; null content → WindowName) used as path prefix |
| 0091ca80 | dword_91CA80 | R | global path string (or handle) set into the string helper via sub_615A50 |
| 00faecbc | dword_FAECBC | R | file-enumeration context for find-first/find-next (sub_615FE0 / sub_615D40 / sub_615D30) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041ed50 | sub_41ED50 | initializes/clears the linked-list header at this+0x74 |
| 0048d380 | sub_48D380 | returns the string value of the `UnlockGold`/`UnlockPass` nodes (fed to atol) |
| 00615860 | StringCopyWithBufferRealloc [structural] | stores the selected path/name string through the global string helper |
| 00615a50 | sub_615A50 | selects the second path/base used by the string helper |
| 00615ce0 | LinkedListNodePeek [exact] | advances/peeks the enumeration list before requesting the next file name |
| 00615d30 | ShortComputation_5f70 [exact] | computes the number of enumerated files (stored into this+0x50 and returned) |
| 00615d40 | sub_615D40 | returns the next file name from the enumeration, null when exhausted |
| 00615fe0 | sub_615FE0 | starts the `*.GDB` wildcard file search |
| 00616840 | FileStreamReader [structural] | opens/reads the enumerated GDB file as config |
| 00616f90 | sub_616F90 | selects the loaded file context by name |
| 00617030 | sub_617030 | constructs the temporary path/buffer object (v17) used around the sprintf |
| 00617060 | sub_617060 | destroys the temporary path/buffer object |
| 00630739 | ??2@YAPAXI@Z | allocates the 16-byte value record and the 12-byte list entry |
| 006308d8 | j_j__free | frees heap blocks during SEH cleanup (paired with the allocations; not visible in the C text) |
| 00631761 | _sprintf | formats `%s%s` (WindowName + file name) into Buffer |
| 00631a35 | _atol | parses `UnlockGold` / `UnlockPass` strings into the record |

**Guard conditions:** The whole scan loop is gated by `sub_615D40(&unk_FAECBC)` returning a file name (`v4 != 0`); once it returns null the loop exits. For each file: the path is trimmed back to the last `\` of `WindowName+name` before `sub_616F90` loads it. `operator new(0x10)` returning null stores a null record pointer (then written through) — no explicit guard; `operator new(0xC)` null likewise falls through to the list append. The separate spec string `v15` is stored only `if (v15)` before the GDB config is queried; `UnlockGold`/`UnlockPass` nodes are each applied only if the lookup returns non-null. The append path selects head-vs-tail depending on whether `*v3` (head) is already set. Loop continues while find-next returns a name; returns this+0x50 (count).

**String literals referenced (deterministic):**

- `%s%s`
- `UnlockPass`
- `UnlockGold`
- `*.GDB`
