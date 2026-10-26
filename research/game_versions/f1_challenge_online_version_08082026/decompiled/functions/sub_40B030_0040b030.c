int __thiscall sub_40B030(_DWORD *this, int a2)
{
  int v3; // ebp
  _BYTE *v4; // esi
  int v5; // edi
  int v6; // esi
  int v7; // eax
  _UNKNOWN **v8; // esi
  int v9; // edi
  _BYTE *v11; // edi
  int *v12; // eax
  _DWORD *v13; // ebp
  _DWORD *v14; // edi
  _DWORD *v15; // eax
  int v16; // edi
  int v17; // esi
  _UNKNOWN **v18; // esi
  int v19; // edi
  int v20; // [esp+10h] [ebp-5438h]
  _BYTE v21[28]; // [esp+14h] [ebp-5434h] BYREF
  char v22[384]; // [esp+30h] [ebp-5418h] BYREF
  int v23; // [esp+1B0h] [ebp-5298h]
  char v24; // [esp+1B4h] [ebp-5294h]
  int v25; // [esp+1BCh] [ebp-528Ch]
  int v26; // [esp+1C0h] [ebp-5288h]
  int v27; // [esp+1C4h] [ebp-5284h]
  _BYTE v28[384]; // [esp+1C8h] [ebp-5280h] BYREF
  CHAR v29[256]; // [esp+348h] [ebp-5100h] BYREF
  _BYTE v30[20480]; // [esp+448h] [ebp-5000h] BYREF
  _UNKNOWN *retaddr; // [esp+5448h] [ebp+0h] BYREF

  sub_5668B0(v21);
  v3 = 0;
  memset(v28, 0, sizeof(v28));
  v23 = 0;
  v27 = 0;
  v25 = 0;
  v26 = 0;
  v24 = 1;
  v4 = v30;
  v5 = 128;
  do
  {
    sub_4571E0(v4);
    v4 += 160;
    --v5;
  }
  while ( v5 );
  v6 = 0;
  v7 = sub_544F50(aMainview);
  if ( v7 )
    this[1] = v7;
  if ( (unsigned __int8)sub_566B20(a2, 1) )
  {
    if ( !sub_566CC0(v28, 384) )
      goto LABEL_27;
    v11 = v30;
    do
    {
      if ( !sub_5651B0(v22) && sub_565520(aStaticcam, v29, 0) && v6 < 128 )
      {
        sub_4572B0(v21, v29);
        ++v6;
        v11 += 160;
      }
    }
    while ( sub_566CC0(v28, 384) );
    if ( v6 > 0 )
    {
      v12 = (int *)sub_587C03(160 * v6 + 4);
      if ( v12 )
      {
        v13 = v12 + 1;
        *v12 = v6;
        v14 = v12 + 1;
        if ( v6 - 1 >= 0 )
        {
          v20 = v6;
          do
          {
            sub_4571E0(v14);
            v14 += 40;
            --v20;
          }
          while ( v20 );
        }
        v15 = v13;
        v3 = 0;
      }
      else
      {
        v15 = 0;
      }
      v16 = 0;
      this[3] = v15;
      this[4] = v6;
      this[5] = 0;
      v17 = 0;
      do
      {
        sub_457B60(&v30[v17]);
        ++v16;
        v17 += 160;
      }
      while ( v16 < this[4] );
    }
    else
    {
LABEL_27:
      v3 = 1;
    }
    sub_566B90(v21);
    v18 = &retaddr;
    v19 = 128;
    do
    {
      v18 -= 40;
      sub_4562A0(v18);
      --v19;
    }
    while ( v19 );
    sub_5668D0(v21);
    return v3;
  }
  else
  {
    v8 = &retaddr;
    v9 = 128;
    do
    {
      v8 -= 40;
      sub_4562A0(v8);
      --v9;
    }
    while ( v9 );
    sub_5668D0(v21);
    return 1;
  }
}
