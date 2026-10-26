int __thiscall sub_5E47E0(void *this, _DWORD *a2, const char *ArgList, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v10; // eax
  _DWORD *v12; // eax
  char *v13; // esi
  char *v14; // ecx
  bool v15; // zf
  _DWORD *v16; // eax
  _DWORD *v17; // esi

  if ( a2 )
  {
    v10 = sub_5E9100(ArgList, 1);
    if ( v10 )
    {
      ++*(_DWORD *)(v10 + 108);
      *a2 = v10;
      return 0;
    }
    v12 = operator new(0xDCu);
    if ( v12 )
    {
      v13 = (char *)(v12 + 1);
      *v12 = 1;
      sub_630A11(v12 + 1, 216, 1, sub_5E2AC0, j_j_nullsub_7);
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    *a2 = v14;
    v15 = sub_5E2E70(v14, ArgList, a4, a5, a6, a7, a8, a9) == 0;
    v16 = (_DWORD *)*a2;
    if ( v15 )
    {
      ++v16[27];
      sub_5FDFB0(*a2, 0);
      return 0;
    }
    if ( v16 )
    {
      v17 = v16 - 1;
      `eh vector destructor iterator'(v16, 0xD8u, *(v16 - 1), j_j_nullsub_7);
      j__free(v17);
    }
    *a2 = 0;
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error initializing texture %s", (char)ArgList);
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid texture pointer for %s", (char)ArgList);
  }
  return -1;
}
