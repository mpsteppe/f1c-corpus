void __thiscall sub_554660(float *this, float a2)
{
  if ( a2 != this[16] )
  {
    this[16] = a2;
    (*(void (__stdcall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)dword_8B89A0 + 252))(
      dword_8B89A0,
      *(_DWORD *)this,
      19,
      *((_DWORD *)this + 16));
  }
}

