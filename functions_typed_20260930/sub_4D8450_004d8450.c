int __thiscall sub_4D8450(int this)
{
  _BYTE *v2; // ecx
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // edi
  __int16 *v7; // ebp
  BOOL v8; // eax
  int v9; // eax
  char v10; // cl
  _BYTE *v11; // edx
  int v12; // eax
  char v13; // cl
  BOOL v14; // eax
  int v15; // eax
  char v16; // cl
  int v17; // eax
  char v18; // cl
  _BYTE *v19; // ecx
  _BYTE v20[127]; // [esp+8h] [ebp-100h] BYREF
  char v21; // [esp+87h] [ebp-81h]
  _BYTE v22[127]; // [esp+88h] [ebp-80h] BYREF
  char v23; // [esp+107h] [ebp-1h]

  HUDFlagRendererMain((_DWORD *)this);
  if ( *(_DWORD *)this != -1 && flt_5EA4E8 <= 0.0 )
  {
    if ( *(float *)(this + 220) <= 0.0 )
    {
      v2 = *(_BYTE **)(this + 4 * *(_DWORD *)this + 16);
      if ( v2 )
      {
        if ( VTableDispatchChain_7e00(v2) == 1 )
        {
          *(_DWORD *)this = -1;
          *(_DWORD *)(this + 220) = 1056964608;
        }
      }
      else
      {
        *(_DWORD *)this = -1;
      }
    }
    else
    {
      *(float *)(this + 220) = *(float *)(this + 220) - dbl_8AFE98;
    }
  }
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != -1 && VTableDispatchChain_7e00(*(_BYTE **)(this + 4 * v3 + 116)) == 1 )
    *(_DWORD *)(this + 4) = -1;
  v4 = *(_DWORD *)(this + 8);
  if ( v4 != -1 )
    VTableDispatchChain_7e00(*(_BYTE **)(this + 4 * v4 + 12));
  result = dword_7CB218;
  v6 = 0;
  if ( dword_7CB218 > 0 )
  {
    v7 = word_7CB21C;
    while ( *v7 != 3 )
    {
      if ( *v7 == 4 )
      {
        v8 = dword_7CF638 == 0;
        dword_7CF638 = v8;
        if ( !v8 )
        {
          sub_4D8760(-1, 0);
          if ( BinarySearchInStringTable(byte_5EC4C0, aBroadcastDispl_0, byte_5EC4CC) )
          {
            v12 = 0;
            do
            {
              v13 = aBroadcastDispl_0[v12];
              byte_5EC4CC[v12++] = v13;
            }
            while ( v13 );
          }
          sub_587DD0(v20, byte_5EC4CC, 127);
          v21 = 0;
          TextLineWrappingAndRendering(&dword_7CD204, (int)v20, 3, 16909060);
          goto LABEL_37;
        }
        if ( BinarySearchInStringTable(byte_5EC4C0, aBroadcastDispl, byte_5EC4CC) )
        {
          v9 = 0;
          do
          {
            v10 = aBroadcastDispl[v9];
            byte_5EC4CC[v9++] = v10;
          }
          while ( v10 );
        }
        sub_587DD0(v20, byte_5EC4CC, 127);
        v21 = 0;
        v11 = v20;
        goto LABEL_36;
      }
LABEL_37:
      result = dword_7CB218;
      ++v6;
      ++v7;
      if ( v6 >= dword_7CB218 )
        goto LABEL_38;
    }
    v14 = dword_7CF788 == 0;
    dword_7CF788 = v14;
    if ( v14 )
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, aHudOn, byte_5EC4CC) )
      {
        v15 = 0;
        do
        {
          v16 = aHudOn[v15];
          byte_5EC4CC[v15++] = v16;
        }
        while ( v16 );
      }
      sub_587DD0(v22, byte_5EC4CC, 127);
      v23 = 0;
      TextLineWrappingAndRendering(&dword_7CD204, (int)v22, 3, 16909060);
      goto LABEL_37;
    }
    IndexValidationSetter(-1);
    if ( BinarySearchInStringTable(byte_5EC4C0, aHudOff, byte_5EC4CC) )
    {
      v17 = 0;
      do
      {
        v18 = aHudOff[v17];
        byte_5EC4CC[v17++] = v18;
      }
      while ( v18 );
    }
    sub_587DD0(v22, byte_5EC4CC, 127);
    v23 = 0;
    v11 = v22;
LABEL_36:
    TextLineWrappingAndRendering(&dword_7CD204, (int)v11, 3, 16909060);
    goto LABEL_37;
  }
LABEL_38:
  if ( *(_BYTE *)(this + 236) )
  {
    v19 = *(_BYTE **)(this + 216);
    if ( v19 )
    {
      result = dword_5EA528;
      if ( dword_5EA518 != dword_5EA528 || *(_DWORD *)(dword_5EA528 + 52) != 1 )
        return VTableDispatchChain_7e00(v19);
    }
  }
  return result;
}

