## sub_4AA3F0_004aa3f0 — ProcessGameNameEntry

**Summary:** Single-step walk over the list anchored at dword_B76250 (cursor dword_B76258): constructs a local 56-byte string object, stages the global name from dword_91CA70 plus the node's name, resolves a "Game Name" lookup, and submits the resulting string via sub_4D93B0 before destroying the local object and advancing the cursor one link (node+4).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e2990 | SEH_4AA3F0 | R | SEH scope/cleanup table entry for this function (ensures local object destruction on exceptions). |
| 006f16bc | WindowName | R | Fallback default name used for the global name, node name, and lookup fallback paths. |
| 006f7b78 | aGameName | R | Literal key "Game Name" used in the lookup sub_616930. |
| 0091ca70 | dword_91CA70 | R | Pointer to a global name string (dereferenced) copied into the shared string state first. |
| 00b76250 | dword_B76250 | R | List anchor/head; cursor dword_B76258 is initialized from it. |
| 00b76258 | dword_B76258 | RW | Current node cursor; read, advanced to node+4 if non-null. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d0ac0 | sub_4D0AC0 | Setup call made before processing (argument via registers; exact role not visible here). |
| 004d93b0 | sub_4D93B0 | Entry sink; receives the resolved string plus ten constant arguments (0,0,0,0,0,-1,-1,-1,-1). |
| 00615860 | StringCopyWithBufferRealloc [structural] | Copies the global name string (dword_91CA70 or WindowName) into the shared string state. |
| 00615a50 | sub_615A50 | Adds the node's name (or WindowName) into the local object buffer v7. |
| 00616930 | sub_616930 | Looks up "Game Name"; a null result falls back to the node name/WindowName. |
| 00616f90 | sub_616F90 | Operation on WindowName with constant 0 (string state manipulation). |
| 00617030 | sub_617030 | Constructs/initializes the local 56-byte object v7. |
| 00617060 | sub_617060 | Destroys the local object v7 (cleanup path, also the returned value). |
| 006308d8 | j_j__free | Frees buffer memory in the local object's cleanup path. |

**Guard conditions:** The main body runs only when dword_B76250 != 0 AND *(DWORD*)dword_B76250 != 0; otherwise the function returns the head pointer immediately. The "Game Name" lookup result is used only when sub_616930 returns non-null; on null it falls back to the node's name (*v1) and then to WindowName. Cursor advance occurs only when dword_B76258 is non-null.

**String literals referenced (deterministic):**

- `Game Name`
