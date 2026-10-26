// f1c  0x0056eb90  size=109
int __thiscall sub_56EB90(int *this)
{
  int result; // eax
  int v2; // esi
  int v3; // edi
  _DWORD *v4; // eax

  result = *this;
  v2 = 0;
  if ( *this > 0 )
  {
    v3 = 0;
    do
    {
      v4 = (_DWORD *)(v3 + this[1]);
      v4[77] = 0;
      v4[78] = 0;
      v4[79] = 0;
      v4[80] = 0;
      v4[81] = 0;
      v4[82] = 0;
      v4[83] = 0;
      v4[84] = 0;
      v4[85] = 0;
      v4[86] = 0;
      v4[87] = 0;
      v4[88] = 0;
      result = *this;
      ++v2;
      v3 += 580;
    }
    while ( v2 < *this );
  }
  return result;
}
