int __thiscall sub_458E10(_DWORD *this)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // ebx

  while ( 1 )
  {
    sub_458780((int)this);
    v2 = this + 21;
    v4 = dword_16C9A58;
    do
    {
      if ( *v2 )
        sub_458E10();
      ++v2;
      --v4;
    }
    while ( v4 );
    result = this[25];
    if ( !result )
      break;
    this = (_DWORD *)this[25];
  }
  return result;
}
