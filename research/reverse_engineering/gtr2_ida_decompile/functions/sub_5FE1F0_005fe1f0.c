int __thiscall sub_5FE1F0(_DWORD *this, int a2, int a3)
{
  int *v3; // eax
  _DWORD *v4; // esi
  int result; // eax
  int v6; // eax
  int *v7; // eax
  void *v8; // eax
  int v9; // edi

  v3 = (int *)this[177];
  v4 = this + 177;
  this[179] = v3;
  if ( v3 && (result = *v3) != 0 )
  {
    while ( *(_DWORD *)(result + 20) != a2 || *(_DWORD *)(result + 24) != a3 )
    {
      v6 = this[179];
      if ( v6 )
        this[179] = *(_DWORD *)(v6 + 4);
      v7 = (int *)this[179];
      if ( v7 )
      {
        result = *v7;
        if ( result )
          continue;
      }
      goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    v8 = operator new(0x1Cu);
    v9 = (int)v8;
    if ( v8 )
    {
      sub_5D9010(v8);
      *(_BYTE *)v9 = 0;
      *(_DWORD *)(v9 + 20) = 0;
      *(_DWORD *)(v9 + 24) = 0;
    }
    else
    {
      v9 = 0;
    }
    *(_DWORD *)(v9 + 20) = a2;
    *(_DWORD *)(v9 + 24) = a3;
    sub_5FDFB0(v4, v9, 1);
    return v9;
  }
  return result;
}
