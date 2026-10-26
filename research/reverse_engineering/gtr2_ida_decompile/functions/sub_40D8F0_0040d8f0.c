char __thiscall sub_40D8F0(_DWORD *this, int a2, char a3)
{
  char result; // al
  int v4; // edi
  int v5; // edx
  int i; // esi

  result = 0;
  if ( a2 )
  {
    v4 = this[4];
    v5 = 0;
    if ( v4 > 0 )
    {
      for ( i = this[3]; i != a2; i += 164 )
      {
        if ( ++v5 >= this[4] )
          return result;
      }
      if ( v5 >= 0 )
      {
        if ( v5 < v4 )
          this[5] = v5;
        if ( a3 )
          (*(void (__thiscall **)(_DWORD *))(*this + 16))(this);
        return 1;
      }
    }
  }
  return result;
}
