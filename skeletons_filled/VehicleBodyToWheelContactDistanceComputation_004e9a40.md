## VehicleBodyToWheelContactDistanceComputation_004e9a40 — body-to-wheel contact distance with network write

**Summary:** Computes local-frame distance from predicted vehicle body position to wheel contact reference, writes 13 contact elements to network packet, returns clamped norm. Part of vehicle dynamics/netcode system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SwitchBasedStateHandler (0040f380), AIRacingLinePathFollowing (004e9ca0), ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x72C | R | — | local contact offset X (subtracted from transformed delta) |
| this | 0x730 | R | — | local contact offset Y (subtracted from transformed delta) |
| this | 0x734 | R | — | local contact offset Z (subtracted from transformed delta) |
| this | 0x34B0 | R | — | rotation matrix row 0, col 0 |
| this | 0x34B4 | R | — | rotation matrix row 1, col 0 |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] — rotation matrix row 2, col 0 |
| this | 0x34BC | R | — | rotation matrix row 0, col 1 |
| this | 0x34C0 | R | — | rotation matrix row 1, col 1 |
| this | 0x34C4 | R | — | rotation matrix row 2, col 1 |
| this | 0x34C8 | R | — | rotation matrix row 0, col 2 |
| this | 0x34CC | R | — | rotation matrix row 1, col 2 |
| this | 0x34D0 | R | — | rotation matrix row 2, col 2 |
| this | 0x34D4 | R | — | current body position X |
| this | 0x34D8 | R | — | current body position Y |
| this | 0x34DC | R | — | current body position Z |
| this | 0x3ABC | R | — | start of 13-element contact data array (3 floats per element, stride 12 bytes) |
| this | 0x3AC0 | R | — | second element of contact data array (this[3760]) |
| this | 0x3B60 | R | — | wheel contact reference position X |
| this | 0x3B64 | R | — | wheel contact reference position Y |
| this | 0x3B68 | R | — | wheel contact reference position Z |
| this | 0x3B6C | R | — | minimum clamp value for returned distance norm |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054fa00 | NetworkPacketDataWriter | writes contact data (transformed delta minus offset) to network packet, 13 iterations |

**Guard conditions:** a2 (velocity prediction pointer) == null → skip velocity offset addition, use raw reference position. this[3803] (0x3B6C) > computed norm → return this[3803] (minimum clamp).
