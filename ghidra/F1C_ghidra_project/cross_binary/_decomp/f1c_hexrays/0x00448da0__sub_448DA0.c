// f1c  0x00448da0  size=52
int __thiscall sub_448DA0(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx
  int result; // eax

  while ( 1 )
  {
    sub_448730((int)this);
    v2 = this + 19;
    v3 = 4;
    do
    {
      if ( *v2 )
        sub_448DA0();
      ++v2;
      --v3;
    }
    while ( v3 );
    result = this[23];
    if ( !result )
      break;
    this = (_DWORD *)this[23];
  }
  return result;
}
