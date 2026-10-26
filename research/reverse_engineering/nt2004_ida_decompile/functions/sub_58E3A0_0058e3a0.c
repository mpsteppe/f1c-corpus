int __cdecl sub_58E3A0(int a1, _DWORD *a2, int a3)
{
  int result; // eax
  __int16 *v4; // ebp
  int v5; // ebx
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // [esp+4h] [ebp-38h]
  int v10; // [esp+8h] [ebp-34h] BYREF
  int v11; // [esp+Ch] [ebp-30h] BYREF
  int v12; // [esp+10h] [ebp-2Ch] BYREF
  int v13; // [esp+14h] [ebp-28h]
  _DWORD v14[7]; // [esp+20h] [ebp-1Ch] BYREF
  int v15; // [esp+40h] [ebp+4h]

  result = 0;
  v10 = 0;
  v9 = 0;
  if ( dword_7FFA00 )
  {
    sub_58D640((int)a2, &v11);
    sub_58D600((int)a2, &v10);
    if ( *(unsigned __int8 *)(a1 + 4) >> 2 )
    {
      v15 = *(unsigned __int8 *)(a1 + 4) >> 2;
      v4 = (__int16 *)(8 * a3 + 8276054);
      do
      {
        v5 = *(v4 - 1);
        v6 = (unsigned __int16)v4[1];
        v7 = *(_DWORD *)(dword_7E483C + 4 * v5);
        if ( *(char *)(v7 + 4) < 0 && dword_61B56C )
          sub_58E4F0(v7, v6);
        if ( sub_58FF00(v7, v6, &v12) )
        {
          v8 = v13;
          if ( *v4 != -1 )
            v8 = v13 + ((*v4 * *(unsigned __int16 *)(v7 + 8) * (*(unsigned __int8 *)(v7 + 7) + 1)) << 8);
          v14[1] = v8;
          v9 += v12;
          v14[2] = v12;
          v14[3] = *a2;
          v14[6] = v11;
          v14[0] = v5;
          v14[4] = v10;
          v14[5] = *(unsigned __int16 *)(v7 + 2);
          dword_7FFA00(v14);
          sub_58CF10((_BYTE *)v7, v6);
        }
        v4 += 4;
        --v15;
      }
      while ( v15 );
    }
    return sub_58E550(v9);
  }
  return result;
}
