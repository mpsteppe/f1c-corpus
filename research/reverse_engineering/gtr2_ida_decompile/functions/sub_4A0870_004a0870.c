int __thiscall sub_4A0870(_DWORD *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // eax
  int v5; // eax
  _BYTE v7[128]; // [esp+8h] [ebp-80h] BYREF

  sub_510770(&byte_B6F530, 0);
  v2 = this[217];
  if ( v2 >= 0 && v2 < this[221] )
  {
    v3 = (int *)this[218];
    if ( v2 <= 0 )
    {
LABEL_6:
      if ( v3 )
      {
        v4 = *v3;
        if ( v4 )
        {
          v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 28))(v4);
          if ( v5 || strlen(0) )
            sub_514EC0(v5, 0);
        }
      }
    }
    else
    {
      while ( v3 )
      {
        v3 = (int *)v3[1];
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
    }
  }
  sub_501490(v7, 127);
  return sub_4CE770(v7);
}
