# VehiclePhysicsGlobalLifecycle

Scope: `vehicle_physics`  
Trust: `DERIVED`

Four thin wrappers over the static physics-object region near 0x008D44B8-0x008D4648. Three (0x0059980E destroyPhysicsBlock, 0x0059983B destroyPhysicsState, 0x00599868 DestroyPhysicsSolver) pass the address of a distinct global physics object to the CDestructorWithVTableChain helper and return its result unchanged, i.e. they are teardown trampolines that run each object's destructor chain through its virtual tables. The fourth (0x0059AAAF ValidatePhysicsState) passes the address of the global object at 0x008D4648 to a NullCheckWithVirtualDispatch helper and discards any result. The helper callees have no address evidence in the packet, class identity of every global is unknown, and no callers/ordering are evidenced.

## Function roles

- `0x0059980E` **PhysicsBlockGlobal** — Vtable-chain destructor wrapper over the global physics block object at 0x008D4510; calls CDestructorWithVTableChain with that global address and returns the helper result unchanged.
- `0x0059983B` **PhysicsStateGlobal** — Vtable-chain destructor wrapper over the global physics state object at 0x008D44B8; calls CDestructorWithVTableChain with that global address and returns the helper result unchanged.
- `0x00599868` **PhysicsSolverGlobal** — Zero-argument vtable-chain destructor wrapper over the global solver object at 0x008D45A0; calls CDestructorWithVTableChain with that global address and returns the helper result unchanged.
- `0x0059AAAF` **PhysicsStateValidatorGlobal** — Zero-argument wrapper that runs NullCheckWithVirtualDispatch against the global physics-state object at 0x008D4648; null-checks the object pointer before a virtual dispatch and returns nothing.

## Proposed classes

### PhysicsBlockGlobal

Static global physics block object at 0x008D4510. Opaque: destroyed through its virtual-table destructor chain via the wrapper at 0x0059980E. No internal layout recovered.

Methods: `0x0059980E`


### PhysicsStateGlobal

Static global physics state object at 0x008D44B8. Opaque: destroyed through its virtual-table destructor chain via the wrapper at 0x0059983B. No internal layout recovered.

Methods: `0x0059983B`


### PhysicsSolverGlobal

Static global physics solver object at 0x008D45A0. Opaque: destroyed through its virtual-table destructor chain via the wrapper at 0x00599868. 'PhysicsSolverWrapper' and the ABI lead are naming leads, not confirmed owners.

Methods: `0x00599868`


### PhysicsStateValidatorGlobal

Static global physics-state object at 0x008D4648. Opaque: subject of a null-checked virtual dispatch via the wrapper at 0x0059AAAF. The specific virtual method dispatched is not visible in the wrapper body.

Methods: `0x0059AAAF`


## Compatibility contracts

- **PhysicsGlobalVTableChainDestruction** — On shutdown the static physics objects at 0x008D44B8 (state), 0x008D4510 (block) and 0x008D45A0 (solver) must be destroyed by walking their virtual-table destructor chains; a replacement executable needs equivalent teardown entry points. The packet proves the wrappers exist and their single operand, but not the helper callee address, the call sites, or any ordering between the three destructions.
- **PhysicsStateNullCheckedValidation** — A validation entry point (0x0059AAAF) null-checks the global object at 0x008D4648 before a virtual dispatch on it; the replacement must preserve a null-guarded validation path rather than dispatching on an unchecked pointer. The specific dispatched virtual method is not evidenced.

## Unresolved

- The absolute addresses of the CDestructorWithVTableChain and NullCheckWithVirtualDispatch helpers are absent from the packet callee evidence, so no callee address can be cited.
- Class identity and concrete type of each global object (0x008D44B8, 0x008D4510, 0x008D45A0, 0x008D4648) are unknown; all are unk_/dword_ labels.
- Whether the wrappers are static exit/teardown trampolines or live-method call sites is unresolved; the packet carries no caller evidence.
- The globals sit in the same static-object region, but the packet does not prove common ownership, so they are kept as separate objects rather than merged into a shared struct.
- No destruction ordering or trigger path between the three destructor wrappers is evidenced.
- The specific virtual method dispatched by the NullCheckWithVirtualDispatch helper at 0x0059AAAF is not visible in the wrapper body.
- The IPhysicsGlobalLifecycle interface is a GUESS grouping; the packet contains no vtable, base-class, or shared-interface evidence tying the four wrappers together.
