int __thiscall sub_66078B(_DWORD *this, char *a2, int a3, int a4)
{
  unsigned int v4; // kr00_4
  char *v5; // ebx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  unsigned int v9; // [esp+0h] [ebp-8h]

  v9 = sub_65EBAB(a2);
  v4 = strlen(a2);
  v5 = (char *)operator new(v4 + 1);
  if ( !v5 )
    return -2147024882;
  qmemcpy(v5, a2, v4 + 1);
  v6 = operator new(0x24u);
  v7 = v6 ? sub_6603E6(v6, (int)v5, a3, a4, this[v9]) : 0;
  if ( !v7 )
    return -2147024882;
  this[v9] = v7;
  return 0;
}
