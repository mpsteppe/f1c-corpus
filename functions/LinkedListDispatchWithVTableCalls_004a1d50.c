int __thiscall sub_4A1D50(int *this, int a2, int a3)
{
  int result; // eax
  bool v5; // zf
  void (__thiscall ***i)(_DWORD, int); // ecx

  if ( a3 )
    ResourceLookupWithDualPath(a3);
  result = *this;
  v5 = *this == 0;
  this[2] = *this;
  if ( !v5 )
  {
    for ( i = *(void (__thiscall ****)(_DWORD, int))result;
          *(_DWORD *)result;
          i = *(void (__thiscall ****)(_DWORD, int))result )
    {
      (**i)(i, a2);
      result = this[2];
      if ( !result )
        break;
      result = *(_DWORD *)(result + 4);
      this[2] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
