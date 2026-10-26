// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040F1C0
// Canonical corpus name: SceneObjectLoaderStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneObjectLoaderStateMachine_0040f1c0.c

void UnknownObject::SceneObjectLoaderStateMachine()
{
    // Seven-mode state machine (mode selector at this+0x1C) that loads or unloads a scene object. Modes 0-5 call sub_45A8E0 against the position buffer at this+0xC to decide between a clear path (CameraShakeRingBufferWrite + sub_4BDE20, return 0) and a keep path (sub_4BDE20, return the check result). Mode 6 gates VehiclePhysicsModeDispatcher on bit 8 of the sub-object vtable entry at (*(this+0x20)+0x0)+0x48BC, runs SuspensionStateUpdate on the sub-object, copies its position triple at +0x34D4/0x34D8/0x34DC into this+0xC/0x10/0x14, then returns 1.
    // STATE_TRANSITION: Per-frame tick invoked from LoopWithConditionalSkipFunction (frame-path enabled). [caller:0x00410980, function:0x0040F1C0]
    // GUARD: Dispatch on the mode selector at this+0x1C across 7 states via the jump table jpt_40F1D0. [field:this:0x0000001C, global:0x0040F2D8]
    // CALL: sub_45A8E0(a2, position pointer this+0xC) checks sub-object status; the result routes each mode to the clear or keep path. [callee:0x0045A8E0, field:this:0x0000000C]
    // CALL: Clear path: CameraShakeRingBufferWrite(this) then sub_4BDE20(this); returns 0. [callee:0x0040F600, callee:0x004BDE20]
    // CALL: Keep path (LABEL_12): sub_4BDE20(this); returns the sub_45A8E0 result. [callee:0x004BDE20]
    // GUARD: Mode 6: bit 8 of the vtable entry at (*(this+0x20)+0x0)+0x48BC gates VehiclePhysicsModeDispatcher. [field:*(this+0x20):0x00000000, field:*(*(this+0x20)+0x0):0x000048BC]
    // CALL: VehiclePhysicsModeDispatcher(a2) when the vtable gate bit is set. [callee:0x004E4930]
    // CALL: SuspensionStateUpdate on the sub-object pointer held at this+0x20. [callee:0x004E9600, field:this:0x00000020]
    // ASSIGNMENT: Copy the sub-object position triple at +0x34D4/0x34D8/0x34DC into this+0xC/0x10/0x14. [field:*(this+0x20):0x000034D4, field:*(this+0x20):0x000034D8, field:*(this+0x20):0x000034DC, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014]
    // RETURN: Mode 6 returns 1 after sub_4BDE20; other modes return the check result or 0. [source:raw]

    // Conservative worker pseudocode:
    //   switch (this->dword[0x1C]) {
    //       case 0: case 3: v3 = sub_45A8E0(a2, this + 0xC); if (v3) goto KEEP; goto CLEAR
    //       case 1: case 4: v3 = sub_45A8E0(a2, this + 0xC); if (!v3) goto CLEAR; goto KEEP
    //       case 2: case 5: v3 = sub_45A8E0(a2, this + 0xC); if (v3) goto KEEP; goto CLEAR
    //       CLEAR:
    //           CameraShakeRingBufferWrite(this)
    //           sub_4BDE20(this)
    //           return 0
    //       case 6:
    //           if ((*(*(*(this + 0x20)) + 0x48BC) & 8) != 0) VehiclePhysicsModeDispatcher(a2)
    //           SuspensionStateUpdate(*(this + 0x20))
    //           copy (*(this+0x20)+0x34D4..0x34DC) to (this+0xC..0x14)
    //           sub_4BDE20(this)
    //           return 1
    //       default: v3 = 0;
    //       KEEP:
    //           sub_4BDE20(this)
    //           return v3
    //   }
    // UNRESOLVED: dword_8AB710 appears in the IDB global list but is not referenced by the raw source (possibly reachable only through the jump table analysis).
    // UNRESOLVED: The exact meaning of the sub_45A8E0 result per mode (status of a sub-object) is a DERIVED interpretation.
    // UNRESOLVED: abi:lead LEGACY name Scene_Object_Loader_State_Machine is retained as a lead only; owner remains UnknownObject.
}
