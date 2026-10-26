int __thiscall sub_547280(_DWORD *this, int a2, int a3)
{
  int result; // eax

  result = a3;
  if ( a3 == 4096 )
  {
    result = a2;
    this[35] = a2;
  }
  else if ( a3 == 0x2000 )
  {
    this[36] = a2;
  }
  return result;
}

