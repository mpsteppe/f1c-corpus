## EventTriggerOnStateChange_0042e470 — StateChangeEventTrigger

**Summary:** Detects state change on tracked entity. Compares entity ID and state fields between reference (a2) and current (a3). When IDs match and state differs, copies new state and sets event trigger flags at this[0] and this[0x19A4] to 1.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TrackConfig (0042e530), AIGearSelectionSet (0042eaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | eventTriggerFlag |
| this | 0x19A4 | RW | 1 | stateChangeDetectedFlag |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x19A4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Only triggers when `a2+16 == a3+16` (entity IDs match) AND `a2+20 != a3+20` (state field changed). If IDs don't match, returns without action.
