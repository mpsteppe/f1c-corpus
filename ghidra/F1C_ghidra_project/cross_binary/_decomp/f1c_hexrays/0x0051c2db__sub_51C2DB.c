// f1c  0x0051c2db  size=263
unsigned __int8 **__cdecl sub_51C2DB(unsigned __int8 **a1, int a2, unsigned __int8 **a3, int *a4)
{
  unsigned __int8 **result; // eax
  unsigned __int8 *v5; // edx
  unsigned __int8 *v6; // edi
  _BYTE *v7; // esi
  int v8; // ecx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // edx
  int v11; // eax
  unsigned __int8 *v12; // edi
  unsigned __int8 *v13; // edx
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  bool v16; // zf
  int v17; // [esp+0h] [ebp-14h]
  int v18; // [esp+4h] [ebp-10h]
  unsigned __int8 **v19; // [esp+8h] [ebp-Ch]
  int v20; // [esp+Ch] [ebp-8h]
  int v21; // [esp+10h] [ebp-4h]
  int v22; // [esp+28h] [ebp+14h]

  v21 = 0;
  v17 = *a4;
  result = a1;
  if ( (int)a1[68] > 0 )
  {
    result = a3;
    v19 = a3;
    do
    {
      v22 = 0;
      do
      {
        v5 = *result;
        if ( v22 )
          v6 = result[1];
        else
          v6 = *(result - 1);
        v7 = *(_BYTE **)(v17 + 4 * v21++);
        v8 = *v6 + 3 * *v5;
        v9 = v6 + 1;
        v10 = v5 + 1;
        v11 = *v9 + 3 * *v10;
        *v7 = (4 * v8 + 8) >> 4;
        v12 = v9 + 1;
        v13 = v10 + 1;
        *++v7 = (v8 + v11 + 2 * v8 + 7) >> 4;
        v14 = v7 + 1;
        v20 = v11;
        if ( *(_DWORD *)(a2 + 40) != 2 )
        {
          v18 = *(_DWORD *)(a2 + 40) - 2;
          do
          {
            v11 = *v12 + 3 * *v13;
            *v14 = (3 * v20 + v8 + 8) >> 4;
            ++v12;
            ++v13;
            v15 = v14 + 1;
            *v15 = (3 * v20 + v11 + 7) >> 4;
            v8 = v20;
            v14 = v15 + 1;
            v16 = v18-- == 1;
            v20 = v11;
          }
          while ( !v16 );
        }
        ++v22;
        *v14 = (v11 + v8 + 2 * v11 + 8) >> 4;
        v14[1] = (4 * v11 + 7) >> 4;
        result = v19;
      }
      while ( v22 < 2 );
      result = ++v19;
    }
    while ( v21 < (int)a1[68] );
  }
  return result;
}
