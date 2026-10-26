void __thiscall sub_5E6500(void *this)
{
  int *v2; // eax
  int v3; // ebx
  int v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  int *v7; // eax
  void *v8; // esi
  int v9; // ecx
  void *v10; // esi

  v2 = (int *)*((_DWORD *)this + 17);
  *((_DWORD *)this + 19) = v2;
  if ( v2 )
  {
    v3 = *v2;
    if ( *v2 )
    {
      do
      {
        sub_5E6500(v3);
        v4 = *(_DWORD *)(v3 + 48);
        if ( v4 )
          *(_DWORD *)(v4 + 464) = 0;
        v5 = (_DWORD *)*((_DWORD *)this + 17);
        v6 = 0;
        if ( v5 )
        {
          while ( *v5 != v3 )
          {
            v6 = v5;
            v5 = (_DWORD *)v5[1];
            if ( !v5 )
              goto LABEL_17;
          }
          if ( v5 == *((_DWORD **)this + 19) )
            *((_DWORD *)this + 19) = v5[1];
          if ( v6 )
            v6[1] = v5[1];
          else
            *((_DWORD *)this + 17) = v5[1];
          if ( *((_DWORD **)this + 18) == v5 )
            *((_DWORD *)this + 18) = v6;
          --*((_DWORD *)this + 20);
          sub_5DA690((int)v5);
          j__free(v5);
        }
LABEL_17:
        v7 = (int *)*((_DWORD *)this + 17);
        *((_DWORD *)this + 19) = v7;
        if ( !v7 )
          break;
        v3 = *v7;
      }
      while ( *v7 );
    }
  }
  if ( *((_DWORD *)this + 11) )
  {
    sub_5FF560();
    v8 = (void *)*((_DWORD *)this + 11);
    if ( v8 )
    {
      sub_600430(*((void **)this + 11));
      j__free(v8);
    }
    *((_DWORD *)this + 11) = 0;
  }
  if ( (*(_DWORD *)this & 0x20000) != 0 )
  {
    v9 = *((_DWORD *)this + 10);
    if ( v9 )
    {
      sub_5E4AA0(v9, 0);
      v10 = (void *)*((_DWORD *)this + 10);
      if ( v10 )
      {
        sub_5E39C0(*((char **)this + 10));
        j__free(v10);
      }
      *((_DWORD *)this + 10) = 0;
    }
  }
}
