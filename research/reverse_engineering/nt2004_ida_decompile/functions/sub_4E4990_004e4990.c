int __thiscall sub_4E4990(int *this)
{
  int v2; // eax
  const char *v3; // ebx
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  const char **v8; // eax
  const char *v9; // eax

  if ( !sub_57AE50(aRaceorder) )
    return -1;
  if ( this[7742] < 0 )
    return -1;
  v2 = sub_57A700(this[7742]);
  if ( !v2 )
    return -1;
  v3 = (const char *)sub_57A6C0(v2);
  v4 = this[3];
  v5 = 0;
  if ( v4 <= 0 )
    return -1;
  while ( 1 )
  {
    v6 = v5;
    if ( v5 < 0 || v5 >= v4 )
      goto LABEL_11;
    v7 = *this;
    if ( v5 > 0 )
    {
      while ( v7 )
      {
        v7 = *(_DWORD *)(v7 + 4);
        if ( --v6 <= 0 )
          goto LABEL_10;
      }
LABEL_11:
      v8 = 0;
      goto LABEL_13;
    }
LABEL_10:
    if ( !v7 )
      goto LABEL_11;
    v8 = *(const char ***)v7;
LABEL_13:
    v9 = *v8;
    if ( !v9 )
      v9 = &byte_629120;
    if ( !_strcmpi(v9, v3) )
      return v5;
    v4 = this[3];
    if ( ++v5 >= v4 )
      return -1;
  }
}
