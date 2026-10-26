int __stdcall sub_6B4780(int *a1)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // ebx
  _DWORD *v14; // edi
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int result; // eax
  int v19; // [esp-8h] [ebp-Ch]
  int v20; // [esp-8h] [ebp-Ch]
  int v21; // [esp-8h] [ebp-Ch]
  int v22; // [esp+Ch] [ebp+8h]

  v2 = a1[5];
  if ( v2 != 202 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 20;
    *(_DWORD *)(v3 + 24) = v2;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  v4 = a1[12];
  v5 = a1[13];
  if ( 8 * v4 > v5 )
  {
    if ( 4 * v4 > v5 )
    {
      if ( 2 * v4 > v5 )
      {
        v7 = a1[8];
        a1[28] = a1[7];
        a1[80] = 8;
      }
      else
      {
        v9 = sub_6B5FB0(a1[7], 2);
        v21 = a1[8];
        a1[28] = v9;
        v7 = sub_6B5FB0(v21, 2);
        a1[80] = 4;
      }
    }
    else
    {
      v8 = sub_6B5FB0(a1[7], 4);
      v20 = a1[8];
      a1[28] = v8;
      v7 = sub_6B5FB0(v20, 4);
      a1[80] = 2;
    }
  }
  else
  {
    v6 = sub_6B5FB0(a1[7], 8);
    v19 = a1[8];
    a1[28] = v6;
    v7 = sub_6B5FB0(v19, 8);
    a1[80] = 1;
  }
  v10 = (_DWORD *)a1[55];
  a1[29] = v7;
  if ( a1[9] > 0 )
  {
    v10 += 3;
    v22 = a1[9];
    do
    {
      v11 = a1[80];
      if ( v11 < 8 )
      {
        v12 = v11 * a1[78];
        do
        {
          if ( 2 * v11 * *(v10 - 1) > v12 )
            break;
          if ( 2 * v11 * *v10 > a1[80] * a1[79] )
            break;
          v11 *= 2;
        }
        while ( v11 < 8 );
      }
      v10[6] = v11;
      v10 += 21;
      --v22;
    }
    while ( v22 );
  }
  v13 = 0;
  if ( a1[9] > 0 )
  {
    v14 = (_DWORD *)(a1[55] + 36);
    do
    {
      v15 = sub_6B5FB0(a1[7] * *v14 * *(v14 - 7), 8 * a1[78]);
      v16 = a1[79];
      v14[1] = v15;
      v14[2] = sub_6B5FB0(*v14 * a1[8] * *(v14 - 6), 8 * v16);
      ++v13;
      v14 += 21;
    }
    while ( v13 < a1[9] );
  }
  switch ( a1[11] )
  {
    case 1:
      a1[30] = 1;
      break;
    case 2:
    case 3:
      a1[30] = 3;
      break;
    case 4:
    case 5:
      a1[30] = 4;
      break;
    default:
      v10 = (_DWORD *)a1[9];
      a1[30] = (int)v10;
      break;
  }
  v17 = 1;
  if ( !a1[21] )
    v17 = a1[30];
  a1[31] = v17;
  result = sub_6B4700((int)v10, a1);
  if ( result )
    a1[32] = a1[79];
  else
    a1[32] = 1;
  return result;
}
