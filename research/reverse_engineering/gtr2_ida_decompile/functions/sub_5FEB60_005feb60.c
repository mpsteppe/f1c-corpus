int __thiscall sub_5FEB60(_DWORD *this, int a2)
{
  _DWORD *v3; // ecx
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  _DWORD *v6; // ecx
  int v7; // edi
  int v8; // eax
  char *v9; // edx
  char v10; // cl
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // edi
  _DWORD *v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // [esp-18h] [ebp-70h]
  int v22; // [esp-18h] [ebp-70h]
  int v23; // [esp-14h] [ebp-6Ch]
  int v24; // [esp-14h] [ebp-6Ch]
  int v25; // [esp-Ch] [ebp-64h]
  int v26; // [esp-8h] [ebp-60h]
  char v27; // [esp+0h] [ebp-58h]
  char Buffer[64]; // [esp+Ch] [ebp-4Ch] BYREF
  int v29; // [esp+54h] [ebp-4h]

  if ( (*this & 0x40000) != 0 )
    return 0;
  v3 = (_DWORD *)this[67];
  if ( (_BYTE)a2 )
  {
    v8 = sub_5E2E00(v3, 0) + 140;
    v9 = &Buffer[-v8];
    do
    {
      v10 = *(_BYTE *)v8;
      v9[v8] = *(_BYTE *)v8;
      ++v8;
    }
    while ( v10 );
    v7 = *(_DWORD *)(sub_5E2E00((_DWORD *)this[67], 0) + 24);
  }
  else if ( sub_5E2E00(v3, 0) )
  {
    v7 = a2;
  }
  else
  {
    sprintf(Buffer, "PROJ%.3dTEX", this[10]);
    v4 = operator new(0xDCu);
    v29 = 0;
    if ( v4 )
    {
      v5 = v4 + 1;
      *v4 = 1;
      sub_630A11(v4 + 1, 216, 1, sub_5E2AC0, j_j_nullsub_7);
    }
    else
    {
      v5 = 0;
    }
    *(_DWORD *)(this[67] + 220) = v5;
    v6 = (_DWORD *)this[67];
    v29 = -1;
    sub_5E3A10(v6, Buffer, 32770);
    v7 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 284))(dword_FB27A4);
  }
  v23 = this[61];
  v21 = this[60];
  v11 = (char *)sub_5E2E00((_DWORD *)this[67], 0);
  if ( !sub_5E2E70(v11, Buffer, v21, v23, v7, 1, 262216, 32770)
    || ((*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 340))(dword_FB27A4, 0),
        v24 = this[61],
        v22 = this[60],
        v12 = (char *)sub_5E2E00((_DWORD *)this[67], 0),
        !sub_5E2E70(v12, Buffer, v22, v24, v7, 1, 262216, 32770)) )
  {
    v26 = this[61];
    v25 = this[60];
    v16 = (_DWORD *)sub_5E2E00((_DWORD *)this[67], 0);
    sub_5E6F50(v16, 0, 0, v25, v26, 0);
    if ( !(_BYTE)a2 )
    {
      v17 = sub_5E2E00((_DWORD *)this[67], 0);
      *(_DWORD *)(v17 + 136) |= 0x80000u;
      v18 = sub_5E2E00((_DWORD *)this[67], 0);
      sub_5FDFB0(&dword_FB2D78, v18, 0);
      v19 = sub_5E2E00((_DWORD *)this[67], 0);
      ++*(_DWORD *)(v19 + 108);
      v20 = sub_5E2E00((_DWORD *)this[67], 0);
      sub_5E55E0((_DWORD *)this[68], v20);
    }
    *this |= 0x40000u;
    return 0;
  }
  v13 = (char *)sub_5E2E00((_DWORD *)this[67], 0);
  if ( v13 )
  {
    v14 = v13 - 4;
    `eh vector destructor iterator'(v13, 0xD8u, *((_DWORD *)v13 - 1), j_j_nullsub_7);
    j__free(v14);
  }
  *(_DWORD *)(this[67] + 220) = 0;
  sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error allocating shadow caster target surface", v27);
  return -1;
}
