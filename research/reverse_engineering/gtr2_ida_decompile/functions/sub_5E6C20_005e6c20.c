int __thiscall sub_5E6C20(_DWORD *this, unsigned int ArgList, int a3, int a4, int a5, int a6)
{
  void *v7; // ecx
  int *v8; // edi
  int v9; // edi
  _DWORD *v10; // eax
  unsigned int *v11; // eax
  int result; // eax
  int v13; // [esp+0h] [ebp-18h]
  __int16 v14; // [esp+4h] [ebp-14h]

  v7 = *(void **)(ArgList + 464);
  if ( v7 )
  {
    sub_5E6500(v7);
    v8 = *(int **)(ArgList + 464);
    if ( v8 )
    {
      sub_5DD490(v8 + 17);
      nullsub_7(v8);
      j__free(v8);
    }
    *(_DWORD *)(ArgList + 464) = 0;
  }
  v9 = a6;
  if ( this[208] )
    v9 = a6 | 0x10000;
  v10 = operator new(0x54u);
  if ( v10 )
    v11 = sub_5E6460(v10);
  else
    v11 = 0;
  *(_DWORD *)(ArgList + 464) = v11;
  result = sub_5E5CC0(v11, v9, ArgList, (unsigned int)this, 0, ArgList, a4, a5, v9, v13, v14);
  if ( result != -1 )
  {
    if ( !*(_DWORD *)(a3 + 624) )
      sub_5FDFB0(*(_DWORD *)(ArgList + 464), 1);
    return 0;
  }
  return result;
}
