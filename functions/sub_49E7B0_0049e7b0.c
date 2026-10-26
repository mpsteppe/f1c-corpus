void __stdcall sub_49E7B0(int a1, int a2, int a3, int a4, int a5)
{
  double v5; // st7
  int v6; // ecx
  int v7; // eax
  int v8; // [esp-4h] [ebp-14h]
  float v9; // [esp+14h] [ebp+4h]

  if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
  {
    v5 = (*(double *)((char *)&unk_7C7A48 + 1124 * a1) - 0.75) * 4.0;
    v9 = v5;
    if ( v5 >= 0.0 )
    {
      if ( v9 > 1.0 )
        v9 = 1.0;
    }
    else
    {
      v9 = 0.0;
    }
    RenderDrawOperationWithClipping(a2, a3, a4, a5, -16777216);
    if ( v9 > 0.0 )
    {
      v6 = -65536;
      if ( v9 <= 0.80000001 )
      {
        if ( v9 > 0.5 )
          v6 = -256;
      }
      else
      {
        v6 = -16711936;
      }
      v8 = v6;
      v7 = CRTFtol((double)a4 * v9);
      RenderDrawOperationWithClipping(a2, a3, v7, a5, v8);
    }
  }
  else
  {
    RenderDrawOperationWithClipping(a2, a3, a4, a5, -16711936);
  }
}
