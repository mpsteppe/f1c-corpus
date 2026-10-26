int __thiscall sub_5E24F0(void *this, const char *ArgList)
{
  int v4; // ebx
  char String[256]; // [esp+10h] [ebp-918h] BYREF
  int v6[2]; // [esp+110h] [ebp-818h] BYREF
  int v7; // [esp+118h] [ebp-810h]
  _BYTE v8[1024]; // [esp+11Ch] [ebp-80Ch] BYREF
  int v9; // [esp+91Ch] [ebp-Ch]
  void *v10; // [esp+920h] [ebp-8h]

  if ( *ArgList )
  {
    v4 = sub_5E0740(this, ArgList, 0);
    if ( v4 )
    {
      memset(v8, 0, sizeof(v8));
      v7 = 0;
      v10 = 0;
      v6[0] = 0;
      v6[1] = 0;
      v9 = 0;
      v7 = *(_DWORD *)(v4 + 8);
      v10 = *(void **)v4;
      dword_FB2E8C = 0;
      while ( sub_5DF750(v6) != 3 )
      {
        if ( v6[0] == 3 )
          break;
        if ( v6[0] != 2 )
        {
          if ( sub_5DF240((int)v6, "INSTANCE", String, 0, 0, 0, 0, 0, 0, 0) )
            sub_5E06B0((int)String, v6);
        }
      }
      sub_5DF6E0((void **)v4);
      return dword_FB2E8C;
    }
    else
    {
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error opening scene file name %s", (char)ArgList);
      return -1;
    }
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid scene file name %s", (char)ArgList);
    return -1;
  }
}
