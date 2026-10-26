## FloatToIntSwitch_005472d0 — Float-to-int conversion by channel index

**Summary:** Multiplies selected float field (this+0x50/0x60/0x70/0x80 based on a2 channel index 1-4) by 255.0 and converts to int via CRTFtol, storing result in *a3. Inverse of SwitchBasedFloatSetter (float = byte/255, here byte = float*255). Color channel readback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_54CA00 (0054ca00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | R | — | float field read when a2==2 (channel 2) |
| this | 0x60 | R | — | float field read when a2==1 (channel 1) |
| this | 0x70 | R | — | float field read when a2==3 (channel 3) |
| this | 0x80 | R | — | float field read when a2==4 (channel 4) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00547358 | jpt_5472DB | R | jump table for switch/case dispatch |
| 005adb58 | dbl_5ADB58 | R | Unknown_5ADB58 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | CRT floating-point to integer conversion |

**Guard conditions:** If a3 (output pointer) is null, BLOCKED: no conversion or write. Otherwise switch on a2 (1-4): a2=1 reads this+0x60, a2=2 reads this+0x50, a2=3 reads this+0x70, a2=4 reads this+0x80. Default (a2 outside 1-4): BLOCKED, returns early.
