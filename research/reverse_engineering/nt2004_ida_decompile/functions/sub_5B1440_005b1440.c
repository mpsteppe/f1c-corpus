int __thiscall sub_5B1440(int *this, const char *a2, int a3, int a4)
{
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int i; // eax
  _DWORD *v10; // eax
  char Buffer[256]; // [esp+8h] [ebp-100h] BYREF

  if ( sub_5B16F0(a2) )
  {
    sprintf(Buffer, "Actor %s already exists", a2);
    return -1;
  }
  else
  {
    v6 = *this;
    if ( *this )
    {
      for ( i = *(_DWORD *)(v6 + 28); i; i = *(_DWORD *)(i + 28) )
        v6 = i;
      v10 = operator new(0x20u);
      if ( v10 )
        v8 = sub_5B12C0(v10);
      else
        v8 = 0;
      *(_DWORD *)(v6 + 28) = v8;
    }
    else
    {
      v7 = operator new(0x20u);
      if ( v7 )
      {
        v8 = sub_5B12C0(v7);
        *this = (int)v8;
      }
      else
      {
        v8 = 0;
        *this = 0;
      }
    }
    sub_5B12E0((int)v8, a2, a3, a4);
    return 0;
  }
}
