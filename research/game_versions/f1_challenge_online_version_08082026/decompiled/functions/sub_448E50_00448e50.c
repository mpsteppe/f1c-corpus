int __thiscall sub_448E50(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx
  int result; // eax

  while ( 1 )
  {
    sub_448E20(this);
    v2 = this + 19;
    v3 = 4;
    do
    {
      if ( *v2 )
        sub_448E50();
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
