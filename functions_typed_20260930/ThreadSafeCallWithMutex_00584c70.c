char __thiscall sub_584C70(_DWORD *this, int a2)
{
  void *v2; // eax
  _DWORD *v3; // esi
  char v4; // bl
  DWORD v5; // eax
  void *v6; // esi

  v2 = (void *)this[341];
  v3 = this + 337;
  v4 = 0;
  if ( v2 )
  {
    v5 = WaitForSingleObject(v2, this[342]);
    if ( !v5 || v5 == 128 )
    {
      if ( (unsigned __int8)LinkedListNodeAppend_6000(a2, 0) )
        v4 = 1;
      v6 = (void *)v3[4];
      if ( v6 )
        ReleaseMutex(v6);
    }
  }
  return v4;
}

