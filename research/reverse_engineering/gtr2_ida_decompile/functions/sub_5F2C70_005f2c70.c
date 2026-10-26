int __thiscall sub_5F2C70(int this)
{
  int v2; // eax
  char v4; // [esp+0h] [ebp-4h]

  v2 = *(_DWORD *)(this + 68);
  if ( v2 )
  {
    if ( *(_BYTE *)(this + 72) )
    {
      sub_5D8C80(this, (char *)0xFFFFFFFF, "Query already issued for %s", this);
      return -1;
    }
    else if ( (*(int (__stdcall **)(int, int))(*(_DWORD *)v2 + 24))(v2, 2) )
    {
      sub_5D8C80(this, (char *)0xFFFFFFFF, "Error issuing query begin.", v4);
      return -1;
    }
    else
    {
      *(_BYTE *)(this + 72) = 1;
      return 0;
    }
  }
  else
  {
    sub_5D8C80(this, (char *)0xFFFFFFFF, "No hw query object for %s", this);
    return -1;
  }
}
