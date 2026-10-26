// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049DB80
// Canonical corpus name: BrakeWaterTemperatureHUDDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BrakeWaterTemperatureHUDDisplay_0049db80.c

void UnknownObject::BrakeWaterTemperatureHUDDisplay()
{
    // Renders the water, oil, and brake temperature HUD rows. Converts six Kelvin temperature globals to Celsius by subtracting 273.16, formats each label/value pair with StringFormatAndRender, and steps the Y position by dword_5CCBBC per row. Guarded on the render surface pointer at this+0x8.
    // ASSIGNMENT: Load layout globals into locals: v1 = dword_5CCBC0, v2 = dword_7CE238, v5 = dword_5CCBB8 (starting Y position); result = this[2] (render surface). [global:0x005CCBC0, global:0x007CE238, global:0x005CCBB8, field:this:0x00000008]
    // GUARD: If this[2] (render surface/texture pointer) is zero, return this[2] and skip all rendering. [field:this:0x00000008, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aWater, byte_5EC4CC): look up the water label and copy it into byte_5EC4CC, then copy that into the local buffer v28. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCEE8, global:0x005EC4CC]
    // CALL: StringFormatAndRender(buffer, dword_5CCBC0, v5, this[2], *(this[5]+84), 1): render the water label at the first row. [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALCULATION: Convert the water temperature Kelvin global to Celsius: v22 = dbl_7C91B4 - 273.16. [global:0x007C91B4]
    // CALL: sub_49DB00(v22, buffer): format the water temperature value into the buffer. [callee:0x0049DB00]
    // CALL: StringFormatAndRender(buffer, dword_7CE238, v5, this[2], *(this[5]+84), 0): render the water temperature value at the same row. [callee:0x0049F6A0, global:0x007CE238, field:this:0x00000008, field:this:0x00000014]
    // CALCULATION: Advance to the next row: v10 = dword_5CCBBC + v5. [global:0x005CCBBC]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aOil, byte_5EC4CC): look up the oil label and copy it into byte_5EC4CC, then into the local buffer v28. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCEE0, global:0x005EC4CC]
    // CALL: StringFormatAndRender(buffer, dword_5CCBC0, v10, this[2], *(this[5]+84), 1): render the oil label at the next row. [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALCULATION: Convert the oil temperature Kelvin global to Celsius: v23 = dbl_7C9174 - 273.16. [global:0x007C9174]
    // CALL: sub_49DB00(v23, buffer) then StringFormatAndRender(buffer, dword_7CE238, v10, ...): format and render the oil temperature value at its row. [callee:0x0049DB00, callee:0x0049F6A0, global:0x007CE238]
    // CALCULATION: Advance to the brake label row: v15 = dword_5CCBBC + v10. [global:0x005CCBBC]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aBrakes_0, byte_5EC4CC): look up the brakes label and copy it into byte_5EC4CC, then into the local buffer v28. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCED8, global:0x005EC4CC]
    // CALL: StringFormatAndRender(buffer, dword_5CCBC0, v15, this[2], *(this[5]+84), 1): render the brakes label at its row. [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALCULATION: Convert the first brake temperature Kelvin global to Celsius: v24 = dbl_7C7AB8 - 273.16, and advance to the value row v20 = dword_5CCBBC + v15. [global:0x007C7AB8, global:0x005CCBBC]
    // CALL: sub_49DB00(v24, buffer) then StringFormatAndRender(buffer, dword_5CCBC0, v20, ...): format and render the first brake temperature value. [callee:0x0049DB00, callee:0x0049F6A0, global:0x005CCBC0]
    // CALCULATION: Convert the second brake temperature Kelvin global to Celsius: v25 = dbl_7C7F1C - 273.16, and advance to the next row v21 = dword_5CCBBC + v20. [global:0x007C7F1C, global:0x005CCBBC]
    // CALL: sub_49DB00(v25, buffer) then StringFormatAndRender(buffer, dword_7CE238, v21, ...): format and render the second brake temperature value. [callee:0x0049DB00, callee:0x0049F6A0, global:0x007CE238]
    // CALCULATION: Convert the remaining brake temperature Kelvin globals to Celsius: v26 = dbl_7C8380 - 273.16 and v27 = dbl_7C87E4 - 273.16. [global:0x007C8380, global:0x007C87E4]
    // CALL: sub_49DB00(v26, buffer) then StringFormatAndRender(buffer, dword_5CCBC0, v21, ...): format and render the next brake temperature value. [callee:0x0049DB00, callee:0x0049F6A0, global:0x005CCBC0]
    // RETURN: Return the result of sub_49DB00(v27, buffer) and StringFormatAndRender(buffer, dword_7CE238, v21, ..., 0), the final brake temperature value row. [callee:0x0049DB00, callee:0x0049F6A0, global:0x007CE238]

    // Conservative worker pseudocode:
    //   int sub_49DB80(void *this) {
    //     int v1 = dword_5CCBC0, v2 = dword_7CE238, v5 = dword_5CCBB8;
    //     int result = this[2];
    //     if (result) {
    //       copyLabel(aWater, v28);
    //       StringFormatAndRender(v28, v1, v5, this[2], *(int*)(this[5]+84), 1);
    //       sub_49DB00(dbl_7C91B4 - 273.16, v28);
    //       StringFormatAndRender(v28, v2, v5, this[2], *(int*)(this[5]+84), 0);
    //       int v10 = v5 + dword_5CCBBC;
    //       copyLabel(aOil, v28);
    //       StringFormatAndRender(v28, v1, v10, this[2], *(int*)(this[5]+84), 1);
    //       sub_49DB00(dbl_7C9174 - 273.16, v28);
    //       StringFormatAndRender(v28, v2, v10, this[2], *(int*)(this[5]+84), 0);
    //       int v15 = v10 + dword_5CCBBC;
    //       copyLabel(aBrakes_0, v28);
    //       StringFormatAndRender(v28, v1, v15, this[2], *(int*)(this[5]+84), 1);
    //       int v20 = v15 + dword_5CCBBC;
    //       sub_49DB00(dbl_7C7AB8 - 273.16, v28);
    //       StringFormatAndRender(v28, v1, v20, this[2], *(int*)(this[5]+84), 1);
    //       sub_49DB00(dbl_7C7F1C - 273.16, v28);
    //       StringFormatAndRender(v28, v2, v20, this[2], *(int*)(this[5]+84), 0);
    //       int v21 = v20 + dword_5CCBBC;
    //       sub_49DB00(dbl_7C8380 - 273.16, v28);
    //       StringFormatAndRender(v28, v1, v21, this[2], *(int*)(this[5]+84), 1);
    //       sub_49DB00(dbl_7C87E4 - 273.16, v28);
    //       return StringFormatAndRender(v28, v2, v21, this[2], *(int*)(this[5]+84), 0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the trailing int parameter (0/1) of StringFormatAndRender are unknown here.
    // UNRESOLVED: Why six distinct temperature globals are rendered into three label/value pairs (water, oil, brakes) is not resolved; the mapping between global and row is taken from the call order only.
    // UNRESOLVED: Field this+0x68 is listed in the packet but not referenced by the raw source.
}
