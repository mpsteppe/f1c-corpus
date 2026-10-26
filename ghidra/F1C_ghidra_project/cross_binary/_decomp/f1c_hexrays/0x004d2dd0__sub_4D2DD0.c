// f1c  0x004d2dd0  size=66
int __thiscall sub_4D2DD0(_DWORD *this)
{
  int result; // eax
  _DWORD *v3; // eax
  int *v4; // eax

  result = this[41];
  if ( !result )
  {
    v3 = (_DWORD *)sub_587C03(8);
    if ( v3 )
    {
      v4 = sub_4D0060(v3);
      this[41] = v4;
      return sub_4D0110(v4);
    }
    else
    {
      this[41] = 0;
      return sub_4D0110(0);
    }
  }
  return result;
}
