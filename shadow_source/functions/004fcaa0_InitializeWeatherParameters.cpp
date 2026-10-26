// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FCAA0
// Canonical corpus name: sub_4FCAA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FCAA0_004fcaa0.c

void UnknownObject::InitializeWeatherParameters()
{
    // Initializes a weather parameter block on this. Optionally persists a generated weather conditions file (weather.txt) when the global guard dword_7CF080 is clear, resets state fields to sentinel values, scales packed short color components into floats, computes a derived weather timing factor from the field at offset 224, installs blend/half factors and range/default constants, then delegates cloud/skybox scene setup to sub_4FBA10. Called from Game_Init.
    // CALL: Run linked-list/dual-list teardown before any initialization. [callee:0x004FD840]
    // GUARD: Guard on global flag dword_7CF080; when zero the weather.txt generation block runs. [global:0x007CF080]
    // CALL: sub_4FD8B0(0.0, 432000.0) prepares the weather conditions range using the floats read from flt_59E444 and flt_59E460. [callee:0x004FD8B0, global:0x0059E444, global:0x0059E460]
    // CALCULATION: Select the base directory string: dword_5EC438 when non-null, otherwise byte_5EA438. [global:0x005EC438, global:0x005EA438]
    // CALL: StringFormatWithBufferOverflowCheck builds the path "%sweather.txt" from the selected directory string. [callee:0x0058815F, global:0x005D6F68]
    // CALL: WeatherConditionsFileWriter writes the generated conditions file to the formatted path. [callee:0x004FE820]
    // ASSIGNMENT: Reset weather state: field +12 to 1.0f, field +16 to -1 (invalid sentinel), fields +24 and +164 to -1.0f sentinel. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000018, field:this:0x000000A4]
    // CALL: ShortFieldAccessor reads three packed short color components into local outputs. [callee:0x005439F0]
    // CALCULATION: Scale the packed short components: fields +180, +184, +188 = component * 0.0039215689 (a /255 color scaling). [field:this:0x000000B4, field:this:0x000000B8, field:this:0x000000BC]
    // CALL: GetOrientationAngleValues retrieves orientation angle values into the two output slots. [callee:0x00543A30]
    // CALL: FieldGetter_3a60 reads a field value from offset +224 used later in the weather timing formula. [callee:0x00543A60]
    // CALL: ClampedReciprocalWithGuard(1040187392) performs a guarded reciprocal computation on the guard constant. [callee:0x004FEFC0]
    // CALCULATION: Compute v3 = 0.0099999998 - field(+224); the value at offset +224 feeds the weather timing blend. [field:this:0x000000E0]
    // ASSIGNMENT: Set weather blend factors: fields +192, +196, +200 to 0.75f. [field:this:0x000000C0, field:this:0x000000C4, field:this:0x000000C8]
    // CALCULATION: Derive the weather timing factor: field +236 = (0.0099999998 - field(+224)) * field(+168) + field(+224). [field:this:0x000000A8, field:this:0x000000EC]
    // ASSIGNMENT: Set weather half factors: fields +204, +208, +212 to 0.5f. [field:this:0x000000CC, field:this:0x000000D0, field:this:0x000000D4]
    // ASSIGNMENT: Install range and default constants: field +240 to 0, field +244 to 150.0f, field +248 to 0.01f, field +228 to 175.0f, field +232 to 675.0f. [field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000E4, field:this:0x000000E8]
    // CALL: ValueClampRange(0.5, 0.0) clamps a value to the 0.0..0.5 range. [callee:0x004FF040]
    // CALL: sub_4FBA10 performs cloud/skybox scene-graph setup on the block starting at this + 264. [callee:0x004FBA10]
    // ASSIGNMENT: Clear a status byte at this + 452 to 0 after setup. [field:this:0x000001C4]
    // RETURN: Return the result of sub_4FBA10. [source:raw]

    // Conservative worker pseudocode:
    //   DualLinkedListDestruction();
    //   if (!dword_7CF080) {
    //     sub_4FD8B0(0.0, 432000.0);
    //     base = dword_5EC438 ? dword_5EC438 : byte_5EA438;
    //     StringFormatWithBufferOverflowCheck(buf, "%sweather.txt", base);
    //     WeatherConditionsFileWriter(buf);
    //   }
    //   set_float(this + 12, 1.0f);  set_int(this + 16, -1);
    //   set_float(this + 24, -1.0f); set_float(this + 164, -1.0f);
    //   ShortFieldAccessor(&r, &g, &b);
    //   set_float(this + 180, r * 0.0039215689);
    //   set_float(this + 184, g * 0.0039215689);
    //   set_float(this + 188, b * 0.0039215689);
    //   GetOrientationAngleValues(this + 216, this + 220);
    //   FieldGetter_3a60(this + 224);
    //   ClampedReciprocalWithGuard(1040187392);
    //   v3 = 0.0099999998 - get_float(this + 224);
    //   set_float(this + 192, 0.75f); set_float(this + 196, 0.75f); set_float(this + 200, 0.75f);
    //   set_float(this + 236, v3 * get_float(this + 168) + get_float(this + 224));
    //   set_float(this + 204, 0.5f); set_float(this + 208, 0.5f); set_float(this + 212, 0.5f);
    //   set_float(this + 240, 0.0f);  set_float(this + 244, 150.0f); set_float(this + 248, 0.01f);
    //   set_float(this + 228, 175.0f); set_float(this + 232, 675.0f);
    //   ValueClampRange(0.5, 0.0);
    //   result = sub_4FBA10(this + 264);
    //   set_byte(this + 452, 0);
    //   return result;
    // UNRESOLVED: Global dword_8AFE88 is read but does not appear in the raw source body of this function; its role is unknown here.
    // UNRESOLVED: Semantic meaning of individual weather fields (blend factors, range limits, timing factor) is inferred from literal values and is not independently verified.
}
