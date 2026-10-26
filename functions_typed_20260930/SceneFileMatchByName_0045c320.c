char __thiscall sub_45C320(_DWORD *this, const char *a2, _DWORD *a3)
{
  int *v4; // eax
  int v5; // esi
  const char *v6; // ecx
  char *v7; // eax
  int v8; // eax
  int *v9; // eax

  v4 = (int *)this[1];
  this[3] = v4;
  if ( v4 && (v5 = *v4) != 0 )
  {
    while ( 1 )
    {
      v6 = &a2[strlen(a2)];
      if ( v6 > a2 )
      {
        while ( *v6 != 92 )
        {
          if ( --v6 <= a2 )
            goto LABEL_8;
        }
        ++v6;
      }
LABEL_8:
      v7 = *(char **)v5;
      if ( !*(_DWORD *)v5 )
        v7 = byte_5EA438;
      if ( !sub_588410(v6, v7) )
        break;
      v8 = this[3];
      if ( v8 )
        this[3] = *(_DWORD *)(v8 + 4);
      v9 = (int *)this[3];
      if ( v9 )
      {
        v5 = *v9;
        if ( *v9 )
          continue;
      }
      goto LABEL_15;
    }
    *a3 = *(_DWORD *)(v5 + 8);
    return 1;
  }
  else
  {
LABEL_15:
    *a3 = 0;
    return 0;
  }
}

