int __thiscall sub_502E90(float *this)
{
  const char *v1; // esi
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  char v9; // cl
  int v10; // [esp+4h] [ebp-94h]
  int v11; // [esp+8h] [ebp-90h]
  char *Source; // [esp+Ch] [ebp-8Ch]
  char Buffer[8]; // [esp+10h] [ebp-88h] BYREF
  char Destination[127]; // [esp+18h] [ebp-80h] BYREF
  char v15; // [esp+97h] [ebp-1h]

  v1 = 0;
  if ( this[4] < 0.0 )
    return 1;
  this[4] = this[4] - dbl_7DA9C8;
  Source = 0;
  v3 = sub_57AE50(aSeasonraces);
  v4 = dword_7D6B58 + 400 * dword_7D6B54;
  if ( !v3 || !v4 || !sub_57A720((char *)(v4 + 260)) )
    goto LABEL_14;
  v5 = sub_57A720(off_612BAC);
  if ( v5 )
    v1 = (const char *)sub_57A6D0(v5);
  v6 = sub_57A720(off_612BB0);
  if ( v6 )
    Source = (char *)sub_57A6D0(v6);
  if ( v1 )
  {
    if ( sub_41F230(dword_62A170, v1, ::Destination) )
    {
      strncpy(::Destination, v1, 0x1FFu);
      byte_62A37B = 0;
    }
    strncpy(Destination, ::Destination, 0x7Fu);
    v7 = 640;
    v15 = 0;
    sub_501610((int)Destination, 640, 50, 0xFFFFFF, 2, 0, 1.0, 1.0);
  }
  else
  {
LABEL_14:
    v7 = v10;
  }
  sprintf(Buffer, "%c", byte_612BA0);
  v8 = 0;
  do
  {
    v9 = *(&byte_629120 + v8);
    Destination[v8++] = v9;
  }
  while ( v9 );
  v11 = 16;
  do
  {
    strcat(Destination, Buffer);
    --v11;
  }
  while ( v11 );
  sub_501610((int)Destination, v7, 90, 0xFFFFFF, 2, 3, 1.0, 1.0);
  if ( Source )
  {
    if ( sub_41F230(dword_62A170, Source, ::Destination) )
    {
      strncpy(::Destination, Source, 0x1FFu);
      byte_62A37B = 0;
    }
    strncpy(Destination, ::Destination, 0x7Fu);
    v15 = 0;
    sub_501610((int)Destination, 640, 130, 0xFFFFFF, 2, 0, 1.0, 1.0);
  }
  return 0;
}
