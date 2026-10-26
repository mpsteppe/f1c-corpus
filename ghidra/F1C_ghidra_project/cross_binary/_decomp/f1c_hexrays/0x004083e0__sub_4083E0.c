// f1c  0x004083e0  size=50
int __thiscall sub_4083E0(_BYTE *this)
{
  bool v2; // zf
  int result; // eax

  v2 = this[21] == 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 1065353216;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  this[20] = 0;
  if ( !v2 )
  {
    result = sub_4D8860(1);
    this[21] = 0;
  }
  return result;
}
