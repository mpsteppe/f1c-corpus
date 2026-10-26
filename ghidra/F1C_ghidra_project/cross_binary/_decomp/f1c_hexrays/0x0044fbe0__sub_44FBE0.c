// f1c  0x0044fbe0  size=53
int __thiscall sub_44FBE0(_DWORD *this)
{
  int result; // eax

  result = this[32];
  this[189] = 0;
  if ( result )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)result + 32))(result);
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)this[32] + 8))(this[32]);
    this[32] = 0;
  }
  return result;
}
