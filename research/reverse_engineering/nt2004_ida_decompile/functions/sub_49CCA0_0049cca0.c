int __thiscall sub_49CCA0(_DWORD *this)
{
  int result; // eax
  int i; // edi
  _DWORD *v4; // ebp
  char v5; // al
  LPVOID *v6; // esi
  int v7; // esi
  int v8; // eax
  int v9; // eax

  result = this[61];
  if ( result )
  {
    for ( i = this[21]; i; result = sub_5BE8AE(v4) )
    {
      v4 = (_DWORD *)i;
      v5 = *(_BYTE *)(i + 8);
      i = *(_DWORD *)(i + 4);
      if ( v5 )
      {
        v6 = (LPVOID *)*v4;
        if ( *v4 )
        {
          sub_4AFEE0(*v4);
          if ( v6[5] )
            sub_5BE8AE(v6[5]);
          if ( v6[1] )
            sub_5BE8AE(v6[1]);
          sub_5BE8AE(v6);
        }
      }
    }
    v7 = 0;
    this[21] = 0;
    this[22] = 0;
    this[23] = 0;
    this[24] = 0;
    if ( *(int *)(this[61] + 12) > 0 )
    {
      do
      {
        v8 = sub_4B1160(v7);
        if ( v8 )
        {
          v9 = *(_DWORD *)(v8 + 28);
          if ( v9 )
            sub_49CD60(v9, 1);
        }
        result = *(_DWORD *)(this[61] + 12);
        ++v7;
      }
      while ( v7 < result );
    }
  }
  return result;
}
