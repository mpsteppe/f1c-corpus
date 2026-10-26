int __thiscall sub_6C8AE5(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // ecx
  int v5; // edx
  char *v6; // eax
  int v7; // ecx
  char *v8; // edi
  int v9; // edx
  int v10; // ebx
  char *v11; // ecx
  int v12; // edi
  int v13; // eax
  int v14; // edi
  unsigned int v15; // [esp+8h] [ebp-14h]
  char *v16; // [esp+Ch] [ebp-10h]
  unsigned int v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-8h]
  int v19; // [esp+18h] [ebp-4h]

  v19 = 0;
  v3 = a2;
  if ( a2 )
  {
    v19 = 1;
  }
  else
  {
    v3 = (_DWORD *)this[64];
    a2 = v3;
  }
  if ( (*v3 & 0xFFF00000) != 0x20400000 )
    return 1;
  v5 = *v3 & 0xFFFFF;
  v6 = (char *)v3[2];
  v7 = this[4];
  v8 = &v6[4 * v5];
  v15 = v5;
  v9 = this[5];
  if ( (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)v8) + 4)) + 5) & 1) != 0 )
  {
    v16 = v6;
    v6 = v8;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)v6) + 4)) + 5) & 1) == 0 )
      return 1;
    v16 = v8;
  }
  v10 = this[64];
  v11 = v16;
  if ( (_DWORD *)v10 != a2 )
    v11 = *(char **)(v10 + 8);
  this[87] = 0;
  v17 = 0;
  if ( v15 )
  {
    v18 = v6 - v11;
    while ( *(double *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)&v11[v18]) + 32) == 1.0
         && (v19 || (*(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)v11) + 60) & 0x1F0000) == 0x80000) )
    {
      v12 = *(_DWORD *)(v9 + 4 * *(_DWORD *)v11);
      if ( (*(_BYTE *)(v12 + 61) & 2) == 0 && ((4 * (v19 == 0) + 20) & *(_DWORD *)v12) == 0 )
        this[87] = 1;
      ++v17;
      v11 += 4;
      if ( v17 >= v15 )
        goto LABEL_21;
    }
    return 1;
  }
LABEL_21:
  if ( v19 )
    v13 = sub_6C73E9((int)this, 0x10000, 0, *(char **)(v10 + 8), 0x10000, (int)a2, 0);
  else
    v13 = sub_6C73E9((int)this, 0x10000, 0x80000, v16, 589824, 0, 0);
  v14 = v13;
  if ( this[87] == 2 )
    sub_686816(
      (int)this,
      *(_DWORD *)(this[64] + 60),
      (const char *)0x125E,
      "complement opportunity missed because input result WAS clamped from 0 to 1");
  return v14;
}
