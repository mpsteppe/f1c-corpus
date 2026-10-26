// f1c  0x00598c4a  size=38
int __thiscall sub_598C4A(_DWORD *this)
{
  int v2; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  sub_59A54D(v4);
  v2 = this[1];
  if ( v2 != -1 )
    this[1] = v2 + 1;
  return sub_59A5E9(v4);
}
