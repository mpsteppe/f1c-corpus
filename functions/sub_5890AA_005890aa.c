void __cdecl sub_5890AA(unsigned int a1, unsigned int a2, unsigned int a3, int (__cdecl *a4)(int))
{
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int i; // edi
  int v8; // eax
  unsigned int v9; // eax
  unsigned int *v10; // edx
  unsigned int *v11; // ecx
  unsigned int *v12; // ecx
  unsigned int *v13; // eax
  char v14; // [esp+Ch] [ebp-F8h] BYREF
  char v15; // [esp+84h] [ebp-80h] BYREF
  unsigned int v16; // [esp+FCh] [ebp-8h]
  int v17; // [esp+100h] [ebp-4h]
  unsigned int *v18; // [esp+10Ch] [ebp+8h]
  unsigned int *v19; // [esp+110h] [ebp+Ch]

  if ( a2 >= 2 && a3 )
  {
    v17 = 0;
    v18 = (unsigned int *)&v15;
    v5 = a1 + a3 * (a2 - 1);
    v19 = (unsigned int *)&v14;
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = (v5 - a1) / a3 + 1;
        if ( v6 <= 8 )
        {
          sub_5891FE(a1, v5, a3, a4);
          goto LABEL_6;
        }
        ByteBufferSwap(a1 + a3 * (v6 >> 1), a1, a3);
        v16 = a1;
        for ( i = v5 + a3; ; ByteBufferSwap(v16, i, a3) )
        {
          do
          {
            v8 = a3 + v16;
            v16 += a3;
          }
          while ( v16 <= v5 && a4(v8) <= 0 );
          do
            i -= a3;
          while ( i > a1 && a4(i) >= 0 );
          if ( i < v16 )
            break;
        }
        ByteBufferSwap(a1, i, a3);
        v9 = v16;
        if ( (int)(i - a1 - 1) >= (int)(v5 - v16) )
          break;
        if ( v16 < v5 )
        {
          v12 = v19;
          ++v17;
          ++v19;
          *v12 = v16;
          v13 = v18++;
          *v13 = v5;
        }
        if ( a1 + a3 >= i )
        {
LABEL_6:
          --v17;
          --v19;
          --v18;
          if ( v17 < 0 )
            return;
          a1 = *v19;
          v5 = *v18;
        }
        else
        {
          v5 = i - a3;
        }
      }
      if ( a1 + a3 < i )
      {
        v10 = v19++;
        v11 = v18;
        ++v17;
        ++v18;
        *v10 = a1;
        *v11 = i - a3;
      }
      if ( v9 >= v5 )
        goto LABEL_6;
      a1 = v9;
    }
  }
}
