int __thiscall sub_681430(char *this, _DWORD *a2)
{
  _DWORD *v2; // eax
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // ecx
  void *v11; // edi

  v2 = a2;
  if ( !a2 )
    return -2147467259;
  *(_DWORD *)this = *a2;
  v5 = a2[1];
  if ( v5 > *((_DWORD *)this + 1) )
  {
    if ( v5 > 8 )
    {
      v6 = sub_681169(a2[1]);
      *((_DWORD *)this + 2) = v6;
      if ( !v6 )
        return -2147024882;
      v2 = a2;
    }
    else
    {
      *((_DWORD *)this + 2) = this + 64;
    }
  }
  v7 = v2[1];
  *((_DWORD *)this + 1) = v7;
  qmemcpy(*((void **)this + 2), (const void *)v2[2], 4 * v7);
  v8 = v2[3];
  if ( v8 > *((_DWORD *)this + 3) )
  {
    if ( v8 > 4 )
    {
      v9 = sub_681169(v2[3]);
      *((_DWORD *)this + 4) = v9;
      if ( !v9 )
        return -2147024882;
      v2 = a2;
    }
    else
    {
      *((_DWORD *)this + 4) = this + 96;
    }
  }
  v10 = v2[3];
  v11 = (void *)*((_DWORD *)this + 4);
  *((_DWORD *)this + 3) = v10;
  qmemcpy(v11, (const void *)v2[4], 4 * v10);
  *((_DWORD *)this + 9) = v2[9];
  *((_DWORD *)this + 10) = v2[10];
  *((_DWORD *)this + 12) = v2[12];
  *((_DWORD *)this + 15) = v2[15];
  return 0;
}
