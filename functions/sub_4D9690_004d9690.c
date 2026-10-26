int __stdcall sub_4D9690(int a1, float a2, float a3)
{
  int result; // eax
  unsigned int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // eax
  double v9; // st7
  int v10; // eax
  int v11; // [esp-Ch] [ebp-B0h]
  int v12; // [esp+18h] [ebp-8Ch] BYREF
  int v13; // [esp+1Ch] [ebp-88h] BYREF
  float v14; // [esp+20h] [ebp-84h]
  CHAR SrcStr[127]; // [esp+24h] [ebp-80h] BYREF
  char v16; // [esp+A3h] [ebp-1h]
  float v17; // [esp+B0h] [ebp+Ch]

  result = 1;
  if ( a1 )
  {
    v4 = *(_DWORD *)(a1 + 16480) - 1;
    if ( v4 <= 0x18 )
    {
      StringFormatWithBufferOverflowCheck(SrcStr, "%c", (char)(v4 + byte_5D4AE8));
      v11 = CRTFtol(a3);
      v5 = CRTFtol(a2);
      UITextRenderWithScale((int)SrcStr, v5, v11, 0xFFFFFF, 0, 3, 3.0, 3.0);
    }
    sub_587DD0(SrcStr, a1 + 18168, 127);
    v16 = 0;
    sub_589901(SrcStr);
    v6 = CRTFtol(a2 + 110.0);
    v7 = CRTFtol(a3);
    UITextRenderWithScale((int)SrcStr, v6, v7, 0xFFFFFF, 0, 0, 1.0, 1.0);
    sub_587DD0(SrcStr, a1 + 18104, 127);
    v16 = 0;
    sub_589901(SrcStr);
    v17 = a3 + 40.0;
    v8 = CRTFtol(v17);
    UITextRenderWithScale((int)SrcStr, v6, v8, 4762291, 0, 0, 1.0, 1.0);
    v9 = *(float *)(a1 + 16476);
    v14 = *(float *)(a1 + 16476);
    if ( v9 >= 0.0 )
    {
      v13 = 0;
      *(float *)&v12 = 0.0;
      SpatialGridCell(v14, &v13, (float *)&v12);
      StringFormatWithBufferOverflowCheck(SrcStr, "%.2d:%06.3f", v13, *(float *)&v12);
    }
    else
    {
      sub_587DD0(SrcStr, asc_5CCE18, 127);
      v16 = 0;
    }
    v10 = CRTFtol(v17 + 40.0);
    UITextRenderWithScale((int)SrcStr, v6, v10, 16776960, 0, 0, 1.0, 1.0);
    return 0;
  }
  return result;
}
