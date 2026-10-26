void __thiscall sub_40A730(void **this, void *a2)
{
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax
  void *v6; // ebx

  if ( a2 )
  {
    v3 = *this;
    if ( *this )
    {
      while ( (void *)*v3 != a2 )
      {
        v3 = (_DWORD *)v3[1];
        if ( !v3 )
          goto LABEL_19;
      }
      if ( v3 == this[2] )
        this[2] = (void *)v3[1];
      v4 = v3[2];
      if ( v4 )
        *(_DWORD *)(v4 + 4) = v3[1];
      else
        *this = (void *)v3[1];
      v5 = v3[1];
      if ( v5 )
        *(_DWORD *)(v5 + 8) = v3[2];
      if ( this[1] == v3 )
        this[1] = (void *)v3[2];
      this[3] = (char *)this[3] - 1;
      if ( *((_BYTE *)v3 + 12) )
      {
        v6 = (void *)*v3;
        if ( *v3 )
        {
          sub_459AC0(*v3);
          sub_5BE8AE(v6);
        }
      }
      sub_5BE8AE(v3);
    }
  }
LABEL_19:
  if ( a2 == this[4] )
  {
    this[4] = 0;
    sub_40A240(this, 0);
  }
}
