int __thiscall sub_5C2F70(_DWORD *this)
{
  int result; // eax
  void (__thiscall ***v3)(_DWORD, int); // ecx
  bool v4; // zf

  result = this[13];
  if ( result )
  {
    do
    {
      v3 = *(void (__thiscall ****)(_DWORD, int))(this[15] + 4 * this[13] - 4);
      if ( v3 )
        (**v3)(v3, 1);
      result = this[13] - 1;
      v4 = this[13] == 1;
      this[13] = result;
    }
    while ( !v4 );
  }
  return result;
}
