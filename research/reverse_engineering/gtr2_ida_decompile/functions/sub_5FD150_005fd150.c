int __thiscall sub_5FD150(int this, int a2, int a3)
{
  int result; // eax
  void *v5; // edi

  result = *(_DWORD *)(this + 48);
  if ( result )
  {
    if ( (*(_DWORD *)this & 0x80000) != 0 )
    {
      result = sub_5FCA00((int *)this, 4096);
      v5 = *(void **)(this + 68);
      if ( !v5 )
        return result;
      qmemcpy(v5, *(const void **)(this + 96), (*(_DWORD *)(this + 36) * *(_DWORD *)(this + 44)) << 6);
      sub_5FCA80((unsigned int *)this, 4096);
      *(_DWORD *)this &= ~0x80000u;
    }
    return (*(int (__thiscall **)(int, int, int))(*(_DWORD *)dword_FB27A4 + 424))(dword_FB27A4, a3, this);
  }
  return result;
}
