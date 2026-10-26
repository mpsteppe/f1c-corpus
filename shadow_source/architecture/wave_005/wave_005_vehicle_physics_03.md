# CollisionGlobals

Scope: `vehicle_physics`  
Trust: `DERIVED`

44 one-shot collision-globals initializers (0x0044CF20..0x0044E5A0), all straight-line writes of a leading tag literal plus zeroed parameter dwords (optionally a tail threshold), no guards, no this-pointer, no callers. Proposed as a single DERIVED class CollisionGlobalsInitializer; tag semantics, tail-threshold meaning, block-contiguity, and the four unnamed callees are unresolved.

## Function roles

- `0x0044CF20` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 38 to 0x007CA3A8, zeroes 1 immediately following dword fields, returns 0. No guards, no field access, no this-pointer. Delegates remaining setup to unnamed callee globalstateinitializer_cf34 (no address in packet).
- `0x0044CF80` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 39 to 0x007CA480, zeroes 1 immediately following dword fields, returns 0. No guards, no field access, no this-pointer. Calls unnamed audiomixergaininit (no address in packet).
- `0x0044D040` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 41 to 0x007CA3D8, zeroes 1 immediately following dword fields, returns 0. No guards, no field access, no this-pointer. Delegates remaining setup to unnamed callee initfloatglobals_d054 (no address in packet).
- `0x0044D0A0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 106 to 0x007CCF90, zeroes 3 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D100` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 107 to 0x007CCF60, zeroes 3 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D160` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 108 to 0x007CCF70, zeroes 3 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D1C0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 109 to 0x007CCFA0, zeroes 3 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D2E0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 62 to 0x007CA410, zeroes 1 immediately following dword fields, returns 0. No guards, no field access, no this-pointer. Delegates remaining setup to unnamed callee initrenderconstantszeroone (no address in packet).
- `0x0044D340` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 63 to 0x007CA4D0, zeroes 3 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D3A0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 13 to 0x007CCD50, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D4C0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 16 to 0x007CCCD8, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D520` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 17 to 0x007CCD20, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D580` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 18 to 0x007CCD08, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D640` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 20 to 0x007CCC68, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D6A0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 21 to 0x007CCCC0, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D700` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 22 to 0x007CCC98, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D760` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 23 to 0x007CCC20, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D7C0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 24 to 0x007CCC08, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D8E0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 27 to 0x007CCDE0, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D940` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 28 to 0x007CCDC8, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044D9A0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 42 to 0x007CCF30, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DA00` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 43 to 0x007CCF18, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DA60` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 44 to 0x007CCED0, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DB20` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 46 to 0x007CCF00, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DBE0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 48 to 0x007CCE70, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DC40` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 49 to 0x007CCE58, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DCA0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 50 to 0x007CCEA0, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DD00` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 51 to 0x007CCE88, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DDC0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 53 to 0x007CCDF8, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DE20` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 54 to 0x007CCE40, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DE80` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 55 to 0x007CCE28, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DEE0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 56 to 0x007CCBDC, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044DF40` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 57 to 0x007CCBC4, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044E0C0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 69 to 0x007CCD98, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044E120` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 70 to 0x007CD1A8, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044E180` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 71 to 0x007CD1C0, zeroes 3 immediately following dword fields and writes tail literal 9000 to 0x007CD1D4, returns 0. No guards, no field access, no this-pointer.
- `0x0044E1E0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 72 to 0x007CCF48, zeroes 3 immediately following dword fields and writes tail literal 18000 to 0x007CCF5C, returns 0. No guards, no field access, no this-pointer.
- `0x0044E240` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 73 to 0x007CD1D8, zeroes 3 immediately following dword fields and writes tail literal 27000 to 0x007CD1EC, returns 0. No guards, no field access, no this-pointer.
- `0x0044E2A0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 74 to 0x007CD098, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044E3C0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 77 to 0x007CD130, zeroes 3 immediately following dword fields and writes tail literal 27000 to 0x007CD144, returns 0. No guards, no field access, no this-pointer.
- `0x0044E420` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 78 to 0x007CD004, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.
- `0x0044E480` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 79 to 0x007CD034, zeroes 3 immediately following dword fields and writes tail literal 9000 to 0x007CD048, returns 0. No guards, no field access, no this-pointer.
- `0x0044E540` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 81 to 0x007CD0E0, zeroes 3 immediately following dword fields and writes tail literal 27000 to 0x007CD0F4, returns 0. No guards, no field access, no this-pointer.
- `0x0044E5A0` **CollisionGlobalsInitializer** — One-shot collision global-block initializer: writes tag literal 82 to 0x007CC9FC, zeroes 5 immediately following dword fields, returns 0. No guards, no field access, no this-pointer.

## Proposed classes

### CollisionGlobalsInitializer

DERIVED grouping of the structurally identical straight-line global-block initializers. The packet gives no this-pointer, no static callers, and no frame-path membership, so class ownership is a reconstruction grouping, not an evidenced C++ class. ABI names partition the functions into grid/state/region/table/broadphase/config/audio/global prose families; those partitions are unverified. Distinct global blocks are initialized by distinct functions; contiguity between blocks does not prove shared struct ownership.

Methods: `0x0044CF20`, `0x0044CF80`, `0x0044D040`, `0x0044D0A0`, `0x0044D100`, `0x0044D160`, `0x0044D1C0`, `0x0044D2E0`, `0x0044D340`, `0x0044D3A0`, `0x0044D4C0`, `0x0044D520`, `0x0044D580`, `0x0044D640`, `0x0044D6A0`, `0x0044D700`, `0x0044D760`, `0x0044D7C0`, `0x0044D8E0`, `0x0044D940`, `0x0044D9A0`, `0x0044DA00`, `0x0044DA60`, `0x0044DB20`, `0x0044DBE0`, `0x0044DC40`, `0x0044DCA0`, `0x0044DD00`, `0x0044DDC0`, `0x0044DE20`, `0x0044DE80`, `0x0044DEE0`, `0x0044DF40`, `0x0044E0C0`, `0x0044E120`, `0x0044E180`, `0x0044E1E0`, `0x0044E240`, `0x0044E2A0`, `0x0044E3C0`, `0x0044E420`, `0x0044E480`, `0x0044E540`, `0x0044E5A0`


## Compatibility contracts

- **CollisionGlobalsInitValues** — 44 fixed global data blocks are written once with a leading type/tag literal and zeroed parameter dwords (some with a tail threshold 9000/18000/27000) by the initializers at 0x0044CF20..0x0044E5A0. A replacement executable that wants identical startup state must initialize these globals with the same values, or reimplement the behaviour that reads them.

## Unresolved

- Class ownership: every function has owner trust UNKNOWN, no this-pointer, no static callers, and is not on a tick frame path; CollisionGlobalsInitializer is a DERIVED grouping of structurally identical initializers, not evidenced original-source structure.
- Unnamed callees GlobalStateInitializer_cf34 (0x0044CF20), AudioMixerGainInit (0x0044CF80), InitFloatGlobals_d054 (0x0044D040), and InitRenderConstantsZeroOne (0x0044D2E0) have no addresses or prototypes in the packet; the call targets are unlinked.
- Semantic meaning of the tag literals (13, 16, 17, 18, 20-24, 27, 28, 38, 39, 41-44, 46, 48-51, 53-57, 62, 63, 69-74, 77-79, 81, 82, 106-109) is not established; the grid/state/region/table/broadphase/config prose names are DERIVED and unverified, and 0x0044DDC0's 'SteeringSensitivity' label conflicts with the table-entry reading.
- Literals 1065353216 (plausibly 1.0f) and -1082130432 (plausibly -1.0f) are stored in dwords; the float-vs-integer intent is ambiguous from the raw source (float reading DERIVED).
- Tail thresholds 9000 (0x0044E180, 0x0044E480), 18000 (0x0044E1E0), and 27000 (0x0044E240, 0x0044E3C0, 0x0044E540) have no evidenced meaning; the toe-angle/renderer-threshold/caster-limit/max-distance/UI-stat prose readings conflict and are all DERIVED.
- Adjacent global blocks (e.g. 0x007CCC08/0x007CCC20/0x007CCC98/0x007CCCC0) are written by separate initializer functions; equal 4-byte spacing suggests array/struct strides but no packet evidence shows a loop, shared base pointer, or common owner, so equality of ownership is unproven.
- Field-level layout (tag at +0x0, zeroed parameters at +0x4..+0x14) is recorded in role prose and the compatibility contract; the architecture schema's field mechanism requires field: evidence refs that this packet does not allow, so classes carry empty fields arrays.
