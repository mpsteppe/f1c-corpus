bool __thiscall sub_4C5D30(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // edx
  bool v4; // sf
  bool v5; // of
  int v6; // eax
  int v7; // edx
  char *v9; // esi
  char *v10; // ecx
  int v11; // eax

  v2 = this[3];
  v3 = a2[3];
  v5 = __OFSUB__(v2, v3);
  v4 = v2 - v3 < 0;
  if ( v2 == v3 )
  {
    v6 = dword_8AC490 + 396 * *this;
    v7 = dword_8AC490 + 396 * *a2;
    if ( v6 && v7 )
      return (int)sub_588410(v6 + 260, v7 + 260) < 0;
    v9 = (char *)a2[1];
    if ( !v9 )
      v9 = byte_5EA438;
    v10 = (char *)this[1];
    if ( !v10 )
      v10 = byte_5EA438;
    v11 = sub_588410(v10, v9);
    v5 = 0;
    v4 = v11 < 0;
  }
  return v4 ^ v5;
}
