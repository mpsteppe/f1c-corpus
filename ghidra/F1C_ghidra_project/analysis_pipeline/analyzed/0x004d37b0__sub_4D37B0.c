// Address: 0x004d37b0
// Size: 314 bytes
// Name: sub_4D37B0
// Type: int __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_4D37B0(_DWORD *this)
{
  char *v2; // esi
  float v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h] BYREF
  int v6; // [esp+10h] [ebp-4h] BYREF

  sub_54C150(&v5, 2048);
  sub_54C150(&v6, 2048);
  v2 = (char *)&unk_5EC6D8 + 18624 * v5;
  if ( v6 != -11 )
  {
    sub_424CD0(5, 0);
    sub_4A5F20(v2 + 13004);
    if ( v2 == (char *)dword_7C54E8 )
    {
      pfnAPC(0);
      sub_40D450(&dword_5EA510);
    }
    goto LABEL_10;
  }
  sub_424CD0(4, 0);
  sub_4A5EA0(v2 + 13004);
  if ( v2 == (char *)dword_7C54E8 )
    pfnAPC(1u);
  if ( fabs(dbl_8AFEA0 - flt_8AC4B0) <= 3.0 )
  {
LABEL_10:
    sub_54FAE0(this[5]);
    return 0;
  }
  if ( dword_83EE60 < 1023 )
  {
    ++dword_83EE60;
    dword_8AAE64 += 432;
  }
  v4 = dbl_8AFEA0;
  sub_4B33B0(3, 7, 0, *((_DWORD *)v2 + 4645), LODWORD(v4), 0);
  flt_8AC4B0 = dbl_8AFEA0;
  sub_54FAE0(this[5]);
  return 0;
}
