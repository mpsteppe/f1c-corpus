int sub_4929D0()
{
  int v0; // eax
  unsigned int v1; // kr04_4
  char v2; // dl
  char v4[28]; // [esp+4h] [ebp-9Ch] BYREF
  char Buffer[125]; // [esp+20h] [ebp-80h] BYREF
  __int16 v6; // [esp+9Dh] [ebp-3h]
  char v7; // [esp+9Fh] [ebp-1h]

  sub_57A080(v4);
  if ( (unsigned __int8)sub_57A2F0(aNt03Ver, 1) )
  {
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x7Cu);
    v6 = 0;
    v7 = 0;
    sub_57A490(Buffer, 127);
    v0 = 0;
    v1 = strlen(Buffer) + 1;
    if ( (int)(v1 - 1) > 0 )
    {
      while ( 1 )
      {
        v2 = Buffer[v0];
        if ( v2 == 10 || v2 == 13 )
          break;
        if ( ++v0 >= (int)(v1 - 1) )
          goto LABEL_8;
      }
      Buffer[v0] = 0;
    }
LABEL_8:
    sub_49EC60(Buffer);
    sub_57A360(v4);
    sub_57A0A0(v4);
    return 0;
  }
  else
  {
    sub_49EC60(&byte_629120);
    sub_57A0A0(v4);
    return 1;
  }
}
