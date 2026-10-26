int __cdecl sub_58F5F0(int a1, __int16 *a2, int a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // ecx
  __int16 *v6; // edx
  int v7; // esi
  int v8; // edi
  char v9; // bl
  int v10; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+8h] [ebp-18h] BYREF
  int v12; // [esp+Ch] [ebp-14h]
  _BYTE v13[16]; // [esp+10h] [ebp-10h] BYREF
  __int16 *v14; // [esp+24h] [ebp+4h]

  result = sub_58D680(a1, &v11);
  if ( result )
  {
    v4 = a3;
    v5 = 0;
    v10 = 0;
    v12 = *(unsigned __int8 *)(a3 + 4) >> 2;
    result = v12;
    if ( v12 )
    {
      v6 = a2;
      v14 = a2;
      do
      {
        v7 = 0;
        v8 = v4 + 4 * *(unsigned __int8 *)(v4 + v5 + 8);
        if ( *(char *)(v8 + 4) > 0 )
        {
          do
          {
            if ( *(_BYTE *)(v8 + v7 + 8) == 0xFE )
            {
              v9 = *(_BYTE *)(v7 + v8 + 16);
              if ( v9 >= 0 )
              {
                if ( sub_58FF00(
                       *(_DWORD *)(dword_7E483C + 4 * *v6),
                       *((unsigned __int8 *)a2 + *((unsigned __int8 *)v6 + 6) + 98),
                       v13) )
                {
                  *(_BYTE *)((unsigned __int8)v9 + v11) = v13[v7 + 12];
                }
              }
            }
            v6 = v14;
            ++v7;
          }
          while ( v7 < *(char *)(v8 + 4) );
          v4 = a3;
          v5 = v10;
        }
        result = v12;
        ++v5;
        v6 += 4;
        v10 = v5;
        v14 = v6;
      }
      while ( v5 < v12 );
    }
  }
  return result;
}
