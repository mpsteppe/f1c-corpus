void __userpurge sub_6D75E0(int a1@<ecx>, int a2@<ebx>, int a3, int a4, int a5)
{
  int v5; // ecx
  int v6; // esi
  char *v7; // edi
  char v8; // dl
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+0h] [ebp-4h]

  v5 = a1 - a5;
  v11 = v5;
  if ( v5 > 0 )
  {
    v6 = 0;
    if ( a4 > 0 )
    {
      while ( 1 )
      {
        v7 = (char *)(a5 + *(_DWORD *)(a3 + 4 * v6));
        LOBYTE(a2) = *(v7 - 1);
        BYTE1(a2) = a2;
        v8 = v5;
        v9 = (unsigned int)v5 >> 2;
        v10 = a2 << 16;
        LOWORD(v10) = a2;
        memset32(v7, v10, v9);
        memset(&v7[4 * v9], a2, v8 & 3);
        if ( ++v6 >= a4 )
          break;
        v5 = v11;
      }
    }
  }
}
