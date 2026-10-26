## RenderDrawOperationWithClipping_00543440 — Clipped surface blit render

**Summary:** Clips draw parameters (position, dimensions, source pointer) via helper sub_543540, then performs 2D surface blit/fill if clipped region has positive dimensions. Clears status bit 0x400 in field offset 0x18 on completion.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalSubsystemCallWithParameter (00408de0), sub_409890 (00409890), DelegationWrapper (00494bf0), SteeringWheelAnimation (0049d070), sub_49DE40 (0049de40), SuspensionCornerCheck (0049e570), sub_49E7B0 (0049e7b0), sub_4F9480 (004f9480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | — | Status flags; bit 0x400 cleared after successful blit |

**Written-by note (persistence):**
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005404d0 | F_2DSurfaceBlitFill | Performs 2D surface blit/fill operation with clipped parameters |
| 00543540 | sub_543540 | Clips draw coordinates and dimensions against surface bounds |

**Guard conditions:** Blocked if clipped width (`a4`) ≤ 0 or clipped height (`a5`) ≤ 0. Passes only when both clipped dimensions are positive.
