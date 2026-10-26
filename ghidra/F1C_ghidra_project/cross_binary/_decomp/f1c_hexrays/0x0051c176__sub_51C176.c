// f1c  0x0051c176  size=87
_BYTE ***__cdecl sub_51C176(int a1, int a2, int a3, _BYTE ***a4)
{
  _BYTE ***result; // eax
  _BYTE **v6; // esi
  int v7; // edx
  _BYTE *v8; // eax
  char *v9; // edi
  unsigned int v10; // ecx
  char v11; // dl
  _BYTE *v12; // eax
  int v13; // [esp+10h] [ebp+8h]
  int v14; // [esp+1Ch] [ebp+14h]

  result = a4;
  v14 = 0;
  v6 = *result;
  if ( *(int *)(a1 + 272) > 0 )
  {
    v7 = a3 - (_DWORD)v6;
    v13 = a3 - (_DWORD)v6;
    do
    {
      v8 = *v6;
      v9 = *(_BYTE **)((char *)v6 + v7);
      v10 = (unsigned int)&(*v6)[*(_DWORD *)(a1 + 92)];
      if ( (unsigned int)*v6 < v10 )
      {
        do
        {
          v11 = *v9++;
          *v8 = v11;
          v12 = v8 + 1;
          *v12 = v11;
          v8 = v12 + 1;
        }
        while ( (unsigned int)v8 < v10 );
        v7 = v13;
      }
      result = (_BYTE ***)++v14;
      ++v6;
    }
    while ( v14 < *(_DWORD *)(a1 + 272) );
  }
  return result;
}
