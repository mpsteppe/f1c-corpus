void __thiscall sub_5F4500(int *this, int a2)
{
  _DWORD *v2; // eax
  int *v3; // ebp
  int v4; // eax

  if ( a2 )
  {
    v2 = (_DWORD *)this[2348];
    v3 = this + 2348;
    if ( v2 )
    {
      while ( !*v2 || *v2 != a2 )
      {
        v2 = (_DWORD *)v2[1];
        if ( !v2 )
          return;
      }
      if ( *v2 )
      {
        memset((void *)a2, 0, 0x40u);
        v4 = *(_DWORD *)(a2 + 68);
        if ( v4 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(*(_DWORD *)(a2 + 68));
        *(_DWORD *)(a2 + 68) = 0;
        *(_BYTE *)(a2 + 72) = 0;
        sub_5DB730(v3, a2, 1);
      }
    }
  }
}
