int __thiscall sub_65B3D1(int this)
{
  int *v2; // esi
  int result; // eax
  int v4; // [esp+Ch] [ebp-4h]

  v2 = (int *)(this + 632);
  result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
  if ( result >= 0 )
  {
    v4 = *v2;
    if ( *v2 == 9 )
    {
      if ( !strcmp(*(const char **)(this + 640), "pack_matrix") )
        return sub_65A626(this);
      if ( !strcmp(*(const char **)(this + 640), "warning") )
        return sub_65A765(this);
      if ( !strcmp(*(const char **)(this + 640), (const char *)&off_737974) )
        return sub_65AB4D(this);
    }
    if ( v4 != 12 && v4 != 13 )
      sub_65D86A(*(_DWORD *)(this + 620));
    result = 0;
  }
  *(_DWORD *)(this + 64) = 1;
  return result;
}
