// f1c  0x0051e2ba  size=301
int __usercall sub_51E2BA@<eax>(_DWORD *a1@<esi>)
{
  int v1; // ebx
  int v2; // eax
  int *v3; // eax
  int result; // eax
  int v5; // ecx
  int v6; // edi
  int i; // edx
  int v8; // eax
  int v9; // [esp+8h] [ebp-34h]
  int v10; // [esp+14h] [ebp-28h]
  int v11; // [esp+18h] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-20h]
  _DWORD *v13; // [esp+20h] [ebp-1Ch]
  int *v14; // [esp+24h] [ebp-18h]
  int v15; // [esp+28h] [ebp-14h]
  int v16; // [esp+2Ch] [ebp-10h]
  int v17; // [esp+34h] [ebp-8h]
  int j; // [esp+38h] [ebp-4h]

  v10 = a1[105];
  v1 = sub_51E1EF(a1, (char *)(v10 + 32));
  v2 = *a1;
  if ( a1[25] == 3 )
  {
    v3 = (int *)(v2 + 24);
    *v3 = v1;
    v3[1] = *(_DWORD *)(v10 + 32);
    v3[2] = *(_DWORD *)(v10 + 36);
    v3[3] = *(_DWORD *)(v10 + 40);
    *(_DWORD *)(*a1 + 20) = 93;
  }
  else
  {
    *(_DWORD *)(v2 + 20) = 94;
    *(_DWORD *)(*a1 + 24) = v1;
  }
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  result = (*(int (__cdecl **)(_DWORD *, int, int, _DWORD))(a1[1] + 8))(a1, 1, v1, a1[25]);
  v12 = 0;
  v9 = result;
  v15 = v1;
  if ( (int)a1[25] > 0 )
  {
    v13 = (_DWORD *)result;
    v14 = (int *)(v10 + 32);
    do
    {
      v5 = *v14;
      v6 = 0;
      v17 = v15 / *v14;
      if ( *v14 > 0 )
      {
        v16 = 0;
        v11 = *v14;
        do
        {
          for ( i = v16; i < v1; i += v15 )
          {
            for ( j = 0; j < v17; *(_BYTE *)(v8 + i) = (v6 + (v5 - 1) / 2) / (v5 - 1) )
            {
              v8 = j + *v13;
              ++j;
            }
          }
          v16 += v17;
          v6 += 255;
          --v11;
        }
        while ( v11 );
      }
      ++v12;
      ++v14;
      ++v13;
      v15 = v17;
    }
    while ( v12 < a1[25] );
    result = v9;
  }
  *(_DWORD *)(v10 + 20) = v1;
  *(_DWORD *)(v10 + 16) = result;
  return result;
}
