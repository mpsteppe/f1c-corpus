# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposed grouping of generic runtime objects in the 0x4C0000 block: a family of singly-linked-list containers that share a node layout (data pointer at +0, next pointer at +4, ownership/flag byte at +8) but differ in container field placement (heads at this+0x0, this+0x8, this+0x10, or behind a header pointer at this+0xC), plus career/season scoring state, team identity fields, scene filter properties, camera FOV interpolation, and shutdown dispatch over global singletons. The list operations, node/header layouts, scoring gates and teardown contracts are the defensible, evidence-linked core; owner class identities remain mostly UNKNOWN and the heterogeneous container layouts are kept separate rather than merged.

## Function roles

- `0x004C1700` **DualListOwner** — Destroys the two singly-linked lists (payloads released only for owned nodes) and zeroes the container's list words.
- `0x004C2300` **DualListOwner** — Deep destruction of two intrusive lists plus zeroing of the container state block; one restored value (from dword_7D0A24) and one ready byte (this+0x6C = 1) survive the clear.
- `0x004C2420` **CareerStatsFileWriter** — Writes the career-statistics text block (headers, player/opponent states over a linked list, per-track records over a second list, separator tokens) into the output buffer context.
- `0x004C2860` **NamedSceneList** — Walks the named-entry list and returns the node whose name string matches a2 (falling back to a default path when the node name is null).
- `0x004C2990` **NodeFlagsProxy** — Returns the flags of the dereferenced list node, or an unspecified register value on the null path (genuine undefined behavior in the rendered body).
- `0x004C29F0` **SeasonScoringState** — Race-session scoring update gated on session type: updates short-term scoring, running average, conditionally feeds the AI difficulty value, processes the race-setup scaling factor, and increments a session counter in championship modes.
- `0x004C2A80` **SeasonScoringState** — Season scoring statistics update from the player vehicle: accumulates laps into the track scene node, records minimum speed, feeds the accumulator, and in championship modes evaluates the 90%-race-distance completion criterion.
- `0x004C2E20` **FloatKeySortableList** — Merge-sorts the list in ascending order of the float sort key at payload+4, splitting at the midpoint and merging recursively.
- `0x004C4BB0` **TrackedLinkedList** — Removes every node whose vehicle field fails to match all filter criteria, updating head/tail/cursor/count and freeing removed nodes (and data when the ownership flag is set); returns the remaining count.
- `0x004C4CB0` **TrackedLinkedList** — Searches the list for a node whose data value equals the key; returns 1 on the first match and 0 otherwise.
- `0x004C4CF0` **TrackedLinkedList** — Frees the scene-node list, freeing each node's data buffer only when the ownership flag byte is set, then zeroes the list pointer fields; returns a string-copy helper result made at entry.
- `0x004C50E0` **GuardedListAccessor** — Bounds-checked indexed read into the list; returns the selected node's first dword or an unspecified placeholder on any failure.
- `0x004C5900` **EventNameProvider** — Copies the static event-name string through the validated string-copy helper and returns its result; a thin forwarding stub.
- `0x004C5C80` **SceneFilterProperty** — Initializes a scene-filter property (scene index, order position, slot sentinel, name) and resolves the scene's slot.
- `0x004C6960` **TeamIdentityObject** — Writes the team id to five mirrored fields across the object so every sub-structure agrees on team identity; returns the value written.
- `0x004C69B0` **TeamIdentityObject** — Sets the 7-character short-string buffer (this+0x4708, terminated at +0x470F) and stores the derived string code at this+0x4710.
- `0x004C7E80` **HeaderLinkedList** — Destroys the list rooted at the header pointer this+0xC, invoking each node's content destructor when the ownership flag is set, freeing nodes and the header, and clearing the header fields.
- `0x004C7F30` **CameraState** — Interpolates the camera FOV stored at this+0x8 toward a session-type/race-phase dependent target with a clamped step (min(a2*0.125, 0.05)), never overshooting the target.
- `0x004C81A0` **HeaderLinkedList** — Searches the list for an entry whose data word matches the global comparison value and clears the entry's match flag word at +0x18.
- `0x004C8350` **GlobalSingletonRegistry** — Teardown dispatch over four global singleton pointers via vtable slots (slot 0 with argument 1, or slot 12 with no extra argument), clearing each global after dispatch.
- `0x004C8630` **AudioMixerState** — Stops/clears the audio mixer via vtable slot 12 on dword_8AC4C8 and deactivates the device by clearing the active flag at this+0x10.
- `0x004C88A0` **AudioMixerState** — Conditionally writes a mixer-level ratio into this+0x18 with state this+0x14 = 2, using the constant flt_7CF380 when the denominator is non-positive.

## Proposed classes

### DualListOwner

Container that owns two singly-linked lists (list A at this+0x0, list B at this+0x10) and an optional state block up to this+0x8C; provides deep cleanup that releases owned payloads and zeroes the container.

Methods: `0x004C1700`, `0x004C2300`

- `this+0x00000000` `pointer list_a_head` (read_write, GUESS)
- `this+0x00000004` `dword list_a_word_1` (read_write, GUESS)
- `this+0x00000008` `dword list_a_word_2` (read_write, GUESS)
- `this+0x0000000C` `dword list_a_word_3` (read_write, GUESS)
- `this+0x00000010` `pointer list_b_head` (read_write, GUESS)
- `this+0x00000014` `dword list_b_word_1` (read_write, GUESS)
- `this+0x00000018` `dword list_b_word_2` (read_write, GUESS)
- `this+0x0000001C` `dword list_b_word_3` (read_write, GUESS)
- `this+0x00000020` `dword state_word_0` (read_write, GUESS)
- `this+0x00000024` `dword state_word_1` (read_write, GUESS)
- `this+0x00000028` `dword state_word_2` (read_write, GUESS)
- `this+0x0000002C` `dword state_word_3` (read_write, GUESS)
- `this+0x00000030` `dword state_word_4` (read_write, GUESS)
- `this+0x00000034` `dword state_word_5` (read_write, GUESS)
- `this+0x00000038` `dword state_word_6` (read_write, GUESS)
- `this+0x0000003C` `dword state_word_7` (read_write, GUESS)
- `this+0x00000040` `dword state_word_8` (read_write, GUESS)
- `this+0x00000044` `dword state_word_9` (read_write, GUESS)
- `this+0x00000048` `dword state_word_10` (read_write, GUESS)
- `this+0x0000004C` `dword state_word_11` (read_write, GUESS)
- `this+0x00000050` `dword state_word_12` (read_write, GUESS)
- `this+0x00000054` `dword state_word_13` (read_write, GUESS)
- `this+0x00000058` `dword state_word_14` (read_write, GUESS)
- `this+0x0000005C` `dword state_word_15` (read_write, GUESS)
- `this+0x00000060` `dword state_word_16` (read_write, GUESS)
- `this+0x00000064` `dword state_word_17` (read_write, GUESS)
- `this+0x00000068` `dword state_word_18` (read_write, GUESS)
- `this+0x0000006C` `byte ready_flag` (read_write, GUESS)
- `this+0x00000070` `dword state_word_20` (read_write, GUESS)
- `this+0x00000074` `dword state_word_21` (read_write, GUESS)
- `this+0x00000078` `dword state_word_22` (read_write, GUESS)
- `this+0x0000007C` `dword state_word_23` (read_write, GUESS)
- `this+0x00000080` `dword restored_value` (read_write, GUESS)
- `this+0x00000084` `dword state_word_25` (read_write, GUESS)
- `this+0x00000088` `dword state_word_26` (read_write, GUESS)
- `this+0x0000008C` `dword state_word_27` (read_write, GUESS)

### TrackedLinkedList

Singly linked list tracked by head/tail/cursor/count fields with optional per-node ownership flags; supports filtered removal, key search, and node-list cleanup.

Methods: `0x004C4BB0`, `0x004C4CB0`, `0x004C4CF0`

- `this+0x00000008` `pointer head` (read_write, GUESS)
- `this+0x0000000C` `pointer tail` (read_write, GUESS)
- `this+0x00000010` `pointer cursor` (read_write, GUESS)
- `this+0x00000014` `dword count` (read_write, GUESS)
- `this+0x00000018` `pointer tail_extra` (read_write, GUESS)
- `obj+0x00000000` `pointer data` (read_write, GUESS)
- `obj+0x00000004` `pointer next` (read_write, GUESS)
- `obj+0x00000008` `byte ownership_flag` (read, GUESS)

### FloatKeySortableList

List whose nodes wrap a payload holding a float sort key at payload+4; supports recursive merge sorting in ascending key order.

Methods: `0x004C2E20`

- `this+0x00000000` `pointer head` (read, GUESS)
- `this+0x00000004` `pointer next` (read_write, GUESS)
- `obj+0x00000004` `float sort_key` (read, GUESS)

### GuardedListAccessor

Provides bounds-checked indexed access into a list: rejects negative indices, validates against an (index, count) range, bounds-checks, then walks nodes to the selected entry.

Methods: `0x004C50E0`

- `this+0x00000008` `pointer node_base` (read, GUESS)
- `this+0x00000014` `dword index` (read, GUESS)
- `this+0x00000018` `dword count` (read, GUESS)

### NamedSceneList

List of named scene entries with a cursor for lookup; searches by node name string with a default-path fallback when a node name is null.

Methods: `0x004C2860`

- `this+0x00000010` `pointer list_head` (read, GUESS)
- `this+0x00000018` `pointer cursor` (read_write, GUESS)
- `this+0x0000001C` `dword read_only_field` (read, UNKNOWN)
- `*(this+0x10)+0x00000008` `pointer name_ptr` (read, GUESS)

### NodeFlagsProxy

Thin wrapper that dereferences a list node and returns its flags; the null path returns an unspecified register value.

Methods: `0x004C2990`


### CareerStatsFileWriter

Serializes career statistics into an output buffer context: optional header, career/race-condition/game-option label lines, player/opponent states, per-track records, and closing separator.

Methods: `0x004C2420`

- `this+0x00000004` `pointer player_state_list_head` (read, GUESS)
- `this+0x00000008` `pointer player_state_iterator` (read_write, GUESS)
- `this+0x0000000C` `pointer track_stats_container` (read, UNKNOWN)
- `this+0x00000010` `pointer track_list_head` (read, GUESS)
- `this+0x00000018` `pointer track_iterator` (read_write, GUESS)
- `this+0x0000001C` `pointer output_context` (read, GUESS)

### SeasonScoringState

Session-gated race/season scoring state: short-term scoring updates, running averages, lap accumulation, and the championship completion criterion.

Methods: `0x004C29F0`, `0x004C2A80`

- `this+0x0000003C` `dword session_counter` (read_write, GUESS)

### SceneFilterProperty

Record describing a scene filter: scene index, order position, slot/sort-key sentinel, and filter name; resolves the scene slot via a lookup.

Methods: `0x004C5C80`

- `this+0x00000000` `dword scene_index` (read_write, GUESS)
- `this+0x00000004` `dword order_position` (read_write, GUESS)
- `this+0x00000008` `dword slot_key` (read_write, GUESS)

### TeamIdentityObject

Large vehicle/team object that replicates the team id across five mirror fields and stores a 7-character short string plus its derived code.

Methods: `0x004C6960`, `0x004C69B0`

- `this+0x00000004` `dword team_id` (read_write, GUESS)
- `this+0x00000010` `dword team_id_mirror_4` (read_write, GUESS)
- `this+0x000032D0` `dword team_id_mirror_3252` (read_write, GUESS)
- `this+0x00004038` `dword team_id_mirror_4110` (read_write, GUESS)
- `this+0x00004894` `dword team_id_mirror_4645` (read_write, GUESS)
- `this+0x0000470F` `byte string_terminator` (write, GUESS)
- `this+0x00004710` `dword string_code` (write, GUESS)

### CameraState

Camera state holding a field-of-view value that is interpolated toward a session-type and race-phase dependent target.

Methods: `0x004C7F30`

- `this+0x00000008` `float field_of_view` (read_write, GUESS)

### HeaderLinkedList

List managed through a header block (head/tail/cursor/count) pointed to by this+0xC; provides full destruction with content-destructor invocation and a global-value match search.

Methods: `0x004C7E80`, `0x004C81A0`

- `this+0x0000000C` `pointer header_ptr` (read_write, GUESS)
- `*(this+0xC)+0x00000000` `pointer head` (read_write, GUESS)
- `*(this+0xC)+0x00000004` `pointer tail` (read_write, GUESS)
- `*(this+0xC)+0x00000008` `pointer cursor` (read_write, GUESS)
- `*(this+0xC)+0x0000000C` `dword count` (read_write, GUESS)
- `this+0x00000014` `pointer cursor_slot` (read_write, GUESS)

### GlobalSingletonRegistry

Process-global singleton registry whose teardown dispatches each non-null singleton through a vtable slot and then clears the global pointer.

Methods: `0x004C8350`


### AudioMixerState

Audio mixer/device state: reset deactivates the device and dispatches a stop/clear vtable method; a conditional ratio computation stores mixer-level ratios and a state code.

Methods: `0x004C8630`, `0x004C88A0`

- `this+0x00000010` `byte active_flag` (read_write, GUESS)
- `this+0x00000014` `dword state` (write, GUESS)
- `this+0x00000018` `float ratio` (write, GUESS)

### EventNameProvider

Provides the static event-name string by copying it through the validated string-copy helper; a thin forwarding stub.

Methods: `0x004C5900`


## Compatibility contracts

- **List node layout** — List nodes are intrusive 12-byte entries: data/content pointer at +0, next pointer at +4, ownership/alive flag byte at +8. Node and payload deallocation must route through FreeWrapper_7bcf.
- **List header layout** — Header-managed lists keep head/tail/cursor/count at header offsets +0/+4/+8/+0xC and hold the header pointer at this+0xC; after destruction the header fields are zeroed and this+0xC cleared.
- **Ownership-flag cleanup semantics** — Destructors release an owned payload (via cleanup helpers such as PitStopMemoryCleanup) before freeing the node when the +8 flag is set; the node is freed in every iteration, and containers zero their list fields afterwards.
- **Career statistics text block** — The career block writes a fixed header/label sequence (career totals, race conditions, game options, player/opponent states, per-track records) through the buffer writer 0x00566C30, bracketed by the separator token global 0x005C30B4.
- **Session type and championship mode semantics** — dword_7C56A4 == 7 selects the race-session scoring branch; dword_7D0410 values 3 and 4 select championship mode with the 90%-race-distance completion criterion; dword_8AB6E4 == 2 gates the scoring update off.
- **Team identity replication** — Writes of the team id must reach the five mirrored fields (offsets +0x4, +0x10, +0x32D0, +0x4038, +0x4894) so all sub-structures remain consistent.
- **Camera FOV interpolation** — FOV moves toward a session/phase target by step min(a2*0.125, 0.05) and never overshoots; targets are clamped to [0.25, 1.0] or [0.5, 1.0] depending on the session type.
- **Global singleton teardown dispatch** — At shutdown the four global singletons are dispatched via vtable slot 0 with argument 1 (dword_8AC4C8 / 8AC4CC / 8AC4D0) or vtable slot 12 with no extra argument (dword_8AC4C4), then each global is cleared to null.

## Unresolved

- Callee 0x004C1E40 is recorded in the packet but absent from the raw source; its role is unknown.
- The object type owning the two-list container (and what the payloads are) is unidentified; packet owner evidence is empty, so DualListOwner is a proposed grouping, not a confirmed class.
- Purpose of the sub_4C1E20(1) third-pass side-effect in 0x004C1700 is unknown; the re-walk after both lists were freed likely merges separate source-level cleanup sites.
- Container field layouts differ across the list functions (heads at this+0x0, this+0x8 or this+0x10; inline-head vs header-pointer at this+0xC); equal offsets on different this bases are kept separate rather than merged into one class.
- this+0x14 is read as an (index, count) pair in 0x004C50E0, as the count in 0x004C4BB0/0x004C4CB0, and as a pointer field zeroed in 0x004C4CF0; the semantics conflict is unresolved.
- dword_7D0A24 is read and restored into this+0x80, and the ready byte set at this+0x6C is the only non-zero field in the cleared block; their meanings are unknown.
- Identity of the four singleton object types and the dispatched vtable methods behind 0x004C8350 is not statically known; the constant 1 (first three) vs no argument (fourth) is unexplained.
- The vtable slot-12 method on dword_8AC4C8 in 0x004C8630 is read as stop/clear audio from prior analysis (DERIVED), not proven here.
- The null-path return of 0x004C2990, the header-NULL early return of 0x004C7E80, and the v3 == 0 fallback of 0x004C2A80 read uninitialized register values (genuine undefined behavior in the rendered bodies).
- Jump tables jpt_4C7F4B (0x004C8144) and jpt_4C8011 (0x004C8158) drive the FOV switch but are absent from the raw text; many float globals listed in the packet (flt_59E4xx, flt_5ACDxx, dword_8ACEE0) are not referenced in the visible body.
- sub_588410 (string equality, 0 on match), sub_66810 (criteria match), sub_587ECE / sub_587DD0 (string code / bounded copy), ReadFieldAtOffset0x14 (0x005871F0) and BoundsCheckedIndexSetter_6760 (0x004C6760) contracts are inferred from call patterns only.
- MEMORY[0] is a decompiler placeholder for the failure-path return value in 0x004C50E0; the actual value is unspecified.
- Global 0x005D2B14 (aPlayertracksta) and field this+0x0C (track-stats data container) in 0x004C2420 are listed in the packet but absent from the raw body.
- The node's data-buffer flag byte at node+8 in 0x004C4CF0 has no dedicated packet field evidence reference; scene/layer node identity and owner class are unknown.
- The exact meaning of the +16472 vehicle state word, the +16444 lap count, and the 4/3 championship-mode enumeration in the scoring functions is not proven by this packet.
- Read-only globals flt_59E440, flt_59E824 and unk_5EC6D0 in the scoring functions render as constants (0.0 / 0.89999998) and are not directly referenced in the raw body.
- The 7-character short-string buffer at this+0x4708 in 0x004C69B0 is evidenced only via source:raw and callee 0x00587DD0 (no field:this:0x00004708 evidence ref exists in the packet), so it is not modeled as a class field; only its terminator (+0x470F) and derived code (+0x4710) carry field evidence.
- dword_7C56A4 as session-type selector and dword_7C56A8 as race-phase selector are inferred from branch structure only; sub_4D1B50(0) returns an index into dword_5F0714 at stride 4656 whose meaning is not established.
