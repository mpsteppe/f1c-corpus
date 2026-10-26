// f1c  0x00547860  size=69
int __thiscall sub_547860(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax
  int i; // edx

  v2 = this[10];
  result = 0;
  if ( v2 )
  {
    result = this[10];
    for ( i = *(_DWORD *)(v2 + 92); i; i = *(_DWORD *)(i + 92) )
      result = i;
    *(_DWORD *)(result + 92) = a2;
    *(_DWORD *)(a2 + 88) = result;
    *(_DWORD *)(a2 + 92) = 0;
    ++this[3];
  }
  else
  {
    this[10] = a2;
    *(_DWORD *)(a2 + 88) = 0;
    *(_DWORD *)(a2 + 92) = 0;
    ++this[3];
  }
  return result;
}
