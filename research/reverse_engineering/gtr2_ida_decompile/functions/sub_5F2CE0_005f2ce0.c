int __thiscall sub_5F2CE0(int this)
{
  char v3; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)(this + 68) )
  {
    if ( *(_BYTE *)(this + 72) )
    {
      if ( (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 68) + 24))(*(_DWORD *)(this + 68), 1) )
      {
        sub_5D8C80(this, (char *)0xFFFFFFFF, "Error issuing query end.", v3);
        return -1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      sub_5D8C80(this, (char *)0xFFFFFFFF, "No pending query for %s", this);
      return -1;
    }
  }
  else
  {
    sub_5D8C80(this, (char *)0xFFFFFFFF, "No hw query object for %s", this);
    return -1;
  }
}
