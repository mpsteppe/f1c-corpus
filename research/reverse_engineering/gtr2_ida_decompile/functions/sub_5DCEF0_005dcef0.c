int __thiscall sub_5DCEF0(_DWORD *this, int a2, int a3)
{
  int v3; // ebx
  int v6; // [esp+0h] [ebp-8h]
  __int16 v7; // [esp+4h] [ebp-4h]

  v3 = a2;
  if ( a2 )
  {
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int *))(*(_DWORD *)dword_FB27A4 + 636))(dword_FB27A4, 0, 0, &a2);
    if ( v6 == 257 || v6 == 514 )
    {
      this[185] = 8;
    }
    else if ( v6 == 1032 )
    {
      this[185] = 12;
    }
    if ( sub_5E26B0(v3) )
    {
      return -1;
    }
    else
    {
      if ( v7 < 0 )
        sub_609430(0, 1);
      return 0;
    }
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid scene file name %s", 0);
    return -1;
  }
}
