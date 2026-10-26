int sub_48FB10()
{
  int v0; // eax
  char *v1; // eax
  int v2; // edx
  char v3; // cl
  _BYTE v5[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v6; // [esp+45h] [ebp-3h]
  char v7; // [esp+47h] [ebp-1h]

  v5[0] = byte_629120;
  memset(&v5[1], 0, 0x3Cu);
  v6 = 0;
  v7 = 0;
  v0 = sub_4E7760(&unk_7D6A50);
  if ( v0 )
  {
    v1 = (char *)(v0 + 182);
    v2 = v5 - v1;
    do
    {
      v3 = *v1;
      v1[v2] = *v1;
      ++v1;
    }
    while ( v3 );
    sub_49EC60(v5);
  }
  return 0;
}
