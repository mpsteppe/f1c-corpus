char __thiscall sub_40DB60(_DWORD *this, int a2, char a3)
{
  char result; // al
  int v5; // edi
  int v6; // ecx
  int i; // edx
  int v8; // eax

  result = 0;
  if ( a2 )
  {
    v5 = this[4];
    v6 = 0;
    if ( v5 > 0 )
    {
      for ( i = this[3]; i != a2; i += 272 )
      {
        if ( ++v6 >= this[4] )
          return result;
      }
      if ( v6 >= 0 )
      {
        if ( v6 < v5 )
        {
          v8 = *this;
          this[5] = v6;
          (*(void (__thiscall **)(_DWORD *))(v8 + 16))(this);
        }
        if ( a3 )
          (*(void (__thiscall **)(_DWORD *))(*this + 16))(this);
        return 1;
      }
    }
  }
  return result;
}
