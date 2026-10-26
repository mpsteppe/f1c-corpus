void __thiscall sub_614990(int **this, char *String2)
{
  int *v3; // eax
  bool v4; // zf
  int v5; // edi
  const char *v6; // eax
  int *v7; // eax
  int *v8; // eax
  int *v9; // esi
  int *v10; // eax
  void *v11; // edi

  v3 = *this;
  v4 = *this == 0;
  this[2] = *this;
  if ( !v4 )
  {
    v5 = *v3;
    if ( *v3 )
    {
      while ( 1 )
      {
        v6 = *(const char **)(v5 + 4);
        if ( !v6 )
          v6 = WindowName;
        if ( !_stricmp(v6, String2) && !*(_BYTE *)v5 )
          break;
        v7 = this[2];
        if ( v7 )
        {
          v8 = (int *)v7[1];
          this[2] = v8;
          if ( v8 )
          {
            v5 = *v8;
            if ( *v8 )
              continue;
          }
        }
        return;
      }
      v9 = *this;
      v10 = 0;
      if ( *this )
      {
        while ( *v9 != v5 )
        {
          v10 = v9;
          v9 = (int *)v9[1];
          if ( !v9 )
            return;
        }
        if ( v9 == this[2] )
          this[2] = (int *)v9[1];
        if ( v10 )
          v10[1] = v9[1];
        else
          *this = (int *)v9[1];
        if ( this[1] == v9 )
          this[1] = v10;
        this[3] = (int *)((char *)this[3] - 1);
        if ( *((_BYTE *)v9 + 8) )
        {
          v11 = (void *)*v9;
          if ( *v9 )
          {
            sub_614070((_DWORD *)*v9);
            j__free(v11);
          }
        }
        j__free(v9);
      }
    }
  }
}
