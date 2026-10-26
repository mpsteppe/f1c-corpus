int __fastcall sub_564C70(int a1, int a2, int a3, int a4)
{
  int v5; // eax
  char *v6; // ecx
  int v7; // esi
  char *v8; // edi
  int v9; // ebp
  int result; // eax
  int v11; // esi
  int v12; // edi
  int v13; // ebx
  int v15; // [esp+10h] [ebp-110h]
  unsigned __int8 v16; // [esp+14h] [ebp-10Ch]
  char v17[256]; // [esp+20h] [ebp-100h] BYREF

  v5 = 0;
  v6 = v17;
  do
    *v6++ = v5++;
  while ( (__int16)v5 < 256 );
  v16 = 0;
  LOBYTE(v7) = 0;
  v8 = v17;
  v9 = 256;
  do
  {
    v7 = (unsigned __int8)(*(_BYTE *)(v16 + a1) + v7 + *v8);
    v16 = (v16 + 1) % a2;
    sub_5622B0(v8++, &v17[v7]);
    --v9;
  }
  while ( v9 );
  result = a4;
  v11 = 0;
  v15 = 0;
  if ( a4 > 0 )
  {
    LOBYTE(v12) = 0;
    LOBYTE(v13) = 0;
    do
    {
      v12 = (unsigned __int8)(*(_BYTE *)(v11 + a3) + v12 + 1);
      v13 = (unsigned __int8)(v13 + v17[v12]);
      sub_5622B0(&v17[v12], &v17[v13]);
      *(_BYTE *)(v11 + a3) ^= v17[(unsigned __int8)(v17[v13] + v17[v12])];
      v11 = (__int16)++v15;
      result = a4;
    }
    while ( (__int16)v15 < a4 );
  }
  return result;
}
