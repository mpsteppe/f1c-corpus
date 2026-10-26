void __thiscall sub_5AA7F0(float *this, float a2)
{
  if ( a2 != this[16] )
  {
    this[16] = a2;
    (*(void (__stdcall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)dword_7E7CA8 + 252))(
      dword_7E7CA8,
      *(_DWORD *)this,
      19,
      *((_DWORD *)this + 16));
  }
}
