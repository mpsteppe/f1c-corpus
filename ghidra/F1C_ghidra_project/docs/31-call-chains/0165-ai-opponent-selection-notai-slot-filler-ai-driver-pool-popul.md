# Chain: AI Opponent Selection / NotAI Slot Filler — AI Driver Pool Population

Seed: FUN_004bf790  |  System: docs/02-ai-system.md  |  Depth: 2  |  Functions: 7

---

## Overview

Fills non-player (NotAI) grid slots with randomly selected AI opponents. Entry point for building the AI opponent list each session. Called by AI Driver Count Setup (FUN_004bfd90) and Game Filter Data Loader (FUN_004c0db0). Validates slots, randomly selects AI drivers from pool, checks duplicates, creates linked list nodes with QualifyingAbility scores, and merge-sorts by ability.

## Call Tree

```
FUN_004bf790 — AI Opponent Selection / NotAI Slot Filler  [trigger: session AI setup]
  +-- FUN_004bfa00 — AI Path/Performance Function  [slot check: docs/02]
  +-- FUN_004bf6a0 — QA Score Getter  [QualifyingAbility: unlabeled]
  +-- FUN_004c5070 — Random Vehicle Selector  [pool access: docs/06]
  |     +-- FUN_005871f0 — Read Field at Offset 0x14  [docs/20]
  |     +-- FUN_004c6760 — Bounds-Checked Index Setter  [docs/20]
  +-- FUN_004c50e0 — Guarded List Accessor  [AI pool access: docs/20]
  |     +-- FUN_005871f0 — Read Field at Offset 0x14  [docs/20]
  |     +-- FUN_004c6760 — Bounds-Checked Index Setter  [docs/20]
  +-- FUN_00588410 — String Compare Helper  [duplicate check: docs/06]
  +-- FUN_004c2e20 — MergeSortLinkedListByFloat  [sort by QA: docs/10]
  |     +-- FUN_004c2e20 — MergeSortLinkedListByFloat  [recursive self-call]
  +-- FUN_0058815f — String Format with Buffer Overflow Check  ["%s NOT: NotAI": docs/08]
        +-- FUN_0058d04d — Core Format Engine (vsnprintf)  [leaf]
        +-- FUN_0058cf35 — Overflow Error Handler  [docs/06]
```

## Step-by-Step Trace

### Level 0: FUN_004bf790 — AI Opponent Selection / NotAI Slot Filler

**Trigger:** Called during session AI setup — by FUN_004bfd90 (AI Driver Count Setup) and FUN_004c0db0 (Game Filter Data Loader).
**Called by:** FUN_004bfd90 (docs/02), FUN_004c0db0 (docs/08).
**Purpose:** Selects random AI opponents to fill non-player grid slots.

**Key actions:**
1. If param_2 < 0xb and FUN_004bfa00 returns same ID: returns early (slot already filled)
2. Otherwise: randomly selects param_2 AI drivers from pool (FUN_004c5070/004c50e0)
3. For each candidate:
   - Checks for duplicate via FUN_00588410 (string compare)
   - Creates linked list node: stores AI entry pointer + QualifyingAbility score (FUN_004bf6a0 from entry+0x2f)
   - Appends to param_1 linked list
4. After selection: merge-sorts linked list by QualifyingAbility score (ascending)
5. Formats debug string "%s NOT: NotAI" via FUN_0058815f
6. Returns count of AI drivers selected

**Struct offsets (linked list node, 0xc bytes):**
- +0x00: AI entry sub-node pointer (8 bytes: ID + QA float)
- +0x04: Next pointer
- +0x08: Flag byte (= 1)

### Level 1: FUN_004c5070 — Random Vehicle Selector

**Trigger:** Called once per AI driver slot to fill.
**Called by:** FUN_004bf790.
**Purpose:** Selects a random vehicle entry from the AI pool.

**Key actions:**
1. Calls FUN_005871f0 to read field at +0x14 (pool size/count)
2. Calls FUN_004c6760 for bounds-checked index assignment

### Level 1: FUN_004c2e20 — MergeSortLinkedListByFloat

**Trigger:** Called once after all AI entries selected.
**Called by:** FUN_004bf790.
**Purpose:** Sorts the AI driver linked list by QualifyingAbility score ascending.

**Key actions:**
1. Recursive merge sort on singly-linked list
2. Compares float values at each node
3. Returns sorted list head

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004bf790 | param_2 (slot count) | random selection + dedup | linked list of AI entries |
| FUN_004bfa00 | entry ID | slot check | already-filled flag |
| FUN_004c5070 | AI pool | random access | selected AI entry |
| FUN_004bf6a0 | entry+0x2f | QA score read | QualifyingAbility float |
| FUN_004c2e20 | linked list | merge sort | sorted by QA |

## Globals Written in This Chain

None. Reads from AI pool data structures.

## Notes

- Ascending sort by QA: lower QA (better) first — affects grid order.
- FUN_004c2e20 is recursive — self-call for merge sort divide step.
- Debug format "%s NOT: NotAI" suggests developer logging.
- Called from two different points: AI count setup (docs/02) and game filter loading (docs/08).

---
