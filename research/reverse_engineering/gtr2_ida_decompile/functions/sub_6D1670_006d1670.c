int __userpurge sub_6D1670@<eax>(int *a1@<eax>, int a2@<edx>, int a3, unsigned __int8 **a4)
{
  int result; // eax
  unsigned __int8 **v5; // esi
  int v6; // ecx
  unsigned __int8 *v7; // esi
  _BYTE *v8; // ecx
  int v9; // edi
  int v10; // eax
  unsigned __int8 *v11; // esi
  unsigned __int8 *v12; // edx
  _BYTE *v13; // ecx
  int v14; // ebx
  _BYTE *v15; // ecx
  int v16; // [esp+0h] [ebp-24h]
  int v17; // [esp+4h] [ebp-20h]
  int v18; // [esp+8h] [ebp-1Ch]
  unsigned __int8 *v19; // [esp+Ch] [ebp-18h]
  int v20; // [esp+10h] [ebp-14h]
  int v21; // [esp+14h] [ebp-10h]
  int v22; // [esp+18h] [ebp-Ch]
  int v23; // [esp+1Ch] [ebp-8h]
  int v24; // [esp+2Ch] [ebp+8h]

  v18 = *a1;
  result = 0;
  v16 = *(_DWORD *)(a2 + 316);
  if ( v16 > 0 )
  {
    v5 = a4;
    v17 = *(_DWORD *)(a3 + 40) - 2;
    do
    {
      v6 = 0;
      v21 = 0;
      v19 = *v5;
      do
      {
        if ( v6 )
          v7 = v5[1];
        else
          v7 = *(v5 - 1);
        v8 = *(_BYTE **)(v18 + 4 * result);
        v20 = result + 1;
        v9 = *v7 + 3 * *v19;
        v10 = v7[1] + 3 * v19[1];
        *v8 = (4 * v9 + 8) >> 4;
        v11 = v7 + 2;
        v12 = v19 + 2;
        *++v8 = (v9 + v10 + 2 * v9 + 7) >> 4;
        v24 = v9;
        v13 = v8 + 1;
        v14 = v10;
        v23 = v10;
        if ( v17 )
        {
          v22 = v17;
          do
          {
            v10 = *v11 + 3 * *v12;
            *v13 = (3 * v14 + v24 + 8) >> 4;
            ++v11;
            ++v12;
            v15 = v13 + 1;
            v24 = v23;
            *v15 = (3 * v14 + v10 + 7) >> 4;
            v13 = v15 + 1;
            v14 = v10;
            v23 = v10;
            --v22;
          }
          while ( v22 );
        }
        v5 = a4;
        *v13 = (v10 + v24 + 2 * v10 + 8) >> 4;
        v13[1] = (4 * v10 + 7) >> 4;
        result = v20;
        v6 = ++v21;
      }
      while ( v21 < 2 );
      v5 = ++a4;
    }
    while ( v20 < v16 );
  }
  return result;
}
