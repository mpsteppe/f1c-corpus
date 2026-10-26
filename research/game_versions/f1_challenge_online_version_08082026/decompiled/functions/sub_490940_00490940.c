int __fastcall sub_490940(__int16 a1, __int16 a2, __int16 a3, __int16 a4)
{
  _DWORD *v4; // ebx
  int *v5; // eax
  _DWORD *v6; // edi
  int v7; // esi
  _DWORD *v8; // ebp
  _DWORD *v9; // eax
  _DWORD *v10; // ebx
  _DWORD *v11; // esi
  int v12; // ebp
  _DWORD *v13; // eax
  int i; // esi
  _DWORD *v15; // eax
  int v16; // ebx
  bool v17; // zf
  _DWORD *v18; // esi
  _DWORD *v19; // eax
  int v21; // [esp-8h] [ebp-24h]
  _DWORD *v22; // [esp+Ch] [ebp-10h]
  _DWORD *v23; // [esp+10h] [ebp-Ch]

  v4 = (_DWORD *)sub_490930();
  v5 = (int *)v4[4];
  v6 = v4 + 4;
  v7 = 0;
  v22 = v4;
  v4[6] = v5;
  if ( v5 )
  {
    v7 = *v5;
    v21 = *v5;
    *((_BYTE *)v5 + 8) = 0;
    if ( !(unsigned __int8)sub_491D30(v21, 1) )
      v7 = 0;
  }
  if ( !v7 )
  {
    v8 = (_DWORD *)sub_587C03(4);
    v23 = v8;
    if ( v8 )
    {
      v9 = (_DWORD *)sub_587C03(68);
      if ( v9 )
      {
        v10 = v9 + 1;
        *v9 = 4;
        v11 = v9 + 1;
        v12 = 4;
        do
        {
          sub_4912F0(v11);
          v11 += 4;
          --v12;
        }
        while ( v12 );
        v8 = v23;
        v13 = v10;
        v4 = v22;
        *v23 = v13;
      }
      else
      {
        *v8 = 0;
      }
    }
    else
    {
      v8 = 0;
    }
    sub_434030(v4, (int)v8, 1);
    for ( i = 0; i < 64; i += 16 )
      sub_4BB490(i + *v8, 0);
    v15 = (_DWORD *)*v6;
    v16 = 0;
    v17 = *v6 == 0;
    v6[2] = *v6;
    if ( !v17 )
    {
      *((_BYTE *)v15 + 8) = 0;
      v16 = *v15;
      if ( *v15 && (v18 = (_DWORD *)*v6, v19 = 0, *v6) )
      {
        while ( *v18 != v16 )
        {
          v19 = v18;
          v18 = (_DWORD *)v18[1];
          if ( !v18 )
            goto LABEL_19;
        }
        if ( v18 == (_DWORD *)v6[2] )
          v6[2] = v18[1];
        if ( v19 )
          v19[1] = v18[1];
        else
          *v6 = v18[1];
        if ( (_DWORD *)v6[1] == v18 )
          v6[1] = v19;
        --v6[3];
        sub_491E40(v18);
        sub_587BCF(v18);
      }
      else
      {
LABEL_19:
        v16 = 0;
      }
    }
    v7 = v16;
  }
  sub_4916E0(a1, a2, a3, a4);
  return v7;
}
