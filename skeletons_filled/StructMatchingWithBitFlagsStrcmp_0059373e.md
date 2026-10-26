## StructMatchingWithBitFlagsStrcmp_0059373e — CppTypeDescriptorMatch

**Summary:** C++ exception type descriptor (RTTI) matching for catch handler selection. Compares type names via string comparison and validates const/volatile qualifier compatibility through bit flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5934E1 (005934e1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x8 | R | — | Type name string data of the descriptor |
| this | 0x0 | R | — | Type descriptor flags/qualifiers byte |
| this | 0x4 | R | — | Pointer to type name descriptor structure |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058fb90 | sub_58FB90 | Compare type name strings; returns 0 if equal, non-zero if different |

**Guard conditions:** If `this+0x4` (type name pointer) is NULL or byte at offset 8 of that structure is zero, returns 1 immediately (match by default, no type info to compare). If type name pointers at `a1+4` and `a2+4` differ, calls `sub_58FB90` to compare strings — returns 0 if strings differ. If `*(BYTE*)a2 & 2` (catch qualifier bit) is set AND `*(BYTE*)a1 & 8` is not set, returns 0. If `*a3 & 1` (match flag) AND `*(BYTE*)a1 & 1` not set, returns 0. If `*a3 & 2` AND `*(BYTE*)a1 & 2` not set, returns 0. Returns 1 only if all checks pass.
