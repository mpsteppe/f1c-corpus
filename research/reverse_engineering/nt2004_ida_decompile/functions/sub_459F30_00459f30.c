LPVOID __thiscall sub_459F30(int this)
{
  LPVOID result; // eax

  result = *(LPVOID *)this;
  if ( *(_DWORD *)this )
  {
    result = (LPVOID)sub_5BE8AE(*(LPVOID *)this);
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
  return result;
}
