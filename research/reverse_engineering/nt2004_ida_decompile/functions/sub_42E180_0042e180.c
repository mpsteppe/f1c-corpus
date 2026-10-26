int __thiscall sub_42E180(_DWORD *this)
{
  int v2; // esi
  int v3; // edx
  int *v4; // eax
  int v5; // edx
  bool v6; // bl
  CHAR *v7; // eax
  int v8; // edi
  int v9; // esi
  char *v10; // ecx
  signed int i; // esi
  int result; // eax
  char v13; // [esp+0h] [ebp-10h]
  _BYTE v14[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_3, 785) )
    sub_500FE0((int)&unk_7D7920, aEnteredDynmanI, v13);
  sub_416E90(dword_6291D0);
  *this = 0;
  v2 = *(_DWORD *)dword_7689CC;
  v3 = 0;
  v4 = &dword_630030;
  while ( 1 )
  {
    if ( v2 != 4 && v2 != 8 )
      v4[1073] = v3 + 1;
    if ( !*v4 )
      break;
    v4 += 6326;
    ++v3;
    if ( (int)v4 >= (int)dword_7588B0 )
      goto LABEL_11;
  }
  sub_42DB60(v3);
  sub_42DC00(v5);
LABEL_11:
  if ( v3 == 48 && dword_7D5DA4 != 2 )
  {
    sub_42DB60(0);
    sub_42DC00(0);
  }
  v6 = dword_75CBB0 == 1 || dword_75CBB0 == 2 || dword_75CBB0 == 3 || dword_75CBB0 == 4;
  sub_4E29B0(v14);
  if ( byte_75AB9C )
  {
    if ( v2 == 4 )
    {
      if ( v6 )
        sub_4E2FD0(v14);
      sub_4E3090(v14);
    }
  }
  else
  {
    v7 = *(CHAR **)&dword_769638[28 * *(_DWORD *)dword_7689CC];
    if ( !v7 )
      v7 = &byte_629120;
    sub_4E2AD0((char)v7);
    if ( *(_DWORD *)dword_7689CC != 3 || dword_766CBC == 2 )
      sub_4E2DB0(v14);
    else
      sub_4E2FD0(v14);
  }
  sub_42DC40();
  v8 = 0;
  if ( dword_5FD344 > 0 )
  {
    v9 = 0;
    do
    {
      v10 = (char *)off_5FD348 + v9;
      dword_75AB90[v8] = (int)off_5FD348 + v9;
      sub_4EE0B0(v10, 1);
      *(_DWORD *)((char *)off_5FD348 + v9 + 25264) = 43;
      *(_DWORD *)((char *)off_5FD348 + v9 + 25300) = 1;
      ++v8;
      v9 += 25304;
    }
    while ( v8 < dword_5FD344 );
  }
  for ( i = 0; i < (int)NumOfElements; ++i )
    sub_4EE0B0((void *)dword_75AAD0[i], 1);
  sub_435480(&unk_75E8E8);
  result = dword_75AAC8;
  if ( (unsigned int)dword_75AAC8 < 0x30 && !*(_DWORD *)(dword_75AAD0[dword_75AAC8] + 16584) )
    result = sub_436470(dword_75AAC8);
  if ( dword_75ABA0 == 1 )
    dword_75ABA0 = 2;
  return result;
}
