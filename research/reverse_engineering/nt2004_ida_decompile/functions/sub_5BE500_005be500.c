char __fastcall sub_5BE500(_BYTE *a1, int a2, int a3)
{
  char result; // al
  int i; // eax
  int v7; // edi
  unsigned __int8 v8; // al
  char v9; // cl
  _BYTE *v10; // eax
  char v11; // al
  char v12; // dl
  unsigned __int8 v13; // cl
  int v14; // [esp+8h] [ebp-Ch] BYREF
  int v15; // [esp+Ch] [ebp-8h] BYREF
  int v16; // [esp+10h] [ebp-4h]

  if ( !(_BYTE)a3 )
    return sub_5BE4C0(a1);
  for ( i = 0; i < 256; ++i )
    a1[i] = i;
  v15 = 0;
  LOBYTE(v14) = 0;
  v7 = 255;
  do
  {
    v8 = sub_5BE5C0(a2, a3, &v14, &v15);
    v9 = a1[v7];
    LOBYTE(v16) = v8;
    v10 = &a1[v8];
    a1[v7--] = *v10;
    *v10 = v9;
  }
  while ( v7 >= 0 );
  v11 = a1[1];
  v12 = a1[5];
  a1[257] = a1[3];
  v13 = v14;
  a1[256] = v11;
  result = a1[7];
  a1[258] = v12;
  a1[259] = result;
  a1[260] = a1[v13];
  return result;
}
