int __stdcall sub_6B5530(int *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // edi
  int v6; // eax
  int result; // eax
  unsigned int v8; // esi
  _DWORD *v9; // eax
  unsigned int v10; // ecx
  int v11; // [esp+Ch] [ebp-4h]
  int v12; // [esp+20h] [ebp+10h]

  v11 = a1[1];
  v5 = 0x3B9AC9F0 / a3;
  if ( (int)(0x3B9AC9F0 / a3) <= 0 )
  {
    v6 = *a1;
    *(_DWORD *)(v6 + 20) = 70;
    (*(void (__stdcall **)(int *))v6)(a1);
  }
  if ( (int)v5 >= (int)a4 )
    v5 = a4;
  *(_DWORD *)(v11 + 80) = v5;
  result = sub_6B5340(a1, a2, 4 * a4);
  v8 = 0;
  v12 = result;
  if ( a4 )
  {
    do
    {
      if ( v5 >= a4 - v8 )
        v5 = a4 - v8;
      v9 = sub_6B5480(a1, a2, a3 * v5);
      if ( v5 )
      {
        v10 = v5;
        do
        {
          *(_DWORD *)(v12 + 4 * v8++) = v9;
          v9 = (_DWORD *)((char *)v9 + a3);
          --v10;
        }
        while ( v10 );
      }
    }
    while ( v8 < a4 );
    return v12;
  }
  return result;
}
