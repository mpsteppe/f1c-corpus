int __stdcall sub_55B8C0(const char *a1, _DWORD *a2)
{
  int v3; // edi
  int v4; // ebp
  const char *v5; // esi
  int v6; // esi
  char v7[256]; // [esp+10h] [ebp-514h] BYREF
  _DWORD v8[2]; // [esp+110h] [ebp-414h] BYREF
  int v9; // [esp+118h] [ebp-40Ch]
  LPVOID v10; // [esp+420h] [ebp-104h]
  _BYTE v11[256]; // [esp+424h] [ebp-100h] BYREF

  sub_559A40(v8);
  if ( !*a1 )
    goto LABEL_2;
  v3 = sub_587DB0(a1, aRb);
  if ( v3 )
    goto LABEL_9;
  v4 = 0;
  if ( dword_8B8E30 > 0 )
  {
    v5 = byte_8B5A3C;
    do
    {
      sub_58815F(v11, "%s\\%s", v5, a1);
      v3 = sub_587DB0(v11, aRb);
      if ( v3 )
        break;
      ++v4;
      v5 += 132;
    }
    while ( v4 < dword_8B8E30 );
  }
  if ( v4 != dword_8B8E30 )
  {
LABEL_9:
    sub_587F64(v3, 0, 2);
    v6 = sub_58ACE6(v3);
    sub_587F64(v3, 0, 0);
    v9 = v6;
    v10 = (LPVOID)sub_587C03(v6);
    if ( sub_58803F(v10, 1, v9, v3) == v6 && sub_559A70(v8) != 3 )
    {
      do
      {
        if ( v8[0] == 3 )
          break;
        if ( v8[0] != 2 && sub_559E20((int)v8, (int)aInstance, v7, 0) && sub_559A70(v8) != 3 )
        {
          while ( v8[0] != 3 )
          {
            if ( v8[0] != 2 && sub_559E20((int)v8, (int)aMeshfile, v7, 0) )
            {
              if ( a2 )
                ++*a2;
              break;
            }
            if ( sub_559A70(v8) == 3 )
              break;
          }
        }
      }
      while ( sub_559A70(v8) != 3 );
    }
    sub_587BCF(v10);
    sub_587D02(v3);
    return 0;
  }
  else
  {
LABEL_2:
    sub_58815F(v7, "Illegal scene file name %s", a1);
    sub_53C590(-1, v7);
    return -1;
  }
}
