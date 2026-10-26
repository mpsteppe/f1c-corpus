int __usercall sub_51941D@<eax>(_DWORD *a1@<edi>)
{
  _DWORD *v1; // ebx
  int result; // eax
  _DWORD *v3; // ecx
  int v4; // eax
  int v5; // edx
  int v6; // esi
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // ecx
  int *v10; // ecx
  int v11; // edx
  _DWORD *v12; // esi
  bool v13; // zf
  _DWORD *v14; // ecx
  int *v15; // [esp+4h] [ebp-2Ch]
  _DWORD *v16; // [esp+8h] [ebp-28h]
  _DWORD *v17; // [esp+Ch] [ebp-24h]
  int v18; // [esp+10h] [ebp-20h]
  int v19; // [esp+10h] [ebp-20h]
  int v20; // [esp+14h] [ebp-1Ch]
  _DWORD *v21; // [esp+18h] [ebp-18h]
  int *v22; // [esp+1Ch] [ebp-14h]
  int v23; // [esp+20h] [ebp-10h]
  int v24; // [esp+20h] [ebp-10h]
  int v25; // [esp+24h] [ebp-Ch]
  _DWORD *v26; // [esp+28h] [ebp-8h]
  int v27; // [esp+2Ch] [ebp-4h]

  v25 = 0;
  v1 = (_DWORD *)a1[96];
  v20 = a1[69];
  result = a1[49];
  v16 = v1;
  if ( (int)a1[8] > 0 )
  {
    v3 = (_DWORD *)(result + 12);
    v21 = (_DWORD *)(result + 12);
    v22 = v1 + 2;
    while ( 1 )
    {
      v4 = *v3 * v3[6] / a1[69];
      v17 = *(_DWORD **)(4 * v25 + v1[14]);
      v5 = *(_DWORD *)(4 * v25 + v1[15]);
      v6 = *v22;
      v7 = v4 * (v20 + 2);
      v18 = v4;
      if ( v7 > 0 )
      {
        v8 = *(_DWORD **)(4 * v25 + v1[15]);
        v23 = v7;
        do
        {
          v9 = *(_DWORD *)((char *)v8 + v6 - v5);
          *v8 = v9;
          *(_DWORD *)((char *)v8++ + (_DWORD)v17 - v5) = v9;
          --v23;
        }
        while ( v23 );
        v1 = v16;
        v4 = v18;
      }
      if ( 2 * v4 > 0 )
      {
        v26 = (_DWORD *)(v5 + 4 * v20 * v4);
        v4 = v18;
        v15 = (int *)(v6 + 4 * v18 * (v20 - 2));
        v27 = v6 - v5;
        v24 = v5 - v6;
        v19 = 2 * v18;
        v10 = v15;
        do
        {
          *(int *)((char *)v10 + v24) = *(_DWORD *)((char *)v26 + v27);
          v11 = *v10;
          v12 = v26++;
          ++v10;
          v13 = v19-- == 1;
          *v12 = v11;
        }
        while ( !v13 );
      }
      if ( v4 > 0 )
      {
        v14 = &v17[-v4];
        do
        {
          *v14++ = *v17;
          --v4;
        }
        while ( v4 );
      }
      result = ++v25;
      ++v22;
      v21 += 21;
      if ( v25 >= a1[8] )
        break;
      v3 = v21;
    }
  }
  return result;
}
