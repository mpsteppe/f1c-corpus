int __thiscall sub_6A4923(_DWORD *this)
{
  _DWORD *v2; // eax
  char *v3; // ebx
  unsigned int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  bool v13; // zf
  int v14; // edx
  _DWORD *v15; // ecx
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  bool v22; // cf
  unsigned int i; // eax
  void *v24; // ecx
  _DWORD v26[4]; // [esp+Ch] [ebp-108h] BYREF
  _DWORD v27[36]; // [esp+1Ch] [ebp-F8h] BYREF
  _DWORD v28[16]; // [esp+ACh] [ebp-68h] BYREF
  _DWORD v29[4]; // [esp+ECh] [ebp-28h] BYREF
  BOOL v30; // [esp+FCh] [ebp-18h]
  int v31; // [esp+100h] [ebp-14h]
  unsigned int v32; // [esp+104h] [ebp-10h] BYREF
  int v33; // [esp+108h] [ebp-Ch]
  unsigned int v34; // [esp+10Ch] [ebp-8h]
  int v35; // [esp+110h] [ebp-4h]

  v2 = (_DWORD *)this[64];
  v3 = 0;
  v32 = 0;
  v29[0] = 0;
  v29[1] = 1;
  v29[2] = 2;
  v29[3] = 3;
  v4 = *v2 & 0xFFFFF;
  v34 = 0;
  if ( sub_6BB35B(v2, &unk_742918, v28, &v32, v26, v29, v4, 0) )
  {
    v5 = sub_6BB35B(this[64], &unk_742978, v28, &v32, v26, v29, v4, 0);
    v34 = 1;
    if ( v5 )
    {
LABEL_30:
      v35 = 0;
      goto LABEL_31;
    }
  }
  v30 = 0;
  if ( v34 )
  {
    v6 = this[5];
    v7 = this[4];
    v8 = *(_DWORD *)(v7 + 4 * *(_DWORD *)(*(_DWORD *)(v6 + 4 * v26[0]) + 4));
    v9 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(*(_DWORD *)(v6 + 4 * v27[0]) + 4)) + 4);
    v30 = (v9 & 0x200) != 0;
    if ( (*(_DWORD *)(v8 + 4) & 0x300) != 0 && (v9 & 0x300) != 0 )
      return 1;
  }
  v10 = (_DWORD *)sub_681186(116);
  if ( v10 )
    v3 = (char *)sub_680CEC(v10);
  else
    v3 = 0;
  if ( !v3 )
    return -2147024882;
  if ( v34 )
    v11 = v4 | 0x70400000;
  else
    v11 = v4 | 0x70300000;
  v35 = sub_6811D1(v3, v11, 3 * v4, v4, 0);
  if ( v35 >= 0 )
  {
    v35 = sub_680D22(v3, this[64]);
    if ( v35 >= 0 )
    {
      v34 = 0;
      if ( v4 )
      {
        v31 = 8 * v4;
        v33 = 4 * v4;
        do
        {
          v12 = 4 * v34;
          v13 = !v30;
          *(_DWORD *)(v12 + *((_DWORD *)v3 + 4)) = *(_DWORD *)(4 * v34 + *(_DWORD *)(this[64] + 16));
          v14 = *((_DWORD *)v3 + 2);
          v15 = &v27[v12 / 4];
          v35 = (int)&v27[v12 / 4];
          if ( v13 )
          {
            *(_DWORD *)(v12 + v14) = *(v15 - 4);
            v16 = *(_DWORD *)v35;
          }
          else
          {
            *(_DWORD *)(v12 + v14) = *v15;
            v16 = *(_DWORD *)(v35 - 16);
          }
          v17 = v33;
          v18 = *((_DWORD *)v3 + 2);
          ++v34;
          v33 += 4;
          *(_DWORD *)(v17 + v18) = v16;
          v19 = v31;
          v20 = *((_DWORD *)v3 + 2);
          v21 = *(_DWORD *)(v35 + 16);
          v31 += 4;
          v22 = v34 < v4;
          *(_DWORD *)(v19 + v20) = v21;
        }
        while ( v22 );
      }
      if ( (*(int (__thiscall **)(_DWORD *, char *, _DWORD))(*this + 32))(this, v3, 0) )
      {
        v35 = 1;
        goto LABEL_31;
      }
      for ( i = 0; i < v32; ++i )
        *(_DWORD *)v28[i] = 0;
      v24 = (void *)this[64];
      if ( v24 )
        sub_66238F(v24, 1);
      *(_DWORD *)(this[6] + 4 * this[63]) = v3;
      v3 = 0;
      goto LABEL_30;
    }
  }
LABEL_31:
  if ( v3 )
    sub_66238F(v3, 1);
  return v35;
}
