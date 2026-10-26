## SceneFileTopLevelParser_0055b200 — scene MAS file top-level parser (ambient, fog, view, instance, light, group directives)

**Summary:** Parses the top-level directives of a scene definition file (MAS format): includefile, searchpath, groupmethod, fontfile, masfile, ambientcolor, fogmode/fogcolor/fogin/fogout/fogdensity, and dispatches view/group/instance/light sub-blocks to specialized parsers. Populates scene-state struct fields with parsed values.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55B6B0 (0055b6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x188 | RW | — | fog color blue channel (WORD at offset 392) |
| this | 0x18A | RW | — | fog color green channel (WORD at offset 394) |
| this | 0x18C | RW | — | fog color red channel (WORD at offset 396) |
| this | 0x190 | RW | — | fog density (float stored as DWORD at offset 400) |
| this | 0x194 | RW | — | fog near distance / "fogin" (float stored as DWORD at offset 404) |
| this | 0x198 | RW | — | fog far distance / "fogout" (float stored as DWORD at offset 408) |
| this | 0x19C | RW | 524288 | fog mode flags (0x20000=linear, 0x40000=exp, 0x80000=exp2; init 0x80000=EXP2 default) |

**Written-by note (persistence):**
- this 0x188: written once when "fogcolor" keyword parsed (line 70-72); survives for scene lifetime
- this 0x18A: written once with fogcolor G component; persistent scene property
- this 0x18C: written once with fogcolor R component; persistent scene property
- this 0x190: written once when "fogdensity" keyword parsed (line 78-79); persistent
- this 0x194: written once when "fogin" keyword parsed (line 74-75); persistent
- this 0x198: written once when "fogout" keyword parsed (line 76-77); persistent
- this 0x19C: default-initialized to 0x80000 (EXP2), then overwritten when "fogmode" keyword parsed (lines 55/59/63); persistent fog mode selection

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cd620 | aInstance | R | StringInstance [DERIVED] |
| 005d3960 | aMasfile | R | StringMasFile [DERIVED] |
| 005d3968 | aSearchpath | R | Str_SearchPath [DERIVED] |
| 005dc234 | aView | R | StrView [DERIVED] |
| 005dc298 | aLight | R | Str_Light [DERIVED] |
| 005dc3a0 | aGroup | R | GroupString [DERIVED] |
| 005dc3a8 | aFogdensity | R | FogDensityString [DERIVED] |
| 005dc3b4 | aFogout | R | FogoutString [DERIVED] |
| 005dc3bc | aFogin | R | FogInStr [DERIVED] |
| 005dc3c4 | aFogcolor | R | FogColorString [DERIVED] |
| 005dc3d0 | aExp2 | R | Exp2Field [DERIVED] |
| 005dc3d8 | aExp | R | StrExp [DERIVED] |
| 005dc3dc | aLinear | R | String_Linear [DERIVED] |
| 005dc3e4 | aFogmode | R | FogModeString [DERIVED] |
| 005dc3ec | aAmbientcolor | R | AmbientcolorString [DERIVED] |
| 005dc3fc | aFontfile | R | FontFileString [DERIVED] |
| 005dc408 | aLinksingle | R | String_LinkSingle [DERIVED] |
| 005dc414 | aDynamic | R | aDynamic [DERIVED] |
| 005dc41c | aGroupmethod | R | GroupMethod [DERIVED] |
| 005dc428 | aIncludefile | R | IncludeFileField [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c6f0 | sub_53C6F0 | sets the search-path for subsequent file loading |
| 0053ce10 | ErrorHandlerSet | loads a MAS file and returns error code; nonzero = load failure |
| 0053cfe0 | sub_53CFE0 | creates/open a font file resource from path string with flags |
| 0053d340 | LinkedListAppend_d340 | appends the font resource to a linked list |
| 00543800 | F_3DPositionSetWithUIRefresh | sets ambient color RGB values on the scene struct |
| 0054a160 | FlagBitSetter_a160 | sets bit flags on the scene struct (0x1000=linksingle, 0x2000=dynamic) |
| 00559a40 | LargeBufferZeroInit_9a40 | zero-initializes the line-reader buffer |
| 00559a70 | LineReaderFromBuffer | reads next token/line from the input text buffer; returns 3 on EOF |
| 00559e20 | sub_559E20 | keyword matching: returns nonzero if current line matches the keyword string |
| 00559f00 | sub_559F00 | parses 3-integer (RGB) value from the current line |
| 00559fb0 | PRNG4UniformFloatsFromSeed | parses a single float value from the current line (named "PRNG4" but used here as float parser) |
| 0055a060 | sub_55A060 | recursive sub-parser for "view" block (viewpoint/camera definition) |
| 0055a500 | sub_55A500 | recursive sub-parser for "light" block (light source definition) |
| 0055a790 | sub_55A790 | recursive sub-parser for "group" block (geometry group definition) |
| 0055a910 | SceneNode | recursive sub-parser for "instance" block (scene-node instantiation) |
| 0055b6b0 | sub_55B6B0 | recursive call: processes "includefile" directive by parsing nested scene file |
| 00587bcf | FreeWrapper_7bcf | frees the file-data buffer allocated by OperatorNewNhMallocWrapper |
| 00587c03 | OperatorNewNhMallocWrapper | allocates memory for the raw file data buffer (size = a3 bytes) |
| 0058803f | ThreadSafeReadWrapper_803f | reads file data from handle a2 into buffer, returns bytes read |
| 00588640 | sub_588640 | string comparison: returns nonzero if v13 matches the given string with length limit |

**Guard conditions:** 

| Condition | What PASSES | What is BLOCKED |
|-----------|-------------|-----------------|
| ThreadSafeReadWrapper_803f returns != a3 (partial read) OR LineReaderFromBuffer returns 3 (empty file) | — | function returns 0 (nothing to parse, clean exit) |
| sub_559E20 matches "includefile" AND sub_55B6B0 returns nonzero on nested file | function returns -1 after FreeWrapper_7bcf | — |
| sub_559E20 matches "masfile" AND ErrorHandlerSet returns nonzero | function returns -1 | — |
| sub_559E20 matches "view" AND sub_55A060 fails | function returns -1 via LABEL_46 | — |
| sub_559E20 matches "group" AND sub_55A790 fails | function returns -1 via LABEL_46 | — |
| sub_559E20 matches "instance" AND SceneNode fails | function returns -1 via LABEL_46 | — |
| sub_559E20 matches "light" AND sub_55A500 fails | function returns -1 via LABEL_46 | — |
| groupmethod="dynamic" (sub_588640 matches) | sets bit 0x2000 on this | — |
| groupmethod="linksingle" (sub_588640 matches) | sets bit 0x1000 on this | — |
| fogmode="linear" | sets fog mode to 0x20000 | — |
| fogmode="exp" | sets fog mode to 0x40000 | — |
| fogmode="exp2" | sets fog mode to 0x80000 | — |
