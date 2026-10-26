int __stdcall sub_4EC270(_DWORD *a1)
{
  char *v3; // eax
  int v4; // esi
  int *v5; // edi
  int v6; // ebx
  unsigned __int64 v7; // rax
  int v8; // esi
  int v9; // [esp+Ch] [ebp+4h]
  int v10; // [esp+Ch] [ebp+4h]
  int v11; // [esp+Ch] [ebp+4h]

  if ( !a1[3705] )
  {
    if ( !dword_B6FA78 )
    {
      sub_412EB0(&dword_91BF20, 5, 1);
      return off_16C9674(a1);
    }
    v3 = sub_41D840(&byte_91CC38, "Race Finished, return to pits or press Escape");
    sub_4730C0((int **)&dword_B6CB98, v3, 3, (int)&byte_1020304, 1084227584);
    v4 = 1;
    if ( a1[4831] == 1 )
    {
      sub_4EE320(74, 0);
    }
    else
    {
      v9 = 0;
      if ( byte_B722E4 )
      {
        v5 = a1 + 4839;
        do
        {
          v6 = *v5;
          v10 = (unsigned __int64)(sub_530630(*(v5 - 5), v4) + (double)v9);
          v7 = (unsigned __int64)(sub_5306C0(a1 + 5500, v6, v4++) + (double)v10);
          ++v5;
          v9 = v7;
        }
        while ( v4 < 4 );
      }
      v8 = a1[4842];
      v11 = (unsigned __int64)(sub_530630(a1[4837], 4) + (double)v9);
      if ( (unsigned int)(unsigned __int64)(sub_5306C0(a1 + 5500, v8, 4) + (double)v11) )
        sub_4EE320(75, 0);
      else
        sub_4EE320(73, 0);
    }
  }
  if ( a1[4831] == 1 )
    sub_562430(&dword_FAE988, 19, 0);
  return 0;
}
