int __thiscall sub_4586A0(_DWORD *this)
{
  unsigned int v2; // ecx
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int v5; // edi
  int result; // eax

  while ( 1 )
  {
    v2 = this[8];
    if ( v2 >= 0xB )
    {
      v2 = 11;
LABEL_4:
      v3 = this + 9;
      do
      {
        *v3 = *(_DWORD *)(*v3 + 28);
        ++v3;
        --v2;
      }
      while ( v2 );
      goto LABEL_6;
    }
    if ( v2 )
      goto LABEL_4;
LABEL_6:
    v4 = this + 21;
    v5 = 4;
    do
    {
      if ( *v4 )
        sub_4586A0();
      ++v4;
      --v5;
    }
    while ( v5 );
    result = this[25];
    if ( !result )
      return result;
    this = (_DWORD *)this[25];
  }
}
