## sub_4FBF60_004fbf60 — BuildVehicleStatusStrings

**Summary:** Fills the object's display text buffers for a vehicle status screen: the fuel/amount string (liters, or gallons when a global unit flag is set), two spare-part name lookups with a "No Change" fallback, and six component status labels ("OK" / "Repair" / "Replace" / "Do Not Repair" / "Do Not Replace") plus a final compound/count line. Part of the car setup/vehicle-status UI text formatting.

**Called by:** sub_4E6E80 (004e6e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x298) | 0x10 | R | — | Entry count of the table pointed to by this+0x298; bounds the spare-part index lookup |
| obj | 0x4BC4 | R | — | Count/value read from the base object (*(this)+0x4BC4) and appended after the '%s/%d' status label |
| this | 0x0 | R | — | Base object pointer; dereferenced to reach offset 0x4BC4 |
| this | 0x2C | R | — | Index into an array of 108-byte records at this+21656 (0x5498); the record's bytes are printed with '%.8s' |
| this | 0x68 | R | — | Status of the item whose text goes to this+118: ==1 selects the positive label (off_6F3FD0) |
| this | 0x6C | R | — | Companion flag for the non-OK case of 0x68: 0 selects unk_6F939C, nonzero selects off_6F9398 |
| this | 0x98 | R | — | Double: offset term of the amount computation (v32 = int(0xAC) * double(0xA0) + double(0x98)) |
| this | 0xA0 | R | — | Double: scale term multiplied by the integer at 0xAC |
| this | 0xAC | R | — | Integer multiplier (dword 43) in the amount computation |
| this | 0x168 | R | — | Status for the item at this+374: ==1 → 'OK', else 'Repair'/'Do Not Repair' via 0x16C |
| this | 0x16C | R | — | Companion flag choosing 'Repair' (nonzero) vs 'Do Not Repair' (0) |
| this | 0x1A8 | R | — | Status for the item at this+438: ==1 → 'OK', else 'Replace'/'Do Not Replace' via 0x1AC |
| this | 0x1AC | R | — | Companion flag choosing 'Replace' (nonzero) vs 'Do Not Replace' (0) |
| this | 0x1E8 | R | — | Status for the item at this+502: ==1 → 'OK', else 'Replace'/'Do Not Replace' via 0x1EC |
| this | 0x1EC | R | — | Companion flag choosing 'Replace' (nonzero) vs 'Do Not Replace' (0) |
| this | 0x228 | R | — | Status for the item at this+566: ==1 → 'OK', else 'Replace'/'Do Not Replace' via 0x22C |
| this | 0x22C | R | — | Companion flag choosing 'Replace' (nonzero) vs 'Do Not Replace' (0) |
| this | 0x268 | R | — | Status for the item at this+630: ==1 → 'OK', else 'Replace'/'Do Not Replace' via 0x26C |
| this | 0x26C | R | — | Companion flag choosing 'Replace' (nonzero) vs 'Do Not Replace' (0) |
| this | 0x298 | R | — | Pointer to a list/table; its dword at +0x10 is the entry count used to validate spare-part indices |
| this | 0x2E8 | R | — | Float capacity/ratio; if nonzero a '/%d' suffix (value × computed amount) is appended to the fuel string; if zero the suffix is omitted |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Fallback display name used when the spare-part lookup returns a null name pointer |
| 006f2378 | dbl_6F2378 | R | Double constant referenced in the amount/conversion computation (exact value not shown in body) |
| 006f2a98 | aS_2 | R | Format string '%s' used for the plain label writes |
| 006f3f90 | dbl_6F3F90 | R | Double constant referenced in the amount/conversion computation (exact value not shown in body) |
| 006f3fd0 | off_6F3FD0 | R | Label used when status 0x68 equals 1 (the positive case for the this+118 line) |
| 006f6718 | aOk | R | Text 'OK' for satisfied component statuses |
| 006f9398 | off_6F9398 | R | Label used for the non-OK case of this+118 when companion flag 0x6C is nonzero |
| 006f939c | unk_6F939C | R | Label used for the non-OK case of this+118 when companion flag 0x6C is zero |
| 006fb7f8 | aDS_1 | R | Format string '%d%s' used for the integer amount display |
| 0071333c | aD_6 | R | Format string '%d' used inside the '/%d' capacity suffix |
| 00714aec | aSD_6 | R | Format string '%s/%d' for the final label/count line |
| 00714af4 | aDoNotRepair | R | Label 'Do Not Repair' when the repair companion flag is 0 |
| 00714b04 | aRepair | R | Label 'Repair' when the repair companion flag is nonzero |
| 00714b0c | a8s_0 | R | Format string '%.8s' for the table record text |
| 00714b14 | aDoNotReplace | R | Label 'Do Not Replace' when a replace companion flag is 0 |
| 00714b24 | aReplace_0 | R | Label 'Replace' when a replace companion flag is nonzero |
| 00714b2c | aNoChange | R | Label 'No Change' written when the spare-part lookup fails |
| 00714b38 | a41fS | R | Format string '%4.1f%s' for the gallon amount display |
| 00731ce8 | String2 | R | Global string constant referenced by this routine; its use is not visible in the decompiled body |
| 0091cc38 | byte_91CC38 | R | Global context/buffer passed as first argument to the string conversion helper sub_41D840 |
| 00b72454 | dword_B72454 | R | Unit-system selector: ==1 → gallons ('%4.1f%s', ×0.264172), otherwise liters ('%d%s') |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | String lookup/conversion helper — returns a processed form of a literal for display |
| 00560800 | StringBasedLookup [exact] | Index→entry lookup; the returned record's first dword is a name pointer |
| 0063099c | __ftol2 | Double→integer conversion helper used to truncate the computed amount |
| 00631761 | _sprintf | Formats a label/amount into the object's text buffers |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x68 | == | 1 | Status of the this+118 line; ==1 selects the positive label |
| this | 0x168 | == | 1 | Repair item status; ==1 → 'OK' instead of Repair-based label |
| this | 0x1A8 | == | 1 | Replace item status; ==1 → 'OK' |
| this | 0x1E8 | == | 1 | Replace item status; ==1 → 'OK' |
| this | 0x228 | == | 1 | Replace item status; ==1 → 'OK' |
| this | 0x268 | == | 1 | Replace item status; ==1 → 'OK' |

**Guard interpretation:** For each of the six status fields, value 1 PASSES to the positive label path ('OK' or the off_6F3FD0 label); any other value BLOCKS it and falls into the companion-flag branch, where the companion field at the adjacent offset picks between the normal and "Do Not ..." label (0 → "Do Not ...", nonzero → action label). The two spare-part loop lookups pass only when the id is > 0 AND id-1 < *(this+0x298)+0x10 AND the lookup returns non-null; otherwise "No Change" is written. The fuel '/%d' suffix is emitted only when the float at 0x2E8 is nonzero; a zero value omits the suffix.

**String literals referenced (deterministic):**

- `N/A`
- `Yes`
- `%d%s`
- `/%d`
- `%s/%d`
- `Do Not Repair`
- `Repair`
- `%.8s`
- `Do Not Replace`
- `Do Not Replace`
- `Do Not Replace`
- `Do Not Replace`
- `Replace`
- `Replace`
- `Replace`
- `Replace`
- `No Change`
- `%4.1f%s`
