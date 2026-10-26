int __thiscall sub_5A7F10(int *this, int *a2)
{
  int v3; // edx
  int v4; // edi
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // eax

  v3 = 0;
  v4 = 0;
  if ( !this[1126] )
    v3 = 16;
  if ( !a2 )
  {
    sub_591C60((int)this, -1, aInvalidParamet);
    return -1;
  }
  v5 = *a2;
  if ( (*a2 & 2) != 0 )
    v3 |= 8u;
  if ( (v5 & 0x10) != 0 )
    v3 |= 8u;
  if ( (v5 & 0x20) != 0 )
  {
    v6 = this[1297];
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( !v7 )
      {
        v3 |= 0x210u;
        goto LABEL_16;
      }
      if ( v7 != 1 )
        goto LABEL_16;
    }
    else
    {
      v4 = 2;
    }
    v3 |= 0x200u;
  }
LABEL_16:
  v8 = (*(int (__stdcall **)(int, int, int, int, int, int *))(*(_DWORD *)this[1112] + 92))(
         this[1112],
         a2[2] * a2[3],
         v3,
         a2[1],
         v4,
         a2 + 8);
  *this = v8;
  if ( !v8 )
    return 0;
  sub_591C60((int)this, -1, aErrorCreatingV);
  return -1;
}
