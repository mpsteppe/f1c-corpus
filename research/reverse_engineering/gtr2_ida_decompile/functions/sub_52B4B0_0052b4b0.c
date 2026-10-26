void __thiscall sub_52B4B0(int this, char a2)
{
  _BYTE *v3; // esi
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]

  *(float *)(this + 20) = dbl_FB1D18;
  v3 = off_757C18;
  sub_53F0E0(1);
  sub_53F190(v3, 1, v5);
  sub_53F230(v3, 1, v4);
  sub_577660(v3 + 16, 0);
  v3[20416] = 0;
  if ( a2 )
    sub_429200((int)v3, 1);
  else
    sub_429200((int)v3, 0);
  sub_41FC00((int)v3);
  *(_DWORD *)(this + 12) = 0;
  *(_BYTE *)(this + 1) = a2 != 0;
  sub_52B2C0((char *)this, 1);
  *(_DWORD *)(this + 4) = 0;
  *(float *)(this + 16) = sub_577BC0((char *)off_757C18 + 16);
}
