int __thiscall sub_614160(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int result; // eax
  char Buffer[64]; // [esp+Ch] [ebp-40h] BYREF

  sub_613DE0(this, Buffer, 7);
  if ( !strcmp("//[[gM", Buffer) )
  {
    sub_613DE0(this, Buffer, 2);
    *(_DWORD *)(this + 16) = Buffer[0] == 97;
    sub_613DE0(this, Buffer, 6);
    sub_630FE0(this + 32);
    sub_613DE0(this, Buffer, 2);
    *(_BYTE *)(this + 64) = Buffer[0] == 98;
    sub_613DE0(this, Buffer, 18);
    v2 = *(_DWORD *)(this + 20);
    if ( v2 )
    {
      if ( v2 == 5 )
        sub_613A50(*(_DWORD **)(this + 4), this + 72, 4);
      else
        sub_62AD40(4);
    }
    else
    {
      sub_6318A2(this + 72, 1, 4, *(_DWORD *)(this + 4));
    }
    v3 = *(_DWORD *)(this + 20);
    if ( v3 )
    {
      if ( v3 == 5 )
        sub_613A50(*(_DWORD **)(this + 4), this + 68, 4);
      else
        sub_62AD40(4);
    }
    else
    {
      sub_6318A2(this + 68, 1, 4, *(_DWORD *)(this + 4));
    }
    v4 = *(_DWORD *)(this + 20);
    if ( v4 )
    {
      if ( v4 == 5 )
        sub_613A50(*(_DWORD **)(this + 4), this + 80, 4);
      else
        sub_62AD40(4);
    }
    else
    {
      sub_6318A2(this + 80, 1, 4, *(_DWORD *)(this + 4));
    }
    sub_613DE0(this, Buffer, 5);
    v5 = *(_DWORD *)(this + 20);
    if ( v5 )
    {
      if ( v5 == 5 )
        result = *(_DWORD *)(*(_DWORD *)(this + 4) + 24);
      else
        result = sub_62B120(*(_DWORD *)(this + 4));
      *(_DWORD *)(this + 84) = result;
      *(_BYTE *)(this + 88) = 1;
    }
    else
    {
      result = sub_634320(*(_DWORD *)(this + 4));
      *(_DWORD *)(this + 84) = result;
      *(_BYTE *)(this + 88) = 1;
    }
  }
  else
  {
    *(_BYTE *)(this + 88) = 0;
    return sub_613F20(this);
  }
  return result;
}
