int __thiscall sub_5C2FB0(_DWORD *this)
{
  int result; // eax
  void (__thiscall ***v3)(_DWORD, int); // ecx
  bool v4; // zf

  result = this[16];
  if ( result )
  {
    do
    {
      v3 = *(void (__thiscall ****)(_DWORD, int))(this[18] + 4 * this[16] - 4);
      if ( v3 )
        (**v3)(v3, 1);
      result = this[16] - 1;
      v4 = this[16] == 1;
      this[16] = result;
    }
    while ( !v4 );
  }
  return result;
}
