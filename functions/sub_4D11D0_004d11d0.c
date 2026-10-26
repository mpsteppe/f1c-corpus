char __stdcall sub_4D11D0(float a1, const char *a2)
{
  const char *v2; // esi
  double v3; // st7
  double v4; // st7
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v9; // [esp+8h] [ebp-84h]
  char v10[128]; // [esp+Ch] [ebp-80h] BYREF
  float v11; // [esp+90h] [ebp+4h]

  v2 = a2;
  if ( !a2 )
    v2 = byte_5EA438;
  v3 = a1 + 1.0;
  v11 = v3;
  v4 = v3 + 1.0;
  v5 = CRTFtol(v4);
  v6 = CRTFtol(v4);
  StringFormatWithBufferOverflowCheck(v10, "%s%02d:%02d", v2, v5, v6);
  ShortComputation_bde0((_DWORD **)&dword_7CD204, v10, 0);
  v9 = CRTFtol(v11 * 0.016666668);
  v7 = CRTFtol(v11 - (double)v9 * 60.0);
  StringFormatWithBufferOverflowCheck(v10, "%s%02d:%02d", v2, v9, v7);
  return TextLineWrappingAndRendering(&dword_7CD204, (int)v10, 3, 16909060);
}
