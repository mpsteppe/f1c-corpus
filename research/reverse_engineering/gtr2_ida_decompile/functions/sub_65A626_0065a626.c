int __thiscall sub_65A626(int this)
{
  int *v2; // esi
  int result; // eax
  int v4; // eax
  int *v5; // esi
  int *v6; // esi
  const char *v7; // [esp+8h] [ebp-4h]

  v2 = (int *)(this + 632);
  result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
  if ( result >= 0 )
  {
    v4 = *v2;
    if ( *v2 != 1 || strcmp((const char *)(this + 640), "(") )
      goto LABEL_20;
    v5 = (int *)(this + 632);
    result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
    if ( result >= 0 )
    {
      if ( *v5 == 9 )
      {
        v7 = *(const char **)(this + 640);
        result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
        if ( result < 0 )
          goto LABEL_24;
      }
      else
      {
        v7 = 0;
      }
      v4 = *v5;
      if ( *v5 != 1 || strcmp((const char *)(this + 640), (const char *)&word_6FBE80) )
        goto LABEL_20;
      v6 = (int *)(this + 632);
      result = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
      if ( result >= 0 )
      {
        v4 = *v6;
        if ( *v6 == 12 || v4 == 13 )
        {
          if ( !v7 )
          {
            *(_DWORD *)(this + 56) = 0;
LABEL_23:
            result = 0;
            goto LABEL_24;
          }
          if ( !strcmp(v7, "row_major") )
          {
            *(_DWORD *)(this + 56) = 1024;
            goto LABEL_23;
          }
          if ( !strcmp(v7, "column_major") )
          {
            *(_DWORD *)(this + 56) = 2048;
            goto LABEL_23;
          }
        }
LABEL_20:
        if ( v4 != 12 && v4 != 13 )
          sub_65D86A(*(_DWORD *)(this + 620));
        goto LABEL_23;
      }
    }
  }
LABEL_24:
  *(_DWORD *)(this + 64) = 1;
  return result;
}
