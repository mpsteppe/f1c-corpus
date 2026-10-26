// positive sp value has been detected, the output may be wrong!
int __usercall sub_48C0D7@<eax>(char a1@<al>, char a2@<dl>, int a3@<ecx>)
{
  CHAR *v4; // eax
  int v5; // eax
  char *v6; // edx
  char v7; // cl
  char *v8; // eax
  const char *v9; // eax
  char v11[253]; // [esp-F8h] [ebp-100h] BYREF
  __int16 v12; // [esp+5h] [ebp-3h]
  char v13; // [esp+7h] [ebp-1h]

  *(_BYTE *)(a3 + 1431502946) &= a2;
  v11[0] = a1;
  memset(&v11[1], 0, 0xFCu);
  v12 = 0;
  v13 = 0;
  v4 = dword_766594;
  if ( !dword_766594 )
    v4 = &byte_629120;
  sub_4E8C80(v4);
  v5 = 400 * dword_7D6B54 + dword_7D6B58 + 4;
  v6 = &v11[-v5];
  do
  {
    v7 = *(_BYTE *)v5;
    v6[v5] = *(_BYTE *)v5;
    ++v5;
  }
  while ( v7 );
  v8 = &v11[strlen(v11)];
  if ( v8 > v11 )
  {
    while ( *v8 != 46 )
    {
      if ( --v8 <= v11 )
        goto LABEL_10;
    }
    *v8 = 0;
  }
LABEL_10:
  v9 = *(const char **)(a3 + 168);
  if ( !v9 )
    v9 = &byte_629120;
  strcat(v11, v9);
  sub_578600(v11);
  return 0;
}
