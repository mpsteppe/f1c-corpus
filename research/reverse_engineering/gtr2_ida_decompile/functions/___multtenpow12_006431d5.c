int __cdecl __multtenpow12(_WORD *a1, int a2, int a3)
{
  int result; // eax
  char *v4; // ebx
  char v5; // al
  char *v6; // esi
  _DWORD *v7; // esi
  __int64 v8; // [esp+4h] [ebp-10h] BYREF
  int v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  result = dword_912B08;
  v4 = (char *)&unk_913850 - 96;
  v10 = dword_912B08;
  if ( a2 )
  {
    if ( a2 < 0 )
    {
      a2 = -a2;
      v4 = (char *)&unk_9139B0 - 96;
    }
    if ( !a3 )
    {
      result = (int)a1;
      *a1 = 0;
    }
    while ( a2 )
    {
      v5 = a2;
      a2 >>= 3;
      result = v5 & 7;
      v4 += 84;
      if ( result )
      {
        v6 = &v4[12 * result];
        if ( *(_WORD *)v6 >= 0x8000u )
        {
          LODWORD(v8) = *(_DWORD *)v6;
          v7 = v6 + 4;
          HIDWORD(v8) = *v7;
          v9 = v7[1];
          --*(_DWORD *)((char *)&v8 + 2);
          v6 = (char *)&v8;
        }
        result = __ld12mul((int)a1, (int)v6);
      }
    }
  }
  return result;
}
