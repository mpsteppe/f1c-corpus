## CamMan_Post_0040cce0 — CameraManagerPost

**Summary:** Cleans up camera manager: zeros main pointer, releases three virtual loader objects (config, scene, module) via vtable[0] release pattern, resets state, and clears byte flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | vtable of config loader object; vtable[0] release method called |
| *(*(this+0x1C)+0x0) | 0x0 | R | — | vtable of scene loader object; vtable[0] release method called |
| *(*(this+0x20)+0x0) | 0x0 | R | — | vtable of module loader object; vtable[0] release method called |
| *(this+0x18) | 0x0 | R | — | pointer to config loader object (to read vtable) |
| *(this+0x1C) | 0x0 | R | — | pointer to scene loader object (to read vtable) |
| *(this+0x20) | 0x0 | R | — | pointer to module loader object (to read vtable) |
| this | 0x8 | RW | 0 | main camera pointer, zeroed on post |
| this | 0x18 | RW | 0 | config loader pointer, zeroed after release |
| this | 0x1C | RW | 0 | scene loader pointer, zeroed after release |
| this | 0x20 | RW | 0 | module loader pointer, zeroed after release |
| this | 0x2E | RW | 0 | byte flag, reset to 0 |

**Written-by note (persistence):**
- this 0x8: zeroed once on post
- this 0x18: zeroed after releasing config loader
- this 0x1C: zeroed after releasing scene loader
- this 0x20: zeroed after releasing module loader
- this 0x2E: zeroed on post

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be958 | aDDevF119992002_15 | R | AssertStr_SourcePath_15 [DERIVED] |
| 005be99c | aEnteredCammanP | R | String_EnteredCamManP [DERIVED] — debug log string |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] — passed to struct cleanup |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004083e0 | StructInitWithConditionalNotify | cleanup/reinit of global state |
| 004d7a50 | StringSplitLoop | debug log gating |
| 004d7aa0 | DebugLogWrite | writes "entered CamMan_Post" debug message |

**Guard conditions:** each of the three loader pointers (0x18, 0x1C, 0x20) checked for non-null before calling vtable[0] release. If StringSplitLoop returns non-zero, writes debug log.
