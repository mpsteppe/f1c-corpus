void **__thiscall sub_60C8D0(_DWORD *this)
{
  void **v2; // eax
  char *v3; // ebx
  int v4; // edi
  int v5; // eax
  char *v6; // ebp
  void **v7; // eax
  void **result; // eax
  char *i; // ebx
  int v10; // edi
  int v11; // eax
  char *v12; // ebp

  v2 = (void **)this[51];
  this[53] = v2;
  if ( v2 )
  {
    v3 = (char *)*v2;
    if ( *v2 )
    {
      do
      {
        ((void (__thiscall *)(char *))loc_5F80E0)(v3);
        v4 = this[51];
        v5 = 0;
        if ( v4 )
        {
          while ( *(char **)v4 != v3 )
          {
            v5 = v4;
            v4 = *(_DWORD *)(v4 + 4);
            if ( !v4 )
              goto LABEL_18;
          }
          if ( v4 == this[53] )
            this[53] = *(_DWORD *)(v4 + 4);
          if ( v5 )
            *(_DWORD *)(v5 + 4) = *(_DWORD *)(v4 + 4);
          else
            this[51] = *(_DWORD *)(v4 + 4);
          if ( this[52] == v4 )
            this[52] = v5;
          --this[54];
          if ( *(_BYTE *)(v4 + 8) )
          {
            v6 = *(char **)v4;
            if ( *(_DWORD *)v4 )
            {
              sub_5F77C0(*(char **)v4);
              j__free(v6);
            }
          }
          j__free((void *)v4);
        }
LABEL_18:
        `eh vector destructor iterator'(v3, 0x17Cu, *((_DWORD *)v3 - 1), (void (__thiscall *)(void *))sub_5F77C0);
        j__free(v3 - 4);
        v7 = (void **)this[51];
        this[53] = v7;
        if ( !v7 )
          break;
        v3 = (char *)*v7;
      }
      while ( *v7 );
    }
  }
  result = (void **)this[55];
  this[57] = result;
  if ( result )
  {
    for ( i = (char *)*result; *result; i = (char *)*result )
    {
      sub_5FA840((int)i);
      v10 = this[55];
      v11 = 0;
      if ( v10 )
      {
        while ( *(char **)v10 != i )
        {
          v11 = v10;
          v10 = *(_DWORD *)(v10 + 4);
          if ( !v10 )
            goto LABEL_37;
        }
        if ( v10 == this[57] )
          this[57] = *(_DWORD *)(v10 + 4);
        if ( v11 )
          *(_DWORD *)(v11 + 4) = *(_DWORD *)(v10 + 4);
        else
          this[55] = *(_DWORD *)(v10 + 4);
        if ( this[56] == v10 )
          this[56] = v11;
        --this[58];
        if ( *(_BYTE *)(v10 + 8) )
        {
          v12 = *(char **)v10;
          if ( *(_DWORD *)v10 )
          {
            sub_5F77C0(*(char **)v10);
            j__free(v12);
          }
        }
        j__free((void *)v10);
      }
LABEL_37:
      `eh vector destructor iterator'(i, 0x190u, *((_DWORD *)i - 1), (void (__thiscall *)(void *))sub_5F77C0);
      j__free(i - 4);
      result = (void **)this[55];
      this[57] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
