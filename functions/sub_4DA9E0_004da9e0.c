int __thiscall sub_4DA9E0(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // ebp
  int v6; // eax
  char v7; // cl
  double v8; // st7
  double v9; // st7
  double v11; // [esp+0h] [ebp-128h]
  int v12; // [esp+14h] [ebp-114h] BYREF
  int v13; // [esp+18h] [ebp-110h] BYREF
  int v14; // [esp+1Ch] [ebp-10Ch] BYREF
  int v15; // [esp+20h] [ebp-108h] BYREF
  int v16; // [esp+24h] [ebp-104h] BYREF
  CHAR SrcStr[127]; // [esp+28h] [ebp-100h] BYREF
  char v18; // [esp+A7h] [ebp-81h]
  _BYTE v19[125]; // [esp+A8h] [ebp-80h] BYREF
  __int16 v20; // [esp+125h] [ebp-3h]
  char v21; // [esp+127h] [ebp-1h]

  SrcStr[0] = byte_5EA438[0];
  memset(&SrcStr[1], 0, 126);
  v18 = 0;
  v19[0] = byte_5EA438[0];
  memset(&v19[1], 0, 0x7Cu);
  v20 = 0;
  v21 = 0;
  SizeOffsetTableByMode(a2, &v14, &v16, &v13);
  v4 = *(_DWORD *)(a3 + 16480);
  v5 = v4 - 1;
  if ( v4 == 1 )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, aLaps_0, byte_5EC4CC) )
    {
      v6 = 0;
      do
      {
        v7 = aLaps_0[v6];
        byte_5EC4CC[v6++] = v7;
      }
      while ( v7 );
    }
    StringFormatWithBufferOverflowCheck(v19, "%d %s", this[9], byte_5EC4CC);
  }
  else
  {
    *(float *)&v12 = ArithmeticComparison_ad50(this);
    v8 = SingleFunctionCallWrapper_ad30(a3);
    if ( v8 > 0.0 )
    {
      v9 = v8 - *(float *)&v12;
      *(float *)&v12 = v9;
      if ( v9 > 0.0 )
      {
        SpatialGridCell(*(float *)&v12, &v15, (float *)&v12);
        v11 = *(float *)&v12;
        if ( v15 <= 0 )
          StringFormatWithBufferOverflowCheck(v19, "%.3f", v11);
        else
          StringFormatWithBufferOverflowCheck(v19, "%d:%06.3f", v15, v11);
      }
    }
  }
  StringFormatWithBufferOverflowCheck(SrcStr, "%c", v5 + byte_5D4AE8);
  UITextRenderWithScale((int)SrcStr, v14, v13, 0xFFFFFF, 0, 3, 1.0, 1.0);
  sub_587DD0(SrcStr, a3 + 18168, 127);
  v18 = 0;
  sub_589901(SrcStr);
  v14 += 40;
  UITextRenderWithScale((int)SrcStr, v14, v13, 0xFFFFFF, 0, 0, 1.0, 1.0);
  sub_587DD0(SrcStr, v19, 127);
  v18 = 0;
  return UITextRenderWithScale((int)SrcStr, v16, v13, 16776960, 1, 0, 1.0, 1.0);
}
