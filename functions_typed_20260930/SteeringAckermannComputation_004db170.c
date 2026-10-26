int __thiscall SteeringAckermannComputation(_DWORD *this)
{
  double v2; // st7
  int v3; // ebp
  int v4; // ebx
  const char *v5; // eax
  const char *v6; // esi
  int v7; // esi
  int v9; // [esp+10h] [ebp-88h]
  int v10; // [esp+10h] [ebp-88h]
  float v11; // [esp+14h] [ebp-84h]
  _BYTE v12[127]; // [esp+18h] [ebp-80h] BYREF
  char v13; // [esp+97h] [ebp-1h]

  if ( flt_5EA4E8 <= 0.0 )
    return 1;
  v2 = ShortComputation_8490(&flt_5EA4E8);
  v9 = CRTFtol(v2);
  v3 = 128;
  v4 = CRTFtol(v2);
  v5 = (const char *)this[4];
  if ( !v5 )
    v5 = byte_5EA438;
  if ( strcmp(v5, byte_5EA438) )
  {
    v6 = (const char *)this[4];
    if ( !v6 )
      v6 = byte_5EA438;
    if ( BinarySearchInStringTable(byte_5EC4C0, v6, byte_5EC4CC) )
    {
      if ( v6 )
        strcpy(byte_5EC4CC, v6);
      else
        byte_5EC4CC[0] = 0;
    }
    sub_587DD0(v12, byte_5EC4CC, 0x7Fu);
    v13 = 0;
    UITextRenderWithScale((int)v12, 100, v9, 0xFFFFFF, 0, 0, 1.0, 1.0);
  }
  if ( PackedFlagRead_9a00(&dword_8AB6EC) && flt_5EA4E8 == 1.0 )
  {
    v11 = sub_4B9A10((int *)&dword_8AB6EC);
    StringFormatWithBufferOverflowCheck(v12, (int)"%c", byte_5D4AEC);
    v7 = 0;
    v10 = 0;
    do
    {
      if ( (double)v10 * 0.025 > v11 )
        UITextRenderWithScale((int)v12, v3, v4, 0xFFFFFF, 0, 3, 1.0, 1.0);
      else
        UITextRenderWithScale((int)v12, v3, v4, 16711680, 0, 3, 1.0, 1.0);
      v3 += 25;
      v10 = ++v7;
    }
    while ( v7 <= 40 );
  }
  return 0;
}

