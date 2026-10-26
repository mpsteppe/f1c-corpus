int __thiscall sub_4852A0(_DWORD *this)
{
  int v2; // esi
  LPVOID **v3; // edi
  bool v4; // zf
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD v8[255]; // [esp+10h] [ebp-7F8h] BYREF
  _DWORD v9[255]; // [esp+40Ch] [ebp-3FCh] BYREF

  qmemcpy(v8, &unk_762B08, sizeof(v8));
  qmemcpy(v9, &unk_762F04, sizeof(v9));
  v2 = this[13];
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 && *v3 )
      sub_4115A0(*v3, 1);
    sub_5BE8AE(v3);
  }
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  sub_49D5B0(aCustom, -1);
  sub_49D5B0(aKeyboard, -1);
  if ( dword_768948 )
  {
    v5 = sub_451240(&v8[32]);
    sub_49D5B0(v5, -1);
    v6 = sub_451240(&v9[32]);
    sub_49D5B0(v6, -1);
    if ( !strcmp(&byte_629120, (const char *)sub_49D690(2)) )
      sub_49D5B0(aController1, 2);
    if ( !strcmp(&byte_629120, (const char *)sub_49D690(3)) )
      sub_49D5B0(aController2, 3);
  }
  else
  {
    sub_49D5B0(aController1, -1);
    sub_49D5B0(aController2, -1);
  }
  return 0;
}
