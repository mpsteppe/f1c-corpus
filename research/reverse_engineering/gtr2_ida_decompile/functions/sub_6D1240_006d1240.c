int __stdcall sub_6D1240(int a1, int a2, int a3, _BYTE ***a4)
{
  _BYTE **v4; // edi
  int result; // eax
  int v6; // ebx
  _BYTE *v7; // eax
  char *v8; // edx
  _BYTE *v9; // esi
  char v10; // cl
  _BYTE *v11; // eax
  int v12; // [esp+Ch] [ebp+8h]
  int v13; // [esp+18h] [ebp+14h]

  v4 = *a4;
  result = *(_DWORD *)(a1 + 316);
  if ( result > 0 )
  {
    v12 = *(_DWORD *)(a1 + 112);
    v6 = a3 - (_DWORD)v4;
    v13 = result;
    do
    {
      v7 = *v4;
      v8 = *(_BYTE **)((char *)v4 + v6);
      v9 = &(*v4)[v12];
      if ( *v4 < v9 )
      {
        do
        {
          v10 = *v8++;
          *v7 = v10;
          v11 = v7 + 1;
          *v11 = v10;
          v7 = v11 + 1;
        }
        while ( v7 < v9 );
      }
      ++v4;
      result = --v13;
    }
    while ( v13 );
  }
  return result;
}
