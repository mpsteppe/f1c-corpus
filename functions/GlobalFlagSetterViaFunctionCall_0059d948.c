char __stdcall GlobalFlagSetterViaFunctionCall(int a1, int a2)
{
  char v2; // al

  v2 = ShortComputation_bad0();
  *(_BYTE *)(dword_5C7530 + 128) = v2;
  return HUDFlagRendererSecondary(v2, 0, a1, a2);
}
