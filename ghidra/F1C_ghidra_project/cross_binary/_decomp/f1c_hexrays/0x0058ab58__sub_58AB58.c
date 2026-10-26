// f1c  0x0058ab58  size=317
LPVOID __cdecl sub_58AB58(int a1, int a2)
{
  SIZE_T v2; // esi
  LPVOID result; // eax
  LPVOID v4; // [esp+14h] [ebp-20h]
  unsigned int v5; // [esp+18h] [ebp-1Ch]

  v2 = a2 * a1;
  v5 = a2 * a1;
  if ( (unsigned int)(a2 * a1) <= 0xFFFFFFE0 )
  {
    if ( !v2 )
      v2 = 1;
    v2 = (v2 + 15) & 0xFFFFFFF0;
  }
  while ( 1 )
  {
    v4 = 0;
    if ( v2 <= 0xFFFFFFE0 )
    {
      if ( dword_8D4908 == 3 )
      {
        if ( v5 > dword_8D4900 )
          goto LABEL_14;
        sub_58DFEA(9);
        v4 = (LPVOID)sub_59416F(v5);
        sub_58E04B(9);
        if ( v4 )
        {
          sub_58BB10(v4, 0, v5);
          goto LABEL_14;
        }
LABEL_15:
        v4 = HeapAlloc(hHeap, 8u, v2);
        goto LABEL_16;
      }
      if ( dword_8D4908 == 2 && v2 <= dword_5E998C )
      {
        sub_58DFEA(9);
        v4 = (LPVOID)sub_594C12(v2 >> 4);
        sub_58E04B(9);
        if ( !v4 )
          goto LABEL_15;
        sub_58BB10(v4, 0, v2);
      }
LABEL_14:
      if ( v4 )
        return v4;
      goto LABEL_15;
    }
LABEL_16:
    if ( v4 || !dword_8D41B0 )
      return v4;
    result = (LPVOID)sub_593DB8(v2);
    if ( !result )
      return result;
  }
}
