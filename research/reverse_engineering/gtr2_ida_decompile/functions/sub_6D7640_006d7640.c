int __stdcall sub_6D7640(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5)
{
  int result; // eax
  int v7; // edi
  _DWORD *v8; // esi
  int i; // eax
  int v10; // [esp+Ch] [ebp-4h]
  void (__stdcall **v11)(_DWORD *, int, int, int); // [esp+18h] [ebp+8h]

  result = a1[91];
  v7 = a1[17];
  v10 = 0;
  if ( (int)a1[15] > 0 )
  {
    v11 = (void (__stdcall **)(_DWORD *, int, int, int))(result + 12);
    v8 = a2;
    for ( i = a4 - (_DWORD)a2; ; i = a4 - (_DWORD)a2 )
    {
      (*v11)(a1, v7, 4 * a3 + *v8, *(_DWORD *)((char *)v8 + i) + 4 * a5 * *(_DWORD *)(v7 + 12));
      result = v10 + 1;
      ++v11;
      ++v8;
      v7 += 84;
      if ( ++v10 >= a1[15] )
        break;
    }
  }
  return result;
}
