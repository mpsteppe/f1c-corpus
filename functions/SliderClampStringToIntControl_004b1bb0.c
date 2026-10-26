char __thiscall sub_4B1BB0(_DWORD *this, const char *a2)
{
  const char *v3; // ecx
  int v4; // eax
  bool v5; // cc
  int v6; // edx

  if ( !a2 || !strlen(a2) )
    return 0;
  ObjectHandleReader((int)a2, &a2);
  v3 = a2;
  v4 = this[7];
  v5 = (int)a2 < v4;
  v6 = this[8];
  this[5] = a2;
  if ( v5 )
  {
    this[5] = v4;
    return 1;
  }
  else
  {
    if ( (int)v3 > v6 )
      this[5] = v6;
    return 1;
  }
}
