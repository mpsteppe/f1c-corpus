int __usercall sub_6CE040@<eax>(_DWORD *a1@<eax>)
{
  int v1; // ecx
  int v2; // edx
  int v3; // ebx
  int result; // eax
  _DWORD **v5; // edi
  _DWORD *v6; // ebx
  int v7; // esi
  int v8; // eax
  int v9; // edx
  _DWORD *v10; // esi
  _DWORD *v11; // edx
  _DWORD *v12; // edi
  int v13; // ecx
  _DWORD *v14; // eax
  int v15; // ecx
  bool v16; // zf
  int v17; // [esp+4h] [ebp-1Ch]
  _DWORD *v18; // [esp+8h] [ebp-18h]
  int v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  _DWORD *v21; // [esp+14h] [ebp-Ch]
  _DWORD **v22; // [esp+18h] [ebp-8h]
  int v23; // [esp+1Ch] [ebp-4h]
  int v24; // [esp+1Ch] [ebp-4h]

  v1 = a1[80];
  v2 = a1[107];
  v3 = a1[55];
  result = a1[9];
  v17 = v1;
  if ( result > 0 )
  {
    v5 = *(_DWORD ***)(v2 + 60);
    v6 = (_DWORD *)(v3 + 12);
    v7 = *(_DWORD *)(v2 + 56) - (_DWORD)v5;
    v21 = v6;
    v22 = v5;
    v19 = v7;
    v20 = result;
    while ( 1 )
    {
      v8 = *v6 * v6[6] / v1;
      v9 = *(int *)((char *)v5 + v7);
      v10 = *v5;
      v23 = v9;
      if ( v8 > 0 )
      {
        v18 = &v10[v8 * (v1 + 2)];
        v11 = &v10[-v8];
        v12 = &v10[v8 * (v1 + 1)];
        v13 = v23;
        v24 = v8;
        v14 = v18;
        v15 = v13 - (_DWORD)v10;
        do
        {
          *(_DWORD *)((char *)v11 + v15) = *(_DWORD *)((char *)v12 + v15);
          *v11 = *v12;
          *(_DWORD *)((char *)v14 + v15) = *(_DWORD *)((char *)v10 + v15);
          *v14 = *v10;
          ++v12;
          ++v11;
          ++v10;
          ++v14;
          --v24;
        }
        while ( v24 );
        v1 = v17;
        v6 = v21;
        v5 = v22;
      }
      ++v5;
      v6 += 21;
      result = v20 - 1;
      v16 = v20 == 1;
      v22 = v5;
      v21 = v6;
      --v20;
      if ( v16 )
        break;
      v7 = v19;
    }
  }
  return result;
}
