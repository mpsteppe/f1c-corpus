// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479690
// Canonical corpus name: UISliderConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UISliderConstructor_00479690.c

void UnknownObject::UISliderConstructor()
{
    // UI slider component constructor: calls VTableSetInit(this, 0, 1061997773) to initialize the base UI component with parameters 0 and default float value 0.8 (1061997773) for the initial slider position, then installs the slider vtable pointer off_5A4B90 at this+0x0, overriding the base vtable. Returns this.
    // CALL: VTableSetInit(this, 0, 1061997773) initializes the base UI component with parameter 0 and default float 0.8 (1061997773) as the initial slider position. [callee:0x004795E0, function:0x00479690, source:raw]
    // ASSIGNMENT: Install the slider vtable pointer: this+0x0 = off_5A4B90, overriding the base vtable installed by VTableSetInit. [field:this:0x00000000, global:0x005A4B90, source:raw]
    // RETURN: Return the initialized this pointer. [function:0x00479690, source:raw]

    // Conservative worker pseudocode:
    //   void* UISliderConstructor(UnknownObject* this) {
    //     VTableSetInit(this, 0, 1061997773);
    //     this->vtable = &off_5A4B90;
    //     return this;
    //   }
    // UNRESOLVED: The exact UI component class and the meaning of parameter 0 / default float 0.8 are owned by the base VTableSetInit (004795E0) and not evidenced here.
    // UNRESOLVED: No static callers are evidenced; object creation path is unknown.
}
