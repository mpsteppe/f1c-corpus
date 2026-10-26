# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

Two independent helpers are reconstructed for the ui_platform_and_options scope. ConstraintComplianceMatrixBuild (0x004364A0) fills a 15-double constraint compliance matrix (this[0..14], fields +0x0..+0x70) from scalar and vector constraint parameters and returns nonzero iff any of the first 13 entries is non-zero; its caller 0x0043C250 defines the semantic roles of the parameters. SettingsPathBuilder (0x004A1EC0) concatenates the application directory (byte_5EA438), base path (asc_5CD148), a caller-supplied player identifier, and file suffix (asc_5CD144) into a path buffer, forwards the result to ShortComputation_1b70 (0x004A1B70), and returns that call's result. The two functions share no evidence of common ownership; both owners are reported as UnknownObject in the packet. The matrix fields are grounded in packet operations; the settings-path class and all names are synthesis.

## Function roles

- `0x004364A0` **ConstraintComplianceMatrix** — Builds the 3x5 constraint compliance matrix into a 15-double buffer (this[0..14], fields +0x0..+0x70) as products of input scalars and a5 vector components, plus two rows normalized by 1/sqrt(a2); returns nonzero if any of this[0..12] is non-zero. Parameter semantics are defined by caller 0x0043C250.
- `0x004A1EC0` **SettingsPathBuilder** — Builds a settings file path by copying the application directory (byte_5EA438) into a buffer, appending the base path (asc_5CD148), a caller-supplied player-specific identifier (a2), and the file suffix (asc_5CD144), then forwarding the completed path to ShortComputation_1b70 (0x004A1B70) and returning its result.

## Proposed classes

### ConstraintComplianceMatrix

Holds the 15-double (0x78-byte) constraint compliance matrix written by 0x004364A0. Entry semantics (3x5 layout, which entries carry products of which parameters, and the two 1/sqrt(a2)-normalized rows) are taken from packet operation descriptions; the class boundary itself is inferred because the packet owner is UnknownObject.

Methods: `0x004364A0`

- `this+0x00000000` `double entry_00` (read_write, DERIVED)
- `this+0x00000008` `double entry_01` (read_write, DERIVED)
- `this+0x00000010` `double entry_02` (read_write, DERIVED)
- `this+0x00000018` `double entry_10` (read_write, DERIVED)
- `this+0x00000020` `double entry_11` (read_write, DERIVED)
- `this+0x00000028` `double entry_12` (read_write, DERIVED)
- `this+0x00000030` `double entry_20` (read_write, DERIVED)
- `this+0x00000038` `double entry_21` (read_write, DERIVED)
- `this+0x00000040` `double entry_22` (read_write, DERIVED)
- `this+0x00000048` `double entry_30` (read_write, DERIVED)
- `this+0x00000050` `double entry_31` (read_write, DERIVED)
- `this+0x00000058` `double entry_40` (read_write, DERIVED)
- `this+0x00000060` `double entry_41` (read_write, DERIVED)
- `this+0x00000068` `double normalized_row_a` (write, DERIVED)
- `this+0x00000070` `double normalized_row_b` (write, DERIVED)

### SettingsPathBuilder

Constructs a settings file path in a local buffer by concatenating the application directory, a base file path, a player-specific identifier, and a file suffix, then passes it to 0x004A1B70 for further processing and returns that result. The buffer is local (not evidenced as a field), so no class fields are proposed.

Methods: `0x004A1EC0`


## Compatibility contracts

- **ConstraintMatrixLayoutAndReturn** — A replacement for 0x004364A0 must write 15 doubles into the this-referenced buffer at offsets +0x0..+0x70 (contiguous 0x78-byte layout) and return a non-zero value exactly when any of the first 13 entries (this[0]..this[12]) is non-zero. Caller 0x0043C250 relies on both the written matrix and the return value.
- **SettingsPathConcatenationOrder** — A replacement for 0x004A1EC0 must build the settings path by concatenating, in order: the application directory string (byte_5EA438), the base file path (asc_5CD148), the caller-supplied player identifier, and the file suffix (asc_5CD144); it must then call 0x004A1B70 with the completed path and propagate that call's return value. The referenced globals must remain readable as string data in the same order.

## Unresolved

- Read-only globals dbl_59E420 and dbl_59E430 are flagged by packet facts but do not appear in the raw decompiled source; their relation to the constraint matrix (e.g. coefficients used by caller 0x0043C250) is unknown.
- The meaning of parameters a2..a13 and the a5 vector in 0x004364A0 is inferred only from the compliance-matrix output shape; the caller 0x0043C250 defines their semantic roles.
- Identity of the player-specific identifier a2 and the exact meanings of the asc_5CD148 / asc_5CD144 path components.
- What ShortComputation_1b70 (0x004A1B70) does with the built path is outside this function's scope.
- The two functions share no evidence of common ownership or of belonging to a single UI/platform/options class despite sharing a scope grouping.
- Both owners are reported as UnknownObject in the packet; the proposed classes ConstraintComplianceMatrix and SettingsPathBuilder are synthesis, not confirmed source-level types.
