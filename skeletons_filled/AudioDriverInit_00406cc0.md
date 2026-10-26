## AudioDriverInit_00406cc0 — AudioDriverInit

**Summary:** Initializes Miles Sound System digital audio driver. Calls Miles startup, selects sample rate based on stored index (11025/22050/44100), opens digital driver, sets HWND and file callbacks on success, or shuts down on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | vtable method index 3 (init method called at start) |
| obj | 0x34 | R | — | vtable method index 13 (setup/resize method called on success) |
| this | 0x0 | R | — | vtable pointer (dispatched through +12 and +52 methods) |
| this | 0x54 | R | — | sample rate selector (0=11025, 1=22050, else=44100) |
| this | 0x58 | RW | 0 | zeroed field on success |
| this | 0x5C | RW | 0 | zeroed field on success |
| this | 0x60 | RW | 0 | zeroed field on success |
| this | 0x70 | RW | 0 | zeroed field on success |
| this | 0x74 | RW | 0 | zeroed field on success |
| this | 0x78 | RW | 0 | zeroed field on success |
| this | 0x7C | RW | 0 | zeroed field on success |
| this | 0x80 | RW | 0 | zeroed field on success |
| this | 0x84 | RW | 0 | zeroed field on success |
| this | 0x88 | RW | 0 | initialized flag (set to 1 on success, 0 on failure) |
| this | 0x90 | RW | 0 | driver handle from AIL_open_digital_driver |

**Written-by note (persistence):**
- this 0x58: written on success — zeroed once during init
- this 0x5C: written on success — zeroed once during init
- this 0x60: written on success — zeroed once during init
- this 0x70: written on success — zeroed once during init
- this 0x74: written on success — zeroed once during init
- this 0x78: written on success — zeroed once during init
- this 0x7C: written on success — zeroed once during init
- this 0x80: written on success — zeroed once during init
- this 0x84: written on success — zeroed once during init
- this 0x88: written on success/failure — set to 1 on success, 0 on failure
- this 0x90: written on both paths — set to driver handle or 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00405050 | ShortComputation_5050 | R | file I/O callback function for AIL_set_file_callbacks |
| 0059e390 | _AIL_set_DirectSound_HWND@8 | R | Miles API to set DirectSound window handle |
| 0059e394 | __imp__AIL_shutdown@0 | R | Miles API to shut down audio system |
| 0059e398 | _AIL_open_digital_driver@16 | R | Miles API to open digital audio driver |
| 0059e39c | _AIL_set_preference@8 | R | Miles API to set audio preference |
| 0059e3a0 | _AIL_startup@0 | R | Miles API to initialize sound system |
| 0059e3e4 | _AIL_set_file_callbacks@16 | R | Miles API to set file I/O callbacks |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534ac0 | CallbackRegistration_4ac0 | registers callback function(s) |

**Guard conditions:** checks AIL_open_digital_driver return value — if NULL (failure), takes failure path: calls vtable+52 with 0, calls AIL_shutdown, sets init flag to 0, returns 1. On success, continues with configuration and returns 0.
