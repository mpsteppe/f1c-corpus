void __userpurge sub_6D7990(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4)
{
  int v6; // edi
  int v7; // ecx
  unsigned __int8 **v8; // edx
  _BYTE *v9; // esi
  unsigned __int8 *v10; // eax
  int v11; // ecx
  int v12; // [esp+Ch] [ebp-18h]
  int v13; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  int v17; // [esp+20h] [ebp-4h]

  v6 = 8 * *(_DWORD *)(a2 + 28);
  v13 = v6;
  sub_6D75E0(16 * *(_DWORD *)(a2 + 28), a3, a3, *(_DWORD *)(a1 + 244), *(_DWORD *)(a1 + 28));
  v7 = 0;
  v14 = 0;
  v12 = *(_DWORD *)(a2 + 12);
  if ( v12 > 0 )
  {
    v8 = (unsigned __int8 **)a3;
    v15 = a3;
    do
    {
      v9 = *(_BYTE **)(a4 + 4 * v7);
      v10 = *v8;
      v17 = 1;
      if ( v6 )
      {
        v11 = v8[1] - v10;
        v16 = v6;
        do
        {
          *v9++ = (v10[v11] + v10[v11 + 1] + v17 + v10[1] + *v10) >> 2;
          v10 += 2;
          v17 ^= 3u;
          --v16;
        }
        while ( v16 );
        v7 = v14;
        v6 = v13;
        v8 = (unsigned __int8 **)v15;
      }
      v8 += 2;
      ++v7;
      v15 = (int)v8;
      v14 = v7;
    }
    while ( v7 < v12 );
  }
}
