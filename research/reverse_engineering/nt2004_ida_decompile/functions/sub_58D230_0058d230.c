int __cdecl sub_58D230(_BYTE *a1, int a2)
{
  int v2; // ebp
  int v3; // ebx
  int *v4; // ecx
  int v5; // eax
  int v6; // ecx
  int *v7; // eax
  int v8; // eax
  int v10; // [esp+10h] [ebp-4h] BYREF

  v2 = (int)a1;
  v3 = 0;
  if ( *a1 == 3 && a1[1] == 12 )
  {
    sub_58E0F0(a1, &v10, &a1);
    v4 = dword_8000C0;
    while ( 1 )
    {
      v5 = *v4;
      if ( *v4 )
      {
        if ( (_BYTE *)*(unsigned __int8 *)(v5 + 9) == a1 && *(unsigned __int8 *)(v5 + 8) == v10 )
          break;
      }
      v4 += 2;
      if ( (int)v4 >= (int)&dword_800100 )
      {
        v6 = 0;
        v7 = dword_8000C0;
        while ( *v7 )
        {
          v7 += 2;
          ++v6;
          if ( (int)v7 >= (int)&dword_800100 )
            goto LABEL_13;
        }
        v8 = a2;
        dword_8000C0[2 * v6] = v2;
        dword_8000C4[2 * v6] = v8;
        v3 = 1;
LABEL_13:
        sub_58D1C0(a2);
        return v3;
      }
    }
  }
  return v3;
}
