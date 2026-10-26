void __thiscall sub_4F84C0(_DWORD *this)
{
  _DWORD *v1; // ebp
  int v2; // ecx
  _DWORD *v3; // eax
  int v4; // ecx
  _DWORD *v5; // eax
  int v6; // ecx
  int i; // edi
  char *v8; // esi
  int v9; // ebp
  float *v10; // eax
  int *v11; // edx
  int v12; // eax
  int *v13; // edx
  int *v14; // edx
  bool v15; // bl
  int j; // esi
  int *v17; // edx
  _DWORD *v18; // ecx
  int v19; // eax
  bool v20; // al
  bool v21; // al
  int v22; // esi
  int v23; // eax
  float v24; // [esp-10h] [ebp-330h]
  float v25; // [esp-10h] [ebp-330h]
  float v26; // [esp-10h] [ebp-330h]
  bool v27; // [esp+Ah] [ebp-316h]
  bool v28; // [esp+Bh] [ebp-315h]
  int v30; // [esp+10h] [ebp-310h]
  float v31; // [esp+14h] [ebp-30Ch]
  _DWORD v32[96]; // [esp+18h] [ebp-308h] BYREF
  int v33; // [esp+198h] [ebp-188h]
  _DWORD v34[96]; // [esp+19Ch] [ebp-184h] BYREF
  int v35; // [esp+31Ch] [ebp-4h]

  v1 = this;
  if ( !*(_BYTE *)this )
  {
    v2 = dword_6310D8[6326 * sub_4FA870(0)];
    v28 = dword_7D74B8 - v2 > 10;
    v30 = v2;
    v27 = dword_7D74B8 - v2 <= 1;
    v3 = v32;
    v4 = 48;
    do
    {
      *v3 = -2;
      v3[1] = -1082130432;
      v3 += 2;
      --v4;
    }
    while ( v4 );
    sub_4F7CC0(v32);
    v5 = v34;
    v6 = 48;
    do
    {
      *v5 = -2;
      v5[1] = -1082130432;
      v5 += 2;
      --v6;
    }
    while ( v6 );
    sub_4F7CC0(v34);
    sub_4F7E70(v32, v1 + 98);
    sub_4F7CC0(v1 + 98);
    sub_4F7CC0(v1 + 1);
    for ( i = 0; i < v33; ++i )
    {
      v8 = (char *)&unk_62BF68 + 25304 * sub_4F7CF0(v32, i);
      v9 = sub_4FA870(0);
      if ( sub_4DCA60((_DWORD *)v8 + 5209) )
      {
        sub_4F7D10(v32, i);
        v10 = (float *)sub_4F7D10(v32, i);
        sub_4F7DC0(v34, *v11, v10[1], 1);
        v1 = this;
      }
      else
      {
        v12 = *((_DWORD *)v8 + 5212);
        if ( v12 >= v30 )
          goto LABEL_16;
        if ( v12 == v30 - 1 )
        {
          v31 = sub_51C900(v8 + 84);
          if ( sub_51C900((char *)&unk_62BFBC + 25304 * v9) < v31 )
            goto LABEL_16;
        }
        if ( !v28 )
        {
          if ( !v27 )
            sub_45D100(&byte_764D68, (int)aWillNotDoubleF, 2, 16909060, 0);
LABEL_16:
          sub_4F7D10(v32, i);
          v1 = this;
          v25 = *((float *)sub_4F7D10(v32, i) + 1);
          sub_4F7DC0(this + 98, *v14, v25, 1);
          continue;
        }
        sub_4F7D10(v32, i);
        v1 = this;
        v24 = *((float *)sub_4F7D10(v32, i) + 1);
        sub_4F7DC0(this + 1, *v13, v24, 1);
      }
    }
    v15 = v1[194] >= v1[97];
    for ( j = 0; j < v35; ++j )
    {
      sub_4F7D10(v34, j);
      v26 = *((float *)sub_4F7D10(v34, j) + 1);
      v18 = v1 + 98;
      if ( !v15 )
        v18 = v1 + 1;
      sub_4F7DC0(v18, *v17, v26, 1);
      v19 = sub_4F7CF0(v34, j);
      sub_4DC9C0((int *)&unk_6310CC + 6326 * v19, 3);
    }
    v20 = sub_42DBA0();
    if ( sub_4F8410(v1, v20 ? dword_75AACC : 0) )
    {
      v21 = sub_42DBA0();
      v22 = dword_75AACC;
      v23 = sub_4F82E0(v1, v21 ? dword_75AACC : 0);
      sub_4DCEB0((int *)(v22 + 20836), v23);
    }
  }
  *(_BYTE *)v1 = 1;
}
