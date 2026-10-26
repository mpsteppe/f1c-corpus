## AIDriverRandomSelector_0042ae20 — ResetRandomDriverSelection

**Summary:** Resets AI driver random selection state: if a2 matches stored random targets at 0x45FC or 0x45F8, clears them and resets lateral force/torque field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C6E80 (004c6e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4420 | RW | — | Lateral force/torque control field to reset when target match |
| this | 0x45F8 | RW | — | Secondary random target index to match and clear |
| this | 0x45FC | RW | 0 | Primary random target index to match and clear |

**Written-by note (persistence):**
- this 0x4420: written to 0 conditionally when a2 matches primary target; external poke survives until next match
- this 0x45F8: written to 0 conditionally when a2 matches secondary target; external poke survives until next match
- this 0x45FC: written to 0 conditionally when a2 matches; external poke overwritten on next match

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ad00 | LateralForceTorqueCalculation | Recalculate lateral force and torque with index 100 after primary target reset |

**Guard conditions:** a2 == this[0x45FC]: matches primary target → zero it, call LateralForceTorqueCalculation(this, 100), zero this[0x4420]. a2 == this[0x45F8]: matches secondary target → zero it only. Neither matches → no changes.
