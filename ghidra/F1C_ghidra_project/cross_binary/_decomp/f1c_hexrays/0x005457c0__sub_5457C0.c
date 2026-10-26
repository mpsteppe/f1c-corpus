// f1c  0x005457c0  size=46
int __thiscall sub_5457C0(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  v2 = a2;
  if ( a2 < 0 || a2 >= this[71] )
    return 0;
  result = this[72];
  if ( a2 > 0 )
  {
    do
    {
      --v2;
      result = *(_DWORD *)(result + 108);
    }
    while ( v2 );
  }
  return result;
}
