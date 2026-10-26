int __thiscall sub_6703EF(int this, _DWORD *a2, unsigned int a3, _DWORD *a4, int a5)
{
  int result; // eax
  int v7; // eax
  size_t v8; // esi
  void *v9; // edx
  int v10; // esi
  int v11; // edi
  unsigned int v12; // [esp+8h] [ebp-14h]
  unsigned int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  void *Block; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  if ( a3 && (a5 != a3 || (*(_BYTE *)(*(_DWORD *)(this + 8) + 112) & 4) == 0) )
  {
    result = sub_67051D(a3, 0);
    if ( result < 0 )
      return result;
    if ( *(_DWORD *)(this + 80) || *(_DWORD *)(this + 84) )
      return 0;
    a3 = 0;
  }
  v7 = *(_DWORD *)(this + 8);
  v8 = 4 * *(_DWORD *)(*(_DWORD *)(this + 4) + 24);
  v12 = *(_DWORD *)(v7 + 8);
  v13 = *(_DWORD *)(v7 + 12);
  v9 = operator new(v8);
  Block = v9;
  if ( v9 )
  {
    qmemcpy(v9, *(const void **)(this + 24), v8);
    if ( *(_DWORD *)(*(_DWORD *)(this + 8) + 92) )
    {
      v10 = *(_DWORD *)(this + 88);
      v11 = *(_DWORD *)(this + 92);
      v14 = *(_DWORD *)(this + 96);
      *(_DWORD *)(this + 88) = 1;
      *(_DWORD *)(this + 92) = 0;
      *(_DWORD *)(this + 96) = 0;
      v16 = sub_668167(this, (unsigned int)a2, a3, (int)a4, a5, (int)v9);
      *(_DWORD *)(this + 76) = 0;
      *(_DWORD *)(this + 80) = 0;
      *(_DWORD *)(this + 84) = 0;
      *(_DWORD *)(this + 88) = v10;
      *(_DWORD *)(this + 92) = v11;
      *(_DWORD *)(this + 96) = v14;
      if ( v16 >= 0 )
        goto LABEL_16;
      sub_664155(this, v12, v13, Block);
    }
    v16 = sub_668FA5(this, a2, a3, a4, a5, (char *)Block);
    if ( v16 >= 0 )
      v16 = 0;
    goto LABEL_16;
  }
  v16 = -2147024882;
LABEL_16:
  j__free(Block);
  return v16;
}
