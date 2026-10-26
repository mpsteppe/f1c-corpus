int __thiscall sub_48DDC0(void *this)
{
  const char *v2; // eax
  char *v3; // eax
  int i; // edx
  char Destination[61]; // [esp+8h] [ebp-C0h] BYREF
  __int16 v7; // [esp+45h] [ebp-83h]
  char v8; // [esp+47h] [ebp-81h]
  char Buffer[125]; // [esp+48h] [ebp-80h] BYREF
  __int16 v10; // [esp+C5h] [ebp-3h]
  char v11; // [esp+C7h] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x3Cu);
  v7 = 0;
  v8 = 0;
  v2 = (const char *)sub_49FB30(this);
  if ( v2 )
  {
    strncpy(Destination, v2, 0x3Fu);
    v8 = 0;
  }
  sub_49FEC0(this);
  sub_578960(&unk_7D7A0C);
  v3 = ArgList;
  if ( !ArgList )
    v3 = &byte_629120;
  sub_578A30(aVcr_2, 1, v3, 0);
  sub_578E30(0);
  for ( i = sub_578980(&unk_7D7A0C); i; i = sub_578980(&unk_7D7A0C) )
  {
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x7Cu);
    v10 = 0;
    v11 = 0;
    sub_48DD40(i, Buffer);
    if ( strlen(Buffer) )
      sub_49F730(Buffer, 0, 0, 0, 0);
    sub_5789D0(&unk_7D7A0C);
  }
  sub_49FDB0(Destination, 0);
  return sub_578960(&unk_7D7A0C);
}
