## sub_4DC3C0_004dc3c0 — Gizmo object reader (ReadGizmoObject)

**Summary:** Reads one gizmo definition block for the named gizmo type: uppercases the name, recursively counts the read, instantiates the gizmo object via sub_4DBE00, then loops over key/value entries and applies them (name, position/size/offsets, captions/tooltips, tooltip colours, CHILD, ACTIONS, ATTRIBUTESET, FRIENDGIZMO, CUSTOMDATA). Returns 0 on an unknown gizmo type, otherwise exits through the off_16C96B0 indirect helper.

**Called by:** sub_4DC3C0 (004dc3c0), sub_4DCE40 (004dce40), sub_4DD1F0 (004dd1f0), sub_4DD510 (004dd510)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | R | — | Gizmo nesting/recursion depth counter, incremented once per read |
| this | 0x2FE | R | — | Byte flag enabling the duplicate-name path (checked with the counter) |
| this | 0x300 | R | — | Count of names assigned; duplicate-name handling only while < 4 and 0x2FE is set |
| this | 0x308 | R | — | Pointer to the owning gizmo-set/context; also used as base for the attribute registry at +1380 |
| this | 0x30C | R | — | Value copied verbatim into the new gizmo object's dword[38] |
| this | 0x310 | R | — | Value copied verbatim into the new gizmo object's dword[39] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Default tooltip BG map name used when 'ToolTipBGMap' value is "none" |
| 006f5d1c | aPosition | R | Key name "POSITION" |
| 00711868 | aCustomdata | R | Key name "CUSTOMDATA" |
| 00712824 | asc_712824 | R | Unnamed string constant used by the gizmo reader (exact text not visible in the decompiled body) |
| 007128cc | aPosWH | R | Key name "POS-W-H" |
| 00712b64 | aFriendgizmo | R | Key name "FRIENDGIZMO" |
| 00712b70 | aAttributeset | R | Key name "ATTRIBUTESET" |
| 00712b80 | aActions | R | Key name "ACTIONS" |
| 00712b88 | aChild | R | Key name "CHILD" |
| 00712b90 | aCaption3 | R | Key name "CAPTION3" |
| 00712b9c | aCaption2 | R | Key name "CAPTION2" |
| 00712ba8 | aTooltipfontcol | R | Key name "ToolTipFontColorARGB" |
| 00712bc0 | aTooltipfontsca | R | Key name "ToolTipFontScale" |
| 00712bd4 | aTooltipfont | R | Key name "ToolTipFont" |
| 00712be0 | aTooltiptextjus | R | Key name "ToolTipTextJustification" |
| 00712bfc | aNone | R | Value "none" compared case-insensitively for ToolTipBGMap |
| 00712c04 | aTooltipbgmap | R | Key name "ToolTipBGMap" |
| 00712c14 | aTooltipbgcolor | R | Key name "ToolTipBGColorARGB" |
| 00712c28 | aTooltip3 | R | Key name "TOOLTIP3" |
| 00712c34 | aTooltip2 | R | Key name "TOOLTIP2" |
| 00712c40 | aTooltip | R | Key name "TOOLTIP" |
| 00712c48 | aCaption1 | R | Key name "CAPTION1" |
| 00712c54 | aOffset | R | Key name "OFFSET" |
| 00712c5c | aPos2Offset | R | Key name "POS2-OFFSET" |
| 00712c68 | aWidthHeight | R | Key name "WIDTH_HEIGHT" |
| 00712c78 | aName | R | Key name "NAME" |
| 00712c80 | aUndefinedGizmo | R | Error format "undefined gizmo type %s" |
| 00712c98 | aNullGizmonameP | R | Error message "Null gizmoName ptr passed to ::ReadGizmoObject" |
| 0075ad58 | unk_75AD58 | R | Unknown — not referenced in the visible decompiled body |
| 0075af70 | byte_75AF70 | R | Current definition line/token buffer: tested for "}" and for the CUSTOMDATA keyword |
| 00b6e1a0 | String1 | R | Global scratch string buffer that receives parsed values (and the undefined-type message) |
| 016c96b0 | off_16C96B0 | R | Indirect exit helper called with the gizmo name on both return paths (purpose unknown) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd2a0 | sub_4CD2A0 | Notification after an attribute set was assigned (no arguments) |
| 004cd360 | sub_4CD360 | Notification after a child gizmo was added |
| 004d3c70 | sub_4D3C70 | FRIENDGIZMO handler |
| 004dac90 | sub_4DAC90 | Fetches the next key/value token from the gizmo definition (loop condition) |
| 004dad10 | sub_4DAD10 | Error path for an undefined gizmo type |
| 004dada0 | sub_4DADA0 | ACTIONS handler (this, new object, value string) |
| 004dbb40 | sub_4DBB40 | Error reporting: logs the message with severity 2 |
| 004dbcd0 | sub_4DBCD0 | Records/logs a duplicate gizmo name (this, name) |
| 004dbe00 | sub_4DBE00 | Looks up a gizmo type by (uppercased) name and creates/returns its object; 0 if unknown |
| 004dc3c0 | sub_4DC3C0 | Self-recursion — reads a CHILD gizmo block |
| 004e2a80 | ShortComputation_a9c0 [exact] | Computes a rectangle from x, y, w, h |
| 004e2af0 | OffsetAccumulator [exact] | Stores/accumulates position (x, y) |
| 004e2b30 | PositionUpdate [exact] | Stores width/height |
| 004e2b70 | sub_4E2B70 | Sets the object's name from the parsed string |
| 004e3af0 | sub_4E3AF0 | Looks up an attribute set by name in the registry at (0x308 + 1380) |
| 004e3ee0 | sub_4E3EE0 | Adds/accumulates an offset pair into the object field at +28 (called twice for POS2-OFFSET) |
| 006131c0 | sub_6131C0 | Reads a single value/string for the given key into a buffer; true when the key matched |
| 006133a0 | sub_6133A0 | Parses four ARGB component values for the given key |
| 006134b0 | sub_6134B0 | Parses up to 8 float values for the given key |
| 00615860 | StringCopyWithBufferRealloc [structural] | Assigns text (with buffer realloc) to the current caption/tooltip/map target |
| 00616480 | sub_616480 | Checks whether the current definition line contains the given keyword |
| 0063099c | __ftol2 | Float-to-int64 conversion helper |
| 00630a80 | _strstr | Searches the current line buffer for "}" |
| 00631761 | _sprintf | Formats the "undefined gizmo type %s" message into global String1 |
| 00631c0d | __stricmp | Case-insensitive compare of the ToolTipBGMap value with "none" |
| 00633686 | __strupr | Uppercases the gizmo type name before lookup |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x300 | < | 4 | Name counter: duplicate-name handling only while below 4 |

**Guard interpretation:** A null gizmo name is logged (severity 2) and then copied anyway; an unknown gizmo type prints "undefined gizmo type %s", calls sub_4DAD10 and returns 0 before any fields are applied. The key/value loop continues only while sub_4DAC90 yields tokens; a "}" found in byte_75AF70 aborts the whole read (exit through off_16C96B0). The first matching key wins (chained if/else), unmatched keys fall through to the next token. NAME additionally calls sub_4DBCD0 only when byte 0x2FE is set AND counter 0x300 < 4 — otherwise the duplicate-name path is blocked. ToolTipBGMap with value "none" resolves to WindowName; any other value is stored as-is. ATTRIBUTESET only triggers the sub_4CD2A0 notification when the lookup returned non-zero.

**String literals referenced (deterministic):**

- `POSITION`
- `CUSTOMDATA`
- `POS-W-H`
- `FRIENDGIZMO`
- `ATTRIBUTESET`
- `ACTIONS`
- `CHILD`
- `CAPTION3`
- `CAPTION2`
- `ToolTipFontColorARGB`
- `ToolTipFontScale`
- `ToolTipFont`
- `ToolTipTextJustification`
- `none`
- `ToolTipBGMap`
- `ToolTipBGColorARGB`
- `TOOLTIP3`
- `TOOLTIP2`
- `TOOLTIP`
- `CAPTION1`
- … +6 more
