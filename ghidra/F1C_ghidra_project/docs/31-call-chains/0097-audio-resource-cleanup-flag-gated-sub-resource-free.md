# Chain: Audio Resource Cleanup — Flag-Gated Sub-Resource Free

Seed: FUN_00552760  |  System: docs/21-audio-network-internals.md  |  Depth: 1-2  |  Functions: 4 callees

---

## Overview

Frees audio/managed resources from a struct. Checks flag bit at +0x24 (0x20000) to determine whether to clean sub-resources at +0x0c and +0x868. Always releases resource at offset 100 (FUN_0053cb90). Uses standard free wrappers.

## Call Tree

```
FUN_00552760 — Audio Resource Cleanup  [trigger: audio resource destruction / manager teardown]
  +-- FUN_0053cb90 — Resource release utility                        [leaf]
  +-- FUN_00540eb0 — Object destructor/arithmetic                    [leaf]
  +-- FUN_00587bcf — Heap memory free wrapper (operator delete)      [depth 1: calls FUN_0058aa6f]
  |     +-- FUN_0058aa6f — Heap deallocation (heap_free)             [leaf]
  +-- FUN_00557470 — No-op release stub                              [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_00552760 — Audio Resource Cleanup

**Trigger:** Audio resource destruction — called when audio manager or specific audio object is destroyed.
**Called by:** Unknown (callers.json shows no callers — likely called from audio manager destructor)
**Purpose:** Free audio resources with flag-gated sub-resource cleanup.

**Key actions:**
1. Call FUN_0053cb90 on *(param_1+100) — release resource handle at +0x64
2. Set *(param_1+100) = 0
3. Check flag at *(param_1+0x24) & 0x20000:
   - If flag set:
     - Call FUN_00540eb0 on *(param_1+0xc) — destructor/cleanup sub-resource
     - If *(param_1+0xc) non-null: free via FUN_00587bcf()
     - Check *(param_1+0x868): if non-null:
       - Call FUN_00557470() (no-op release stub — interface compatibility)
       - Free via FUN_00587bcf()
4. Return 0

**Data passed to callees:** resource handles/pointers from audio struct.

### Level 1: Callees

- **FUN_0053cb90 (resource release):** Releases audio resource at given handle. Leaf.
- **FUN_00540eb0 (object destructor):** Calls destructor/arithmetic on sub-object. Leaf.
- **FUN_00587bcf (free wrapper):** operator delete / heap free. Calls FUN_0058aa6f (heap deallocation).
- **FUN_00557470 (no-op stub):** Empty function — MSVC interface compatibility placeholder.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00552760 | audioResource ptr | flag check, free | freed resources |
| FUN_0053cb90 | handle | release | handle released |
| FUN_00540eb0 | sub-resource | destructor | object destroyed |
| FUN_00587bcf | pointer | free | heap released |

## Globals Written in This Chain

None — operates on audio struct fields.

## Notes

Chain depth 1-2 (only FUN_00587bcf has deeper callee). The 0x20000 flag gate at +0x24 controls whether cleanup of +0x0c and +0x868 resources occurs. Pattern matches audio resource destruction where the secondary resource may or may not be allocated.
