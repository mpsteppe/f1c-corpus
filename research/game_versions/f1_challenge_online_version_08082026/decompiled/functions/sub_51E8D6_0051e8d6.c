char __cdecl sub_51E8D6(_DWORD *a1, int a2, void **a3, int a4)
{
  int v4; // ebx
  int v5; // eax
  int v7; // esi
  unsigned __int8 *v8; // edi
  _BYTE *v9; // esi
  _WORD *v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edx
  bool v14; // zf
  int v16; // [esp+8h] [ebp-40h]
  int v17; // [esp+10h] [ebp-38h]
  int v18; // [esp+14h] [ebp-34h]
  int v19; // [esp+18h] [ebp-30h]
  int v20; // [esp+1Ch] [ebp-2Ch]
  _DWORD *v21; // [esp+20h] [ebp-28h]
  int v22; // [esp+24h] [ebp-24h]
  unsigned int v23; // [esp+28h] [ebp-20h]
  int v24; // [esp+2Ch] [ebp-1Ch]
  __int16 v25; // [esp+30h] [ebp-18h]
  __int16 v26; // [esp+34h] [ebp-14h]
  int v27; // [esp+38h] [ebp-10h]
  unsigned int v28; // [esp+3Ch] [ebp-Ch]
  _DWORD *v29; // [esp+40h] [ebp-8h]
  int v30; // [esp+44h] [ebp-4h]
  int v31; // [esp+50h] [ebp+8h]
  void **v32; // [esp+5Ch] [ebp+14h]

  v30 = a1[25];
  v4 = a1[105];
  v5 = a1[71];
  v28 = a1[23];
  v16 = v4;
  v20 = v5;
  if ( a4 > 0 )
  {
    v7 = a2 - (_DWORD)a3;
    v32 = a3;
    v22 = a4;
    do
    {
      sub_5159A8(*v32, v28);
      v31 = 0;
      if ( v30 > 0 )
      {
        v21 = (void **)((char *)v32 + v7);
        v29 = (_DWORD *)(v4 + 68);
        do
        {
          v8 = (unsigned __int8 *)(v31 + *v21);
          v9 = *v32;
          if ( *(_BYTE *)(v4 + 84) )
          {
            v27 = -1;
            v9 += v28 - 1;
            v8 += v30 * (v28 - 1);
            v24 = -v30;
            v10 = (_WORD *)(*v29 + 2 * v28 + 2);
          }
          else
          {
            v24 = v30;
            v10 = (_WORD *)*v29;
            v27 = 1;
          }
          v19 = *(_DWORD *)(4 * v31 + *(_DWORD *)(v4 + 24));
          v18 = *(_DWORD *)(4 * v31 + *(_DWORD *)(v4 + 16));
          v11 = 0;
          v26 = 0;
          v25 = 0;
          if ( v28 )
          {
            v23 = v28;
            do
            {
              v12 = *(unsigned __int8 *)(*v8 + (((__int16)v10[v27] + v11 + 8) >> 4) + v20);
              v13 = *(unsigned __int8 *)(v12 + v19);
              *v9 += v13;
              v8 += v24;
              v9 += v27;
              v17 = v12 - *(unsigned __int8 *)(v13 + v18);
              *v10 = 3 * v17 + v26;
              v26 = 5 * v17 + v25;
              v11 = 7 * v17;
              v14 = v23-- == 1;
              v25 = v17;
              v10 += v27;
            }
            while ( !v14 );
            v4 = v16;
          }
          ++v31;
          ++v29;
          *v10 = v26;
        }
        while ( v31 < v30 );
        v7 = a2 - (_DWORD)a3;
      }
      LOBYTE(v5) = *(_BYTE *)(v4 + 84) == 0;
      ++v32;
      v14 = v22-- == 1;
      *(_BYTE *)(v4 + 84) = v5;
    }
    while ( !v14 );
  }
  return v5;
}
