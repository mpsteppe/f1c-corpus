## WheelRotationAnimation_0049d280 — Wheel rotation audio animation

**Summary:** Triggers up to four wheel rotation audio effects based on driver appearance bitmask. Each wheel's audio source is stored in struct fields at offsets 0x20-0x2C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SteeringWheelAnimation (0049d070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | wheel 0 audio source handle (this[8]) |
| this | 0x24 | R | — | wheel 1 audio source handle (this[9]) |
| this | 0x28 | R | — | wheel 2 audio source handle (this[10]) |
| this | 0x2C | R | — | wheel 3 audio source handle (this[11]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b7a0 | sub_49B7A0 | reads DriverAppearanceFlag bitmask |
| 0049e4e0 | AudioEffectTrigger | triggers wheel rotation audio effect per wheel |

**Guard conditions:** Checks this[8]-this[11] (0x20-0x2C) all non-null — blocks entirely if any null. Checks `dword_7C54E0 + 3984` (wheelSpinFlag?) or `dword_7C54E0 + 3964` (wheelMovingFlag?) are non-zero — blocks audio if both zero (wheels not spinning/moving).
