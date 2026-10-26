int __fastcall sub_4F95D0(int a1)
{
  int v1; // ebx
  int v2; // ebp
  int *v3; // edi
  int i; // esi
  char v5; // al
  signed int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v1 = 0;
  v2 = *(_DWORD *)(a1 + 288) + 3;
  v9 = a1;
  v8 = 0;
  v7 = 0;
  if ( (int)NumOfElements > 0 )
  {
    v3 = dword_75AAD0;
    do
    {
      for ( i = 0; i < 18; ++i )
      {
        if ( sub_50BEB0(i) == 1 && ++v1 >= v2 )
          v8 = 1;
      }
      ++v3;
      ++v7;
    }
    while ( v7 < (int)NumOfElements );
    a1 = v9;
  }
  v5 = *(_BYTE *)(a1 + 163);
  *(_DWORD *)(a1 + 288) = v1;
  if ( v5 )
    return 0;
  else
    return v8;
}
