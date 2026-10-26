int __thiscall sub_469900(_DWORD *this)
{
  const char *v1; // edi
  const char *v2; // eax
  char *v3; // eax
  int v4; // edi
  char *v5; // eax
  char *v6; // eax
  double v7; // st7
  int v8; // kr00_4
  int v9; // edx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int result; // eax
  int v14; // edi
  char *v15; // eax
  char *v16; // eax
  double v17; // st7
  int v18; // kr04_4
  int v19; // edx
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  char v23; // [esp+18h] [ebp-188h] BYREF
  __int16 v24; // [esp+19h] [ebp-187h]
  char v25; // [esp+1Bh] [ebp-185h]
  int v26; // [esp+1Ch] [ebp-184h]
  _WORD v27[16]; // [esp+20h] [ebp-180h] BYREF
  _WORD v28[16]; // [esp+40h] [ebp-160h] BYREF
  _WORD v29[31]; // [esp+60h] [ebp-140h] BYREF
  __int16 v30; // [esp+9Eh] [ebp-102h]
  _BYTE v31[256]; // [esp+A0h] [ebp-100h] BYREF

  v24 = 0;
  v23 = byte_5EA438[0];
  v25 = 0;
  v29[0] = word_5C694C;
  memset(&v29[1], 0, 0x3Cu);
  v30 = 0;
  v28[0] = word_5C694C;
  memset(&v28[1], 0, 30);
  v27[0] = word_5C694C;
  memset(&v27[1], 0, 30);
  v1 = (const char *)this[96];
  if ( !v1 )
    v1 = byte_5EA438;
  v2 = (const char *)dword_7CE668;
  if ( !dword_7CE668 )
    v2 = byte_5EA438;
  if ( strcmp(v2, v1) )
  {
    v3 = (char *)dword_7CE668;
    if ( !dword_7CE668 )
      v3 = byte_5EA438;
    sub_566650(v3);
  }
  dword_7D2DC8 = dword_7D2DC0;
  if ( dword_7D2DC0 )
  {
    v4 = *(_DWORD *)dword_7D2DC0;
    if ( *(_DWORD *)dword_7D2DC0 )
    {
      v5 = *(char **)v4;
      if ( !*(_DWORD *)v4 )
        v5 = byte_5EA438;
      if ( sub_4C58A0(v29, 64, aGrandprixname, v5) )
      {
        v6 = *(char **)v4;
        if ( !*(_DWORD *)v4 )
          v6 = byte_5EA438;
        sub_587DD0(v29, v6, 63);
        HIBYTE(v30) = 0;
      }
      sub_58815F(v27, "%d", *(_DWORD *)(v4 + 16));
      v7 = *(float *)(v4 + 20);
      v8 = sub_587BDC(v7);
      v9 = v8 / 60;
      if ( v8 / 60 > 0 )
      {
        v26 = 60 * v9;
        v7 = v7 - (double)(60 * v9);
      }
      sub_58815F(v28, "%i:%06.3f", v8 / 60, v7);
    }
  }
  sub_4894D0(&v23);
  v10 = (const char *)sub_487010(0);
  sub_58815F(v31, "%s%s%s", v10, &v23, (const char *)v29);
  sub_489600(v31, 0, 0, 0, 0);
  v11 = (const char *)sub_487010(1);
  sub_58815F(v31, "%s%s%s", v11, &v23, (const char *)v27);
  sub_489600(v31, 0, 0, 0, 0);
  v12 = (const char *)sub_487010(2);
  sub_58815F(v31, "%s%s%s", v12, &v23, (const char *)v28);
  sub_489600(v31, 0, 0, 0, 0);
  result = dword_7D2DC8;
  if ( dword_7D2DC8 && (dword_7D2DC8 = *(_DWORD *)(dword_7D2DC8 + 4), (result = dword_7D2DC8) != 0) )
    v14 = *(_DWORD *)dword_7D2DC8;
  else
    v14 = 0;
  while ( v14 )
  {
    LOBYTE(v29[0]) = 0;
    v15 = *(char **)v14;
    if ( !*(_DWORD *)v14 )
      v15 = byte_5EA438;
    if ( sub_4C58A0(v29, 64, aGrandprixname, v15) )
    {
      v16 = *(char **)v14;
      if ( !*(_DWORD *)v14 )
        v16 = byte_5EA438;
      sub_587DD0(v29, v16, 63);
      HIBYTE(v30) = 0;
    }
    sub_58815F(v27, "%d", *(_DWORD *)(v14 + 16));
    v17 = *(float *)(v14 + 20);
    v18 = sub_587BDC(v17);
    v19 = v18 / 60;
    if ( v18 / 60 > 0 )
    {
      v26 = 60 * v19;
      v17 = v17 - (double)(60 * v19);
    }
    sub_58815F(v28, "%i:%06.3f", v18 / 60, v17);
    sub_58815F(v31, byte_5EA438);
    sub_489600(v31, 0, 0, 0, 0);
    v20 = (const char *)sub_487010(0);
    sub_58815F(v31, "%s%s%s", v20, &v23, (const char *)v29);
    sub_489600(v31, 0, 0, 0, 0);
    v21 = (const char *)sub_487010(1);
    sub_58815F(v31, "%s%s%s", v21, &v23, (const char *)v27);
    sub_489600(v31, 0, 0, 0, 0);
    v22 = (const char *)sub_487010(2);
    sub_58815F(v31, "%s%s%s", v22, &v23, (const char *)v28);
    sub_489600(v31, 0, 0, 0, 0);
    result = dword_7D2DC8;
    if ( dword_7D2DC8 && (dword_7D2DC8 = *(_DWORD *)(dword_7D2DC8 + 4), (result = dword_7D2DC8) != 0) )
      v14 = *(_DWORD *)dword_7D2DC8;
    else
      v14 = 0;
  }
  return result;
}
