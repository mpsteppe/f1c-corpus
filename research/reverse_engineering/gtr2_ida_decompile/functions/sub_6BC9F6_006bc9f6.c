int __stdcall sub_6BC9F6(_DWORD *a1, int a2)
{
  unsigned int v3; // esi
  int v5; // edx
  int *v6; // eax
  int v7; // esi
  int *v8; // eax
  int v9; // esi
  int result; // eax
  int v11; // [esp+10h] [ebp+8h]
  int v12; // [esp+14h] [ebp+Ch]

  v3 = *a1 & 0xFFFFF;
  if ( a1[1] / v3 )
  {
    v12 = 4 * v3;
    v5 = 4 * a2;
    v11 = a1[1] / v3;
    do
    {
      v6 = (int *)(v5 + a1[2]);
      v7 = *v6;
      *v6 = v6[1];
      *(_DWORD *)(a1[2] + v5 + 4) = v7;
      v5 += v12;
      --v11;
    }
    while ( v11 );
  }
  v8 = (int *)(4 * a2 + a1[4]);
  v9 = *v8;
  *v8 = v8[1];
  result = a1[4];
  *(_DWORD *)(result + 4 * a2 + 4) = v9;
  return result;
}
