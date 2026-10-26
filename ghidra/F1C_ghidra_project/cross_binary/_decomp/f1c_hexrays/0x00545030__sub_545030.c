// f1c  0x00545030  size=85
int __thiscall sub_545030(_DWORD *this, int a2)
{
  int result; // eax
  int i; // ecx

  result = this[62];
  if ( result )
  {
    for ( i = *(_DWORD *)(result + 440); i; i = *(_DWORD *)(i + 440) )
      result = i;
    *(_DWORD *)(result + 440) = a2;
    *(_DWORD *)(a2 + 436) = result;
    *(_DWORD *)(a2 + 440) = 0;
  }
  else
  {
    result = a2;
    this[62] = a2;
    *(_DWORD *)(a2 + 436) = 0;
    *(_DWORD *)(a2 + 440) = 0;
  }
  return result;
}
