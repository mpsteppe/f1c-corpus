## sub_4AC8B0_004ac8b0 — UpdateSteeringArmsState

**Summary:** Updates a steering/ARMS UI state: in the byte_B71CF0 path it forces the vtable slots +36/+40 and runs sub_4DF3F0(0); otherwise it refreshes the window list (sub_501CC0/53BDE0/539FF0), re-pushes the resolved name (dword_B6F708 or WindowName) through slot +40 when the tracked list value changed (or the timer expired), and when the ARMS updates are active performs an "ARMS" lookup then a "CATSTEER" lookup whose value at +24 is halved and sent to sub_5F1530.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x24 | R | — | Vtable slot (index 9) invoked with status 0/1. |
| obj | 0x28 | R | — | Vtable slot (index 10) invoked with 0, 1 or the resolved name string. |
| this | 0x0 | R | — | Vtable pointer of the object. |
| this | 0x10C | R | — | Flag (this[67]) gating the ARMS update block and part of the slot +40 condition. |
| this | 0x128 | RW | — | Float timer (this[74]); negative triggers the slot reset, set to 0.5 after a name push. |
| this | 0x12C | RW | — | Copy of dword_BE1BD0 (this[75]) used to detect list changes. |

**Written-by note (persistence):**
- this 0x128: Written conditionally (0.5) only when the name is re-pushed; otherwise left as is, so a poke survives until that branch next runs.
- this 0x12C: Written conditionally to dword_BE1BD0 only in the same branch; otherwise unchanged, so a poke survives until the branch re-executes.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Fallback name when dword_B6F708 is null. |
| 006f16c8 | flt_6F16C8 | R | Read on this path (consumer not visible in this function). |
| 006ff7d4 | aCatsteer | R | Literal "CATSTEER" used in the sub_5F12D0 lookup. |
| 006ff7e0 | aArms | R | Literal "ARMS" used in the sub_5DA9A0 lookup. |
| 00731ce8 | String2 | R | Read on this path (consumer not visible in this function). |
| 00b6e070 | dword_B6E070 | R | Argument (context/owner) passed to the "ARMS" lookup sub_5DA9A0. |
| 00b6e198 | dword_B6E198 | R | Flag gating the ARMS update block. |
| 00b6f530 | byte_B6F530 | R | Global structure reset via sub_501CC0(&byte_B6F530, 1). |
| 00b6f708 | dword_B6F708 | R | Name string pointer pushed through slot +40 (WindowName when null). |
| 00b71cf0 | byte_B71CF0 | R | Mode flag selecting the early forced slot path. |
| 00be1bd0 | dword_BE1BD0 | R | Current list value compared with this[75] to detect changes. |
| 00be1ce0 | unk_BE1CE0 | R | Window/list container snapshotted with sub_53BDE0 then reset via sub_539FF0. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004df3f0 | sub_4DF3F0 | Invoked with 0 on the byte_B71CF0 path. |
| 00501cc0 | sub_501CC0 | Reset/init of the byte_B6F530 structure with flag 1. |
| 00539ff0 | sub_539FF0 | Resets the unk_BE1CE0 list after the snapshot. |
| 0053bde0 | sub_53BDE0 | Snapshots unk_BE1CE0 into the local descriptor (buffer v11, size 512). |
| 005da9a0 | sub_5DA9A0 | Looks up "ARMS" within dword_B6E070; result v4 queried further. |
| 005f12d0 | sub_5F12D0 | Looks up "CATSTEER" starting from *v5; result v7 supplies the float at +28/+24. |
| 005f1530 | sub_5F1530 | Applies the halved value (field+24 * 0.5) for the CATSTEER entry. |

**Guard conditions:** If byte_B71CF0 != 0 → early path: slot +36(this,1), slot +40(this,0), sub_4DF3F0(0), return 0 (everything else blocked). Otherwise: this[74] < 0.0 triggers slot +36(this,0) and slot +40(this,1); the name push via slot +40 runs only when this[75] != dword_BE1BD0 OR (this[67] == 0 AND this[74] < 0.0). The ARMS block requires dword_B6E198, this[67] and dword_B6E070 all non-zero, then v4 non-zero, *(v4+544) > 0, *(v4+532) non-zero, *v5 non-zero and the CATSTEER lookup non-zero.

**String literals referenced (deterministic):**

- `CATSTEER`
- `ARMS`
