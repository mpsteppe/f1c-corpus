int __thiscall sub_475150(_DWORD *this)
{
  int v2; // eax
  char *v3; // edx
  char v4; // cl
  int v5; // edi
  int v6; // esi
  char *v7; // eax
  char v8; // cl
  unsigned int v9; // edx
  int v10; // eax
  char *v11; // eax
  int v12; // eax
  char v13; // cl
  int v15; // eax
  char v16; // cl
  char v17; // [esp+15h] [ebp-20Dh] BYREF
  int v18; // [esp+16h] [ebp-20Ch]
  int v19; // [esp+1Ah] [ebp-208h]
  int v20; // [esp+1Eh] [ebp-204h]
  char v21[16]; // [esp+22h] [ebp-200h] BYREF
  _BYTE v22[16]; // [esp+32h] [ebp-1F0h] BYREF
  char v23[32]; // [esp+42h] [ebp-1E0h] BYREF
  char v24[112]; // [esp+62h] [ebp-1C0h] BYREF
  __int16 v25; // [esp+D2h] [ebp-150h]
  char v26[128]; // [esp+E2h] [ebp-140h] BYREF
  char v27[64]; // [esp+162h] [ebp-C0h] BYREF
  char v28[128]; // [esp+1A2h] [ebp-80h] BYREF

  v28[0] = 0;
  v2 = sub_489920(this);
  if ( v2 )
  {
    v3 = &v28[-v2];
    do
    {
      v4 = *(_BYTE *)v2;
      v3[v2] = *(_BYTE *)v2;
      ++v2;
    }
    while ( v4 );
  }
  sub_489CB0(this);
  v5 = sub_461FF0(dword_7CD25C);
  v20 = v5;
  v18 = 0;
  if ( v5 > 0 && !sub_461FC0(dword_7CD25C) )
  {
    sub_462160(dword_7CD25C, dword_7D1020, 0, 0);
    v6 = 0;
    v19 = 0;
    do
    {
      sub_461550(v24);
      v27[0] = 0;
      if ( (unsigned __int8)((int (__thiscall *)(_DWORD *, int, char *, char *, int, char *))loc_462010)(
                              dword_7CD25C,
                              v6,
                              v24,
                              v27,
                              64,
                              &v17)
        && v25 < 9999 )
      {
        v26[0] = 0;
        strcat(v26, v24);
        sub_4894D0(v26);
        if ( sub_423A00(byte_5EC4C0, v27, byte_5EC4CC) )
        {
          v7 = byte_5EC4CC;
          do
          {
            v8 = v7[v27 - byte_5EC4CC];
            *v7++ = v8;
          }
          while ( v8 );
        }
        strcat(v26, byte_5EC4CC);
        sub_4894D0(v26);
        v23[0] = 0;
        sub_58815F(v23, "%d/%d", v24[101], v24[102]);
        strcat(v26, v23);
        sub_4894D0(v26);
        v21[0] = 0;
        sub_58815F(v21, "%d", v25);
        v9 = strlen(v21) + 1;
        v10 = v19;
        qmemcpy(&v26[strlen(v26)], v21, v9);
        sub_58815F(v22, "%d", v10);
        v11 = (char *)this[46];
        if ( !v11 )
          v11 = byte_5EA438;
        sub_489600(v26, v11, byte_5EA438, v22, 0);
        if ( v17 )
        {
          sub_489C10(this[37] - 1, aFtim14greyoutl);
        }
        else if ( sub_4615F0(v24, 2) )
        {
          sub_489C10(this[37] - 1, aFtim14redoutli);
        }
        else
        {
          sub_489C10(this[37] - 1, aFtim14blkoutli);
        }
        v6 = v19;
        ++v18;
      }
      nullsub_3(v24);
      v19 = ++v6;
    }
    while ( v6 < v20 );
    if ( strlen(v28) )
      sub_489BA0(v28, 0);
    if ( v18 )
      return sub_48A3B0(1);
  }
  sub_48A3B0(0);
  if ( sub_461FC0(dword_7CD25C) )
  {
    if ( sub_423A00(byte_5EC4C0, aSearching, byte_5EC4CC) )
    {
      v15 = 0;
      do
      {
        v16 = aSearching[v15];
        byte_5EC4CC[v15++] = v16;
      }
      while ( v16 );
    }
  }
  else if ( sub_423A00(byte_5EC4C0, aNoGamesAvailab, byte_5EC4CC) )
  {
    v12 = 0;
    do
    {
      v13 = aNoGamesAvailab[v12];
      byte_5EC4CC[v12++] = v13;
    }
    while ( v13 );
  }
  return sub_489600(byte_5EC4CC, byte_5EA438, 0, 0, 0);
}
