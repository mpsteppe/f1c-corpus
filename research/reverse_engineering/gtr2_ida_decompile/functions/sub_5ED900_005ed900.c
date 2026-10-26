int __thiscall sub_5ED900(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // edx
  int v4; // esi
  _DWORD *v5; // eax

  v3 = this[113];
  if ( v3 && (v4 = *(_DWORD *)(v3 + 12)) != 0 )
  {
    if ( a3 >= *(_DWORD *)(v3 + 8) )
    {
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid collision point index in instance %s", (_BYTE)this - 44);
      return -1;
    }
    else
    {
      v5 = (_DWORD *)(v4 + 116 * a3);
      v5[1] = *a2;
      v5[2] = a2[1];
      v5[3] = a2[2];
      v5[7] = a2[3];
      v5[8] = a2[4];
      v5[9] = a2[5];
      *v5 |= 0x80u;
      return 0;
    }
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "No collision object in instance %s", (_BYTE)this - 44);
    return -1;
  }
}
