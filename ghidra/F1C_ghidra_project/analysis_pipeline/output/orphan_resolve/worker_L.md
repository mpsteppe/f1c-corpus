=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x0040ac40 | vtable_member | HIGH | C++ destructor pattern: sets vtable to PTR_LAB_0059e678, calls virtual func at index 0, sets vtable to PTR_LAB_0059e634. Called via object vtable during destruction | class destructor |
| 0x0044c980 | game_logic_isolated | MEDIUM | Collision global init: sets MaxContactCount=10, CollisionContactSentinel=-1.0f. No direct callers found, likely called from collision master init via function pointer table. References DAT_007ccf80 (MaxContactCount) | collision_master_init |
| 0x0044cf20 | game_logic_isolated | MEDIUM | CollisionStateInit_Alpha2: sets DAT_007ca3a8=0x26 (38), init fields. Part of collision subsystem initialization sequence. References collision globals | collision_master_init |
| 0x0044d4c0 | game_logic_isolated | MEDIUM | CollisionGridInit16x16: sets grid size=16, zeroes grid state. References DAT_007cccd8 (CollisionGridSize). Called from collision init sequence | collision_master_init |
| 0x0044da60 | game_logic_isolated | MEDIUM | Collision Material Init: sets MaterialStride=0x2c (44), zeroes material state. References DAT_007cced0. Part of collision material setup | collision_master_init |
| 0x0044e000 | game_logic_isolated | MEDIUM | Collision Subsystem Init: sets DAT_007ccd80=0x43 (67), zeroes subsystem state. Part of collision pipeline initialization | collision_master_init |
| 0x0044e5a0 | game_logic_isolated | MEDIUM | Collision global init (group 0x52): sets DAT_007cc9fc=0x52, zeroes 5 fields. References CollisionSystemData block | collision_master_init |
| 0x0044eb40 | game_logic_isolated | MEDIUM | CollisionGridInit97: sets grid size=97 (0x61), max distance=27000. References DAT_007ca51c (CollisionGridSize_97). Part of collision spatial partition init | collision_master_init |
| 0x004694b0 | utility_isolated | MEDIUM | Filename from linked list. Walks list at param_1+0x444, copies filename to param_1+0x344, strips to last backslash. File I/O utility, no game globals. Called via file system interface | file_system_code |
| 0x0047f210 | vtable_member | HIGH | Conditional vtable call: if param_1[3] non-zero, calls virtual func index 0 with arg 1. Likely a C++ conditional destructor or flag-check dispatch method | class destructor / update |
| 0x00499520 | game_logic_isolated | MEDIUM | Linked list traversal at param_1+0x44 with stride +0x23, calls vtable+0xa4 on each node. Update/render dispatch pattern. No game globals but is game engine traversal code | engine_update_loop |
| 0x004e2130 | game_logic_isolated | MEDIUM | ChassisWorldTransform: computes world-space position from chassis transform using offsets +0x918/+0x91c/+0x920 (LocalOffset). Reads vehicle struct fields. Called from vehicle physics update | vehicle_physics_update |
| 0x0050cbb6 | utility_isolated | HIGH | Pure 4x4 matrix multiply. No game globals, no struct offsets. Math library utility, likely called inline or via function pointer | math_util_caller |
| 0x0050e19e | utility_isolated | HIGH | Quaternion Slerp. Reads DAT_0059e440 (cosine threshold) and _DAT_005ac9c0 (epsilon). Pure math utility, no game logic. Called from animation/transform interpolation | math_util_caller |
| 0x005196b8 | vtable_member | MEDIUM | Buffered Data Stream Write. Reads vtable pointers from param_1+0x180/+0x184/+0x188. Stream buffer flush/write via virtual dispatch. Called through stream object vtable | stream_write_code |
| 0x00537d10 | utility_isolated | HIGH | Adler-32 checksum algorithm. Pure data integrity utility, no game globals. Called from network/save data verification | checksum_caller |
| 0x0055ef24 | utility_isolated | HIGH | 3x3 matrix * float3 vector multiply. Pure math utility, no game globals | math_util_caller |
| 0x00575882 | utility_isolated | MEDIUM | Complex validation function with lookup table (108 entries). Compares 0x22 pairs of doubles against _DAT_0059e430 reference. Likely CD/save file validation or data integrity check. No game globals touched | validation_check_caller |
| 0x00588a19 | entry_point | HIGH | __local_unwind2 wrapper. MSVC SEH unwind handler for local destructors. Called from exception handler table, not game code directly | MSVC EH table |
| 0x0058e1b0 | entry_point | HIGH | _strlen CRT implementation. Aligned word-scan strlen. Called from any string operation in the game | CRT / any game code |
| 0x00598654 | entry_point | HIGH | select() Winsock import thunk. OS API call. Called from network code | network_socket_code |
| 0x00599081 | vtable_member | MEDIUM | Buffered Stream Read. Checks buffer at param_1[7], fallback to vtable calls at +0x14 and +0x08. Called through buffered stream object vtable | stream_read_code |
| 0x0059c6e8 | entry_point | HIGH | SEH Unwind: calls FUN_00587bcf (memory free). Compiler-generated exception handler for objects requiring cleanup | MSVC EH table |
| 0x0059cf70 | entry_point | HIGH | SEH Unwind Handler (Array Dtor): calls FUN_0058a5f7 to array-destruct stride 0x28 × 1 element. Compiler-generated | MSVC EH table |
| 0x0059d4d8 | entry_point | HIGH | SEH Unwind: calls FUN_0059a5e9. Compiler-generated exception handler | MSVC EH table |

=== FULL ENTRIES ===

(No new full entries needed — all 25 orphans classified above. Existing full entries in docs/ already cover game-logic functions. Utility/SEH/CRT functions have no new caller relationships to document.)

