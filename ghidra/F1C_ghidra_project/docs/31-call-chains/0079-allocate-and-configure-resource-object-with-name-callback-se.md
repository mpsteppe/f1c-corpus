# Chain: Allocate and configure resource object with name/callback setup

Seed: FUN_005474d0  |  System: docs/01-engine-architecture.md  |  Depth: 2  |  Functions: 10

---

## Overview

Creates a resource object through vtable dispatch. Chooses between two creation paths based on param_3 flag and checks a sub-object's field at +0x1a0. Allocates 0xc4-byte object, registers it, and configures with name/callback. Checks for existing object first (FUN_00548890); increments refcount if found.

## Call Tree

```
FUN_005474d0 — AllocateConfigureResource  [trigger: resource creation request]
  +-- FUN_00548890 — FindExistingResource  [check if resource exists]
  +-- FUN_00546250 — AllocateObject  [allocate 0xc4-byte object]
  +-- FUN_00546330 — RegisterResource  [register resource]
  +-- FUN_0054fb90 — AllocPackedArray  [allocate packed array stride 0x94+4]
  +-- FUN_00547100 — SetDefaultConfig  [set default config]
  +-- FUN_0054fc10 — ConfigureFromParam5  [config based on param_5]
  +-- FUN_00546f30 — ConfigureFromParam6  [config based on param_6]
  +-- FUN_00546f70 — SetNameFlag  [set name/flag field]
  +-- FUN_00547670 — SetInitStatus  [set init status/completion]
```

## Step-by-Step Trace

### Level 0: FUN_005474d0 — AllocateConfigureResource

**Trigger:** Called during resource creation (asset loading, texture/sound/scene init)
**Called by:** Various resource creation callers
**Purpose:** Allocates and configures resource object with name/callback setup.

**Key actions:**
1. Checks for existing object via FUN_00548890; increments refcount if found
2. Allocates 0xc4-byte object via FUN_00546250
3. Registers via FUN_00546330
4. Allocates packed array (stride 0x94 + 4 header) via FUN_0054fb90
5. Sets default config via FUN_00547100
6. Conditionally calls FUN_0054fc10 and FUN_00546f30 based on param_5/param_6 string flags
7. Sets name/flag via FUN_00546f70
8. Sets init status via FUN_00547670

**Data passed to callees:** param_1 (resource type), param_2 (name), param_3 (flag), param_5/param_6 (config strings)

### Level 1: All 9 callees

All callees are single-purpose allocation/config functions. All are leaf functions with no further documented callees.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_005474d0 | param_2 (name) | Search existing resources | Found/created pointer |
| FUN_005474d0 | param_1 (type) | Allocate 0xc4-byte object | New resource object |
| FUN_005474d0 | param_5/param_6 | Conditional config | Configured resource |

## Notes

- All 9 callees are leaf allocation/config functions — no further recursion
- operator_new used for allocation internally
- Resource type determined by param_1 (vtable dispatch)
- Used by texture, sound, scene, and other resource systems

---
