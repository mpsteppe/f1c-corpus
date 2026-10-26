int __thiscall sub_60AED0(_DWORD *this)
{
  int v2; // eax
  int result; // eax

  while ( (int)this[4] > 0 )
  {
    v2 = this[8];
    if ( v2 && !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 48))(this[8]) )
      --this[4];
  }
  result = this[8];
  this[4] = 0;
  if ( result )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 8))(result);
    this[8] = 0;
  }
  return result;
}
