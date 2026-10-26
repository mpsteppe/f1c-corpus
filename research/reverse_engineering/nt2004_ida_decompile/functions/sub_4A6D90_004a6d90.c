int __stdcall sub_4A6D90(_DWORD *a1, int a2, signed int a3)
{
  signed int v3; // eax
  const char *v4; // eax
  int i; // esi
  int v6; // ecx
  int *v7; // eax
  int v8; // eax
  char ArgList[253]; // [esp+14h] [ebp-100h] BYREF
  __int16 v11; // [esp+111h] [ebp-3h]
  char v12; // [esp+113h] [ebp-1h]

  ArgList[0] = byte_629120;
  memset(&ArgList[1], 0, 0xFCu);
  v11 = 0;
  v12 = 0;
  v3 = 0;
  if ( a3 > 0 )
  {
    memset(ArgList, 0x20u, a3);
    v3 = a3;
  }
  ArgList[v3] = 0;
  sub_57A400(a2, aSSS_5, (char)ArgList);
  sub_57A400(a2, aS_10, (char)ArgList);
  sub_57A400(a2, aSSS_4, (char)ArgList);
  v4 = (const char *)a1[4];
  if ( !v4 )
    v4 = &byte_629120;
  if ( strcmp(v4, &byte_629120) )
    sub_57A400(a2, aSSS_4, (char)ArgList);
  for ( i = 0; i < a1[10]; ++i )
  {
    v6 = i;
    if ( i >= 0 && i < a1[10] )
    {
      v7 = (int *)a1[7];
      if ( i <= 0 )
      {
LABEL_13:
        if ( v7 )
        {
          v8 = *v7;
          goto LABEL_16;
        }
      }
      else
      {
        while ( v7 )
        {
          v7 = (int *)v7[1];
          if ( --v6 <= 0 )
            goto LABEL_13;
        }
      }
    }
    v8 = 0;
LABEL_16:
    sub_4A6D90(v8, a2, a3 + 2);
  }
  return sub_57A400(a2, aS_9, (char)ArgList);
}
