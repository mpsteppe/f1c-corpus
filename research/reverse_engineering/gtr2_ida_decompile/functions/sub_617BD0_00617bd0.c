char __fastcall sub_617BD0(int a1, char a2, unsigned __int8 a3, int *a4)
{
  int *v4; // ebp
  unsigned __int8 v8; // bl
  int v9; // esi
  int v10; // edi
  int v11; // ebx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  _DWORD v15[23]; // [esp+Ch] [ebp-1E8h] BYREF
  _BYTE v16[384]; // [esp+68h] [ebp-18Ch] BYREF
  int v17; // [esp+1F0h] [ebp-4h]

  v4 = a4;
  *a4 = 0;
  sub_613B30(v15);
  v17 = 0;
  sub_614460(v15, a1, 0);
  if ( v15[1] )
  {
    v8 = a2 + 37;
    if ( v8 < 3u )
      v8 = 3;
    v9 = a3;
    v10 = v8;
    v11 = v8 / 3;
    do
    {
      v12 = sub_613CE0(v15, (int)v16, 384);
      v13 = 0;
      if ( v12 > 0 )
      {
        v14 = *v4;
        do
        {
          v14 += v9 * (char)v16[v13];
          if ( ++v9 > v10 )
            v9 -= v10;
          ++v13;
        }
        while ( v13 < v12 );
        v4 = a4;
        *a4 = v14;
      }
      v9 = (v11 + v9) % v10;
    }
    while ( v12 );
    sub_613C30((int)v15);
    v17 = -1;
    sub_614140();
    return 1;
  }
  else
  {
    v17 = -1;
    sub_614140();
    return 0;
  }
}
