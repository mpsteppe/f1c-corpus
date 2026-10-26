int __thiscall sub_43A126(void *this, int *a2, int ArgList, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v11; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  _DWORD *v15; // ecx
  bool v16; // zf
  _DWORD *v17; // eax
  _DWORD *v18; // esi

  if ( a2 )
  {
    v11 = sub_5E9100(ArgList, 1);
    if ( v11 )
    {
      ++*(_DWORD *)(v11 + 108);
      *a2 = v11;
      return 0;
    }
    v13 = operator new(0xDCu);
    if ( v13 )
    {
      v14 = v13 + 1;
      *v13 = 1;
      sub_630A11(v13 + 1, 216, 1, sub_5E2AC0, j_j_nullsub_7);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    *a2 = (int)v15;
    v16 = sub_5E30C0(ArgList, a4, a5, a6, a7, a8, a9) == 0;
    v17 = (_DWORD *)*a2;
    if ( v16 )
    {
      ++v17[27];
      sub_5FDFB0(*a2, 0);
      return 0;
    }
    if ( v17 )
    {
      v18 = v17 - 1;
      `eh vector destructor iterator'(v17, 0xD8u, *(v17 - 1), j_j_nullsub_7);
      j__free(v18);
    }
    *a2 = 0;
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error initializing texture %s", ArgList);
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid texture pointer for %s", ArgList);
  }
  return -32;
}
