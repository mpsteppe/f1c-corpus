// f1c  0x0051c099  size=221
const void **__cdecl sub_51C099(unsigned int *a1, int a2, char **a3, int *a4)
{
  int v4; // ebx
  int v6; // eax
  int v7; // ecx
  const void **result; // eax
  int v9; // edi
  char *v10; // edx
  char *v11; // eax
  unsigned int v12; // ecx
  char v13; // al
  int v14; // eax
  unsigned int v15; // [esp+Ch] [ebp-14h]
  int v16; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]
  char *v19; // [esp+28h] [ebp+8h]
  int v21; // [esp+34h] [ebp+14h]

  v4 = *a4;
  v6 = *(_DWORD *)(a2 + 4) + a1[103];
  v7 = *(unsigned __int8 *)(v6 + 140);
  result = (const void **)*(unsigned __int8 *)(v6 + 150);
  v9 = 0;
  v16 = *a4;
  v21 = v7;
  v18 = (int)result;
  for ( i = 0; v9 < (int)a1[68]; i = v9 )
  {
    v10 = *a3;
    v11 = *(char **)(v4 + 4 * v9);
    v12 = (unsigned int)&v11[a1[23]];
    v19 = v11;
    v15 = v12;
    while ( (unsigned int)v19 < v12 )
    {
      v13 = *v10++;
      if ( v21 > 0 )
      {
        LOBYTE(v4) = v13;
        BYTE1(v4) = v13;
        v14 = v4 << 16;
        LOWORD(v14) = v4;
        v4 = v16;
        memset32(v19, v14, (unsigned int)v21 >> 2);
        memset(&v19[4 * ((unsigned int)v21 >> 2)], v14, v21 & 3);
        v9 = i;
        v12 = v15;
        v19 += v21;
      }
    }
    result = (const void **)v18;
    if ( v18 > 1 )
      result = sub_51593F(v4, v9, v4, v9 + 1, v18 - 1, a1[23]);
    v9 += v18;
    ++a3;
  }
  return result;
}
