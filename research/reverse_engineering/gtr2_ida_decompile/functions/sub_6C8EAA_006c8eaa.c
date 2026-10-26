int __thiscall sub_6C8EAA(int this)
{
  int v1; // edi
  unsigned int v2; // eax
  unsigned int v3; // edi
  _DWORD *v5; // ebx
  _DWORD *v6; // edx
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  unsigned int v9; // eax
  _DWORD *v10; // edi
  _DWORD *v11; // [esp+Ch] [ebp-24h]
  _DWORD *v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-18h] BYREF
  int *v14; // [esp+20h] [ebp-10h]
  unsigned int v15; // [esp+24h] [ebp-Ch]
  int v16; // [esp+28h] [ebp-8h]
  int v17; // [esp+2Ch] [ebp-4h]

  v1 = **(_DWORD **)(this + 256);
  v2 = v1 & 0xFFF00000;
  v3 = v1 & 0xFFFFF;
  v16 = this;
  if ( v2 != 1882193920 )
    return 1;
  v5 = *(_DWORD **)(this + 256);
  v17 = *(_DWORD *)(this + 252);
  sub_6C5283((_DWORD *)this, v3 & 0xFFFFF | 0x20500000, v5, &v13, 2);
  if ( !v14 )
    return 1;
  v15 = 0;
  if ( v3 )
  {
    v6 = (_DWORD *)v14[4];
    v7 = (_DWORD *)(v5[2] + 8 * v3);
    while ( *v7 == *v6 )
    {
      ++v15;
      ++v7;
      ++v6;
      if ( v15 >= v3 )
        goto LABEL_8;
    }
    return 1;
  }
LABEL_8:
  v8 = (_DWORD *)v5[2];
  v9 = v3;
  v10 = (_DWORD *)v14[2];
  v9 *= 4;
  v11 = (_DWORD *)((char *)v8 + v9);
  v12 = (_DWORD *)((char *)v10 + v9);
  if ( sub_6C2FB9(v16, (int)v8, (char *)v8 + v9, v10, (char *)v10 + v9, v14, (int)v5, v17)
    && sub_6C2FB9(v16, (int)v11, v8, v10, v12, v14, (int)v5, v17)
    && sub_6C2FB9(v16, (int)v8, v11, v12, v10, v14, (int)v5, v17)
    && sub_6C2FB9(v16, (int)v11, v8, v12, v10, v14, (int)v5, v17)
    && sub_6C2FB9(v16, (int)v10, v12, v8, v11, v14, (int)v5, v17)
    && sub_6C2FB9(v16, (int)v12, v10, v8, v11, v14, (int)v5, v17)
    && sub_6C2FB9(v16, (int)v10, v12, v11, v8, v14, (int)v5, v17) )
  {
    return sub_6C2FB9(v16, (int)v12, v10, v11, v8, v14, (int)v5, v17);
  }
  else
  {
    return 0;
  }
}
