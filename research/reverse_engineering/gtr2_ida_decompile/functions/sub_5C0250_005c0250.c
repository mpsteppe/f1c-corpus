int __thiscall sub_5C0250(_DWORD *this)
{
  int result; // eax
  void (__thiscall ***v3)(_DWORD, int); // ecx
  bool v4; // zf

  result = this[90];
  if ( result )
  {
    do
    {
      v3 = *(void (__thiscall ****)(_DWORD, int))(this[92] + 4 * this[90] - 4);
      if ( v3 )
        (**v3)(v3, 1);
      result = this[90] - 1;
      v4 = this[90] == 1;
      this[90] = result;
    }
    while ( !v4 );
  }
  return result;
}
