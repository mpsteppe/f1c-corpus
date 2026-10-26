# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Two vehicle-physics functions. (1) computeInverse3x3CoordinateTransform (0x0056D020, owner MatrixTransformWorkspace, DERIVED) reads matrix/vector blocks from its workspace, transforms two input vectors with Matrix3x3VectorMultiply, computes cofactor-based inverse-matrix rows and additional matrix-vector products into the result buffer at this+0x10, and returns a pointer into that buffer; callers at 0x00439210 and 0x0056D930 depend on it. (2) PhysicsStateZeroInit (0x00579CCF, owner PhysicsSolverState, GUESS grouping) zero-initializes a large contiguous global solver-state region: 24 named doubles set directly to 0.0 and 34 blocks (24..272 bytes) cleared through sub_58BB10, returning the result of the final 272-byte block clear. No callers recorded for the zero-init; per-block semantics and the header/padding fields this+0x18 / this+0x20 remain unestablished.

## Function roles

- `0x0056D020` **MatrixTransformWorkspace** — Compute a 3x3 inverse coordinate transform: transform two input workspace vectors via Matrix3x3VectorMultiply, assemble cofactor-based inverse-matrix rows and matrix-vector products into the result buffer (this+0x10), and return a pointer into that buffer.
- `0x00579CCF` **PhysicsSolverState** — Zero-initialize a large global physics/dynamics solver state region: 24 named doubles written directly to 0.0 and 34 array/block bases cleared through sub_58BB10 (24..272 bytes each), returning the result of the final 272-byte block clear.

## Proposed classes

### MatrixTransformWorkspace

Holds input matrix/vector pointers and a result buffer; computeInverse3x3CoordinateTransform reads two matrix blocks, transforms two input vectors via Matrix3x3VectorMultiply, assembles cofactor-based inverse-matrix rows and matrix-vector products into the result buffer (this+0x10), and returns a pointer into it.

Methods: `0x0056D020`

- `this+0x00000004` `double* matrixPtr` (read, GUESS)
- `this+0x00000008` `double* vectorWorkspacePtr` (read, GUESS)
- `this+0x0000000C` `double* secondMatrixPtr` (read, GUESS)
- `this+0x00000010` `double* resultBufferPtr` (read_write, DERIVED)
- `this+0x00000018` `unknown blockHeaderPad0` (unknown, UNKNOWN)
- `this+0x00000020` `unknown blockHeaderPad1` (unknown, UNKNOWN)
- `this+0x00000028` `double cofactorDouble0` (write, GUESS)
- `this+0x00000030` `double cofactorDouble1` (write, GUESS)
- `this+0x00000038` `double cofactorDouble2` (write, GUESS)
- `this+0x00000040` `double cofactorDouble3` (write, GUESS)
- `this+0x00000048` `double cofactorDouble4` (write, GUESS)
- `this+0x00000050` `double cofactorDouble5` (write, GUESS)
- `this+0x00000058` `double productDouble0` (write, GUESS)
- `this+0x00000060` `double productDouble1` (write, GUESS)
- `this+0x00000068` `double productDouble2` (write, GUESS)
- `this+0x00000070` `double productDouble3` (write, GUESS)
- `this+0x00000078` `double productDouble4` (write, GUESS)
- `this+0x00000080` `double productDouble5` (write, GUESS)

### PhysicsSolverState

Hypothesized single owner of the global physics/dynamics solver state region (base 0x008D2120, span ~0x1860 bytes) that PhysicsStateZeroInit zero-initializes via direct double assignments and block clears through sub_58BB10. The packet evidences the region only as named globals (global:0x008D...), never as object-relative fields, so the 58 cleared locations are carried as class-level evidence references rather than modeled as fields; per-block semantics (constraint matrices, bias vectors, solver workspaces) are unestablished and common ownership is a GUESS.

Methods: `0x00579CCF`


## Compatibility contracts

- **InverseCoordinateTransformResultBuffer** — computeInverse3x3CoordinateTransform (0x0056D020) writes the inverse-transform result into the workspace buffer at this+0x10 (elements this+0x28 through this+0x80) and returns a pointer into that buffer; callers at 0x00439210 and 0x0056D930 rely on the returned pointer.
- **GlobalPhysicsSolverStateZeroInit** — PhysicsStateZeroInit (0x00579CCF) zero-initializes a contiguous global solver-state region beginning at 0x008D2120 and ending with the 272-byte block at 0x008D3870 (span ~0x1860 bytes), mixing direct double assignments with block clears through sub_58BB10; a replacement executable must preserve this global layout and the double alignment of the cleared blocks.
- **Matrix3x3VectorMultiplySemantics** — Matrix3x3VectorMultiply (0x00435E00) transforms an input vector by a 3x3 matrix; computeInverse3x3CoordinateTransform calls it twice on the two workspace input vectors, so a replacement must provide the same 3x3 vector-transform semantics for the two input-vector slots (this+0x04, this+0x08).

## Unresolved

- Mapping between individual source writes (result[0..14]) and the packet result-buffer field offsets (this+0x28..0x80) is not evidenced; fields are grouped by source region only.
- Roles of the header/padding fields at this+0x18 and this+0x20 (inside the pointed-to data blocks) are not attributable to any operation.
- The semantics of each cleared global block (constraint matrices, bias vectors, solver workspaces) are not established; the packet evidences the solver region only as named globals (global:0x008D...), so the 58 cleared locations are referenced at class level instead of being modeled as object fields. Grouping all globals into a single PhysicsSolverState class is a GUESS and common ownership is not proven by this packet.
- sub_58BB10 is an unverified block-zeroing helper; its exact operation (beyond zero-filling size bytes at a double-aligned address) is not evidenced in this packet.
- No caller is recorded for 0x00579CCF, so its role in the physics pipeline is unconfirmed.
