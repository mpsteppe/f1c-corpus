LPVOID __thiscall sub_4E3E50(LPVOID *this)
{
  LPVOID *v2; // esi
  int v3; // edi
  LPVOID result; // eax
  LPVOID **v5; // esi
  LPVOID **v6; // ebp
  char v7; // al
  LPVOID *v8; // edi

  if ( this[7734] )
    sub_5BE8AE(this[7734]);
  if ( this[7732] )
    sub_5BE8AE(this[7732]);
  sub_4E3520(this + 7571);
  v2 = this + 7571;
  v3 = 47;
  do
  {
    v2 -= 161;
    result = sub_4E3520(v2);
    --v3;
  }
  while ( v3 );
  v5 = (LPVOID **)*this;
  if ( *this )
  {
    do
    {
      v6 = v5;
      v7 = *((_BYTE *)v5 + 8);
      v5 = (LPVOID **)v5[1];
      if ( v7 )
      {
        v8 = *v6;
        if ( *v6 )
        {
          if ( *v8 )
            sub_5BE8AE(*v8);
          sub_5BE8AE(v8);
        }
      }
      result = (LPVOID)sub_5BE8AE(v6);
    }
    while ( v5 );
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
