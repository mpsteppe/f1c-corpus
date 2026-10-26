## SettingsPathBuilder_004a1ec0 — SettingsPathBuilder

**Summary:** Constructs a settings file path by concatenating the application directory, a base file path, a player-specific identifier, and a file suffix, then passes the built path to ShortComputation_1b70 for processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerOptionsInitializer (004aa270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cd144 | asc_5CD144 | R | asc_5CD144 [DERIVED] |
| 005cd148 | asc_5CD148 | R | FilePathString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1b70 | ShortComputation_1b70 | Processes the constructed path and appends to linked list |
| 005665b0 | sub_5665B0 | Concatenates/appends string to the path buffer |
| 00566650 | StringCopyWithBufferRealloc | Copies string with buffer reallocation for the base path |

**Guard conditions:** No guard — always concatenates the path components and calls ShortComputation_1b70.
