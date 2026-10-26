char __thiscall sub_616C30(_DWORD *this, char *String2)
{
  char v2; // bl
  int v4; // ebp
  unsigned int v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  char *String2a; // [esp+Ch] [ebp+4h]

  v2 = 0;
  if ( !String2 )
    return 0;
  v4 = sub_616B50(this, String2);
  if ( v4 < 0 )
    return 0;
  v5 = 0;
  String2a = 0;
  do
  {
    v6 = (_DWORD *)this[v5];
    if ( v6 )
    {
      do
      {
        v7 = (_DWORD *)v6[1];
        if ( v6[7] == v4 )
        {
          sub_616960(this, v6);
          v2 = 1;
        }
        v6 = v7;
      }
      while ( v7 );
      v5 = (unsigned int)String2a;
    }
    String2a = (char *)++v5;
  }
  while ( v5 < 9 );
  return v2;
}
