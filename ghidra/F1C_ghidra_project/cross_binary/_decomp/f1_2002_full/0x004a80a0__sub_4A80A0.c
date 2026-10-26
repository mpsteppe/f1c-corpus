// f1_2002_full  0x004a80a0  size=39
int __thiscall sub_4A80A0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // esi

  this[5] = a2;
  result = this[7];
  v3 = this[5];
  v4 = this[8];
  if ( v3 >= result )
  {
    if ( v3 > v4 )
      this[5] = v4;
  }
  else
  {
    this[5] = result;
  }
  return result;
}
