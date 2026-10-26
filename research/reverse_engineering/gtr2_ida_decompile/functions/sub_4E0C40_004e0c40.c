int __thiscall sub_4E0C40(_DWORD *this, char a2)
{
  int v3; // eax
  int v5; // ecx
  int i; // esi
  int v7; // [esp-Ch] [ebp-10h]
  int v8; // [esp-8h] [ebp-Ch]

  for ( ; (unsigned __int8)sub_4DF840(); this = (_DWORD *)sub_4DF700() )
    ;
  if ( this[15] )
  {
    v5 = this[16];
    if ( v5 && a2 )
      sub_4E40C0(v5);
    for ( i = this[13]; i; i = sub_4CD340() )
      (*(void (__thiscall **)(int))(*(_DWORD *)i + 48))(i);
    return 0;
  }
  else
  {
    v8 = dword_903EBC;
    v7 = *(_DWORD *)dword_903EB8;
    v3 = sub_4DDFE0();
    sub_4DD980(&unk_B6E2A0, v3, 0, 0, v7, v8, 16);
    return -1;
  }
}
