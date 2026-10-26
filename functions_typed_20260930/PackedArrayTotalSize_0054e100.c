int __thiscall sub_54E100(_DWORD *this)
{
  int v1; // edx
  int result; // eax
  _DWORD *v3; // ecx

  v1 = this[70];
  result = 0;
  if ( v1 > 0 )
  {
    v3 = (_DWORD *)(this[71] + 8);
    do
    {
      result += *v3;
      v3 += 16;
      --v1;
    }
    while ( v1 );
  }
  return result;
}

