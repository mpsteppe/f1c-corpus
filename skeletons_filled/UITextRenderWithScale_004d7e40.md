## UITextRenderWithScale_004d7e40 — UITextRenderWithScale

**Summary:** Renders UI text with horizontal/vertical scaling. Looks up render context via SwitchBasedGlobalLookup, applies scale factors (a7, a8), computes scaled position with alignment (left or center), renders via sub_553070 to D3D device, restores original context scale. Heavily called across UI rendering.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TimerClockFormat (004d8130), StartingGridUIDraw (004d9420), sub_4D9690 (004d9690), TimerCountdown (004d98a0), HUDVenue (004d99e0), TimerDisplayRender (004d9dd0), sub_4DA0D0 (004da0d0), sub_4DA9E0 (004da9e0), SteeringAckermannComputation (004db170), PositionOrderNameDisplay (004db6f0), sub_4DB7F0 (004db7f0), UtilityFunction_b9a0 (004db9a0), UIMessageCompose (004dba00), HUDFlagRendererSecondary (004dbac3), DrawDebugTextOverlay (004dbb60), MultiLayerTextStringRenderer (004dbc90), TextRenderWithShadow (004dbde0), MultiLayerTextRendering (004dbe60), MultiColorTextRender (004dbf90), UIDebugOverlayRender (004dc0b0), DoubleRenderPass (004dc1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8dc8 | dword_8B8DC8 | R | render device pointer (D3D device/renderer interface) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7f20 | CenteredPosition | computes centered text position based on string width |
| 004d7f60 | SizeComputationWithSubtraction | computes left-aligned text position |
| 004d7fa0 | SwitchBasedGlobalLookup | looks up render context/font structure by ID |
| 00552fc0 | FieldSetterAt0x48 | sets some field at offset 0x48 in UI/render struct |
| 00553070 | sub_553070 | core text rendering function (draws to render device) |
| 00587bdc | CRTFtol | CRT float-to-integer truncation conversion |

**Guard conditions:** if SwitchBasedGlobalLookup(a6) returns null (no render context found), skip all rendering and return immediately.
