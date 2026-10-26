// Address: 0x0047f0a0
// Size: 109 bytes
// Name: sub_47F0A0
// Type: int()
// Source: IDA Hex-Rays decompilation

int sub_47F0A0()
{
  const char *v0; // esi

  v0 = (const char *)sub_463C80(&unk_7CD25C);
  if ( v0 && strlen(v0) )
  {
    if ( sub_423A00(v0, byte_5EC4CC) )
      strcpy(byte_5EC4CC, v0);
    sub_488B40(byte_5EC4CC);
    return 0;
  }
  else
  {
    sub_488B40(&byte_5EA438);
    return 0;
  }
}
