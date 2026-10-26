int __thiscall sub_5BD3F0(int this)
{
  int v2; // ebx
  u_short v3; // ax
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int result; // eax
  size_t v8; // eax
  size_t v9; // ecx
  char *v10; // eax

  v2 = 0;
  if ( *(int *)(this + 120) < 3 )
    return v2;
  while ( 2 )
  {
    v3 = ntohs(**(_WORD **)(this + 116));
    if ( v3 > 0x1000u )
    {
      v2 = 4;
LABEL_18:
      sub_5BCA10(this);
      return v2;
    }
    v4 = v3;
    if ( *(_DWORD *)(this + 120) < (int)v3 )
      return 0;
    v5 = *(_DWORD *)(this + 116);
    switch ( *(_BYTE *)(v5 + 2) )
    {
      case 1:
        v6 = sub_5BD4F0(v4 - 3);
        goto LABEL_10;
      case 2:
        v6 = sub_5BD600(v4 - 3);
        goto LABEL_10;
      case 3:
        if ( send(*(_DWORD *)(this + 1184), (const char *)v5, v4, 0) > 0 )
          goto LABEL_11;
        return 3;
      case 4:
        v6 = sub_5BD5C0(v4 - 3);
LABEL_10:
        v2 = v6;
        goto LABEL_11;
      default:
LABEL_11:
        v8 = *(_DWORD *)(this + 120) - v4;
        *(_DWORD *)(this + 120) = v8;
        v9 = v8;
        if ( v8 )
        {
          v10 = *(char **)(this + 116);
          if ( v10 )
            memcpy(v10, &v10[v4], v9);
        }
        if ( v2 )
          goto LABEL_18;
        if ( *(int *)(this + 120) >= 3 )
          continue;
        result = 0;
        break;
    }
    return result;
  }
}
