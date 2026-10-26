## LazyRendererAudioInitCheck_004184f0 — LazyRendererAudioInit

**Summary:** Lazily initializes audio renderer on first call. Returns 0 on success (ready or already initialized), 1 on failure. Creates audio object via virtual dispatch on global InitStatus, stores handle at this+0xAF4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Sound_Enter (004c8a20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAF0 | RW | 1 | Initialized flag (byte): 0=not init, 1=init done |
| this | 0xAF4 | RW | — | Audio object handle/pointer from vfunc call |

**Written-by note (persistence):**
- this 0xAF0: set to 1 on successful init, persists until explicitly reset
- this 0xAF4: set to vfunc result (audio object), checked as error indicator next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004116b0 | WrapperReturning0 | Cleanup/no-op wrapper returning 0 |
| 00415090 | ShortComputation_5090 | Operates on cleanup list (dword_5EA5E8) |
| 00418970 | ThresholdGatedVirtualDispatch | Virtual dispatch with threshold gating on track condition |

**Guard conditions:** If this+0xAF0 (initialized flag) is non-zero: return 0 (already done, skip). If this+0xAF4 is non-zero: return 1 (stored sentinel/error). If dword_8AC4C4 (InitStatus) is null: return 1 (global not ready). If vfunc(InitStatus) returns 0 (object creation failed): return 1.
