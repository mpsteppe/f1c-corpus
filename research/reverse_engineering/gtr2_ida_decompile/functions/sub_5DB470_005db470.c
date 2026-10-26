int __thiscall sub_5DB470(int *this, int ArgList, int a3, int a4, int a5, int a6)
{
  void *v7; // edi
  void *v8; // eax
  int v9; // eax
  int result; // eax

  if ( *(_DWORD *)(ArgList + 464) )
  {
    sub_5E6500();
    v7 = *(void **)(ArgList + 464);
    if ( v7 )
    {
      sub_5E64B0(*(void **)(ArgList + 464));
      j__free(v7);
    }
    *(_DWORD *)(ArgList + 464) = 0;
  }
  v8 = operator new(0x54u);
  if ( v8 )
    v9 = sub_5E6460(v8);
  else
    v9 = 0;
  *(_DWORD *)(ArgList + 464) = v9;
  result = sub_5E5CC0(this[155], 0, ArgList, a4, a5, a6);
  if ( result != -1 )
  {
    if ( !a3 )
    {
      sub_5EB310(ArgList);
      sub_5FDFB0(*(_DWORD *)(ArgList + 464), 1);
    }
    return 0;
  }
  return result;
}
