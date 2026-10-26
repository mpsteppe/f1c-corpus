int __usercall sub_51D6D2@<eax>(int *a1@<eax>, int a2@<esi>, int a3)
{
  int v3; // ebx
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int result; // eax
  int v11; // [esp+Ch] [ebp-3Ch]
  int v12; // [esp+10h] [ebp-38h]
  int v13; // [esp+14h] [ebp-34h]
  int v14; // [esp+20h] [ebp-28h]
  int v15; // [esp+24h] [ebp-24h]
  int v16; // [esp+28h] [ebp-20h]
  int v17; // [esp+2Ch] [ebp-1Ch]
  int v18; // [esp+30h] [ebp-18h]
  int v19; // [esp+34h] [ebp-14h]
  int v20; // [esp+38h] [ebp-10h]
  int v21; // [esp+3Ch] [ebp-Ch]
  int v22; // [esp+40h] [ebp-8h]
  unsigned __int16 *v23; // [esp+44h] [ebp-4h]

  v18 = 0;
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v3 = a1[5];
  v11 = a1[1];
  v4 = a1[2];
  v14 = a1[3];
  v5 = a1[4];
  v6 = *a1;
  v7 = a3;
  if ( v6 <= v11 )
  {
    v19 = 8 * v6 + 4;
    do
    {
      if ( v4 <= v14 )
      {
        v20 = 4 * v4 + 2;
        v21 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 420) + 24) + 4 * v6) + 2 * (v5 + 32 * v4);
        v8 = v14 - v4 + 1;
        v12 = v8;
        do
        {
          v23 = (unsigned __int16 *)v21;
          if ( v5 <= v3 )
          {
            v22 = 8 * v5 + 4;
            v13 = v3 - v5 + 1;
            do
            {
              v9 = *v23++;
              if ( v9 )
              {
                v18 += v9;
                v16 += v9 * v20;
                v17 += v9 * v19;
                v15 += v9 * v22;
              }
              v22 += 8;
              --v13;
            }
            while ( v13 );
            v8 = v12;
          }
          v21 += 64;
          v20 += 4;
          v12 = --v8;
        }
        while ( v8 );
        v7 = a3;
      }
      v19 += 8;
      ++v6;
    }
    while ( v6 <= v11 );
  }
  *(_BYTE *)(v7 + **(_DWORD **)(a2 + 116)) = ((v18 >> 1) + v17) / v18;
  *(_BYTE *)(v7 + *(_DWORD *)(*(_DWORD *)(a2 + 116) + 4)) = ((v18 >> 1) + v16) / v18;
  result = ((v18 >> 1) + v15) / v18;
  *(_BYTE *)(v7 + *(_DWORD *)(*(_DWORD *)(a2 + 116) + 8)) = result;
  return result;
}

