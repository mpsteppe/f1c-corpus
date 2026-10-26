int __fastcall sub_5B9C60(int *a1, int a2, int a3, int a4, int a5, int a6, u_long hostlong, int a8)
{
  int v9; // esi
  int v10; // ebx
  int v11; // edx
  int result; // eax
  char Buffer[253]; // [esp+14h] [ebp-100h] BYREF
  __int16 v15; // [esp+111h] [ebp-3h]
  char v16; // [esp+113h] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v9 = 0;
  v15 = 0;
  v16 = 0;
  v10 = 0;
  a1[386] = a3;
  for ( a1[15] = 0; v9 < a5; ++v9 )
  {
    if ( (int)(strlen(*((const char **)&off_624B98 + *(unsigned __int8 *)(v9 + a4))) + 1 + v10) >= 256 )
      break;
    v10 += sprintf(&Buffer[v10], off_6248F0, *((_DWORD *)&off_624B98 + *(unsigned __int8 *)(v9 + a4)));
    LOBYTE(v11) = *(_BYTE *)(v9 + a4);
    sub_5BC0E0(a1, v11);
  }
  result = sub_5BC220(a6, hostlong, a8);
  if ( !result && !a2 )
  {
    while ( a1[18] == 3 || a1[4] > 0 && !result )
    {
      sub_5BDB80(0xAu);
      result = sub_5B9F20(a1);
    }
  }
  return result;
}
