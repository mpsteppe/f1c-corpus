## sub_4DD1F0_004dd1f0 — ParseLayerDefinition

**Summary:** Parses a layer definition by type string (NORMAL/MODAL), allocates a 0xB0-byte layer object and wires it into the layer manager, then consumes a directive block (NAME, SOUND_FOCUS, SOUND_LOSTFOCUS, GIZMO, PAGE) until the closing brace. Part of the UI layer/screen definition parser.

**Called by:** sub_4DD510 (004dd510)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | R | — | Nesting/reentrancy counter: incremented on entry, decremented on exit |
| this | 0x2FE | R | — | Byte flag gating NAME registration (checked before sub_4DBCD0) |
| this | 0x300 | R | — | Count of registered names; must be < 4 for another NAME to be accepted |
| this | 0x308 | R | — | Layer manager/container pointer passed to sub_4DFF60 and sub_4DFF90 |
| this | 0x30C | RW | 0 | Current layer object pointer (set to newly created layer, reset to 0 on exit) |

**Written-by note (persistence):**
- this 0x30C: [LLM: written once/conditional/recalc every frame? would an external poke survive?] — rewritten on every call: assigned the newly allocated layer object after the type dispatch and explicitly reset to 0 after the parse loop; an external poke would be overwritten on the next invocation and zeroed at each return.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e535c | SEH_4DD1F0 | R | SEH scope handler/registration used by this function's exception frame |
| 006f4ed0 | aNormal | R | Literal "NORMAL" compared against the uppercased type string |
| 00712824 | asc_712824 | R | String constant referenced by the parser (likely the "}" block terminator tested with strstr); exact text not shown |
| 00712a88 | aSoundLostfocus | R | Literal "SOUND_LOSTFOCUS" directive keyword |
| 00712a98 | aSoundFocus | R | Literal "SOUND_FOCUS" directive keyword |
| 00712c78 | aName | R | Literal "NAME" directive keyword |
| 00712cdc | aGizmo | R | Literal "GIZMO" directive keyword |
| 00712d18 | aPage_0 | R | Literal "PAGE" directive keyword |
| 00712d20 | aUndefinedLayer | R | Format string "undefined layer type %s" for the unknown-type error |
| 00712d38 | aModal | R | Literal "MODAL" compared against the uppercased type string |
| 0075ad58 | unk_75AD58 | R | Parser/tokenizer global state read while advancing through the definition |
| 0075af70 | byte_75AF70 | R | Token/line buffer searched with strstr for the "}" end marker |
| 00b6e1a0 | String1 | R | Global scratch buffer receiving the sprintf-formatted error message |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dac90 | sub_4DAC90 | Tokenizer advance: fetches the next directive/token; loop condition |
| 004dbb40 | sub_4DBB40 | Reports a parser error (severity 3) with a message string |
| 004dbcd0 | sub_4DBCD0 | Registers a NAME entry for the layer (called only under the count guard) |
| 004dc3c0 | sub_4DC3C0 | Parses/creates a gizmo by name, returns its pointer |
| 004dce40 | sub_4DCE40 | Handles a PAGE directive for the layer |
| 004df6c0 | sub_4DF6C0 | Layer constructor: builds a layer object, argument 0=NORMAL, 1=MODAL |
| 004dff60 | sub_4DFF60 | Attaches the new layer to the layer manager (this+0x308) |
| 004dff90 | sub_4DFF90 | Registers a parsed gizmo with the layer manager/layer |
| 004e03a0 | sub_4E03A0 | Resets/clears the token buffer after a sound directive |
| 004e2a80 | ShortComputation_a9c0 [exact] | Sets the layer's computation region to (0, 599, 0, 799) |
| 004e2b70 | sub_4E2B70 | Assigns a name string to the layer object |
| 006131c0 | sub_6131C0 | Keyword matcher: checks a directive keyword and extracts its value; returns bool |
| 00630739 | ??2@YAPAXI@Z | operator new — allocates the 0xB0-byte layer object |
| 00630a80 | _strstr | Finds the "}" end-of-block marker in the token buffer |
| 00631761 | _sprintf | Formats "undefined layer type %s" into the global String1 buffer |
| 00631c0d | __stricmp | Case-insensitive compare of the type string against NORMAL/MODAL |
| 00633686 | __strupr | Uppercases the copied type string before matching |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x300 | < | 4 | Registered-name count; limits how many names a layer may carry |

**Guard interpretation:** When a NAME directive is found, sub_4DBCD0 (name registration) runs only if this+0x2FE is nonzero AND this+0x300 < 4. If the count is 4 or more (or the flag is clear) the registration is skipped and only sub_4E2B70 is applied. Any other directive types pass through to their own handlers with no count limit.

**String literals referenced (deterministic):**

- `NORMAL`
- `SOUND_LOSTFOCUS`
- `SOUND_FOCUS`
- `NAME`
- `GIZMO`
- `PAGE`
- `undefined layer type %s`
- `MODAL`
