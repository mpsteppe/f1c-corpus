// f1c  0x00587510  size=101
char __thiscall sub_587510(int this, const void *a2, int a3)
{
  char result; // al

  if ( a3 > *(_DWORD *)(this + 4) )
  {
    if ( *(_DWORD *)this )
      sub_587BCF(*(LPVOID *)this);
    sub_5874D0(a3, (_DWORD *)this);
    *(_DWORD *)(this + 4) = a3;
  }
  if ( *(_DWORD *)this && a3 > 0 )
  {
    qmemcpy(*(void **)this, a2, a3);
    result = 1;
    *(_DWORD *)(this + 8) = a3;
  }
  else
  {
    *(_DWORD *)(this + 8) = 0;
    return 1;
  }
  return result;
}
