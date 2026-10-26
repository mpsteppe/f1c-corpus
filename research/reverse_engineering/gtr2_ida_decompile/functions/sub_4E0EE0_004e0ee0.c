int __thiscall sub_4E0EE0(_DWORD *this)
{
  int v2; // esi
  int v3; // esi
  int i; // esi
  char v6; // [esp+4h] [ebp-4h]

  if ( !this[21] )
    return 0;
  v2 = this[16];
  v6 = 1;
  if ( v2 )
  {
    while ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 120))(v2) )
    {
      v2 = sub_4CD340();
      if ( !v2 )
        goto LABEL_5;
    }
    goto LABEL_9;
  }
LABEL_5:
  v3 = *(_DWORD *)(this[17] + 52);
  if ( v3 )
  {
    while ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 120))(v3) )
    {
      v3 = sub_4CD340();
      if ( !v3 )
        goto LABEL_10;
    }
LABEL_9:
    v6 = 0;
  }
LABEL_10:
  sub_4E0C40((_DWORD *)this[17], v6);
  for ( i = this[16]; i; i = sub_4CD340() )
    (*(void (__thiscall **)(int))(*(_DWORD *)i + 48))(i);
  return 0;
}
