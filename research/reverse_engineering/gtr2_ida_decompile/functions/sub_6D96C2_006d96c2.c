int __usercall sub_6D96C2@<eax>(int *a1@<eax>, _DWORD *a2@<edx>)
{
  int v2; // ebx
  int *v3; // eax
  int result; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  _WORD *i; // edi
  _DWORD *v10; // esi
  unsigned __int16 *v11; // ecx
  int v12; // esi
  int v13; // [esp+8h] [ebp-28h]
  _DWORD *v14; // [esp+8h] [ebp-28h]
  int v15; // [esp+Ch] [ebp-24h]
  int v16; // [esp+10h] [ebp-20h]
  int v17; // [esp+14h] [ebp-1Ch]
  int v18; // [esp+18h] [ebp-18h]
  int *v19; // [esp+1Ch] [ebp-14h]
  int v20; // [esp+1Ch] [ebp-14h]
  int v21; // [esp+20h] [ebp-10h]
  _WORD *v22; // [esp+20h] [ebp-10h]
  int v23; // [esp+24h] [ebp-Ch]
  int v24; // [esp+28h] [ebp-8h]
  int v25; // [esp+2Ch] [ebp-4h]
  int v26; // [esp+2Ch] [ebp-4h]

  v25 = 0;
  v16 = a1[1];
  v2 = *a1;
  v3 = (int *)a1[2];
  v13 = *v3;
  v15 = v3[1];
  v18 = v3[2];
  v24 = v3[4];
  memset(a2 + 717, 0, 0x20u);
  *(_WORD *)(v2 + 4 * a2[a2[1299] + 725] + 2) = 0;
  result = a2[1299] + 1;
  if ( result < 573 )
  {
    v19 = &a2[result + 725];
    v17 = 573 - result;
    result = 573;
    do
    {
      v5 = *v19;
      v23 = 4 * *v19;
      v6 = *(unsigned __int16 *)(v2 + 4 * *(unsigned __int16 *)(v23 + v2 + 2) + 2) + 1;
      if ( v6 > v24 )
      {
        v6 = v24;
        ++v25;
      }
      *(_WORD *)(v23 + v2 + 2) = v6;
      if ( v5 <= v16 )
      {
        ++*((_WORD *)a2 + v6 + 1434);
        v21 = 0;
        if ( v5 >= v18 )
          v21 = *(_DWORD *)(v15 + 4 * (v5 - v18));
        v7 = *(unsigned __int16 *)(v23 + v2);
        a2[1448] += v7 * (v6 + v21);
        if ( v13 )
          a2[1449] += v7 * (v21 + *(unsigned __int16 *)(v23 + v13 + 2));
      }
      ++v19;
      --v17;
    }
    while ( v17 );
    if ( v25 )
    {
      do
      {
        v8 = v24 - 1;
        for ( i = (_WORD *)a2 + v24 + 1433; !*i; --i )
          --v8;
        --*((_WORD *)a2 + v8 + 1434);
        v25 -= 2;
        *((_WORD *)a2 + v8 + 1435) += 2;
        --*((_WORD *)a2 + v24 + 1434);
      }
      while ( v25 > 0 );
      v26 = v24;
      if ( v24 )
      {
        v22 = (_WORD *)a2 + v24 + 1434;
        do
        {
          v20 = (unsigned __int16)*v22;
          if ( *v22 )
          {
            v10 = &a2[result + 725];
            do
            {
              --v10;
              --result;
              v14 = v10;
              if ( *v10 <= v16 )
              {
                v11 = (unsigned __int16 *)(v2 + 4 * *v10);
                v12 = v11[1];
                if ( v12 != v26 )
                {
                  a2[1448] += *v11 * (v26 - v12);
                  v11[1] = v26;
                }
                --v20;
                v10 = v14;
              }
            }
            while ( v20 );
          }
          --v26;
          --v22;
        }
        while ( v26 );
      }
    }
  }
  return result;
}
