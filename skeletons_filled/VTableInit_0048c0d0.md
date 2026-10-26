## VTableInit_0048c0d0 — HUDTimerVTableReinit

**Summary:** Reinitializes HUD timer vtable to off_5ABF88 and calls VTableSetterSubCall_b4e0. Called during destruction/reset sequence to restore vtable before sub-call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithSubCallAndConditionalFree (004713c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | &off_5ABF88 | VTable pointer set to HUDTimer vtable |

**Written-by note (persistence):**
- this 0x0: written once per call — sets vtable. Survives until overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abf88 | off_5ABF88 | R | VTable_HUDTimer — assigned as object vtable |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — always executes unconditionally.
