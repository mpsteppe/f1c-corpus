int __thiscall sub_61C150(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // edi
  int result; // eax
  int v6; // ecx
  int v7; // esi
  int v8; // ebp
  int *v9; // ebx
  int v10; // edx
  double v11; // st7
  unsigned __int8 *v12; // edx
  int v13; // esi
  int v14; // edi
  int v15; // ebx
  int v16; // edx
  char v17; // bl
  int v18; // edx
  int v19; // esi
  int v20; // ebx
  double v21; // st7
  bool v22; // cc
  int i; // edi
  int v24; // eax
  int v25; // ebp
  char v26; // bl
  int v27; // edx
  int v28; // ebx
  int v29; // [esp+10h] [ebp-14h]
  int v30; // [esp+10h] [ebp-14h]
  int v31; // [esp+14h] [ebp-10h]
  int v33; // [esp+1Ch] [ebp-8h]
  int *v34; // [esp+20h] [ebp-4h]

  v4 = a4;
  result = 0;
  v6 = a3;
  v31 = 0;
  if ( a4 > 0 )
  {
    do
    {
      v7 = *(_DWORD *)(*this + result + 4);
      v8 = *(_DWORD *)(a2 + 4 * v31);
      v9 = (int *)(result + *this);
      v10 = 0;
      v34 = v9;
      v33 = v7;
      if ( *(_BYTE *)(v7 + 1) )
      {
        do
        {
          v29 = *(unsigned __int8 *)(*(_DWORD *)(v7 + 4) + v10++);
          v7 = v33;
          *(double *)(result + v8) = *(double *)(result + v8)
                                   - *(double *)(*(_DWORD *)(a2 + 4 * v29) + result) * *(double *)(v8 + 8 * v29);
        }
        while ( v10 < *(unsigned __int8 *)(v33 + 1) );
        v4 = a4;
      }
      v11 = 1.0 / *(double *)(result + v8);
      v30 = 1;
      if ( *v9 > 1 )
      {
        do
        {
          v12 = (unsigned __int8 *)(v9[1] + 8 * v30);
          v13 = *(_DWORD *)(a2 + 4 * *v12);
          v14 = 0;
          if ( v12[1] )
          {
            do
            {
              v15 = *(unsigned __int8 *)(*((_DWORD *)v12 + 1) + v14++);
              *(double *)(result + v13) = *(double *)(result + v13)
                                        - *(double *)(*(_DWORD *)(a2 + 4 * v15) + result) * *(double *)(v13 + 8 * v15);
            }
            while ( v14 < v12[1] );
            v9 = v34;
            v6 = a3;
          }
          *(double *)(v8 + 8 * *v12) = v11 * *(double *)(result + v13);
          ++v30;
        }
        while ( v30 < *v9 );
        v4 = a4;
      }
      v16 = *(_DWORD *)(*this + 8 * v4 + 4);
      v17 = *(_BYTE *)(v16 + result + 1);
      v18 = result + v16;
      v19 = 0;
      if ( v17 )
      {
        do
        {
          v20 = *(unsigned __int8 *)(*(_DWORD *)(v18 + 4) + v19++);
          *(double *)(result + v6) = *(double *)(result + v6) - *(double *)(v8 + 8 * v20) * *(double *)(v6 + 8 * v20);
        }
        while ( v19 < *(unsigned __int8 *)(v18 + 1) );
      }
      v21 = v11 * *(double *)(result + v6);
      result += 8;
      v22 = v31 + 1 < v4;
      *(double *)(result + v6 - 8) = v21;
      ++v31;
    }
    while ( v22 );
  }
  for ( i = v4 - 2; i >= 0; --i )
  {
    v24 = this[1];
    v25 = *(_DWORD *)(a2 + 4 * i);
    v26 = *(_BYTE *)(v24 + 8 * i + 1);
    result = 8 * i + v24;
    v27 = 0;
    if ( v26 )
    {
      do
      {
        v28 = *(unsigned __int8 *)(*(_DWORD *)(result + 4) + v27++);
        *(double *)(8 * i + v6) = *(double *)(8 * i + v6) - *(double *)(v25 + 8 * v28) * *(double *)(v6 + 8 * v28);
      }
      while ( v27 < *(unsigned __int8 *)(result + 1) );
    }
  }
  return result;
}
