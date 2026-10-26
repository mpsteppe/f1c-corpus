int __cdecl sub_58F3D0(int a1, unsigned __int8 *a2)
{
  unsigned __int8 *v2; // esi
  int v3; // ebp
  int v4; // ecx
  _BYTE *v5; // eax
  int v6; // ecx
  int v7; // eax
  _BYTE *v8; // edi
  int v9; // ecx
  int v10; // edx
  unsigned __int8 *v11; // esi
  int v12; // ebx
  int v13; // edx
  int v14; // eax
  unsigned __int8 v15; // cl
  int v16; // eax
  int v17; // eax
  unsigned int v19; // [esp+10h] [ebp-20h]
  int v20; // [esp+14h] [ebp-1Ch]
  int v21; // [esp+18h] [ebp-18h]
  int v22; // [esp+1Ch] [ebp-14h]
  _BYTE v23[16]; // [esp+20h] [ebp-10h] BYREF

  v2 = a2;
  v19 = (unsigned int)&a2[((4 * a2[6] + 3) & 0xFFFFFFFC) + 8 + (((a2[4] >> 2) + 3) & 0xFFFFFFFC)];
  sub_58F100(a2);
  v3 = a1;
  v4 = 12;
  v5 = (_BYTE *)(a1 + 7);
  do
  {
    *v5 = 0;
    v5 += 8;
    --v4;
  }
  while ( v4 );
  v6 = a2[4] >> 2;
  v22 = v6;
  while ( 2 )
  {
    v7 = 0;
    v21 = 1;
    v20 = 0;
    if ( v6 <= 0 )
      return 1;
    v8 = (_BYTE *)(v3 + 7);
    do
    {
      if ( !*v8 )
      {
        v9 = dword_7E483C;
        v10 = v2[v7 + 8];
        *v8 = 1;
        v11 = &v2[4 * v10];
        v12 = (char)v11[4];
        if ( !sub_58FF00(
                *(_DWORD *)(v9 + 4 * *(__int16 *)(v8 - 7)),
                *(unsigned __int8 *)((unsigned __int8)*(v8 - 1) + v3 + 98),
                v23) )
          return 0;
        v13 = 0;
        if ( v12 <= 0 )
        {
          v2 = a2;
        }
        else
        {
          do
          {
            v14 = v11[v13 + 16];
            if ( v14 != 255 && (v14 & 0x80u) != 0 )
            {
              v15 = v11[v13 + 8];
              v16 = v14 & 0x7F;
              if ( v15 == 0xFF )
              {
                v17 = *(_DWORD *)(v19 + 4 * v16);
                if ( v17 )
                {
                  if ( ((1 << v23[v13 + 12]) & v17) == 0 )
                    return 0;
                }
                else
                {
                  *v8 = 0;
                  v21 = 0;
                }
              }
              else if ( v15 == 0xFE )
              {
                *(_DWORD *)(v19 + 4 * v16) = 1 << v23[v13 + 12];
              }
            }
            ++v13;
          }
          while ( v13 < v12 );
          v2 = a2;
          v3 = a1;
        }
      }
      v6 = v22;
      v7 = v20 + 1;
      v8 += 8;
      ++v20;
    }
    while ( v20 < v22 );
    if ( !v21 )
      continue;
    break;
  }
  return 1;
}
