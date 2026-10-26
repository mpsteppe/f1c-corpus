LPVOID __thiscall sub_4189D0(int this)
{
  LPVOID result; // eax
  int v3; // ebp
  int v4; // edi

  result = *(LPVOID *)this;
  if ( *(_DWORD *)this )
  {
    v3 = 0;
    if ( *(int *)(this + 4) > 0 )
    {
      v4 = 0;
      do
      {
        if ( *(_DWORD *)(v4 + *(_DWORD *)this + 44) )
        {
          sub_5BE8AE(*(LPVOID *)(v4 + *(_DWORD *)this + 44));
          *(_DWORD *)(v4 + *(_DWORD *)this + 44) = 0;
        }
        ++v3;
        v4 += 48;
      }
      while ( v3 < *(_DWORD *)(this + 4) );
    }
    result = (LPVOID)sub_5BE8AE(*(LPVOID *)this);
    *(_DWORD *)this = 0;
  }
  *(_DWORD *)(this + 4) = 0;
  *(_BYTE *)(this + 8) = 0;
  return result;
}
