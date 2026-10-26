// f1c  0x00404790  size=53
int __thiscall sub_404790(_DWORD *this)
{
  int result; // eax
  int v3; // edi
  int v4; // ebx

  result = this[76];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = 0;
    do
    {
      sub_4FB5D0(v4 + this[77]);
      result = this[76];
      ++v3;
      v4 += 316;
    }
    while ( v3 < result );
  }
  return result;
}
