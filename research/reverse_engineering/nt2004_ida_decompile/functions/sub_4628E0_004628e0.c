void __thiscall sub_4628E0(int this, char a2)
{
  const char *v3; // ebp
  CHAR **v4; // eax
  CHAR **v5; // edi
  CHAR ***v6; // eax
  CHAR *v7; // eax
  char *v8; // edi
  char v9; // [esp+0h] [ebp-CCh]
  char v10[64]; // [esp+Ch] [ebp-C0h] BYREF
  char Buffer[128]; // [esp+4Ch] [ebp-80h] BYREF

  if ( a2 )
  {
    v3 = aOpened;
    *(_DWORD *)(this + 36) = 1084227584;
  }
  else
  {
    v3 = aClosed;
    *(_DWORD *)(this + 36) = -1082130432;
    *(_BYTE *)(this + 33) = 0;
  }
  if ( dword_768948 )
  {
    v4 = (CHAR **)operator new(8u);
    if ( v4 )
    {
      *v4 = 0;
      v4[1] = (CHAR *)-1;
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    sub_4E8F80(v10, 63);
    sprintf(Buffer, "*** The server %s %s", v3, v10);
    sub_578600(Buffer);
    if ( v5 )
    {
      v6 = (CHAR ***)operator new(0xCu);
      if ( v6 )
      {
        *v6 = v5;
        v6[1] = 0;
        *((_BYTE *)v6 + 8) = 0;
      }
      else
      {
        v6 = 0;
      }
      if ( *(_DWORD *)(this + 30120) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 30124) + 4) = v6;
      }
      else
      {
        *(_DWORD *)(this + 30120) = v6;
        *(_DWORD *)(this + 30128) = v6;
      }
      *(_DWORD *)(this + 30124) = v6;
      ++*(_DWORD *)(this + 30132);
    }
    v7 = *v5;
    if ( !*v5 )
      v7 = &byte_629120;
    sub_45D100(&byte_764D68, (int)v7, 3, 16909060, 0);
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 5572) )
    {
      v8 = *v5;
      if ( !v8 )
        v8 = &byte_629120;
      sub_500FE0((int)&unk_7D7920, v8, v9);
    }
  }
}
