int __cdecl sub_55B5ED(int a1, int a2, _DWORD *a3, int a4)
{
  int *v4; // eax
  int v5; // edx
  int result; // eax
  int v7; // edx
  _DWORD *v8; // edi
  unsigned __int8 *v9; // ecx
  _BYTE *v10; // esi
  char v11; // dl
  unsigned __int8 *v12; // ecx
  char v13; // dl
  char v14; // al
  int v15; // [esp+4h] [ebp-10h]
  int v16; // [esp+8h] [ebp-Ch]
  int v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]
  int v19; // [esp+1Ch] [ebp+8h]

  v4 = *(int **)(*(_DWORD *)(a1 + 420) + 24);
  v18 = *v4;
  v5 = v4[1];
  result = v4[2];
  v17 = v5;
  v7 = *(_DWORD *)(a1 + 92);
  v16 = result;
  v15 = v7;
  if ( a4 > 0 )
  {
    v8 = a3;
    result = a2 - (_DWORD)a3;
    do
    {
      v9 = *(unsigned __int8 **)((char *)v8 + result);
      v10 = (_BYTE *)*v8;
      if ( v7 )
      {
        v19 = v7;
        do
        {
          v11 = *(_BYTE *)(*v9 + v18);
          v12 = v9 + 1;
          v13 = *(_BYTE *)(*v12++ + v17) + v11;
          v14 = *(_BYTE *)(*v12 + v16);
          v9 = v12 + 1;
          *v10++ = v14 + v13;
          --v19;
        }
        while ( v19 );
        v7 = v15;
        result = a2 - (_DWORD)a3;
      }
      ++v8;
      --a4;
    }
    while ( a4 );
  }
  return result;
}
