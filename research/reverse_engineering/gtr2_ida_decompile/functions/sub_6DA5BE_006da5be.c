int __userpurge sub_6DA5BE@<eax>(int a1@<edx>, int a2@<ebx>, int a3)
{
  int v3; // edi
  int result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // esi
  int v8; // edx
  __int16 *v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  int v12; // ecx
  __int16 v13; // [esp+8h] [ebp-20h] BYREF
  char v14; // [esp+Ah] [ebp-1Eh] BYREF

  v3 = 0;
  LOWORD(result) = 0;
  v5 = 1;
  v6 = a1 - (_DWORD)&v14;
  do
  {
    v7 = *(unsigned __int16 *)((char *)&v13 + 2 * v5 + v6);
    LOWORD(v7) = result + v7;
    result = 2 * v7;
    *(&v13 + v5++) = 2 * v7;
  }
  while ( v5 <= 15 );
  if ( a3 >= 0 )
  {
    do
    {
      v8 = *(unsigned __int16 *)(a2 + 4 * v3 + 2);
      if ( *(_WORD *)(a2 + 4 * v3 + 2) )
      {
        v9 = &v13 + v8;
        v10 = (unsigned __int16)(*v9)++;
        v11 = 0;
        do
        {
          v12 = v10 & 1;
          v10 >>= 1;
          v11 = 2 * (v12 | v11);
          --v8;
        }
        while ( v8 > 0 );
        result = v11 >> 1;
        *(_WORD *)(a2 + 4 * v3) = result;
      }
      ++v3;
    }
    while ( v3 <= a3 );
  }
  return result;
}
