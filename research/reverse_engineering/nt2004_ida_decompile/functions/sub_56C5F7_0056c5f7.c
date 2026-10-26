// positive sp value has been detected, the output may be wrong!
char __userpurge sub_56C5F7@<al>(char *a1@<eax>, char a2@<dh>, int a3@<ebx>, char a4, int a5)
{
  char *v5; // edx
  char v6; // cl
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char v12; // bl
  char *v13; // eax
  char v15; // [esp-69h] [ebp-69h]
  char v16[8]; // [esp-68h] [ebp-68h] BYREF
  char v17[32]; // [esp-60h] [ebp-60h] BYREF
  char v18[64]; // [esp-40h] [ebp-40h] BYREF
  char v19; // [esp+4h] [ebp+4h]

  *(a1 - 80407) += a2;
  ++*(_DWORD *)(a3 + 1149988076);
  LOBYTE(a1) = (unsigned __int8)a1 & 0x70;
  v18[0] = 0;
  v5 = (char *)(v18 - a1);
  do
  {
    v6 = *a1;
    a1[(_DWORD)v5] = *a1;
    ++a1;
  }
  while ( v6 );
  v7 = strtok(v18, asc_5FE040);
  if ( !v7 )
    return 0;
  v17[0] = 0;
  strncpy(v17, v7, 0x1Fu);
  v17[31] = 0;
  v8 = strtok(0, asc_5FE040);
  if ( !v8 )
    return 0;
  v16[0] = 0;
  strncpy(v16, v8, 7u);
  v16[7] = 0;
  v9 = strtok(v17, word_5FC804);
  if ( !v9 )
    return 0;
  v19 = atol(v9);
  v10 = strtok(0, word_5FC804);
  if ( !v10 )
    return 0;
  v15 = atol(v10);
  v11 = strtok(0, word_5FC804);
  if ( !v11 )
    return 0;
  v12 = atol(v11);
  v13 = strtok(0, word_5FC804);
  if ( !v13 )
    return 0;
  *(_BYTE *)(a5 + 7) = atol(v13);
  *(_BYTE *)(a5 + 4) = v19;
  *(_BYTE *)(a5 + 5) = v15;
  *(_BYTE *)(a5 + 6) = v12;
  *(_WORD *)(a5 + 2) = atol(v16);
  return 1;
}
