char __fastcall sub_40FF80(int a1, char *a2, int a3)
{
  char *v3; // ebp
  unsigned int v4; // kr04_4
  signed int v5; // ebx
  int v6; // esi
  int v7; // ebp
  signed int v8; // ecx
  char v9; // dl
  int v10; // eax
  int v11; // eax
  char v12; // cl
  char Buffer[125]; // [esp+8h] [ebp-100h] BYREF
  __int16 v16; // [esp+85h] [ebp-83h]
  char v17; // [esp+87h] [ebp-81h]
  CHAR v18; // [esp+88h] [ebp-80h]
  _BYTE v19[124]; // [esp+89h] [ebp-7Fh] BYREF
  __int16 v20; // [esp+105h] [ebp-3h]
  char i; // [esp+107h] [ebp-1h]

  v3 = a2;
  if ( a1 < 0 || !a2 || a3 <= 1 )
    return 0;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v16 = 0;
  v17 = 0;
  sprintf(Buffer, "%d", a1);
  v4 = strlen(Buffer) + 1;
  v5 = v4 - 1;
  if ( (int)(v4 - 2) / 3 > 0 )
  {
    v6 = v5 % 3;
    if ( !(v5 % 3) )
      v6 = 3;
    v18 = byte_629120;
    memset(v19, 0, sizeof(v19));
    v20 = 0;
    v7 = 0;
    v8 = 0;
    for ( i = 0; v8 < v5; ++v8 )
    {
      v9 = Buffer[v8];
      v10 = v8 + v7;
      if ( v8 + v7 == v6 )
      {
        ++v7;
        v19[v10 - 1] = 44;
        v6 += 4;
        v19[v10] = v9;
      }
      else
      {
        v19[v10 - 1] = v9;
      }
    }
    v11 = 0;
    do
    {
      v12 = v19[v11 - 1];
      Buffer[v11++] = v12;
    }
    while ( v12 );
    v3 = a2;
  }
  strcpy(v3, asc_5FC1B4);
  strcat(v3, Buffer);
  return 1;
}
