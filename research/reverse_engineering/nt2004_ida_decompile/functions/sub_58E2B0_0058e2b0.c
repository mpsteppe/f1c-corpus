unsigned __int8 *__cdecl sub_58E2B0(int a1, int a2, int a3, int a4)
{
  unsigned __int8 *result; // eax
  int v5; // ebp
  __int16 *v6; // ebx
  int v7; // esi
  int v8; // ebp
  int v9; // edi
  int v10; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+8h] [ebp-18h] BYREF
  int v12; // [esp+Ch] [ebp-14h]
  _BYTE v13[16]; // [esp+10h] [ebp-10h] BYREF

  result = (unsigned __int8 *)dword_7FFA08;
  if ( dword_7FFA08 )
  {
    sub_58D640(a1, &v11);
    v5 = a3;
    result = 0;
    v10 = 0;
    v12 = *(unsigned __int8 *)(a3 + 4) >> 2;
    if ( v12 )
    {
      v6 = (__int16 *)(8 * a4 + 8276052);
      while ( 1 )
      {
        v7 = 0;
        v8 = v5 + 4 * result[v5 + 8];
        do
        {
          if ( *(unsigned __int8 *)(v7 + v8 + 12) != 255 )
          {
            v9 = sub_58FC40(a2, *(unsigned __int8 *)(v7 + v8 + 12));
            if ( sub_58FF00(*(_DWORD *)(dword_7E483C + 4 * *v6), (unsigned __int16)v6[2], v13) )
              dword_7FFA08(a1, v9, 1 << v13[v7 + 12], v11);
          }
          ++v7;
        }
        while ( v7 < 4 );
        result = (unsigned __int8 *)(v10 + 1);
        v6 += 4;
        if ( ++v10 >= v12 )
          break;
        v5 = a3;
      }
    }
  }
  return result;
}
