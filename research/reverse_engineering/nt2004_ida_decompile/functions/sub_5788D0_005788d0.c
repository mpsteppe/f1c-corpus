int __thiscall sub_5788D0(int **this)
{
  int result; // eax
  int *v3; // ebx
  int v4; // esi
  _BYTE *v5; // edi

  result = sub_578800(*this);
  v3 = *this;
  if ( *this )
  {
    if ( v3[132] )
      sub_5BE8AE();
    v4 = *v3;
    while ( v4 )
    {
      v5 = (_BYTE *)v4;
      v4 = *(_DWORD *)(v4 + 4);
      if ( v5[8] )
      {
        if ( *(_DWORD *)v5 )
        {
          sub_40D5B0((LPVOID *)(*(_DWORD *)v5 + 324));
          sub_5BE8AE();
        }
      }
      sub_5BE8AE();
    }
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    return sub_5BE8AE();
  }
  return result;
}
