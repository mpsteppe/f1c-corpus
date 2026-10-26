int __thiscall sub_49F130(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // eax
  char *v7; // eax

  v6 = this[61];
  if ( v6 )
  {
    v7 = *(char **)(v6 + 64);
    if ( !v7 )
      v7 = &byte_629120;
    sub_4AE350(v7);
  }
  return sub_49ED00(this, a2, a3, a4, a5);
}
