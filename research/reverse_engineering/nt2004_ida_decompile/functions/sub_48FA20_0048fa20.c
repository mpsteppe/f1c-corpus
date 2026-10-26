int sub_48FA20()
{
  int v0; // eax
  char *v1; // eax
  char *v2; // edx
  char v3; // cl
  char String[61]; // [esp+8h] [ebp-80h] BYREF
  __int16 v6; // [esp+45h] [ebp-43h]
  char v7; // [esp+47h] [ebp-41h]
  char v8[61]; // [esp+48h] [ebp-40h] BYREF
  __int16 v9; // [esp+85h] [ebp-3h]
  char v10; // [esp+87h] [ebp-1h]

  v8[0] = byte_629120;
  memset(&v8[1], 0, 0x3Cu);
  v9 = 0;
  v10 = 0;
  String[0] = byte_629120;
  memset(&String[1], 0, 0x3Cu);
  v6 = 0;
  v7 = 0;
  v0 = sub_4E7760(&unk_7D6A50);
  if ( v0 )
  {
    v1 = (char *)(v0 + 246);
    v2 = (char *)(String - v1);
    do
    {
      v3 = *v1;
      v1[(_DWORD)v2] = *v1;
      ++v1;
    }
    while ( v3 );
    strcat(v8, _strupr(String));
    sub_49EC60(v8);
  }
  return 0;
}
