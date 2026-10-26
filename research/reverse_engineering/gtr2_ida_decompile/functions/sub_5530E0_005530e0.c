int __thiscall sub_5530E0(void *this, int a2, int a3)
{
  int v4; // esi
  double v5; // st7
  char v6; // dl
  int v8; // [esp+0h] [ebp-10h]

  v4 = off_9034A4;
  if ( dword_82F4A0 < 1023 )
  {
    ++dword_82F4A0;
    off_9034A4 += 848;
  }
  v5 = dbl_FB1D18;
  *(float *)&v8 = dbl_FB1D18;
  sub_51B2A0((_DWORD *)v4, 4, 21, 2, 255, v8, 3);
  *(_BYTE *)(v4 + 8) = a2;
  if ( a3 < 0 )
  {
    *(_BYTE *)(v4 + 9) = -1;
    return sub_5500B0((int)this, v5, a2, *(char *)(v4 + 9));
  }
  else
  {
    v6 = *(_BYTE *)(*(&dword_91E088 + a3) + 22468);
    *(_BYTE *)(v4 + 9) = v6;
    return sub_5500B0((int)this, v5, a2, v6);
  }
}
