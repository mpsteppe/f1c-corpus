int sub_4D59B0()
{
  int v0; // esi
  int v1; // edx
  char v2; // cl
  int v3; // eax
  int v4; // eax
  int v5; // edx
  char v6; // cl
  int v7; // esi
  char v8; // cl
  char v10; // [esp+Fh] [ebp-9h] BYREF
  float v11; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h] BYREF

  v10 = 4;
  sub_4D5BE0(&v10, 1);
  v0 = 0;
  v1 = 0;
  v2 = 0;
  do
  {
    v3 = (unsigned __int8)byte_7C749A[v1];
    if ( v1 == 5 && !dword_7CEA5C )
      v3 = 1;
    v4 = v3 << v2;
    v2 += 2;
    v0 += v4;
    ++v1;
  }
  while ( v1 < 11 );
  v5 = dword_7CE6D0 << v2;
  v6 = v2 + 2;
  v7 = (dword_7CE958 << v6) + v5 + v0;
  v12 = v7;
  v8 = v6 + 1;
  if ( *(_DWORD *)(dword_7C54E8 + 4180) == 1 )
    v7 += 1 << v8;
  v12 = ((unsigned __int8)byte_7CE88C << (v8 + 2)) + ((unsigned __int8)byte_7CE874 << (v8 + 1)) + v7;
  sub_4D5BE0(&v12, 4);
  v11 = flt_8AFEE4;
  sub_4D5BE0(&v11, 4);
  v11 = flt_8AFEE8;
  sub_4D5BE0(&v11, 4);
  v11 = flt_8AFEEC;
  sub_4D5BE0(&v11, 4);
  v11 = flt_8AFEF0 + 273.16;
  sub_4D5BE0(&v11, 4);
  v11 = flt_8AFEF4 + 273.16;
  return sub_4D5BE0(&v11, 4);
}
