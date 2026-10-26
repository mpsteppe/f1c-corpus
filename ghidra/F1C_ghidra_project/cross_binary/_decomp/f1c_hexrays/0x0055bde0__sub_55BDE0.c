// f1c  0x0055bde0  size=56
int __thiscall sub_55BDE0(_DWORD *this, int a2)
{
  int result; // eax
  int i; // edx

  if ( a2 >= this[71] )
    return 0;
  result = this[72];
  for ( i = 0; i < a2; result = *(_DWORD *)(result + 32) )
  {
    if ( !*(_DWORD *)(result + 32) )
      break;
    ++i;
  }
  return result;
}
