## TickUpdateDispatch_0040e170 — TickUpdateDispatch

**Summary:** Tick update dispatch: conditionally initializes engine subsystem if a sub-struct flag at offset 0x24 equals 10, calls a vtable method on a pointer chain through this+0x8, initializes a buffer with defaults, then resets the camera director.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimer (004d2e50), sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x8)+0xAF4)+0x0) | 0xC | R | — | vtable pointer at offset 0xC (vtable[3]) for virtual method call on object chain |
| *(*(this+0x8)+0xAF4) | 0x0 | R | — | pointer at v3+0xAF4, checked for NULL before vtable dispatch |
| *(this+0x8) | 0xAF4 | R | — | reads pointer at offset 0xAF4 from sub-struct at this+0x8 |
| *(this+0x88) | 0x24 | R | — | field in sub-struct at this+0x88, compared to 10 for guarded init |
| this | 0x8 | R | — | pointer to engine/buffer sub-struct |
| this | 0x88 | R | — | pointer to sub-struct whose field at 0x24 controls guarded init |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | initializes buffer at sub-struct (this+0x8) with default 10f values |
| 004347c0 | EngineGuardedInitializer | guarded engine subsystem init, called when sub-struct field at 0x24 == 10 |
| (vtable) | vtable+0xC call | virtual method call through pointer chain at this+0x8 -> +0xAF4 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x88) | 0x24 | == | 10 | flag in sub-struct at this+0x88: when 10, enables EngineGuardedInitializer |

**Guard interpretation:**
- *(this+0x88) not null AND *(*(this+0x88)+0x24) == 10 → PASSES: calls EngineGuardedInitializer(this+0x14).
- *(this+0x88) null OR *(*(this+0x88)+0x24) != 10 → BLOCKED: skips EngineGuardedInitializer.
- *(*(this+0x8)+0xAF4) (v4) not null → PASSES: calls vtable method at offset 0xC on v4.
- v4 null → BLOCKED: skips vtable call.
