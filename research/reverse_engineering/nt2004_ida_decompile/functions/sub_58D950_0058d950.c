int __cdecl sub_58D950(unsigned int a1, int a2, int a3)
{
  int v3; // edi
  int result; // eax
  char *v5; // ecx
  int v6; // eax
  int v7; // esi
  int *v8; // ecx
  unsigned int v9; // edx
  char *v10; // ecx
  int v11; // edx

  v3 = -1;
  result = 0;
  v5 = byte_7FFAAA;
  while ( *v5 )
  {
    v5 += 96;
    ++result;
    if ( (int)v5 >= (int)&unk_8000AA )
    {
      if ( a3 )
        v3 = dword_7FFA80[a2];
      v6 = sub_58FC30();
      v7 = 0;
      v8 = dword_7FFAB0;
      do
      {
        if ( !*((_WORD *)v8 - 2) )
        {
          v9 = *(unsigned __int16 *)(*v8 + 2);
          if ( (_WORD)v9 )
          {
            if ( v6 - *(v8 - 3) > v9 && v3 != v7 )
            {
              sub_58DB10(v7);
              return v7;
            }
          }
        }
        v8 += 24;
        ++v7;
      }
      while ( (int)v8 < (int)dword_8000B0 );
      result = 0;
      v10 = byte_7FFAAB;
      while ( 1 )
      {
        if ( !*(_WORD *)(v10 + 1) )
        {
          v11 = (unsigned __int8)*v10;
          if ( *(unsigned __int16 *)(*(_DWORD *)(v10 + 5) + 4) <= a1 && v11 == a2 && result != v3 )
            break;
        }
        v10 += 96;
        ++result;
        if ( (int)v10 >= (int)&unk_8000AB )
          return -1;
      }
      byte_7FFAAA[96 * result] = 0;
      --dword_7FFA40[v11];
      return result;
    }
  }
  return result;
}
