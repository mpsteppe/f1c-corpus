int __thiscall sub_5A4130(int *this)
{
  void *v1; // eax
  int *v2; // esi
  DWORD v3; // eax
  int *v4; // eax
  void *v5; // esi
  int v6; // edi

  v1 = (void *)this[64];
  v2 = this + 63;
  if ( v1 && ((v3 = WaitForSingleObject(v1, this[65])) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  v5 = (void *)v2[1];
  v6 = *v4;
  if ( v5 )
    ReleaseMutex(v5);
  return v6;
}
