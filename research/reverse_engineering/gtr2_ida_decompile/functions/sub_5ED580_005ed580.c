int __thiscall sub_5ED580(_DWORD *this, int a2, void *a3)
{
  int v3; // edx
  _BYTE *v4; // eax

  v3 = this[113];
  if ( v3 )
  {
    if ( a2 >= *(_DWORD *)(v3 + 8) )
    {
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid collision point index in instance %s", (_BYTE)this - 44);
      return 0;
    }
    v4 = (_BYTE *)(*(_DWORD *)(v3 + 12) + 116 * a2);
    if ( (*v4 & 0x10) != 0 )
    {
      qmemcpy(a3, v4 + 52, 0x40u);
      return 1;
    }
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "No collision object in instance %s", (_BYTE)this - 44);
  }
  return 0;
}
