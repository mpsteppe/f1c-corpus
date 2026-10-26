int __userpurge sub_6D7850@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4)
{
  int v6; // edi
  int result; // eax
  unsigned __int8 **v8; // edx
  int v9; // ebx
  _BYTE *v10; // ecx
  unsigned __int8 *v11; // eax
  int v12; // esi
  bool v13; // zf
  int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned __int8 **v16; // [esp+14h] [ebp-4h]
  int v17; // [esp+20h] [ebp+8h]

  v6 = 8 * *(_DWORD *)(a2 + 28);
  v15 = v6;
  sub_6D75E0(16 * *(_DWORD *)(a2 + 28), a2, a3, *(_DWORD *)(a1 + 244), *(_DWORD *)(a1 + 28));
  result = *(_DWORD *)(a2 + 12);
  if ( result > 0 )
  {
    v8 = (unsigned __int8 **)a3;
    v9 = a4 - a3;
    v16 = (unsigned __int8 **)a3;
    v14 = a4 - a3;
    v17 = result;
    do
    {
      v10 = *(unsigned __int8 **)((char *)v8 + v9);
      v11 = *v8;
      v12 = 0;
      if ( v6 )
      {
        do
        {
          *v10++ = (v12 + v11[1] + *v11) >> 1;
          v12 ^= 1u;
          v11 += 2;
          --v6;
        }
        while ( v6 );
        v8 = v16;
        v6 = v15;
        v9 = v14;
      }
      ++v8;
      result = v17 - 1;
      v13 = v17 == 1;
      v16 = v8;
      --v17;
    }
    while ( !v13 );
  }
  return result;
}
