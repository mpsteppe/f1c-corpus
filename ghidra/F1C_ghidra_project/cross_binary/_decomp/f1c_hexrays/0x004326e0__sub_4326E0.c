// f1c  0x004326e0  size=296
int __thiscall sub_4326E0(char **this)
{
  char *v2; // ecx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  char **v7; // esi
  char *v8; // eax
  char *v9; // esi

  sub_432180(this);
  sub_432220((char ***)this);
  sub_4326D0(this);
  v2 = (char *)dword_7CE5EC;
  if ( !dword_7CE5EC )
    v2 = &byte_5EA438;
  v3 = sub_4326A0(v2);
  sub_566650(v3);
  if ( sub_423A00(byte_5EC4C0, &byte_5EA438, byte_5EC4CC) )
  {
    if ( &byte_5EA438 )
      strcpy(byte_5EC4CC, &byte_5EA438);
    else
      byte_5EC4CC[0] = 0;
  }
  sub_566650(byte_5EC4CC);
  v4 = 0;
  while ( 1 )
  {
    v5 = v4++;
    if ( v5 < 0 || v5 >= *((_DWORD *)*this + 11) )
      break;
    v6 = *((_DWORD *)*this + 8);
    if ( v5 > 0 )
    {
      while ( v6 )
      {
        v6 = *(_DWORD *)(v6 + 4);
        if ( --v5 <= 0 )
          goto LABEL_13;
      }
      break;
    }
LABEL_13:
    if ( !v6 )
      break;
    v7 = *(char ***)v6;
    if ( !*(_DWORD *)v6 )
      break;
    v8 = *v7;
    if ( !*v7 )
      v8 = &byte_5EA438;
    if ( !sub_588410(v8, &byte_5EA438) )
    {
      v9 = *v7;
      if ( !v9 )
        v9 = &byte_5EA438;
      sub_432980(v9);
      break;
    }
  }
  sub_4326D0(this);
  return 0;
}
