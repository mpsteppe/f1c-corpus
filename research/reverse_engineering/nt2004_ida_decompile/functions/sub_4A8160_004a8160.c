int __thiscall sub_4A8160(_DWORD *this)
{
  _DWORD *v1; // edi
  int v2; // ebp
  LPVOID **v3; // ebx
  char v4; // al
  LPVOID *v5; // esi
  int result; // eax

  v1 = this;
  v2 = *this;
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        sub_506C70(v5 + 12);
        if ( v5[24] )
          sub_5BE8AE(v5[24]);
        if ( v5[22] )
          sub_5BE8AE(v5[22]);
        sub_506920(v5 + 12);
        sub_4A8160(v5 + 7);
        if ( v5[4] )
          sub_5BE8AE(v5[4]);
        if ( v5[2] )
          sub_5BE8AE(v5[2]);
        if ( *v5 )
          sub_5BE8AE(*v5);
        sub_5BE8AE(v5);
        v1 = this;
      }
    }
    sub_5BE8AE(v3);
  }
  result = 0;
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return result;
}
