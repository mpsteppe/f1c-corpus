int __thiscall sub_44EFE0(_DWORD *this)
{
  int result; // eax

  result = this[1];
  this[158] = 0;
  if ( result )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)result + 32))(result);
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)this[1] + 8))(this[1]);
    this[1] = 0;
  }
  return result;
}
