char __thiscall sub_4DED50(_DWORD *this)
{
  char result; // al
  _DWORD *v2; // edx
  int v3; // eax
  int v4; // eax

  for ( result = 0; this[6]; result = 1 )
  {
    v2 = (_DWORD *)this[6];
    if ( v2[13] != 1 )
      break;
    v3 = this[5];
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 + 88) )
      {
        v4 = v2[23];
        this[6] = v4;
        *(_DWORD *)(v4 + 88) = 0;
        v2[22] = 0;
        v2[23] = 0;
      }
    }
  }
  return result;
}
