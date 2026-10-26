void __usercall sub_55B4A0(int a1@<edi>)
{
  int v1; // edx
  int *v2; // ecx
  int v3; // esi
  int v4; // eax
  _DWORD *v5; // ebx
  int v6; // eax
  int v7; // ebx
  int *v8; // ecx
  int i; // esi
  int v10; // eax
  int v11; // [esp+0h] [ebp-14h]
  int v12; // [esp+4h] [ebp-10h]
  int *v13; // [esp+8h] [ebp-Ch]
  double *v14; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 420);
  v15 = 0;
  v11 = v1;
  if ( *(int *)(a1 + 100) > 0 )
  {
    v2 = (int *)(v1 + 52);
    v13 = (int *)(v1 + 52);
    do
    {
      v3 = *(v2 - 5);
      v4 = 0;
      if ( v15 <= 0 )
        goto LABEL_9;
      v5 = (_DWORD *)(v1 + 32);
      while ( v3 != *v5 )
      {
        ++v4;
        ++v5;
        if ( v4 >= v15 )
          goto LABEL_9;
      }
      v6 = *(_DWORD *)(v1 + 4 * v4 + 52);
      if ( !v6 )
      {
LABEL_9:
        v12 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
        v7 = (v3 << 9) - 512;
        v14 = dbl_5F5B68;
        v8 = (int *)v12;
        do
        {
          for ( i = 0; i < 16; ++i )
          {
            v10 = (65025 - 510 * *((unsigned __int8 *)v14 + i)) / v7;
            *v8++ = v10;
          }
          v14 += 2;
        }
        while ( (int)v14 < (int)dword_5F5C68 );
        v6 = v12;
        v1 = v11;
        v2 = v13;
      }
      ++v15;
      *v2++ = v6;
      v13 = v2;
    }
    while ( v15 < *(_DWORD *)(a1 + 100) );
  }
}
