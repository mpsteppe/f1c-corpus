// f1c  0x00489450  size=38
int __thiscall sub_489450(_DWORD *this)
{
  int v1; // edx
  int result; // eax

  v1 = this[90];
  result = 0;
  if ( v1 >= 0 )
  {
    for ( result = this[36]; result; --v1 )
    {
      if ( v1 <= 0 )
        break;
      result = *(_DWORD *)(result + 140);
    }
  }
  return result;
}
