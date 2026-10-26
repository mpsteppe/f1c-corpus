_BYTE ***__userpurge sub_6D1320@<eax>(_BYTE ***result@<eax>, int a2@<edx>, int a3@<ecx>, int a4)
{
  int v4; // ecx
  _BYTE **v5; // edi
  int v6; // eax
  unsigned __int8 *v7; // ecx
  int v8; // edx
  int v9; // esi
  _BYTE *v10; // eax
  unsigned __int8 *v11; // ecx
  int v12; // edx
  _BYTE *v13; // eax
  int v14; // edi
  int v15; // ebx
  _BYTE *v16; // eax
  int v17; // edx
  bool v18; // zf
  int v19; // [esp+4h] [ebp-Ch]
  int v20; // [esp+8h] [ebp-8h]
  _BYTE **v21; // [esp+Ch] [ebp-4h]
  int v22; // [esp+18h] [ebp+8h]

  v4 = *(_DWORD *)(a3 + 316);
  v5 = *result;
  if ( v4 > 0 )
  {
    v19 = *(_DWORD *)(a2 + 40) - 2;
    v6 = a4 - (_DWORD)v5;
    v21 = v5;
    v20 = a4 - (_DWORD)v5;
    v22 = v4;
    while ( 1 )
    {
      v7 = *(_BYTE **)((char *)v5 + v6);
      v8 = *v7;
      v9 = v7[1];
      v10 = *v5;
      v11 = v7 + 1;
      *v10++ = v8;
      *v10 = (v8 + v9 + 2 * v8 + 2) >> 2;
      v12 = v19;
      v13 = v10 + 1;
      if ( v19 )
      {
        do
        {
          ++v11;
          v14 = 3 * v9;
          v15 = *(v11 - 2) + 3 * v9 + 1;
          v9 = *v11;
          *v13 = v15 >> 2;
          v16 = v13 + 1;
          *v16 = (v9 + v14 + 2) >> 2;
          v13 = v16 + 1;
          --v12;
        }
        while ( v12 );
        v5 = v21;
      }
      v17 = *v11;
      *v13 = (*(v11 - 1) + 3 * v17 + 1) >> 2;
      v13[1] = v17;
      ++v5;
      result = (_BYTE ***)(v22 - 1);
      v18 = v22 == 1;
      v21 = v5;
      --v22;
      if ( v18 )
        break;
      v6 = v20;
    }
  }
  return result;
}
