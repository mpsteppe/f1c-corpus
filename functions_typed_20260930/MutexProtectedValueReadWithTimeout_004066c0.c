int __thiscall sub_4066C0(_DWORD *this)
{
  void *v2; // eax
  int v3; // edi
  DWORD v4; // eax
  void *v5; // esi

  v2 = (void *)this[20];
  v3 = -1;
  if ( v2 )
  {
    v4 = WaitForSingleObject(v2, this[21]);
    if ( !v4 || v4 == 128 )
    {
      v3 = this[19];
      v5 = (void *)this[20];
      if ( v5 )
        ReleaseMutex(v5);
    }
  }
  return v3;
}

