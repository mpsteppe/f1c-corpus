bool __thiscall sub_54F230(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax

  v2 = this[418];
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_4:
    v3 = -2;
  }
  else
  {
    while ( *(_DWORD *)(a2 + 22468) != this[2 * v3 + 210] )
    {
      if ( ++v3 >= v2 )
        goto LABEL_4;
    }
  }
  return v3 >= 0;
}
