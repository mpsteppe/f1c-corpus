unsigned int __thiscall sub_65E50F(int this, unsigned int a2, _DWORD *a3)
{
  char *v5; // esi
  int v6; // eax
  char *v7; // edi
  char *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  char v11[32]; // [esp+4h] [ebp-2Ch] BYREF
  _DWORD v12[3]; // [esp+24h] [ebp-Ch] BYREF

  if ( (*(_BYTE *)(this + 40) & 2) == 0 )
    return 0;
  v5 = (char *)a2;
  if ( a2 + 1 >= *(_DWORD *)(this + 4) )
    return 0;
  if ( !sub_633848() )
    return 0;
  if ( !sub_633848() )
    return 0;
  if ( (unsigned int)(v5 + 2) >= *(_DWORD *)(this + 4) )
    return 0;
  if ( v5[2] != 46 )
    return 0;
  v6 = sub_65E2D3(this, v5 + 3, &a2);
  if ( !v6 )
    return 0;
  if ( a2 > 0xFF )
    return 0;
  v7 = &v5[v6 + 3];
  if ( (unsigned int)v7 >= *(_DWORD *)(this + 4) || *v7 != 46 )
    return 0;
  v8 = v7 + 1;
  v9 = sub_65E2D3(this, v8, &a2);
  if ( !v9 )
  {
    v9 = sub_65DA50((_DWORD *)this, v8, &a2);
    if ( !v9 )
      return 0;
    a2 = 0;
  }
  if ( a2 <= 0xFF )
  {
    v10 = &v8[v9] - v5;
    if ( v10 < 0x20 )
    {
      qmemcpy(v11, v5, v10);
      v11[v10] = 0;
      if ( sub_6460B4(v11, 1, v12) >= 0 )
      {
        *a3 = v12[1];
        return v10;
      }
    }
  }
  return 0;
}
