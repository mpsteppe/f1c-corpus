int __thiscall sub_4DA5C0(_DWORD *this)
{
  int result; // eax

  result = this[2];
  *this = 0;
  *(_DWORD *)(result + 2164) = 5;
  return result;
}
